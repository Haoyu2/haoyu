// storage.js — IndexedDB CRUD with expiration support

const DB_NAME = 'csv-manager-db';
const DB_VERSION = 1;
const STORE_NAME = 'csv_files';

function openDB() {
  return new Promise((resolve, reject) => {
    const request = indexedDB.open(DB_NAME, DB_VERSION);
    request.onupgradeneeded = (e) => {
      const db = e.target.result;
      if (!db.objectStoreNames.contains(STORE_NAME)) {
        db.createObjectStore(STORE_NAME, { keyPath: 'id' });
      }
    };
    request.onsuccess = (e) => resolve(e.target.result);
    request.onerror = (e) => reject(e.target.error);
  });
}

/** Save a CSV record. */
export async function saveCSV({ name, data, headers, rows, fileSize, expirationDays = 7 }) {
  const db = await openDB();
  const id = `${Date.now()}-${Math.random().toString(36).slice(2, 9)}`;
  const now = Date.now();
  const record = {
    id,
    name,
    data,        // full CSV string
    headers,     // parsed header array
    rows,        // parsed rows (array of arrays)
    rowCount: rows.length,
    fileSize,
    createdAt: now,
    expiresAt: now + expirationDays * 86400000,
  };
  return new Promise((resolve, reject) => {
    const tx = db.transaction(STORE_NAME, 'readwrite');
    tx.objectStore(STORE_NAME).put(record);
    tx.oncomplete = () => resolve(record);
    tx.onerror = (e) => reject(e.target.error);
  });
}

/** Get a full CSV record by id. */
export async function getCSV(id) {
  const db = await openDB();
  return new Promise((resolve, reject) => {
    const tx = db.transaction(STORE_NAME, 'readonly');
    const request = tx.objectStore(STORE_NAME).get(id);
    request.onsuccess = () => resolve(request.result || null);
    request.onerror = (e) => reject(e.target.error);
  });
}

/** Read a chunk of rows from a CSV record. */
export async function readChunk(id, offset, chunkSize = 30) {
  const record = await getCSV(id);
  if (!record) return null;
  const chunk = record.rows.slice(offset, offset + chunkSize);
  return {
    headers: record.headers,
    rows: chunk,
    totalRows: record.rowCount,
    offset,
    hasMore: offset + chunkSize < record.rowCount,
  };
}

/** Get metadata for all stored CSVs (lightweight — excludes raw data & rows). */
export async function getAllMeta() {
  const db = await openDB();
  return new Promise((resolve, reject) => {
    const tx = db.transaction(STORE_NAME, 'readonly');
    const request = tx.objectStore(STORE_NAME).getAll();
    request.onsuccess = () => {
      const metas = request.result.map(({ id, name, rowCount, fileSize, createdAt, expiresAt }) => ({
        id, name, rowCount, fileSize, createdAt, expiresAt,
      }));
      resolve(metas);
    };
    request.onerror = (e) => reject(e.target.error);
  });
}

/** Delete a CSV record by id. */
export async function deleteCSV(id) {
  const db = await openDB();
  return new Promise((resolve, reject) => {
    const tx = db.transaction(STORE_NAME, 'readwrite');
    tx.objectStore(STORE_NAME).delete(id);
    tx.oncomplete = () => resolve();
    tx.onerror = (e) => reject(e.target.error);
  });
}

/** Update the expiration of a CSV record. */
export async function updateExpiration(id, newExpirationDays) {
  const record = await getCSV(id);
  if (!record) return null;
  record.expiresAt = Date.now() + newExpirationDays * 86400000;
  const db = await openDB();
  return new Promise((resolve, reject) => {
    const tx = db.transaction(STORE_NAME, 'readwrite');
    tx.objectStore(STORE_NAME).put(record);
    tx.oncomplete = () => resolve(record);
    tx.onerror = (e) => reject(e.target.error);
  });
}

/** Purge all expired CSV records. */
export async function purgeExpired() {
  const db = await openDB();
  return new Promise((resolve, reject) => {
    const tx = db.transaction(STORE_NAME, 'readwrite');
    const store = tx.objectStore(STORE_NAME);
    const request = store.getAll();
    request.onsuccess = () => {
      const now = Date.now();
      const expired = request.result.filter(r => r.expiresAt <= now);
      expired.forEach(r => store.delete(r.id));
      tx.oncomplete = () => resolve(expired.length);
    };
    request.onerror = (e) => reject(e.target.error);
  });
}

/** Download a CSV record as a file. */
export async function downloadCSV(id) {
  const record = await getCSV(id);
  if (!record) return;
  const blob = new Blob([record.data], { type: 'text/csv' });
  const url = URL.createObjectURL(blob);
  const a = document.createElement('a');
  a.href = url;
  a.download = record.name;
  document.body.appendChild(a);
  a.click();
  document.body.removeChild(a);
  URL.revokeObjectURL(url);
}
