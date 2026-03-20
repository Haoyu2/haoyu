// csv-parser.js — CSV text → structured data, with pagination helpers

/**
 * Parse raw CSV text into headers + rows.
 * Handles quoted fields containing commas and newlines.
 */
export function parseCSV(text) {
    const lines = [];
    let current = '';
    let inQuotes = false;

    for (let i = 0; i < text.length; i++) {
        const ch = text[i];
        if (ch === '"') {
            if (inQuotes && text[i + 1] === '"') {
                current += '"';
                i++; // skip escaped quote
            } else {
                inQuotes = !inQuotes;
            }
        } else if (ch === '\n' && !inQuotes) {
            if (current.endsWith('\r')) current = current.slice(0, -1);
            lines.push(current);
            current = '';
        } else {
            current += ch;
        }
    }
    if (current.trim()) lines.push(current);

    const splitRow = (line) => {
        const cols = [];
        let cell = '';
        let q = false;
        for (let i = 0; i < line.length; i++) {
            const c = line[i];
            if (c === '"') {
                if (q && line[i + 1] === '"') { cell += '"'; i++; }
                else q = !q;
            } else if (c === ',' && !q) {
                cols.push(cell);
                cell = '';
            } else {
                cell += c;
            }
        }
        cols.push(cell);
        return cols;
    };

    const headers = splitRow(lines[0] || '');
    const rows = lines.slice(1).map(splitRow);
    return { headers, rows };
}

/**
 * Get a page of rows from a given dataset slice.
 * @param {string[][]} rows  - row data
 * @param {number} pageNum   - 1-based page number within the chunk
 * @param {number} pageSize  - rows per page (default 10)
 */
export function getPage(rows, pageNum, pageSize = 10) {
    const start = (pageNum - 1) * pageSize;
    return rows.slice(start, start + pageSize);
}
