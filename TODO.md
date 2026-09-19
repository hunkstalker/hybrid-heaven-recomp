# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` y `notes/` (no duplicar). Histórico: `notes/`, `notes/archive/`.

## Ahora (priorizado)

- [ ] **Audio: sincronizar la tasa** (feedback del error de cola SDL en `osAiGetLength`) para quitar
  los descartes periódicos del watermark. Ver `notes/2026-09-18-suavizado-fase1-y-cache-loader.md` §2.
- [ ] **Menú IN-GAME de opciones PC (ADR 0008)**: reutilizar el menú del `expansionram` (módulo idx 23).
  **Antes: spike go/no-go** (nota 09-18 §6: handler de módulo end-to-end, rótulo con fuentes del juego,
  aplicar/persistir `GraphicsConfig`).
- [ ] **Definir ADR 0009** (estrategia de cobertura nativa / clean-room) **cuando se adopte la visión**
  de `docs/README.md`. Incluye el **manifiesto de reimplementadas** + **métrica de cobertura** (§5).
- [ ] **Teardown SEGV** al cerrar en Windows (`exe +0x12A602`): mapear con el `.map`, reproducir en
  Linux y arreglar el orden de deinit (respuesta a `EXCEPTION_EXECUTE_HANDLER`).
- [ ] **Mando**: identificar el botón N64 que abre el menú de **acciones/lucha en CaC** y asignarlo a
  **X** (`config.ini`). **Bloqueado por el CaC** (el juego se congela antes del combate): revisar cuando
  se resuelva la entrada al combate. Lo normal (pausa/inventario) sale con **Start** y está bien.
  Decidir también `LB` y el atajo de cámara/1ª persona.
- [ ] **Limpieza de instrumentación**: decidir sobre `requeue_pi=true`, los `[MQDROP]`, la sombra
  `hh_sh_*` y el watchpoint (ya está todo gated tras `HH_DIAG`).
- [ ] **Smoke de arranque** (opcional, requiere ROM): con la ROM en `rom\` junto al `.exe`, comprobar
  que la encuentra y que no hay `Failed to find function`. En Docker: `HH_HEADLESS=1` + `rom/`.

## Backlog (priorizado)

- [ ] **CaC: corrupción de estado (BLOQUEANTE)**. Al entrar en combate el objeto `0x8024A990` acaba con
  callback `+0x1C=0xFFFF84CD` y se corrompen colas (`[BADMQ]`). **HITO 2026-09-18**: el replay **reproduce
  el CaC de forma fiable** en port (Windows VI≈20710 y Linux VI≈20949) con `HH_REPLAY_MODE=poll`; el
  **emulador pasa el CaC con el mismo input** (objeto sano `801CB71C`). **Diferencial por VI (2026-09-18)**:
  en 20200/20500/20700/20900 port y emu son **idénticos** en el estado del CaC (cuando el port no
  congela); primera divergencia = **timing** del loader (carga #12: port vis 413 vs emu vi 1535).
  **VENENO CAPTURADO EN VIVO (watchpoint en `0x8024AB14`)**: `FUN_800058dc` escribe `0xFFFF84CD` con
  `a0=0x8024AAF8` (llamante con `a2=0x801BC23A`/`a3=0x801BBBF0`); `M7_FUN_8012e774` lo consume.
  **CONTRALADO EMULADOR (decisivo)**: con el mismo replay, el emu ejecuta `FUN_800058dc` 1426 veces
  pero **0 con el veneno** y **0 veces** `M10_FUN_8021b280`/`M55_FUN_80379410` → **la ruta correcta es
  NO ejecutar el disable**; el callback sano es `801CB71C`. **Cadena confirmada (2026-09-19)**: capturado
  `hh_venom.log` con el wrapper del setter (bug de signo-extensión corregido): el callring da
  `M10_FUN_8021b280 → M10_FUN_8022c7a4 → M10_FUN_8022c5ac → M10_FUN_8022c314 → M10_FUN_8022c478 →
  M55_FUN_80379410 → FUN_800058dc`; `M10_FUN_8021b280` es **callback por puntero** (12 resoluciones,
  `ra=0`). **INSTALADOR Y PUERTA (2026-09-19)**: `M10_FUN_8021b240` publica `0x8021B280` en el slot
  `0x8024C950` (obj `0x8024C934`) vía `FUN_800058dc`, solo si `M7_FUN_80126A0C(obj,0x39,1) != 0`
  (puerta: timer `0x8008D580 < 0x3001` + `FUN_801267B8(lhu[sp+0x1E])==1` + `[0x801BBD71]==0`). Ocurre
  al final del replay (sample ~9803, VI 20006). **Reloj determinista `HH_DET_CLOCK` implementado**
  (`osGetTime = total_vis*781250 + sub-VI`): da **30 fps** pero **NO** arregla la carrera (con watchpoint
  vuelve a aparecer 3/4) → el trigger son los **parones del hilo de juego**, no el origen del reloj.
  **Workaround `HH_NO_DISABLE=1` PROBADO EN VIVO (Windows): NO funciona** (sigue el cuelgue antes del
  CaC) → el disable no es el único bloqueo. Evidencia: en vivo hay ticks de **3 VI** con `guest_busy`
  ~34 ms desde el principio (`logs_nodisable_20260919_081332/hh_slow.log`). **Siguiente (prioridad
  única)**: **alinear frame↔VI** (limiter que reanude en la rejilla VI o desacoplar stalls de
  render/audio/IO). Detalle: `notes/2026-09-19-veneno-capturado-bug-signo-extension.md` y
  `notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md` (§2d/§2e/§6).
- [ ] **Textos/traducción** (requisito de producto): encoding + extracción + re-inserción.
- [ ] **Guardado**: validar Controller Pak contra el emulador; ficheros en disco + **Rumble**.
- [ ] **Builds/empaquetado**: validar "build once, promote" en GitHub y empaquetado **Steam Deck**.
- [ ] **Tarea #3**: mapa overlay→RAM por BizHawk (complementa la medición empírica de bases).
- [ ] **Cadencia/hitches de puertas** (mejora): precarga/decode y enganche a VI
  (`notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md`).
- [ ] **Símbolos**: fronteras gruesas (`0xADDR:0xSIZE`) y auto-mid del módulo 12 (datos como código).
- [ ] **Data-as-code** (189 sospechosas): limpiar → permite reevaluar `use_lookup_for_all_function_calls`.
- [ ] **Ramas del toolchain**: publicar `hybrid-heaven-tool` (13 ficheros) para reproducir la
  regeneración (el build no la necesita).
- [ ] **Higiene del repo** (`notes/2026-09-16-limpieza-repo-inventario.md`): archivar scripts one-off
  de `tools/analysis/`, variantes obsoletas de `config/`, decidir el `work/` rastreado. **NO borrar**
  `*.syms.toml.keep`, `keep_syms*.txt`, `module_extras.json`, `config/n64recomp_changes/*`.
- [ ] **Sanear menciones a la ROM en docs/notas** (frases cortas del juego en `notes/`).

## Hecho (resumen; detalle en `notes/`)

- [x] Arranque completo, gameplay, menús, combate y cinemáticas en Windows (RTX 4080) con mando Xbox.
- [x] Guardado en cápsula (Controller Pak) validado (`osPfsFindFile`→5).
- [x] Audio `aspMain` del ROM recompilado a 43200 Hz; perfiles de mando por contexto.
- [x] Fase B (ADR 0007): cache de assets + loader LZKN64 nativo.
- [x] Rendimiento: `get_function` sin `getenv` por llamada → stalls de 1-4 s a 0 y 30 ticks/s
  (`notes/2026-09-18-faseb-cache-trans-implementado.md` §8/§8b).
- [x] Replay fiel (`HH_REPLAY_MODE=vi`); build reproducible + CI/Releases (ADR 0005).

## Documentos de detalle (no duplicar)

`PROYECTO.md` · `docs/README.md` (visión) · `docs/architecture.md` · `docs/adr/` · `docs/workflows.md`
· `notes/2026-09-1*.md`.
