# 2026-09-16 — B físico debe ir atrás en los menús (incl. menú principal)

## Síntoma

En el menú del juego, el **B físico del mando Xbox** hacía la acción de aceptar en vez de ir atrás.
El botón **Select/Back** (mapeado a B del N64) **sí** iba atrás. En juego, B = Z (agacharse).

## Causa

El mapeo por contexto (`config.ini` `[game]`/`[menu]`) detectaba el menú solo con el **flag de UI
in-game `0x802690D0`** (se activa con pausa/mapa, verificado). Ese flag **no se activa en los menús
previos al gameplay** (título / menú principal), así que allí se usaba el perfil `[game]` y el B
físico salía como **Z** (que en esos menús confirma).

## Fix (`port/.../src/game/input.cpp`)

Se añade detección de **front-end** por el **directorio de recursos/código del juego** en
`0x8008DFC0` (0x100 entradas de 8 B, `id16` + `base32`):

- En el front-end (título / menú principal) hay **pocas** entradas; al entrar en gameplay (GAME
  START) sube a **~30**. Evidencia en dumps: `work/debug/emu_menu.t0/t1.bin` = 6 entradas,
  `dump_gameplay.bin` = 32, `dump_menu.bin` (pausa) = 31.
- `hh_frontend_menu()` cuenta entradas (hasta 16) y marca `gameplay_seen` **una vez** alcanza el
  umbral; luego queda fijado (no se vuelve al perfil de menú).
- `menu = ui_flag(0x802690D0) || !gameplay_seen`. Override de diagnóstico: `HH_PAD_CONTEXT=menu|juego`.

Con esto, en el menú principal el B físico pasa a ser **B del N64 (atrás/cancelar)** y no se toca el
mapeo de gameplay (B = Z).

## Verificación

- Build Linux (`build_dbg`): OK.
- Pendiente: validar en Windows que en el menú principal el B físico va atrás.

## Aparcado: SEGV del menú multijugador

En la misma sesión se capturó un `[SEGV]` al entrar en un **menú multijugador** (crash host
`exe+0x55DAF` ≈ `FUN_80026f58`, con `guest sp=8005BE78` y `ra=0`, repitiendo en dos caídas). No se
aborda ahora (rama multijugador fuera de alcance); queda anotado en `TODO.md`.
