// app.js — Main application: wiring, views, pagination, file management

import { saveCSV, getAllMeta, deleteCSV, downloadCSV, updateExpiration, readChunk, purgeExpired } from './storage.js';
import { parseCSV, getPage } from './csv-parser.js';

// ───── DOM refs ─────
const $dashboard = document.getElementById('view-dashboard');
const $viewer = document.getElementById('view-viewer');
const $backBtn = document.getElementById('btn-back-to-dashboard');
const $fileInput = document.getElementById('file-input');
const $uploadArea = document.getElementById('upload-area');
const $fileGrid = document.getElementById('file-grid');
const $emptyState = document.getElementById('empty-state');
const $fileCount = document.getElementById('file-count');
const $viewerName = document.getElementById('viewer-file-name');
const $viewerInfo = document.getElementById('viewer-row-info');
const $tableHead = document.getElementById('table-head');
const $tableBody = document.getElementById('table-body');
const $pagInfo = document.getElementById('pagination-info');
const $pagControls = document.getElementById('pagination-controls');
const $pageSize = document.getElementById('select-page-size');
const $chunkSize = document.getElementById('select-chunk-size');
const $modalOverlay = document.getElementById('modal-overlay');
const $modalTitle = document.getElementById('modal-title');
const $modalInput = document.getElementById('modal-expiry-input');
const $modalCancel = document.getElementById('modal-cancel');
const $modalConfirm = document.getElementById('modal-confirm');
const $toastContainer = document.getElementById('toast-container');
const $themeToggle = document.getElementById('btn-theme-toggle');

// ───── State ─────
let currentView = 'dashboard'; // 'dashboard' | 'viewer'
let viewerState = {
    fileId: null,
    fileName: '',
    totalRows: 0,
    headers: [],
    chunkRows: [],      // currently loaded chunk of rows
    chunkOffset: 0,     // offset of current chunk in full dataset
    currentPage: 1,     // 1-based page within full dataset
    pageSize: 10,
    chunkSize: 30,
};
let modalFileId = null;

// ───── Helpers ─────
function formatBytes(bytes) {
    if (bytes < 1024) return `${bytes} B`;
    if (bytes < 1048576) return `${(bytes / 1024).toFixed(1)} KB`;
    return `${(bytes / 1048576).toFixed(1)} MB`;
}

function formatDate(ts) {
    return new Date(ts).toLocaleDateString('en-US', { month: 'short', day: 'numeric', year: 'numeric' });
}

function daysUntil(ts) {
    const diff = ts - Date.now();
    const d = Math.ceil(diff / 86400000);
    return d;
}

function toast(message, type = 'info') {
    const el = document.createElement('div');
    el.className = `toast ${type}`;
    el.textContent = message;
    $toastContainer.appendChild(el);
    setTimeout(() => el.remove(), 3100);
}

// ───── View switching ─────
function showDashboard() {
    currentView = 'dashboard';
    $dashboard.classList.remove('hidden');
    $viewer.classList.add('hidden');
    $backBtn.classList.add('hidden');
    refreshDashboard();
}

function showViewer(fileId, fileName) {
    currentView = 'viewer';
    $dashboard.classList.add('hidden');
    $viewer.classList.remove('hidden');
    $backBtn.classList.remove('hidden');
    viewerState.fileId = fileId;
    viewerState.fileName = fileName;
    viewerState.currentPage = 1;
    viewerState.chunkOffset = 0;
    viewerState.pageSize = parseInt($pageSize.value);
    viewerState.chunkSize = parseInt($chunkSize.value);
    $viewerName.textContent = fileName;
    loadChunkAndRender();
}

// ───── Dashboard ─────
async function refreshDashboard() {
    const metas = await getAllMeta();
    // Sort by most recently created first
    metas.sort((a, b) => b.createdAt - a.createdAt);

    $fileCount.textContent = metas.length ? `(${metas.length})` : '';
    $fileGrid.innerHTML = '';

    if (metas.length === 0) {
        $emptyState.classList.remove('hidden');
        return;
    }
    $emptyState.classList.add('hidden');

    metas.forEach((meta, i) => {
        const days = daysUntil(meta.expiresAt);
        let expiryClass = '';
        let expiryText = '';
        if (days <= 0) {
            expiryClass = 'expired';
            expiryText = 'Expired';
        } else if (days <= 3) {
            expiryClass = 'expiring-soon';
            expiryText = `${days}d left`;
        } else {
            expiryText = formatDate(meta.expiresAt);
        }

        const card = document.createElement('div');
        card.className = 'file-card';
        card.style.animationDelay = `${i * 0.05}s`;
        card.innerHTML = `
      <div class="file-card-header">
        <span class="file-card-name" data-id="${meta.id}" data-name="${meta.name}" title="Click to view">${meta.name}</span>
      </div>
      <div class="file-card-meta">
        <div class="meta-item">
          <span class="meta-label">Size</span>
          <span class="meta-value">${formatBytes(meta.fileSize)}</span>
        </div>
        <div class="meta-item">
          <span class="meta-label">Rows</span>
          <span class="meta-value">${meta.rowCount.toLocaleString()}</span>
        </div>
        <div class="meta-item">
          <span class="meta-label">Uploaded</span>
          <span class="meta-value">${formatDate(meta.createdAt)}</span>
        </div>
        <div class="meta-item">
          <span class="meta-label">Expires</span>
          <span class="meta-value ${expiryClass}">${expiryText}</span>
        </div>
      </div>
      <div class="file-card-actions">
        <button class="btn btn-ghost btn-sm action-view" data-id="${meta.id}" data-name="${meta.name}">
          <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M1 12s4-8 11-8 11 8 11 8-4 8-11 8-11-8-11-8z"/><circle cx="12" cy="12" r="3"/></svg>
          View
        </button>
        <button class="btn btn-ghost btn-sm action-download" data-id="${meta.id}">
          <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M21 15v4a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2v-4"/><polyline points="7 10 12 15 17 10"/><line x1="12" y1="15" x2="12" y2="3"/></svg>
          Download
        </button>
        <button class="btn btn-ghost btn-sm action-expiry" data-id="${meta.id}" data-name="${meta.name}">
          <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><circle cx="12" cy="12" r="10"/><polyline points="12 6 12 12 16 14"/></svg>
          Expiry
        </button>
        <button class="btn btn-danger btn-sm action-delete" data-id="${meta.id}" data-name="${meta.name}">
          <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><polyline points="3 6 5 6 21 6"/><path d="M19 6l-1 14a2 2 0 0 1-2 2H8a2 2 0 0 1-2-2L5 6"/><path d="M10 11v6"/><path d="M14 11v6"/><path d="M9 6V4a1 1 0 0 1 1-1h4a1 1 0 0 1 1 1v2"/></svg>
          Delete
        </button>
      </div>
    `;
        $fileGrid.appendChild(card);
    });
}

// ───── Upload ─────
async function handleFiles(files) {
    for (const file of files) {
        if (!file.name.toLowerCase().endsWith('.csv') && file.type !== 'text/csv') {
            toast(`"${file.name}" is not a CSV file`, 'error');
            continue;
        }
        try {
            const text = await file.text();
            const { headers, rows } = parseCSV(text);
            await saveCSV({
                name: file.name,
                data: text,
                headers,
                rows,
                fileSize: file.size,
                expirationDays: 7,
            });
            toast(`"${file.name}" uploaded (${rows.length} rows)`, 'success');
        } catch (err) {
            toast(`Error uploading "${file.name}": ${err.message}`, 'error');
        }
    }
    refreshDashboard();
}

$fileInput.addEventListener('change', (e) => {
    if (e.target.files.length) handleFiles(e.target.files);
    e.target.value = ''; // reset so same file can be re-uploaded
});

// Drag & drop
$uploadArea.addEventListener('dragover', (e) => { e.preventDefault(); $uploadArea.classList.add('drag-over'); });
$uploadArea.addEventListener('dragleave', () => $uploadArea.classList.remove('drag-over'));
$uploadArea.addEventListener('drop', (e) => {
    e.preventDefault();
    $uploadArea.classList.remove('drag-over');
    if (e.dataTransfer.files.length) handleFiles(e.dataTransfer.files);
});

// ───── Dashboard actions (delegated) ─────
$fileGrid.addEventListener('click', async (e) => {
    const viewBtn = e.target.closest('.action-view') || e.target.closest('.file-card-name');
    if (viewBtn) {
        const id = viewBtn.dataset.id;
        const name = viewBtn.dataset.name;
        showViewer(id, name);
        return;
    }

    const dlBtn = e.target.closest('.action-download');
    if (dlBtn) {
        await downloadCSV(dlBtn.dataset.id);
        toast('Download started', 'info');
        return;
    }

    const exBtn = e.target.closest('.action-expiry');
    if (exBtn) {
        modalFileId = exBtn.dataset.id;
        $modalTitle.textContent = `Change Expiration — ${exBtn.dataset.name}`;
        $modalInput.value = 7;
        $modalOverlay.classList.remove('hidden');
        return;
    }

    const delBtn = e.target.closest('.action-delete');
    if (delBtn) {
        if (confirm(`Delete "${delBtn.dataset.name}"?`)) {
            await deleteCSV(delBtn.dataset.id);
            toast(`"${delBtn.dataset.name}" deleted`, 'success');
            refreshDashboard();
        }
        return;
    }
});

// ───── Modal ─────
$modalCancel.addEventListener('click', () => $modalOverlay.classList.add('hidden'));
$modalOverlay.addEventListener('click', (e) => {
    if (e.target === $modalOverlay) $modalOverlay.classList.add('hidden');
});
$modalConfirm.addEventListener('click', async () => {
    const days = parseInt($modalInput.value);
    if (!days || days < 1) {
        toast('Enter a valid number of days', 'error');
        return;
    }
    await updateExpiration(modalFileId, days);
    toast(`Expiration updated to ${days} day${days > 1 ? 's' : ''}`, 'success');
    $modalOverlay.classList.add('hidden');
    refreshDashboard();
});

// ───── Viewer: chunk loading + pagination ─────
async function loadChunkAndRender() {
    const { fileId, chunkOffset, chunkSize } = viewerState;
    const result = await readChunk(fileId, chunkOffset, chunkSize);
    if (!result) {
        toast('File not found — it may have expired', 'error');
        showDashboard();
        return;
    }
    viewerState.headers = result.headers;
    viewerState.chunkRows = result.rows;
    viewerState.totalRows = result.totalRows;
    $viewerInfo.textContent = `${result.totalRows.toLocaleString()} total rows`;
    renderTable();
}

function renderTable() {
    const { headers, chunkRows, chunkOffset, currentPage, pageSize, totalRows } = viewerState;

    // Figure out which rows from the chunk correspond to the current page
    const globalStart = (currentPage - 1) * pageSize;  // 0-based global start
    const localStart = globalStart - chunkOffset;
    const pageRows = chunkRows.slice(localStart, localStart + pageSize);

    // Header row
    $tableHead.innerHTML = `<tr><th class="row-num">#</th>${headers.map(h => `<th>${escapeHTML(h)}</th>`).join('')}</tr>`;

    // Body
    $tableBody.innerHTML = pageRows.map((row, i) => {
        const rowNum = globalStart + i + 1;
        return `<tr><td class="row-num">${rowNum}</td>${row.map(cell => `<td title="${escapeHTML(cell)}">${escapeHTML(cell)}</td>`).join('')}</tr>`;
    }).join('');

    renderPagination();
}

function renderPagination() {
    const { totalRows, pageSize, currentPage } = viewerState;
    const totalPages = Math.ceil(totalRows / pageSize);
    const globalStart = (currentPage - 1) * pageSize + 1;
    const globalEnd = Math.min(currentPage * pageSize, totalRows);

    $pagInfo.textContent = `Showing ${globalStart}–${globalEnd} of ${totalRows.toLocaleString()} rows`;

    // Build page buttons
    let html = '';
    html += `<button class="page-btn" data-page="prev" ${currentPage <= 1 ? 'disabled' : ''}>‹</button>`;

    const maxButtons = 7;
    let startPage = Math.max(1, currentPage - Math.floor(maxButtons / 2));
    let endPage = Math.min(totalPages, startPage + maxButtons - 1);
    if (endPage - startPage < maxButtons - 1) startPage = Math.max(1, endPage - maxButtons + 1);

    if (startPage > 1) {
        html += `<button class="page-btn" data-page="1">1</button>`;
        if (startPage > 2) html += `<span style="color:var(--text-muted);padding:0 4px;">…</span>`;
    }
    for (let p = startPage; p <= endPage; p++) {
        html += `<button class="page-btn ${p === currentPage ? 'active' : ''}" data-page="${p}">${p}</button>`;
    }
    if (endPage < totalPages) {
        if (endPage < totalPages - 1) html += `<span style="color:var(--text-muted);padding:0 4px;">…</span>`;
        html += `<button class="page-btn" data-page="${totalPages}">${totalPages}</button>`;
    }

    html += `<button class="page-btn" data-page="next" ${currentPage >= totalPages ? 'disabled' : ''}>›</button>`;
    $pagControls.innerHTML = html;
}

// Navigate to a page — may need to load a new chunk
async function goToPage(page) {
    const { pageSize, chunkSize, chunkOffset, totalRows } = viewerState;
    const totalPages = Math.ceil(totalRows / pageSize);
    if (page < 1 || page > totalPages) return;

    viewerState.currentPage = page;
    const globalStart = (page - 1) * pageSize;  // 0-based row index
    const globalEnd = globalStart + pageSize - 1;

    // Check if needed rows are outside the current chunk
    if (globalStart < chunkOffset || globalEnd >= chunkOffset + viewerState.chunkRows.length) {
        // Load a new chunk starting at an aligned offset
        viewerState.chunkOffset = Math.floor(globalStart / chunkSize) * chunkSize;
        await loadChunkAndRender();
    } else {
        renderTable();
    }
}

$pagControls.addEventListener('click', (e) => {
    const btn = e.target.closest('.page-btn');
    if (!btn || btn.disabled) return;
    const val = btn.dataset.page;
    if (val === 'prev') goToPage(viewerState.currentPage - 1);
    else if (val === 'next') goToPage(viewerState.currentPage + 1);
    else goToPage(parseInt(val));
});

// Settings changes
$pageSize.addEventListener('change', () => {
    viewerState.pageSize = parseInt($pageSize.value);
    viewerState.currentPage = 1;
    viewerState.chunkOffset = 0;
    loadChunkAndRender();
});

$chunkSize.addEventListener('change', () => {
    viewerState.chunkSize = parseInt($chunkSize.value);
    viewerState.currentPage = 1;
    viewerState.chunkOffset = 0;
    loadChunkAndRender();
});

$backBtn.addEventListener('click', showDashboard);

// ───── Utility ─────
function escapeHTML(str) {
    const div = document.createElement('div');
    div.textContent = str;
    return div.innerHTML;
}

// ───── Theme ─────
function applyTheme(theme) {
    document.documentElement.setAttribute('data-theme', theme);
    localStorage.setItem('csv-manager-theme', theme);
}

(function initTheme() {
    const saved = localStorage.getItem('csv-manager-theme') || 'dark';
    applyTheme(saved);
})();

$themeToggle.addEventListener('click', () => {
    const current = document.documentElement.getAttribute('data-theme') || 'dark';
    applyTheme(current === 'dark' ? 'light' : 'dark');
});

// ───── Init ─────
async function init() {
    const purged = await purgeExpired();
    if (purged > 0) toast(`Removed ${purged} expired file${purged > 1 ? 's' : ''}`, 'info');
    showDashboard();
}

init();
