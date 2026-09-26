# CONTINUAR (dispatch nativo) y fallos visuales detectados en Windows

> Sesión 2026-09-26 (d), rama `menu-nativo`. Cierra la tarea **`CONTINUAR`** (backlog del menú) y
> recoge los **fallos visuales** que el mantenedor detectó al validarla. Estado/pendientes: `TODO.md`.

## 1. `CONTINUAR` — reenviar al dispatch nativo

**Objetivo**: que `CONTINUAR` (raíz del overlay) retome la partida guardada, reutilizando la lógica
real del juego en vez de reimplementarla.

**Análisis del menú nativo** (`func_801C1DB8`, módulo 23, jump table `0x801CF264`):
- El índice de selección está en **`0x801CC8C4`** y va **0..4** (con wrap), con el orden nativo
  `0=NEW GAME / 1=CONTINUE / 2=BATTLE MODE / 3=SOUND / 4=RESOLUTION`.
- Anclas que lo confirman: `case 3` → `0x801C4960` (submenú de SONIDO) y `case 4` → `0x801C5108`
  (submenú de RESOLUCIÓN); `case 0` (NEW GAME) registra 7 textos en `0x801CED10` = submenú de NUEVA
  PARTIDA. Por tanto **`case 1 = CONTINUE` → `func_801C3CDC`**, que desmonta el menú y transiciona
  (carga la partida).

**Implementación** (`src/hooks/sections.cpp`):
- Al confirmar `Action::Continue` con el overlay activo, `feed_menu_navigation` escribe `sel = 1` en
  `0x801CC8C4` y marca `g_inject_native_a`.
- `hh_native_ab_input` (override de `0x801C1334`, el lector de A/B/START del handler nativo) devuelve
  **A (`0x8000`)** cuando `g_inject_native_a` está activo; las direcciones siguen muteadas.
- `hh_title_menu_hook` ejecuta el handler original con esa A inyectada → corre su rama **CONTINUE**
  real. La inyección es de **un solo frame** (`g_inject_native_a=false` tras la llamada).
- Con `HH_OVERLAY=0` no cambia nada (manda el menú nativo).

**Validado en Windows**: `CONTINUAR` carga la última partida guardada.

## 2. Fallos visuales detectados (backlog)

Con el menú funcionando, el mantenedor irá dejando capturas en
**`work/gameplay screenshots/CONTINUAR/`** (`work/` está **gitignored**: si hay que conservarlas,
copiar al repo).

1. **`DATA LOAD` (slots de partida)**: al mover el cuadro de selección entre slots, el **borde verde**
   del cuadro aparece pegado al **borde superior de la pantalla** (línea verde a `y≈0`), descolgado de
   su posición real. Captura `Captura de pantalla 2026-09-26 033740.png`. Este menú es **nativo** (no
   es el overlay del port) → apunta a widescreen (`snap_overscan`)/rect 2D. Acotar con **F7** (captura
   pareada) y `HH_FULL_FRAME=0`.
2. **Combate (golpes)**: las cajas de los ataques (verdes/rojas) se dibujan con un **recuadro negro
   (solo el borde)**; en el original **no** llevan ese borde.

## Archivos

`src/hooks/sections.cpp` (CONTINUAR) · `TODO.md`, `RETOMAR.md` (backlog y estado).