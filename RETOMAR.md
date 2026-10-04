# RETOMAR — handoff RAMA `fps-interpolacion-tagging` (2026-10-04, sesión 6)

> **TAREA (rama): interpolación fiel / desbloquear FPS.** La **interpolación** (tagging, cámara,
> efectos) está **cerrada**: cámara `46b3f0d`, A2.2d no-bug, bug latente de walkers corregido
> (`a8212b3`). Ahora toca la **cadencia**: **A1 (estabilizar el tick lógico)** y **A3 (validar 120/240)**.
> Referencia: `notes/2026-10-02-workorder-desbloquear-fps-interpolacion.md` §4.
> Reglas: `AGENTS.md` y `docs/documentation.md`.

## INTENCIÓN: integrar en `main` (adelantar los arreglos visuales validados)

**Objetivo de la rama:** llegar a **integrar en `main`** lo que ya está **validado** (aunque no
tengamos el **100% de emparejamiento**), para que esos arreglos visuales lleguen a los usuarios.

**Lo validado y candidato a promover** (cámara, identidad por nodos, **#6** gate de escala, **#8**,
huesos, minas/láseres). **Lo que se deja gateado** (no promover por defecto): efectos/A2.2d e
instrumentación de diagnóstico.

**Plan de integración (por fases; NO es un merge ciego):**
1. **Sincronizar**: `git merge main` en esta rama; resolver conflictos (`src/subsystems/input.cpp`
   —`main` lo tocó para el fix de input— y los `.md` de estado `RETOMAR/TODO/PROYECTO`).
2. **Re-validar** en Windows con los flags ON (`HH_MTXGROUP=1`/`HH_EMIT_TAG=1`) sin regresiones.
3. **Promover**: **encender por defecto** solo lo validado (cámara + identidad + #6); dejar gateado
   lo incompleto.
4. **RT64**: `main` (y esta carpeta, tras revertir) tiene `lib/rt64` **limpio**; la instrumentación
   (gates de escala/rotación, contadores, pairing) vive **solo** en
   `patches/rt64/hh-interpolation-tagging.patch`. Para **activarla** en esta rama:
   `git -C lib/rt64 apply patches/rt64/hh-interpolation-tagging.patch`; para **quitarla**:
   `git -C lib/rt64 checkout -- .`. Para un release, **commitear el fork** (gate de escala, etc.) + subir
   la chincheta. (Explicación completa en `docs/workflows.md §1.2`, que **llega a la rama con el sync del paso 1**.)
5. **Merge/PR a `main`** con la documentación (`notes/2026-10-04-fps-*`).

> Ver también: `main`'s `RETOMAR.md` tiene una sección con este mismo plan (contexto desde `main`).

## Estado — lo que funciona (MEDIDO, run del mantenedor)

- **Sesgado de cámara RESUELTO** (`46b3f0d`, port-only): grupo de PROYECCIÓN con id de cámara + generación.
- **A2.2d CERRADA (no-bug)**: los efectos los dibuja `func_8000C768` y materializa (`id=EE0F…`);
  cobertura 98.6% con id; las capturas de minas/láser/partículas/puerta-FIGHT son **transitorios**.
- **Partículas del heal = no-bug**: los "quads" son el asset original del juego (glow 8x8 + estrella
  16x16); coincide con el emulador. Herramientas: `HH_TEXDUMP` + `tools/analysis/decode_texdump.py`.
- **Bug latente corregido** (`a8212b3`, `dl_snap.cpp`): longitud real de los comandos extendidos en los
  walkers de DL (no observado en HH). Doc: `notes/2026-10-04-fps-walker-dl-comandos-extendidos-latente.md`.

## TAREA SIGUIENTE — A1 tick lógico + A3 validar 120/240

### A1 — Estabilizar el tick lógico (`notes/…-workorder… §4`)

- Garantizar **2 VI/frame estables** (lógica a **30 Hz**, como el N64) y **slips a 3 VI solo cuando el
  trabajo no quepa** (no por jitter). Un tick irregular dispara fallos de matching/interpolación.
- Herramientas: **`HH_DET_CLOCK=1|quant` + `HH_DET_CLOCK_BIAS`** (reloj determinista en el runtime,
  `ultramodern timer.cpp`), compensación de stalls (precarga/caché de módulos `trans`, audio/DMA).
- Verificar que **render/present no realimentan el tick** (que el frame de RT64 no retrase la lógica).
- **Criterio**: cadencia estable (2 VI/tick, `d2` dominante en `hh_tick.log`, `d3/d4+=0`); desaparecen
  los artefactos dependientes de jitter (hitches de puerta).

### A3 — Validar a 120/240 Hz (Windows RTX 4080 + Steam Deck)

- Regresión: menús, guardado, combate, cinemáticas; **sin** parpadeo ni geometría incoherente.
- A/B por métrica (`HH_FPS=1`) y ojo; F9 (interpolación ON/OFF), F8 (PresentEarly).

### Observación del mantenedor (2026-10-04)

**Rara vez ve 120 fps y nunca 240.** `[hh-fps]` ya imprime `present vs target`, `target/vi/swapChain/
refresh/vsync`. Primer paso: **medir** con `HH_FPS=1` a 120/240 (menú GRÁFICOS o `HH_REFRESH_RATE=manual:<hz>`),
distinguir si el cuello está en: (a) **lógica/tick** (slips → `hh_slow.log`), (b) **present/GPU**
(`present` por debajo de `target` con tick sano) o (c) **VSync/monitor** (`target=swapChain`).

## Instrumentación (reutilizable)

- **Cadencia**: `HH_FPS=1` → `[hh-fps]` (update/present + target/vi/swapChain/refresh/vsync);
  `HH_DIAG=1` → **`hh_tick.log`** (ticks, `d1..d4+` = VI por tick, `max_dt`) y **`hh_slow.log`**
  (ticks >36 ms: `send_dl`/`update_screen`/`guest_busy`/`pending_ext`);
  `HH_STATE_SECS=<s>` → `hh_state.log` (estado de hilos).
- **Present/video**: `HH_REFRESH_RATE=original|display|manual:<hz>`; **F9** = toggle interpolación;
  **F8** = menu nativo; `HH_PRESENT_EARLY=0` (=F8 sonda).
- **Runtime**: `HH_VI_EVERY=<n>` (entrega VI al guest; diagnóstico de cadencia), `HH_DET_CLOCK[_BIAS]`.
- **Tagging/interpolación** (de la tarea previa): `HH_MTXGROUP`, `HH_EMIT_TAG`/`HH_FX_EMIT`, `HH_FX_PASS2`,
  `HH_PAIRING` (con `emitmat=[…]`), `HH_PAIRCAP`/`HH_GENCAP`, `HH_PAIRING_DUMP`, `HH_SCALE_GATE`.

### Run del mantenedor (cadencia)

```powershell
hybrid-heaven-recomp\build_windows.local.bat
$env:HH_FPS='1'; $env:HH_DIAG='1'; $env:HH_STATE_SECS='2'; $env:HH_MTXGROUP='1'; $env:HH_EMIT_TAG='1'
hybrid-heaven-recomp\run_windows.bat release
```
Logs en `build\windows\bin\Release\` (`hh.log`, `hh_tick.log`, `hh_slow.log`, `hh_state.log`). Borrar los
`hh_*.log` antes de cada run (algunos abren en `w`/append).

## Árbol y pistas

- Tick/lógica: `src/subsystems/input.cpp` (`get_input`, `HH_DIAG`, `hh_tick.log`/`hh_slow.log`),
  `src/platform/main.cpp` (`HH_STATE_SECS`), runtime `N64ModernRuntime` (`events.cpp`, `timer.cpp`).
- Present/GPU: `src/platform/rt64_render_context.cpp` (`[hh-fps]`, send_dl/update_screen),
  `lib/rt64` (`rt64_workload_queue.cpp`, present queue).
- Notas: `notes/2026-10-02-workorder-desbloquear-fps-interpolacion.md` §4 (A1/A3),
  `notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md`,
  `notes/2026-09-19-causa-raiz-cadencia-frames.md` (1 vs 2 VI/tick),
  `notes/2026-09-22-fps-y-present-early.md`.
- **`lib/rt64`**: en `main` está **limpio** (pineado a `a8f0a70`, con el fix 2D). La instrumentación de
  esta rama va en el **patch**, no commiteada en el submódulo. Para activarla aquí:
  `git -C lib/rt64 apply patches/rt64/hh-interpolation-tagging.patch`; quitarla:
  `git -C lib/rt64 checkout -- .`. **No commitear el submódulo** (fork).

## Pitfalls (NO repetir)

- **Metas**: ">30 visual" ya existe (interpolación); **240 "reales" (lógica a 240) NO** es el objetivo
  (eso es la Fase B/ADR). No confundir fps **presentados** con lógica.
- No concluir cuelgues/freeze solo desde headless; validar en Windows.
- `HH_VI_EVERY` es **diagnóstico global** (baja el frame en todo el juego), no un fix.
- **NO** `git reset --hard`; no editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
