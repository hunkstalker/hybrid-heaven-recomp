# RETOMAR — handoff (2026-10-02)

> Handoff para la próxima sesión. **Rama de trabajo: `menu-carga-guardado-partida`** (creada desde
> `menu-edicion-partida`; nada pusheado; `main` = v0.5.1). Reglas: `AGENTS.md` y `docs/documentation.md`.
> (El editor/niveles vive en `menu-edicion-partida`.)
>
> **Sesión 2026-10-01 (commits ya en la rama)**: título del Área al cargar (`874b9f6`); **i18n — fuente
> única de traducciones** (`assets/lang/*.txt`, clave = inglés; ADR 0014); **pulido de menú/vídeo**
> (`CONTINUAR` gris sin partidas, `SALIDA` stepper, arreglo pantalla completa ↔ ventana); **tareas
> pequeñas de menú** (`DATA EDIT` fuera de `MODO COMBATE`, **letra de dificultad** en el slot, `AREA/
> LEVEL/TIME` traducidos, `ULTIMATE` fr y `NO DATA` fr a 2 líneas). Detalle: `notes/2026-10-01-i18n-*.md`,
> `notes/2026-10-01-menu-continuar-salida-fullscreen.md` y `notes/2026-10-01-slot-dificultad-y-traduccion.md`.

## ✅ HECHO y VALIDADO en Windows (2026-10-02): acentos/`¿`/`¡` en los mensajes del overlay

> **Tarea de la sesión (commiteada).** Los mensajes de la cápsula (DATA SAVE/LOAD) salían sin la `í`
> (`... aqu .`) ni el `¿`. **Causa `[MEDIDO]`**: la ROM US de `color4` solo trae **88 glifos** (sin
> acentos). Solución: **franja propia de acentos** en el atlas (`font.cpp`, `kAccentTop`, celdas 8x12
> por codepoint latin-1) consultada por `face_glyph_uv(Color4, c>=0x80)`, cocinando **`hh::kGameGlyphs`**
> (`include/hh/game_font_color4.h`) = la **misma tipografía `color4`**: glifos reales de color4 EU +
> compuestos letra-base color4 + marca (**no** `hh::kAccentGlyphs`, que son color0 8x8). `overlay.cpp`
> reutiliza el camino; fuera el hack del `?` girado para el `¿` y el CP437. Detalles finos: `í/ì/î/ï`
> sin punto y con 1 px de separación, sombra negra, `¿`/`¡` subidos 2 filas (no se cortan). Detalle/handoff:
> **`notes/2026-10-02-tildes-y-signos-en-mensajes.md`**. Ficheros: `src/subsystems/font.cpp`,
> `src/platform/overlay.cpp`, `tools/text/build_font.py`, `include/hh/game_font_color4.h`.

### Rótulo `AREA` del título — traducido (2026-10-02) — HECHO y VALIDADO en Windows
> El rótulo del título del Área estaba **hardcodeado** (`snprintf("AREA %d")`) → en ES salía sin tilde.
> Ahora usa la clave `AREA` de `assets/lang/*.txt` (`hh::menu::localized("AREA")`): `ÁREA`/`ÀREA`/`ZONE`/
> `BEREICH` (color0 los acentúa con las marcas del menú). El ancho se mide en **codepoints** (Á/À = 2
> bytes UTF-8). Fichero: `src/hooks/menu_overlay.cpp`. Detalle:
> **`notes/2026-10-02-titulo-area-rotulo-traducido.md`**.

### Transición del título del Área: fundido y hold (2026-10-02) — IMPLEMENTADO (2.ª validación pdte.)
> Fade por TIEMPO (`HH_TITLE_FADE_MS` 2000), **fade-out real** por el hilo de render (`fade_out_menu`,
> `HH_TITLE_FADEOUT_MS` 1000), hold `HH_TITLE_TRANS_MS` 400. Telón **opaco** (si se funde se cuela el
> título nativo) → funde solo el texto. Detalle: **`notes/2026-10-02-transicion-titulo-fade.md`**.

### Tareas pequeñas de menú (bloque anterior) — HECHO y VALIDADO en Windows (2026-10-01)
> `DATA EDIT` fuera; letra de dificultad en el slot; `AREA/LEVEL/TIME` traducidos; `ULTIMATE` fr y
> `NO DATA` fr a 2 líneas. Detalle: **`notes/2026-10-01-slot-dificultad-y-traduccion.md`**.

### Tareas de i18n (bloque anterior) — HECHO y VALIDADO en Windows
> Detalle en `notes/2026-10-01-i18n-unificar-traducciones-plan.md` §8.

### i18n — una sola fuente de traducciones (bloque anterior) — HECHO y VALIDADO en Windows
> Clave = **texto original en inglés**; ficheros `assets/lang/<code>.txt` (`en` = identidad); el código
> solo referencia claves (`hh::text::translate`, que `hh::menu::localized` delega). Plan/evidencia:
> **`notes/2026-10-01-i18n-unificar-traducciones-plan.md`**.

### Hecho reciente — commit `874b9f6`: título del Área al cargar partida
Al cargar un slot, el nombre del Área (gráfico nativo intraducible) se pinta con **overlay propio**:
telón negro + `AREA N` (fuente del juego) + nombre en **Work Sans SemiBold incrustada**, traducido en
`en/es/ca/fr/de` (`ja` nativo). **Calibrado 1:1** con el original (ancho/alto/peso/métrica) y **salto de
línea** centrado cuando no cabe en el ancho visible (p. ej. 4:3). Candado anti-parpadeo; timing colgado
de la cadena nativa. Fuente **incrustada** (sin `.ttf` suelto; `licences/OFL.txt`). Además, reorg de
carpetas junto al exe: `assets/{lang,logos,sounds}`, `licences/`, `saves/{,templates}`. Detalle:
`notes/2026-10-01-titulo-area-carga.md` y `...-calibracion.md`.
- **Pendiente menor**: recompilar Windows (limpio) para regenerar estructura + embebido.
- **Decisión abierta**: ¿inglés usa overlay (actual) o nativo 1:1 (cambiar `!= "ja"` por `!= "en"`)?

---

## VALIDADO en Windows (2026-10-01): UI de CARGA en `CONTINUAR` (`LoadGame`)

Tarea anterior, **HECHA y VALIDADA**. Documento maestro: **`notes/2026-10-01-cargar-partida-continuar.md`**.
- **Entrada** `CONTINUAR`: título → UI de carga **limpia** (sin superposición del título/logo, sin
  parpadeo, sin retardo). `g_load_enter` + hook `func_800179B0` (no dibuja el aviso de Controller Pak).
- **Carga real** (A): deserializa el slot (`func_801423C8`) y arranca la escena replicando la rama de
  ÉXITO nativa (`func_80142570` + `func_800179B0` + `func_801C11BC` + callback `func_801C3E24`).
- **Borrado** (X): `Remove play data?` → `Remove completed.` → A vuelve a la lista.
- **Vuelta** (B): cinemática nativa → **menú de título** (fix `close_load_game` retira `LoadGame`).
- Flujo por fases `hh::menu::LoadPhase` (`Browse`/`ConfirmDelete`/`Removed`, +`Loaded` reservado).
- Traza de diagnóstico: `run_load_trace.bat` (`HH_LOAD_TRACE`).

> Nota: la carga sigue siendo **DIRECTA** (`hh_do_load_game`, rama de ÉXITO replicada). Se probó a
> dejar que la máquina nativa del file-select hiciera `state 2→3→4` inyectándole A, pero se **congela
> en state 3** (su gate de mensaje `D_8008EE78` no se limpia en el port). Verifica: `notes/2026-10-01-titulo-area-carga.md` §3.

### Guardado (`DATA SAVE`) — VALIDADO (2026-09-30 / 10-01)
Guardar (`NEW GAME`/sobrescribir) · **AREA 1-1** · **TIME** · salida de la cápsula · reentrada ·
borrado de slots · mensaje de `Select` con bindings. Detalle:
**`notes/2026-09-30-save-capsule-logica.md`** (su §8ter: borrado; §9: recetas reutilizables).

---

## Aviso de método (AGENTS)
- Distinguir **medido** de **inferido**; no concluir comportamiento de ejecución sin evidencia
  (oráculo/Windows); no inventar UI ni fórmulas.
- **Un tema = un commit**; **no commitear/pushear** sin que lo pida el mantenedor.
- No validar el caso "todo vacío" con un `.pak` con datos.

### Pendientes menores (aparcados)
- **JA**: restos sin consolidar (`Face::Color1`, `？/！` en `jp_kana.h`); kana útil solo de
  `color0`/`color1`; el kanji vive en `color3` **JP** (no lo tenemos).
- **UI de GUARDAR**: sigue publicándose como COPIA de la de cargar sobre el DATA SAVE nativo; afinar
  a 1:1 si se pide.

---

## Contexto vivo
- **DEPENDENCIA DE FORK:** la rama necesita 2 commits de `N64ModernRuntime`: `9b14604`
  `hh_pak_reload_from_disk()` y `3523bf3` `PAK_SIZE=0x40000` (publicado). Gitlink bumpeado en
  `dbb209a`. ADR: `docs/adr/0013-pfs-virtual-ampliado-y-pak-de-n-slots.md`.
- **Plan de fondo**: "Menú propio de CARGAR/GUARDAR partida (un `.pak` con N=74 slots: 45 partidas +
  29 plantillas, trailer de metadatos)": **`notes/2026-09-29-menu-cargar-guardar-partida-plan.md`**.
  UI Fase 2/3: `notes/2026-09-29-menu-cargar-guardar-fase2-ui.md`. Tipografías:
  `notes/2026-09-30-tipografias-data-load-hallazgos.md`.
- **ESTRATEGIA DE MERGE**: `menu-carga-guardado-partida` es **DERIVADA** → **no** va a `main`. Al
  terminar: merge a **`menu-edicion-partida`**; luego → **`main`**.
- **Puntos de guardado del mantenedor**: `notes/reference/saveedit/PUNTOS_DE_GUARDADO.md`.
- **Áreas-Partes**: `notes/2026-09-29-editor-area-parte-plan.md`. Pendientes vivos: (a) validar en
  Windows `EXTRAS > IR A ÁREA` + `DEBUG NIVELES`; (b) "mover mi partida a una Área-Parte" (§6bis);
  (c) "volver al menú desde el gameplay" (el idx 7 daba la intro pero hoy crashea).

---

## Cómo trabajar (rápido)
- Build Linux: `cmake --build build/linux --parallel $(nproc)`.
- Build Windows: `rmdir /s /q hybrid-heaven-recomp\build\windows` + `hybrid-heaven-recomp\build_windows_release.bat`.
- Traza de carga: `hybrid-heaven-recomp\run_load_trace.bat`. Guardado: `run_save_trace.bat`.
  Combate/campo: `run_battle_trace.bat` (F12), `run_field_watch.bat` (`HH_WATCH_ADDR`).
- Regenerar C recompilado: `python3 tools/regenerate.py` (no se versiona; ADR 0009/0011). Tras
  regenerar: `python3 tools/analysis/fix_fallthroughs.py`.
- Docs: `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`; `--check` valida).

## Git / forks
- Rama **`menu-carga-guardado-partida`**; **nada pusheado**. Commitear solo lo validado/docs y con
  permiso. Push (si se pide): **forks primero** (`N64Recomp`, `N64ModernRuntime`), luego el repo
  principal (ver `AGENTS.md`).
