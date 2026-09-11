# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** Estado: `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` (arquitectura/ADRs) y `notes/` (histórico). No duplicar.

## Ahora — hacia las primeras píxeles (render)

1. [ ] **Wiring de render (A3)**: enganchar el sistema de eventos (`osSetEventMesg` con IDs estándar →
   ultramodern), el **routing de tareas RSP** y **`loadUCodeGBI`** para que el juego envíe tareas de
   **display** (hoy solo envía audio, type 2) y RT64 las procese. Objetivo: primera imagen.
2. [ ] **Validar en Windows (MSVC)** el estado actual (módulo idx 7 + audio no-op + fixes de apagado).

## Fundaciones pendientes

3. [ ] **Higiene de runtime**: parches mínimos y documentados; decidir si el lock single-CPU sigue
   siendo necesario (hoy exonerado en 9d); mantener `N64ModernRuntime` cercano a upstream.
4. [ ] **Interfaces de sub-objetivos** (texto/traducción, audio, guardado): contrato y punto de hook.

## Backlog

- [ ] **Audio**: identificar el microcode custom KCEO (no matchea `aspMain`).
- [ ] **Textos/traducción**: encoding + extracción + re-inserción (requisito de producto).
- [ ] **Guardado**: Controller Pak → ficheros en disco (+ Rumble).
- [ ] **Builds**: Windows + Linux + Steam Deck; resolución/widescreen; empaquetado sin ROM.
- [ ] **Tarea #3** (mapa overlay→RAM por BizHawk): necesaria para módulos/overlays futuros.
- [ ] Limpiar data-as-code (189 sospechosas) → habilita re-evaluar `use_lookup_for_all_function_calls=false`.

## Hecho (2026-09-11)

- [x] Boot **estable**: corre indefinidamente + **apagado limpio** (9d: `exit(0)` en `poll_input` → `~std::thread` joinable → terminate; fix `ultramodern::quit()` + `return 0`).
- [x] **0 funciones faltantes** (A2) vía evidencia runtime (`add_missing_funcs.py` + `HH_SOFT_LOOKUP`).
- [x] **Módulo idx 7 integrado y ejecutando** (B9): config combinada de 2 secciones; `get_function(0x80107830)` resuelve.
- [x] **Audio RSP no-op** (A1): tareas sin ucode se completan como dummy.
- [x] **Pipeline reproducible** `tools/recomp.py` + **validador** `validate_syms.py` (+ `gen_module_syms.py`, `fix_function_bounds.py` report-only).
- [x] **Reproducibilidad ROM→módulo** (`tools/setup_module.py`): extrae el módulo idx 7 de la ROM con `lzkn64` (CRC `0xA9213032`), regenera syms + ROM combinado, todo determinista y sin ejecutar el juego.
- [x] **Modelo de módulos `trans`** caracterizado + **ADR 0001** aceptado (base determinista, blob autoligado).
- [x] Extracción exacta del módulo (RDRAM + bswap32, CRC `0xA9213032`).
- [x] **Documentación consolidada** (modelo por capas) + protocolo de imágenes.
- [x] (histórico) Toolchain/repos/extracción Nisitenma; port + builds; syms Ghidra; fix DMA; game loop; scheduler VI.

## Documentos de detalle (no duplicar)
`PROYECTO.md` (estado) · `docs/architecture.md` · `docs/adr/` · `docs/workflows.md` ·
`notes/2026-09-11-*.md` (modelo módulos, B9, A1, A2, 9d, pipeline).
