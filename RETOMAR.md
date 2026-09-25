# RETOMAR — handoff

> **Handoff para la próxima sesión.** Corto: estado, siguiente tarea y Git.
> **Diseño** y **técnica** viven en `docs/` y `notes/`; aquí solo se enlazan. Reglas: `AGENTS.md`.
> **Rama de trabajo: `menu-nativo`** (el `main` es la release; ver §Git).

## LO PRIMERO: sincronizar con `main` (merge `main` → `menu-nativo`)

`menu-nativo` salió de **v0.4.0** (`c977bd5`) y `main` ya publicó **v0.4.1–v0.4.4** (fixes del HUD de
combate POWER/STAMINA/combo/stamina y del minimapa, captura **F7**, toggles F8–F10). Hay que traerlos
a esta rama **antes** de seguir/validar. **No** mergear todavía `menu-nativo` → `main`: es WIP sin
validar en Windows; será la **futura feature release** (probablemente **v0.5.0**) cuando esté completa.

**Método**: `git switch menu-nativo && git merge main` — **merge, no rebase** (`menu-nativo` ya está en
`origin`; reescribir 60 commits es malo). Antes conviene: tag de checkpoint y **pushear `menu-nativo`**
(`origin/menu-nativo` va detrás).

**Conflictos esperados (~14 ficheros "changed in both", medido con `git merge-tree`)**: `.gitignore`,
`AGENTS.md`, `PROYECTO.md`, `README.md`, `RETOMAR.md`, `TODO.md`, `build_windows.bat`, `docs/INDEX.md`,
`include/hh.h`, `src/hooks/dl_snap.cpp`, `src/platform/main.cpp`,
`src/platform/rt64_render_context.cpp`, `src/platform/support.cpp`, `src/subsystems/input.cpp`.
- `src/hooks/hud_rewrite.cpp` **no** aparece → los fixes de HUD (issue #3/#7) llegan **limpios**;
  el riesgo está en la **API/teclas**, no en la lógica del anclaje.
- **Conservar de `main`**: fixes de HUD, captura **F7** + toggles **F8–F10**, `kVersionPatch` y docs.
- **Conservar de `menu-nativo`**: lógica del menú, **F5** idioma / **F6** menú nativo, idiomas/acentos.
- **Reconciliar con cuidado**: `input.cpp` (teclas), `include/hh.h` (API), `support.cpp` y
  `rt64_render_context.cpp` (aquí chocan los toggles de video/render de `main` con el menú), `main.cpp`
  (init) y los docs (`RETOMAR`/`TODO`/`PROYECTO`/`README`/`INDEX`).
- Tras resolver: `cmake --build build/linux` y `python3 tools/analysis/docs_index.py`.

No cerrar el merge “a ciegas”: compilar Linux **y** validar en Windows (ver §SIGUIENTE TAREA).

## Estado

- **Menú inicial (`hh_menu`) COMPLETO**: modelo, dibujo 1:1, menú nativo oculto, navegación propia
  (A/B, control total), acciones (RATIO/RESOLUCIÓN/P. COMPLETA/ANTIALIASING/VSYNC/LÍMITE DE FPS/
  MOSTRAR FPS/VENTANA DEBUG → `[video]`; SONIDO → `[audio]`) y SFX por eventos del modelo.
- **Acentos + idiomas HECHO (2026-09-25, headless)**: ver `notes/2026-09-25-d-menu-multilingue-...md`
  y **ADR 0012**:
  - Menú: **letra base color0 + marca** dibujada por el mantenedor (`tools/text/menu_marks.py` →
    `include/hh/menu_marks.h`; atlas 128×44). `¿ ¡` = `? !` girados.
  - **`IDIOMA` en `AJUSTES`** y **funcional** (cambia menú + texto in-game; persiste en
    `config.ini [lang]`). Etiquetas localizadas **en/es/ca/fr/de** (`hh::menu::localized`); lista en
    **endónimos**.
  - **Idioma del sistema** si no hay `[lang]` (Windows `GetUserDefaultLocaleName`; Linux `LANG`/`LC_*`),
    con fallback a **inglés**. Prioridad `HH_LANG` > `[lang]` > sistema > `en`.
- **Fuente in-game (8×12 `color4`) ES/CA/FR/DE preparada** (`tools/text/build_font.py` →
  `include/hh/game_font_color4.h`) pero **sin cablear** (hoy `text_glyphs.cpp` sirve un set 8×8 propio).
- **Idiomas en las ROMs**: EU = En/Fr/De; JP = ja (añadida a `work/roms/jp.z64`); ES/CA no existen.
- Diseño: **`docs/menu.md`**; ADRs **0008** y **0012**; técnica del overlay: `architecture.md` §7.

## BUG RESUELTO (2026-09-25, headless) — cambiar de idioma aceleraba el juego

**Causa (medida)**: `hh_trans_reapply_language` (`src/subsystems/trans_cache.cpp`) reescribía el módulo
entero desde el cache/ROM; el juego **modifica en caliente** esas regiones (relocaliza el módulo de
código `005F1190`@`801BF1A0`: 241 B; buffer de trabajo `0068BF26`@`803837E0`: 33889 B) y el reapply
las pisaba → `viOriginalRate` 30 → 60.

**Fix**: re-aplicar **solo** las posiciones cuyo contenido actual coincide con el testigo `written`
(los bytes que el port escribió en la carga, con traducción); se respetan los cambios del juego.
Además: poda de entradas que solapan una carga nueva, tope de memoria (32 MB) y knob de A/B
`HH_LANG_REAPPLY=0`. Detalle y evidencia: `notes/2026-09-25-e-fix-reapply-idioma.md`.

**Validado headless**: con `HH_FPS=1 HH_LANG_CYCLE_AT=15` el `vi` se queda en 30 y `present≈29.5`
(antes saltaba a 60 / ~54). **Falta confirmar en Windows** (ver tarea siguiente).

## SIGUIENTE TAREA: validar en Windows (paso 8)

No hay nada bloqueante de diseño. En Windows (build normal), comprobar:
1. **Menú 1:1** con el nativo, navegación, listas/selectores, SFX.
2. **Acentos**: abrir `NUEVA PARTIDA` y `GRÁFICOS` (`CÁMARA`, `GRÁFICOS`, `RESOLUCIÓN`, `LÍMITE`) y
   ver las tildes (letra + marca). Forzar con `HH_MENU_SCREEN=6`/`=5` si hace falta.
3. **IDIOMA** (en `AJUSTES`): cambiar a EN/CA/FR/DE y ver que **todo el menú** cambia (y el
   texto in-game con F5), **sin que el juego se acelere** (fix del reapply; ver §BUG RESUELTO).
   Persistencia en `config.ini [lang]`.
4. **Idioma del sistema**: borrar `[lang]` de `config.ini` y arrancar con el SO en otro idioma
   (p. ej. francés) → debe arrancar en ese idioma; un idioma no incluido → inglés.
5. Rotar el log para revisar `[text] idioma del sistema: ...`.

### Después (backlog de la tarea)

- **JA del menú**: embeber la **kana** del `color0` JP (o TTF) para que las etiquetas salgan en JA
  (hoy caen a inglés). `color0` JP tiene kana, no kanji.
- **Cablear** `game_font_color4.h` en `src/hooks/text_glyphs.cpp` (acentos del texto in-game).
- **Traducciones in-game**: extraer **DE/FR** de la ROM EU y **JA** de la JP (emparejar por módulo) →
  `assets/lang/*.txt`; redactar **ES/CA**.
- Pendiente funcional del menú: `CÁMARA LIBRE`/`APUNTADO LIBRE` (modifican el juego; aparcado),
  `DIFICULTAD`/`EMPEZAR PARTIDA`/`CONTINUAR` (arrancar/retomar con dificultad interna).

## Git

- **`menu-nativo`** (WIP del menú): todo el trabajo posterior a **v0.4.0** + fix ROM. **Sin pushear**
  (`origin/menu-nativo` va 25 detrás; **pushear antes del merge**, opcional).
- **`main` = release**: al día y pusheado, **v0.4.4** (v0.4.1–v0.4.4 publicadas). Traer `main` aquí con
  `git merge main` (ver §LO PRIMERO).
- Commitear **solo** lo validado o la documentación (regla `AGENTS.md`).

## Método (rápido)

- **Build/run Windows**: `AGENTS.md` (build) + `docs/BUILDING_windows.md`. **Build Linux**:
  `cmake --build build/linux --parallel $(nproc)` (necesita `lib/` ya clonado).
  **Regenerar C recompilado**: `python3 tools/regenerate.py` (ADR 0009/0011; no se versiona).
- **Headless + replay para llegar al menú**: `docs/workflows.md` §2.
- **Diagnósticos** (`hh.log`): `HH_MENU_TRACE=1`, `HH_NATIVE=1`, `HH_OVERLAY_X/Y/SX/SY`, `HH_OVERLAY=0`,
  `HH_MENU_SCREEN=<id>`, `HH_FONT_TRACE=1`, `HH_FONT_DUMP_GLYPH=<color>`, `HH_ACCENTS=0`, `HH_LANG=es`,
  `HH_FPS=1`. Atajos: F2 aspecto, F3 ventana, F4 MSAA, F5 idioma, **F6 menú nativo**. Inspector RT64:
  `HH_DEVELOPER=1` + F1 (o `DEBUG → VENTANA DEBUG = SÍ`).
- **Fuente/acentos**: `tools/text/menu_marks.py` (marcas del menú), `tools/text/build_font.py`
  (fuente in-game 8×12), `tools/text/README_font_sheet.md` (formato de las hojas). ROMs en `work/roms/`
  (`us_dec.z64`, `eu_dec.z64`, `jp.z64`).
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso. ROM USA para el port:
  `build/linux/baserom.us.z64` (o cualquier `*.z64`, el nombre da igual). SHA-1 USA retail:
  `16dbc21620b52deab5c5abf8a309ac60adfbee85`.
- **Docs**: tras editar docs, `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`;
  `--check` valida enlaces y el presupuesto de arranque).
