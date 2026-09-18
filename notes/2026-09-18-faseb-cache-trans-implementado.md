# 2026-09-18 — Fase B: cache de assets + loader LZKN64 nativo (implementado y validado headless)

> Implementa ADR 0007. Continúa `notes/2026-09-18-suavizado-fase1-y-cache-loader.md` y el perfil de
> `logs_pacing_20260918_114105`. DEV headless; el test de juego lo hace el mantenedor.

## 1. Perfil de partida (confirmación)

`logs_pacing_20260918_114105` (Windows, `run_cac_profile.bat`, hasta la 1ª puerta): de los 600 ticks
lentos (>36 ms) de `hh_slow.log`, **`guest_busy` = 39345 ms de 39464 (99,7%)**; `send_dl`≈3 ms,
`update_screen`≈0. Los 11 stalls >200 ms (0,25–4,2 s) son **100% `guest_busy`** (loader). Cadencia:
`d2=29 d3=1` (30/s) hasta t≈29; tras la puerta `d3=10-18` (22-25/s). El `0xC0000005` final es el
**teardown al cerrar la ventana** (mismo AV con `HH_TRANS_CACHE=0`), no un crash de juego.

Conclusión: el presupuesto de 2 VI (33,3 ms) se lo come el **código guest / loader**, no RT64/present.

## 2. Firma real de `FUN_80003824`

- `a0` = offset de ROM del asset; `a1` = destino (RDRAM); `a2` = tamaño **comprimido**; `a3` sin uso.
- El stream empieza con 4 bytes BE = **tamaño comprimido** (límite del bucle de entrada), no el
  descomprimido. Verificado: `src=0x4E69A8` → header `0x00055DD4` = `a2` = longitud del asset.
- Devuelve `r2 = dst + out_len` (fin de la salida).
- La ruta de decodificación cuando `(header & 0xF0000000)==0` es **exactamente LZKN64**
  (`tools/lzkn64/lzkn64.py`). El header físico lo lee el port en orden guest (MEM_BU + `^3`).
- Los contadores `0x8005D010/14/18/1C/20/24` son estado interno del cluster del loader; ningún otro
  sitio del código recompilado los lee (verificado por grep de las constantes `-0x2FEx`).

## 3. Implementación

- **`port/HybridHeavenRecomp/src/game/trans_cache.cpp`** (versionado) expone
  `extern "C" void hh_trans_load(uint8_t* rdram, recomp_context* ctx, recomp_func_t* real_loader)`.
- **Wrapper** en `librecomp/src/overlays.cpp` (runtime local, no versionado): `hh_wrap_FUN_80003824`
  llama a `hh_trans_load` en vez de al loader original, y después `load_module_by_source` como antes.
- Modos: **hit** `memcpy` desde `cache/trans.bin`; **miss** decodifica nativo y da de alta; si el
  nativo no aplica (header no LZKN64, tamaño fuera de rango, destino no alineado) usa el loader
  original y captura su salida.
- El cache guarda los bytes del layout host (word-swapped), posición-independiente para dst alineado
  -> copia directa. Fichero: `magic + version + count + rom_hash(FNV-1a)` + registros
  `(src,size,len,payload)`; se invalida si cambia el hash de la ROM.
- Knobs: `HH_TRANS_CACHE` (def 1), `HH_TRANS_NATIVE` (def 1), `HH_TRANS_VERIFY` (def 0),
  `HH_TRANS_DUMP` (def 0).

## 4. Validación headless (build_dbg, lvp Vulkan)

- `HH_TRANS_VERIFY=1`: en las 11 cargas del boot, `native=1 real=N bad=0` (nativo byte-exacto vs
  loader original), incluido el asset grande `004E69A8` (564.464 B) y el módulo 23 `005F1190`
  (68.432 B).
- `tools/analysis/validate_trans_cache.py`: cache nativo == cache del original == `lzkn64.py`
  (8 entradas únicas, 704.364 B), `OK=8 BAD=0`.
- Times (dump): miss nativo ≈ **2 ms**/asset (18,6 ms el de 564 KB, incluye init), hit ≈ **0-8 µs**.
  Frente a los stalls de 0,25-4,2 s del loader guest.
- El crash headless posterior (en una librería, no el exe) se reproduce igual con
  `HH_TRANS_CACHE=0` -> es del entorno (llvmpipe), no del cache.

## 5. Pendiente / siguiente

- **(MANTENEDOR) Windows**: `build_windows.local.bat` + `run_cac_profile.bat` incluyendo la 1ª
  puerta; comprobar que los stalls del loader desaparecen (`hh_slow.log`) y que no hay regresión.
  Opcional: una pasada con `HH_TRANS_VERIFY=1` para validar todas las cargas del juego (más lenta).
  Si algo se corrompe, `HH_TRANS_NATIVE=0` revierte a captura (100% fiel) sin recompilar.
- Decidir default de `HH_TRANS_NATIVE` tras la validación completa.
- Extractor offline opcional para precargar el cache (~14 MB) y no depender de una 1ª pasada.
- El **régimen 2** (escenas pesadas a 3 VI) no lo arregla Fase B: es otro frente (optimizar guest).

## 6. Validación Windows (2026-09-18, `logs_pacing_20260918_131409`) y hallazgos

- El cache se creó (1,69 MB, 35 entradas) y se activó (`[trans] cache activo ... nativo=1`). Los 35
  assets **decodifican todos con LZKN64** (comprobado con `validate_trans_cache.py`), así que el
  decoder nativo debería cubrirlos.
- **Pero los stalls de boot/puerta persisten** con magnitudes casi idénticas a la pasada sin cache:
  pre `{4222,1154,1464,1816,2631,1255} ms` vs post `{4187,1081,1495,2460,1249} ms`. => El cache no
  los elimina.
- **Bug encontrado y corregido (v2)**: 3 assets tienen salida con longitud **no múltiplo de 4**
  (`3514`, `43`, `783` B). La v1 guardaba/copiaba el layout host de forma contigua, lo que solo es
  correcto si `len % 4 == 0`; para el resto corrompía el último byte. La v2 guarda el payload en
  **orden guest** y escribe con `store_guest` (permutación exacta para cualquier longitud). Se sube
  la versión del cache a 2 (invalida la v1).
- **Diagnóstico añadido para la próxima pasada de Windows**:
  - `hh.log`: una línea por carga `[trans] load src=.. size=.. dst=.. kind=hit|native|real len=..
    us=..`. Distingue si el nativo se usa de verdad y su coste.
  - `hh_slice.log`: sampler de **slices guest largos** (`hh_busy_active_ms > 150`): vuelca contexto +
    anillo de últimas llamadas de cada hilo. Identifica la función guest culpable de un stall que
    no sea el loader.
- **Hipótesis a resolver con esa pasada**: (a) el nativo falla en Windows y cae al loader original
  (`kind=real`, warning `nativo NO aplica`); o (b) los stalls son **otro trabajo guest** (no
  `FUN_80003824`) y `hh_slice.log` dará la función. Los datos actuales apuntan a (b) o a que el
  nativo no se ejecuta.

## 7. Segunda pasada Windows (`logs_pacing_20260918_132739`): el loader NO es la causa

- `hh.log` confirma que **todas** las cargas son `kind=native` (0 `real`): el decoder nativo funciona
  en Windows. Tiempos: **0,2–0,6 ms** típicos (15 ms el asset de 564 KB); los picos de ~9–11 ms son
  la escritura del cache a disco. Nada de 4 s.
- Los stalls de boot/puerta **persisten** (`4265, 1103, 1533, 2521, 1285` ms) y son 100 %
  `guest_busy`, pero `hh_slice.log` **no se generó**: el primer sampler usaba `hh_busy_active_ms`
  (>150 ms de slice continuo) y no disparó => los stalls son **muchos slices cortos**, no un bucle
  continuo. `guest_busy` los suma, pero el hilo se parkea/resume a menudo.
- Conclusión: **la Fase B arregla el loader, pero los stalls de 1–4 s son otro trabajo guest**
  (probablemente el setup/init de escena tras cada carga, o un busy-poll de colas). Hay que
  identificarlo.
- **Sampler corregido**: ahora se dispara cuando el latido de input (`polls`) se detiene >200 ms
  (que es exactamente la condición de stall), y volca contexto + **stack-scan** + anillo de llamadas
  a `hh_slice.log`. Verificado en Linux (dispara y vuelca). Próxima pasada Windows: localizar la
  función guest culpable y decidir si es inherente (optimizar guest, régimen 2) o un artefacto del
  port.

## 8. CAUSA RAÍZ de los stalls y del "régimen 2": `get_function` instrumentado

La pasada Windows con el sampler (`logs_pacing_20260918_135140`, todas las cargas `kind=hit`)
volcó `hh_slice.log`: durante los stalls de 1-4 s el hilo de juego (tid=5) está **exclusivamente**
en el cluster `0x80015A64`/`0x80016xxx` (bit-reader/decode: `FUN_80015a64` llama
`FUN_80016D50`/`FUN_80016CE4` en bucle). 509/624 entradas del anillo caen en `0x80016xxx`.

El problema no es ese código, sino que **cada llamada recompilada pasa por `get_function()`**
(`#define LOOKUP_FUNC(val) get_function(val)` en `recomp.h`), y la versión del port ejecutaba en
**cada llamada**:
- `hh_calltrace()` -> `getenv("HH_CALLTRACE")` cuando estaba off (¡nunca cacheaba!),
- `getenv("HH_MQLOG_ALL")` x2,
- `getenv("HH_MODTRACE")`,
- `getenv("HH_TBLTRACE")` + `getenv("HH_LSTTRACE")`,
- `func_map.find()` (unordered_map),
- `hh_trace_fn`, `hh_s0fix_check`, `hh_owner_watched`, `hh_callring_record` (estos baratos).

En bucles de decodificación con **millones** de llamadas a funciones diminutas, 4-5 `getenv()`
por llamada (cada uno recorre el entorno) suman **segundos**. Eso explica los stalls de boot/puerta
y probablemente el "régimen 2" (escenas pesadas).

**Fix (runtime local)**: cachear los flags de instrumentación en `static const bool` (una sola
`getenv` al arrancar) y `hh_calltrace` cachea su propio flag. Se conservan `hh_s0fix_check`
(funcional), `hh_callring_record` (barato, lo usa `hh_slice`), `hh_trace_fn` (early-out barato),
`hh_owner_watched` (cacheado) y `func_map.find`.

Nota: el `get_function` upstream de N64Recomp también hace un lookup por llamada; lo correcto a
futuro sería una tabla directa indexada por VRAM (con invalidación al cargar/descargar overlays),
pero primero medir el efecto del fix de `getenv`.

### 8b. Validación Windows del fix (`logs_pacing_20260918_140027`)

| métrica (`hh_slow.log`) | antes (`132739`) | después (`140027`) |
|---|---|---|
| ticks lentos >36 ms | 587 | **19** |
| stalls >200 ms | **8** (4265, 2521, 1533, 1285, 1103, 287, 278, 248) | **0** |
| `dt` mediana / máx | 42,1 / 4264,6 ms | 38,2 / **76,9 ms** |
| `guest_busy` mediana / máx | 42,0 / 4259 ms | 35,0 / **77 ms** |
| cadencia tras la puerta (`hh_tick.log`) | `d3=10-18` (~22-25/s) | **`d2=29-30`, `d3=0-1` (30/s)** |

`hh_slice.log` queda prácticamente vacío (un muestreo de boot con 0 contextos). Los ticks lentos
residuales son de ~37-39 ms (`guest_busy≈34-35` + `send_dl≈3`), rozando el presupuesto de 2 VI; ya no
hay hitches. **El overhead de `get_function` era la causa raíz de los stalls y del régimen 2.**
Pendiente menor: reducir ese ~4-6 ms residual por tick (tabla directa de `get_function`, o reimplementar
funciones guest calientes) si se quiere clavar `d3=0`.
