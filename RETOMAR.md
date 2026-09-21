# RETOMAR — migración a la vía de recompilación de la referencia (ELF + splat)

> Handoff para la sesión nueva. **Última sesión: 2026-09-21.**
>
> **DIRECCIÓN ACTUAL (2026-09-21):** se **abandona la vía Ghidra-per-file** (per-`file_NN` con syms y
> residente reciclado) y se migra a la **vía de la referencia**: **ELF desde splat/spimdisasm sobre
> la imagen expandida** + **residente limpio** + **gates de verificación**. Motivo: el build per-file
> arranca y llega al **título sin fondo 3D** (confirmado por el mantenedor y por captura): ejecuta un
> subconjunto de funciones y no emite `G_MTX`; las fronteras por-fichero pierden el contexto de imagen
> completa. Decisión: **calidad antes que prisa**.
>
> **Lee primero, en este orden:** `notes/2026-09-21-migracion-via-referencia-elf.md` (plan por fases
> M0–M5, alcance, riesgos) → `docs/adr/0011-via-recompilacion-elf-splat.md` (decisión) →
> `notes/2026-09-20-ab-bloqueo-boot-per-file.md` (evidencia del fallo). El **handoff largo** de la
> etapa per-file queda abajo como contexto histórico (superado por la migración).
>
> **Progreso de la migración:** **M0 HECHO** (toolchain: `tools/install_splat.sh` →
> `toolchain/splat-venv` con splat 0.50.0 + spimdisasm 1.42.4; MIPS por LLVM `llvm-mc`/`ld.lld`;
> wrapper `tools/splat_headless.sh`). **M1 HECHO** (`tools/unpack_rom.py` → imagen expandida +
> `segments.json` + `file_table.h`; 91 code files, 0x368070 bytes). **M2 HECHO** (`tools/build_elf.sh`:
> splat → `llvm-mc` → `ld.lld` → `elf/hybrid-heaven.us.elf`; **gate: el ELF reconstruye la imagen byte
> a byte**). **M3 HECHO** (N64Recomp ELF mode → C; rc=0, 0 datos-como-código). **M4 HECHO — regresión
> resuelta**: causa raíz = N64Recomp ELF mode no aplicaba `use_lookup_for_all_function_calls` (llamadas
> directas same-section saltaban los hooks de loader → file_008 no se registraba → título sin 3D). Fix
> en `main.cpp` del tool (snapshot en `recomp/n64recomp_changes/main.cpp`); + nombres libultra
> (`symbol_addrs.txt`) y 47 funciones del runtime registradas. Resultado: boot carga 8/55/24, `polls`
> avanza y **título con fondo 3D**. **VALIDADO EN WINDOWS**: gameplay, primer NPC, cajas, **primer CaC**
> y ~30 min hasta el 6º combate **sin cuelgues ni crashes** — **bloqueante original RESUELTO**.
> **Siguiente: M5 (saneamiento y estructura)** — retirar Ghidra-per-file a `legacy/`, unificar
> `config/`→`recomp/`, purgar workarounds `HH_*`, reescribir docs, actualizar pins y **push**. Aparte:
> **M4c** (SEGV al salir/teardown). Detalle: `notes/2026-09-21-migracion-via-referencia-elf.md`.

---

# ▓▓ HISTÓRICO — etapa per-file (superada por la migración ELF) ▓▓

> Documentación de la etapa anterior (reset per-file, 2026-09-20). Se conserva como contexto; el plan
> vigente es la migración a la vía de la referencia (arriba).

# RETOMAR — recompilación per-file completa (reset)

> Handoff para la sesión nueva. **Contexto**: se rehace la **recompilación per-file completa** porque
> la anterior era incompleta/heurística y causaba el freeze del CaC. El enfoque/documentación anterior
> queda en `legacy/`. **Estado**: la recompilación per-file ya **arranca, carga overlays y renderiza**;
> falta **la transición al intro/CaC** (`file_025`). Última sesión: **2026-09-20 (reset per-file)**.
>
> **Lee primero**: `notes/2026-09-20-pipeline-per-file-estado.md` (estado+evidencia, §15-18) y esta
> nota. El **método** generalizable está en `notes/2026-09-20-lecciones-recompilacion-per-file.md`.

---

## 0. OBJETIVO

Port nativo de PC (exe + ROM) de Hybrid Heaven (USA) por recompilación per-file (**91 code files**),
conservando el runtime (libultra/RT64/audio/Controller Pak/trans_cache), el tooling y la estructura.
**Sin `RecompFrontend`**. **Meta mínima de la siguiente sesión: entrar al primer CaC** (como el build
pre-reset), sin workarounds de síntoma.

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

### Hecho (sesión 2026-09-20)
- **Pipeline per-file completo**: `tools/analyze_code_files.py` (manifiesto de los **91 code files**),
  `tools/ghidra_sections.py` (Ghidra por fichero → syms `.file_NN`), `tools/regenerate.py`
  (ROM → … → N64Recomp → `work/recomp/RecompiledFuncs`). **N64Recomp rc=0**; el port **compila**.
- **Saneamiento**: el **C recompilado no se versiona** (obra derivada; **ADR 0009**): vive en
  `work/recomp/RecompiledFuncs` y `port/.../RecompiledFuncs` es un **symlink**. **Historia reescrita**
  (filter-branch) para borrar el C derivado del pasado (`.git` 15.4→1.8 MB; **force-push pendiente**).
- **Loaders estilo referencia** en `port/HybridHeavenRecomp/src/main/sections.cpp` (`file_table.h` +
  `announce_load` con evicción + hooks `add_loaded_function` de `FUN_8000469C` y `FUN_80004838`,
  registrados en `on_init`). Sustituyen a `register_overlays.cpp`/`module_sources.inc` (borrados).
- **Boot ARREGLADO**: carga `file_008 → file_055 → file_024 (heap) → resource loads`, bucle principal
  a ~57 `FUN_80001454`/s, render, **sin lookup misses**. Cadena de callbacks (22 `[SETCB]`) hasta
  front-end/trans.
- **Fixes de runtime de fondo** (mismos que el port de referencia, phase-04):
  - `osCreatePiManager`/PI coherente (game manager + runtime `osEPiStartDma`).
  - **yield con entrega de eventos + reschedule** (`ultramodern::wait_for_external_message_timed` +
    `check_running_queue`): **drena el contador de tareas `0x8005CD4C` a 0** (era el gate).
  - clamp del gestor de audio (`0x8001FD8C`, `sltu`→`slt`).
- **Fronteras**: `tools/analysis/fix_per_file_syms.py` fusiona el split `lui;lhu` de Ghidra (p.ej.
  callback `0x801078E0`); `regenerate.py` **siempre** re-ejecuta `validate_syms`.

### BLOQUEANTE ACTUAL (meta: primer CaC)
La **transición al intro/CaC no dispara**. El build viejo carga `file_025/026/100` en `s=846`/`vi=1692`;
el nuevo, no. Divergencias de estado medidas a ~28 s (A/B binario, mismo runtime/replay):
`scene` (`0x801BBC1C` u16) viejo 4 / nuevo 9; `objCB` (`0x8024AB14`) viejo `0x801CB71C` (callback real)
/ nuevo `0xF0F0FBFE` (basura); `0x801BBD56` viejo 6 / nuevo 0; primer word de estado distinto
`0x80044084` (viejo 1 / nuevo 4). Detalle: `notes/2026-09-20-pipeline-per-file-estado.md` §16-18.

### A/B binario (RECETA — clave para continuar)
```sh
# 1) build pre-reset aislado (config game_combined; compila entero)
git worktree add --detach /tmp/oldb 8fd6ddf
cp -a port/HybridHeavenRecomp/lib/{N64ModernRuntime,rt64} /tmp/oldb/port/HybridHeavenRecomp/lib/
mkdir -p /tmp/oldb/work/roms && ln -s "$PWD/work/roms/us_retail.z64" /tmp/oldb/work/roms/
cmake -S /tmp/oldb/port/HybridHeavenRecomp -B /tmp/oldb/port/HybridHeavenRecomp/build_dbg -DCMAKE_BUILD_TYPE=Release
cmake --build /tmp/oldb/port/HybridHeavenRecomp/build_dbg -j28
# 2) comparar con HH_HANG_FORCE=N (dumps word-swapped) o HH_CALLTRACE; el replay
#    work/debug/replays/cac_full_20260918_210956.txt sirve en ambos.
```
Dumps RDRAM del port: **word-swapped** → leer u32 LE (`notes/`). `HH_HANG_FORCE` + `q268`/`gframe`.

### Assets temporales (se pierden entre sesiones)
`/tmp/opencode/oldb` (worktree viejo) y `/tmp/opencode/gitbackup/pre-filter.bundle` (histórico previo).
Regenerables con la receta de arriba.

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
7. **`recomp/n64recomp_changes/`**: **conservar** (son parches al recompilador: `hh_mem_off`,
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
7. **Aplicar parches** de `recomp/n64recomp_changes/` al N64Recomp del toolchain (documentar).

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
  `recomp/n64recomp_changes/`), **Ghidra 11.x** (`analyzeHeadless`), JDK 17.

---

## 7. REPOS Y COMMIT

- **Main repo** (`origin` → `hunkstalker/hybrid-heaven-recomp`, `main`).
- **N64ModernRuntime** (fork, rama `hybrid-heaven`) y **N64Recomp** (fork, `hybrid-heaven`).
- Orden de push: **N64Recomp → N64ModernRuntime → main** (`port/runtime.lock` los pinea).
- **Historia reescrita (2026-09-20)**: se eliminó el C recompilado de **todos los commits**
  (`git filter-branch`, 258 commits; `.git` 15.4 → 1.8 MB). Los **hashes cambiaron** y `origin/main`
  queda divergente → **`git push --force-with-lease origin main`** (pendiente; hacerlo cuando valide).
  Respaldo del histórico previo: `git bundle` externo en `/tmp/opencode/gitbackup/pre-filter.bundle`.
- **Estado del árbol**: limpio y **commiteado**. Commits de esta sesión (más nuevos primero):
  `docs(per-file): A/B binario…`, `recomp(per-file): yield con entrega de eventos…`, `docs(per-file):
  checkpoint boot OK…`, `recomp(per-file): RESUELTO el boot…`, `recomp(per-file): PI path…`,
  `recomp(per-file): no versionar el C…`.
- **Fork runtime** (`lib/N64ModernRuntime`, `hybrid-heaven`): 3 commits locales **sin push**
  (`register_flat_code` skip relocatable, osGetMemSize 4MB, PI ownership). `runtime.lock` pinea el
  fork: **fuerza-push del fork antes de main** (orden N64Recomp → N64ModernRuntime → main).
- **N64Recomp (toolchain)**: los cambios viven en `toolchain/` (gitignored) + snapshot en
  `recomp/n64recomp_changes/symbol_lists.cpp` (ADR 0002). Rebuild: `--target N64RecompCLI`.

---

## 8. PRIMEROS PASOS DE LA SESIÓN NUEVA

> Hecho ya: pipeline per-file (N64Recomp rc=0), saneamiento (ADR 0009), loaders estilo referencia,
> **boot arreglado** (fronteras + validate + PI + yield + clamp). **Bloqueante actual: la transición
> al intro/CaC no dispara** (§2). Detalle/evidencia: `notes/2026-09-20-pipeline-per-file-estado.md`
> §15-18.

1. **Localizar la primera divergencia de estado** con el **A/B binario** (§2 receta):
   `HH_HANG_FORCE=10/28` + dumps word-swapped en viejo↔nuevo, o `HH_CALLTRACE` filtrado. Primeras
   pistas ya medidas: `scene` (`0x801BBC1C`) 4 vs 9, `objCB` (`0x8024AB14`) `0x801CB71C` vs `0xF0F0FBFE`,
   `0x801BBD56` 6 vs 0, `0x80044084` 1 vs 4. **Encontrar quién escribe** `0x8024AB14`/`0x801BBC1C`
   primero distinto (watchpoint `HH_WATCH_ADDR`, o trazar por `HH_CALLTRACE`).
2. **Hipótesis a comprobar** (fronteras/libultra en orden): (a) otra frontera de `file_024`/`file_012`
   mal partida (como `0x801078E0`); (b) un libultra que el nuevo deja al ROM pero el viejo tenía
   runtime-owned (o viceversa) — comparar `recomp_overlays.inl` viejo vs nuevo para `*_recomp`;
   (c) el **SEGV tardío** en `FUN_80023bf4` (~180 s) por corrupción acumulada.
3. **Si dispara la transición**: validar la intro, menús, GAME START y **primer CaC** (sin `HH_*`).
4. **Fase C (purga)**: mover a `legacy/` lo obsoleto (`setup_module.py`, syms viejas, workarounds),
   split `recomp/`+`port/`, quitar del fork runtime el registro viejo (`register_module_sources`/
   `load_module_by_source`) e instrumentación muerta. **force-push** (§7).

## 7b. Uso obligatorio de las tools
- Pipeline completo: **`python3 tools/regenerate.py`** (ROM → … → `work/recomp/RecompiledFuncs`;
  `--skip-ghidra` reutiliza syms). Compilar: `tools/build_linux.sh` / `port\build_windows.bat`.
- Nunca editar el C generado; todo fix va a `config/*.toml` + syms y se regenera (ADR 0009).
- Dependencias de **recompilación** (dev): JDK 21 + Ghidra (`tools/install_ghidra.sh`), N64Recomp.
  **Build del port**: solo C++/CMake/SDL2/RT64 + la ROM.

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
- Config única `recomp/game.toml` (hoy `recomp/hybrid-heaven.us.toml`).
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
