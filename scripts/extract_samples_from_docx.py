from docx import Document
from pathlib import Path

def extract_samples(docx_path, out_dir="samples"):
    doc = Document(docx_path)
    out = Path(out_dir)
    out.mkdir(exist_ok=True)

    digit = None
    rows = []
    for para in doc.paragraphs:
        text = para.text.strip()
        if not text:
            continue
        if text.isdigit() and len(text) == 1:
            if digit is not None and rows:
                (out / f"{digit}.txt").write_text("\n".join(rows) + "\n")
                rows = []
            digit = text
        elif all(ch in "01" for ch in text) and len(text) >= 8:
            rows.append(text[:8])
    if digit is not None and rows:
        (out / f"{digit}.txt").write_text("\n".join(rows) + "\n")

    print(f"✅ Done. Samples saved to {out.resolve()}")

if __name__ == "__main__":
    extract_samples("數字辨識.docx")
