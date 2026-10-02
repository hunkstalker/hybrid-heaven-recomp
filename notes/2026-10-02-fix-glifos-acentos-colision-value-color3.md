# Fix — artefactos en el diálogo del ordenador: los acentos pisaban un `value` nativo de color3

> 2026-10-02. Bug reportado por el mantenedor (ventana del ordenador con "caracteres alienígenas").
> **Resuelto y VALIDADO en Windows.** Corrige/depura el diagnóstico del handoff
> `2026-10-02-handoff-glifos-acentos-colision-kana.md` (que atribuía el fallo a color0/kana).
> Distinción **medido** / **inferido** explícita.

## 1. Síntoma (medido)

Al inicio, tras el primer punto de guardado, el PJ usa un ordenador y su ventana de diálogo muestra
glifos corruptos ("alienígenas").

A/B medido por el mantenedor:
- `HH_FONT_TRACE=1` (que **desactiva** la inyección de acentos; ver `sections.cpp:2825-2835`) → se ve
  **bien**.
- `HH_FONT_TRACE=0` (acentos ON) → se ve **mal**.
- Tras el fix, `HH_FONT_TRACE=0` → se ve **bien**.

## 2. Causa raíz (medido)

En `build/windows/bin/Release/hh.log` (traza `HH_FONT_TRACE=1`):

```
[font] d394 color=3 code=A7B9 -> 200 (slot 100)
[font] bfe4 color=3 code=00C8 slot=100 stride=78 fileidx=107
```

- La ventana usa **color3** (12×13, `stride=78`, `fileidx=107`), no color0.
- Dibuja un glifo nativo con `value=200` **11 veces** (`[fontall]`), el mismo `value` que el port
  usaba para el acento `á`.
- `hh_accent_bfe4` interceptaba **por `value` a secas** y escribía **32 B del bloque color0 8×8**
  donde color3 espera **78 B (12×13)** → glifo corrupto.

El handoff acertaba en el rango `value` 200..248, pero el color era `[INFERIDO]` mal (es **color3**),
y el `stride` distinto agravaba la corrupción.

## 3. Fix (implementado)

`src/hooks/text_glyphs.cpp`, mecanismo de **donante ASCII + marca de origen** (acordado):

1. **Marca de origen**: `hh_accent_d394` sólo marca "pendiente" si el código EUC es uno de los
   nuestros (`B1Ax`); cualquier otro glifo nativo la invalida. `hh_accent_bfe4` sustituye el bloque
   **sólo** si color + `value` coinciden con la marca. Así el `value=200` nativo (y la kana de color0)
   pasan intactos: **no se sustituye por `value` a secas**.
2. **Donante ASCII** (no inventar `value`): `d394` devuelve el `value` real del donante `@`
   (`A1F7`), resuelto con el propio `d394` original (cacheado por color). Se descartó `~` porque la
   tabla de valores lo mapea a **0** y el motor **no llama** a `func_8001BFE4` con `value=0` (el
   acento no se serviría); `@` → valor **80** (medido en la tabla `0x80044648`).
3. **Guarda de `stride`**: sólo se sirve el bloque si el color espera 32 B (color0); en
   color3/color4 no se escribe un bloque de otro tamaño.

`tools/text/gen_accent_glyphs.py` deja de emitir `value` (el runtime usa el donante); header
`include/hh/accent_glyphs.h` regenerado (mismos códigos/bloques, sin `value`).

## 4. Límite conocido

Los acentos propios se sirven **sólo en color0** (8×8). En color4 in-game (8×12) o color3 (12×13)
`bfe4` cae al original (sin corromper, pero sin acento). Cablear el bloque color4 por `cp` desde
`include/hh/game_font_color4.h` es el follow-up natural (encaja con "cablear la fuente in-game 8×12"
de `TODO.md`).

## 5. Evidencia / ficheros

- `build/windows/bin/Release/hh.log` (líneas `[font]`/`[fontall]` de color3).
- `src/hooks/text_glyphs.cpp`, `tools/text/gen_accent_glyphs.py`, `include/hh/accent_glyphs.h`.
- Handoff previo: `notes/2026-10-02-handoff-glifos-acentos-colision-kana.md`.
- Formato de fuente: `notes/2026-09-23-b-fuente-formato-y-gaiji.md`.
- Validación: Windows, tras el fix, sin `HH_FONT_TRACE` (acentos ON).

## 6. Referencia útil

Tablas del motor (en el `.resident`): ASCII→EUC en `0x80044548`; valor por color (subrutinas
`func_8001C670/C6E8/C734/...`, tablas en `0x80044648`/`A4`/`AC`/`F8`/`74C`). La tabla de color0 en
`0x80044648` es la que mapea `@` (`A1F7`) → 80.
