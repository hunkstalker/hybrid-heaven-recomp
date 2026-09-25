# RETOMAR — handoff

> **Handoff para la próxima sesión** (última: **2026-09-25**). Corto: estado, siguiente tarea y Git.
> El **diseño** y la **técnica** viven en `docs/` y `notes/`; aquí solo se enlazan. Reglas: `AGENTS.md`.
> **Rama de trabajo: `menu-nativo`** (el `main` es la release; ver §Git).

## Estado

- **A2 (overlay del menú inicial)**: render hook de RT64 + plume + atlas RGBA8 de la fuente del juego.
  Validado en Windows en la fase A (`notes/2026-09-23-a2-render-hook-y-atlas.md`).
- **`hh_menu`**: modelo del árbol + dibujo 1:1 + **menú nativo oculto** (F6 lo alterna). Los **3 bugs
  del overlay** validados en Windows (`82df034`).
- **Paso 5 HECHO (headless; falta Windows)**: navegación propia (A/B, sin X) + **control total** (input
  del handler nativo muteado + temporizador de inactividad a tope). `feed_menu_navigation`.
- **Dibujo de menú HECHO**: listas (aplicada verde, resto gris); selectores (`NO/SÍ` o `< valor >` con
  flechas dibujadas); **dígitos, `:` `.` `%` dibujados**. Árbol: NUEVA PARTIDA =
  `EMPEZAR PARTIDA / DIFICULTAD / CÁMARA LIBRE / APUNTADO LIBRE / IDIOMA`; GRÁFICOS = `RATIO` (filtra
  `RESOLUCIÓN`) / `RESOLUCIÓN` / `P. COMPLETA` / `ANTIALIASING` / `VSYNC` / `LÍMITE DE FPS`; SONIDO =
  `VOLUMEN` / `SALIDA` / `MENÚ SFX`; DEBUG = `VENTANA DEBUG` + `MOSTRAR FPS`.
  `HH_MENU_SCREEN`: `6`=GRÁFICOS, `5`=IDIOMA, `7`=SONIDO, `8`=DEBUG.
- **Paso 6 (acciones) CASI HECHO (validado headless; falta Windows)**: `RATIO`, `RESOLUCIÓN`,
  `P. COMPLETA`, `ANTIALIASING`, `VSYNC`, `LÍMITE DE FPS`, `MOSTRAR FPS` y `VENTANA DEBUG` aplican en
  vivo y **persisten en `config.ini [video]`**; `SONIDO` (`VOLUMEN`/`SALIDA`/`MENÚ SFX`) persiste en
  `[audio]`. Escritor compartido `hh::config_ini_set` (`include/hh/config_ini.h`). Ventana `windowed`
  con geometría recordada (`win_*`) → `res` concreta → nativa. `MOSTRAR FPS` mide presents reales.
  **Ver VSYNC** con `HH_FPS=1` (la línea `[hh-fps]` incluye `vsync=0|1` real).
- **Paso 7 SFX HECHO (headless; falta Windows)**: `Move`/`Accept`/`Back` desde los eventos del modelo
  (`feed_menu_navigation`); puente retirado. `MENÚ SFX = NO` los silencia. `.wav` de `sounds/` son
  personalizables (mismos nombres, 48 kHz/S16/estéreo).
- **Fix ROM** (cherry-pick de `main`) integrado.
- **`LÍMITE DE FPS`**: `NATIVO/30/40/60/75/90/120/144/165/240` (recorta al refresco del monitor).
- Diseño del menú: **`docs/menu.md`**. Técnica: **`docs/architecture.md` §7**.

## SIGUIENTE TAREA: acentos reales del overlay (paso 4)

**Decisión tomada: usar los glifos REALES de la ROM EU** (no inventar/componer). Estado de la
investigación (todo en **`notes/2026-09-25-c-font-eu-color4-localizada.md`**):

- **Fuente EU "idioma" localizada**: `work/roms/eu_dec.z64` @ **`0x8C3298`**, **114 valores**, formato
  **idéntico al US**: 32 B por **par de valores** (`bloque = v>>1`), paridad `v&1` elige el plano; 8×8
  2bpp, 2 px/byte (nibble). US = 66 valores (2112 B, `idx108` @ `0x6E4CD6`); EU = 114 (3648 B).
  **El fichero EU está reordenado por completo** (solo 1 bloque coincide con US). Validado: `v1`="1",
  `v2`="2"; los valores altos son los acentos reales (Ü, Ä, Ö, À, Ç, É, Ê, Î, Ì, Ù, ü, ö, ß…).
- **Hoja legible**: `python3 tools/text/extract_eu_font.py --sheet work/fonts/eu_all.png` (114 glifos
  etiquetados por valor). Herramienta en `tools/text/extract_eu_font.py`.
- **El menú vanilla EU no se tradujo** (sigue en inglés); los acentos están para texto in-game y partes
  traducidas, pero **la fuente con tildes existe** y es la que hay que usar.

### Pasos concretos para retomar

1. **Identificar** cada valor EU (0..113) con su Unicode leyendo `work/fonts/eu_all.png` (los 0-65 son
   letras/dígitos/símbolos; 66-113 son acentos + símbolos). Construir una tabla `Unicode → valor EU`.
   - Pista de anclajes ya confirmada por texto DE/FR: `B0B2=ä, B0B3=â, B0B4=à, B0B7=ê, B0B8=è,
     B0B9=é, B0BA=ü, B0BF=ö, B0C1=ç, B0CA=ß` (falta mapear `B0xx → valor`; la tabla del motor EU no
     está en las mismas direcciones que US — investigar o deducir por forma).
2. **Integrar en el overlay**: el atlas (`src/subsystems/font.cpp`) usa hoy `color0` 8×8 US
   (`tools/text/gen_accent_glyphs.py` **compone** acentos; se quiere **sustituir por los reales**).
   Opciones: (a) ampliar el atlas del overlay con los bloques EU de los acentos reales; (b) migrar el
   overlay a la fuente EU. Decidir y regenerar el atlas.
3. **Quitar el plegado `to_ascii`** en `src/hooks/menu_overlay.cpp` y mapear UTF-8 → valor/atlas.
4. **Validar** con `HH_MENU_SCREEN=5` (IDIOMA), `=6`/`=7` y navegando. Luego Windows.

**Nota catalán/francés**: la PAL no trae `Ò`/`ò` grave ni `œ`; el catalán necesita `·` (punt volat)
y `l·l`. Si falta algo, **derivar** (p. ej. girar 180° el `Ó`) — decisión del mantenedor: **glifos
reales primero; lo que no exista, derivar**.

### Utilidades dejadas para la captura (BizHawk, ROM EU)

- `tools/analysis/bizhawk_eu_glyph_capture.lua` (v3): al pulsar **`L`** (LB) guarda un volcado de RDRAM
  (8 MB) + PNG + registros. **No bloquea** (sin hooks). `MARK_BUTTON` configurable.
- `tools/analysis/eu_glyphs_find.py --buf 0x80109B60 --render`: analiza volcados.
- Guía: `tools/analysis/README_eu_glyphs_dump.md`. **Lección**: `memory.getmemorydomainlist()` (no
  `getmemorydomains`); dominio N64 = **"System Bus"**. El hook `event.onmemorywrite` **bloquea** el
  emulador (descartado). El motor **compone** los glifos (no copia bloques).
- Los volcanes de 8 MB se redujeron a ventanas `.buf/.tex` en `work/eu_glyphs/small/` (gitignored).

### Otros pendientes del menú (después de acentos)

- **Acciones restantes del paso 6**: `DIFICULTAD` + `EMPEZAR PARTIDA` (arrancar partida nueva con la
  dificultad interna del juego) y `CONTINUAR`. **`CÁMARA LIBRE`/`APUNTADO LIBRE`**: requieren modificar
  el juego, **aparcado**.
- **IDIOMAS**: en la **EU** el selector de idioma vive en la **misma pantalla** que EMPEZAR
  PARTIDA/DIFICULTAD (referencia para recolocar nuestro `IDIOMA`).
- **Validar en Windows**: paso 5 + dibujo + DEBUG + GRÁFICOS/geometría + SONIDO/SFX/fix ROM.

## Git (estado al cerrar esta sesión)

- **Rama de trabajo: `menu-nativo`** (WIP del menú). Último commit: **`0b7eb4d`** (fuente EU extraída).
  Contiene TODO el trabajo posterior a **v0.4.0** + el fix ROM.
- **Sin push**: `origin/menu-nativo` sigue en `4a989d5`; el local va **muchos commits por delante**
  (todo lo de esta sesión). Al retomar: `git switch menu-nativo`; si `main` avanzó, `git merge main`.
- **`main` = release**: pendiente de la otra sesión subir `4600fa3` (SHA-1 + README) y tag `v0.4.1`.
- Commitear **solo** lo validado o la documentación (regla `AGENTS.md`). Árbol limpio salvo
  `docs/INDEX.md` regenerado (ver abajo).

## Método (rápido)

- **Build/run Windows**: `AGENTS.md` (build) + `docs/BUILDING_windows.md`. **Build Linux**:
  `cmake --build build/linux --parallel $(nproc)` (necesita `lib/` ya clonado).
  **Regenerar C recompilado**: `python3 tools/regenerate.py` (ADR 0009/0011; no se versiona).
- **Headless + replay para llegar al menú**: `docs/workflows.md` §2.
- **Diagnósticos** (`hh.log`): `HH_MENU_TRACE=1`, `HH_NATIVE=1`, `HH_OVERLAY_X/Y/SX/SY`, `HH_OVERLAY=0`,
  `HH_MENU_SCREEN=<id>`, `HH_FONT_TRACE=1`, `HH_FONT_DUMP_GLYPH=<color>`, `HH_ACCENTS=0`, `HH_LANG=es`,
  `HH_FPS=1`. Atajos: F2 aspecto, F3 ventana, F4 MSAA, F5 idioma, **F6 menú nativo**. Inspector RT64:
  `HH_DEVELOPER=1` + F1 (o `DEBUG → VENTANA DEBUG = SÍ`).
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso. ROM USA para el port:
  `build/linux/baserom.us.z64` (o cualquier `*.z64`, el nombre da igual). ROM EU (análisis):
  `work/roms/eu_dec.z64`. SHA-1 USA retail: `16dbc21620b52deab5c5abf8a309ac60adfbee85`.
- **Docs**: tras editar docs, `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`;
  `--check` valida enlaces y el presupuesto de arranque).
