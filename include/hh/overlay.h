#pragma once

// hh_overlay — overlay 2D del port dibujado con el RENDER HOOK de RT64 (plume). A2, Fase A.
//
// El overlay NO usa GBI: se dibuja al final del frame, sobre el framebuffer del swapchain ya
// compuesto por el VI renderer de RT64 (ver RETOMAR.md y notes/2026-09-23-a2-overlay-primer-paso.md).
// Flujo: hh_menu -> hh_overlay (paneles + texto con el atlas de la fuente del juego).

#include "hh/font.h"

#include <cstdint>
#include <string>
#include <vector>

namespace hh::overlay {

// Espacio de coordenadas del overlay: resolucion virtual (px, origen arriba-izquierda). El draw
// hook la escala al framebuffer del swapchain. 320x240 = resolucion interna del juego.
inline constexpr float kVirtualWidth = 320.0f;
inline constexpr float kVirtualHeight = 240.0f;

// Color RGBA empaquetado (R en el byte bajo), como lo espera el vertex format R8G8B8A8_UNORM.
inline constexpr uint32_t rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    return uint32_t(r) | (uint32_t(g) << 8) | (uint32_t(b) << 16) | (uint32_t(a) << 24);
}

// Rectangulo solido (panel/fondo/cursor), en unidades virtuales.
struct Panel {
    float x = 0.0f, y = 0.0f, w = 0.0f, h = 0.0f;
    uint32_t color = 0xFFFFFFFFu;
};

// Texto con la fuente del juego. `scale_x`/`scale_y` 1.0 = glifo a su tamaño nativo (8x8 virtual);
// se separan para poder igualar el aspecto del texto del juego (que no va estirado a 16:9).
struct Text {
    float x = 0.0f, y = 0.0f;
    float scale_x = 1.0f, scale_y = 1.0f;
    uint32_t color = 0xFFFFFFFFu;
    std::string text;
    // Tipografia (fichero Nisitenma). El DATA LOAD nativo usa color3 (titulo), color4 (mensaje) y
    // color0 (filas/atlas historico del menu). Ver include/hh/font.h y
    // notes/2026-09-30-tipografias-data-load-hallazgos.md.
    hh::font::game::Face face = hh::font::game::Face::Color0;
};

// Texto con la fuente Work Sans embebida (SIL OFL-1.1): para el título del Área traducido. `x`/`y` en
// unidades virtuales; `y` es la LÍNEA BASE. `scale` 1.0 = px del atlas de la fuente (rasterizada a
// ~22 px); 0.5 = ~11 px virtuales.
struct TtfText {
    float x = 0.0f, y = 0.0f;
    float scale = 0.5f;      // escala horizontal (y vertical si scale_y == 0)
    float scale_y = 0.0f;    // escala vertical independiente (0 = usar `scale`); estira el ALTO
    float tracking = 0.0f;   // espaciado extra entre letras (unidades virtuales)
    float word_space = 0.0f; // espaciado extra ADICIONAL tras cada espacio (unidades virtuales)
    uint32_t color = 0xFFFFFFFFu;
    std::string text;
};

// Contenido de un frame. El menú lo publica (game thread) y el draw hook lo dibuja (render thread).
struct Frame {
    bool visible = false;
    std::vector<Panel> panels;
    std::vector<Text> texts;
    std::vector<TtfText> ttf_texts;   // Work Sans (título del Área traducido)
};

// Publica el frame a dibujar. Thread-safe (copia bajo mutex). Llamar cada frame desde el menú.
void publish(Frame frame);

// Mantiene el último frame publicado al menos `ms` ms ADICIONALES aunque no se vuelva a publicar (se
// usa para el título del Área: tras la transición no hay más publicaciones, pero hay que seguir
// tapando el nombre nativo hasta que arranca el gameplay). Se extiende con cada llamada.
void hold_ms(int ms);
long hold_remaining_ms();   // ms que quedan de hold (0 si no hay)

// true si el overlay está activo (HH_OVERLAY!=0). El menú PC lo usa para decidir si toma el control
// total del menú de título (neutralizando el input del handler nativo); con el overlay desactivado,
// el menú nativo sigue respondiendo a los botones.
bool enabled();

// Capa de IMAGEN a pantalla completa (logos de la intro, etc.): carga un PNG (RGBA8) y lo dibuja
// cubriendo el framebuffer con aspecto "contain" (letterbox si no coincide). Es independiente del
// frame del menú (puede estar visible sola). La carga real ocurre en el hilo de render (seguro);
// esta llamada solo encola la petición. Llamar desde el hilo del juego.
// `black_bg`: la imagen trae fondo NEGRO (logos modernos) -> la tarjeta se pinta negra y rellena
// los laterales en negro; si es false, la tarjeta es blanca (logos clasicos).
void set_screen_image(const std::string& png_path, bool black_bg = false);
void clear_screen_image();

// Precarga el PNG (lo sube a textura) SIN mostrarlo, para que el primer fade-in no se pierda
// mientras se decodifica el PNG (evita que el logo aparezca a mitad de fundido).
void preload_screen_image(const std::string& png_path, bool black_bg = false);

// Composicion de la capa de imagen: NEGRO base + TARJETA BLANCA OPACA + logo + VELO NEGRO de fundido.
// `set_screen_image_alpha` fija el alfa (0..255) del logo (crossfade KONAMI<->KCEO) y el nivel del
// grupo (`fade`; 255 = sin velo, 0 = negro). `fade_out_screen_image` baja el velo durante `ms` y
// luego limpia la imagen (animado por el hilo de render); el logo no se toca.
void set_screen_image_alpha(int logo_alpha, int fade_alpha);
void fade_out_screen_image(int ms);

// Funde a negro el TEXTO del frame del menú/título durante `ms` y, al terminar, oculta el frame. Los
// paneles (telón negro) se quedan opacos para no destapar el título nativo de detrás. Lo anima el hilo
// de render (tras la transición del título ya no se publican frames), así que sirve para el fade-out
// del título del Área.
void fade_out_menu(int ms);

// Flash blanco a pantalla completa (p. ej. al desbloquear EXTRAS con el codigo Konami): pinta un
// velo blanco que arranca al maximo y se desvanece durante `ms`. Lo anima el hilo de render.
void flash_white(int ms);

// Telon NEGRO opaco a pantalla completa, independiente de la capa de imagen. Se activa al arrancar
// para tapar los logos NATIVOS del boot (file 8) que se pintan antes de que empiece nuestra fase de
// logos (file 055); se retira al terminar la intro. Auto-off de seguridad a los 30 s.
void set_screen_blackout(bool enabled);

// Indicador de FPS (menú DEBUG -> MOSTRAR FPS): texto de SOLO NÚMEROS en la esquina superior
// izquierda. Es una capa independiente del frame del menú (lo dibuja el render hook siempre que
// esté activo, también en gameplay). Se llama por frame desde el hilo de render.
void set_fps_indicator(bool enabled, int fps);

// Indicador del CICLO DE PUNTOS (diagnóstico): muestra "idx=<n>" en la esquina superior izquierda,
// debajo del FPS. Independiente del frame del menú (se ve también en gameplay).
void set_cycle_indicator(bool enabled, int idx);

// Nº de frames realmente PRESENTADOS (una vez por draw del render hook, es decir, por frame que
// llega al swapchain, incluidos los interpolados). Lo usa el indicador de FPS para medir la tasa
// real de presentación (no la de update_screen, que corre a la tasa VI).
uint64_t presented_frames();

// Ancho VISIBLE en unidades virtuales según el aspecto real (240 * ancho/alto): 320 en 4:3, ~427 en
// 16:9. Lo fija el draw hook (render thread) y lo consulta el título del Área (game thread) para
// decidir si partir el nombre en dos líneas. `visible_width()` devuelve el último valor conocido.
void set_visible_width(float vw);
float visible_width();

// Registra los render hooks de RT64 (init/draw/deinit). OJO: el hook `init` se invoca DENTRO de
// `Application::setup()`, asi que hay que llamar a esto ANTES de crear/configurar la aplicacion
// RT64 (ver RT64Context, como en Goemon). Idempotente.
void register_hooks();

}  // namespace hh::overlay
