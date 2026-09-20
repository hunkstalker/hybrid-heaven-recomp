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

- **Hecho (2026-09-20, esta sesión)**: Fase 0-2.5 (manifiesto de los **91 code files**, extracción,
  **Ghidra per-file** → syms `.file_NN`, **N64Recomp completo rc=0**; port compila y arranca con las
  91 secciones). **Saneamiento**: el **C recompilado deja de versionarse** (obra derivada; **ADR 0009**)
  y se regenera con **`tools/regenerate.py`**; `.gitignore` + symlink `RecompiledFuncs` →
  `work/recomp/RecompiledFuncs`; **historia reescrita** (filter-branch) para eliminar el C del pasado
  (`.git` 15.4 → 1.6 MB; **force-push pendiente**). **Fase A.2**: loaders estilo referencia en
  `src/main/sections.cpp` (`file_table.h` + `announce_load` + hooks en `on_init`).
- **Regresión pendiente (BLOQUEANTE)**: el build per-file arranca pero **no pasa de la fase temprana**
  (solo carga `file_008`; el viejo cargaba `file_055` en `vi≈77`). A/B real viejo↔nuevo y conclusión
  (código idéntico; diverge registro/estado) en `notes/2026-09-20-pipeline-per-file-estado.md` §9-11.
- **Trabajo en el árbol**: el fix parcial del 57 (módulo 56 + wrapper streamed) queda **sustituido**
  por la recompilación per-file. Ver §7 (repos) y §8.
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
- **Historia reescrita (2026-09-20)**: se eliminó el C recompilado de **todos los commits**
  (`git filter-branch`, 258 commits; `.git` 15.4 → 1.6 MB). Los **hashes cambiaron** y `origin/main`
  queda divergente → **`git push --force-with-lease origin main`** (pendiente; hacerlo cuando la
  tarea valide). Respaldo del histórico previo: `git bundle` externo (no en el repo).

---

## 8. PRIMEROS PASOS DE LA SESIÓN NUEVA

> Hecho ya (esta sesión): Fase 0-2.5 (N64Recomp rc=0), saneamiento (ADR 0009, no versionar el C,
  `tools/regenerate.py`) y Fase A.2 (loaders estilo referencia). **Bloqueante**: el boot no avanza de
  la fase temprana (§2). Detalle y reproducción: `notes/2026-09-20-pipeline-per-file-estado.md`.

1. **Cerrar el diagnóstico de boot** (§10-11 de la nota): el código recompilado es idéntico al viejo;
   la cadena de callbacks de `file_008` **no llega a `func_801079B0`** aunque el dispatcher
   `FUN_80005270` corre. Comparar `func_map`/colas justo tras `func_80107830` viejo↔nuevo.
2. **Si se confirma**: cerrar Fase 3 (completitud: secciones == code files, todo `jal` resuelve, sin
   solapes/datos-como-código) y validar boot + CaC (sin workarounds `HH_*`).
3. **Fase C (purga)**: mover a `legacy/` lo obsoleto (`setup_module.py`, `module_sources.inc`,
   `config/us_*.syms.toml`, workarounds `HH_*`), split `recomp/`+`port/`, y **quitar del fork runtime**
   `register_module_sources`/`load_module_by_source`/`hh_wrap_FUN_80003848`.
4. **Force-push** (§7) cuando valide; actualizar `runtime.lock`/docs vivos si cambia el runtime.

---

# ▓▓ PLAN DE SANEAMIENTO (PRIORITARIO) ▓▓

> Objetivo: **una sola arquitectura de recompilación, sin código viejo innecesario, con el recomp
> nuevo funcionando**. Hoy el build es un **híbrido** (recomp per-file nuevo + registro de loaders
> viejo + residente reciclado) y por eso no arranca más allá de la fase temprana.
> **Orden crítico**: completar/migrar y validar **antes** de borrar. Limpiar antes puede quitar lo
> que hoy “tapa” el fallo.

## S0. Arquitectura objetivo (única)
- Recompilación **per-file**: 1 sección relocalizable por fichero de código (`.file_NN`) y el
  **residente `.text` generado con Ghidra por-file** (no reciclado de `us_ghidra.syms.toml`).
- **Registro por loader notificado**: implementar `recomp_load_overlays(rom, ram, size)` /
  `recomp_unload_overlays(ram, size)` y llamarlos desde **ambos** loaders (`FUN_80003824`/`0x8000469C`
  y `FUN_80004838`). **Sin** `module_sources`, **sin** `hh_stream_id_to_src`, **sin** wrappers
  manuales de registro.
- Config única `recomp/game.toml` (hoy `config/game_code_files.toml`).
- Artefacto versionado: el **C recompilado** (`port/HybridHeavenRecomp/RecompiledFuncs/`); las syms
  y el ROM combinado viven en `work/` (dev, gitignored) — salvo decisión explícita de versionar la
  syms agregada para reproducir sin Ghidra.

## S1. Inventario legacy → sustituto

**`config/`** (mover a `legacy/config/` o borrar):
- Syms viejas: `us_ghidra.syms.toml`, `us_combined.syms*.toml(.bak)`, `us_module*.syms.toml`
  (+`.fixed`/`.keep`), `us_dec/us_retail/us_unified.syms.toml`, `keep_syms*.txt`,
  `module_extras.json`, `merge_loop.py`.
- Configs viejas: `game.toml`, `game_combined.toml`, `game_module7.toml`, `game_retail.toml`,
  `game_unified.toml` → sustituidas por la nueva.
- `RecompiledFuncs_*` viejas (gitignored): borrar del disco.
- **Conservar**: `n64recomp_changes/`, `rsp_hh_aspMain.toml`, `code_files.json`,
  `code_files.overlays.txt`, `game_code_files.toml`.

**`tools/`** (borrar → `legacy/tools/`):
- `setup_module.py`, y de `analysis/`: `gen_module_syms.py`, `gen_ghidra_syms.py`,
  `fix_function_bounds.py`, `fix_ghidra_sizes.py`, `add_mid_entry.py`, `add_missing_funcs.py`,
  `gen_module_extras.py`, `check_syms_overrides.py`, `overlay_chunks.py`, `auto_syms_loop.py`,
  `merge_loop.py`, `scan_lzkn64_strict.py`, `test_lzkn64.py`, `detect_lzkn64.py`, `textseg.py`,
  `parse_exec_trace.py`.
- **Conservar**: `analyze_code_files.py`, `ghidra_sections.py`, `ghidra_headless.sh`,
  `install_ghidra.sh`, `analysis/fix_per_file_syms.py`, `analysis/validate_syms.py`, `lzkn64/`,
  `rommy.py`, `build_linux.sh` y diagnósticos (RDRAM/emu/screenshots/`docs_index`).
- `recomp.py`: **reescribir** para el pipeline per-file (o retirar hasta tener el nuevo).

**Runtime fork (`N64ModernRuntime`, `librecomp/src/overlays.cpp`)**:
- Quitar `register_module_sources` / `load_module_by_source` / mapa `module_sources` y el wrapper
  `hh_wrap_FUN_80004838` + `hh_stream_id_to_src`; en su lugar, notificar `load_overlays`/
  `unload_overlays` desde los loaders.
- **Conservar**: `register_overlays`/`init_overlays`/`load_overlays`/`unload_overlays` (genéricos) y
  la **evicción de solapes** (`hh_unload_sections_overlapping`, útil).
- Instrumentación `HH_*`: conservar durante el reset (gated); **podar al final**.

**Port `src/`**:
- `register_overlays.cpp` + `module_sources.inc`: simplificar (sin `module_sources`); añadir los
  hooks de loader (`recomp_load_overlays`/`unload`).
- **Conservar**: `main.cpp`, `icon.cpp`, `rt64_render_context.cpp`, `support.cpp`, `input.cpp`,
  `trans_cache.cpp`, `firmware.c`, `rsp/hh_aspMain.cpp`.

**Docs/notas/bats**:
- `docs/`/`notes/` viejos → `legacy/`; las `notes/2026-09-20-*` vivas se conservan/reescriben.
- Bats de diagnóstico CaC → `legacy/port/`; conservar `build_windows*.bat`, `run_windows.bat`.

## S2. Fases (con *gates* de verificación)

**Fase A — Completar el recomp nuevo (NO borrar nada aún)**
1. **Residente con Ghidra per-file** (`ghidra_sections.py`): no reciclar `us_ghidra.syms.toml`;
   excluir rangos de overlay; re-recompilar. *Gate: `N64Recomp rc=0`; sin avisos nuevos de
   stub/datos-como-código.*
2. **Loaders estilo Goemon**: `recomp_load_overlays`/`unload` en ambos loaders; mapear **todos** los
   ids (no solo 57). *Gate: `[OVL]` de todos los ficheros que carga el boot.*
3. **A/B de la regresión**: comparar `hh_hang.log`/`hh_state.log` viejo↔nuevo en el mismo VI (anillo
   del hilo 5) y aislar el punto de divergencia. *Gate: el boot avanza como el viejo o más.*

**Fase B — Validar la base nueva**
4. Boot headless + en vivo y **CaC** (sin workarounds `HH_*`). *Gate: entra al combate.*

**Fase C — Purga legacy**
5. `git rm`/mover todo lo de S1; `CMakeLists.txt` y config apuntan solo a lo nuevo.
6. Retirar workarounds de síntoma (runtime: `HH_M55SPFIX`, etc.; config: `module_extras`,
   `add_mid_entry`). Podar instrumentación `HH_*` que ya no se use.
7. Reescribir/ordenar docs vivas; regenerar `docs/INDEX.md`.

**Fase D — Cierre**
8. Checks de completitud (S3).
9. Actualizar `runtime.lock` (commits nuevos), `AGENTS.md` (deps build vs recompilación), commit(s) y
   push (forks → main).

## S3. Checks de completitud (CI)
- nº de secciones == nº de code files (91); residente sin funciones en rango de overlay.
- Todo `jal`/`jalr` resuelve (sin `do_break`/stubs por frontera perdida).
- Sin “datos-como-código” (`syscall`/`mthi`/`break` en regiones de datos).
- Carga de overlays: cada `[LD384]`/streamed tiene su `[OVL]`/registro; sin `func_map` rancio.

## S4. Riesgos y mitigaciones
- **Purgar antes de validar** → puede reintroducir la regresión. Mitigación: purgar solo tras Fase B.
- **Evicción/registro** → verificar `func_map` sin rancios (A/B con `HH_NO_EVICT`).
- **Determinismo de Ghidra** → fijar versión (12.1.3 ya instalada) y documentarla.
- **Syms no versionadas** → regenerar exige Ghidra (dep. de dev documentada); alternativa: versionar
  `recomp/syms/`.

---

# ▓▓ MEJORAS ESTRUCTURALES PROPUESTAS ▓▓

> Hoy la raíz mezcla dos proyectos: el **port** (build/uso) y el **pipeline de recompilación** (dev).
> Separarlos evita que lo viejo contamine el build (causa de fondo del estado híbrido).

1. **Split `recomp/` + `port/`**:
   ```
   recomp/            # pipeline per-file (dev)
     game.toml  code_files.json  code_files.overlays.txt
     n64recomp_changes/  rsp/  ghidra/  syms/(opcional)
   port/HybridHeavenRecomp/{src,RecompiledFuncs,assets,rsp,lib,...}
   ```
   `config/` deja de ser un cajón (hoy 62 entradas mezclando 5 `game_*.toml`, syms, `RecompiledFuncs_*`,
   `module_extras.json`, `n64recomp_changes/`, `rsp_hh_aspMain.toml`, `config.ini`).
2. **Documentación viva vs histórica**: `docs/` = referencia viva, con **`GAME-INTERNALS.md`**
   (tablas Nisitenma/VRAM, loaders, intercambio de overlays, LZKN64) y **`docs/issues/NNN-*.md`**
   (bugs numerados con estado). `notes/` = evidencia de sesión.
3. **`docs/PLAN.md`** (plan maestro) separado de `RETOMAR.md` (handoff) y `TODO.md` (tareas).
4. **Deps en dos secciones explícitas**: *build del port* (usuario: toolchain, CMake, SDL2, RT64,
   Python + ROM) vs *regenerar la recompilación* (dev: Python, `lzkn64`, N64Recomp con
   `n64recomp_changes/`, **Ghidra** + JDK).
5. **Bats ordenados**: `port/` (build/run) y `port/diag/` (diagnóstico); one-off a `legacy/port/`.
6. **Fuente única del mapeo de overlays**: `code_files.json` + `code_files.overlays.txt` (pequeños,
   versionados) + doc que los explique; eliminar la verdad repartida en `module_sources.inc`/
   `module_extras.json`/notas.
7. **CI (`.github/workflows/ci.yml`)**: job de **completitud** (S3) + build del port.
8. **Higiene de raíz**: quitar `hhport_win.zip`, `.backup/`, `build/` de raíz, `config.ini` local; y
   un `README` en `RecompiledFuncs/` aclarando que es **generado** (no editar a mano).
9. **Pins de runtime**: `runtime.lock` pinea NMR; pinear/ documentar **RT64** igual; actualizar el pin
   NMR tras push.

## Decisiones (recomendadas, pendientes de tu OK)
- Adoptar **`recomp/` + `port/`** y `docs/GAME-INTERNALS.md` / `docs/issues/` / `docs/PLAN.md`.
- ¿Versionar la **syms agregada** en `recomp/syms/` (reproducir sin Ghidra) o dejarla en `work/`?
- Config final: `recomp/game.toml` (renombrar `game_code_files.toml`) o mantener el nombre.
