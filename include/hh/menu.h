#pragma once

// hh_menu — modelo del menú inicial del port (A2, paso 1: SOLO ESTADO).
//
// Describe el árbol de pantallas acordado en RETOMAR.md §Menú (CONTINUAR / NUEVA PARTIDA /
// MODO COMBATE / CONFIGURACIÓN y sus subpantallas) y la navegación. NO dibuja, NO lee input y NO
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

#include <cstdint>
#include <string>
#include <vector>

namespace hh::menu {

// Identidad de cada pantalla del árbol.
enum class ScreenId {
    Root,          // título (CONTINUAR / NUEVA PARTIDA / MODO COMBATE / CONFIGURACIÓN)
    NewGame,       // NUEVA PARTIDA (EMPEZAR PARTIDA / DIFICULTAD / selectores)
    Difficulty,    // DIFICULTAD (lista)
    BattleMode,    // MODO COMBATE (MODO VS / COMBATE DE CRIATURAS / EDITAR DATOS)
    BattleCreature,  // COMBATE DE CRIATURAS (5 COMBATES / SUPERVIVENCIA)
    Settings,      // CONFIGURACIÓN
    Language,      // IDIOMA (lista)
    Graphics,      // GRÁFICOS (RATIO / RESOLUCIÓN / P. COMPLETA / ANTIALIASING / VSYNC / FPS)
    Sound,         // SONIDO (lista)
    Debug,         // DEBUG (VENTANA DEBUG + MOSTRAR FPS)
    Extras,        // EXTRAS (desbloqueable con el codigo Konami)
    Controls,      // CONTROLES (mapeado de teclado/mando + Stick C)
    SaveEdit,          // EDICIÓN DE PARTIDA (editor de save)
    SaveEditAbilities, // EDICIÓN DE PARTIDA -> HABILIDADES (toggles)
    SaveEditBody,      // EDICIÓN DE PARTIDA -> ESTADO (estado + partes del cuerpo)
    SaveEditItems,     // EDICIÓN DE PARTIDA -> ITEMS (cantidad)
    SaveEditStats,     // EDICIÓN DE PARTIDA -> ATRIBUTOS (HP/OFFENSE/... globales)
    SaveEditCombatSim, // EDICIÓN DE PARTIDA -> SIM. COMBATE (simula N combates)
    ChooseLevel,       // EXTRAS -> ELEGIR NIVEL (CARGAR/GUARDAR/ELIMINAR + IR A NIVEL)
    LoadGame,          // CARGAR PARTIDA (menú propio de carga; Fase 2 del menú de carga/guardado)
    SaveGame,          // GUARDAR PARTIDA (copia 1:1 de la UI de cargar, encima del DATA SAVE nativo)
};

// Acción de una entrada. El modelo solo la describe.
enum class Action {
    None,
    Continue,        // CONTINUAR: retomar partida
    Exit,            // SALIR (raíz): cierra el port de forma ordenada
    StartGame,       // EMPEZAR PARTIDA
    BattleMode,      // MODO COMBATE: submenu (recreado con nuestro menu; ver docs/menu.md)
    BattleModeVs,        // MODO COMBATE -> VS MODE
    BattleModeCreature,  // MODO COMBATE -> COMBATE DE CRIATURAS (entra a su subpantalla)
    BattleModeDataEdit,  // MODO COMBATE -> EDITAR DATOS
    BattleCreatureMatches,   // COMBATE DE CRIATURAS -> 5 COMBATES
    BattleCreatureSurvival,  // COMBATE DE CRIATURAS -> SUPERVIVENCIA
    OpenNewGame,     // submenú NUEVA PARTIDA
    OpenDifficulty,  // submenú DIFICULTAD
    OpenSettings,    // submenú CONFIGURACIÓN
    OpenLanguage,    // submenú IDIOMA
    OpenGraphics,    // submenú GRÁFICOS
    OpenSound,       // submenú SONIDO
    OpenDebug,       // submenú DEBUG (VENTANA DEBUG + MOSTRAR FPS)
    OpenExtras,      // submenú EXTRAS (solo si esta desbloqueado)
    OpenChooseLevel, // EXTRAS -> ELEGIR NIVEL (CARGAR/GUARDAR/ELIMINAR + IR A NIVEL)
    OpenControls,    // submenú CONTROLES (mapeado de teclado/mando)
    OpenSaveEdit,          // EXTRAS -> EDICIÓN DE PARTIDA
    SaveEditSlot,          // EDICIÓN DE PARTIDA: selector CARGAR PARTIDA (slot; carga al cambiar)
    SaveEditProgress,      // EDICIÓN DE PARTIDA: selector PROGRESO (N-P)
    SaveEditLevel,         // EDICIÓN DE PARTIDA: selector NIVEL
    OpenSaveEditAbilities, // EDICIÓN DE PARTIDA -> HABILIDADES
    SaveEditAbilitiesBulk,   // HABILIDADES: selector SIN CAMBIOS / TODO SÍ / TODO NO
    OpenSaveEditBody,      // EDICIÓN DE PARTIDA -> BODY
    SaveEditBodyState,     // BODY/ESTADO: selector OFENSIVO/DEFENSIVO (nivel de parte)
    SaveEditBodyValue,     // BODY/ESTADO: fila nivel de parte (`< NIVEL n >`)
    SaveEditBodyBulk,      // BODY/ESTADO: TODOS = nudge ±1 a las 6 partes del eje activo
    SaveEditBodyLevel,     // (sin uso) BODY: fila de nivel de atributo
    SaveEditBodyProgress,  // (sin uso) BODY: fila de progreso/EXP
    OpenSaveEditItems,     // EDICIÓN DE PARTIDA -> ITEMS
    SaveEditItem,          // ITEMS: fila de cantidad
    OpenSaveEditStats,     // EDICIÓN DE PARTIDA -> ATRIBUTOS (HP/atributos globales)
    SaveEditStat,          // ATRIBUTOS: fila de valor (cur.index = cual)
    OpenSaveEditCombatSim, // EDICIÓN DE PARTIDA -> SIM. COMBATE
    SaveEditAttrLevel,     // ATRIBUTOS: nivel por atributo (izq/der cambian y aplican incrementos)
    SaveEditAttrBulk,      // ATRIBUTOS -> TODOS: sube/baja el mismo delta a los 6 atributos
    SaveEditSave,          // EDICIÓN DE PARTIDA: GUARDAR
    SaveEditDelete,        // EDICIÓN DE PARTIDA: ELIMINAR slot (A sobre el selector)
    SaveEditRestore,       // EDICIÓN DE PARTIDA: RESTAURAR el slot al estado al cargar el `.pak`
    ToggleVibration, // CONTROLES -> VIBRACIÓN: Rumble Pak / vibración del mando
    ResetControls,   // CONTROLES -> RESET: vuelve al mapeo por defecto (mando + teclado)
    ToggleExtrasPersist,  // EXTRAS -> MANTENER EXTRAS: SÍ = el menu EXTRAS persiste entre arranques
    ToggleOriginalLogos,  // EXTRAS -> LOGOS ORIGINALES: SÍ = clasicos (blanco), NO = modernos (negro)
    ToggleHeavenMode,     // EXTRAS -> MODO HEAVEN: SÍ = aplica el "modo trampa" (niveles/hab/items)
    ToggleAdvantage,      // EXTRAS -> VENTAJA: SÍ = ventaja de combate (back attack) siempre
    ToggleInfinitePower,    // EXTRAS -> PODER ∞: SÍ = el PODER de combate no se gasta
    ToggleInfiniteStamina,  // EXTRAS -> RESIS. ∞: SÍ = la RESISTENCIA de combate no se gasta
    ToggleDebugLevels,      // EXTRAS -> DEBUG NIVELES: SÍ = atajos del ciclo de puntos + indicador idx
    WarpToLevel,     // EXTRAS -> IR A NIVEL: teletransporta al Area-Parte seleccionada (transicion)
    ToggleDebug,     // VENTANA DEBUG: habilita el modo desarrollador de RT64 (Inspector con F1)
    ToggleFullscreen,// P. COMPLETA: NO = ventana (windowed); SÍ = borderless completa
    ToggleVsync,     // VSYNC: NO/ SÍ; aplica la sincronía de presentación de RT64
    FpsLimit,        // LÍMITE DE FPS: NATIVO o una tasa fija (RT64 refreshRate)
    ToggleShowFps,   // MOSTRAR FPS: indicador de FPS del overlay (solo números, arriba-izquierda)
    MsaaSelect,      // ANTIALIASING: MSAA de RT64 (x0/x2/x4/x8)
    VolumeSelect,    // VOLUMEN: volumen general (0-100 %)
    OutputSelect,    // SALIDA: MONO / ESTÉREO / AURICULARES (crossfeed)
    MenuSfxToggle,   // MENÚ SFX: activa/desactiva los sonidos del menú
    RatioSelect,     // selector RATIO: filtra las resoluciones y ajusta su valor
    ResolutionSelect,// selector RESOLUCIÓN (lista dependiente del ratio)
    OpenLoadGame,    // CARGAR PARTIDA: sustituye el CONTINUAR nativo (menú propio; Fase 2)
    LoadGamePick,    // CARGAR PARTIDA: A sobre una partida de la lista -> cargarla
    SaveGameNew,     // GUARDAR PARTIDA: A sobre "NEW GAME" -> guardar en el siguiente slot libre
    SaveGamePick,    // GUARDAR PARTIDA: A sobre un slot con datos -> sobrescribirlo
};

// Tipo de entrada dentro de una pantalla.
enum class Kind {
    Item,      // entrada normal: A ejecuta su acción (o entra si es submenú)
    Submenu,   // A entra a la pantalla hija (action = Open*)
    Selector,  // selector lateral < valor >: izq/der cambian, X aplica
    Option,    // opción de una pantalla-lista: A la marca, X aplica
    Binding,   // fila de mapeado: etiqueta + binding actual a la derecha (A reasigna)
    Number,    // fila numérica < valor >: izq/der suman/restan `step` (min..max)
    Toggle,    // fila con estado propio NO/SÍ: A la alterna (varias a la vez)
};

// Tipo de pantalla.
enum class ScreenKind {
    Menu,    // entradas de menú (Item/Submenu/Selector/Number)
    List,    // lista de opciones (IDIOMA/DIFICULTAD/SONIDO)
    Toggle,  // lista de toggles independientes (HABILIDADES)
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
    int value = 0;                     // Selector/Number: valor activo
    bool marked = false;               // List/Toggle: opción activa/marcada (verde)
    int min = 0;                       // Number: mínimo
    int max = 0;                       // Number: máximo
    int step = 1;                      // Number: paso
    int index = -1;                    // Number/Toggle: índice (parte, item, técnica...)
    std::string binding;               // Binding: texto del binding actual (derecha)
    std::string remap_key;             // Binding: accion N64 a reasignar ("a","b","z",...)
    std::string prefix;                // Number: prefijo del valor (p. ej. "NIVEL " -> "< NIVEL 5 >")
    std::string suffix;                // Number: anotación a la derecha del valor (p. ej. "NIVEL 5")
    bool stepper = false;              // Selector: forzar estilo < valor > (chevrons) aunque las
                                       // opciones quepan enteras (p. ej. ANTIALIASING x0/x2/x4/x8)
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

// Acceso de solo lectura a una pantalla por id (nullptr si no existe). Lo usa la capa de acciones
// (feed_menu_navigation) para consultar el estado de OTRA pantalla; p. ej. la DIFICULTAD marcada al
// pulsar EMPEZAR PARTIDA.
const Screen* screen(ScreenId id);

// Empuja una pantalla hija por id (sin pasar por `confirm()`). Lo usa la capa de acciones para
// acompañar la navegación NATIVA cuando el overlay controla un submenú que no se entra desde nuestro
// modelo (p. ej. COMBATE DE CRIATURAS). No hace nada si el id no existe.
void push(ScreenId id);

const Layout& layout();

// Traduce una etiqueta/opción canónica (en español) al idioma activo (hh::text_current_language()).
// Si no hay traducción para la clave, devuelve la canónica tal cual. La capa de dibujo la usa.
std::string localized(const std::string& label);

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

// --- EDICIÓN DE PARTIDA (editor de save; ver hh/save_edit.h) -------------------------------------
// Slot seleccionado (0..3) y estado de BODY seleccionado (0..3); las pantallas del editor se
// reconstruyen con refresh_save_edit() cuando cambian o cuando se edita un valor.
int save_edit_slot();
void set_save_edit_slot(int slot);
int save_edit_save_target();          // 0 = NUEVA PARTIDA, 1..N = slot
void set_save_edit_save_target(int t);
int save_edit_save_target_slot();     // slot real destino (0..N-1); resuelve NUEVA PARTIDA
int save_edit_delete_target();        // ELIMINAR: 1..N = slot a borrar (valor del selector)
void set_save_edit_delete_target(int t);
int save_edit_delete_slot();          // slot real a borrar (0..N-1)
int save_edit_body_state();
void set_save_edit_body_state(int state);

uint16_t save_edit_progress_value(int index);   // índice del selector PROGRESO -> N*10+P
void refresh_save_edit();

// Valor de escena del slot (índice de mapa, `0x564`) -> Área-Parte (N-P) según la MISMA enumeración
// que el selector PROGRESO (`kAreaPartsSave`). Lo usa el guardado de la cápsula para la cabecera.
// Fallback si no está en la tabla: `area = v/10 + 1`, `sub = (v%10)/2 + 1`.
void area_sub_from_value(uint16_t value, int& area, int& sub);

// --- CARGAR PARTIDA (menú propio de carga; Fase 2 del menú de carga/guardado) --------------------
// La pantalla `LoadGame` lista las 45 partidas del `.pak` (rango de partidas, sin las plantillas), con
// los metadatos del trailer (Área-Level / nivel / tiempo). La fila i corresponde al slot i (0-based).
// A sobre una partida la carga. Se reconstruye con refresh_load_game() cuando el `.pak` cambia.
// Ver notes/2026-09-29-menu-cargar-guardar-fase2-ui.md.
const char* load_game_row_text(int index);   // texto de la fila (dibujo 1:1), o nullptr
bool load_game_row_present(int index);       // true si la partida existe (registro presente)
void refresh_load_game();                    // reconstruye LoadGame/SaveGame desde el `.pak`
// Fija la pila a [Root, LoadGame] (idempotente) y refresca la lista. La llama el hook del file-select
// (Fase 3) para que, al dar CONTINUAR, la pantalla activa sea la nuestra.
void open_load_game();

// --- GUARDAR PARTIDA (copia 1:1 de la UI de cargar sobre el DATA SAVE nativo) --------------------
// La pantalla `SaveGame` parte como COPIA de `LoadGame` (mismos 45 slots y metadatos). El hook de la
// vía de guardado (0x803771A4) la publica ENCIMA del DATA SAVE nativo (sin ocultarlo) para poder
// comparar ambas UI y ajustar la de guardado a 1:1. No hay lógica de guardado todavía.
void open_save_game();
// Cierra la "sesión" de guardado: al volver a ENTRAR en la cápsula el flujo debe REINICIARSE en `Ask`
// (si no, se quedaba la última fase, p. ej. `Completed`, y A solo salía). La llama el hook al salir.
void close_save_game();

// GUARDAR: fase del flujo de guardado en la capsula (DATA SAVE):
//   Ask         -> "Save play data?" Yes/No (slots OCULTOS).
//   Select      -> mensaje con bindings (A/J guarda, X/H borra) + slots (sin Yes/No).
//   ConfirmHere -> "Saving current play data here." Yes/No (slots VISIBLES; slot objetivo marcado).
//   ConfirmExit -> "Exit without saving?" Yes/No (mensaje NUEVO del port, no nativo).
//   ConfirmDelete -> confirmacion de BORRADO de un slot (Yes/No).
//   Completed   -> "Save completed." + flecha abajo; A cierra y el PJ sale de la capsula.
//   Removed     -> "Remove completed." + flecha abajo; A vuelve a `Select` (NO sale de la capsula).
enum class SavePhase { Ask, Select, ConfirmHere, ConfirmExit, ConfirmDelete, Completed, Removed };
SavePhase save_phase();
void set_save_phase(SavePhase phase);
// GUARDAR: compatibilidad: `true` mientras el prompt INICIAL ("Save play data?") está activo. Es
// equivalente a `save_phase() == SavePhase::Ask` (los slots permanecen ocultos).
bool save_confirm();
void set_save_confirm(bool on);
// GUARDAR: opcion elegida en el prompt (true = Yes, false = No). El overlay dibuja el cursor en ella.
bool save_yes_selected();
void set_save_yes_selected(bool on);
// GUARDAR: true cuando ya se eligio Yes Y ha pasado el retardo (~0.5 s); entonces se muestran los slots.
bool save_slots_ready();
// GUARDAR: slot objetivo (0-based) elegido en la lista para "Saving current play data here." (-1 = NEW
// GAME / siguiente libre). Lo fija el handler de input al pulsar A sobre una fila.
int save_target_slot();
void set_save_target_slot(int slot);
// GUARDAR: mensaje de la fase `Select` (SUSTITUYE al `Select location in which to save play data.`)
// con los bindings REALES insertados (p. ej. `A/J` guarda, `X/H` borra).
std::string save_select_message();
// GUARDAR: slot objetivo del BORRADO (fase ConfirmDelete; -1 = ninguno).
int save_delete_slot();
void set_save_delete_slot(int slot);
// true durante ~120 ms tras entrar en `Select`/`Removed`: ignora el input que provoco la transicion.
bool save_input_blocked();

// --- ELEGIR NIVEL (EXTRAS): CARGAR/GUARDAR/ELIMINAR + IR A NIVEL ---------------------------------
// `game_loaded` = hay una partida viva (se pone al cargar/empezar y al deserializar el personaje).
// IR A NIVEL (transición de escena) solo está disponible con partida cargada.
bool game_loaded();
void set_game_loaded(bool on);
uint16_t warp_value_at(int index);   // índice del selector IR A NIVEL -> valor de escena (idx)
// IR A NIVEL sin partida cargada: pide cargar la plantilla y, tras cargar, hacer el warp a `idx`.
void request_warp(uint16_t idx);
bool take_pending_warp(uint16_t& idx);   // consume el warp pendiente (lo llama el hook de carga)

// CICLO DE PUNTOS (diagnóstico): recorre los índices de escena (0..299) para mapearlos a mano. F8/F9
// (o las teclas asignadas) piden avanzar/retroceder; el hook del menú (con rdram) lo ejecuta. El
// índice vive aquí (persiste entre cargas). Ver notes/2026-09-29-editor-area-parte-plan.md.
void cycle_step(int delta);        // pide mover el índice del ciclo (+1/-1, fino)
void cycle_step_block(int delta);  // pide mover el índice de 10 en 10 (bloques de área)
void cycle_reset();                // reinicia el índice del ciclo a 0
void cycle_goto(int idx);          // salta a un índice concreto y lo ejecuta (p. ej. 7 = menú)
bool cycle_skipped(int idx);       // true si el índice está en la lista de saltos (cuelga)
bool request_cycle();              // ¿hay un paso de ciclo pendiente? (lo consume el hook del menú)
int  cycle_index();                // índice actual del ciclo (0..299)
// HABILIDADES: guarda la copia de la carga y restaura una técnica desde ella (selector SIN CAMBIOS).
void capture_tech_baseline();
void restore_tech_baseline(int id);
void set_save_edit_tech_bulk(int mode);   // 0 SIN CAMBIOS, 1 TODO SÍ, 2 TODO NO

// EXTRAS -> DEBUG NIVELES: activa los atajos del CICLO DE PUNTOS (F5/F6, RePag/AvPag) y el indicador
// `idx=` en pantalla. Persiste en config.ini [extras].debug_levels.
bool debug_levels_enabled();
void set_debug_levels_enabled(bool on);

// EXTRAS -> MODO HEAVEN: modo GLOBAL de juego (persiste en config.ini [extras].heaven). Al cargar
// cualquier partida aplica ATRIBUTOS/ESTADO máx + habilidades, y en runtime anula el daño al jugador
// y el consumo de items (hooks de `src/hooks/sections.cpp`). Ver RETOMAR.md.
bool heaven_enabled();
void set_heaven_enabled(bool on);   // persiste el flag (equivale a extras_set_heaven)

// EXTRAS -> VENTAJA: ventaja de combate ("back attack") siempre, INDEPENDIENTE de MODO HEAVEN (puede
// ir sola). Persiste en config.ini [extras].advantage. La ventaja se aplica si HEAVEN **o** VENTAJA
// estan en SI (`src/hooks/sections.cpp`), asi que activar HEAVEN la incluye y no hay conflicto.
bool advantage_enabled();
void set_advantage_enabled(bool on);   // persiste el flag (equivale a extras_set_advantage)

// EXTRAS -> PODER ∞ / RESIS. ∞: gauges de combate del jugador que no se gastan (los pinnea
// `hh_battle_frame_hook` a max cada frame). Persistentes en config.ini [extras].infinite_power y
// [extras].infinite_stamina. Direcciones/medio del gauge MEDIDOS con la traza F12 (ver RETOMAR.md).
bool infinite_power_enabled();
void set_infinite_power_enabled(bool on);
bool infinite_stamina_enabled();
void set_infinite_stamina_enabled(bool on);

// EXTRAS: pantalla desbloqueable con el codigo Konami durante el logo KONAMI. Se muestra si se
// desbloqueo en esta sesion con el codigo o si el ajuste MANTENER EXTRAS esta en SI ([extras] en
// config.ini). Al desbloquear se rehace el arbol para anadir la entrada EXTRAS (encima de SALIR).
bool extras_unlocked();
void unlock_extras();
// Solo el desbloqueo por codigo de la sesion (sin el ajuste MANTENER EXTRAS): lo usa la intro para
// el cambio a los logos modernos (recompensa del codigo).
bool extras_code_unlocked();

}  // namespace hh::menu
