# Logos de intro HD + código Konami → `EXTRAS` (implementación)

> Tarea 2026-09-26, rama `menu-nativo`. Continuación de
> `notes/2026-09-26-h-logos-intro-hd-y-konami.md` (reconocimiento y plan).
> **Estado: implementado y validado en HEADLESS; PENDIENTE VALIDAR EN WINDOWS** (fades, skip, flash,
> `EXTRAS` y el parpadeo de arranque). **No se ha commiteado nada** (a la espera del mantenedor).
> Las utilidades de captura/volcado usadas son **externas al repo** (`/tmp`); aquí va el conocimiento.
>
> **CORRIGE el diagnóstico previo (nota h/i vieja)**: los logos de arranque los pinta el **módulo de
> arranque file 055**, no el módulo de título. Ver §Causa raíz.

## Causa raíz (FILE 055)

Los logos que se ven **al arrancar** los dibuja el **módulo de arranque file 055** (base `0x803837E0`),
en concreto su estado `func_80383AD4`. Los handlers del **módulo de título** `0x801C1624/1764/17C8`
son el **replay del modo attract** (t≈30 s), no la intro. Por eso la implementación inicial (hooks del
módulo de título) hacía que la intro HD saliera **tarde** (dentro del menú).

Evidencia (medida, no inferida):
- `HH_TRACE_RANGE=0x803837E0:0xA5E0` → `func_80383AD4` corre cada frame durante los logos nativos.
- `HH_CANARY=0x8038Dxxx` → banderas/alfas del propio módulo (ver §Alfas nativas).
- Capturas con `HH_OVERLAY=0` (nativo) vs overlay: el nativo pinta KONAMI/KCEO antes de que el overlay
  empiece a dibujar (primer *present* de RT64).

Índices del file 055 (direcciones absolutas; `0x80390000 - off`):
| dirección | off | papel |
|---|---|---|
| `0x8038DBD8` | 0x2428 | flag capa **KONAMI** (1 mientras se ve) |
| `0x8038DBD0` | 0x2430 | flag capa **KCEO** |
| `0x8038DBC0` | 0x2440 | **alfa KONAMI** (sube al entrar, baja al salir) |
| `0x8038DBD4` | 0x242C | **alfa KCEO** (sube al entrar, **baja al final**) |
| `0x8038DBB8` | 0x2448 | state KONAMI (0=fade-in,1=hold,2=fade-out,3=fin) |
| `0x8038DBB4` | 0x244C | contador del hold |
| `0x8038DBCC` | 0x2434 | state KCEO (1=fade-in,2=hold,3=fade-out,4=fin) |

## Assets

`assets/logos/` (PNG 4:3 3840×2880, dibujados a mano por el mantenedor en Affinity; CMake los copia a
`<exe>/logos/`):
- **Clásicos (fondo BLANCO)**: `konami-1998.png`, `kceo-1995.png` — por defecto.
- **Modernos (fondo NEGRO)**: `konami-2023.png`, `kceo-2000.png` — al desbloquear `EXTRAS`.

## Composición del overlay (fundido por grupo + clave de blanco)

Antes se pintaba `negro base + capa blanca (alfa) + logo (alfa)`, y al bajar las dos capas a la vez el
negro se colaba por las partes opacas → el logo se **lavaba** (fallo clásico de fundir cada capa en vez
del composite). Ahora se composita **una sola vez** y se funde el grupo:

1. **Negro base** (tapa el nativo).
2. **Tarjeta OPACA** a pantalla completa: **blanca** (clásicos) o **negra** (modernos, fondo negro).
3. **Logo** encima (contain), con `mode 2` = **clave de blanco** (el `#FFFFFF` del PNG se vuelve
   transparente y lo aporta la tarjeta). `iColor.a` = alfa de crossfade KONAMI↔KCEO.
4. **Velo negro** (`alfa = 1 - fade`) que funde el grupo entero → fade-in/out a negro. El logo NO se
   baja en el fundido de grupo (si no, se lavaba).
5. **Flash blanco** opcional (unlock): `flash_white(ms)` arranca al máximo y se desvanece.
6. **Telón negro** opcional (`set_screen_blackout`) para tapar los logos NATIVOS del boot; se retira al
   arrancar la intro (va encima de todo, así que **no debe quedar activo durante la intro**).

`set_screen_image_alpha(logo, fade)` (0..255). La **tarjeta** se elige con `set_screen_image(path,
black_bg)` y `g_card_black` se aplica **al cargar la textura** (no al pedirla), para no ver el logo
viejo sobre la tarjeta nueva mientras carga.

## Alineado con los alfas NATIVOS

El hook del file 055 (`hh_boot_logo_hook` en `src/hooks/sections.cpp`) **copia** los alfas nativos en
vez de inventar tiempos:
- `fade` (grupo): sube con el alfa KONAMI (`0x8038DBC0`) al inicio, `255` durante los logos, y **baja
  con el alfa KCEO** (`0x8038DBD4`) al final.
- `logo` (crossfade): `255` en fade-in/hold/fade-out; solo varía en el pase KONAMI→KCEO (baja `C0` →
  cambio de PNG → sube `D4`). Bandera `g_boot_konami_hold` cuando `C0` llega a 255.
- **Fade-out final**: se dispara cuando el alfa KCEO **empieza a bajar** (punto determinista), con un
  **fade fijo del render** (`kBootFinalFadeMs = 350`) que ya no depende de cuándo carga el módulo de
  título. El hilo del juego deja de tocar alfas a partir de ahí (evita carreras y variación entre
  sesiones).

## Código Konami (+ pausa, modernos, flash)

`hh_boot_logo_hook` lee input nativo y alimenta `konami_tick` (`↑↑↓↓←→←→BA` por flancos; SFX
correct/error/unlock; timeout 2 s; reintentos infinitos).
- **Pausa**: al primer `↑` se **congela** el state machine del file 055 (`0x8038DBB8=1`,
  `0x8038DBB4=0`, `0x8038DBC0=0xFF`, `0x8038DBD4=0`), aplicado **después** del original para que el
  próximo frame parta del hold lleno. Al acabar/timeout se suelta.
- **Al completar**: `unlock_extras()` + **cambio a los logos modernos** + `flash_white(400)`.
- **Preload**: `preload_screen_image(logo_path(konami_logo()), logo_is_modern(...))` al arrancar
  (`register_runtime_functions`), para no perder el primer fade-in decodificando el PNG.

## `EXTRAS`

- `ScreenId::Extras` + `Action::OpenExtras` en `include/hh/menu.h`.
- Entrada en la **raíz, encima de `SALIR`**, solo si está desbloqueado (`build_tree` filtra por
  `extras_unlocked()`); `unlock_extras()` rehace el árbol (`reset()`) para que aparezca al vuelo.
- **Desbloqueo SOLO DE SESIÓN** (no persiste): `extras_unlocked()` devuelve un flag de memoria; en el
  próximo arranque hay que teclear el código otra vez. (Lo de DENTRO, si hubiera ajustes, se
  persistirá aparte.)
- Pantalla `Extras` con placeholders **deshabilitados** `NIVEL` / `HABILIDADES` — **contenido por
  definir con el mantenedor**.

## Skip con START

- KONAMI: lo gestiona el nativo (1 pulsación avanza a KCEO).
- KCEO: el nativo **ignora** `START` durante su fade-in (solo actúa en su estado *hold* 2), así que el
  hook fuerza `0x8038DBCC = 3` en la pulsación → **1 Enter = 1 skip** también en KCEO.

## Arranque de ventana

`src/platform/support.cpp`: en fullscreen (`wm != "windowed"`) la ventana se crea ya **borderless** y a
tamaño de monitor, **visible**; RT64 confirma el modo en su constructor (`setFullScreen` guarda el rect
y re-aplica `WS_POPUP` al mismo rect) → sin transición con barra ni resize de swapchain.
- Se probó `SDL_WINDOW_HIDDEN` + mostrar tras el setup (para no ver ni el frame en ventana), pero
  **robaba el foco** (F11 caía en la terminal y no había icono en la taskbar) → **descartado**.

## Diagnóstico / instrumentación

- `HH_MENU_TRACE=1`: `[intro] boot logo konami=… kceo=… ak=… ae=… la=… fade=… pause=… out=…`,
  `[konami] inicio/acierto/COMPLETADO`, `[overlay] imagen cargada`, `[menu] goto pantalla=…`.
- `HH_TRACE_RANGE=0x803837E0:0xA5E0`, `HH_CANARY=0x8038Dxxx` para el file 055.
- Autoplay temporal de test (`HH_BOOT_KONAMI_AUTOPLAY`): usado y **retirado** (no está en el árbol).
- Replay para llegar al menú: `HH_REPLAY` + `HH_REPLAY_MODE=vi` (START=`0x1000`).

## Pendiente

1. **Windows**: validar fades (inicio / KONAMI→KCEO / final), **skip con Enter** (1 por logo), flash +
   modernos al desbloquear, `EXTRAS` en la raíz, y que **no parpadea** al inicio.
2. **Parpadeo de arranque**: el nativo del **file 8** se pinta antes del primer *present* del overlay
   (~1.5 s en headless); el **telón negro** lo tapa desde que el overlay dibuja. Si aún se ve un
   instante, el siguiente paso es **enganchar el logo del file 8** (ocultarlo), no solo taparlo.
3. `EXTRAS`: definir el **contenido real** (nivel/habilidades) y cablearlo.
4. **BUG de paridad headless** (carrera `ptick`/`bootstate`): fix de fondo (hoy `HH_FORCE_INTRO`).

## Referencias

- `notes/2026-09-26-h-logos-intro-hd-y-konami.md` (reconocimiento y plan A–F).
- `docs/menu.md` §Acciones nativas; `RETOMAR.md` §SIGUIENTE TAREA.
