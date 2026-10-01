#!/usr/bin/env python3
"""Migracion (de un solo uso) de la traduccion EN CODIGO a los ficheros `assets/lang/*.txt`.

Hasta ahora la UI del port se traducia con la tabla `kMenuTr` (menu.cpp, clave = ESPANOL) y los
nombres de Area con `kAreaNames` (menu_overlay.cpp, columnas por idioma). El texto NATIVO de la ROM
ya vivia en `assets/lang/<code>.txt` (clave = INGLES). Este script UNIFICA todo en esos ficheros con
la clave canonica = TEXTO ORIGINAL EN INGLES.

- Fuente de la UI: `kMenuTr` -> clave = columna `en`.
- Fuente de las Areas: `kAreaNames` -> clave = campo `en`.
- Se FUSIONA con lo ya existente en `assets/lang/es.txt` (texto nativo).
- Precedencia: la UI (kMenuTr) gana sobre el texto nativo cuando la clave inglesa coincide (resuelve
  inconsistencias como BATTLE MODE = MODO LUCHA [nativo] vs MODO COMBATE [UI]).
- `en` = identidad: no se genera `en.txt`.

Colisiones de clave dentro de `kMenuTr` (misma cadena inglesa con distinto sentido): de momento solo
`SAVE` y `BODY`; se conserva la fila cuya version espanola SI se usa en el codigo (ver KEEP_ES). Si
aparece una colision nueva, el script ABORTA para resolverla a mano.

Despues de ejecutarlo se borran las tablas de codigo (`kMenuTr`, columnas de `kAreaNames`). El script
queda como registro de la migracion; NO es un generador recurrente (las tablas desaparecen).

Uso:
    python3 tools/text/migrate_menu_tr.py            # informe (no escribe)
    python3 tools/text/migrate_menu_tr.py --write    # escribe assets/lang/*.txt
"""
import argparse
import os
import re
import sys
from collections import defaultdict, OrderedDict

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
MENU_CPP = os.path.join(ROOT, "src", "subsystems", "menu.cpp")
OVERLAY_CPP = os.path.join(ROOT, "src", "hooks", "menu_overlay.cpp")
LANG_DIR = os.path.join(ROOT, "assets", "lang")

# Colision `en` -> version espanola que SI se usa en el codigo (la otra fila se descarta).
KEEP_ES = {
    "SAVE": "GUARDAR",   # "PARTIDA" (en=SAVE) no se usa como etiqueta
    "BODY": "CUERPO",    # "BODY" (en=BODY) no se usa; el submenu ahora es ESTADO
}

LANGS = ["es", "ca", "fr", "de", "ja"]


def extract_block(src, name):
    """Devuelve el texto `{ ... }` que sigue a `name` (balanceando llaves, ignorando strings)."""
    i = src.index(name)
    i = src.index("{", i)
    start = i
    depth = 0
    in_str = False
    esc = False
    while i < len(src):
        c = src[i]
        if in_str:
            if esc:
                esc = False
            elif c == "\\":
                esc = True
            elif c == '"':
                in_str = False
        else:
            if c == '"':
                in_str = True
            elif c == "{":
                depth += 1
            elif c == "}":
                depth -= 1
                if depth == 0:
                    return src[start:i + 1]
        i += 1
    raise ValueError("bloque sin cerrar: " + name)


def parse_rows(block):
    """Extrae las listas de literales de cada `{ ... }` de nivel superior."""
    rows = []
    i = 0
    n = len(block)
    while i < n:
        if block[i] == "{":
            depth = 1
            j = i + 1
            in_str = False
            esc = False
            while j < n and depth > 0:
                c = block[j]
                if in_str:
                    if esc:
                        esc = False
                    elif c == "\\":
                        esc = True
                    elif c == '"':
                        in_str = False
                else:
                    if c == '"':
                        in_str = True
                    elif c == "{":
                        depth += 1
                    elif c == "}":
                        depth -= 1
                        if depth == 0:
                            break
                j += 1
            rows.append(re.findall(r'"((?:[^"\\]|\\.)*)"', block[i:j]))
            i = j + 1
        else:
            i += 1
    return rows


def c_unescape(s):
    """Convierte los escapes de un literal C (`\\n`, `\\t`, `\\"`, `\\\\`) a bytes reales."""
    out = []
    i = 0
    while i < len(s):
        if s[i] == "\\" and i + 1 < len(s):
            n = s[i + 1]
            if n == "n":
                out.append("\n")
                i += 2
                continue
            if n == "t":
                out.append("\t")
                i += 2
                continue
            if n == "\\":
                out.append("\\")
                i += 2
                continue
            if n == '"':
                out.append('"')
                i += 2
                continue
        out.append(s[i])
        i += 1
    return "".join(out)


def tsv_escape(s):
    """Escapa para el `.txt` (`\\n`, `\\t`, `\\\\`); el loader lo revierte al cargar."""
    return s.replace("\\", "\\\\").replace("\n", "\\n").replace("\t", "\\t")


def parse_menu_tr():
    src = open(MENU_CPP, encoding="utf-8").read()
    rows = [r for r in parse_rows(extract_block(src, "kMenuTr[]")[1:-1]) if len(r) == 6]
    # es, en, ca, fr, de, ja
    out = [{"es": c_unescape(r[0]), "en": c_unescape(r[1]), "ca": c_unescape(r[2]),
            "fr": c_unescape(r[3]), "de": c_unescape(r[4]), "ja": c_unescape(r[5])} for r in rows]
    return out


def parse_area_names():
    src = open(OVERLAY_CPP, encoding="utf-8").read()
    rows = [r for r in parse_rows(extract_block(src, "kAreaNames[9]")[1:-1]) if len(r) == 5]
    # en, es, ca, fr, de
    out = [{"en": c_unescape(r[0]), "es": c_unescape(r[1]), "ca": c_unescape(r[2]),
            "fr": c_unescape(r[3]), "de": c_unescape(r[4])} for r in rows]
    return out


def parse_existing_es():
    """Lee las entradas nativas ya presentes en assets/lang/es.txt (clave inglesa)."""
    out = OrderedDict()
    path = os.path.join(LANG_DIR, "es.txt")
    if not os.path.exists(path):
        return out
    for line in open(path, encoding="utf-8"):
        line = line.rstrip("\n")
        if not line or line.lstrip().startswith("#") or "=" not in line:
            continue
        k, v = line.split("=", 1)
        out[k.strip()] = v.strip()
    return out


def resolve_collisions(menu_tr):
    by_en = defaultdict(list)
    for row in menu_tr:
        by_en[row["en"]].append(row)
    resolved = []
    for en, rows in by_en.items():
        if len(rows) == 1:
            resolved.append(rows[0])
            continue
        keep = KEEP_ES.get(en)
        if keep is None:
            sys.exit(f"ERROR: colision de clave '{en}' sin resolver en KEEP_ES: "
                     f"{[r['es'] for r in rows]}")
        chosen = [r for r in rows if r["es"] == keep]
        if len(chosen) != 1:
            sys.exit(f"ERROR: KEEP_ES['{en}']='{keep}' no casa con una fila unica de {[r['es'] for r in rows]}")
        resolved.append(chosen[0])
    return resolved


def build_tables():
    native = parse_existing_es()
    menu_tr = resolve_collisions(parse_menu_tr())
    areas = parse_area_names()

    # tabla[lang][key] = value ; orden estable de insercion.
    tables = {lang: OrderedDict() for lang in LANGS}

    # 1) Texto nativo (solo es tiene entradas hoy).
    for k, v in native.items():
        tables["es"][k] = v

    # 2) Nombres de Area (clave = nombre ingles).
    for a in areas:
        for lang in LANGS:
            if lang in a:
                tables[lang][a["en"]] = a[lang]

    # 3) UI del port (gana sobre el nativo en colision de clave).
    for row in menu_tr:
        for lang in LANGS:
            tables[lang][row["en"]] = row[lang]

    # Informe de colisiones UI<->nativo resueltas a favor de la UI.
    print("=== claves del nativo sobrescritas por la UI ===")
    for lang in tables:
        for k, v in tables[lang].items():
            if k in native and native[k] != v:
                print(f"  [{lang}] {k!r}: nativo={native[k]!r} -> UI={v!r}")

    print(f"\nentradas: " + ", ".join(f"{lang}={len(tables[lang])}" for lang in LANGS))
    return tables


HEADERS = {
    "es": "Espanol (de serie). Clave = texto original en INGLES; valor = traduccion.",
    "ca": "Catala (de serie). Clau = text original en ANGLES; valor = traduccio.",
    "fr": "Francais (de serie). Cle = texte original en ANGLAIS; valeur = traduction.",
    "de": "Deutsch (de serie). Schluessel = Originaltext auf ENGLISCH; Wert = Uebersetzung.",
    "ja": "Nihongo (de serie). Clave = texto original en INGLES; valor = traduccion (kana UTF-8).",
}


def write_tables(tables):
    for lang in LANGS:
        path = os.path.join(LANG_DIR, f"{lang}.txt")
        with open(path, "w", encoding="utf-8") as f:
            f.write(f"# {HEADERS[lang]}\n")
            f.write("#\n")
            f.write("# Formato (sin cambios): CLAVE=VALOR, una por linea. `^` al inicio del valor = centrado por\n")
            f.write("# el motor. La clave inglesa es la fuente unica para la UI del port y para el texto nativo de\n")
            f.write("# la ROM. `en` = identidad (no hay en.txt). Escapes: \\n y \\t en clave o valor.\n")
            for k, v in tables[lang].items():
                f.write(f"{tsv_escape(k)}={tsv_escape(v)}\n")
        print("escrito", os.path.relpath(path, ROOT))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true", help="escribir assets/lang/*.txt")
    args = ap.parse_args()
    tables = build_tables()
    if args.write:
        write_tables(tables)
    else:
        print("\n(informe; usar --write para escribir)")


if __name__ == "__main__":
    main()
