# 2026-09-14 — Geometría y píxeles alcanzados (logo, título y attract en RT64)

> Cierra el objetivo del work order original ("llegar a geometría/píxeles"). Continúa
> `notes/2026-09-14-registro-dinamico-modulos.md`.

## 1. Evidencia (capturas del port en Xvfb :99)

Con `import -window root` durante un run normal (`HH_VERBOSE=1`, ~200 s):

| Archivo (`work/debug/`) | t | Contenido |
|---|---|---|
| `port_shot_45.png`  | ~45 s  | Logo **HYBRID HEAVEN** (attract) |
| `port_shot_80.png`  | ~80 s  | **Pantalla de título**: logo, "PRESS START BUTTON", "(C) KONAMI & KONAMI COMPUTER ENTERTAINMENT OSAKA ALL RIGHTS RESERVED" |
| `port_shot_120.png` | ~120 s | Escena 3D del attract (fachada/edificio con ventanas y volúmenes) |
| `port_shot_160.png` | ~160 s | Otra escena del attract (fondo azul con objeto rojo) |

⇒ **RT64 renderiza geometría 3D real y texto del juego** (no solo DLs contadas): el port ha
superado el arranque/carga y la transición, y muestra el modo título/attract.

## 2. Estado

- `fe00=0x3C01`, `fe02=0x80` (marcadores de la transición, estables).
- `0x80037750` (fase) = 0: corresponde a **título/attract**; el juego no ha entrado en gameplay.
- ~3000 tasks gfx (`type=1`) en el run, sin SEGV durante la ejecución (el SEGV observado en runs
  anteriores ocurre al **teardown** del `timeout`, en hilos que siguen ejecutando código de módulo
  con el estado de cierre; no es el bloqueo de gameplay).
- Símbolos: 0 `Failed to find function` en runs largos (ver nota de registro dinámico).

## 3. Siguiente

1. **Entrar en gameplay**: "PRESS START BUTTON" requiere **input** (el harness headless no pulsa
   nada). Opciones: sintetizar input (tecla/ botón en `hh::poll_input` o por env), o comparar contra
   el emulador con input. Verificar que `0x80037750` pasa a 1 y que el attract se corta.
2. **Robustez de cierre**: el SEGV del teardown en código de módulo (p.ej. `M25_FUN_801e2d94`).
3. Validar audio audible / guardado / textos (backlog).

## 4. Artefactos

`work/debug/port_shot_{45,80,120,160}.png` (gitignored; el usuario los abre desde su filesystem),
`work/debug/run_shots.log`.
