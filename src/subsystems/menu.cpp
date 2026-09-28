// hh_menu — modelo del menú inicial del port (A2, paso 1: SOLO ESTADO).
//
// Implementa el árbol y la navegación descritos en include/hh/menu.h y RETOMAR.md §Menú. No dibuja,
// no lee input y no persiste: es una máquina de estados pura y testeable.

#include "hh/menu.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>

#include "hh.h"   // VideoConfig/AudioConfig: valores iniciales de los selectores
#include "hh/save_edit.h"  // EDICIÓN DE PARTIDA

namespace hh::menu {
namespace {

std::vector<Screen> g_screens;      // todas las pantallas (el estado vive aquí y se conserva)
std::vector<ScreenId> g_stack;      // camino activo; el tope es la pantalla visible
Layout g_layout;

// EXTRAS: se muestra si se ha desbloqueado en esta sesion con el codigo Konami, o si hay algun
// ajuste de EXTRAS persistido distinto del valor por defecto (asi el menu no se pierde tras
// configurarlo). Al volver a los valores por defecto deja de estar persistido -> oculto al arrancar.
bool g_extras_unlocked_state = false;

// Traducciones de las etiquetas/opciones del menú. Clave = etiqueta canónica en ESPAÑOL (la del
// modelo). Columnas: en, ca, fr, de, ja. El JAPONÉS se escribe en KANA (la fuente color0 del juego
// tiene kana en los valores 64..255; ver tools/text/extract_jp_kana.py e include/hh/jp_kana.h). No
// hay kanji en esa fuente, así que todo va en katakana/hiragana. Uppercase (la fuente del menú no
// tiene minúsculas acentuadas). Las tildes salen de las marcas del overlay (A/N/C).
struct MenuTr {
    const char* es;
    const char* en;
    const char* ca;
    const char* fr;
    const char* de;
    const char* ja;
};
const MenuTr kMenuTr[] = {
    // Pantallas / entradas
    {"CONTINUAR", "CONTINUE", "CONTINUAR", "CONTINUER", "FORTSETZEN", "コンティニュー"},
    {"NUEVA PARTIDA", "NEW GAME", "NOVA PARTIDA", "NOUVELLE PARTIE", "NEUES SPIEL", "ニューゲーム"},
    {"MODO COMBATE", "BATTLE MODE", "MODE COMBAT", "MODE COMBAT", "KAMPFMODUS", "バトルモード"},
    // MODO COMBATE (subpantallas recreadas con nuestro menu; ver docs/menu.md)
    {"MODO VS", "VS MODE", "MODE VS", "MODE VS", "VS-MODUS", "タイセンモード"},
    {"COMBATE DE CRIATURAS", "CREATURE BATTLE", "COMBAT DE CRIATURES", "COMBAT DE CRÉATURES",
     "KREATURENKAMPF", "クリーチャーバトル"},
    {"EDITAR DATOS", "DATA EDIT", "EDITAR DADES", "ÉDITER DONNÉES", "DATEN BEARBEITEN",
     "データエディット"},
    {"5 COMBATES", "5 MATCHES", "5 COMBATS", "5 COMBATS", "5 KÄMPFE", "5タイセン"},
    {"SUPERVIVENCIA", "SURVIVAL", "SUPERVIVÈNCIA", "SURVIE", "ÜBERLEBEN", "サバイバル"},
    {"CONFIGURACIÓN", "SETTINGS", "CONFIGURACIÓ", "CONFIGURATION", "KONFIGURATION", "コンフィグ"},
    {"SALIR", "EXIT", "SORTIR", "QUITTER", "BEENDEN", "シュウリョウ"},
    {"EMPEZAR PARTIDA", "START GAME", "COMENÇAR PARTIDA", "COMMENCER", "SPIEL STARTEN",
     "ゲームスタート"},
    {"DIFICULTAD", "DIFFICULTY", "DIFICULTAT", "DIFFICULTÉ", "SCHWIERIGKEIT", "ナンイド"},
    {"IDIOMA", "LANGUAGE", "IDIOMA", "LANGUE", "SPRACHE", "ゲンゴ"},
    {"GRÁFICOS", "GRAPHICS", "GRÀFICS", "GRAPHIQUES", "GRAFIK", "グラフィック"},
    {"SONIDO", "SOUND", "SO", "SON", "TON", "サウンド"},
    {"DEBUG", "DEBUG", "DEBUG", "DEBUG", "DEBUG", "デバッグ"},
    {"EXTRAS", "EXTRAS", "EXTRAS", "EXTRAS", "EXTRAS", "エクストラ"},
    {"MANTENER EXTRAS", "KEEP EXTRAS", "MANTENIR EXTRAS", "GARDER EXTRAS", "EXTRAS BEHALTEN",
     "エクストラホゾン"},
    {"LOGOS ORIGINALES", "ORIGINAL LOGOS", "LOGOS ORIGINALS", "LOGOS ORIGINAUX", "ORIGINAL-LOGOS",
     "オリジナルロゴ"},
    {"CONTROLES", "CONTROLS", "CONTROLS", "CONTRÔLES", "STEUERUNG", "コントロール"},
    {"ARRIBA/ADELANTE", "UP/FORWARD", "AMUNT/ENDAVANT", "HAUT/AVANT", "HOCH/VORWÄRTS",
     "ウエ/ススム"},
    {"ABAJO/ATRÁS", "DOWN/BACK", "AVALL/ENRERE", "BAS/ARRIÈRE", "RUNTER/ZURÜCK", "シタ/モドル"},
    {"IZQUIERDA", "LEFT", "ESQUERRA", "GAUCHE", "LINKS", "ヒダリ"},
    {"DERECHA", "RIGHT", "DRETA", "DROITE", "RECHTS", "ミギ"},
    {"MENÚ ARRIBA", "MENU UP", "MENÚ AMUNT", "MENU HAUT", "MENÜ HOCH", "メニューウエ"},
    {"MENÚ ABAJO", "MENU DOWN", "MENÚ AVALL", "MENU BAS", "MENÜ RUNTER", "メニューシタ"},
    {"MENÚ IZQUIERDA", "MENU LEFT", "MENÚ ESQUERRA", "MENU GAUCHE", "MENÜ LINKS",
     "メニューヒダリ"},
    {"MENÚ DERECHA", "MENU RIGHT", "MENÚ DRETA", "MENU DROITE", "MENÜ RECHTS", "メニューミギ"},
    {"ACCIÓN/ACEPTAR", "ACTION/ACCEPT", "ACCIÓ/ACCEPTAR", "ACTION/ACCEPTER", "AKTION/OK",
     "ケッテイ"},
    {"MAPA/ATRÁS", "MAP/BACK", "MAPA/ENRERE", "CARTE/RETOUR", "KARTE/ZURÜCK", "マップ/モドル"},
    {"AGACHARSE", "CROUCH", "AJUPIR-SE", "S'ACCROUPIR", "DUCKEN", "シャガム"},
    {"MENÚ", "MENU", "MENÚ", "MENU", "MENÜ", "メニュー"},
    {"APUNTAR", "AIM", "APUNTAR", "VISER", "ZIELEN", "エイム"},
    {"VIBRACIÓN", "VIBRATION", "VIBRACIÓ", "VIBRATION", "VIBRATION", "シンドウ"},
    {"ALTURA CÁMARA", "CAMERA HEIGHT", "ALÇADA CÀMERA", "HAUTEUR CAMÉRA", "KAMERAHÖHE",
     "カメラノタカサ"},
    {"PRIMERA PERSONA", "FIRST PERSON", "PRIMERA PERSONA", "PREMIÈRE PERSONNE", "ERSTE PERSON",
     "イチニンショウ"},
    {"PULSA...", "PRESS...", "PREM...", "APPUYEZ...", "DRÜCKEN...", "オシテ..."},
    {"D-PAD ARRIBA", "D-PAD UP", "D-PAD AMUNT", "D-PAD HAUT", "D-PAD HOCH", "ジュウジキウエ"},
    {"D-PAD ABAJO", "D-PAD DOWN", "D-PAD AVALL", "D-PAD BAS", "D-PAD RUNTER", "ジュウジキシタ"},
    {"D-PAD IZQ", "D-PAD LEFT", "D-PAD ESQ", "D-PAD GAUCHE", "D-PAD LINKS", "ジュウジキヒダリ"},
    {"D-PAD DER", "D-PAD RIGHT", "D-PAD DRETA", "D-PAD DROITE", "D-PAD RECHTS", "ジュウジキミギ"},
    {"CÁMARA LIBRE", "FREE CAMERA", "CÀMERA LLIURE", "CAMÉRA LIBRE", "FREIE KAMERA", "フリーカメラ"},
    {"APUNTADO LIBRE", "FREE AIM", "APUNTAT LLIURE", "VISÉE LIBRE", "FREIES ZIELEN",
     "フリーエイム"},
    {"RATIO", "RATIO", "RATIO", "RATIO", "RATIO", "ガメンヒ"},
    {"RESOLUCIÓN", "RESOLUTION", "RESOLUCIÓ", "RÉSOLUTION", "AUFLÖSUNG", "カイゾウド"},
    {"P. COMPLETA", "FULLSCREEN", "P. COMPLETA", "PLEIN ÉCRAN", "VOLLBILD", "フルスクリーン"},
    {"ANTIALIASING", "ANTIALIASING", "ANTIALIASING", "ANTIALIASING", "ANTIALIASING",
     "アンチエイリアス"},
    {"VSYNC", "VSYNC", "VSYNC", "VSYNC", "VSYNC", "ブイシンク"},
    {"LÍMITE DE FPS", "FPS LIMIT", "LÍMIT DE FPS", "LIMITE FPS", "FPS-LIMIT", "FPSセイゲン"},
    {"VENTANA DEBUG", "DEBUG WINDOW", "FINESTRA DEBUG", "FENÊTRE DEBUG", "DEBUG-FENSTER",
     "デバッグウインドウ"},
    {"MOSTRAR FPS", "SHOW FPS", "MOSTRAR FPS", "AFFICHER FPS", "FPS ANZEIGEN", "FPSヒョウジ"},
    {"VOLUMEN", "VOLUME", "VOLUM", "VOLUME", "LAUTSTÄRKE", "オンリョウ"},
    {"SALIDA", "OUTPUT", "SORTIDA", "SORTIE", "AUSGABE", "シュツリョク"},
    {"MENÚ SFX", "MENU SFX", "MENÚ SFX", "MENU SFX", "MENÜ-SFX", "メニューオンセイ"},
    // EDICIÓN DE PARTIDA (editor de save)
    {"EDICIÓN DE PARTIDA", "SAVE EDIT", "EDICIÓ DE PARTIDA", "ÉDITION DE PARTIE",
     "SPIELSTAND-EDITOR", "セーブエディット"},
    {"PARTIDA", "SAVE", "PARTIDA", "PARTIE", "SPIELSTAND", "セーブ"},
    {"CARGAR PARTIDA", "LOAD SAVE", "CARREGAR PARTIDA", "CHARGER PARTIE", "SPIELSTAND LADEN",
     "ロードセーブ"},
    {"GUARDAR PARTIDA", "SAVE GAME", "DESAR PARTIDA", "SAUVEGARDER", "SPEICHERN", "セーブする"},
    {"PROGRESO", "PROGRESS", "PROGRÉS", "PROGRÈS", "FORTSCHRITT", "シンコウ"},
    {"NIVEL", "LEVEL", "NIVELL", "NIVEAU", "LEVEL", "レベル"},
    {"HABILIDADES", "ABILITIES", "HABILITATS", "CAPACITÉS", "FÄHIGKEITEN", "ノウリョク"},
    {"BODY", "BODY", "COS", "CORPS", "KÖRPER", "ボディ"},
    {"GUARDAR", "SAVE", "DESAR", "SAUVEGARDER", "SPEICHERN", "セーブ"},
    {"ESTADO", "STATE", "ESTAT", "ÉTAT", "STATUS", "ジョウタイ"},
    {"CABEZA", "HEAD", "CAP", "TÊTE", "KOPF", "アタマ"},
    {"BRAZO IZQ", "LEFT ARM", "BRAÇ ESQ", "BRAS GAUCHE", "LINKER ARM", "ヒダリウデ"},
    {"BRAZO DER", "RIGHT ARM", "BRAÇ DRET", "BRAS DROIT", "RECHTER ARM", "ミギウデ"},
    {"PIERNA IZQ", "LEFT LEG", "CAMA ESQ", "JAMBE GAUCHE", "LINKES BEIN", "ヒダリアシ"},
    {"PIERNA DER", "RIGHT LEG", "CAMA DRET", "JAMBE DROITE", "RECHTES BEIN", "ミギアシ"},
    {"CUERPO", "BODY", "COS", "CORPS", "KÖRPER", "カラダ"},
    {"OFENSIVO", "OFFENSIVE", "OFENSIU", "OFFENSIF", "OFFENSIV", "コウゲキ"},
    {"DEFENSIVO", "DEFENSIVE", "DEFENSIU", "DÉFENSIF", "DEFENSIV", "ボウギョ"},
    {"HIT COUNT", "HIT COUNT", "HIT COUNT", "HIT COUNT", "TREFFER", "ヒットスウ"},
    {"DAMAGE COUNT", "DAMAGE COUNT", "DAMAGE COUNT", "DAMAGE COUNT", "SCHADEN", "ダメージスウ"},
    // Opciones (mismos valores en todos los idiomas si no cambian)
    {"SÍ", "YES", "SÍ", "OUI", "JA", "ハイ"},
    {"NO", "NO", "NO", "NON", "NEIN", "イイエ"},
    {"AUTO", "AUTO", "AUTO", "AUTO", "AUTO", "オート"},
    {"ORIGINAL", "ORIGINAL", "ORIGINAL", "ORIGINAL", "ORIGINAL", "オリジナル"},
    {"NATIVO", "NATIVE", "NATIU", "NATIF", "NATIV", "ネイティブ"},
    {"MONO", "MONO", "MONO", "MONO", "MONO", "モノ"},
    {"ESTÉREO", "STEREO", "ESTÈREO", "STÉRÉO", "STEREO", "ステレオ"},
    {"AURICULARES", "HEADPHONES", "AURICULARS", "CASQUE", "KOPFHÖRER", "ヘッドホン"},
    {"DEFINITIVO", "ULTIMATE", "DEFINITIU", "SUPRÊME", "ULTIMATIV", "アルティメット"},
    {"DIFÍCIL", "HARD", "DIFÍCIL", "DIFFICILE", "SCHWER", "ハード"},
    {"NORMAL", "NORMAL", "NORMAL", "NORMAL", "NORMAL", "ノーマル"},
};

// Endónimos de la lista IDIOMA: SIEMPRE en su propia lengua (no dependen del idioma activo). Clave =
// nombre canónico en español; valor = endónimo a mostrar. Uppercase (la fuente del menú no tiene
// minúsculas acentuadas: à/ñ/ç). JA en kana (ニホンゴ): color0 no tiene kanji (日本語 sería imposible),
// pero la kana sí (ver jp_kana.h).
struct Endonym { const char* es; const char* shown; };
const Endonym kEndonyms[] = {
    {"INGLÉS", "ENGLISH"},  {"ESPAÑOL", "ESPAÑOL"}, {"CATALÁN", "CATALÀ"},
    {"FRANCÉS", "FRANÇAIS"}, {"ALEMÁN", "DEUTSCH"}, {"JAPONÉS", "ニホンゴ"},
};

Entry make_item(const char* label, Action action, bool enabled = true) {
    Entry e;
    e.label = label;
    e.enabled = enabled;
    e.kind = Kind::Item;
    e.action = action;
    return e;
}

Entry make_submenu(const char* label, Action action, bool enabled = true) {
    Entry e = make_item(label, action, enabled);
    e.kind = Kind::Submenu;
    return e;
}

Entry make_selector(const char* label, std::vector<std::string> options, int value = 0,
                    bool enabled = true) {
    Entry e;
    e.label = label;
    e.enabled = enabled;
    e.kind = Kind::Selector;
    e.options = std::move(options);
    e.value = value;
    return e;
}

// Selector con acción (p. ej. DEBUG -> ToggleDebug): el valor cambia con izq/der y el enganche lee
// `action` para aplicar el efecto (ver feed_menu_navigation).
Entry make_selector_with_action(const char* label, std::vector<std::string> options, Action action,
                                int value = 0) {
    Entry e = make_selector(label, std::move(options), value);
    e.action = action;
    return e;
}

// Valores iniciales de GRÁFICOS desde config.ini [video] (persistidos por las acciones del menú).
int fullscreen_default() { return hh::video_config().wm == "windowed" ? 0 : 1; }
int vsync_default() { return hh::video_config().vsync == "no" ? 0 : 1; }
int fps_limit_default() {
    const std::string& f = hh::video_config().fps;
    if (f.empty() || f == "nativo" || f == "native") return 0;
    switch (std::atoi(f.c_str())) {
        case 30:  return 1;
        case 40:  return 2;
        case 60:  return 3;
        case 75:  return 4;
        case 90:  return 5;
        case 120: return 6;
        case 144: return 7;
        case 165: return 8;
        case 240: return 9;
        default:  return 0;
    }
}
int show_fps_default() { return hh::video_config().showfps == "si" ? 1 : 0; }
int developer_default() { return hh::video_config().developer == "si" ? 1 : 0; }
// VOLUMEN: indice 0..10 (pasos de 10 %) según `[audio].volumen`.
int volume_default() { return std::clamp((hh::audio_config().volume + 5) / 10, 0, 10); }
// SALIDA: 0 MONO, 1 ESTÉREO, 2 AURICULARES según `[audio].salida` (orden MONO/ESTÉREO/AURICULARES).
int output_default() {
    const std::string& o = hh::audio_config().output;
    if (o == "mono") return 0;
    if (o == "auriculares" || o == "headphones" || o == "crossfeed") return 2;
    return 1;  // estereo (default)
}
int menu_sfx_default() { return hh::audio_config().menusfx == "no" ? 0 : 1; }
// CONTROLES -> VIBRACIÓN: Rumble Pak / vibración del mando (persiste en config.ini [input]).
int vibration_default() { return hh::input_vibration_enabled() ? 1 : 0; }
// EXTRAS -> LOGOS ORIGINALES: SÍ (1) = clasicos de fondo blanco; NO (0) = modernos de fondo negro.
int original_logos_default() { return hh::extras_config().original_logos == "si" ? 1 : 0; }
// EXTRAS -> MANTENER EXTRAS: SÍ (1) = el menu EXTRAS persiste entre arranques; NO (0) = solo tras
// teclear el codigo Konami.
int extras_persist_default() { return hh::extras_config().persist == "si" ? 1 : 0; }
// RATIO: índice en {"AUTO","ORIGINAL","4:3","16:9","16:10","21:9"} según `[video].aspect`.
int ratio_default() {
    const std::string a = hh::video_config().aspect;
    if (a == "original") return 1;
    if (a == "4:3") return 2;
    if (a == "16:9") return 3;
    if (a == "16:10") return 4;
    if (a == "21:9") return 5;
    return 0;  // auto / expand
}
// ANTIALIASING: x0/x2/x4/x8 según `[video].msaa`.
int msaa_default() {
    const std::string& m = hh::video_config().msaa;
    if (m == "off" || m == "none" || m == "0") return 0;
    if (m == "2x") return 1;
    if (m == "4x") return 2;
    return 3;  // 8x (default)
}

// Fila de mapeado (CONTROLES): etiqueta de la accion N64 + su binding actual a la derecha.
// `action_key` es el nombre de la accion (mismos que config.ini [game]: a,b,z,start,l,r,dup,...).
Entry make_binding(const char* label, const char* action_key) {
    Entry e;
    e.label = label;
    e.kind = Kind::Binding;
    e.binding = hh::pad_binding_desc(action_key);
    e.remap_key = action_key;
    return e;
}

Entry make_option(const char* label, bool marked = false) {
    Entry e;
    e.label = label;
    e.kind = Kind::Option;
    e.marked = marked;
    return e;
}

Screen make_screen(ScreenId id, ScreenKind kind, std::vector<Entry> entries) {
    Screen s;
    s.id = id;
    s.kind = kind;
    s.entries = std::move(entries);
    return s;
}

// Fila numérica (< valor >) y fila toggle (marca propia NO/SÍ) del editor de partida.
Entry make_number(const char* label, int min, int max, int value, int index, Action action) {
    Entry e;
    e.label = label;
    e.kind = Kind::Number;
    e.value = value;
    e.min = min;
    e.max = max;
    e.step = 1;
    e.index = index;
    e.action = action;
    return e;
}
Entry make_toggle(const char* label, bool marked, int index, Action action) {
    Entry e;
    e.label = label;
    e.kind = Kind::Toggle;
    e.marked = marked;
    e.index = index;
    e.action = action;
    return e;
}

// --- EDICIÓN DE PARTIDA: estado del editor y utilidades -------------------------------------------
int g_edit_slot = 0;        // 0..3
int g_edit_body_state = 0;  // ESTADO (nivel de parte): 0 OFENSIVO, 1 DEFENSIVO
int g_edit_tech_bulk = 0;   // HABILIDADES: 0 SIN CAMBIOS, 1 TODO SÍ, 2 TODO NO
int g_edit_save_target = 0; // GUARDAR: 0 = NUEVA PARTIDA (primer hueco libre), 1..4 = slot
int g_edit_delete_target = 1; // ELIMINAR: 1..4 = slot a borrar (valor del selector)
// Copia de las técnicas tal como estaban al CARGAR (para "SIN CAMBIOS").
uint8_t g_tech_baseline[hh::save::kTechCount];
bool g_tech_baseline_valid = false;

// Puntos de guardado validos por INDICE de escena interno (0..29), leidos de la tabla REAL
// `D_80175490` en runtime (ver hh::save::valid_points_by_level). El valor del campo es
// `idx*10 + punto`. El juego ARRANCA en el indice 1 (valor 0x0A), que muestra como "1-0": el nivel
// mostrado es `idx` (1-based). El grupo 0 (interno) no es jugable.
std::vector<std::string> progress_options() {
    int pts[30] = {0};
    hh::save::valid_points_by_level(pts);
    std::vector<std::string> out;
    for (int idx = 1; idx < 30; ++idx) {
        for (int p = 0; p < pts[idx] && p < 10; ++p) {
            out.push_back(std::to_string(idx) + "-" + std::to_string(p));
        }
    }
    if (out.empty()) out.push_back("1-0");   // guarda si la tabla no está disponible
    return out;
}
int progress_index_of(uint16_t value) {
    int pts[30] = {0};
    hh::save::valid_points_by_level(pts);
    int out = 0;
    for (int idx = 1; idx < 30; ++idx) {
        for (int p = 0; p < pts[idx] && p < 10; ++p, ++out) {
            if (value == static_cast<uint16_t>(idx * 10 + p)) return out;
        }
    }
    return 0;   // 1-0
}
// Valor N*10+P del indice `slot` del selector PROGRESO.
uint16_t progress_value_at(int slot) {
    int pts[30] = {0};
    hh::save::valid_points_by_level(pts);
    int i = 0;
    for (int idx = 1; idx < 30; ++idx) {
        for (int p = 0; p < pts[idx] && p < 10; ++p, ++i) {
            if (i == slot) return static_cast<uint16_t>(idx * 10 + p);
        }
    }
    return 0x0A;   // 1-0 por defecto
}
// Cadena "N-P" (nivel-punto) del valor N*10+P. La fuente no tiene '-': el overlay dibuja el guion.
std::string progress_label(uint16_t value) {
    return std::to_string(value / 10) + "-" + std::to_string(value % 10);
}

// Orden de las partes como las muestra el port (mapa al orden del juego en el struct):
// CABEZA, CUERPO, BRAZO IZQ, BRAZO DER, PIERNA IZQ, PIERNA DER.
const int kPartIndex[6] = {0, 1, 3, 2, 5, 4};
const char* const kPartLabels[6] = {"CABEZA", "CUERPO", "BRAZO IZQ", "BRAZO DER", "PIERNA IZQ",
                                    "PIERNA DER"};

void rebuild_save_edit();   // definida tras find_screen

// Resoluciones (sin AUTO/ORIGINAL) adecuadas a cada RATIO: AUTO/ORIGINAL(4:3)/4X3/16X9/16X10/21X9.
std::vector<std::string> ratio_resolutions(int ratio) {
    switch (ratio) {
        case 3:   // 16X9
            return {"1280x720", "1366x768", "1600x900", "1920x1080", "2560x1440", "3840x2160"};
        case 4:   // 16X10
            return {"1280x800", "1440x900", "1680x1050", "1920x1200", "2560x1600"};
        case 5:   // 21X9
            return {"2560x1080", "3440x1440", "3840x1600"};
        case 1:   // ORIGINAL (4:3 nativo)
        case 2:   // 4X3
            return {"640x480", "800x600", "1024x768", "1280x960", "1600x1200", "2048x1536"};
        default:  // AUTO: sin filtro -> unión
            return {"640x480", "800x600", "1024x768", "1280x960", "1600x1200", "2048x1536",
                    "1280x720", "1366x768", "1600x900", "1920x1080", "2560x1440", "3840x2160",
                    "1280x800", "1440x900", "1680x1050", "1920x1200", "2560x1600",
                    "2560x1080", "3440x1440", "3840x1600"};
    }
}

// Ajusta las opciones/valor de RESOLUCIÓN según el RATIO: AUTO -> AUTO, ORIGINAL -> ORIGINAL, y los
// ratios concretos dejan AUTO. Definida tras `find_screen`.
void sync_resolution();

// Rellena g_screens con el árbol acordado (orden de arriba a abajo).
void build_tree() {
    g_screens.clear();

    std::vector<Entry> root = {
        make_item("CONTINUAR", Action::Continue),
        make_submenu("NUEVA PARTIDA", Action::OpenNewGame),
        make_submenu("MODO COMBATE", Action::BattleMode),
        make_submenu("CONFIGURACIÓN", Action::OpenSettings),
    };
    // EXTRAS: solo aparece si se ha desbloqueado con el codigo Konami (arriba de SALIR).
    if (extras_unlocked()) {
        root.push_back(make_submenu("EXTRAS", Action::OpenExtras));
    }
    // SALIR: extra del port (no existe en el nativo); cierra de forma ordenada. Decidido por el
    // mantenedor (2026-09-25); ver docs/menu.md.
    root.push_back(make_item("SALIR", Action::Exit));
    g_screens.push_back(make_screen(ScreenId::Root, ScreenKind::Menu, std::move(root)));

    // NUEVA PARTIDA: iniciar la partida y elegir dificultad.
    // CÁMARA LIBRE / APUNTADO LIBRE: OCULTOS (2026-09-27) hasta que el juego los soporte (requieren
    // modificar el juego); por ahora no se muestran. La maquinaria de entradas deshabilitadas
    // (`make_selector(..., enabled=false)` + el salto de `!enabled` en move_up/move_down) se conserva
    // por si se deshabilitan otras entradas en el futuro.
    g_screens.push_back(make_screen(ScreenId::NewGame, ScreenKind::Menu, {
        make_item("EMPEZAR PARTIDA", Action::StartGame),
        make_submenu("DIFICULTAD", Action::OpenDifficulty),
    }));

    // DIFICULTAD: lista (A marca la aplicada; el resto sale en gris). La opción marcada es el valor
    // en memoria; vendrá de la config en el paso 6.
    g_screens.push_back(make_screen(ScreenId::Difficulty, ScreenKind::List, {
        make_option("DEFINITIVO"),
        make_option("DIFÍCIL"),
        make_option("NORMAL", /*marked=*/true),
    }));

    // MODO COMBATE: subpantalla recreada con nuestro menu (mismos rotulos que el original),
    // traduccida a todos los idiomas. El despacho nativo de cada entrada se cablea en el hook del
    // submenu de batalla (0x801C4200); ver docs/menu.md y notes/2026-09-27-battle-mode-recon.md.
    g_screens.push_back(make_screen(ScreenId::BattleMode, ScreenKind::Menu, {
        make_item("MODO VS", Action::BattleModeVs),
        make_item("COMBATE DE CRIATURAS", Action::BattleModeCreature),
        make_item("EDITAR DATOS", Action::BattleModeDataEdit),
    }));

    // COMBATE DE CRIATURAS: subpantalla interna (el original: 5 MATCHES / SURVIVAL, cursor 0x801CC8C8
    // en func_801C44C4). Se entra desde MODO COMBATE (nativo, cursor 1) y se sale con B (va a la raiz).
    g_screens.push_back(make_screen(ScreenId::BattleCreature, ScreenKind::Menu, {
        make_item("5 COMBATES", Action::BattleCreatureMatches),
        make_item("SUPERVIVENCIA", Action::BattleCreatureSurvival),
    }));

    // CONFIGURACIÓN: IDIOMA / GRÁFICOS / SONIDO y DEBUG al final (submenú con las opciones de depuración).
    g_screens.push_back(make_screen(ScreenId::Settings, ScreenKind::Menu, {
        make_submenu("IDIOMA", Action::OpenLanguage),
        make_submenu("GRÁFICOS", Action::OpenGraphics),
        make_submenu("SONIDO", Action::OpenSound),
        make_submenu("CONTROLES", Action::OpenControls),
        make_submenu("DEBUG", Action::OpenDebug),
    }));

    // IDIOMA: lista (INGLÉS...JAPONÉS). La opción activa es el idioma actual (negrita/verde).
    {
        Screen lang = make_screen(ScreenId::Language, ScreenKind::List, {
            make_option("INGLÉS"), make_option("ESPAÑOL"), make_option("CATALÁN"),
            make_option("FRANCÉS"), make_option("ALEMÁN"), make_option("JAPONÉS"),
        });
        static const char* kCodes[] = { "en", "es", "ca", "fr", "de", "ja" };
        const std::string cur = hh::text_current_language();
        for (size_t i = 0; i < lang.entries.size() && i < 6; ++i) {
            lang.entries[i].marked = (cur == kCodes[i]);
        }
        g_screens.push_back(std::move(lang));
    }

    // GRÁFICOS: RATIO filtra las resoluciones de RESOLUCIÓN (ambos con AUTO/ORIGINAL). El paso 6
    // aplicará los valores a RT64. Por defecto RATIO=AUTO y RESOLUCIÓN=AUTO.
    g_screens.push_back(make_screen(ScreenId::Graphics, ScreenKind::Menu, {
        make_selector_with_action("RATIO", {"AUTO", "ORIGINAL", "4:3", "16:9", "16:10", "21:9"},
                                  Action::RatioSelect, ratio_default()),
        make_selector_with_action("RESOLUCIÓN", {"AUTO", "ORIGINAL"}, Action::ResolutionSelect),
        // Los tres siguientes persisten en config.ini [video] y aplican en vivo (ver
        // feed_menu_navigation). El valor inicial sale de la config (default: borderless/SÍ/NATIVO).
        make_selector_with_action("P. COMPLETA", {"NO", "SÍ"}, Action::ToggleFullscreen,
                                  fullscreen_default()),
        make_selector_with_action("ANTIALIASING", {"x0", "x2", "x4", "x8"}, Action::MsaaSelect,
                                  msaa_default()),
        make_selector_with_action("VSYNC", {"NO", "SÍ"}, Action::ToggleVsync, vsync_default()),
        // NATIVO = refresco del monitor; un número = tasa fija (RT64 refreshRate). Orden ascendente;
        // incluye 40 (Steam Deck), 90 (Deck/VR) y 75 (monitores antiguos). Se recorta al monitor.
        make_selector_with_action("LÍMITE DE FPS",
                                  {"NATIVO", "30", "40", "60", "75", "90", "120", "144", "165", "240"},
                                  Action::FpsLimit, fps_limit_default()),
    }));

    // DEBUG: opciones de depuración (fuera de GRÁFICOS para no alargarlo).
    g_screens.push_back(make_screen(ScreenId::Debug, ScreenKind::Menu, {
        make_selector_with_action("VENTANA DEBUG", {"NO", "SÍ"}, Action::ToggleDebug,
                                  developer_default()),
        // Indicador de FPS del overlay; persiste en config.ini [video].showfps.
        make_selector_with_action("MOSTRAR FPS", {"NO", "SÍ"}, Action::ToggleShowFps,
                                  show_fps_default()),
    }));

    // EXTRAS: desbloqueado con el codigo Konami. MANTENER EXTRAS decide si el propio menu persiste
    // entre arranques; LOGOS ORIGINALES elige el set de logos de la intro por defecto. Ambos
    // persisten en config.ini [extras].
    g_screens.push_back(make_screen(ScreenId::Extras, ScreenKind::Menu, {
        // MODO HEAVEN: al poner SÍ aplica el "modo trampa" al slot del editor (niveles 99, todas las
        // habilidades, items 99). PENDIENTE: invulnerabilidad (daño 0) y que los items no se gasten
        // (parches runtime; ver RETOMAR.md).
        make_selector_with_action("MODO HEAVEN", {"NO", "SÍ"}, Action::ToggleHeavenMode, 0),
        make_selector_with_action("MANTENER EXTRAS", {"NO", "SÍ"}, Action::ToggleExtrasPersist,
                                  extras_persist_default()),
        make_selector_with_action("LOGOS ORIGINALES", {"NO", "SÍ"}, Action::ToggleOriginalLogos,
                                  original_logos_default()),
        make_submenu("EDICIÓN DE PARTIDA", Action::OpenSaveEdit),
    }));

    // CONTROLES: Stick C + tabla del mapeado (accion N64 -> binding actual de mando/teclado). La
    // lista es larga; el overlay la hace scrollear cuando no cabe en pantalla.
    g_screens.push_back(make_screen(ScreenId::Controls, ScreenKind::Menu, {
        // MOVIMIENTO: direccion del stick y/o tecla (por defecto W/S/A/D).
        make_binding("ARRIBA/ADELANTE", "axis_up"),
        make_binding("ABAJO/ATRÁS", "axis_down"),
        make_binding("IZQUIERDA", "axis_left"),
        make_binding("DERECHA", "axis_right"),
        // Etiquetas = ACCION del juego (no el boton N64); a la derecha, MANDO y TECLADO.
        make_binding("ACCIÓN/ACEPTAR", "a"),
        make_binding("MAPA/ATRÁS", "b"),
        make_binding("AGACHARSE", "z"),
        make_binding("PRIMERA PERSONA", "cdown"),
        make_binding("MENÚ", "start"),
        make_binding("APUNTAR", "r"),
        // C: solo C-arriba (altura de camara); C-abajo = PRIMERA PERSONA; C-izq/der no hacen nada.
        make_binding("ALTURA CÁMARA", "cup"),
        make_binding("MENÚ ARRIBA", "dup"),
        make_binding("MENÚ ABAJO", "ddown"),
        make_binding("MENÚ IZQUIERDA", "dleft"),
        make_binding("MENÚ DERECHA", "dright"),
        // VIBRACIÓN (encima de RESET) y RESET (abajo del todo).
        make_selector_with_action("VIBRACIÓN", {"NO", "SÍ"}, Action::ToggleVibration,
                                  vibration_default()),
        make_item("RESET", Action::ResetControls),
    }));

    sync_resolution();

    // RESOLUCIÓN: fijar el valor persistido ([video].res) si está entre las opciones del ratio.
    {
        const std::string want = hh::video_config().res;
        for (Screen& s : g_screens) {
            if (s.id != ScreenId::Graphics) continue;
            for (Entry& e : s.entries) {
                if (e.action != Action::ResolutionSelect) continue;
                for (size_t i = 0; i < e.options.size(); ++i) {
                    if (e.options[i] == want) { e.value = static_cast<int>(i); break; }
                }
            }
        }
    }

    // SONIDO: VOLUMEN general (0-100 % en pasos de 10) y SALIDA (ESTÉREO/MONO/AURICULARES). Antes
    // era la lista vanilla ESTÉREO/MONO; ahora es un menu de selectores. Ambos persisten en [audio].
    g_screens.push_back(make_screen(ScreenId::Sound, ScreenKind::Menu, {
        make_selector_with_action("VOLUMEN",
                                  {"0%", "10%", "20%", "30%", "40%", "50%", "60%", "70%", "80%",
                                   "90%", "100%"},
                                  Action::VolumeSelect, volume_default()),
        make_selector_with_action("SALIDA", {"MONO", "ESTÉREO", "AURICULARES"}, Action::OutputSelect,
                                  output_default()),
        make_selector_with_action("MENÚ SFX", {"NO", "SÍ"}, Action::MenuSfxToggle,
                                  menu_sfx_default()),
    }));

    // EDICIÓN DE PARTIDA: pantallas propias (se rellenan en rebuild_save_edit con el .pak cargado y
    // los nombres de la ROM). Vacías aquí; el contenido depende del slot seleccionado.
    g_screens.push_back(make_screen(ScreenId::SaveEdit, ScreenKind::Menu, {}));
    g_screens.push_back(make_screen(ScreenId::SaveEditAbilities, ScreenKind::Toggle, {}));
    g_screens.push_back(make_screen(ScreenId::SaveEditBody, ScreenKind::Menu, {}));
    g_screens.push_back(make_screen(ScreenId::SaveEditItems, ScreenKind::Menu, {}));
    g_screens.push_back(make_screen(ScreenId::SaveEditStats, ScreenKind::Menu, {}));
    g_screens.push_back(make_screen(ScreenId::SaveEditCombatSim, ScreenKind::Menu, {}));
    rebuild_save_edit();
}

Screen* find_screen(ScreenId id) {
    for (Screen& s : g_screens) {
        if (s.id == id) {
            return &s;
        }
    }
    return nullptr;
}

// Reconstruye las pantallas del editor con los valores ACTUALES de los globals (la partida cargada).
// Se llama al construir el árbol, al cambiar PARTIDA/ESTADO y tras GUARDAR (lo demás se refleja en el
// propio modelo). Cargar un slot en los globals lo hace `hh::save::load(slot)` (en las acciones).
void rebuild_save_edit() {
    hh::save::load();
    const int slot = g_edit_slot;

    if (Screen* s = find_screen(ScreenId::SaveEdit)) {
        std::vector<Entry> e;
        // CARGAR PARTIDA: selector < PARTIDA N >; al cambiar de valor se carga ese slot en los
        // globals (rápido: leer 0xD00 del PFS cacheado + deserializar; no arranca escena).
        // GUARDAR PARTIDA: selector < NUEVA PARTIDA / PARTIDA N >; NUEVA PARTIDA guarda en el primer
        // slot libre (al final de los usados). A ejecuta el guardado. Un hueco separa del resto.
        std::vector<std::string> slots;
        for (int i = 1; i <= hh::save::kSlots; ++i) slots.push_back("PARTIDA " + std::to_string(i));
        e.push_back(make_selector_with_action("CARGAR", slots, Action::SaveEditSlot, slot));
        std::vector<std::string> save_slots{"NUEVA PARTIDA"};
        for (int i = 1; i <= hh::save::kSlots; ++i) save_slots.push_back("PARTIDA " + std::to_string(i));
        e.push_back(make_selector_with_action("GUARDAR", save_slots, Action::SaveEditSave,
                                              g_edit_save_target));
        // ELIMINAR: mismo selector de partidas; A borra el slot elegido (se aplica al GUARDAR).
        e.push_back(make_selector_with_action("ELIMINAR", slots, Action::SaveEditDelete,
                                              g_edit_delete_target));
        // RESTAURAR: backup del slot tal como estaba al abrir el `.pak` (estado vanilla). Descarta
        // TODOS los cambios en memoria de este slot. No escribe: hay que GUARDAR después.
        e.push_back(make_item("RESTAURAR", Action::SaveEditRestore));
        e.push_back(make_item("", Action::None));   // hueco visual (fila vacía)
        // PROGRESO: lista de N-P válidos; el guion lo dibuja el overlay (la fuente no tiene '-').
        e.push_back(make_selector_with_action("PROGRESO", progress_options(),
                                              Action::SaveEditProgress,
                                              progress_index_of(hh::save::progress_of(slot))));
        // NIVEL GLOBAL: DERIVADO de los niveles de las 6 partes (func_8037865C = media redondeada
        // +1). NO se puede editar: subirlo a mano no cambia ninguna stat (ver docs/stats-partes.md).
        // Solo lectura (cursor-able, sin acción).
        const int lvl = hh::save::global_level_of(slot);
        const std::string lvl_label = "NIVEL " + std::to_string(lvl >= 1 ? lvl : 1);
        e.push_back(make_item(lvl_label.c_str(), Action::None, /*enabled=*/true));
        e.push_back(make_submenu("ATRIBUTOS", Action::OpenSaveEditCombatSim));
        e.push_back(make_submenu("ESTADO", Action::OpenSaveEditBody));   // antes "BODY"
        e.push_back(make_submenu("HABILIDADES", Action::OpenSaveEditAbilities));
        e.push_back(make_submenu("ITEMS", Action::OpenSaveEditItems));
        s->entries = std::move(e);
        if (s->cursor >= static_cast<int>(s->entries.size())) s->cursor = 0;
    }

    if (Screen* s = find_screen(ScreenId::SaveEditAbilities)) {
        std::vector<Entry> e;
        // Cabecera: selector lateral < RESET / TODO SÍ / TODO NO > (accion masiva sobre la lista;
        // RESET restaura las habilidades a como estaban al entrar, sin guardar).
        e.push_back(make_selector_with_action("HABILIDADES", {"RESET", "TODO SÍ", "TODO NO"},
                                              Action::SaveEditAbilitiesBulk, g_edit_tech_bulk));
        e.push_back(make_item("", Action::None));   // hueco visual
        for (int id = 0; id < hh::save::kTechCount; ++id) {
            e.push_back(make_toggle(hh::save::tech_name(id).c_str(), hh::save::tech_learned_of(slot, id), id,
                                    Action::None));
        }
        s->entries = std::move(e);
        if (s->cursor >= static_cast<int>(s->entries.size())) s->cursor = 0;
    }

    if (Screen* s = find_screen(ScreenId::SaveEditBody)) {
        std::vector<Entry> e;
        // ESTADO del cuerpo: SOLO los niveles de parte (OFENSIVO/DEFENSIVO), con `< NIVEL n >`. Fuera
        // HIT/DAMAGE (contadores de uso sin efecto util) y NIVEL/PROGRESO (son de ATRIBUTO, ya en
        // ATRIBUTOS). Los niveles de parte no tienen tabla: se editan en crudo.
        e.push_back(make_selector_with_action(
            "TIPO", {"OFENSIVO", "DEFENSIVO"}, Action::SaveEditBodyState, g_edit_body_state));
        // TODOS: fija las 6 partes del eje activo al nivel elegido (0..99). El valor mostrado es el
        // nivel actual más alto; izq/der lo cambian y aplican a las 6.
        int maxp = 0;
        for (int i = 0; i < 6; ++i)
            maxp = std::max(maxp, static_cast<int>(hh::save::body_stat_of(slot, kPartIndex[i],
                                                                         g_edit_body_state)));
        Entry all = make_number("TODOS", 0, 99, maxp, -1, Action::SaveEditBodyBulk);
        all.prefix = "NIVEL ";
        e.push_back(std::move(all));
        for (int i = 0; i < 6; ++i) {
            const int part = kPartIndex[i];
            Entry n = make_number(kPartLabels[i], 0, 99,
                                  hh::save::body_stat_of(slot, part, g_edit_body_state), part,
                                  Action::SaveEditBodyValue);
            n.prefix = "NIVEL ";
            e.push_back(std::move(n));
        }
        s->entries = std::move(e);
        if (s->cursor >= static_cast<int>(s->entries.size())) s->cursor = 0;
    }

    if (Screen* s = find_screen(ScreenId::SaveEditItems)) {
        std::vector<Entry> e;
        for (int id = 0; id < hh::save::kItemCount; ++id) {
            // El nombre se muestra en orden natural (S,M,L,X...); la cantidad vive en el slot de su
            // familia invertido (item_slot_of): el juego guarda S↔X, M↔L.
            const int slot_id = hh::save::item_slot_of(id);
            std::string nm = hh::save::item_name(id);   // el juego los guarda "Mayús Inicial"; a MAYÚS
            for (char& ch : nm) ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
            e.push_back(make_number(nm.c_str(), 0, 99,
                                    hh::save::item_count_of(slot, slot_id), slot_id,
                                    Action::SaveEditItem));
        }
        s->entries = std::move(e);
        if (s->cursor >= static_cast<int>(s->entries.size())) s->cursor = 0;
    }

    if (Screen* s = find_screen(ScreenId::SaveEditCombatSim)) {
        // ATRIBUTOS: cabecera NIVEL global (derivado, solo lectura); TODOS (nudge relativo ±1 a los 6
        // atributos, se resetea a 0); y una fila por atributo con `< NIVEL n >` editable (izq/der
        // aplican la tabla real, stat += incremento[nivel]) + el valor del stat (sin EXP).
        std::vector<Entry> e;
        const int gl = hh::save::global_level_of(slot);
        e.push_back(make_item(("NIVEL " + std::to_string(gl >= 1 ? gl : 1)).c_str(), Action::None,
                              /*enabled=*/true));
        e.push_back(make_item("", Action::None));   // hueco visual
        // TODOS: fija TODOS los atributos al nivel elegido (0..99). El valor mostrado es el nivel
        // actual más alto; izq/der lo cambian y aplican a los 6.
        {
            int maxl = 0;
            for (int p = 0; p < hh::save::kParts; ++p)
                maxl = std::max(maxl, static_cast<int>(hh::save::part_level_of(slot, p)));
            Entry all = make_number("TODOS", 0, hh::save::kPartLevelMax, maxl, -1,
                                    Action::SaveEditAttrBulk);
            all.prefix = "NIVEL ";
            e.push_back(std::move(all));
        }
        auto padl = [](const std::string& s, size_t n) {
            return std::string(n > s.size() ? n - s.size() : 0, ' ') + s;
        };
        struct Attr { const char* label; int part; int gstat; };
        static const Attr kAttrs[] = {
            {"HP", 0, hh::save::gHpMax},            {"RESISTENCIA", 1, hh::save::gStamina},
            {"OFENSA", 2, hh::save::gOffense},      {"DEFENSA", 3, hh::save::gDefense},
            {"REFLEJOS", 4, hh::save::gReflex},     {"VELOCIDAD", 5, hh::save::gSpeed},
        };
        for (const Attr& a : kAttrs) {
            Entry n = make_number(a.label, 0, hh::save::kPartLevelMax,
                                  hh::save::part_level_of(slot, a.part), a.part,
                                  Action::SaveEditAttrLevel);
            n.prefix = "NIVEL ";
            // Valor del stat, rellenado a la izquierda: el overlay lo dibuja en columna FIJA -> los
            // dígitos quedan alineados aunque el stat tenga 1/2/3/4 cifras.
            n.suffix = padl(std::to_string(hh::save::global_stat_of(slot, a.gstat)), 5);
            e.push_back(std::move(n));
        }
        s->entries = std::move(e);
        if (s->cursor >= static_cast<int>(s->entries.size())) s->cursor = 0;
    }
}

// Ajusta las opciones/valor de RESOLUCIÓN al RATIO: AUTO -> AUTO, ORIGINAL -> ORIGINAL, y los ratios
// concretos dejan las resoluciones de ese ratio con AUTO seleccionado.
void sync_resolution() {
    Screen* g = find_screen(ScreenId::Graphics);
    if (g == nullptr) {
        return;
    }
    Entry* ratio = nullptr;
    Entry* res = nullptr;
    for (Entry& e : g->entries) {
        if (e.action == Action::RatioSelect) {
            ratio = &e;
        }
        else if (e.action == Action::ResolutionSelect) {
            res = &e;
        }
    }
    if (ratio == nullptr || res == nullptr) {
        return;
    }
    std::vector<std::string> opts = {"AUTO", "ORIGINAL"};
    for (const std::string& v : ratio_resolutions(ratio->value)) {
        opts.push_back(v);
    }
    res->options = std::move(opts);
    // ORIGINAL -> ORIGINAL; AUTO -> AUTO; ratio concreto -> la resolución MÍNIMA de su lista (índice 2).
    res->value = (ratio->value == 1) ? 1 : (ratio->value == 0 ? 0 : 2);
}

Screen* top() {
    if (g_stack.empty()) {
        return nullptr;
    }
    return find_screen(g_stack.back());
}

// Índice de la entrada HABILITADA siguiente (dir=+1) o anterior (dir=-1) al cursor `from`,
// envolviendo. Salta las entradas `!enabled` (p. ej. CÁMARA/APUNTADO LIBRE). Devuelve -1 si no hay
// ninguna habilitada (guarda). Si solo hay una habilitada y es la actual, devuelve esa misma.
int step_enabled(const Screen& s, int from, int dir) {
    const int n = static_cast<int>(s.entries.size());
    if (n == 0) {
        return -1;
    }
    int i = from;
    for (int k = 0; k < n; ++k) {
        i += dir;
        if (i < 0) i = n - 1;
        if (i >= n) i = 0;
        const Entry& e = s.entries[i];
        if (e.enabled && !e.label.empty()) {   // salta deshabilitadas y filas-hueco (label vacío)
            return i;
        }
    }
    return -1;
}

void ensure() {
    if (g_screens.empty()) {
        reset();
    }
}

bool screen_for(Action action, ScreenId& out) {
    switch (action) {
        case Action::OpenNewGame:    out = ScreenId::NewGame;    return true;
        case Action::OpenDifficulty: out = ScreenId::Difficulty; return true;
        case Action::OpenSettings:   out = ScreenId::Settings;   return true;
        case Action::OpenLanguage:   out = ScreenId::Language;   return true;
        case Action::OpenGraphics:   out = ScreenId::Graphics;   return true;
        case Action::OpenSound:      out = ScreenId::Sound;      return true;
        case Action::OpenDebug:      out = ScreenId::Debug;      return true;
        case Action::OpenExtras:     out = ScreenId::Extras;     return true;
        case Action::OpenControls:   out = ScreenId::Controls;   return true;
        case Action::OpenSaveEdit:          out = ScreenId::SaveEdit;          return true;
        case Action::OpenSaveEditAbilities: out = ScreenId::SaveEditAbilities; return true;
        case Action::OpenSaveEditBody:      out = ScreenId::SaveEditBody;      return true;
        case Action::OpenSaveEditItems:     out = ScreenId::SaveEditItems;     return true;
        case Action::OpenSaveEditStats:     out = ScreenId::SaveEditStats;     return true;
        case Action::OpenSaveEditCombatSim: out = ScreenId::SaveEditCombatSim; return true;
        case Action::BattleMode:     out = ScreenId::BattleMode; return true;
        default:                     return false;
    }
}

}  // namespace

void reset() {
    build_tree();
    g_stack.clear();
    g_stack.push_back(ScreenId::Root);
}

const Screen& current_screen() {
    ensure();
    const Screen* s = top();
    if (s == nullptr) {
        return g_screens.front();
    }
    return *s;
}

const Screen* screen(ScreenId id) {
    ensure();
    return find_screen(id);
}

void push(ScreenId id) {
    ensure();
    if (find_screen(id) == nullptr) {
        return;
    }
    g_stack.push_back(id);
}

int depth() {
    ensure();
    return static_cast<int>(g_stack.size());
}

const Layout& layout() {
    return g_layout;
}

std::string localized(const std::string& label) {
    if (label.empty()) return label;
    // Endónimos de la lista IDIOMA: fijos (no se traducen).
    for (const Endonym& e : kEndonyms) {
        if (label == e.es) return e.shown;
    }
    const std::string& c = hh::text_current_language();
    int lang = 0;   // 0=es, 1=en, 2=ca, 3=fr, 4=de, 5=ja
    if (c == "en") lang = 1;
    else if (c == "ca") lang = 2;
    else if (c == "fr") lang = 3;
    else if (c == "de") lang = 4;
    else if (c == "ja") lang = 5;
    for (const MenuTr& t : kMenuTr) {
        if (label != t.es) continue;
        switch (lang) {
            case 1: return t.en;
            case 2: return t.ca;
            case 3: return t.fr;
            case 4: return t.de;
            case 5: return t.ja;
            default: return t.es;
        }
    }
    return label;
}

Event move_up() {
    ensure();
    Screen* s = top();
    if (s == nullptr || s->entries.empty()) {
        return Event::None;
    }
    const int c = step_enabled(*s, s->cursor, -1);
    if (c < 0 || c == s->cursor) {
        return Event::None;
    }
    s->cursor = c;
    return Event::Move;
}

Event move_down() {
    ensure();
    Screen* s = top();
    if (s == nullptr || s->entries.empty()) {
        return Event::None;
    }
    const int c = step_enabled(*s, s->cursor, +1);
    if (c < 0 || c == s->cursor) {
        return Event::None;
    }
    s->cursor = c;
    return Event::Move;
}

Event move_left() {
    ensure();
    Screen* s = top();
    if (s == nullptr || s->entries.empty()) {
        return Event::None;
    }
    Entry& e = s->entries[s->cursor];
    if (e.kind == Kind::Number) {
        const int v = e.value - e.step;
        if (v < e.min || v == e.value) {
            return Event::None;
        }
        e.value = v;
        return Event::Move;
    }
    if (e.kind != Kind::Selector || e.options.empty()) {
        return Event::None;
    }
    const int n = static_cast<int>(e.options.size());
    const int v = (e.value - 1 + n) % n;
    if (v == e.value) {
        return Event::None;
    }
    e.value = v;
    if (e.action == Action::RatioSelect) {
        sync_resolution();
    }
    return Event::Move;
}

Event move_right() {
    ensure();
    Screen* s = top();
    if (s == nullptr || s->entries.empty()) {
        return Event::None;
    }
    Entry& e = s->entries[s->cursor];
    if (e.kind == Kind::Number) {
        const int v = e.value + e.step;
        if (v > e.max || v == e.value) {
            return Event::None;
        }
        e.value = v;
        return Event::Move;
    }
    if (e.kind != Kind::Selector || e.options.empty()) {
        return Event::None;
    }
    const int n = static_cast<int>(e.options.size());
    const int v = (e.value + 1) % n;
    if (v == e.value) {
        return Event::None;
    }
    e.value = v;
    if (e.action == Action::RatioSelect) {
        sync_resolution();
    }
    return Event::Move;
}

Event confirm() {
    ensure();
    Screen* s = top();
    if (s == nullptr || s->entries.empty()) {
        return Event::None;
    }
    Entry& e = s->entries[s->cursor];
    if (!e.enabled) {
        return Event::None;
    }
    // Lista de toggles (HABILIDADES): A alterna la marca de esa fila sin tocar las demás.
    if (s->kind == ScreenKind::Toggle) {
        e.marked = !e.marked;
        return Event::Accept;
    }
    // Lista: A marca la opción resaltada (la activa pasa a ser esa).
    if (s->kind == ScreenKind::List) {
        for (Entry& x : s->entries) {
            x.marked = false;
        }
        e.marked = true;
        return Event::Accept;
    }
    // Fila numérica: A incrementa (envuelve al llegar al máximo).
    if (e.kind == Kind::Number) {
        e.value = (e.value >= e.max) ? e.min : e.value + e.step;
        return Event::Move;
    }
    // Submenú: A entra.
    if (e.kind == Kind::Submenu) {
        ScreenId child;
        if (screen_for(e.action, child)) {
            g_stack.push_back(child);
            return Event::Accept;
        }
        return Event::None;
    }
    // Item (acción), selector y fila de mapeado: el modelo solo lo señala; la ejecución es del paso 6.
    if (e.kind == Kind::Item || e.kind == Kind::Selector || e.kind == Kind::Binding) {
        return Event::Accept;
    }
    return Event::None;
}

Event back() {
    ensure();
    if (g_stack.size() <= 1) {
        return Event::None;  // la raíz no tiene "atrás"
    }
    g_stack.pop_back();
    return Event::Back;
}

void debug_show(int screen_id) {
    ensure();
    if (screen_id < 0 || screen_id > static_cast<int>(ScreenId::SaveEditItems)) {
        return;
    }
    const ScreenId id = static_cast<ScreenId>(screen_id);
    g_stack.clear();
    g_stack.push_back(ScreenId::Root);
    if (id != ScreenId::Root) {
        g_stack.push_back(id);
    }
    if (Screen* s = find_screen(id)) {
        s->cursor = 0;
    }
}

std::string describe_current() {
    ensure();
    const Screen* s = top();
    if (s == nullptr) {
        return "(sin pantalla)";
    }
    static const char* kKindName[] = {"Menu", "List", "Toggle"};
    std::string out = "screen=" + std::to_string(static_cast<int>(s->id)) +
                      " kind=" + kKindName[static_cast<int>(s->kind)] +
                      " cursor=" + std::to_string(s->cursor) + "\n";
    for (size_t i = 0; i < s->entries.size(); ++i) {
        const Entry& e = s->entries[i];
        out += (static_cast<int>(i) == s->cursor) ? "> " : "  ";
        out += e.label;
        if (e.kind == Kind::Selector && !e.options.empty()) {
            out += " < " + e.options[e.value] + " >";
        }
        if (e.kind == Kind::Binding) {
            out += " : " + e.binding;
        }
        if (e.marked) {
            out += " [x]";
        }
        if (!e.enabled) {
            out += " (gris)";
        }
        out += "\n";
    }
    return out;
}

// Desbloqueo por CODIGO de la sesion (sin el ajuste MANTENER EXTRAS).
bool extras_code_unlocked() {
    return g_extras_unlocked_state;
}

// Visible si se tecleo el codigo en esta sesion o si MANTENER EXTRAS esta en SI (persistencia
// explicita).
bool extras_unlocked() {
    return g_extras_unlocked_state || hh::extras_config().persist == "si";
}

void unlock_extras() {
    if (g_extras_unlocked_state) return;
    g_extras_unlocked_state = true;
    // Rehace la raiz para que aparezca la entrada EXTRAS (el arbol se construyo sin ella). Seguro:
    // el desbloqueo ocurre durante la intro, antes de usar el menu. El desbloqueo por codigo es de
    // sesion; si ADEMAS MANTENER EXTRAS esta en SI, el menu reaparece solo en el siguiente arranque.
    reset();
}

std::string describe_tree() {
    ensure();
    std::string out;
    for (const Screen& s : g_screens) {
        out += "== screen " + std::to_string(static_cast<int>(s.id)) + " ==\n";
        for (const Entry& e : s.entries) {
            out += "  " + e.label;
            if (e.kind == Kind::Selector && !e.options.empty()) {
                out += " < " + e.options[e.value] + " >";
            }
            if (e.kind == Kind::Binding) {
                out += " : " + e.binding;
            }
            if (!e.enabled) {
                out += " (gris)";
            }
            out += "\n";
        }
    }
    return out;
}

// --- EDICIÓN DE PARTIDA: API pública -----------------------------------------------------------------
int save_edit_slot() { return g_edit_slot; }
void set_save_edit_slot(int slot) {
    g_edit_slot = (slot < 0 || slot >= hh::save::kSlots) ? 0 : slot;
}
int save_edit_save_target() { return g_edit_save_target; }
void set_save_edit_save_target(int t) {
    g_edit_save_target = (t < 0 || t > hh::save::kSlots) ? 0 : t;
}
int save_edit_delete_target() { return g_edit_delete_target; }
void set_save_edit_delete_target(int t) {
    g_edit_delete_target = (t < 1 || t > hh::save::kSlots) ? 1 : t;
}
int save_edit_delete_slot() { return g_edit_delete_target - 1; }   // slot real 0..N-1
// Slot real destino del guardado: target 0 (NUEVA PARTIDA) = primer hueco libre (el usado más bajo
// que esté vacío, o el último slot si todos tienen datos); target 1..N = ese slot.
int save_edit_save_target_slot() {
    if (g_edit_save_target >= 1 && g_edit_save_target <= hh::save::kSlots) {
        return g_edit_save_target - 1;
    }
    for (int i = 0; i < hh::save::kSlots; ++i) {
        if (!hh::save::slot_used(i)) return i;
    }
    return hh::save::kSlots - 1;
}
int save_edit_body_state() { return g_edit_body_state; }
void set_save_edit_body_state(int state) {
    g_edit_body_state = (state < 0 || state > 1) ? 0 : state;
}

uint16_t save_edit_progress_value(int index) { return progress_value_at(index); }
void capture_tech_baseline() {
    for (int id = 0; id < hh::save::kTechCount; ++id) {
        g_tech_baseline[id] = hh::save::tech_learned_of(g_edit_slot, id) ? 1 : 0;
    }
    g_tech_baseline_valid = true;
    g_edit_tech_bulk = 0;   // el selector vuelve a SIN CAMBIOS tras una carga
}
void restore_tech_baseline(int id) {
    if (!g_tech_baseline_valid || id < 0 || id >= hh::save::kTechCount) return;
    hh::save::set_tech_learned_of(g_edit_slot, id, g_tech_baseline[id] != 0);
}
void set_save_edit_tech_bulk(int mode) {
    g_edit_tech_bulk = (mode < 0 || mode > 2) ? 0 : mode;
}
void refresh_save_edit() { rebuild_save_edit(); }

}  // namespace hh::menu
