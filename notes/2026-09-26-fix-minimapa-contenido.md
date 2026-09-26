# Issue #7 — Minimapa desanclado al inicio del nivel 2-1 (RESUELTO)

> 2026-09-26. Bug reportado por El-Rana. Síntoma: al inicio del **nivel 2-1** (tras eliminar al
> primer jefe, Procyon), la **salud** salía desanclada y el **minimapa fuera del marco**. La salud
> ya se había arreglado con el issue #3 (`notes/2026-09-25-f-hud-combate-contenido.md`); quedaba el
> **minimapa**.

## Causa

El anclaje del minimapa (`right`) en `class_of` usaba identidades **dirección + hash**:
`dl:0x030002e0#bbb8c0ba` y `dl:0x03000f10#1427da33`. El **overlay del mapa se carga por
escena/capítulo**; en el nivel 2-1 la **dirección cambia** y la identidad ya no casaba → el mesh
verde (bajo proyección ortográfica; el Inspector lo sitúa en *Framebuffer #1 / Orthographic #5 /
Call #0*) no recibía el `viewport_align(RIGHT)` del grupo `right` → se dibujaba **fuera del panel**.

Igual que el issue #3: **la dirección RDRAM no es identidad**.

## Fix

En `src/hooks/hud_rewrite.cpp` (`class_of`), los `dl:` del minimapa se emparejan por **hash de
contenido** de la lista (primeros 16 comandos, `hudid::list`), que es **estable** entre escenas
(las direcciones dentro de la lista son relativas al overlay, no KSEG0):

```cpp
if (strncmp(identity, "dl:", 3) == 0) {
    uint32_t dh;
    if (parse_hash(identity, dh) && (dh == 0xbbb8c0bau || dh == 0x1427da33u)) return kRight;
}
```

**Validado en Windows**: el mapa vuelve a quedar **dentro** del panel (abajo-derecha) y recortado.

## Notas

- El **fondo negro** del panel (`fill:0x00000000@197,143,277,223`) ya casaba: es identidad
  **posicional** (no depende de la dirección).
- Diagnóstico: **F7** captura pareada + **Inspector de RT64** (`HH_DEVELOPER=1`, F1).
- Relacionado: `notes/2026-09-22-fix-mapa-rect-negro-widescreen.md`
  (`notes/2026-09-22-anclaje-hud-widescreen-fase07b.md`) y el issue #3.
