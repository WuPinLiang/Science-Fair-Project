const buttonsWrap = document.getElementById('digit-buttons');
const rawPre = document.getElementById('raw');
const grid = document.getElementById('grid');

// build digit buttons
for (let d = 0; d <= 9; d++) {
  const btn = document.createElement('button');
  btn.textContent = d;
  btn.addEventListener('click', () => loadDigit(d, btn));
  buttonsWrap.appendChild(btn);
}

// build 8x8 grid
const cells = [];
for (let i = 0; i < 64; i++) {
  const div = document.createElement('div');
  div.className = 'cell';
  grid.appendChild(div);
  cells.push(div);
}

async function loadDigit(digit, btn) {
  // button active
  [...buttonsWrap.children].forEach(b => b.classList.remove('active'));
  btn.classList.add('active');

  // 絕對化路徑：以文件的 baseURI 為準，確保在 GitHub Pages 子路徑下也正確
  const url = new URL(`samples/${digit}.txt`, document.baseURI);
  url.searchParams.set('v', Date.now().toString()); // cache-bust

  try {
    const res = await fetch(url.toString(), { cache: 'no-store' });
    if (!res.ok) throw new Error(`HTTP ${res.status}`);
    const text = await res.text();
    rawPre.textContent = text.trim();

    const lines = text.trim().split(/\r?\n/).map(l=>l.replace(/[^01]/g,'')).filter(l=>l.length>=8).slice(0,8).map(l=>l.slice(0,8));
    const bits = lines.join('');
    if (bits.length < 64) throw new Error('Invalid sample format');

    for (let i = 0; i < 64; i++) {
      const on = bits[i] === '1';
      cells[i].classList.toggle('on', on);
    }
  } catch (err) {
    rawPre.textContent = `Failed to load ${url}\n${err}`;
    cells.forEach(c => c.classList.remove('on'));
  }
}

document.addEventListener('DOMContentLoaded', () => {
  const third = buttonsWrap.children[3];
  if (third) third.click();
});
