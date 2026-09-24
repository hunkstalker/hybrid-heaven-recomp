#pragma once

// hh_config_ini — lectura/escritura puntual de `config.ini` preservando el resto del fichero.
// Lo usa el port para persistir preferencias ([video] del menú GRÁFICOS; [lang] del idioma).

#include <string>
#include <utility>
#include <vector>

namespace hh {

// Ruta de config.ini: HH_PAD_CONFIG si está definido; si no, `config.ini` (junto al .exe).
std::string config_ini_path();

// Fija `clave = valor` en `[seccion]` (crea la sección y el fichero si faltan), preservando el
// resto del contenido y el orden de las claves. Compara secciones/claves sin distinguir mayúsculas.
void config_ini_set(const std::string& section,
                    const std::vector<std::pair<std::string, std::string>>& keys);

// Valor de `clave` en `[seccion]` (recortado); cadena vacía si no existe.
std::string config_ini_get(const std::string& section, const std::string& key);

}  // namespace hh
