# Capturar los glifos (gaiji) de la ROM EU con BizHawk

Objetivo: fijar **empíricamente** el layout del fichero de fuente EU y el mapeo `B0xx → glifo`, para
el paso 4 (acentos reales) del menú A2. Ver `notes/2026-09-25-c-font-eu-color4-localizada.md`.

## Por qué

El motor de texto del EU tiene **otro layout** que el US (direcciones y fichero distintos). La
deducción offline se contradice, así que capturamos **lo que el motor pone en RDRAM**.

## Script (ligero, no bloquea): `bizhawk_eu_glyph_capture.lua`

No engancha hooks (el hook global de escritura **bloqueaba** el emulador). Solo espera a que pulses
un **botón del mando** (por defecto **Start**) y hace **un volcado de RDRAM** (8 MB) en ese frame.

1. Crea la carpeta `hybrid-heaven-recomp\work\eu_glyphs\` (o edita `DIR` en el script; **barra final**).
2. BizHawk + ROM **EU**: `Tools → Lua Console → Script → Open` → `bizhawk_eu_glyph_capture.lua`.
3. Llega a una pantalla **con texto** y pulsa **Start** en 2-3 entradas/pantallas distintas (para
   tener snapshots de textos distintos). Cada pulsación = un fichero `eu_rdram_<NNN>.bin`.
4. Pásame la carpeta `work\eu_glyphs\`.

## Análisis (offline, en este repo)

```sh
# 1) ¿El motor copia tal cual los bloques de la fuente EU a RDRAM? -> localiza el buffer y el valor.
python3 tools/analysis/eu_glyphs_find.py work/eu_glyphs/ --blocks

# 2) Si no aparecen bloques exactos, heuristica por ventana cambiante + prueba de layouts.
python3 tools/analysis/eu_glyphs_find.py work/eu_glyphs/
```

- `--blocks` busca en cada snapshot los **32 B exactos** de cada glifo de la fuente EU conocida
  (`eu_dec.z64` @ vecindad del color0 US). Es lo más fiable: si hay coincidencia, sabemos `slot → RDRAM`.
- La heuristica por diff (sin `--blocks`) localiza la zona que cambia con el texto y prueba layouts.

> Los `.bin` (8 MB c/u) van en `work/` (gitignored). No versionar.

## Respaldo

`bizhawk_eu_glyphs_dump.lua` (vuelca RDRAM cada ~0.75 s): úsalo solo si el método por botón no basta.
