# FPS/interpolación — Partículas del heal: NO es bug (asset original) + herramientas de volcado (2026-10-04)

> Cierre de la investigación de las **partículas de sprites al curarse** (los "cuadrados con degradado").
> Resultado: **no es un fallo** — es el **asset original del juego**; el port coincide con el emulador.
> Se cierra como no-bug. De paso se añadieron herramientas de volcado de texturas. Ver también el bug
> latente (lateral, corregido) en `notes/2026-10-04-fps-walker-dl-comandos-extendidos-latente.md`.

## 1. Síntoma

Al curarse, las partículas se veían como **quads translúcidos con borde recto y degradado** en vez de
"estrellas/copos". Algunas **sí** salían como estrellas finas. No era un artefacto de 1 frame: se veía
sostenido.

## 2. Qué descartamos (MEDIDO)

- **No es interpolación**: **F9** (toggle interpolación ON/OFF) → se ve **igual**.
- **No es el tagging**: A/B `HH_MTXGROUP`/`HH_EMIT_TAG` ON vs OFF → se ve **igual**.
- **No es (a) core** ni los gates de escala/rotación.
- **No es una regresión del port por tocar RT64**: el emulador muestra **lo mismo**.

## 3. Qué es (MEDIDO)

Los "quads" son el **asset original**: el heal usa una **textura cuadrada de glow** (8×8, degradado
suave) y una **estrella** (16×16). Se confirmó con **dump de texturas**:

- **Port**: `HH_TEXDUMP=<dir>` (RT64) → `tools/analysis/decode_texdump.py` → PNG.
- **Emulador** (Project64): dump de texturas del heal → mismas dos texturas (cuadrada + estrella).
- Port y emulador **coinciden** → **no hay bug**.

(El frame en que "todo eran estrellas" era uno donde solo se veían las estrellas.)

## 4. Herramientas añadidas (commit `63a5b70`)

- `HH_TEXDUMP=<dir>` (`src/platform/rt64_render_context.cpp`): volcado automático de cada textura única
  de RT64 (`<hash>.v5.{tmem,tile.json,rice.rdram,…}`) → equivale a Inspector→Textures→Start dumping.
- `tools/analysis/decode_texdump.py`: decodifica a PNG (RGBA/CI/IA). Portado de la línea logos/intro.
- Pista: las **CI** (fmt=2) del dump del port salieron sin `.rice.palette.rdram` → decodifican como
  ruido; para futuros assets CI, usar el dump del emulador o reconstruir la paleta.

## 5. Lección de método

Antes de dar algo por bug de port: **comparar con el emulador** (y, si se duda de su fidelidad, con el
**RDP software/Angrylion**). Y ojo: `unpaired`/capturas **no** miden el render estático.

## 6. Hallazgo lateral

Mientras se investigaba esto se encontró un defecto **latente** en los walkers de DL
(`src/hooks/dl_snap.cpp`), **independiente** de las partículas y **corregido** en `a8212b3`:
`notes/2026-10-04-fps-walker-dl-comandos-extendidos-latente.md`.
