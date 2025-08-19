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

// build 8x8 grid cells
const cells = [];
for (let i = 0; i < 64; i++) {
  const div = document.createElement('div');
  div.className = 'cell';
  grid.appendChild(div);
  cells.push(div);
}

async function loadDigit(digit, btn) {
  // button active state
  [...buttonsWrap.children].forEach(b => b.classList.remove('active'));
  btn.classList.add('active');

  // samples folder is one level up from docs/ (Pages root is docs/)
  const url = `../samples/${digit}.txt`;
  try {
    const res = await fetch(url, { cache: 'no-store' });
    if (!res.ok) throw new Error(`HTTP ${res.status}`);
    const text = await res.text();
    rawPre.textContent = text.trim();

    const lines = text.trim().split(/\r?\n/).slice(0, 8);
    const bits = lines.join('');
    if (bits.length < 64) throw new Error('Invalid sample format');

    // paint grid
    for (let i = 0; i < 64; i++) {
      const on = bits[i] === '1';
      cells[i].classList.toggle('on', on);
    }
  } catch (err) {
    rawPre.textContent = `Failed to load ${url}\n${err}`;
    cells.forEach(c => c.classList.remove('on'));
  }
}

// auto-load '3' as default
document.addEventListener('DOMContentLoaded', () => {
  const third = buttonsWrap.children[3];
  if (third) third.click();
});
