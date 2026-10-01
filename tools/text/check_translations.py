#!/usr/bin/env python3
"""Guard anti-recaida de la UNIFICACION de traducciones (ver notes/2026-10-01-i18n-...).

Comprueba que la traduccion sigue viviendo SOLO en `assets/lang/*.txt` (clave = ingles) y que el
codigo solo referencia claves:

1. No reaparecen tablas de traduccion en codigo (`kMenuTr`, `kEsDefaults`, `kAreaNames`).
2. Cada literal de `localized("...")` del codigo existe como clave en la tabla base (`es.txt`).
3. Cada etiqueta de menu (`make_item`/`make_submenu`/`make_option`/`make_binding`/`make_number`/
   `make_toggle`/`make_selector*` primer argumento) existe en la tabla base, salvo las etiquetas
   LEGADO que aun no se traducen (ver LEGACY_LABELS).
4. Cada opcion de un `make_selector*({...})` existe en la tabla base, salvo valores opacos
   (numeros, `%`, ratios, `xN`...) y las LEGADO.
5. Consistencia de los ficheros: sin claves duplicadas y `ca/fr/de/ja` son subconjunto de `es`.

Uso: `python3 tools/text/check_translations.py`  (0 = OK, 1 = fallo)
"""
from __future__ import annotations

import os
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
LANG_DIR = ROOT / "assets" / "lang"
SRC = ROOT / "src"
BASE = "es"
BUILTINS = ["es", "ca", "fr", "de", "ja"]

FORBIDDEN = ["kMenuTr", "kEsDefaults", "kAreaNames"]

# Etiquetas/opciones que HOY no se traducen (fuera del alcance de la unificacion): se aceptan sin
# entrada en la tabla. Al traducirlas, quitar de aqui.
LEGACY_LABELS = {
    "ATRIBUTOS", "CARGAR", "ELIMINAR", "ITEMS", "MODO HEAVEN", "TIPO", "TODOS", "RESTAURAR",
    "RESET", "TODO SÍ", "TODO NO",
}
# Endónimos del selector IDIOMA (viven en código; no son traducciones).
ENDONYMS = {"INGLÉS", "ESPAÑOL", "CATALÁN", "FRANCÉS", "ALEMÁN", "JAPONÉS"}

# Valores opacos (no son texto a traducir): 0-100%, tasas de FPS, ratios, MSAA, resoluciones.
OPAQUE_RE = re.compile(r"^[0-9x%.:]+$")

WORD = r"(?:[^\"\\]|\\.)*"
MAKE_FIRST = re.compile(
    r'\b(make_item|make_submenu|make_option|make_binding|make_number|make_toggle|'
    r'make_selector|make_selector_with_action)\s*\(\s*"(' + WORD + r')"')
LOCALIZED = re.compile(r'\blocalized\s*\(\s*"(' + WORD + r')"')
SELECTOR_OPTS = re.compile(
    r'\bmake_selector(?:_with_action)?\s*\(\s*"' + WORD + r'"\s*,\s*\{([^}]*)\}', re.S)
OPT_LIT = re.compile(r'"(' + WORD + r')"')


def unescape(s: str) -> str:
    out = []
    i = 0
    while i < len(s):
        if s[i] == "\\" and i + 1 < len(s):
            n = s[i + 1]
            if n == "n":
                out.append("\n"); i += 2; continue
            if n == "t":
                out.append("\t"); i += 2; continue
            if n == "\\":
                out.append("\\"); i += 2; continue
            if n == '"':
                out.append('"'); i += 2; continue
        out.append(s[i]); i += 1
    return "".join(out)


def load_keys(path: Path) -> dict[str, str]:
    keys: dict[str, str] = {}
    for line in path.read_text(encoding="utf-8").splitlines():
        if not line or line.lstrip().startswith("#") or "=" not in line:
            continue
        k, v = line.split("=", 1)
        keys[unescape(k.strip())] = unescape(v.strip())
    return keys


def check_forbidden() -> list[str]:
    errs = []
    for path in SRC.rglob("*.cpp"):
        text = path.read_text(encoding="utf-8")
        for tok in FORBIDDEN:
            if tok in text:
                errs.append(f"{path.relative_to(ROOT)}: reaparece tabla de traduccion en codigo: {tok}")
    for path in SRC.rglob("*.h"):
        text = path.read_text(encoding="utf-8")
        for tok in FORBIDDEN:
            if tok in text:
                errs.append(f"{path.relative_to(ROOT)}: reaparece tabla de traduccion en codigo: {tok}")
    return errs


def check_code_keys(base: dict[str, str]) -> list[str]:
    errs = []
    for path in SRC.rglob("*.cpp"):
        text = path.read_text(encoding="utf-8")
        for m in LOCALIZED.finditer(text):
            key = unescape(m.group(1))
            if key and key not in base and key not in ENDONYMS:
                errs.append(f"{path.relative_to(ROOT)}: localized(\"{key}\") sin entrada en {BASE}.txt")
        for m in MAKE_FIRST.finditer(text):
            key = unescape(m.group(2))
            if not key or key in base or key in LEGACY_LABELS or key in ENDONYMS:
                continue
            errs.append(f"{path.relative_to(ROOT)}: {m.group(1)}(\"{key}\") sin entrada en {BASE}.txt")
        for m in SELECTOR_OPTS.finditer(text):
            for om in OPT_LIT.finditer(m.group(1)):
                key = unescape(om.group(1))
                if not key or key in base or key in LEGACY_LABELS or OPAQUE_RE.match(key):
                    continue
                errs.append(f"{path.relative_to(ROOT)}: opcion \"{key}\" sin entrada en {BASE}.txt")
    return errs


def check_files() -> list[str]:
    errs = []
    tables = {lang: load_keys(LANG_DIR / f"{lang}.txt") for lang in BUILTINS}
    # Duplicados: load_keys ya colapsa; detectarlos leyendo de nuevo a mano.
    for lang in BUILTINS:
        seen = set()
        for line in (LANG_DIR / f"{lang}.txt").read_text(encoding="utf-8").splitlines():
            if not line or line.lstrip().startswith("#") or "=" not in line:
                continue
            k = unescape(line.split("=", 1)[0].strip())
            if k in seen:
                errs.append(f"assets/lang/{lang}.txt: clave duplicada: {k!r}")
            seen.add(k)
    base = tables[BASE]
    for lang in BUILTINS:
        if lang == BASE:
            continue
        extra = set(tables[lang]) - set(base)
        for k in sorted(extra):
            errs.append(f"assets/lang/{lang}.txt: clave ausente en {BASE}.txt: {k!r}")
    if (LANG_DIR / "en.txt").exists():
        errs.append("assets/lang/en.txt no debe existir (en = identidad)")
    return errs


def main() -> int:
    errs = check_forbidden()
    if not (LANG_DIR / f"{BASE}.txt").exists():
        print(f"ERROR: falta {LANG_DIR / (BASE + '.txt')}")
        return 1
    errs += check_code_keys(load_keys(LANG_DIR / f"{BASE}.txt"))
    errs += check_files()
    if errs:
        for e in errs:
            print("ERROR:", e)
        print(f"\ncheck_translations: {len(errs)} error(es)")
        return 1
    print("check_translations: OK")
    return 0


if __name__ == "__main__":
    sys.exit(main())
