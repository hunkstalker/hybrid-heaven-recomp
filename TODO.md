# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** Estado: `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` (arquitectura/ADRs) y `notes/` (histórico). No duplicar.

## Ahora — VALIDAR el fix del módulo 9 (cuelgue del NPC)

> Contexto y evidencia completos: `notes/2026-09-15-fix-modulo9-cuelgue-npc-y-handoff.md`.
> El cuelgue **no era regresión** (el build sin audio `e23e64c` también se cuelga con 3×
> `do_break` en `0x802169AC`). Causa: símbolo `M9_FUN_802169ac` con tamaño 0x4604 (arrastraba datos)
> → stub `do_break`; fix `fa02e24` (0x1C0 + override `0xADDR:0xSIZE` en el pipeline).

1. [•] **Validar en Windows**: `build_windows.bat` (Release) y repetir la entrega del objeto del NPC.
   Si se congela, **esperar ≥20 s** (watchdog por polls o por audio) y leer `hh_hang.log`, `hh_pi.log`
   y `hh_crash*` si hubo. Confirmar que la petición DMA del flujo sale como `region=rom` y completa.
2. [ ] **Si persiste el cuelgue**: analizar el volcado (registros `r4..r7/sp` por hilo) y `hh_pi.log`;
   el `.map` del build (`build_win/HybridHeavenRecomp-Release.map`) traduce `exe+0xNNNN`.
3. [ ] **Mando**: identificar el botón N64 que abre los menús de combate cuerpo a cuerpo y asignarlo a
   **X** (`config.ini`). Decidir también `LB` (¿L?) y el atajo futuro de cámara/1ª persona.
4. [ ] **Teardown SEGV** al cerrar en Windows (`Hybrid Heaven Recomp.exe +0x12A602`).

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

## Fundaciones pendientes

- [ ] **Higiene de runtime**: decidir si el lock single-CPU se elimina y si la entrega SI pasa a
  asíncrona (divergencias con upstream auditadas en `docs/architecture.md` §5).
- [ ] **Interfaces de sub-objetivos** (texto/traducción, audio, guardado): contrato y punto de hook.
- [ ] **Automatizar el inventario de módulos** (medir bases de forma desatendida vía loader).

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
- [ ] **Builds**: Windows + Linux + Steam Deck; empaquetado sin ROM.
- [ ] **Tarea #3** (mapa overlay→RAM por BizHawk): complementa la medición empírica de bases.
- [ ] Limpiar data-as-code (189 sospechosas) → habilita re-evaluar
  `use_lookup_for_all_function_calls=false`.

## Documentos de detalle (no duplicar)
`PROYECTO.md` · `docs/architecture.md` · `docs/adr/` · `docs/workflows.md` · `notes/2026-09-1*.md`.
