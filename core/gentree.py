import os

ROOT_DIR = "."  # ← set to your folder or leave "." to use current folder
OUTPUT_FILE = "verilog_dump.txt"

VALID_EXT = {".v", ".vh", ".V", ".VH"}  # case-insensitive support


def collect_files(root):
    found = []

    print(f"[DEBUG] Walking directory: {os.path.abspath(root)}")

    for dirpath, _, filenames in os.walk(root):
        for f in filenames:
            _, ext = os.path.splitext(f)
            if ext in VALID_EXT:
                full = os.path.join(dirpath, f)
                found.append(full)
                print(f"[FOUND] {full}")

    print(f"[DEBUG] Total Verilog files found: {len(found)}")
    return found


def build_text(files, root):
    lines = []
    lines.append("PROJECT FILE TREE + CONTENTS\n")
    lines.append("=" * 70 + "\n\n")

    root = os.path.abspath(root)

    if not files:
        lines.append("[NO VERILOG FILES FOUND]\n")
        return "".join(lines)

    for fpath in files:
        rel = os.path.relpath(fpath, root)
        lines.append(f"FILE: {rel}\n")
        lines.append("-" * 70 + "\n")

        try:
            with open(fpath, "r", encoding="utf-8", errors="ignore") as f:
                content = f.read()
        except Exception as e:
            content = f"[ERROR READING FILE: {e}]\n"

        lines.append(content)
        lines.append("\n")

    return "".join(lines)


def main():
    files = collect_files(ROOT_DIR)
    output = build_text(files, ROOT_DIR)

    with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
        f.write(output)

    print(f"[DONE] Wrote: {OUTPUT_FILE}")


if __name__ == "__main__":
    main()
