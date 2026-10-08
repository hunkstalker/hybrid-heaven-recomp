# 2026-10-07 — Experimento: extender el límite de caracteres del diálogo

> Rama **`experimento-limites-texto`**. Objetivo: poder aplicar los textos **extendidos** del
> mantenedor (los que no caben en el presupuesto A+). Datos de prueba: `assets/dialogos.txt`.

## 1. Hallazgos (medidos)

- **Presupuesto A+** = bytes del mensaje inglés. De los **215 mensajes** de los módulos 12-17, solo
  **15 exceden**; el exceso total es **~186 B** (ES) / 144 B (CA). No es un problema de tamaño, sino
  **estructural**.
- Los "gaps" entre mensajes son **opcodes y punteros** (`f0/f3` salto, `f8` espera, `fa/fe` fin,
  `fd` fin, `f9/fc`, `ff ff ff ff` y punteros), **no espacio libre**.
- El texto va en **nodos contiguos** por módulo (p. ej. mod12: `0x340C..0x4DB6`); **tras el bloque hay
  más script** (kana `A7xx`), así que no hay hueco libre al final.
- Los nodos se **encadenan con punteros absolutos** (p. ej. nodo `0x33F0` → `+08 = 0x80244034`) y la
  conversación **se entra por una tabla en otro módulo** (`0x803884B8`). Ver
  `notes/2026-10-06-dialogos-estructura-nodos-y-a-plus.md`.
- El port **controla la carga** (`hh_trans_load`, `src/subsystems/trans_cache.cpp`): escribe el módulo
  descomprimido + traducido en RDRAM en `dst` (buffer **del juego**, tamaño fijo = `len`). No se puede
  escribir más allá de `len` sin pisar otros datos.

## 1bis. Etapa 1 (offline) — resultados (medidos)

Herramienta `tools/text/analyze_dialogue_nodes.py`. Para el **módulo 12**:

- **15 nodos** detectados por el patrón `f0 00 fc 00 00 00 00 00` (13 `fc` opcodes).
- Opcodes: `f0/f3` salto, `f8` espera, `fa/fe` fin de mensaje, `fc` inicio de nodo, `fd` fin.
- **Referencias reales** (filtrando por **cabecera de nodo EXACTA**, no por rango): **6 internas**
  (cadena `+08` dentro del módulo) + **7 externas** = 1 en **mod11** y **6 en mod55** (direcciones
  consecutivas → **tabla de entrada** de la conversación).
- El filtro por **rango** produce ~2.200 falsos positivos; el **exacto**, ninguno. → El parcheo debe
  hacerse **solo** sobre valores iguales a una cabecera de nodo conocida.
- Los módulos cargan en **direcciones fijas** (las tablas guardan punteros absolutos `0x8024xxxx`
  horneados), lo que hace viable el remapeo.

## 2. Vía para extender (ruta B revisitada, en runtime)

1. Reservar una **arena guest** en RDRAM libre (~1-4 KB bastan para el exceso real).
2. En la carga del módulo de diálogo, **copiar el bloque de texto a la arena**, repartiéndolo con los
   textos extendidos (sin límite por mensaje).
3. **Remapear todos los punteros de 4 bytes de RDRAM** que apunten al bloque antiguo → nuevo, usando
   un mapa `old_off → new_off`. Esto parchea **la tabla externa y la cadena de nodos sin conocer sus
   direcciones** (barrido de RDRAM; los valores `0x8024xxxx` no colisionan con pares EUC `0xA1xx..`).
4. Mantener el módulo en `dst` (solo se mueve el bloque de texto).

## 3. Riesgos / pendiente

- Localizar **RDRAM libre** para la arena (o usar el asignador del juego).
- Evitar **falsos positivos** al escanear punteros (candidato: restringir al rango del bloque y
  comprobar alineación).
- **Validación in-game** (mantenedor): la lógica del guion y el re-flow dependen del motor del juego.

## 4. Plan de implementación (propuesto)

Algoritmo (por módulo de diálogo, tras la traducción):
1. Detectar nodos (patrón `f0 00 fc 00`) y el rango del bloque `[ini, fin)`.
2. Copiar el bloque a una **arena guest** repartiéndolo: los mensajes traducidos (posiblemente más
   largos) desplazan el resto; los **opcodes se conservan**.
3. Construir el mapa `old_off → new_off` de cada **cabecera de nodo**.
4. **Remapear** en TODA la RDRAM (y en el bloque copiado) toda palabra de 4 B que sea **exactamente**
   una cabecera de nodo antigua → nueva. Esto parchea la cadena `+08` y las tablas externas
   (mod11/mod55) sin conocerlas.
5. Si algo no cuadra → **abortar y dejar A+** (sin cambios).

- Nueva función `hh_text_relocate_dialogues(rdram, dst, len)`; flag **`HH_DLG_ARENA=1`** (off por
  defecto) y traza `[dlg] arena ...`.
- **Arena**: reservar RDRAM libre (medir; candidato: zona alta libre) o enganchar el asignador.
- Criterio de salida: los 15 mensajes extendidos se ven completos en Windows sin romper la escena.

## 5. Etapa 2 (dry-run) — HECHA

- `src/subsystems/trans_cache.cpp`: `dlg_arena_probe()` al cargar cada módulo; con `HH_DLG_ARENA=1`
  detecta nodos y refs exactas y escribe una línea `[dlg] src=... dst=... nodos=N refs internas=...
  externas=...` en `hh.log`. **No modifica nada** (off por defecto).
- Compila en Linux.
- **Validación (Windows)**: arrancar con `HH_DLG_ARENA=1`, llegar a un diálogo y comprobar en `hh.log`
  que aparecen las líneas `[dlg]` con el nº de nodos y refs esperados (módulo 12: 15 nodos, refs
  internas + externas). Sin el flag no se escribe nada.

## 6. Etapa 3a (relocalización byte-idéntica) — HECHA

- `dlg_arena_relocate()` (`trans_cache.cpp`): para el **módulo 12** (`src=0x00599670`), con
  `HH_DLG_ARENA=1`:
  1. bloque `[0x33F0, 0x4DCC)` (6620 B) leído de RDRAM;
  2. **arena** = última región de ceros de RDRAM ≥ bloque + 4 KB (si no hay, aborta y deja A+);
  3. copia el bloque a la arena **remapeando** los punteros internos a cabeceras de nodo;
  4. **parchea en toda la RDRAM** las referencias exactas a cabeceras de nodo (internas + externas);
  5. verifica y loguea `[dlg] arena=... blen=... hdrs=... refs_parcheadas=... verifica=OK/FALLO`.
- **No cambia el texto** (byte-idéntico): valida el mecanismo arena + remapeo.
- Compila en Linux.

### Validación (Windows)
- `HH_DLG_ARENA=1` → llegar al primer diálogo (Mr. Diaz). Debe verse **igual** que sin el flag.
- Mirar `hh.log`: línea `[dlg] arena=... refs_parcheadas=... verifica=OK`.
- Si se rompe/crashea → quitar el flag (vuelve a A+); reportar la línea `[dlg]` para iterar.

## 6bis. Fragilidad ante transiciones (warp) y rediseño reload-safe

- **Observado**: con `HH_DLG_ARENA=1`, el **"viajar por niveles"** (warp) **crashea**; sin el flag, no.
  Causa: el warp recarga/descarga módulos y reutiliza RDRAM; la arena/punteros de la Etapa 3a/3b
  quedaban colgando (y `dlg_apply_pending` re-parcheaba tablas a una arena vieja).
- **Rediseño (reload-safe)**:
  - **Arena persistente por módulo** (`g_arena`): misma dirección en cada carga → las tablas externas
    siguen válidas tras recargas.
  - **Re-parcheo en cada carga** (se quitó el flag `done`): al recargar, el módulo trae los punteros
    originales y se vuelven a parchear a la arena persistente.
  - **Arena preferente**: el hueco tras el propio módulo (misma franja de asignación) si está a cero;
    si no, la última región de ceros. Es más estable que una zona global.
  - `g_dlg_remap` como mapa (sin duplicados); `dlg_apply_pending` parchea tablas cargadas después.
- **Riesgo residual**: si el juego reutiliza el hueco elegido mientras el módulo está cargado, la
  arena podría corromperse. A validar con el warp.
- Reclamar el relleno del bloque **no** es viable: los "ceros" son **opcodes con parámetros**, no
  huecos libres (analizado en mod17).

## 6quater. In-situ — PROBADO Y DESCARTADO

- Se probó rehacer el bloque **in situ** (sin arena; el rebuild encoge, cabe en su sitio). **Crashea
  en el primer diálogo**: al sobrescribir el bloque, cualquier referencia que NO parchemos (p. ej. a
  posiciones de **texto**, no solo a cabeceras de nodo) apunta a **basura** → crash.
- La **arena es más tolerante**: el bloque viejo queda **intacto**, así que una referencia no
  parcheada simplemente lee el texto antiguo (no crashea).
- **Revertido** (commit de revert). Se mantiene la **arena persistente reload-safe**.

## 6quinquies. Robustez ante warp: log de deshacer + detección de pisada

- **Causa medida** (log Windows): la arena quedó en `0x8025FD28` (dentro de los 4 MB del juego) y tras
  el warp **un módulo se cargó justo ahí**, pisándola; la tabla seguía apuntando a la arena vieja →
  crash. El juego solo conoce **4 MB** (`osGetMemSize=0x400000`), así que la mitad alta la usa RT64.
- **Solución**: como arena y diálogo no se usan a la vez, se puede "hacer swap":
  - **Log de deshacer** (`g_dlg_patches`): se registra cada parche `(addr, oldv, newv)`.
  - **Detección de pisada**: si una carga de módulo empieza dentro del rango de la arena
    (`g_dlg_arena_start/end`), se **deshacen** los parches (se restaura la tabla) y se limpia el remap
    → nada apunta a la arena vieja.
  - Al **recargar** el módulo de diálogo se relocaliza a una **arena nueva** y se re-parchea.
  - `dlg_undo_patches` también se llama al inicio de cada relocalización (estado limpio).

## 7. Etapa 3b (textos extendidos en la arena) — HECHA

- **Tabla a nivel de mensaje** `assets/lang/<code>.dlg.txt` (clave = líneas inglesas unidas con
  espacio; valor = traducción completa, sin límite). Generada desde `assets/dialogos.txt`
  (**213 entradas**; módulo 12: 48/48 claves casan, verificado offline).
- `hh_text_rebuild_dialogues()` (`text.cpp`): rehace el bloque de diálogo usando la tabla de mensaje
  (o la de línea como fallback), **refluye a ~30 chars/línea** (`f3 00` entre líneas) y devuelve el
  mapa `old_off→new_off` de las cabeceras de nodo.
- `dlg_arena_relocate()` (`trans_cache.cpp`): descomprime el original de la ROM, hace el rebuild
  (sin límite), busca arena, copia remapeando punteros internos y parchea toda la RDRAM. Si el
  rebuild falla → **fallback byte-idéntico (3a)**. Guarda el remap y lo aplica a módulos que carguen
  después (`dlg_apply_pending`, p.ej. la tabla de mod55).
- La vía A+ por defecto **no se ve afectada** (la tabla `.dlg.txt` solo la usa el rebuild).
- Compila en Linux.

### Alcance actual
- **Módulo 12 (Mr. Diaz)**: NO tenía desbordes → su texto extendido == conciso (no cambia).
- **Módulo 17 (villano/Bross)**: aquí están los **textos extendidos** (54/58 mensajes con entrada en
  `.dlg.txt`). Tabla de bloques: `kDlgBlocks` (`trans_cache.cpp`).

### Validación (Windows)
- `HH_DLG_ARENA=1` → escena del **módulo 17** (villano/Bross): deberían verse los textos extendidos
  (p. ej. m29 "Y por lo tanto, el núcleo del sistema de control central de este refugio, que es, en
  esencia, una sección de la nave...").
- `hh.log`: `[dlg] rebuild OK: ...`, `[dlg] arena=... verifica=OK`, y `[dlg] pending remap ...` al
  cargar la tabla externa.
- Si algo se rompe → quitar el flag (vuelve a A+) y reportar las líneas `[dlg]`.
