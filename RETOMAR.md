# RETOMAR — recompilación per-file completa (reset)

> Handoff para la sesión nueva. **Contexto**: el port arranca y llega al combate, pero arrastra una
> cadena de bugs por una **recompilación mal hecha**. Se ha localizado la causa raíz y se decide
> **rehacer la recompilación per-file completa**. El enfoque/documentación anterior queda en `legacy/`.
> Última sesión: **2026-09-20 (noche-5)**.

---

## 0. OBJETIVO

Rehacer la **recompilación** de Hybrid Heaven (USA) siguiendo el método correcto (per-file con
fronteras de función reales y **todos** los ficheros de código), conservando del proyecto actual el
**runtime del juego** (libultra/RT64/audio/Controller Pak/trans_cache), el **tooling útil** y la
**estructura de proyecto**. Producto: un port nativo de PC (exe + ROM), **sin menús modernos**
(no `RecompFrontend`).

---

## 1. CAUSA RAÍZ (por qué se rehace)

La extracción de módulos era **incompleta y heurística**:

- La tabla **Nisitenma-Ichigo** (ROM US `0x39BF0`) tiene **625 entradas**; **91 son ficheros de
  código**. `tools/setup_module.py` extraía solo **11** (lista `MODULES` hardcodeada: índices
  7,8,9,10,12,23,24,25,54,55,99). **Faltaban 80**, incluido el **índice 56 = fichero 57 (combate)**.
- El fichero 57 se carga con un **segundo loader streamed** `FUN_80004838(id, dest)` (un trozo por
  llamada, descompresor `0x80003F44`), **no** por `file_load`/`FUN_80003824`. Solo envolvimos el
  primero → el 57 **nunca se registraba** en `func_map`.
- `0x80379410` es **inicio de `func_80379410` en el fichero 57** (base `0x80358820`) pero
  **mid-función** de `func_80379244` en el **fichero 56** (base `0x803757E0`, nuestra `M55`). Al no
  registrar el 57, el port ejecutaba el **mid-entry del 56** (sin prólogo, epílogo compartido `+0x58`)
  → **fuga de pila** → pisa el marco de `FUN_800011b0` (nodo de suscriptores `0x8005BF14`) →
  `[BADMQ]` → deadlock. Todos los `HH_M55SPFIX`/`HH_NO_B280`/… eran **parches de síntoma**.

**Comprobado**: `module56_be.bin` (índice 56) descomprime a `0x343A0` y en `0x80379410` tiene
`afa50004 30a500ff 14a00010 00001025` (sí, es `func_80379410` del 57). El `.text` plano de Ghidra
tenía además **120 funciones en rango de overlay** (código equivocado).

**Cómo lo hace el método correcto (Goemon / repo de referencia)**:
- `relocatable_sections_path` con **una sección por fichero** (`.file_NN`, `rom/vram/size` + funciones
  con fronteras reales, de decomp/desensamblado).
- El loader del juego **notifica** al runtime (`recomp_load_overlays(rom, ram, size)` /
  `unload_overlays`) → registro/desregistro por base (los overlays **se solapan y se intercambian**).
- **Nosotros** usábamos `relocatable_sections_path = ""` + `module_sources.inc` + wrappers manuales.

Referencias de consulta (solo consulta, no copiar): `danielgomesvieira2000/hybrid-heaven-recomp`
(issue `docs/issues/001-first-enemy-lookup-miss.md`) y `/app/goemon-sourcecode` (per-file + relocatable).

---

## 2. ESTADO ACTUAL (checkpoint)

- **Trabajo en el árbol**: fix parcial del 57 (módulo 56 extraído/recompilado + wrapper de
  `FUN_80004838` + `recomp_syscall_handler`), sin validar en Windows. Se conserva como referencia;
  **será sustituido** por la recompilación per-file. Ver §9 (repos).
- `legacy/` creado; `legacy/RETOMAR.md` es el handoff anterior. `legacy/README.md` explica el archivo.
- **Runtime nuevo ya añadido** (fork `N64ModernRuntime`): instrumentación de diagnóstico y el
  wrapper del loader streamed. Se conserva (útil), pero la capa de **registro de módulos**
  (`register_overlays.cpp` + `module_sources.inc`) se rehará al estilo Goemon.

---

## 3. DECISIONES (cerradas)

1. **Recompilación per-file completa** de los **91 ficheros de código** (no solo el 57).
2. **Fronteras con Ghidra por fichero** (proceso propio; no copiamos el `asm/` del repo de referencia).
3. **Ghidra es dependencia de DESARROLLO** (para regenerar syms), **no** de build/uso. El C recompilado
   se versiona; quien clona y compila **no** necesita Ghidra ni N64Recomp. Documentarlo en la sección
   de recompilación (`docs/workflows.md`/`tools/README.md`) + script de instalación.
4. **Sin `RecompFrontend`**: exe + ROM junto a él, aspecto de port nativo (sin menús modernos).
5. **Documentación**: lo viejo a `legacy/`; docs nuevas desde cero. Los docs **vivos** (p. ej.
   `PROYECTO.md`) → **copia a `legacy/` y reescribir la activa** reutilizando lo válido.
6. **Volumen de build**: incremental por lotes (residente → overlays por tandas), validando boot.
7. **`config/n64recomp_changes/`**: **conservar** (son parches al recompilador: `hh_mem_off`,
   fallback de `jal`, semántica `trunc.l`). Documentar cómo se aplican.

---

## 4. PLAN (fases)

### Fase 0 — Ghidra + deps de desarrollo
- Instalar `openjdk17` + Ghidra 11.x (release) en el entorno; wrapper `tools/ghidra_headless.sh`.
- Documentar en la sección de recompilación (no en prerequisitos de build).

### Fase 1 — Reorganización documental + commit "semi-recomienzo"
- `legacy/`: mover histórico (`notes/`, `docs/` viejos, `config/` obsoletos, bats de diagnóstico) y
  **copiar** los vivos antes de reescribirlos.
- Docs nuevas: `docs/documentation.md`, `docs/architecture.md`, `docs/workflows.md`, `AGENTS.md`,
  `PROYECTO.md`, `TODO.md`, `notes/`, `README.md`, `CREDITS.md` (revisar).
- **Primera nota nueva** (obligatoria): `notes/2026-09-20-lecciones-recompilacion-per-file.md` —
  el error cometido + **metodología generalizable** para recompilar otros juegos.

### Fase 2 — Pipeline per-file
1. **Manifiesto de code files** desde Nisitenma (`0x39BF0`) + tabla de VRAM del juego
   (runtime `0x80037C5C`, ROM `0x3885C`): `idx`, `file`, `src_rom`, `vram`, `size`, `crc`.
2. **Extraer** cada fichero (lzkn64, `tools/lzkn64`) → `work/scratch/file_NN.bin`.
3. **Desensamblar con Ghidra por fichero** → fronteras de función exactas → `asm/file_NN` + syms.
4. **Syms por fichero** (`.file_NN` con `rom/vram/size` + funciones). Regenerar el **`.text`
   residente** con Ghidra **excluyendo todos** los rangos de overlay.
5. **Config**: `game_*.toml` con `relocatable_sections_path` = lista de todos los ficheros;
   quitar `module_sources`/`register_overlays` manual.
6. **Loaders**: implementar `recomp_load_overlays`/`recomp_unload_overlays` y notificarlos en
   **ambos** (`FUN_80003824`/`0x8000469C` y `FUN_80004838`).
7. **Aplicar parches** de `config/n64recomp_changes/` al N64Recomp del toolchain (documentar).

### Fase 3 — Verificación y limpieza
- Completeness: nº secciones == code files; todo `jal` resuelve; sin solape flat/overlay;
  sin `do_break`/stubs ni `syscall` de datos-como-código.
- **Retirar workarounds** `HH_*` de síntoma (`HH_M55SPFIX`, `HH_NO_B280`, `HH_NO_DISABLE`,
  `HH_VI_EVERY`, `module_extras`, `add_mid_entry`) y re-evaluar.

### Fase 4 — Validar (boot + CaC, A/B emulador) y continuar plan maestro.

---

## 5. INVENTARIO keep / rewrite / legacy (repasar carpeta a carpeta)

- **Raíz**: keep `LICENSE`/`CREDITS`/`Dockerfile`/`docker/`/`.github`/`.devcontainer`; rewrite
  `README.md`; copiar-a-legacy + reescribir `PROYECTO.md`/`AGENTS.md`; legacy `RETOMAR`/`TODO`/`docs`/`notes`.
- **`tools/`**: keep `lzkn64/`, `rommy.py`, `build_linux.sh`, y diagnósticos (`diff_rdram`,
  `diff_state_at_vi`, `emu_ref.sh`, `r64dump.cpp`, `retro_dump.cpp`, `ring_syms`, `triage_screenshots`,
  `ppmascii`, `fbdecode`, `docs_index`, `bizhawk_*`, `analyze_mqa`, `validate_trans_cache`,
  `hhinput.c`, `xshot.c`); rewrite `recomp.py`, `setup_module.py`, `validate_syms.py`,
  `gen_ghidra_syms.py`, `fix_function_bounds.py`; legacy band-aids (`add_mid_entry`,
  `add_missing_funcs`, `gen_module_extras`, `check_syms_overrides`, `fix_ghidra_sizes`,
  `overlay_chunks`, `auto_syms_loop`, `merge_loop`, `scan_lzkn64_strict`, `test_lzkn64`,
  `detect_lzkn64`, `textseg`, `parse_exec_trace`, `fix_fallthroughs`).
- **`config/`**: keep `n64recomp_changes/`, `rsp_hh_aspMain.toml`; rewrite `game_*.toml`; legacy
  `us_*.syms.toml`, `*.fixed`, `keep_syms*`, `module_extras.json`, `merge_loop.py`, `RecompiledFuncs*`.
- **`port/HybridHeavenRecomp/`**: keep `src/main/main.cpp`,`icon.cpp`,`rt64_render_context.cpp`,
  `support.cpp`, `src/game/*`, `include/`, `rsp/hh_aspMain.cpp`, `assets/`, `lib/`; rewrite
  `register_overlays.cpp`(+`module_sources.inc`) y `CMakeLists.txt`; regenerar `RecompiledFuncs/`.
- **`port/*.bat`**: keep/adapt `build_windows*.bat`, `run_windows.bat`; legacy los diagnósticos CaC.
- **`work/`, `toolchain/`**: gitignored, regenerables.

---

## 6. HERRAMIENTAS / DEPENDENCIAS (desarrollo)

- **Build del port (usuario)**: C++ toolchain, CMake/ninja, SDL2, Vulkan/RT64 deps, Python + ROM.
  **No** Ghidra ni N64Recomp.
- **Regenerar la recompilación (dev)**: Python, `tools/lzkn64`, N64Recomp (con los parches de
  `config/n64recomp_changes/`), **Ghidra 11.x** (`analyzeHeadless`), JDK 17.

---

## 7. REPOS Y COMMIT

- **Main repo** (`origin` → `hunkstalker/hybrid-heaven-recomp`, `main`).
- **N64ModernRuntime** (fork, rama `hybrid-heaven`) y **N64Recomp** (fork, `hybrid-heaven`).
- Orden de push: **N64Recomp → N64ModernRuntime → main** (`port/runtime.lock` los pinea).
- Checkpoint actual: commit "semi-recomienzo / handoff" (ver `git log`). El árbol queda limpio.

---

## 8. PRIMEROS PASOS DE LA SESIÓN NUEVA

1. Leer `notes/2026-09-20-lecciones-recompilacion-per-file.md` (crear si no existe) y esta nota.
2. **Fase 0**: instalar Ghidra + wrapper; documentar.
3. **Fase 2.1**: generar el **manifiesto de los 91 code files** (Nisitenma + tabla VRAM).
4. Empezar por un fichero conocido (idx 56 / file 57) para validar el pipeline Ghidra→syms→N64Recomp,
   y luego generalizar a los 91.
5. Ir moviendo a `legacy/` lo obsoleto conforme se decide, y reescribir los docs vivos.
