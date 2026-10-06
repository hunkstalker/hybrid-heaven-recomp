#pragma once

// Subtítulos de las secuencias sin texto del juego (intro/prólogo y, más adelante, final).
//
// El texto NO está en la ROM (son escenas de voz): se aporta en
//   assets/subtitles/<name>.timing.txt   (tiempos, única fuente para todos los idiomas)
//   assets/lang/subtitles_<lang>.txt     (textos por idioma, clave = <name>.<id>)
// y se dibuja con la capa propia del overlay (`hh::overlay::set_subtitle`) con la tipografía del
// diálogo in-game (Face::Color4).
//
// El reloj se ancla a un contador de VI del juego (`hh_get_vi_count`, ~60 Hz) para no depender del
// wall-clock. Para el desarrollo se ancla a EMPEZAR PARTIDA (`begin`); más adelante se re-ancla al
// inicio real de la escena con `anchor_now()` (evita la varianza de carga entre PCs).
//
// Formato `timing.txt` (líneas `#`/vacías ignoradas):
//     id  in_ms  out_ms
// Formato `subtitles_<lang>.txt` (líneas `clave=valor`, escapes `\n`/`\t`/`\\`):
//     <name>.<id>=texto
//
// Knobs: HH_SUBTITLES=0 desactiva (override del menú); HH_SUB_TRACE=1 traza líneas y ancla.

#include <string>

namespace hh::subtitles {

// Carga config/idioma. Idempotente.
void init();

bool enabled();

// Activa/desactiva la capa en caliente (menú GRÁFICOS -> SUBTÍTULOS INTRO). Al desactivar, oculta lo
// publicado; si se reactiva durante una secuencia, vuelve a publicar en el siguiente `tick()`.
void set_enabled(bool on);

// Empieza la secuencia `name`: carga sus datos y ARMA el ancla (aún no visible). El reloj se ancla
// cuando `notify_scene()` ve la escena objetivo (el inicio real de la cinemática, una vez cargada).
void begin(const std::string& name);

// Desde el hook por-frame: informa de la escena actual. Si estamos armados y es la escena objetivo
// (0x104 = prólogo), marca que la escena ya está activa (el ancla se fija al terminar su carga).
void notify_scene(uint16_t scene);

// Desde el loader `trans`: informa de una carga de módulo. El ancla se fija al terminar la SEGUNDA
// oleada de cargas (la escena de contenido, que coincide con la campanada), tras un hueco largo sin
// cargas: es un evento de código determinista (absorbe la varianza de carga entre PCs).
void notify_load();

// Re-ancla el reloj al VI actual.
void anchor_now();

// Cancela (skip/fin): oculta y desactiva.
void stop();

// Avanza el reloj y publica la línea activa. Llamar una vez por frame (hilo del juego).
void tick();

bool active();

}  // namespace hh::subtitles
