# Fix: subtítulos de la intro al skipear (salían en el gameplay)

> Sesión **2026-10-08**, directo en **`main`**. Estado: **HECHO y validado en Windows** (mantenedor).
> Contexto del motor de subtítulos: `notes/2026-10-06-subtitulos-intro.md`. Handoff: `RETOMAR.md`
> §TAREA 1.

## 1. Síntoma (mantenedor)

- Al **saltar la introducción** con **START/ENTER** **antes** de que saliera el primer subtítulo, los
  subtítulos **salían luego durante el gameplay**.
- En el gameplay, pulsar **A/J** hacía que dejaran de salir (aunque no se vieran). Ese atajo **no**
  debía afectar: el skip de la cinemática es **START/ENTER**, no A/J.

## 2. Causa raíz (código, confirmada)

El skip de subtítulos se evaluaba **solo con la secuencia activa** (`g_active`, ya anclada). Al
skipear antes del ancla la secuencia está **armada** (`g_pending`) → esa pulsación **no** la
cancelaba; cuando el **ancla** disparaba (fin de la 2.ª oleada de cargas, ya en gameplay) la
secuencia se **activaba** en el gameplay y empezaba a subtitular allí.

(`src/subsystems/subtitles.cpp`: `begin()` arma → `notify_scene()` marca 0x104 → `notify_load()`
detecta la 2.ª oleada → `tick()` ancla. El bloque de skip estaba **después** de
`if (!g_active) return;`.)

## 3. Fix

En `src/subsystems/subtitles.cpp`:

1. **Evaluar el flanco de skip también mientras está ARMADA**: el bloque de skip se movió al
   principio de `tick()` y corre si `g_pending || g_active`. Mientras está armada solo cancela si ya
   se vio la escena del prólogo (`g_scene_seen`), para no confundir pulsaciones de menú.
2. **Sembrar el flanco en `begin()`** (`g_seed_skip = true`) para que la pulsación que abre
   **EMPEZAR PARTIDA** no se interprete como skip. Se **eliminó** el `g_seed_skip = true` del ancla
   (ya no hace falta y podía tragarse un skip real en el frame del ancla).
3. **`kSkipMask` = SOLO START** (`0x1000`), quitando **A** (`0x8000`): A (mando) / J (teclado) **no**
   cancelan los subtítulos. START/ENTER sí (salta la cinemática nativa y cancela los subtítulos a la
   vez).
4. **No** consume input (usa `hh_input_buttons_now()`, máscara cruda): el juego sigue recibiendo
   START/ENTER para saltar la cinemática.

Traza nueva: `[subs] skip (armada=<0/1> activa=<0/1> btn=0xNNNN)`.

## 4. Validación (Windows, mantenedor)

- **A/J** durante los subtítulos → **no** desaparecen. ✔
- **START/ENTER** durante la intro (antes del 1er subtítulo) → salta la intro y **no** aparecen
  subtítulos en el gameplay (`[subs] skip (armada=1 activa=0 ...)`). ✔
- Flujo normal (sin tocar nada) → subtitula como antes. ✔

## 5. Descartado

- **`stop()` al salir de la escena 0x104** (punto 3 del handoff): no se añadió. Depende de que la
  cinemática **no cambie de escena** durante sus ~5,6 min; si cambiara, cortaría los subtítulos del
  prólogo normal. El fix del flanco armado ataca la causa directa. Red de seguridad opcional solo si
  se confirma que 0x104 es constante.

## 6. Ficheros

- `src/subsystems/subtitles.cpp` (único fichero de código).
