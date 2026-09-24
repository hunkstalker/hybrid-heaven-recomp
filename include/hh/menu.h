#pragma once

// hh_menu — modelo del menú inicial del port (A2, paso 1: SOLO ESTADO).
//
// Describe el árbol de pantallas acordado en RETOMAR.md §Menú (CONTINUAR / NUEVA PARTIDA /
// MODO COMBATE / AJUSTES y sus subpantallas) y la navegación. NO dibuja, NO lee input y NO
// persiste nada: de eso se encargan las capas posteriores (dibujo con hh_font -> backend_game,
// enganche de input del paso 5 y ejecución de acciones del paso 6).
//
// Reglas del diseño (RETOMAR.md):
//   - Arriba/abajo mueve el cursor; en los selectores laterales, izquierda/derecha cambian el valor.
//   - A  = marca/selecciona la opción resaltada (entra si es submenú).
//   - B  = atrás. (No hay "aplicar": los cambios son en memoria y se ven al momento.)
//   - Listas (IDIOMA / DIFICULTAD / SONIDO): la opción **aplicada** se resalta en verde y el resto
//     sale en gris (deshabilitado); el cursor lo marca la flecha nativa.
//   - Sin entradas "ACEPTAR".
//
// Las acciones (`Action`) son solo descriptivas: la ejecución real (llamar a funciones del juego)
// se enganchará en el paso 6.

#include <string>
#include <vector>

namespace hh::menu {

// Identidad de cada pantalla del árbol.
enum class ScreenId {
    Root,          // título (CONTINUAR / NUEVA PARTIDA / MODO COMBATE / AJUSTES)
    NewGame,       // NUEVA PARTIDA (EMPEZAR PARTIDA / DIFICULTAD / selectores)
    Difficulty,    // DIFICULTAD (lista)
    BattleMode,    // MODO COMBATE (por definir; de momento deshabilitado)
    Settings,      // AJUSTES
    Language,      // IDIOMA (lista)
    Graphics,      // GRÁFICOS (RATIO / RESOLUCIÓN / P. COMPLETA / ANTIALIASING / VSYNC / FPS)
    Sound,         // SONIDO (lista)
    Debug,         // DEBUG (VENTANA DEBUG + MOSTRAR FPS)
};

// Acción de una entrada. El modelo solo la describe.
enum class Action {
    None,
    Continue,        // CONTINUAR: retomar partida
    StartGame,       // EMPEZAR PARTIDA
    BattleMode,      // MODO COMBATE (deshabilitado)
    OpenNewGame,     // submenú NUEVA PARTIDA
    OpenDifficulty,  // submenú DIFICULTAD
    OpenSettings,    // submenú AJUSTES
    OpenLanguage,    // submenú IDIOMA
    OpenGraphics,    // submenú GRÁFICOS
    OpenSound,       // submenú SONIDO
    OpenDebug,       // submenú DEBUG (VENTANA DEBUG + MOSTRAR FPS)
    ToggleDebug,     // VENTANA DEBUG: habilita el modo desarrollador de RT64 (Inspector con F1)
    ToggleFullscreen,// P. COMPLETA: NO = ventana (windowed); SÍ = borderless completa
    ToggleVsync,     // VSYNC: NO/ SÍ; aplica la sincronía de presentación de RT64
    FpsLimit,        // LÍMITE DE FPS: NATIVO o una tasa fija (RT64 refreshRate)
    ToggleShowFps,   // MOSTRAR FPS: indicador de FPS del overlay (solo números, arriba-izquierda)
    RatioSelect,     // selector RATIO: filtra las resoluciones y ajusta su valor
    ResolutionSelect,// selector RESOLUCIÓN (lista dependiente del ratio)
};

// Tipo de entrada dentro de una pantalla.
enum class Kind {
    Item,      // entrada normal: A ejecuta su acción (o entra si es submenú)
    Submenu,   // A entra a la pantalla hija (action = Open*)
    Selector,  // selector lateral < valor >: izq/der cambian, X aplica
    Option,    // opción de una pantalla-lista: A la marca, X aplica
};

// Tipo de pantalla.
enum class ScreenKind {
    Menu,  // entradas de menú (Item/Submenu/Selector)
    List,  // lista de opciones (IDIOMA/DIFICULTAD/SONIDO)
};

// Evento producido por una navegación (lo consumirá el SFX del paso 7).
enum class Event {
    None,
    Move,     // el cursor o un valor ha cambiado
    Accept,   // A: marca/selecciona o entra
    Back,     // B: vuelve atrás
};

struct Entry {
    std::string label;
    bool enabled = true;
    Kind kind = Kind::Item;
    Action action = Action::None;
    std::vector<std::string> options;  // Selector: valores posibles
    int value = 0;                     // Selector: índice activo
    bool marked = false;               // List: opción activa (resaltada en verde)
};

struct Screen {
    ScreenId id = ScreenId::Root;
    ScreenKind kind = ScreenKind::Menu;
    std::vector<Entry> entries;
    int cursor = 0;
};

// Posiciones del texto en unidades virtuales del overlay (px del juego). Valores nativos medidos:
// primera entrada Y = 0x76 (118) y paso 10; X alineada con el texto del menú (ajustable con
// HH_OVERLAY_X/Y desde la capa de dibujo).
struct Layout {
    float x = 112.0f;
    float y0 = 118.0f;  // 0x76
    float dy = 10.0f;
};

// Construye el árbol por defecto. Idempotente; se llama solo la primera vez que hace falta.
void reset();

const Screen& current_screen();
int depth();  // nº de pantallas en la pila (1 = raíz)

const Layout& layout();

// Navegación. Devuelven el evento producido (None si la entrada no hace nada).
Event move_up();
Event move_down();
Event move_left();   // solo selectores
Event move_right();  // solo selectores
Event confirm();     // A
Event back();        // B

// Serialización para diagnóstico/tests (no dibuja). `describe_tree` vuelca todo el árbol;
// `describe_current`, solo la pantalla activa con el cursor.
std::string describe_tree();
std::string describe_current();

// Diagnóstico (HH_MENU_SCREEN=<id>): coloca la pantalla indicada como activa para poder revisar su
// dibujo sin navegar (el input llega en el paso 5). `screen_id` = valor de ScreenId.
void debug_show(int screen_id);

}  // namespace hh::menu
