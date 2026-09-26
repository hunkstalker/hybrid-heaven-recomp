# CONTROLES: remapeo mando/teclado, ejes, D-PAD y VIBRACIÓN

> Tarea 2026-09-26, rama `menu-nativo`. Pantalla del port **`CONFIGURACIÓN → CONTROLES`**.
> Los ejes de movimiento, el D-PAD y la vibración viven en esta misma pantalla.

## Resumen del encargo (mantenedor)

- Submenú **CONTROLES** con una tabla: **acciones a la izquierda**, a la derecha lo asignado
  (MANDO y TECLADO).
- Poder **reasignar cualquier acción** a **cualquier botón del mando (incluido el D-PAD)** y/o una
  **tecla**; **1 botón y 1 tecla por acción**.
- **Movimiento** (las 4 filas de arriba): cada dirección se mapea a una **dirección de stick**
  (izquierdo o derecho) y/o una tecla.
- **D-PAD** como botones pulsados (4 filas `MENÚ ...`), que en este juego hacen de movimiento.
- Toggle **VIBRACIÓN** (el antiguo Rumble Pak; nombre moderno estándar).
- Botón **RESET** (abajo del todo) para volver a los defaults.
- El menú del port debe **centrarse** (los menús nativos conservan su margen original) y las listas
  largas deben **scrollear** con indicadores ↑/↓.

## Pantalla CONTROLES (`ScreenId::Controls`)

- Entrada en `CONFIGURACIÓN` (entre `SONIDO` y `DEBUG`), traducida EN/ES/CA/FR/DE
  (`kMenuTr` en `src/subsystems/menu.cpp`).
- Orden de filas (arriba→abajo):
  1. **Movimiento**: `ARRIBA/ADELANTE`, `ABAJO/ATRÁS`, `IZQUIERDA`, `DERECHA`.
  2. **Acciones**: `ACCIÓN/ACEPTAR`, `MAPA/ATRÁS`, `AGACHARSE`, `PRIMERA PERSONA`, `MENÚ`,
     `APUNTAR`, `ALTURA CÁMARA`.
  3. **D-PAD** como botones: `MENÚ ARRIBA/ABAJO/IZQUIERDA/DERECHA`.
  4. **`VIBRACIÓN`** (selector) y **`RESET`** (item).
- `Kind::Binding` (nuevo): fila etiqueta + 2 columnas (`Entry.remap_key` identifica la acción).
- **Layout** (`src/hooks/menu_overlay.cpp`): los menús del port (`EXTRAS`, `CONTROLES`) se
  **centran** según el ancho real de su contenido; los nativos conservan `layout.x`. CONTROLES usa
  **2 columnas de valores** (MANDO / TECLADO) separadas (`kKeyColGap`).
- **Separador "/"**: la fuente del menú no tiene glifo de barra; se parte la etiqueta y se dibuja con
  `append_slash` (`append_text_with_slashes`).
- **Scroll vertical**: ventana de **5 filas** en las pantallas del port; **flechas ↑/↓** alineadas al
  inicio del texto, que aparecen si hay filas por encima/por debajo y desaparecen en los topes.

## Remapeo (captura) — `src/subsystems/input.cpp` + `src/hooks/sections.cpp`

- `A` sobre una fila → `hh::pad_begin_capture(remap_key)`; la fila muestra `PULSA...` (amarillo); el
  siguiente **flanco** de tecla/botón se asigna; **ESC cancela**.
- `pad_capture_poll` detecta: **teclado** (scancode) y **mando** (cualquier botón, incl. D-PAD).
- Al asignar/cancelar se **bloquea la navegación 0.25 s** (solo **A/B**; las flechas siguen) para que
  el input usado no ejecute su acción. Bug previo: asignar la tecla de "atrás" **volvía un menú**.
- **1 botón + 1 tecla por acción**: al asignar se libera el binding anterior
  (`hh_pad_clear_action` para mando, `hh_key_assign` para teclado).
- Persistencia: mando en `[game]/[menu]` (`hh_pad_save`); teclado y ejes en `[keys]` (`hh_key_save`).
- `hh_key_save` **borra la sección `[keys]`** antes de reescribirla (`config_ini_clear_section`,
  nuevo en `src/platform/config_ini.cpp`): los bindings viejos sobrevivían y ganaban al recargar
  (síntoma: `MENÚ ...` volvía a un mapeo antiguo tras RESET).
- `RESET` (`pad_reset_defaults`) restaura **mando + teclado + ejes**.

## Ejes de movimiento

- Cada eje tiene **fuente de mando** (`hh_axis_gp`): dirección de stick **izq/der**, mostrada como
  `EJE Y+` / `EJE Y-` / `EJE X-` / `EJE X+` (izq) o `EJE RY±` / `EJE RX±` (der); y **tecla**
  (`hh_axis_key`).
- `get_input` compone el vector del stick según las fuentes asignadas (por defecto, stick izquierdo
  **analógico**: `ly = -LEFTY`, etc.), con clamp a [-1,1].
- Captura: detecta dirección de stick (umbral 0.6) o tecla.
- Config en `[keys]`: `axis_up = W`, `axis_up_gp = EJE Y+`, etc.

## Defaults (ES)

| Fila | Mando | Teclado |
|---|---|---|
| ARRIBA/ADELANTE | EJE Y+ | W |
| ABAJO/ATRÁS | EJE Y- | S |
| IZQUIERDA | EJE X- | A |
| DERECHA | EJE X+ | D |
| ACCIÓN/ACEPTAR | A | J |
| MAPA/ATRÁS | B | K |
| AGACHARSE | X | H |
| PRIMERA PERSONA | Y | L |
| MENÚ | START | ENTER |
| APUNTAR | RB | I |
| ALTURA CÁMARA | C-ARRIBA | R |
| MENÚ ARRIBA/ABAJO/IZQ/DER | D-PAD | flechas |

## VIBRACIÓN

- Toggle en CONTROLES (encima de RESET). Persiste en `config.ini [input].vibration` (def. `NO`).
- Con `SÍ`: `get_connected_device_info` reporta `Pak::RumblePak` y `set_rumble` usa
  `SDL_GameControllerRumble` (on 5 s; el juego lo para con `osMotorStop`).
- **OJO**: el runtime no consulta `connected_pak` en `osPfsInitPak` (pak virtual siempre), pero el
  juego **podría** saltarse el PFS al ver Rumble Pak → **pendiente validar que sigue guardando**.

## Pendiente

- **Validar en Windows**: remapeo (incl. tecla de "atrás" y stick), movimiento, D-PAD, `VIBRACIÓN`
  (¿vibra y **guarda**?), `RESET`, centrado y scroll.
- **Cámara libre**: cuando exista, activa → stick derecho = cámara y se **desactivan los mapeados de
  los botones C** (ver `RETOMAR.md` §Aparcado).
