# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** Estado: `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` (arquitectura/ADRs) y `notes/` (histórico). No duplicar.

## Ahora — Cajas de ítem, teardown y limpieza

> **Cuelgue por daño del robot: ARREGLADO y validado en Windows (2026-09-16)**, en dos capas:
> `s0` (r16) machacado por la cadena del frame (fix runtime `HH_S0FIX`) y, ya caído, personaje que no
> se levantaba por un fallthrough ausente al final de `M55_FUN_8037a6f4` (fuga `0x38`/frame +
> lógica de caída saltada; nueva regla de ramas condicionales en `fix_fallthroughs.py`).
> Detalle: `notes/2026-09-16-fix-caida-fallthrough-m55-8037a6f4.md`.
>
> **Entrega del objeto del NPC: ARREGLADA y validada (2026-09-15)**: fallthrough sin encadenar en
> módulo 55 (fuga `0x48`/frame + animación saltada) y mid-entries sin registrar (`0x80379954`,
> `0x803798E8`). Módulo 55 = overlay de la secuencia de objeto (`docs/architecture.md` §2.2).
> Detalle: `notes/2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md`.

1. [•] **Probar abrir cajas/obtener ítems** (usuario, en curso): si crashea con
   `Failed to find function at 0x...`, registrar SOLO esa dirección editando a mano
   `us_moduleNN.syms.toml` + `us_combined.syms.toml` y `tools/recomp.py ... --force` (ver nota,
   "Ronda 9"; **no** usar `setup_module.py`: cascado de `auto_mid` → datos como código).
2. [ ] **Teardown SEGV** al cerrar en Windows (`Hybrid Heaven Recomp.exe +0x12A602`):
   mapear con `build_win/HybridHeavenRecomp-Release.map`, reproducir en Linux (cierre ordenado) y
   arreglar (orden de deinit/destructores estáticos).
3. [ ] **Limpieza de instrumentación** (tras estabilizar): silenciar `hh_sched.log`/`hh_mq.log`/`hh_ovl.log`
   tras un env, y decidir si se quedan `requeue_pi=true`, `[MQDROP]`, la sombra `hh_sh_*` y el watchpoint.
4. [ ] **Mando**: identificar el botón N64 que abre los menús de combate cuerpo a cuerpo y asignarlo a
   **X** (`config.ini`). Decidir también `LB` (¿L?) y el atajo futuro de cámara/1ª persona.

## Hecho (resumen; detalle en `notes/`)

- [x] **Gameplay alcanzado** (2026-09-14): menús → GAME START → escenas 3D in-game; overlays
  idx8/9/10/12/55; IA de combate (`0x80005C70`, `0x80005CB0`, `0x80022978`, `0x800229FC`, `0x80379970`
  + 17 mid-entries). Input sintético `HH_PRESS*`/`HH_STICK`/`HH_CSTICK`; record/replay por VI
  (RMSE=0 misma máquina). Ver `notes/2026-09-14-*.md`.
- [x] **Módulos por sección** (registro dinámico en la base real del loader; idx 7/23/24/25/54/99 +
  8/9/10/12/55), pipeline consciente de sección (`setup_module.py`, `validate_syms`,
  `fix_fallthroughs`, `gen_module_syms --filter-data`, `keep_syms_flat`).
- [x] **Memoria segura**: `MEM_*`/`TO_PTR` con mapeo no-mapeado → scratch (fix del callback de menú);
  `-fno-strict-aliasing` (fix de la transición).
- [x] **Controller Pak (PFS mínimo en RAM)** con persistencia `saves/*.bin.pak`; 13 entradas en
  `reimplemented_funcs`.
- [x] **Audio**: ucode `aspMain` del ROM recompilado; dispositivo WASAPI abierto; tasa 43200 Hz (720
  frames/VI) con feedback de cola; Release por defecto (Debug caía a 30 fps y rompía el pacing).
- [x] **Mando**: perfiles por contexto (`config.ini` [game]/[menu]) con detección automática por el
  flag de UI `0x802690D0` (pausa/mapa verificados); B físico=atrás en menús, Select=mapa, Y=C-Down
  (1ª persona, verificado), X libre.
- [x] **Diagnóstico**: volcados automáticos de crash (log + RDRAM + DMEM + registros del juego, SEH
  del entrypoint), watchdog de cuelgue (polls y audio), `hh_pi.log` con tiempos, `/MAP` de MSVC,
  `hh_missing.log`, bats de regresión `run_test_*`.
- [x] **Bisect del cuelgue del NPC**: conclusión documentada (no regresión) + `bisect_build.bat`.
- [x] **Build reproducible + CI/release** (2026-09-16): `tools/build_linux.sh` (rt64 clonado en commit
  fijo + **snapshot del runtime** + CMake), `Dockerfile` multi-stage (Debian/glibc, stages
  deps/build/runtime), `.github/workflows/{ci,release}.yml` (zip Windows / tar.gz Linux / imagen
  ghcr.io en tag) y devcontainer. Decisión: `docs/adr/0005-build-reproducible-y-artefactos.md`.
- [x] **Runtime y N64Recomp en forks propios** (2026-09-16, validado con los push): el runtime
  modificado vive en `hunkstalker/N64ModernRuntime` (rama `hybrid-heaven`, 23 commits) y el cambio
  de `recomp.h`/`symbol_lists.cpp` en `hunkstalker/N64Recomp` (que **se compila** en el port).
  `main` de ambos forks = upstream (crédito/lineage). Los scripts clonan por URL+SHA de
  `port/runtime.lock`; sin patch ni snapshot. Ver `docs/adr/0005-*.md`.
- [ ] **(Diferido) Ramas del toolchain**: para reproducir la **regeneración** (syms→C) hará falta
  una rama `hybrid-heaven-tool` en el fork de N64Recomp (la herramienta tiene 13 archivos
  modificados). El build no la necesita.
- [x] **Daño del robot, 2 capas** (2026-09-16, validado en Windows): `s0` machacado → dispatch
  frame/no-op roto (`HH_S0FIX` en runtime, incondicional, con auto-test `HH_TEST_S0BUG`); y caída que
  no se levantaba → fallthrough ausente en `M55_FUN_8037a6f4` (continuación `0x8037A884..` y epílogo
  compartido `0x8037A94C/A950` saltados; fuga `0x38`/frame). Ver `notes/2026-09-16-*.md`.

## Fundaciones pendientes

- [ ] **Higiene de runtime**: decidir si el lock single-CPU se elimina y si la entrega SI pasa a
  asíncrona (divergencias con upstream auditadas en `docs/architecture.md` §5).
- [ ] **Interfaces de sub-objetivos** (texto/traducción, audio, guardado): contrato y punto de hook.
- [ ] **Automatizar el inventario de módulos** (medir bases de forma desatendida vía loader).

## Licencia y distribución

- [x] **Créditos de terceros**: `CREDITS.md` (NMR GPL-3.0; N64Recomp/RT64/SDL2 MIT/Zlib; submódulos
  xxHash/miniz/o1heap; herramientas de desarrollo). Se incluye como `CREDITOS.md` en el `.zip`/`.tar.gz`
  de CI/release y en la imagen Docker.
- [ ] **`LICENSE` del proyecto**: los binarios enlazan N64ModernRuntime (**GPL-3.0**) → decidir una
  licencia GPL-3.0-compatible y añadir `LICENSE` a los artefactos.
- [x] **Datos del juego fuera del repo** (2026-09-16): purgados de **todo el historial** los
  assets/capturas (`Referencias screenshots/`, `muestra-menu*.png`, `tests/*.png`), los `assets/`
  del juego y los datos extraídos (manifiestos, mapa de assets, dump de símbolos). El **código del
  port** (incluido `RecompiledFuncs/` y `rsp/hh_aspMain.cpp`) **sí se versiona** → el `.exe` compila
  **sin ROM** y busca la ROM del usuario en runtime (`rom/baserom.us.z64`). Ver ADR 0005.
- [ ] **Sanear menciones a la ROM en docs/notas**: hay notas/`PROYECTO.md` que citan textos/anclas
  del juego (p. ej. `WASHINGTON D.C. @0x...`). Son frases cortas/hechos, pero si quieres “cero
  menciones”, hay que reescribirlas.

## Higiene del repo (candidatos de limpieza)

> Inventario y criterios: `notes/2026-09-16-limpieza-repo-inventario.md`. Ya hecho: purga de `.vs/`
> de toda la historia, borrado de `port/petardeo)` + `tools/analysis/xshot`, y **eliminación de los
> datos del juego del repo/historial** (capturas, assets, manifiestos; `port/bisect_*`).

- [ ] **Archivar** (`tools/archive/`) los scripts de una sola vez de `tools/analysis/` (62 `.java`
  de Ghidra + helpers de diagnóstico), conservando los vivos de `docs/workflows.md` §6.
- [ ] Revisar **variantes de `config/`** obsoletas (`game*.toml`, `us_*.syms.toml` no activas) y
  archivar las que no se usen (activa: `game_combined.toml`).
- [ ] Decidir el **`work/` rastreado** (3 scripts de captura).
- [ ] **NO borrar** `config/*.syms.toml.keep` (los usa `gen_module_syms`/`setup_module`) ni
  `keep_syms*.txt`/`module_extras.json` ni `config/n64recomp_changes/*`.
- [ ] (Opcional) Selector de ROM tipo menú (Zelda64Recomp/Goemon64Recomp); hoy se carga de `rom/`.
- [ ] **Regeneración por terceros**: publicar la rama `hybrid-heaven-tool` del fork de N64Recomp
  (la herramienta tiene 13 archivos modificados).

## Backlog

- [ ] **Audio (FUTURO)**: desacoplar de los fps. Hoy entrega 720 frames por frame de juego (60 fps →
  43.2k/s OK; 30 fps → 21.6k → huecos). El handshake (hilo audio 3 espera EB8; hilo SP 18 publica)
  compite con el frame en el scheduler; `HH_SP_SHARED` no mejora. Mitigación: Release. Ideas:
  completar la task sin pasar por el bucle de juego, o amortiguar/resamplear.
- [ ] **Símbolos**: revisar el resto de funciones con fronteras gruesas (`0xADDR:0xSIZE` en
  `module_extras.json`) y el auto-mid del módulo 12 que mete datos como código; regenerar syms
  completo con cuidado (ver nota del 2026-09-15 §4).
- [ ] **Textos/traducción**: encoding + extracción + re-inserción (requisito de producto).
- [ ] **Guardado**: validar Controller Pak contra el emulador; ficheros en disco (+ Rumble).
- [ ] **Builds/empaquetado**: **validar** los workflows en GitHub tras el primer push (build Linux
  por Docker, build Windows en CI, release con tag `v*` y subida a ghcr.io), y empaquetado para
  **Steam Deck** (AppImage/paquete nativo). Hecho ya: receta Linux + Docker + CI + Releases
  (`docs/adr/0005-build-reproducible-y-artefactos.md`).
- [ ] **Tarea #3** (mapa overlay→RAM por BizHawk): complementa la medición empírica de bases.
- [ ] Limpiar data-as-code (189 sospechosas) → habilita re-evaluar
  `use_lookup_for_all_function_calls=false`.

## Documentos de detalle (no duplicar)
`PROYECTO.md` · `docs/architecture.md` · `docs/adr/` · `docs/workflows.md` · `notes/2026-09-1*.md`.
