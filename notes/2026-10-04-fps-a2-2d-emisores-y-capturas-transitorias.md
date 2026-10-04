# FPS/interpolación — A2.2d (efectos/2D pasada 2): C768 materializa, opción core (a) inerte y capturas = transitorios (2026-10-04, sesión 5)

> Rama `fps-interpolacion-tagging`. **Cierra A2.2d**. Se implementó el *tagging por emisor* y se midió:
> solo `C768` materializa; el resto (`7DE4/8F30/8754/…`) queda huérfano por la **frontera de workload**.
> Se probó el fix core (a) (materializar el `TransformGroup` en el `push`) y resultó **inerte** in
> gameplay (HUD intacto). Se **revierte (a)**. Se demuestra que las **capturas de efectos son
> transitorios** (aparición/cambio de estado/teletransporte), no fallos. Cobertura final **98.6%**.
> Reglas: `AGENTS.md`, `docs/documentation.md`.

## 0. TL;DR

- **Identificado el emisor de los efectos**: `func_8000C768` (tipo 6/12). Sus grupos **sí materializan**
  (`explicit_ids` 0 → ~2.300/s, `groups_seen` sube); `hh_pairdump.log` sale **100% `id=EE0F…`**.
- `emitter_wrap` (`7DE4/82C4/8754/8B9C/8F30/D1CC/A06C/13828`, codes 4–14): sus `gEXMatrixGroup`
  **se despachan pero NO materializan** (`emitmat=[15:…]` en gameplay, sin ningún code 4–14). Frontera
  de workload confirmada.
- **Opción (a) core** (materializar el `TransformGroup` en el `push`): implementada, **HUD intacto**,
  pero **inerte** — `emitmat` sigue mostrando solo el code 15. Revertida.
- **Las capturas no son fallos**: ningún `id` con racha de no-emparejado > 3 frames (mediana 2); las
  transiciones de puerta son **cambio de generación** (mismas posiciones, ids nuevos) → snap correcto.
- Cobertura del tagging: **98.6%** con id explícito · 2.0% sin pareja · **1.44% AUTO** (sin tag, no
  "moved", no dispara capturas).
- Nueva instrumentación conservada: `emitmat=[…]` en `[hh-pair]`.

## 1. Diagnóstico por emisor (MEDIDO)

Se re-añadió un grupo de **MODELVIEW** por emisor en `emitter_wrap` con un id reconocible
(`0xEE000000 | (id_emisor << 16) | (slot & 0xFFFF)`) y se cambió `C768` al mismo esquema (code 15).
Run del mantenedor (FIGHT, minas, láser, partículas, puerta):

| Señal | Run 1 (C768 off) | Run 2 (C768 on) | Run 3/4 |
|---|---|---|---|
| `explicit_ids` | 0/s | ~2.350/s | ~2.000–2.750/s |
| `groups_seen` | 0 | ~292k | sube |
| `hh_pairdump` | 626 líneas, **todas `FFFFFFFF`** (AUTO) | 1.338, **todas `EE0F`** | 1.524, **todas `EE0F`** |
| `emitmat` (run 4) | — | — | **`[15:…]` solo** |

- El `id=EE0F…` (code 15 = `C768`) prueba que **la geometría de los efectos la dibuja `C768`** y que
  materializa. Cada transform tiene **id propio** (`stable_slot`).
- **Ningún** code 4–14 materializa (ni en intro con `HH_FORCE_INTRO=1` ni en gameplay), pese a que
  `7DE4/8F30` disparan. Conclusión: la geometría de esos emisores cae en **otro workload** que el push;
  el `TransformGroup` queda huérfano.

## 2. Cambios port-only (se conservan)

`src/hooks/model_tagging.cpp`:

- `emitter_wrap()` emite además un `gEXMatrixGroupDecomposed` de **modelview** por emisor (diagnóstico,
  gated por `HH_EMIT_TAG`), con `ORDER_AUTO` (nunca `LINEAR` con N transforms) y push/pop balanceados
  alrededor de `emitter_trace`. Los 2D de menú siguen fuera (no se envuelven).
- `hh_emit_c768_hook`: gate **unificado** `HH_EMIT_TAG=1` (alias `HH_FX_EMIT`) en vez de solo
  `HH_FX_EMIT`; id reconocible `EEF0xxxx`. Eliminado `g_fx_emit` (redundante).
- **Por defecto seguimos sin tocar nada**: `g_enabled` (HH_MTXGROUP) y `g_emit_tag` (HH_EMIT_TAG) son
  opt-in.

`src/platform/rt64_render_context.cpp`: `[hh-pair]` imprime `emitmat=[code:count …]` (histograma de
materializaciones por emisor).

## 3. Opción (a) core — implementada, medida y REVERTIDA

Idea (plan 1): materializar el `TransformGroup` en `RSP::matrixId` (push) para que no quede huérfano si
el `pop`/`clearExtended` llega antes que la geometría (sub-DL `G_DL`).

- Implementación **acotada**: al empujar un grupo de **modelview explícito** (`!proj`, id ≠ AUTO/IGNORE)
  se crea el `TransformGroup` en el workload del push (miembros `hhPushedGroup*`); el primer
  `setVertexCommon` lo reutiliza. **No** crea `worldTransform` en el push → no añade entradas a
  `worldTransforms/worldIndex` (que es lo que rompió el HUD en el intento A previo).
- **Validación**: HUD/widescreen **intactos**, sin asserts. Pero **inerte**: `emitmat=[15:…]` (solo
  C768); ningún code 4–14. El `setVertexCommon` de la geometría de esos emisores ocurre en **otro
  workload** (`hhPushedGroupWorkload != workloadCursor`), así que el pendiente nunca se consume.
- **Decisión**: revertida (código muerto). Para cruzar la frontera solo quedan el "grupo activo"
  cross-workload (descartado: asocia por tiempo → rompe HUD) o **option (b): rewrite en `send_dl`**.

## 4. Las capturas son transitorios (MEDIDO)

Análisis de `hh_pairdump.log` (run 4: 1.524 líneas, 377 frames, 570 ids):

- **Ningún id** tiene racha de no-emparejado consecutivo **> 3** frames; **mediana 2 frames en total**
  por id; 151/570 ids aparecen en un solo frame.
- Los picos coinciden con **aparición/cambio de estado**. Ejemplo de **transición de puerta**
  (teleport): `f=948` y `f=990` tienen **las mismas posiciones** con **ids distintos**
  (`EE0F0130` → `EE0F014A`) → no se movieron: **cambió la generación** (`interp_id` mezcla
  `sGeneration`; el corte avanza la generación). Un frame de "todo nuevo" → snap + 1 captura.
- `[hh-interp]` registró los cortes (`gen=3…8`, `dist=122/135/582…`).

Conclusión: minas, drones láser, **transición de puerta** y **FIGHT** (rect de texto que aparece y
luego empareja durante toda la cinemática) **no son fallos**; son ids nuevos en su primer
frame/cambio. Ningún objeto se queda mal-emparejado de forma sostenida.

## 5. Cobertura final

En gameplay (81 muestras):
- **98.56%** de los transforms con id explícito.
- **1.93%** sin pareja; de ellos ~26% taggeados (id nuevo/cambiado: snap correcto) y **1.44% AUTO**.
- El **1.44% AUTO** son los grupos huérfanos: están *unpaired* pero **no "moved"** → **no disparan
  capturas** y RT64 los empareja por heurística. Perseguirlos no cambia lo visible.

## 6. Conclusión

- A2.2d **cierra**: los efectos (minas/láser/partículas/puertas-FIGHT) **no tienen artefacto visual**.
  Lo que disparaba capturas son transitorios legítimos, no mal-emparejamiento.
- La vía "tagging por emisor" **no cruza la frontera de workload** (medida); el único emisor útil
  (`C768`) ya se taggea.
- **Cámara**: resuelta en `46b3f0d` (proyección + generación).

## 7. Siguiente (propuesto)

- **Partículas de sprites al curarse**: se ven como **cuadrados con degradado** (posible **alpha** de
  sprite). Es un tema visual distinto de #10. Reproducir al curarse y revisar el path de sprite/2D
  (¿`gEX` de sprite, `texrect`, o el alpha del RDP?).
- **A2.4 LOD**: localizar el campo de LOD del modelo o cerrar como "no aplica" (sin caso observado).
- **#10**: sin síntoma reciente (varias curas sin romper huesos) → cubierto salvo indicios nuevos.
- **#6/#8**: aura del jefe, resuelto con el gate de escala ya commiteado.
- **Limpieza de instrumentación** de pasada 2/tagging cuando cierre la épica.

## 8. Pitfalls (NO repetir)

- El tagging por emisor (`gEXMatrixGroup` alrededor del emisor) **no** materializa salvo donde la
  geometría va en el mismo workload (`C768`); el resto queda huérfano por la frontera.
- Materializar en el `push` (plan 1) **no** cruza la frontera si la geometría cae en otro workload.
- **No** envolver los 2D de menú (`7750/78AC/79B0`, `919C/11958`, `A828`): congela.
- `unpaired` **no** mide mal-emparejamiento: validar transitorios por **racha de frames** del `id`, no
  por capturas sueltas.
