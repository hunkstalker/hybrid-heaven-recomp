# A2 — Dibujo de selectores y ajuste del árbol de NUEVA PARTIDA

> Sesión 2026-09-24 (continuación del paso 5). Tras la validación en Windows del mantenedor: los
> selectores no dibujaban su valor y la etiqueta `AJUSTES EXPERIENCIA MODERNA` era demasiado larga.
> Diseño: `docs/menu.md`.

## 1. Dibujo de selectores

`title_update` (`src/hooks/menu_overlay.cpp`) no dibujaba el valor de los `Kind::Selector` (era el
pendiente "valores de selectores" del paso 2). Ahora:

- El valor va en una **columna fija** (`kSelectorValueCol = 17`, en caracteres) para que queden
  alineados; la etiqueta más larga ("APUNTADO LIBRE", con su espacio inicial) ocupa 15.
- **Todos los valores visibles** (`NO / SÍ`), el **activo en verde** y el resto en blanco.
- Si el conjunto no cabe en pantalla (p. ej. **LÍMITE DE FPS**), se muestra **solo el activo**, en
  verde.
- El separador **`/` no existe en la fuente del menú** (color0: solo dígitos 0-9, letras y espacio;
  verificado volcando el atlas). Se dibuja con rectángulos de 1 px (`append_slash`), como la flecha
  nativa del cursor.

## 2. Árbol de NUEVA PARTIDA

Se retira el submenú `AJUSTES EXPERIENCIA MODERNA` (su etiqueta se solapaba con los valores) y los
selectores pasan a NUEVA PARTIDA, debajo de DIFICULTAD:

```
EMPEZAR PARTIDA
DIFICULTAD ->
CÁMARA LIBRE   NO / SÍ
APUNTADO LIBRE NO / SÍ
```

Los `ScreenId` se renumeran (desaparece `Experience`): **`HH_MENU_SCREEN=6` = GRÁFICOS, `=5` =
IDIOMA** (antes 7/6). `docs/menu.md` y `RETOMAR.md` actualizados.

## 3. Validación

- **Headless** (replay poll): el modelo cambia los valores con izq/der (`CÁMARA LIBRE < NO >` →
  `< SÍ >`, `APUNTADO LIBRE < SÍ >` → `< NO >`); A entra, B vuelve. Log `[menu-nav]` con
  `describe_current`.
- **Visual**: captura forzando `HH_MENU_SCREEN=1` (NUEVA PARTIDA):
  ```
  > EMPEZAR PARTIDA
    DIFICULTAD
    CÁMARA LIBRE     NO / SI
    APUNTADO LIBRE   NO / SI
  ```
  (`NO` en verde, `/` dibujado). Nota: "CÁMARA"/"SÍ" salen sin tilde (paso 4 pendiente).

## 4. Revisión del mantenedor (misma sesión) — diseño final

Tras ver las capturas, el mantenedor ajusta el diseño. Esto **supersede** los detalles de §1–§2:

1. **Colores** (aclarado por el mantenedor): la regla gris/verde es **solo para las opciones a
   configurar**, no para el menú. Las **etiquetas** del menú van en **blanco** (amarillo la del cursor
   + flecha nativa). En las **listas**, la opción **aplicada** en verde y el resto en gris. En los
   **selectores**, el **valor activo** en verde y el resto en gris. (En un primer intento se puso el
   menú entero en gris; incorrecto.) El cursor de una lista no cambia el color de la opción: lo marca
   la flecha nativa.
2. **Separador de los selectores de pocos valores**: `NO / SÍ` con **2 px** a cada lado de la barra
   (se probó sin espacios y con 4 px; el mantenedor fijó 2).
3. **Sin "aplicar" con X**: se elimina X del modelo (`Event::Applied`/`Screen::applies`/`apply()`); el
   patrón es **A** (entra/marca) y **B** (atrás). Los cambios son en vivo.
4. **Selectores largos** (RESOLUCIÓN, LÍMITE DE FPS): se muestra solo el activo entre **flechas `<` `>`**
   dibujadas con rectángulos (`append_chevron`, 2 px de ancho) y **4 px de separación** con el valor.
   La barra `/` también se dibuja, con **2 px a cada lado** en los selectores de pocos valores
   (`NO / SÍ`). **Todos los valores se alinean en la misma columna** (`kSelectorValueCol`); los
   chevrons quedan a la izquierda/derecha, fuera de la alineación.
5. **Dígitos**: `glyph_value` no mapeaba `0-9` → "ANTIALIASING x0" salía como "x" y las resoluciones
   salían vacías. Se mapean `'0'..'9'` a valores 1-10 del atlas.
6. **RESOLUCIÓN** pasa de submenú-lista a **selector largo** dentro de GRÁFICOS. **Por defecto `AUTO`**
   (value 0) = la nativa del SO (`[video] res = auto`); lista `AUTO`, `ORIGINAL` y resoluciones reales.
   La columna de alineación bajó a **16** para que la resolución más larga (`3840x2160`) quepa con su
   chevron. Desaparece la pantalla `Resolution`.
7. **DEBUG** pasa a **submenú** de AJUSTES con **`VENTANA DEBUG`** (`NO/SÍ`, `Action::ToggleDebug`; al
   cambiar el valor llama a `hh::set_developer_mode()` → Inspector de RT64 con **F1**; validado
   `developerMode=1`) y **`MOSTRAR FPS`** (`NO/SÍ`). Así `GRÁFICOS` no se alarga.
8. **DEFAULTS**: DIFICULTAD marca NORMAL, IDIOMA marca INGLÉS, SONIDO marca ESTÉREO; **VSYNC = SÍ**;
   **LÍMITE DE FPS = `NATIVO`** (refresco del monitor; el valor real lo aplicará el paso 6).
9. **RATIO + RESOLUCIÓN**: `RATIO` (`AUTO/ORIGINAL/4:3/16:9/16:10/21:9`) encima de `RESOLUCIÓN`, que
   **filtra** su lista por ratio. Reglas: `RATIO=ORIGINAL → RESOLUCIÓN=ORIGINAL`;
   `RATIO=AUTO → RESOLUCIÓN=AUTO`; un **ratio concreto → la resolución mínima** de su lista.
   `sync_resolution()` (modelo) lo resuelve en `move_left/right`.
10. **`:` y `.` dibujados**: la fuente del menú no los tiene. Los dibuja el propio overlay
    (`src/platform/overlay.cpp`, rango de paneles) con rectángulos del color del texto, con el avance
    monospace de 8 px; así `4:3`/`16:9` y `P. COMPLETA` se ven enteros.
11. **P. COMPLETA** (pantalla completa, `NO/SÍ`) en GRÁFICOS. Se abrevia con `.` (dibujado) porque
    "PANTALLA COMPLETA" no cabe en la columna de alineación.

**Validado headless** (capturas en `work/gameplay screenshots/menu/2026-09-24_menu_*.png`): NUEVA
PARTIDA (selectores), GRÁFICOS (flechas + dígitos), AJUSTES→DEBUG (SÍ verde tras izq/der, `developerMode=1`),
IDIOMA/DIFICULTAD (aplicada verde, resto gris).

## Pendiente

- **Validar en Windows** (paso 5 + dibujo + DEBUG).
- Paso 6 (acciones): `VENTANA DEBUG` ya enganchado; el resto (CÁMARA LIBRE, APUNTADO LIBRE, RATIO,
  RESOLUCIÓN, P. COMPLETA, ANTIALIASING, VSYNC, LÍMITE DE FPS, MOSTRAR FPS) cambia en memoria pero
  **no** se aplica a RT64 ni se persiste.
- Los valores cambian en memoria; **no se persiste** en `config.ini` todavía.
