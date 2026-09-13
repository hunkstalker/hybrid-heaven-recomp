#!/usr/bin/env python3
"""docs_index.py — genera docs/INDEX.md y valida la documentación viva.

- Escanea los .md del proyecto (raíz, docs/, notes/; excluye terceros en port/, work/,
  toolchain/). Extrae título, resumen (blockquote inicial o primer párrafo) y nº de líneas.
- Escribe docs/INDEX.md (generado, no editar a mano).
- Verifica enlaces relativos entre documentos y presupuestos de tamaño.

Uso:
    python3 tools/analysis/docs_index.py            # regenera docs/INDEX.md y valida
    python3 tools/analysis/docs_index.py --check    # solo valida (no escribe)
    python3 tools/analysis/docs_index.py --quiet    # solo errores

Salida: 0 si no hay enlaces rotos; 1 si los hay (los avisos de tamaño no fallan).
"""
from __future__ import annotations

import argparse
import os
import re
import subprocess
import sys
from datetime import date
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
INDEX = ROOT / "docs" / "INDEX.md"

ROOTS = ["AGENTS.md", "PROYECTO.md", "TODO.md", "README.md"]
GLOBS = ["docs/**/*.md", "notes/**/*.md"]
EXCLUDE = {"docs/INDEX.md"}

# Presupuestos "duros" (fallan en --check) y avisos (solo informan).
HARD_LIMITS = {
    "AGENTS.md": 110,
    "PROYECTO.md": 140,
    "TODO.md": 170,
    "docs/documentation.md": 120,
}
WARN_LINES = 250

LINK_RE = re.compile(r"\[[^\]]*\]\(([^)]+)\)")
FENCE_RE = re.compile(r"^```")
TITLE_RE = re.compile(r"^#\s+(.+)")


def rel(path: Path) -> str:
    return path.relative_to(ROOT).as_posix()


def collect_docs() -> list[Path]:
    files: set[Path] = set()
    for name in ROOTS:
        p = ROOT / name
        if p.is_file():
            files.add(p)
    for pattern in GLOBS:
        for p in ROOT.glob(pattern):
            if p.is_file():
                files.add(p)
    return sorted(p for p in files if rel(p) not in EXCLUDE)


def first_line(lines: list[str], prefix: str) -> str | None:
    for line in lines:
        s = line.strip()
        if s.startswith(prefix):
            return s[len(prefix):].strip()
    return None


def summarize(path: Path) -> dict:
    text = path.read_text(encoding="utf-8", errors="replace")
    lines = text.splitlines()
    title = next((m.group(1).strip() for line in lines if (m := TITLE_RE.match(line))), path.stem)
    summary = None
    for line in lines[:12]:
        s = line.strip()
        if s.startswith(">"):
            summary = s.lstrip("> ").strip()
            if summary:
                break
    if not summary:
        for line in lines:
            s = line.strip()
            if s and not s.startswith("#") and not s.startswith(">"):
                summary = s
                break
    summary = (summary or "")[:150]
    note_date = None
    m = re.match(r"(\d{4}-\d{2}-\d{2})", path.name)
    if m:
        note_date = m.group(1)
    return {"title": title, "summary": summary, "lines": len(lines), "date": note_date}


def classify(path: Path) -> str:
    r = rel(path)
    if r in ROOTS:
        return "Arranque y estado (vivos)"
    if r.startswith("docs/adr/"):
        return "Decisiones (ADR, inmutables)"
    if r.startswith("docs/"):
        return "Técnico y guías (vivos)"
    if r.startswith("notes/archive/"):
        return "Archivo histórico (congelado)"
    if r.startswith("notes/"):
        return "Evidencia (notas, histórico)"
    return "Otros"


def strip_fences(text: str) -> str:
    out, fenced = [], False
    for line in text.splitlines():
        if FENCE_RE.match(line.strip()):
            fenced = not fenced
            continue
        if not fenced:
            out.append(line)
    return "\n".join(out)


def check_links(docs: list[Path]) -> list[tuple[str, int, str]]:
    broken = []
    for path in docs:
        text = strip_fences(path.read_text(encoding="utf-8", errors="replace"))
        for lineno, line in enumerate(text.splitlines(), 1):
            for target in LINK_RE.findall(line):
                target = target.strip().strip("<>").split("#", 1)[0].strip()
                if not target or "://" in target or target.startswith(("mailto:", "#")):
                    continue
                resolved = (path.parent / target).resolve()
                if not resolved.exists():
                    broken.append((rel(path), lineno, target))
    return broken


def fmt_date(p: Path, meta: dict) -> str:
    if meta["date"]:
        return meta["date"]
    try:
        out = subprocess.run(
            ["git", "-C", str(ROOT), "log", "-1", "--format=%cs", "--", rel(p)],
            capture_output=True, text=True, timeout=5,
        )
        if out.returncode == 0 and out.stdout.strip():
            return out.stdout.strip()
    except (OSError, subprocess.SubprocessError):
        pass
    return date.fromtimestamp(p.stat().st_mtime).isoformat()


def build_index(docs: list[Path]) -> str:
    groups: dict[str, list[Path]] = {}
    for p in docs:
        groups.setdefault(classify(p), []).append(p)
    for key in ("Evidencia (notas, histórico)",):
        if key in groups:
            groups[key].sort(key=lambda p: p.name, reverse=True)
    order = [
        "Arranque y estado (vivos)",
        "Técnico y guías (vivos)",
        "Decisiones (ADR, inmutables)",
        "Evidencia (notas, histórico)",
        "Archivo histórico (congelado)",
        "Otros",
    ]
    out = [
        "# Índice de documentación",
        "",
        "> **GENERADO por `tools/analysis/docs_index.py`; no editar a mano.**",
        "> Regenerar: `python3 tools/analysis/docs_index.py` · Validar: `… --check`.",
        "> Regla: una fuente de verdad por tema (`docs/documentation.md`).",
        "",
    ]
    for key in order:
        items = groups.get(key)
        if not items:
            continue
        out.append(f"## {key}")
        out.append("")
        out.append("| Documento | Resumen | Líneas | Actualizado |")
        out.append("|---|---|---|---|")
        for p in items:
            meta = summarize(p)
            link = os.path.relpath(p, INDEX.parent).replace(os.sep, "/")
            out.append(
                f"| [{meta['title']}]({link}) | {meta['summary'].replace('|', '/')} "
                f"| {meta['lines']} | {fmt_date(p, meta)} |"
            )
        out.append("")
    ref = ROOT / "notes" / "reference"
    if ref.is_dir():
        data = sorted(f for f in ref.iterdir() if f.is_file())
        out.append("## Datos generados (`notes/reference/`)")
        out.append("")
        out.append("| Fichero | Tamaño |")
        out.append("|---|---|")
        for f in data:
            out.append(f"| `{rel(f)}` | {f.stat().st_size:,} B |")
        out.append("")
    return "\n".join(out)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true", help="no escribe el índice; solo valida")
    ap.add_argument("--quiet", action="store_true", help="solo imprime problemas")
    args = ap.parse_args()

    docs = collect_docs()
    broken = check_links(docs)
    issues: list[str] = []
    warnings: list[str] = []

    for p in docs:
        n = len(p.read_text(encoding="utf-8", errors="replace").splitlines())
        hard = HARD_LIMITS.get(rel(p))
        if hard and n > hard:
            issues.append(f"líneas: {rel(p)} tiene {n} > {hard} (presupuesto)")
        elif n > WARN_LINES and not rel(p).startswith("notes/"):
            warnings.append(f"líneas: {rel(p)} tiene {n} > {WARN_LINES}")

    if not args.quiet:
        print(f"documentos escaneados: {len(docs)}")
        for w in warnings:
            print(f"  aviso: {w}")
        for b in broken:
            print(f"  roto: {b[0]}:{b[1]} -> {b[2]}")

    if not args.check:
        INDEX.write_text(build_index(docs), encoding="utf-8")
        if not args.quiet:
            print(f"escrito: {rel(INDEX)}")

    for i in issues:
        print(f"  error: {i}")

    return 1 if (broken or issues) else 0


if __name__ == "__main__":
    sys.exit(main())
