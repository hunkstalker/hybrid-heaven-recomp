# Índice de documentación

> **GENERADO por `tools/analysis/docs_index.py`; no editar a mano.**
> Regenerar: `python3 tools/analysis/docs_index.py` · Validar: `… --check`.
> Regla: una fuente de verdad por tema (`docs/documentation.md`).

## Arranque y estado (vivos)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [AGENTS.md — arranque de sesión](../AGENTS.md) | Port nativo de **Hybrid Heaven (N64)** a PC (N64Recomp + RT64 + N64ModernRuntime). Windows + Linux + Steam Deck. | 87 | 2026-09-16 |
| [PROYECTO — Hybrid Heaven: Recompiled (contexto maestro)](../PROYECTO.md) | **Fuente de verdad del contexto y el estado.** Mantenerlo corto (≈1-2 pantallas). | 127 | 2026-09-16 |
| [Hybrid Heaven Recomp (N64 → PC port)](../README.md) | **⚠️ Proyecto EN DESARROLLO (fase temprana).** No está terminado: puede haber fallos, | 69 | 2026-09-16 |
| [TODO — Hybrid Heaven: Recompiled](../TODO.md) | **Única fuente de verdad de tareas.** Estado: `[ ]` pendiente · `[•]` en curso · `[x]` hecho. | 152 | 2026-09-16 |

## Técnico y guías (vivos)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [Hybrid Heaven: Recompiled — Plan Maestro (documentación detallada)](README.md) | Port a PC por **recompilación estática** (N64 → C → nativo) siguiendo el modelo de proyectos como | 233 | 2026-09-11 |
| [Arquitectura — Hybrid Heaven: Recompiled](architecture.md) | Documento vivo. Modelo técnico canónico del port. Las decisiones se registran en `docs/adr/`. | 234 | 2026-09-15 |
| [Cómo documentar este proyecto (guía de documentación)](documentation.md) | **Documento vivo y normativo.** Define *dónde* y *cómo* se documenta todo a partir de ahora. | 79 | 2026-09-13 |
| [Workflows operativos](workflows.md) | Procedimientos recurrentes. Documento vivo. Las decisiones van a `docs/adr/`; el detalle | 239 | 2026-09-16 |

## Decisiones (ADR, inmutables)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [ADR 0001 — Modelo de ejecución de módulos de código (`trans`)](adr/0001-modelo-de-modulos.md) | - **Estado**: Aceptado (2026-09-11). Decisión: **A** (con **B** como seguro). | 53 | 2026-09-11 |
| [ADR 0002 — Generar funciones de init de libultra del ROM (des-stubbing)](adr/0002-des-stub-libultra.md) | - **Estado**: Aceptado (2026-09-13). | 66 | 2026-09-13 |
| [ADR 0003 — Subsistema VI: libultra del ROM, runtime solo como hardware](adr/0003-vi-libultra-del-rom.md) | - **Estado**: Aceptado (2026-09-13). | 72 | 2026-09-13 |
| [ADR 0004 — Registro dinámico de módulos de código en bases reutilizadas](adr/0004-registro-dinamico-modulos.md) | - **Estado**: Aceptado (2026-09-14). | 54 | 2026-09-14 |
| [ADR 0005 — Runtime en forks propios y build reproducible](adr/0005-build-reproducible-y-artefactos.md) | - **Estado**: Aceptado (2026-09-16). | 91 | 2026-09-16 |

## Evidencia (notas, histórico)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [2026-09-16 — Runtime en forks propios y build reproducible (sustituye el snapshot)](../notes/2026-09-16-runtime-en-forks-y-build-reproducible.md) | Consolida el trabajo del día: receta de build (script + Docker + CI), hallazgo del commit local y | 78 | 2026-09-16 |
| [2026-09-16 — Limpieza del repo: purga de `.vs/` e inventario de candidatos](../notes/2026-09-16-limpieza-repo-inventario.md) | Contexto: el usuario crea el repo en GitHub (`hunkstalker/hybrid-heaven-recomp`) y pide limpiar | 67 | 2026-09-16 |
| [2026-09-16 — Guardado en cápsula (Controller Pak) sin UI de slots + crash de CaC `0x8021D8D0`](../notes/2026-09-16-guardado-capsula-pak-y-crash-cac-8021d8d0.md) | ``` | 178 | 2026-09-16 |
| [2026-09-16 — Fix del estado de caída: fallthrough M55 `0x8037A6F4` → `0x8037A884` (fuga `0x38`/frame)](../notes/2026-09-16-fix-caida-fallthrough-m55-8037a6f4.md) | Continúa `2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md` (ronda 14). Ahí quedó: láser | 94 | 2026-09-16 |
| [2026-09-16 — Crash en menú: mid-entry `M55_FUN_80378c48` (módulo 55)](../notes/2026-09-16-crash-menu-midentry-m55-80378c48.md) | En una partida avanzada, al entrar en un **menú**: | 54 | 2026-09-16 |
| [2026-09-16 — Crash al cruzar una puerta (cinemática): mid-entry `M9_FUN_80203830` (módulo 9)](../notes/2026-09-16-crash-cinematica-midentry-m9-80203830.md) | Al cruzar una **puerta que lanza una cinemática** (transición juego → menú): | 76 | 2026-09-16 |
| [2026-09-15 — Cuelgue del NPC: bisect, causa raíz (módulo 9) y punto de retomada](../notes/2026-09-15-fix-modulo9-cuelgue-npc-y-handoff.md) | Nota de sesión. **Estado: fix aplicado y compilado en Linux; PENDIENTE validar en Windows** con la | 105 | 2026-09-15 |
| [2026-09-15 — Cuelgue del NPC (4ª ronda): struct del hilo reutilizado → crash al aparcar](../notes/2026-09-15-cuelgue-npc-thread-struct-pisado.md) | Nota de sesión. Tras el fix FIFO-al-ceder (ronda 3) el cuelgue desaparece, pero aparece un **SEGV** | 71 | 2026-09-15 |
| [2026-09-15 — Cuelgue del NPC (6ª ronda): desbordamiento de pila + sombra host del scheduler](../notes/2026-09-15-cuelgue-npc-stack-overflow-y-sombra-hilos.md) | Nota de sesión. Cierra la cadena de diagnósticos del día (M9 → requeue PI → scheduler FIFO → | 45 | 2026-09-15 |
| [2026-09-15 — Cuelgue del NPC (3ª ronda): inanición del scheduler (LIFO entre igual prioridad)](../notes/2026-09-15-cuelgue-npc-scheduler-fifo.md) | Nota de sesión. **Estado: causa raíz identificada con traza directa; fix aplicado (FIFO entre | 77 | 2026-09-15 |
| [2026-09-15 — Cuelgue del NPC (5ª ronda): mid-entry faltante 0x80380010 (módulo 55)](../notes/2026-09-15-cuelgue-npc-mid-entry-80380010.md) | Nota de sesión. Tras el blindaje del struct de hilo (ronda 4) el juego llega más lejos y aparece | 44 | 2026-09-15 |
| [Cuelgue del NPC (ronda 7): fuga de pila 0x48/frame por fallthrough sin encadenar en el modulo 55](../notes/2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md) | Fecha: 2026-09-15 (noche). Antecedentes: `…-stack-overflow-y-sombra-hilos.md`. | 341 | 2026-09-15 |
| [2026-09-15 — Cuelgue del NPC (2ª ronda): completaciones PI perdidas en la cola del loader](../notes/2026-09-15-cuelgue-npc-completaciones-pi-perdidas.md) | Nota de sesión. **Estado: hipótesis con alta evidencia y fix candidato aplicado (sin validar en | 76 | 2026-09-15 |
| [2026-09-14 — Run largo de cutscenes, símbolos nuevos y callbacks del menú](../notes/2026-09-14-run-largo-cutscenes-y-simbolos.md) | Continuación de `2026-09-14-fix-fallthrough-secciones-y-cutscene.md` (tras el commit `9ff2c05`). | 36 | 2026-09-14 |
| [2026-09-14 — Registro dinámico de módulos (bases reutilizadas): transición funcional](../notes/2026-09-14-registro-dinamico-modulos.md) | Continúa `notes/2026-09-14-fix-strict-aliasing-transicion.md`. **Por qué era la tarea**: con la | 83 | 2026-09-14 |
| [2026-09-14 — Gameplay: input inyectado, menús y Controller Pak](../notes/2026-09-14-input-menus-controller-pak.md) | **Objetivo**: entrar en gameplay desde el título (el menú ya renderizaba; el bloqueo era input). | 79 | 2026-09-14 |
| [2026-09-14 — Geometría y píxeles alcanzados (logo, título y attract en RT64)](../notes/2026-09-14-geometria-pixeles.md) | Cierra el objetivo del work order original ("llegar a geometría/píxeles"). Continúa | 40 | 2026-09-14 |
| [2026-09-14 — `-fno-strict-aliasing`: resuelta la transición (`fe00`) y nueva frontera de símbolos](../notes/2026-09-14-fix-strict-aliasing-transicion.md) | Continúa `notes/2026-09-14-cadena-d550-y-registro-0x74.md`. **Hito**: el juego cruza la | 97 | 2026-09-14 |
| [2026-09-14 — Fix de fallthroughs entre módulos con base compartida y avance de cutscenes](../notes/2026-09-14-fix-fallthrough-secciones-y-cutscene.md) | **Objetivo**: resolver el crash tras GAME START (`M25_FUN_801e2cac`) y seguir hacia gameplay. | 42 | 2026-09-14 |
| [2026-09-14 — Fix del callback del menú (accesos a direcciones no mapeadas)](../notes/2026-09-14-fix-callback-menu-punteros-no-mapeados.md) | **Objetivo**: eliminar el SEGV de `M24_FUN_801cb71c` al quedarse en el menú / volver al menú. | 48 | 2026-09-14 |
| [2026-09-14 — Combate: overlays de IA + grabación/replay de input](../notes/2026-09-14-combate-overlays-y-replay.md) | - Faltaban funciones de la IA enemiga, llamadas cada frame: | 37 | 2026-09-14 |
| [2026-09-14 — Cadena `d550` → `bd6d` y registro del recurso `0x74` (bloqueo de la transición)](../notes/2026-09-14-cadena-d550-y-registro-0x74.md) | Continúa `notes/2026-09-13-fix-corrupcion-audio-y-evento-modulo.md` y el work order | 87 | 2026-09-14 |
| [Work order — Bloqueo por gate de tareas RSP (`0x8005CD4C`)](../notes/2026-09-13-workorder-gate-rsp.md) | Documento operativo para retomar ESTA tarea en una sesión nueva. Autocontenido. | 194 | 2026-09-13 |
| [Work order — Evento de módulo `0x7D` y cadena de callbacks del nodo `0x801D0474`](../notes/2026-09-13-workorder-evento-modulo-0x7D.md) | Documento operativo autocontenido para retomar ESTA tarea en una sesión nueva. | 111 | 2026-09-13 |
| [Work order — Crash del driver de audio por `ctx+4` corrupto (estado del AI)](../notes/2026-09-13-workorder-audio-ai-descriptor.md) | Documento operativo autocontenido para retomar ESTA tarea en una sesión nueva. | 134 | 2026-09-13 |
| [2026-09-13 — ADR 0003 implementado: subsistema VI del ROM (opción A)](../notes/2026-09-13-vi-opcion-a-implementada.md) | Evidencia de la implementación de la decisión A (ver `../docs/adr/0003-vi-libultra-del-rom.md`). | 57 | 2026-09-13 |
| [2026-09-13 — Sentinel de colas libultra + contexto VI del juego](../notes/2026-09-13-vi-context-y-sentinel.md) | Evidencia (continúa `2026-09-13-directorio-nisitenma-y-gate-rsp.md` y su work order). | 85 | 2026-09-13 |
| [2026-09-13 — El gate de la transición es el ucode de audio (RSP)](../notes/2026-09-13-ucode-audio-gate-transicion.md) | Continúa `2026-09-13-audio-ai-y-estructura-pre-transicion.md`. **Causa raíz encontrada** de por | 221 | 2026-09-13 |
| [2026-09-13 — Segundo gate: des-stubbing de libultra y bloqueo del loader](../notes/2026-09-13-segundo-gate-libultra.md) | Nota de evidencia (continuación de `2026-09-13-arranque-memsize-y-accesorios.md`). No operativa. | 93 | 2026-09-13 |
| [2026-09-13 — Resuelta la corrupción de contextos de audio; nueva frontera: evento de módulo 0x7D](../notes/2026-09-13-fix-corrupcion-audio-y-evento-modulo.md) | Continúa `2026-09-13-ucode-audio-gate-transicion.md` y el work order | 123 | 2026-09-13 |
| [2026-09-13 — Directorio Nisitenma, loader y gate de tareas RSP](../notes/2026-09-13-directorio-nisitenma-y-gate-rsp.md) | Nota de evidencia (continúa `2026-09-13-segundo-gate-libultra.md`). No operativa. | 131 | 2026-09-13 |
| [2026-09-13 — Deadlock del gate: race de completaciones SP entre hilos de tareas](../notes/2026-09-13-deadlock-sp-race.md) | Evidencia de la tarea "emparejar el ritmo del gate `0x8005CD4C`". Continúa | 80 | 2026-09-13 |
| [2026-09-13 — Cadena de boot y progreso `fe00` (port vs emulador)](../notes/2026-09-13-cadena-boot-y-progreso-fe00.md) | Evidencia de la tarea "rastrear el callback de progreso del módulo 23". Continúa | 54 | 2026-09-13 |
| [2026-09-13 — Audio/AI, tasas del emulador y estructura de contexto pre-transición](../notes/2026-09-13-audio-ai-y-estructura-pre-transicion.md) | Continúa `2026-09-13-deadlock-sp-race.md` (§5). Objetivo: por qué el port no alcanza la | 72 | 2026-09-13 |
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
