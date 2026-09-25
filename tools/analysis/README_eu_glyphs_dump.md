# Capturar los glifos (gaiji) de la ROM EU con BizHawk

Objetivo: fijar **empíricamente** el layout del fichero de fuente EU y el mapeo `B0xx → glifo`, para
el paso 4 (acentos reales) del menú A2. Ver `notes/2026-09-25-c-font-eu-color4-localizada.md`.

## Por qué

El motor de texto del EU tiene **otro layout** que el US (direcciones y fichero distintos). La
deducción offline se contradice, así que capturamos **el bloque real** que el motor compone.

## Opción A (preferida): captura por hook de escritura

`tools/analysis/bizhawk_eu_glyph_capture.lua` engancha las escrituras a RDRAM (`event.onmemorywrite`)
y guarda los bloques "tipo glifo" (con PC y A1) en `eu_glyph_writes.log`. Es la vía más directa: al
componer un acento, el bloque queda registrado tal cual.

1. Edita `DIR` (carpeta existente, con barra final).
2. BizHawk + ROM **EU**: `Tools → Lua Console → Script → Open` → el script.
3. Llega a una pantalla **con texto** (menú de opciones/pausa: ayuda DE/FR) y pulsa **F12** unas
   cuantas veces durante ~10 s para forzar la composición de glifos (incl. acentos).
4. Pásame `work/eu_glyphs/eu_glyph_writes.log`.

> **Aviso**: el hook de escritura puede ir lento (se dispara mucho). Si BizHawk se arrastra, usa la
> Opción B o reduce el tiempo.

## Opción B (respaldo): volcados periódicos de RDRAM

`tools/analysis/bizhawk_eu_glyphs_dump.lua` vuelca RDRAM completa (8 MB) cada ~0.75 s. Offline se
localiza el buffer por diff:

```sh
python3 tools/analysis/eu_glyphs_find.py work/eu_glyphs/
```

Salida: `work/eu_glyphs/eu_rdram_*.bin` + `eu_rdram_index.txt`. Repetir en 2-3 pantallas con texto
distinto.

> Los `.bin` (8 MB c/u) van en `work/` (gitignored). No versionar.
