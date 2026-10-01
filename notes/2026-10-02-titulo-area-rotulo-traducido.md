# Rótulo `AREA` del título del Área — traducido (2026-10-02)

> Sesión 2026-10-02. Rama **`menu-carga-guardado-partida`**. **HECHO y VALIDADO en Windows**.
> Objetivo: que el rótulo del título del Área al cargar partida salga en el idioma activo (en ES
> `ÁREA`, con tilde), no en inglés fijo.

## 1. Síntoma (mantenedor)

Al cargar partida, el título del Área mostraba el rótulo `AREA` **en inglés** siempre; en español
debía ser `ÁREA` (con tilde). El nombre del Área sí se traducía (Work Sans).

## 2. Causa `[MEDIDO]`

En `src/hooks/menu_overlay.cpp` (`publish_area_title`) el rótulo estaba **hardcodeado**:

```cpp
std::snprintf(buf, sizeof buf, "AREA %d", area_num);
```

La clave `AREA` **ya existía** en `assets/lang/*.txt` (`es=ÁREA`, `ca=ÀREA`, `fr=ZONE`,
`de=BEREICH`); solo faltaba usarla. `en` = identidad (sin fichero).

## 3. Solución

`src/hooks/menu_overlay.cpp`: el rótulo pasa a `hh::menu::localized("AREA") + " " + N` y se dibuja con
la fuente del juego (`color0`), que acentúa con las **marcas del menú** (`kMenuChars`/`kMenuMarks`):
`Á` U+00C1 (marca agudo) y `À` U+00C0 (marca grave) ya están cubiertos — el mismo camino validado en
las filas del slot (`ÁREA/ÀREA/ZONE/BEREICH`). El ancho para centrar se mide en **codepoints** con
`cp_count` (no `strlen`: `Á/À` son 2 bytes en UTF-8). Posición/`y` sin cambios (`AREA N` y `ÁREA N`
ocupan 6 codepoints; el nombre se centra por su cuenta).

## 4. Idiomas

| idioma | rótulo | tilde |
|---|---|---|
| en | `AREA` | — |
| es | `ÁREA` | sí (U+00C1, agudo) |
| ca | `ÀREA` | sí (U+00C0, grave) |
| fr | `ZONE` | — |
| de | `BEREICH` | — |
| ja | nativo (`エリア`) | — |

## 5. Estado / validación

- **Validado en Windows (2026-10-02, mantenedor)**: "queda validado". ES `ÁREA` y CA `ÀREA` con tilde.
- **Build Linux**: OK.
- **Fichero**: `src/hooks/menu_overlay.cpp`.

## Referencias

- Título del Área (overlay, gráfico nativo): `notes/2026-10-01-titulo-area-carga.md`.
- i18n (clave = inglés): `notes/2026-10-01-i18n-unificar-traducciones-plan.md`, ADR 0014.
- Marcas de acento del menú (color0): `include/hh/menu_marks.h`, `tools/text/menu_marks.py`.
- Acentos/`¿`/`¡` en color4 (misma tanda): `notes/2026-10-02-tildes-y-signos-en-mensajes.md`.
