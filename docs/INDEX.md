# Índice de documentación

> **GENERADO por `tools/analysis/docs_index.py`; no editar a mano.**
> Regenerar: `python3 tools/analysis/docs_index.py` · Validar: `… --check`.
> Regla: una fuente de verdad por tema (`docs/documentation.md`).

## Arranque y estado (vivos)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [AGENTS.md — arranque de sesión](../AGENTS.md) | Port nativo de **Hybrid Heaven (N64)** a PC (N64Recomp + RT64 + N64ModernRuntime). Windows + Linux + | 110 | 2026-09-21 |
| [PROYECTO — Hybrid Heaven: Recompiled (contexto maestro)](../PROYECTO.md) | **Fuente de verdad del contexto y el estado.** Mantenerlo corto (≈1-2 pantallas). | 119 | 2026-09-25 |
| [Hybrid Heaven Recomp (N64 → PC)](../README.md) | **⚠️ Proyecto EN DESARROLLO (fase temprana).** Puede haber fallos, incompatibilidades y | 80 | 2026-09-24 |
| [TODO — Hybrid Heaven: Recompiled](../TODO.md) | **Única fuente de verdad de tareas.** `[ ]` pendiente · `[•]` en curso · `[x]` hecho. | 128 | 2026-09-25 |

## Técnico y guías (vivos)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [Hybrid Heaven Recomp — Linux](BUILDING_linux.md) | Binario Linux (x86_64, glibc) del port. **La ROM no se incluye**: al arrancar, el binario busca tu | 77 | 2026-09-21 |
| [Hybrid Heaven Recomp — Build para Windows](BUILDING_windows.md) | Guía para compilar el port en Windows (MSVC / Visual Studio). La recompilación de funciones se hace | 364 | 2026-09-22 |
| [Visión y roadmap — Hybrid Heaven: Recompiled](README.md) | **Documento de visión (no vinculante).** Describe *hacia dónde* va el proyecto a largo plazo. | 77 | 2026-09-21 |
| [Arquitectura — Hybrid Heaven: Recompiled](architecture.md) | Documento vivo. Modelo técnico canónico del port. Las decisiones se registran en `docs/adr/`. | 257 | 2026-09-21 |
| [Cómo documentar este proyecto (guía de documentación)](documentation.md) | **Documento vivo y normativo.** Define *dónde* y *cómo* se documenta todo a partir de ahora. | 85 | 2026-09-18 |
| [Notas de release](releases/README.md) | Un fichero por tag: `docs/releases/<tag>.md` (p. ej. `v0.3.0.md` para el tag `v0.3.0`). | 14 | 2026-09-22 |
| [v0.2.0 - Graphical improvements](releases/v0.2.0.md) | - **Ajustes gráficos `[video]`** en `config.ini`: ventana (borderless/windowed), resolución | 7 | 2026-09-22 |
| [v0.3.0 - Widescreen HUD anchoring & minimap fix](releases/v0.3.0.md) | Primera release con el HUD/minimapa **anclados** en widescreen. | 11 | 2026-09-22 |
| [v0.4.0 - High frame rate (frame interpolation)](releases/v0.4.0.md) | El port presenta ahora hasta el **refresco del monitor** (interpolando los frames de 30 Hz del | 14 | 2026-09-22 |
| [Workflows operativos](workflows.md) | Procedimientos recurrentes. Documento vivo. Las decisiones van a `docs/adr/`; el detalle | 255 | 2026-09-21 |

## Decisiones (ADR, inmutables)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [ADR 0001 — Modelo de ejecución de módulos de código (`trans`)](adr/0001-modelo-de-modulos.md) | - **Estado**: Aceptado (2026-09-11). Decisión: **A** (con **B** como seguro). | 53 | 2026-09-11 |
| [ADR 0002 — Generar funciones de init de libultra del ROM (des-stubbing)](adr/0002-des-stub-libultra.md) | - **Estado**: Aceptado (2026-09-13). | 66 | 2026-09-13 |
| [ADR 0003 — Subsistema VI: libultra del ROM, runtime solo como hardware](adr/0003-vi-libultra-del-rom.md) | - **Estado**: Aceptado (2026-09-13). | 72 | 2026-09-13 |
| [ADR 0004 — Registro dinámico de módulos de código en bases reutilizadas](adr/0004-registro-dinamico-modulos.md) | - **Estado**: Aceptado (2026-09-14). | 54 | 2026-09-14 |
| [ADR 0005 — Runtime en forks propios y build reproducible](adr/0005-build-reproducible-y-artefactos.md) | - **Estado**: Aceptado (2026-09-16). | 91 | 2026-09-16 |
| [ADR 0006 — Política de rutas relativas y contenido externo](adr/0006-politica-de-rutas-relativas-y-contenido-externo.md) | - **Estado**: Aceptado (2026-09-16). | 48 | 2026-09-16 |
| [ADR 0007 — Cache de assets y loader LZKN64 nativo (la ROM solo la primera vez)](adr/0007-cache-assets-y-loader-nativo.md) | - **Estado**: **Implementado v1** (2026-09-18; validado headless; pendiente validación Windows) | 71 | 2026-09-18 |
| [ADR 0008 — Menú in-game de opciones PC (reutilizando el menú del Expansion Pak)](adr/0008-menu-ingame-opciones-pc.md) | - **Estado**: Aceptado (2026-09-18; implementación pendiente, tras el cache de assets) | 55 | 2026-09-18 |
| [ADR 0009 — No versionar el C recompilado (obra derivada)](adr/0009-no-versionar-c-recompilado.md) | - **Estado**: Aceptado (2026-09-20). | 54 | 2026-09-21 |
| [ADR 0010 — Dependencias del runtime como submódulos git (estándar del ecosistema)](adr/0010-dependencias-runtime-como-submodulos.md) | - **Estado**: Aceptado (2026-09-20). Supersede la parte de **clonado por `port/runtime.lock`** de | 48 | 2026-09-21 |
| [ADR 0011 — Adoptar la vía de recompilación de la referencia (ELF + splat + residente limpio)](adr/0011-via-recompilacion-elf-splat.md) | - **Estado**: Aceptado (2026-09-21). | 65 | 2026-09-21 |

## Evidencia (notas, histórico)

| Documento | Resumen | Líneas | Actualizado |
|---|---|---|---|
| [Issue #3 — HUD de combate: anclaje por identidad de contenido (RESUELTO)](../notes/2026-09-25-f-hud-combate-contenido.md) | **Sesiones 2026-09-25.** Cerrado y **validado en Windows** en las 4 partes. Aquí queda el cómo, | 150 | 2026-09-25 |
| [2026-09-22 — FPS: contador mínimo (`HH_FPS`) y pista `PresentEarly`](../notes/2026-09-22-fps-y-present-early.md) | Evidencia de la sesión. Estado/tareas: `TODO.md`. Referencia MIT en `/tmp/opencode/ref-hh` | 110 | 2026-09-22 |
| [2026-09-22 — Fix mapa: rect negro vs contenido (widescreen fase 07b)](../notes/2026-09-22-fix-mapa-rect-negro-widescreen.md) | Tarea cerrada y **validada en Windows** por el mantenedor (2026-09-22). Continúa | 53 | 2026-09-22 |
| [2026-09-22 — Cursor, carpeta `rom/` en release y README](../notes/2026-09-22-cursor-release-rom-readme.md) | Sesión de cierre tras validar el fix del mapa (fase 07b). Tres tareas pequeñas + hallazgo del | 33 | 2026-09-22 |
| [2026-09-22 — Anclaje del HUD/mapa a los bordes (widescreen, fase 07b)](../notes/2026-09-22-anclaje-hud-widescreen-fase07b.md) | Nota de **tarea** (fase 07b). Contexto previo del radar: | 39 | 2026-09-22 |
| [2026-09-21 — Migración a la vía de recompilación de la referencia (ELF + splat + residente limpio)](../notes/2026-09-21-migracion-via-referencia-elf.md) | Nota de sesión (evidencia + PLAN). Continúa `2026-09-20-ab-bloqueo-boot-per-file.md`. | 165 | 2026-09-21 |
| [2026-09-21 — M4c: SEGV en el teardown (al cerrar)](../notes/2026-09-21-m4c-teardown-segv.md) | Nota de plan. Es el **último defecto conocido** del hito ya validado (vía ELF/splat, entrada al CaC | 94 | 2026-09-21 |
| [2026-09-21 — CI con el C recompilado desde un repo privado de secretos](../notes/2026-09-21-ci-recompilado-desde-repo-privado.md) | Nota de decisión/implementación. Cierra el fallo de `ci.yml` tras ADR 0009 (el C recompilado dejó | 60 | 2026-09-21 |
| [2026-09-21 — Audio: petardeo ligero — causa probable y plan (con la referencia)](../notes/2026-09-21-audio-petardeo-ref-y-plan.md) | Nota de tarea para sesión fresca. El resto del port está **validado en Windows** y **publicado** | 104 | 2026-09-21 |
| [2026-09-21 — Widescreen fase 07b: anclaje del radar a la izquierda](../notes/2026-09-21-anclaje-hud-widescreen-radar.md) | Evidencia de la sesión. Fuente de verdad del estado: `TODO.md` / `PROYECTO.md` / `RETOMAR.md`. | 68 | 2026-09-21 |
| [2026-09-20 — Pipeline de recompilación per-file: estado y bloqueos](../notes/2026-09-20-pipeline-per-file-estado.md) | Nota de sesión (evidencia). Continúa `2026-09-20-lecciones-recompilacion-per-file.md` (método). | 326 | 2026-09-20 |
| [2026-09-20 (noche-5) — Origen del nodo `0x8005BF14` y captura del pisado](../notes/2026-09-20-nodo-8005bf14-origen-y-captura.md) | Continuación de `2026-09-19-causa-raiz-cadencia-frames.md` §13-§16. Aquí se **corrige** el | 429 | 2026-09-20 |
| [Lecciones: recompilación per-file (y cómo abordar otros juegos)](../notes/2026-09-20-lecciones-recompilacion-per-file.md) | **Nota de método, no de un bug concreto.** Resume el error que nos costó cientos de commits de | 78 | 2026-09-20 |
| [2026-09-20 — A/B binario del bloqueo per-file: el freeze es de BOOT (no de la transición)](../notes/2026-09-20-ab-bloqueo-boot-per-file.md) | Nota de sesión (evidencia). Continúa `2026-09-20-pipeline-per-file-estado.md` §15-18. | 110 | 2026-09-20 |
| [2026-09-19 (noche-3) — Verificación independiente de la cadencia y del harness de replay](../notes/2026-09-19-verificacion-cadencia-y-harness-replay.md) | Reanudación tras el cuelgue de la sesión anterior (que quedó en bucle). **No se da por buena** | 101 | 2026-09-19 |
| [2026-09-19 — Veneno capturado: bug de signo-extensión en el wrapper (hh_venom.log) y cadena confirmada](../notes/2026-09-19-veneno-capturado-bug-signo-extension.md) | Ejecuta el paso 1 de `RETOMAR.md` (ronda del `2026-09-18-diferencial-port-emu-vi-cac-paridad.md`): | 163 | 2026-09-19 |
| [2026-09-19 (noche-2) — Inventario de pruebas + nueva evidencia de la fase previa](../notes/2026-09-19-inventario-y-nueva-evidencia-fase-previa.md) | Continúa `2026-09-19-clasificacion-adelanto-fase-previa.md`. Antes de ejecutar nada se hizo el | 165 | 2026-09-19 |
| [2026-09-19 (noche) — CaC: el adelanto NO es cadencia del replay; es espera de escena del motor](../notes/2026-09-19-clasificacion-adelanto-fase-previa.md) | Retoma el **Plan único** de `RETOMAR.md` (paso 1: localizar el primer punto donde el port se | 107 | 2026-09-19 |
| [2026-09-19 (noche-3b) — Causa raíz probable: cadencia de frames (1 vs 2 VI/tick)](../notes/2026-09-19-causa-raiz-cadencia-frames.md) | Continuación directa de `2026-09-19-verificacion-cadencia-y-harness-replay.md`. Esta nota **corrige | 383 | 2026-09-19 |
| [2026-09-19 — Lanzador de la vía de los stalls (`run_stall_check.bat` + `stall_summary.ps1`)](../notes/2026-09-19-bat-stall-check.md) | Ejecuta el PENDIENTE de `RETOMAR.md`: un lanzador Windows que arranca el port **en vivo**, recoge y | 462 | 2026-09-19 |
| [2026-09-18 — Suavizado (Fase 1): instrumentación de ticks, fixes de AI/audio y plan de cache de assets](../notes/2026-09-18-suavizado-fase1-y-cache-loader.md) | Continúa `notes/2026-09-17-replay-mode-vi-vis-negativo.md` (que recoge, en sus §5b-5i, el detalle | 141 | 2026-09-18 |
| [2026-09-18 (bis) — HITO: el replay reproduce el CaC en port (Win+Linux); el emulador lo pasa con el mismo input](../notes/2026-09-18-hito-replay-reproduce-cac-port-vs-emu.md) | Continúa `2026-09-18-cac-replay-en-vivo-no-reproduce.md`. Grabación nueva del mantenedor: | 70 | 2026-09-18 |
| [2026-09-18 — Fase B: cache de assets + loader LZKN64 nativo (implementado y validado headless)](../notes/2026-09-18-faseb-cache-trans-implementado.md) | Implementa ADR 0007. Continúa `notes/2026-09-18-suavizado-fase1-y-cache-loader.md` y el perfil de | 150 | 2026-09-18 |
| [2026-09-18 (ter) — Diferencial port↔emulador por VI en el CaC: paridad cuando el port no congela](../notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md) | Ejecuta el plan de `RETOMAR.md` (diferencial en el MISMO VI alrededor del envenenamiento) con el | 267 | 2026-09-18 |
| [2026-09-18 — CaC: el replay en vivo no reproduce el freeze (resultados negativos) y plan de determinismo](../notes/2026-09-18-cac-replay-en-vivo-no-reproduce.md) | Continúa `2026-09-17-bizhawk-replay-freeze-con-rafaga.md` y `2026-09-17-replay-mode-vi-vis-negativo.md` | 119 | 2026-09-18 |
| [Work order — Pacing/cadencia: cuadrar la lógica del port con el original](../notes/2026-09-17-workorder-pacing-cadencia.md) | Documento operativo **autocontenido** para retomar ESTA tarea en una sesión nueva. | 179 | 2026-09-17 |
| [Validación Windows (RTX 4080): cadencia corregida y el freeze del CaC persiste](../notes/2026-09-17-validacion-windows-pacing-y-cac.md) | Fase 3 del work order de pacing + arranque de la Parte B del plan del CaC. Fecha: 2026-09-17. | 57 | 2026-09-17 |
| [Replay preciso: modo poll-exacto (el modo VI derivaba)](../notes/2026-09-17-replay-preciso-modo-poll.md) | Arreglo del replay que el mantenedor reportó como impreciso (2026-09-17): | 39 | 2026-09-17 |
| [2026-09-17 — Replay: bug de `mode=vi` (vis negativos), ruta real con `mode=poll`+stride 2, freeze reproducido y sensibilidad a la cuantización de tick](../notes/2026-09-17-replay-mode-vi-vis-negativo.md) | Corrección de método sobre `2026-09-17-bizhawk-replay-freeze-con-rafaga.md` y continuación del | 303 | 2026-09-17 |
| [2026-09-17 — Replay: reloj esclavo (`HH_REPLAY_CLOCK`) y desfase de frames — **WIP**](../notes/2026-09-17-replay-clock-y-desfase-frames-wip.md) | Continúa `2026-09-17-cac-timeline-modulo24-periodo.md` (§4b-5). **Trabajo a medias, parado a | 96 | 2026-09-17 |
| [Ralentizaciones en puertas y 30 Hz lógicos vs refresco (pendiente, posterior al CaC)](../notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md) | Registro de una observación del mantenedor (2026-09-17) para atacar **después** de las tareas en | 50 | 2026-09-17 |
| [2026-09-17 — Plan de revisión del bloqueo al entrar en combate (CaC)](../notes/2026-09-17-plan-revision-bloqueo-cac.md) | Documento de trabajo. Resume lo **probado**, lo que **falta revisar** y el orden propuesto. | 134 | 2026-09-17 |
| [HH_DIAG (logs de diagnóstico opcionales) y protocolo de comparación Linux ↔ Windows](../notes/2026-09-17-logdiag-y-comparacion-linux-windows.md) | Cierre de la Fase 2 (limpieza de instrumentación) y preparación de la Fase 3 en la máquina real. | 88 | 2026-09-17 |
| [Fase 2 — A/B de cesión de turno y descubrimiento: el I/O de los logs always-on dominaba las medidas](../notes/2026-09-17-fase2-ablacion-yield-y-descubrimiento-io.md) | Evidencia de la Fase 2 del work order `notes/2026-09-17-workorder-pacing-cadencia.md`. | 94 | 2026-09-17 |
| [Fase 1 — Limitador del pacing en el port: cesiones del scheduler en cada osSendMesg/osRecvMesg](../notes/2026-09-17-fase1-limitador-pacing-port.md) | Evidencia de la Fase 1 del work order `notes/2026-09-17-workorder-pacing-cadencia.md`. | 111 | 2026-09-17 |
| [Fase 0 — Referencia de cadencia del original (emulador): HH = 30 fps lógicos](../notes/2026-09-17-fase0-referencia-cadencia-emulador.md) | Evidencia de la Fase 0 del work order `notes/2026-09-17-workorder-pacing-cadencia.md`. | 57 | 2026-09-17 |
| [2026-09-17 — CaC: veneno `0xFFFF84CD` del objeto 0x8024A990 — escritor y cadena exacta](../notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md) | Continúa `2026-09-17-cac-ownership-resuelto.md`. Tarea: identificar **quién** escribe el callback | 168 | 2026-09-17 |
| [2026-09-17 — CaC: por qué el port se salta la ráfaga #22 — LÍNEA TEMPORAL del módulo 24 (periodo g2)](../notes/2026-09-17-cac-timeline-modulo24-periodo.md) | Continúa `2026-09-17-cac-veneno-ffff84cd-y-llamante.md` (§10 = primera divergencia de flujo). Esta | 160 | 2026-09-17 |
| [CaC — Pasada Windows con replay (partida nueva) y firma del objeto `0x8024AAF8`](../notes/2026-09-17-cac-replay-windows-y-firma-8024aaf8.md) | Evidencia de la grabación del repro del CaC (2026-09-17) y del flujo de validación por replay. | 45 | 2026-09-17 |
| [CaC — Ownership resuelto (Linux) y repro funcional del freeze](../notes/2026-09-17-cac-ownership-resuelto.md) | Iteración autónoma 2026-09-17. Continúa `notes/2026-09-17-cac-b2-switch-y-bases-reales.md`. | 236 | 2026-09-17 |
| [CaC — B2 avanzado: switch del selector (s0=0x801CC8C4) y análisis de bases reales](../notes/2026-09-17-cac-b2-switch-y-bases-reales.md) | Ronda 2026-09-17 tras refutar B1 (`notes/2026-09-17-cac-b1-refutado-base-real-modulos.md`). | 76 | 2026-09-17 |
| [CaC Parte B (B1) — Solape de módulos 23/8 y entry interior `0x801C1EE0`](../notes/2026-09-17-cac-b1-solape-modulos-23-8.md) | Evidencia de la ronda B1 del plan `notes/2026-09-17-plan-revision-bloqueo-cac.md`. | 59 | 2026-09-17 |
| [CaC — B1 REFUTADO: el callback `0x801C1EE0` es del módulo residente (base real ≠ base link-time)](../notes/2026-09-17-cac-b1-refutado-base-real-modulos.md) | Corrección del diagnóstico de `notes/2026-09-17-cac-b1-confirmado-callback-801c1ee0.md`. | 52 | 2026-09-17 |
| [CaC B1 confirmado — el callback del objeto es `0x801C1EE0` (función de módulo 23) y lo resuelve el módulo equivocado](../notes/2026-09-17-cac-b1-confirmado-callback-801c1ee0.md) | Evidencia directa del bug de propiedad de `func_map`. Fecha: 2026-09-17. | 61 | 2026-09-17 |
| [2026-09-17 — Replay de BizHawk: freeze CaC reproducido CON la ráfaga #22 (teoría del burst saltado, refutada)](../notes/2026-09-17-bizhawk-replay-freeze-con-rafaga.md) | Continúa `2026-09-17-replay-clock-y-desfase-frames-wip.md` (§4b) y | 66 | 2026-09-17 |
| [2026-09-16 — Sesión: B en menús + mid-entry CaC `0x8037948C` + corrupción al entrar en combate](../notes/2026-09-16-sesion-b-menus-combate-corrupcion.md) | Resumen de la sesión para retomar. Estado del build, cambios de runtime y por dónde seguir. | 73 | 2026-09-16 |
| [2026-09-16 — Runtime en forks propios y build reproducible (sustituye el snapshot)](../notes/2026-09-16-runtime-en-forks-y-build-reproducible.md) | Consolida el trabajo del día: receta de build (script + Docker + CI), hallazgo del commit local y | 78 | 2026-09-16 |
| [2026-09-16 — Plan de la próxima sesión: limpieza de rutas/referencias y pipeline de compilación](../notes/2026-09-16-plan-proxima-sesion-limpieza-rutas-y-build.md) | Plan consolidado y **aprobado por el usuario** (queda ejecutarlo). Es la tarea que `RETOMAR.md` debe | 231 | 2026-09-16 |
| [2026-09-16 — Limpieza de rutas/referencias y pipeline de compilación (ejecución del plan)](../notes/2026-09-16-limpieza-rutas-referencias-y-pipeline-build.md) | Nota de sesión. Ejecuta el plan consolidado | 152 | 2026-09-16 |
| [2026-09-16 — Limpieza del repo: purga de `.vs/` e inventario de candidatos](../notes/2026-09-16-limpieza-repo-inventario.md) | Contexto: el usuario crea el repo en GitHub (`hunkstalker/hybrid-heaven-recomp`) y pide limpiar | 67 | 2026-09-16 |
| [2026-09-16 — Guardado en cápsula VALIDADO en Windows](../notes/2026-09-16-guardado-capsula-validado.md) | Cierre del hito de guardado (Controller Pak). El fix descrito en | 33 | 2026-09-16 |
| [2026-09-16 — Guardado en cápsula (Controller Pak) sin UI de slots + crash de CaC `0x8021D8D0`](../notes/2026-09-16-guardado-capsula-pak-y-crash-cac-8021d8d0.md) | ``` | 195 | 2026-09-16 |
| [2026-09-16 — B físico debe ir atrás en los menús (incl. menú principal)](../notes/2026-09-16-fix-menu-b-fisico-atras.md) | En el menú del juego, el **B físico del mando Xbox** hacía la acción de aceptar en vez de ir atrás. | 39 | 2026-09-16 |
| [2026-09-16 — Crash pocos segundos después de iniciar combate: `M55_FUN_8037948C`](../notes/2026-09-16-fix-combate-midentry-m55-8037948c.md) | Segundo bug de gameplay de la ronda: tras arreglar el arranque del combate, a los pocos segundos cae | 48 | 2026-09-16 |
| [2026-09-16 — Fix del estado de caída: fallthrough M55 `0x8037A6F4` → `0x8037A884` (fuga `0x38`/frame)](../notes/2026-09-16-fix-caida-fallthrough-m55-8037a6f4.md) | Continúa `2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md` (ronda 14). Ahí quedó: láser | 94 | 2026-09-16 |
| [2026-09-16 — Crash en menú: mid-entry `M55_FUN_80378c48` (módulo 55)](../notes/2026-09-16-crash-menu-midentry-m55-80378c48.md) | En una partida avanzada, al entrar en un **menú**: | 54 | 2026-09-16 |
| [2026-09-16 — Crash al entrar en CaC: callback centinela `0xFF7F84CD`](../notes/2026-09-16-crash-combate-centinela-ff7f84cd.md) | Tras el mid-entry `M55_FUN_8037948C`, al entrar en combate cuerpo a cuerpo cae: | 38 | 2026-09-16 |
| [2026-09-16 — Crash al cruzar una puerta (cinemática): mid-entry `M9_FUN_80203830` (módulo 9)](../notes/2026-09-16-crash-cinematica-midentry-m9-80203830.md) | Al cruzar una **puerta que lanza una cinemática** (transición juego → menú): | 76 | 2026-09-16 |
| [2026-09-16 — Combate CaC: corrupción de estado (objeto 0x8024A990 y colas)](../notes/2026-09-16-combate-corrupcion-estado-8024a990.md) | Continuación de `notes/2026-09-16-crash-combate-centinela-ff7f84cd.md`. Con la mitigación (`get_function` | 74 | 2026-09-16 |
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
| [Hybrid Heaven: Recompiled — Plan Maestro (documentación detallada)](../notes/archive/2026-09-18-plan-maestro-legacy.md) | ARCHIVO HISTÓRICO (congelado 2026-09-18). No editar. Contenido del antiguo `docs/README.md` | 240 | 2026-09-18 |

## Datos generados (`notes/reference/`)

| Fichero | Tamaño |
|---|---|
| `notes/reference/n64sym_osfuncs_us_retail.txt` | 3,640 B |
