# Fix: remapeo de teclado en CONTROLES no persistía (defaults, símbolos, layout)

> Sesión 2026-10-04 (cont.), rama **`main`**. Bug reportado en GitHub (**#17**, El-Rana): en
> CONTROLES, asignar teclas (p. ej. números) se aplica al momento pero **no se guarda** al cerrar.
> `[MEDIDO]` = comprobado con el binario Linux + trazas; `[INFERIDO]` = deducido del código.

## 1. Síntoma y causa raíz

Al reasignar una tecla en CONTROLES se aplica, pero al reiniciar el menú vuelve a mostrar la tecla
antigua (parecía que "no se guardaba"). Tres causas encadenadas, **todas en la persistencia**:

1. **Los defaults reinyectados ganaban.** `hh_key_assign` borra la tecla antigua de la acción (una
   tecla por acción) y `hh_key_save` escribe `[keys]` sin ella. Pero `hh_pad_config_load` metía
   **primero los defaults** (`kHHDefaultKeys`: `J=A`, `K=B`, ...) y luego aplicaba `[keys]`. Como
   `[keys]` no mencionaba la tecla borrada, el default **sobrevivía**: la acción quedaba con la tecla
   nueva **y** la vieja, y el menú (`pad_binding_key` devuelve el primer scancode) mostraba la vieja.
2. **Teclas cuyo nombre rompe el INI.** El nombre SDL de varias teclas contiene `=`/`[`/`]`/`#`/`;`
   o espacio (`=`, `[`, `]`, `#`, `;`, `Keypad =`...). El parser de `config.ini` trata `#`/`;` como
   comentario y `=` como separador, así que esas líneas se **escribían pero no se podían leer**.
3. **Glifos.** La fuente del menú no tiene `[ ] \ ' \` { } ^ |`; mostrar esas teclas no es posible.

## 2. Fix `[MEDIDO]` (`src/subsystems/input.cpp`)

1. **`[keys]` es FUENTE AUTORITATIVA del teclado.** Si el `config.ini` trae la sección `[keys]`, se
   **vacía `hh_key_map`** (se descartan los defaults) antes de aplicarla. Así los defaults no
   sobreviven a una tecla borrada. Si no hay `[keys]`, se usan los defaults.
2. **Nombres seguros para el INI** (`hh_key_name_safe`): si el nombre SDL contiene `=`, `[`, `]`,
   `#`, `;`, espacio o tab, se guarda como `sc_<n>` (índice de scancode). `hh_scancode_by_name`
   resuelve `sc_<n>` al cargar. Cubre `;`, `=` y `#` (dibujables, pero conflictivas en el INI).
3. **Solo se mapean teclas dibujables** (`hh_key_drawable` + `hh_text_drawable`): al reasignar
   (acción y ejes), se **rechazan** las teclas cuyo rótulo no tenga glifo. `hh_text_drawable` valida
   codepoint a codepoint: ASCII con `glyph_value`, y acentos/`¡¿·ÆŒ` con `menu_char`.
4. **Rótulo según la LAYOUT del SO** (`hh_scancode_layout_name`): se **muestra** en CONTROLES el
   carácter que el usuario ve al pulsar (`SDL_GetKeyFromScancode`/`SDL_GetKeyName`); en un teclado ES
   la tecla física `=` se muestra como **`¡`**. Si ese rótulo no es dibujable, se cae al nombre físico
   (posicional US). **La persistencia sigue siendo por scancode** (estable entre layouts); el rótulo
   del layout es solo presentación.

## 3. Qué se puede mapear (análisis)

Con `glyph_value` + `menu_char`, son mapeables: **A–Z, 0–9, espacio** y `! # $ % & ( ) * + , - . / : ; < = > ? @`
más acentos/vocales acentuadas, `¡ ¿ · Æ Œ`. **No mapeables** (sin glifo): `[`, `]`, `\`, `'`, `` ` ``
y sus variantes de keypad (`{`, `}`, `^`, `|`).

## 4. Verificación

- **Linux `[MEDIDO]`** (binario + `config.ini` de prueba): con `[keys]` = `1=A, 2=B` ya **no**
  reaparecen `J`/`K`; `;`/`=`/`#` se guardan como `sc_51`/`sc_46`/`sc_50` y **se releen**; las teclas
  sin glifo se rechazan en la captura.
- **Windows**: pendiente validación del mantenedor (números + teclas del layout ES).

## 5. Ficheros

- `src/subsystems/input.cpp`: `hh_key_name_safe`, `hh_scancode_phys_name`/`hh_scancode_layout_name`/
  `hh_text_drawable`/`hh_scancode_display`/`hh_key_drawable`, `hh_scancode_by_name` (`sc_<n>`),
  `hh_pad_config_load` (`[keys]` autoritativo), `hh_key_save` (nombre seguro), `pad_capture_poll`
  (filtro de dibujables en acción y ejes), include `hh/font.h`.

## 6. Referencias

- Issue: hunkstalker/hybrid-heaven-recomp **#17** (comentario de El-Rana sobre números/teclas).
- `docs/menu.md` (CONTROLES). `notes/2026-09-26-j-controles-remapeo-y-vibracion.md` (remapeo previo).
