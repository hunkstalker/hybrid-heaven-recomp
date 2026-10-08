# Subtítulos de la intro en el modo attract (título inactivo)

> Sesión **2026-10-08**, directo en **`main`** (pulido de la intro antes de la traducción).
> Estado: **HECHO y validado en Windows** (mantenedor). Continúa
> `notes/2026-10-06-subtitulos-intro.md` y `notes/2026-10-08-fix-subtitulos-intro-skip.md`.

## 1. Síntoma (mantenedor)

La **cinemática del prólogo** no solo se reproduce en `NUEVA PARTIDA → EMPEZAR PARTIDA`: también al
**no pulsar nada** en el menú de título durante unos segundos (**modo attract**). En esa vía los
subtítulos **no salían**.

## 2. Causa

Los subtítulos solo se **armaban** en el flujo del menú (`hh::subtitles::begin("intro_prologue")` en
`EMPEZAR PARTIDA`, `src/hooks/sections.cpp`). El attract entra en la cinemática **directamente**
(menú inactivo → `goto 0x801C2050` → `func_801C5A00`), sin pasar por `EMPEZAR PARTIDA`, así que nunca
se armaban. La lógica de ancla (`escena 0x104` + 2.ª oleada de cargas) ya era válida para ambas vías.

## 3. Fix

`src/subsystems/subtitles.cpp`: armar también al **detectar la ENTRADA** en la escena objetivo, común
a las dos vías.

- Nuevo `g_prev_scene`. En `notify_scene(scene)`: si `scene == 0x104` y `g_prev_scene != 0x104`
  (**flanco de entrada**, no permanencia) y no está ya armada/activa → `begin("intro_prologue")`.
- El flanco evita **re-armar** tras terminar/skipear mientras la escena sigue siendo 0x104 (y re-arma
  si se vuelve a entrar, p. ej. cuando el attract repite la intro).
- La vía `EMPEZAR PARTIDA` no cambia: su `begin()` explícito ya deja `g_pending`, así que el auto-arm
  no duplica.

## 4. Evidencia (headless = attract, sin input)

Run del port Linux (Xvfb + lavapipe) sin input (llega solo al attract):

```
[scene] transicion func_8012FE50 tipo=1 valor=260 ... | glob 0x801BBBF0 [+4]=260
[subs] auto-arm al entrar en la escena 0x0104 (attract/nueva partida)
[subs] escena objetivo 0x0104 activa (esperando 2.ª oleada de cargas)
[subs] ANCLA (fin 2.ª oleada de cargas) vi=4819
[subs] linea 0 pag 1/7 (t=11000 ms) ...
```

Confirma que el attract **sí** usa la escena **0x104** y que ahora arma/ancla/publica.

## 5. Validación (Windows, mantenedor)

- **Attract** (dejar el título sin tocar): salen los subtítulos. ✔
- **NUEVA PARTIDA → EMPEZAR PARTIDA**: sin regresión. ✔
- **START/ENTER en el attract**: salta y cancela los subtítulos. ✔

## 6. Ficheros

- `src/subsystems/subtitles.cpp` (`g_prev_scene` + auto-arm en `notify_scene`).
