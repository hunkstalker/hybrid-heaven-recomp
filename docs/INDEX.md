# Índice de documentación

> **GENERADO por `tools/analysis/docs_index.py`; no editar a mano.**
> Regenerar: `python3 tools/analysis/docs_index.py` · Validar: `… --check`.
> Regla: una fuente de verdad por tema (`docs/documentation.md`).

## Arranque y estado (vivos)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [AGENTS.md — arranque de sesión](../AGENTS.md) | Port nativo de **Hybrid Heaven (N64)** a PC (N64Recomp + RT64 + N64ModernRuntime). Windows + Linux + Steam Deck. | 86 | 2026-09-13 |
| [PROYECTO — Hybrid Heaven: Recompiled (contexto maestro)](../PROYECTO.md) | **Fuente de verdad del contexto y el estado.** Mantenerlo corto (≈1-2 pantallas). | 102 | 2026-09-13 |
| [Hybrid Heaven Recomp (N64 → PC port)](../README.md) | Port a PC de **Hybrid Heaven** (N64, Konami Computer Entertainment Osaka, proyecto interno | 26 | 2026-09-10 |
| [TODO — Hybrid Heaven: Recompiled](../TODO.md) | **Única fuente de verdad de tareas.** Estado: `[ ]` pendiente · `[•]` en curso · `[x]` hecho. | 143 | 2026-09-13 |

## Técnico y guías (vivos)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [Hybrid Heaven: Recompiled — Plan Maestro (documentación detallada)](README.md) | Port a PC por **recompilación estática** (N64 → C → nativo) siguiendo el modelo de proyectos como | 233 | 2026-09-11 |
| [Arquitectura — Hybrid Heaven: Recompiled](architecture.md) | Documento vivo. Modelo técnico canónico del port. Las decisiones se registran en `docs/adr/`. | 155 | 2026-09-13 |
| [Cómo documentar este proyecto (guía de documentación)](documentation.md) | **Documento vivo y normativo.** Define *dónde* y *cómo* se documenta todo a partir de ahora. | 79 | 2026-09-13 |
| [Workflows operativos](workflows.md) | Procedimientos recurrentes. Documento vivo. Las decisiones van a `docs/adr/`; el detalle | 193 | 2026-09-13 |

## Decisiones (ADR, inmutables)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [ADR 0001 — Modelo de ejecución de módulos de código (`trans`)](adr/0001-modelo-de-modulos.md) | - **Estado**: Aceptado (2026-09-11). Decisión: **A** (con **B** como seguro). | 53 | 2026-09-11 |
| [ADR 0002 — Generar funciones de init de libultra del ROM (des-stubbing)](adr/0002-des-stub-libultra.md) | - **Estado**: Aceptado (2026-09-13). | 66 | 2026-09-13 |
| [ADR 0003 — Subsistema VI: libultra del ROM, runtime solo como hardware](adr/0003-vi-libultra-del-rom.md) | - **Estado**: Aceptado (2026-09-13). | 72 | 2026-09-13 |

## Evidencia (notas, histórico)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [Work order — Bloqueo por gate de tareas RSP (`0x8005CD4C`)](../notes/2026-09-13-workorder-gate-rsp.md) | Documento operativo para retomar ESTA tarea en una sesión nueva. Autocontenido. | 194 | 2026-09-13 |
| [2026-09-13 — ADR 0003 implementado: subsistema VI del ROM (opción A)](../notes/2026-09-13-vi-opcion-a-implementada.md) | Evidencia de la implementación de la decisión A (ver `../docs/adr/0003-vi-libultra-del-rom.md`). | 57 | 2026-09-13 |
| [2026-09-13 — Sentinel de colas libultra + contexto VI del juego](../notes/2026-09-13-vi-context-y-sentinel.md) | Evidencia (continúa `2026-09-13-directorio-nisitenma-y-gate-rsp.md` y su work order). | 85 | 2026-09-13 |
| [2026-09-13 — Segundo gate: des-stubbing de libultra y bloqueo del loader](../notes/2026-09-13-segundo-gate-libultra.md) | Nota de evidencia (continuación de `2026-09-13-arranque-memsize-y-accesorios.md`). No operativa. | 93 | 2026-09-13 |
| [2026-09-13 — Directorio Nisitenma, loader y gate de tareas RSP](../notes/2026-09-13-directorio-nisitenma-y-gate-rsp.md) | Nota de evidencia (continúa `2026-09-13-segundo-gate-libultra.md`). No operativa. | 131 | 2026-09-13 |
| [2026-09-13 — Arranque: memoria (Expansion Pak) y accesorios (Controller/Rumble Pak)](../notes/2026-09-13-arranque-memsize-y-accesorios.md) | Nota de evidencia. No es fuente operativa; el estado vive en `TODO.md`/`PROYECTO.md`. | 121 | 2026-09-13 |
| [2026-09-11 — Pipeline reproducible + validador de símbolos (Fase A #3)](../notes/2026-09-11-pipeline-recomp-validator.md) | Evidencia de sesión. No editar. | 46 | 2026-09-11 |
| [2026-09-11 — Módulo de código Nisitenma idx 7: extracción + syms (Fase A #4)](../notes/2026-09-11-modulo-idx7-extraccion.md) | Evidencia de sesión. No editar. | 45 | 2026-09-11 |
| [2026-09-11 — Modelo de módulos `trans` (Fase A #1)](../notes/2026-09-11-modelo-modulos-trans.md) | Evidencia de sesión. No editar. Resultado: **base determinista + contrato**; ADR 0001 aceptado. | 42 | 2026-09-11 |
| [2026-09-11 — Consolidación de documentación + corrección de calibración (visión)](../notes/2026-09-11-consolidacion-docs-y-vision.md) | Evidencia de sesión. No editar (ver `docs/documentation.md`). | 38 | 2026-09-11 |
| [2026-09-11 — B9: integración del módulo idx 7 (resuelto)](../notes/2026-09-11-b9-integracion-modulo.md) | Evidencia de sesión. No editar. | 43 | 2026-09-11 |
| [2026-09-11 — A3: wiring de render + generalización multi-módulo + jump-tables](../notes/2026-09-11-a3-multi-modulo-jumptables.md) | Evidencia de sesión. No editar. Continúa `2026-09-11-b9-integracion-modulo.md`. | 1196 | 2026-09-11 |
| [2026-09-11 — A2: completitud de símbolos planos (resuelto por evidencia runtime)](../notes/2026-09-11-a2-simbolos-planos.md) | Evidencia de sesión. No editar. | 31 | 2026-09-11 |
| [2026-09-11 — 9d: `terminate called without an active exception` — RESUELTO](../notes/2026-09-11-9d-terminate-hilos.md) | Evidencia de sesión. No editar. | 38 | 2026-09-11 |
| [SESIÓN 2026-09-10 — Port WINDOWS compila y hace boot; pantalla negra (sin render)](../notes/2026-09-10-windows-build.md) | Cierra la tanda de "preparar build Windows". Resultado: el port **Windows compila, hace boot y | 56 | 2026-09-10 |
| [SESIÓN 2026-09-10 — FIX deadlock VI + entrega de mensajes externos (verificado en run headless)](../notes/2026-09-10-session-vi-mesg-fix.md) | Complemento de `notes/2026-09-10-handoff-fase2.md`. Documenta los dos fixes de runtime aplicados | 212 | 2026-09-10 |
| [Cómo abordar el scheduler del motor Konami con Ghidra](../notes/2026-09-10-scheduler-ghidra.md) | Objetivo: encontrar quién envía la **primera tarea** a la cola principal (0x8005BF30) del thread | 95 | 2026-09-10 |
| [SESIÓN 2026-09-10 — DIAGNÓSTICO DEL SCHEDULER KONAMI (paso previo al fix)](../notes/2026-09-10-scheduler-diagnosis.md) | Complementa `notes/2026-09-10-handoff-fase2.md` y `notes/2026-09-10-scheduler-ghidra.md`. | 157 | 2026-09-10 |
| [SESIÓN 2026-09-10 — Investigación del RENDER: hallazgos y dónde se quedó el trabajo](../notes/2026-09-10-render-investigation.md) | Complementa `notes/2026-09-10-scheduler-diagnosis.md`, `notes/2026-09-10-windows-build.md` y | 142 | 2026-09-10 |
| [SESIÓN 2026-09-10 — Bloqueante de RENDER: análisis del mecanismo de tareas custom del motor Konami](../notes/2026-09-10-render-blocker.md) | Complementa `notes/2026-09-10-scheduler-diagnosis.md` y `notes/2026-09-10-windows-build.md`. | 87 | 2026-09-10 |
| [Fase 2 — Boot del núcleo plano (sesión 2026-09-10)](../notes/2026-09-10-recomp-fase2-boot.md) | Registro técnico de la sesión que hizo arrancar el recompilado del núcleo plano (Fase 2) | 228 | 2026-09-10 |
| [SESIÓN 2026-09-10 — Investigación emulador (harness Linux) + mapeo de os funcs](../notes/2026-09-10-osfuncs-investigation.md) | Documenta la tanda de trabajo posterior a `notes/2026-09-10-render-investigation.md` §7: | 129 | 2026-09-10 |
| [SESIÓN 2026-09-10 — CAUSA RAÍZ del bloqueo de render: os funcs de libultra sin mapear](../notes/2026-09-10-n64sym-osfuncs-rootcause.md) | **ESTE ES EL HALLAZGO CLAVE.** Documenta cómo se descubrió y cómo se resuelve el bloqueo de | 325 | 2026-09-10 |
| [SESIÓN 2026-09-10 — Crash determinista del descompresor LZSS (boot) + FIX de concurrencia del runtime](../notes/2026-09-10-lzss-decompressor-crash.md) | Complementa `notes/2026-09-10-ghidra-syms-solucion-fondo.md` §7.5. Documenta dos cosas: | 302 | 2026-09-10 |
| [HANDOFF Fase 2 — Boot del núcleo plano + scheduler (2026-09-10)](../notes/2026-09-10-handoff-fase2.md) | Este documento consolida TODO el contexto para retomar el trabajo de **Fase 2 (recompilación/boot)** | 240 | 2026-09-10 |
| [SOLUCIÓN DE FONDO — Syms/ELF con límites correctos (splat/flib/Ghidra) — EN PROGRESO](../notes/2026-09-10-ghidra-syms-solucion-fondo.md) | Documenta el intento de la "solución de fondo" (generar una syms/ELF completa con límites de | 173 | 2026-09-10 |
| [Overlay resource directory (trans loader) — ground truth + debugger plumbing](../notes/2026-09-08-overlay-directory.md) | Date: 2026-09-08. ROM: `work/roms/us_dec.z64` (z64, plana; código RAM = offset_rom + 0x80000000). | 433 | 2026-09-08 |
| [2026-09-06 (parte 2) — RSP-hle real + overlays detectados en RAM](../notes/2026-09-06_emulator-rdram.md) | Fixed la causa real del crash al adjuntar rsp-hle: | 48 | 2026-09-06 |
| [Nota de sesión 2026-09-05 — Mapa de assets (fase análisis)](../notes/2026-09-05_asset-map.md) | Completa la sección 4.6/4.8 de `../PROYECTO.md`. | 73 | 2026-09-05 |

## Archivo histórico (congelado)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [PROYECTO — Hybrid Heaven: Recompiled (Contexto maestro)](../notes/archive/2026-09-11-proyecto-legacy.md) | **ARCHIVO HISTÓRICO — NO es fuente de verdad operativa.** | 381 | 2026-09-11 |
| [SESIÓN — Hybrid Heaven (N64) → PC: mano de obra y contexto completo para retomar](../notes/archive/2026-09-11-sesion-legacy.md) | **ARCHIVO HISTÓRICO — NO es fuente de verdad operativa.** | 790 | 2026-09-11 |

## Datos generados (`notes/reference/`)

| Fichero | Tamaño |
|---|---|
| `notes/reference/n64sym_osfuncs_us_retail.txt` | 3,640 B |
