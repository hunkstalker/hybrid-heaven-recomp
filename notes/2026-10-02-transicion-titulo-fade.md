# Transición del título del Área: fundido (fade-in/fade-out) y hold (2026-10-02)

> Sesión 2026-10-02. Rama **`menu-carga-guardado-partida`**. Ajuste de la **transición al cargar
> partida** (telón negro + `AREA N` + nombre en Work Sans) para acercarla **1:1 al original**:
> fundido de entrada, tiempo en pantalla y fundido de salida. Handoff de la tarea.

## 1. Qué hace el original `[MEDIDO]` (C recompilado)

- `func_801C3F48` (callback de **fade**): `lbu $v1,0xB(struct)` + `addiu +8` por frame (cap `0xFF`)
  → el alfa del texto sube **+8/frame**. Cuando llega a `0x100`, fija `0xFF`, pone el contador de hold
  en `0x50` (**80 frames**) y salta a `func_801C4018`.
- `func_801C4018` (**espera**): sale a la transición al pulsar botón (`&0xB000`) o al agotar el
  contador de 80 frames.
- `func_801C4074` (**transición de escena**).
- Evidencia: `build/recomp/asm/file_024.s` y `build/recomp/RecompiledFuncs/funcs_68.c`.

## 2. Problemas reportados (mantenedor)

1. El texto aparecía **demasiado repentino**; en el original el fundido de fondo+texto es **más suave
   y tarda más**.
2. El título **duraba demasiado** en pantalla vs. el original.
3. Al alargar/fundir el fondo, **se colaba el título nativo** de detrás.

## 3. Cambios

- **Fade por TIEMPO** (no por frame, que depende del ritmo del port): `area_title_alpha()` usa
  `elapsed / HH_TITLE_FADE_MS` (por defecto **2000 ms**). Nuevo `g_area_title_start_ms`.
- **Fade-out real**: antes se ocultaba de golpe (`hide_now`). Nuevo `hh::overlay::fade_out_menu(ms)`
  (animado por el **hilo de render**, porque tras la transición ya no se publican frames): funde el
  **texto** a negro y luego limpia el frame. `begin_area_title_fadeout()` (menu_overlay) mantiene el
  candado hasta que termina; `tick()` lo suelta. Duración `HH_TITLE_FADEOUT_MS` (def. **1000 ms**).
- **Hold tras la transición**: `HH_TITLE_TRANS_MS` (def. **400**; antes 900 fijos).
- **Telón negro OPACO**: el panel **no** se funde (se transparentaría y dejaría ver el **título
  nativo** que el juego sigue dibujando detrás). El fundido se aplica **solo al texto**. Es el
  compromiso actual; para fundir el fondo habría que **suprimir el dibujo nativo** del título.

## 4. Knobs (por entorno)

| variable | defecto | qué |
|---|---|---|
| `HH_TITLE_FADE_MS` | 2000 | fundido de entrada del texto |
| `HH_TITLE_FADEOUT_MS` | 1000 | fundido de salida del texto |
| `HH_TITLE_TRANS_MS` | 400 | espera tras la transición antes del fade-out (`0` = ya) |
| `HH_TITLE_HOLD_MS` | 1500 | hold del frame sin publicar (ya existía) |

## 5. Estado / validación

- **Build Linux**: OK.
- **Validado en Windows**: pendiente de la última iteración (panel opaco + fade-out).
- **Ficheros**: `src/hooks/sections.cpp`, `src/hooks/menu_overlay.cpp`,
  `src/platform/overlay.cpp`, `include/hh/overlay.h`.
- **Pendiente**: si se quiere que **el negro también se funda**, suprimir el título nativo
  (draw/textura) en vez de taparlo.

## Referencias

- Título del Área (overlay, gráfico nativo): `notes/2026-10-01-titulo-area-carga.md`,
  `notes/2026-10-01-titulo-area-calibracion.md`.
- Rótulo `AREA` traducido: `notes/2026-10-02-titulo-area-rotulo-traducido.md`.
- Reproducción del original (oráculo): `docs/workflows.md` §6.
