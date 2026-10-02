# Handoff — bugs #13 (minimapa por área) y #14 (crash del combate/veneno = CaC)

> 2026-10-02. Handoff para retomar dos bugs abiertos reportados por El-Rana:
> **#13** (HUD/minimapa desanclado al cambiar de Área) y **#14** (crash al recibir el ataque de
> **veneno** de un enemigo). Estado: **abiertos**, ambos reproducibles.
>
> **El #14 es el MISMO bug que el "CaC"/veneno ya investigado** (2026-09-16/19). Aquellas notas son
> evidencia directa y hay que leerlas antes de tocar nada; este documento resume lo sabido y cómo
> aprovechar `IR A ÁREA`/`DEBUG LEVELS` para reproducir a voluntad.

---

## Issue #13 — Área 3-1 / Mini Mapa

- **Síntoma**: al empezar un **Área nueva** (reportado en 3-1; el reporter prevé 4-1, etc.), el
  **minimapa aparece fuera de su marco** (desanclado). El **círculo de salud** y las barras de
  **POWER/STAMINA** (combate) salen **bien**.
- Versión reportada: v0.4.4. URL: https://github.com/hunkstalker/hybrid-heaven-recomp/issues/13
- Relacionado: **issue #7** (mismo síntoma al inicio de 2-1) — allí se cambió el anclaje del minimapa
  de identidad `dl:<dirección>#<hash>` a **hash de contenido** (`notes/2026-09-26-fix-minimapa-contenido.md`).
  El #13 demuestra que ese arreglo **no cubre todas las áreas**: sigue habiendo overlays de mapa cuyo
  **hash de contenido cambia por capítulo/área**.

### Causa (hipótesis medida)

`class_of` (`src/hooks/hud_rewrite.cpp:792`) clasifica el minimapa (`kRight`) por:
1. identidades **exactas** (`fill:0x00000000@…`, `dl:0x030002e0#bbb8c0ba`, `dl:0x03000f10#1427da33`);
2. **hash de contenido** `dl:` fijo (`0xbbb8c0ba` / `0x1427da33`).

En un Área nueva el **overlay del mapa es otro recurso** → ni la dirección ni el **hash** coinciden →
`kAuto` → no recibe `viewport_align(RIGHT)` → se dibuja **fuera del panel**. Patrón de siempre:
**anclar por detección/hash es frágil**.

### Problema de fondo (decidido: hay que cambiarlo)

El anclaje del HUD/mapa se hace **por detección** (hash/posición/color), que ha dado problemas
recurrentes (#3, #7, #13). El mantenedor quiere **una solución de raíz**, no otro parche de hash. Pistas:

- El minimapa se dibuja bajo **proyección ortográfica** con `viewport_align`/scissor; el **panel** del
  mapa (fondo negro `fill:0x00000000@197,143,277,223`) ya casa por **posición** y es estable.
- El anclaje óptimo probablemente sea **estructural** (por **qué** se está dibujando: viewport/scissor
  del grupo `right`, o el **carril/callback** del HUD), no por contenido del recurso.
- Herramientas: **F7** (captura pareada) + **Inspector de RT64** (`HH_DEVELOPER=1`, F1);
  `HH_HUD_REWRITE_TRACE`/`HH_HUD_SITES_TRACE` (`hh_hud.log`), `HH_FULL_FRAME=0`, `HH_NO_HUD_REWRITE=1`.

### Plan

1. **Capturar el Área que falla** (3-1; idealmente 4-1 y otras): con F7/Inspector, volcar la
   identidad/hash/scissor **exactos** del mesh de mapa que sale desanclado.
2. **Decidir la solución estructural**: identificar una propiedad **estable** del HUD (grupo de
   viewport ortográfico, orden de call, rango de scissor) que agrupe *todos* los overlays de mapa sin
   depender del recurso. Objetivo: eliminar los `hash`/identidades exactas del minimapa.
3. Validar en **Windows** en las áreas conocidas (2-1, 3-1, …) y confirmar que no hay **over-match**.

---

## Issue #14 — Área 3-3 / Crasheo (ataque de veneno) — MISMO BUG QUE EL CaC

- **Síntoma**: al recibir el ataque de **veneno** de un enemigo (`Mira` en 3-3; también
  `Alkalurops`), el juego **crashea**. Reproducido en **v0.5.1**. El reporter intuye que los ataques
  **elementales** podrían fallar igual.
  URL: https://github.com/hunkstalker/hybrid-heaven-recomp/issues/14
- **Es el mismo bug que el "CaC"/veneno** ya investigado en profundidad. Documentos maestros
  (leerlos antes de nada):
  - `notes/2026-09-17-plan-revision-bloqueo-cac.md` (plan + hechos probados).
  - `notes/2026-09-17-cac-ownership-resuelto.md` (ownership de módulos, `sel` dentro de ventana).
  - `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md` (**primera divergencia real = carga #22**).
  - `notes/2026-09-19-veneno-capturado-bug-signo-extension.md` (workaround, timing frame↔VI).
  - `notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md` (diferencial, freeze intermitente).

### Lo ya probado (NO repetir)

- **Mecanismo del "veneno"**: el objeto del combate recorre callbacks de **módulo 10**;
  `M10_FUN_8021b280` → `M10_FUN_8022c7ac` → `M55_FUN_80379410(a1=1)` → `FUN_800058dc` escribe el
  callback inválido **`0xFFFF84CD`** en `+0x1C` (el `a1=1` del trampolín = `1 - 0x7B34`).
  `M7_FUN_8012e774` lo enmascara a `0xFF7F84CD`; el dispatcher lo trata como **centinela no-op** →
  state machine atascada → `[BADMQ]` → watchdog. El runtime **ya** mitiga el centinela: no es el crash en sí.
- **NO es** guardado/carga, NI objetos de NPC, NI daño (probados).
- **El emulador NUNCA ejecuta** el gate ni instala callbacks de módulos 9/10/12 en objetos (con el mismo
  input); el **port sí** → **divergencia de estado aguas arriba**.
- **Primera divergencia real (loader `FUN_80003824`)**: las **21 primeras cargas** coinciden 1:1; en la
  **#22** el emulador pide la **ráfaga de recursos de la escena siguiente** (t≈36,6 s) y el **port se la
  salta**, yendo directo a la cadena de módulos siguiente. A partir de ahí todo diverge. Ver
  `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md` §10.
- **Fixes descartados**: `HH_RANGECLEAR=1` (range-clear al cargar) → sin cambios; `HH_NO_DISABLE=1`
  (ignorar el centinela) → sigue el cuelgue; `HH_DET_CLOCK=1` → mantiene 30 fps pero **no** elimina la
  carrera; el disparador son los **stalls/jitter del hilo de juego**, no el reloj.
- **`0x801CC8C4` (sel) cae DENTRO** de la ventana de un módulo (`0x801BF1A0+0xD724`) → lo fija la
  **carga/relocación del módulo**, no un `sb` (por eso `HH_WATCH` no ve las escrituras).

### Por qué ahora es más atacable

Ahora se puede **viajar rápido entre niveles** (`EXTRAS > IR A ÁREA` + `DEBUG LEVELS`), así que se puede
**reproducir a voluntad** (saltar a 3-3) y recorrer el juego para mapear el alcance (¿solo veneno? ¿otros
elementales? ¿qué enemigos?). Antes dependía de llegar jugando.

### Plan (continuar donde se dejó)

1. **Atacar la causa raíz aguas arriba**: identificar **qué dispara la carga #22** en el emulador (la
   tabla/estado que procesa el dispatcher `0x80004778`) y **por qué el port no la pide**
   (`notes/…-veneno…` §10). Es el primer desvío de flujo.
2. **Diferencial estado-contra-estado**: save de mupen en el mismo punto (`.mpk`, **no** savestate) para
   comparar; o replay largo con el mismo input (harness `emu_ref.sh`, `HH_REPLAY`).
3. **Alinear frame↔VI** (si el desvío resulta de timing/stalls): que cada frame abarque 1 tick/2 VI pase
   lo que pase; ver `notes/2026-09-19-veneno-capturado-bug-signo-extension.md` §9.
4. **Validar** con el replay Linux fiel y en **Windows** (el freeze era ~100 % en vivo).

### Instruments

- **Salto de nivel**: `EXTRAS > IR A ÁREA` + `EXTRAS > DEBUG LEVELS` (**F5/F6** ±1, **RePág/AvPág** ±10,
  **Inicio** = 0; indicador `idx=`).
- **Crash**: `HH_CRASH_LOG=1` → `hh_crash*.log` + volcado RDRAM/DMEM; watchdog `HH_DIAG=1`.
- **Módulos/veneno**: `HH_FUNC_OWNER=0x...`, `HH_MODTRACE=…`, `HH_B280TRACE`, `HH_WATCH_ADDR`,
  `HH_TBLTRACE`, `HH_RANGECLEAR`, `HH_NO_DISABLE` (descartados estos dos últimos como fix).
- **Oráculo**: `tools/analysis/emu_ref.sh` (`HB_TRACE_EXEC`, `HH_CALLTRACE`/`HH_JALTRACE`, `diff_rdram.py`).

---

## Prioridad sugerida

- **#13** primero: acotado y patrón recurrente; decisión de diseño clara (anclaje **estructural** del
  HUD/mapa).
- **#14** después (o en paralelo): reaparición del **CaC/veneno**; el camino ya está muy avanzado
  (causa raíz acotada a la **carga #22** del loader).
- **Un tema = un commit** al validar; actualizar `TODO.md` y esta nota con hallazgos.
