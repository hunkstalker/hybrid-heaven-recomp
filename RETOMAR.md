# RETOMAR — handoff (2026-10-01)

> Handoff para la próxima sesión. **Rama de trabajo: `menu-carga-guardado-partida`** (creada desde
> `menu-edicion-partida`; nada pusheado; `main` = v0.5.1). Reglas: `AGENTS.md` y `docs/documentation.md`.
> (El trabajo del editor/niveles vive en `menu-edicion-partida`.)

## 🎯 TAREA ACTUAL: cuadrar el TEXTO del título del Área con el ORIGINAL

Al cargar una partida (`CONTINUAR` → slot) el juego muestra **pantalla negra con el título del Área**
(el nombre del Área del progreso). El port ya lo pinta con **overlay propio** (el nombre nativo es un
**gráfico intraducible**, no texto). **La función está hecha y verificada headless**; lo que falta es
**afinar el texto** para que se vea 1:1 con el original y **validarlo en Windows**.

### Hecho (esta tanda)
- **Work Sans SemiBold** para el nombre, **INCRUSTADA** en el exe (CMake genera el array en configure; el
  `.ttf` **no** se distribuye suelto) + `licences/OFL.txt` (SIL OFL-1.1). Para **iterar sin recompilar**
  se puede forzar un `.ttf` con `HH_TTF=<ruta>` (release: solo la incrustada).
- **Overlay del título** (`hh::menu_overlay::publish_area_title`): telón negro a **pantalla completa** +
  `AREA N` (fuente del juego color0, posición nativa, **sin tocar**) + nombre en Work Sans (traducido).
- **Idiomas**: overlay+traducción en `en, es, ca, fr, de`; **`ja` nativo**. Tabla de nombres en
  `src/hooks/menu_overlay.cpp` (`kAreaNames`; el ORIGINAL medido del juego, p. ej. `Dr.Bross lab`).
- **Timing**: cuelga de la cadena nativa (`func_801C3F48` fade → `func_801C4018` espera →
  `func_801C4074` transición). **Anti-parpadeo**: `hide_now()` no puede borrar el título mientras está
  activo (candado) y se mantiene ~900 ms tras la transición (cubre el nombre nativo hasta el gameplay).
- Hooks registrados **siempre** (`func_801C3F48`/`func_801C4018`/`func_801C4074`/`func_8013EA54`); el
  índice del Área (`func_8013EA54`→`D_801CCAE0`) no depende de `HH_LOAD_TRACE`.
- Nombres originales (US) medidos, p. ej.: 1 `bioweapon storage facility`, 2 `Dr.Bross lab`,
  5 `underground shelter lowest area`, 9 `underground shelter top level`. Evidencia:
  `work/area_titles_montage.png`.

### Pendiente (TAREA)
1. **Afinar el texto** hasta que se parezca al original. **Defaults CALIBRADOS [MEDIDO] (esta tanda)**:
   anclando en el `AREA N` (que NO se toca), el nombre del original mide **~200.6 v × 14.1 v** (aspecto
   14.2; = 0.8358·alto / 0.4400·ancho); Work Sans "natural" mide ~180 v a 14.1 v de alto → se compensa
   el ancho, y **`word_space`** (Work Sans mete los espacios ~40 % más estrechos que el original).
   **Peso = SemiBold (600)** (medido: el trazo del original cae entre Medium y SemiBold; Bold sobra).
   Defaults fijados en `publish_area_title` (`src/hooks/menu_overlay.cpp`): `HH_TITLE_SCALE=0.80`,
   `HH_TITLE_STRETCH=1.10`, `HH_TITLE_TRACK=-0.27` (negativo: las letras **se tocan**, como el original),
   `HH_TITLE_WORDSPACE=5.67`, `HH_TITLE_Y=111.0` (ancho total fijo ≈200.6 v). Mocks:
   `work/area_title_match_mock.png`, `work/area_title_weight_mock.png`, `work/area_title_metric_mock.png`,
   `work/area_title_variants.png` (estirado vertical).
   **Fuente INCRUSTADA (hecho)**: `CMakeLists.txt` incrusta `WorkSans-SemiBold.ttf` (único peso) en el
   exe; no se copia `.ttf` junto al exe (solo la licencia, en `licences/OFL.txt`). Para iterar:
   `HH_TTF=<ruta>`; en release, incrustada.
   - **Nota**: `HH_TITLE_SCALE=1` (lo que probó el mantenedor) da ~241 v de ancho (**~20 % más ancho**
     que el original); no cuadra 1:1. Si prefiere ese tamaño, basta con `HH_TITLE_SCALE=1` por entorno.
   - Knobs por entorno (sin recompilar): `HH_TITLE_SCALE` (ancho), `HH_TITLE_STRETCH` (alto),
     `HH_TITLE_TRACK` (**+ = separa**, − aprieta), `HH_TITLE_Y` (línea base), `HH_TITLE_NUM_Y`
     (`AREA N`, def `89`, NO tocar).
   - **OJO**: el tracking **sí** funciona (0→3.0 cambia el ancho 861→1131 px). Si "no le cambia", su
     **build es antiguo** → recompilar.
2. **Validar en Windows**: tamaño/posición/fade/tiempos 1:1; sin parpadeo; `en/es/ca/fr/de` y `ja`.
   - **Salto de línea**: en **4:3** los 4 nombres más largos (A7 es/ca, A5 de, A9 de) se parten en 2
     líneas centradas (ancho visible real; en 16:9 no cambian). Ver nota de calibración §3bis.
   - Build: `rmdir /s /q hybrid-heaven-recomp\build\windows` + `hybrid-heaven-recomp\build_windows_release.bat`.
3. **Decidir** si inglés usa overlay (actual) o nativo 1:1 (cambiar `!= "ja"` por `!= "en"`).
4. **Limpieza (HECHA)**: fuente **incrustada** (SemiBold) y **sin copia** de `.ttf` junto al exe;
   en `assets/fonts/` solo `WorkSans-SemiBold.ttf` + `OFL.txt`. **Eliminado** el scaffolding de test de
   la tarea: `HH_SET_AREA`, `HH_MAKE_AREAS`, `HH_AUTOPLAY`, `HH_DUMP_AREA` (dump `hh_area_rdram.bin`).
   Se **conservan** `HH_LOAD_TRACE` (lo usa `run_load_trace.bat`) y `HH_FONT_TRACE` (diagnóstico de
   fuentes preexistente). `work/*` (mocks) se conserva (gitignored).
   El mantenedor **acepta el salto de línea sin validarlo en Windows** (se fía).
5. **Un tema = un commit**; no commitear/pushear sin permiso.

### Archivos tocados (sin commitear)
- `CMakeLists.txt` (incrustar **SemiBold**; sin copia de `.ttf`), `assets/fonts/{*.ttf,OFL.txt}`, `CREDITS.md`.
- Nuevos: `include/hh/ttf.h`, `src/subsystems/ttf.cpp` (rasteriza Work Sans con stb_truetype).
- `include/hh/overlay.h`, `src/platform/overlay.cpp` (`TtfText`, `word_space`, `visible_width`, hold).
- `src/hooks/menu_overlay.cpp` (`publish_area_title`, tabla de nombres, calibración, salto de línea, candado).
- `src/hooks/sections.cpp` (hooks del título, supresión nativa, timing, candado).
- Diagnóstico/test: **eliminado** `HH_SET_AREA`/`HH_MAKE_AREAS`/`HH_AUTOPLAY`/`HH_DUMP_AREA`; se
  conservan `HH_LOAD_TRACE` (tooling) y `HH_FONT_TRACE` (diagnóstico de fuentes).

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
