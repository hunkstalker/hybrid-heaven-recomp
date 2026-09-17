# CaC — Ownership resuelto (Linux) y repro funcional del freeze

> Iteración autónoma 2026-09-17. Continúa `notes/2026-09-17-cac-b2-switch-y-bases-reales.md`.

## 1. Repro en Linux: SÍ reproduce el CaC

Con el replay corto (desde guardado) y el `.pak` copiado a `build_dbg/saves/`:

- El juego **carga la partida** (PFS OK: `osPfsInitPak=0`, `FindFile=0`, `ReadWriteFile READ -> 0`).
- Llega a **gameplay (`mode=0004`)** y ejecuta `M23_sel` 4 veces (vi=4220..4559).
- **Se congela**: `polls` congelados a t≈190 (4008) con VI/audio a 60/s.
- Volcado `hh_hang_rdram_8192_0.bin`: `cd4c=0`, `M23=0xAF`, **objeto `0x8024A990` +0x1C = `0xFFFF84CD`**
  (en `0x8024A9AC`). Misma firma que Windows.
- `0x801C40F8` (case 2, armado de combate) **nunca se ejecuta** → el bloqueo es anterior.

## 2. Ownership real (decisivo) — `HH_FUNC_OWNER` en Linux

```
[OWNER] load section=3 addr=801C1DC0   (section 3 = rom 03000000)
[OWNER] load section=3 addr=801C40EC
[OWNER] load section=3 addr=801C40F8
[OWNER] load section=3 addr=801C43BC
[OWNER] load section=7 addr=801C1EE0   (section 7 = rom 07000000)
```

Orden de cargas (`[OVL]`): section 3 (rom 03000000) → `0x801BF1A0`; section 3 → `0x801FA948`;
**section 7 (rom 07000000) → `0x801BF1A0`** (última; residente en esa base).

Conclusión:
- **`0x801C1EE0`** lo registra la sección 7 (M8_FUN_801c1ee0) → el callback del objeto se resuelve
  a **M8** (correcto para el residente).
- **`0x801C40EC/0x801C40F8/0x801C43BC`** siguen registrados por la **sección 3 (M23)** aunque en esa
  base ya reside la sección 7 (que no tiene símbolos ahí) → al llamarlos, el port ejecuta **código
  de M23 con M8 residente** (sombra rancias). El binario difiere entre módulos en esas direcciones
  (verificado con los blobs), así que el state machine diverge — candidato raíz del bloqueo.
- `M23_40EC` se llama 20 veces (modo front-end) y `M23_40F8` **nunca**.

## 3. Fixes candidatos (a validar con el replay Linux, que ya es fiel)

1. **Ownership por base residente**: al cargar una sección, **borrar `func_map` en su rango
   `[ram, ram+size)`** antes de registrar (range-clear). Ya se probó en el plan §3 (Windows) sin
   cambio aparente, pero ahora sabemos que las direcciones afectadas son `0x801C40EC/40F8/43BC`.
   Con range-clear quedarían **sin resolver** (no-op del dispatcher) salvo que además…
2. **Dar entradas propias al módulo residente**: añadir símbolos/mid-entries a la **sección 7
   (rom 07000000)** en esas direcciones, para que ejecute *su* código (que en los blobs no es un
   prólogo → requiere comprobar que el recompilador puede partirlas sin romper jump-tables).
3. **Revisar la semántica de carga/descarga**: ¿el juego descarga M23 al cargar section 7 en la
   misma base? Si sí, el port debería borrar M23 al `unload`; si no, el hardware también sobrescribe
   y los callbacks rancios serían "correctos" solo si el juego no los usa.

## 4. Siguiente (una variable por pasada)

- Pasada A: `HH_CANARY=0x801CC8C4:0x04` en el repro Linux para ver **quién y cuándo** mueve el estado
  del selector (0→1→0xAF; nunca 2) junto a `[MODT]`.
- Pasada B: fix candidato 1 (range-clear) y medir con el replay Linux (¿se arma combate / cambia el
  desenlace?).
- Instrumentación lista: `HH_MODTRACE` (con `vi`/`mode`), `HH_FUNC_OWNER`, replay `clean` en
  `run_corrupt.bat`, y modo poll-fiel en Linux.

## 5. Resultados Pasada A/B (Linux) y CORRECCIÓN de módulo

**Pasada A** (`HH_CANARY=0x801CC8C4:0x04`, repro Linux):
- Estado `[0x801CC8C4]`: `0x00→0x01` (vi=337) y `0x01→0xAF` (vi=876); **nunca 2**.
- `M23_sel` 4 veces (`mode=0004`), `M23_40F8` 0; freeze reproducido (polls parados, VI=9191).

**Pasada B** (`HH_RANGECLEAR=1`, mismo replay): **sin cambios** (mismo estado, mismo freeze). Las
entradas de `0x801C40EC/40F8` solo se usan **antes** de que cargue la sección que reutiliza la base,
así que el range-clear no es el fix. Queda **opt-in** (`HH_RANGECLEAR=1`), desactivado por defecto.

**Corrección importante (ownership en runtime)**:
```
[OWNER] load section=7 addr=801C1EE0 func=0x…39a0     (sección 7 = rom 07000000)
[MODT]  M23_sel  mode=0004 addr=801C1EE0 -> 0x…39a0   (mismo puntero)
```
→ En gameplay, la función que corre en `0x801C1EE0` es **de la sección 7 (rom 07000000, `M8_FUN_801c1ee0`)**,
**no** `M23_FUN_801c1dc0`. El switch del selector analizado en el plan (módulo 23, `s0=0x801CC8C4`) **no
es el código que se ejecuta** en esa dirección (M23 no tiene símbolo ahí; la sección 7 sí).
Conclusión: el state machine que debe armar el combate está en el **módulo rom `0x07000000`
(sección 7)**, no en M23. La Parte B del plan (y la atribución "M23") apuntaba al módulo equivocado;
hay que re-analizar `M8_FUN_801c1ee0` y el resto de la sección 7.

## 6. Siguiente (revisado)

1. Estático: reversear `M8_FUN_801c1ee0` (0x60 bytes, sección 7) y la ruta de la sección 7 que fija
   `[0x801CC8C4]` y arma combate; comparar con los blobs (module8_be).
2. Trazar los **escritores** de `[0x801CC8C4]=1/0xAF` (canary rings: vi=876 con `tid=5` en bucle
   `0x80003D3C`) y quién debería poner `2`.
3. Revisar por qué el objeto es "disabled" (`0xFFFF84CD` en `+0x1C` de `0x8024A990`): ruta M10/M55
   (`FUN_800058DC`), y si el port la toma por divergencia de estado.

## 7. Ronda estática (sección 7 / M8) y escritor del estado

- **`M8_FUN_801c1ee0`** (`funcs_76.c`, sección 7, offset 0x2D40, 0x60 bytes): handler pequeño que
  lee globales (`0x801BBCF0+0xF00/F08/F10`), escribe `0x801E0B00+0/4/6/8`, pone `[a0+0x5C]+0x78=1` y
  llama al setter `0x800058DC(a0, 0x801C1F40)`. → Es el que "avanza" el objeto del combate.
- **`FUN_800058dc`** (setter): símbolo `size=0x18` pero el C generado es un stub con 3 epílogos
  fusionados (`jr ra; sw a1,0x1C(a0)` + `+0x18` + `+0x20`). **Solo se llama `0x800058DC`** (grep de
  `jal`/`LOOKUP_FUNC`), que hace `sw a1,0x1C(a0)` → correcto; los otros epílogos no se usan.
- **Escritor de `[0x801CC8C4]`**: `HH_WATCH` sobre `0x801CC8C4` **no registra las escrituras** (solo
  6 accesos, todos lecturas con `val` ya 0 o 0xAF). El canary sí ve los cambios (0→1 vi=337, 1→0xAF
  vi=876) → las escrituras **no pasan por los accesores `MEM_*`** (DMA/direct-write o copia directa).
  → Siguiente diagnóstico: hook de escritura directa sobre ese rango (tipo `hh_direct_write` con
  rango) o canary `with where` para identificar el origen; y mapear el `ret` de `hh_watch_log` con el
  `.map`/`addr2line` si aparecen escrituras.
- Las únicas funciones del set compilado que **referencian** `0x801CC8C4` son M23 (`801c18fc`,
  `801c1c50`, `801c1dc0`, `801c56b8`), M12 y M25 — **ninguna de sección 7/M8**; coherente con que el
  estado lo toca el código que realmente corre (M23 reubicado/estale) y no el residente.

## 8. Hipótesis de trabajo: `0x801CC8C4` es DATO de la ventana de módulo

- `0x801CC8C4 = 0x801BF1A0 + 0xD724`, **dentro** del rango RAM de la sección de módulo 23
  (`size=0x10B50`). Es decir, no es una variable global "suelta": cae en la ventana que los módulos
  `trans` **cargan/relocan sobreescribiéndola**.
- Eso explica que `HH_WATCH` (que engancha los accesores `MEM_*`) **no vea las escrituras** al
  cambiar (`0→1→0xAF`): el byte lo fija la **carga de módulos** (copia del blob a RDRAM), no un
  `sb` del código. El canary sí lo detecta por diff de frame.
- Implicación: el "estado" del selector es en realidad **dato inicializado por el módulo residente**;
  si el port carga/reloca los módulos en distinto orden o no copia exactamente el mismo blob en esa
  ventana, el byte diverge (0xAF) y el state machine nunca llega a `2` → CaC.

### CONFIRMADO con el loader (debug en `hh_wrap_FUN_80003824`)

Tras cada descompresión, el byte en `0x801CC8C4` es **el dato del blob del módulo** en offset
`0xD724`:

| carga (dst) | src | byte `0x801CC8C4` tras cargar | blob `0xD724` |
|---|---|---|---|
| `0x801BF1A0` | `0x005F1190` (módulo 23) | `0x00` | módulo23 = `0x00` |
| `0x801BF1A0` | `0x0053C77C` (sección 7/M8) | `0xAF` | módulo8 = `0xAF` |

y el canary veía exactamente `0→1→0xAF`. **`0x801CC8C4` no es una variable de control**: es el byte
`0xD724` del módulo residente en `0x801BF1A0` (dentro de su ventana de datos, `size=0x10B50`).

Barrido de todos los blobs en `0xD724`: M23=`00`, M24=`00`, M25=`00`, M7=`0C`, M8=`AF`, M9=`46`,
M10=`8F`, M55=`3C` (M12/M54/M99 no llegan). **Ninguno es `0x02`**.

Conclusión: la premisa del plan (“`case 2` de `M23_FUN_801c1dc0` arma combate vía
`[0x801CC8C4]=2`”) **no se sostiene**: ese byte es dato de módulo y nunca vale 2 en ningún blob. Hay
que **re-identificar el selector/estado real** del armado de combate (probablemente en la sección 7
residente, `M8_FUN_801c1ee0`→setter→`0x801C1F40`), sin apoyarse en `0x801CC8C4`.

### Siguientes diagnósticos (prioridad)

1. Reversear la cadena de la **sección 7** que arranca en `M8_FUN_801c1ee0` (setter → `0x801C1F40`,
   etc.) y ver dónde debería decidir "entrar en combate".
2. Revisar por qué el objeto acaba "disabled" (`0xFFFF84CD`): quién llama a la ruta M10/M55 y con qué
   condición, comparando port vs emulador en la misma fase.
3. (Opcional) dump comparativo emu/port de `0x801CC8C4` para documentar que también en el emulador es
   dato de módulo (control negativo).

## 9. Gate del "disable" (código) y comparación con el emulador

Secuencia real de callbacks (`setter 0x800058DC`) en la traza del replay corto (Windows):

- t=39..92: el objeto **`0x8024A990`** recorre los callbacks de **módulo 10** (`0x80241948`,
  `0x80241984`, … hasta `0x802425F4`).
- t=151.215: `0x8024B7A0 ← 0x8021D8D0` (M10_FUN_8021d8d0, "primer CaC").
- t=152.172: `0x8024C4FC ← 0x8021B280` (M10_FUN_8021b280).
- **t=152.197: `0x8024A990 ← 0xFFFF84CD`** (disable) y luego se repite cada frame.

GATE del disable (en `M10_FUN_8022c7ac`, `funcs_98.c`):
```
lbu  t7, -0x226E(0x8018)   ; t7 = [0x8017DD92]
bnel t7, zero, fin          ; si [0x8017DD92] != 0 -> NO disable
addiu a1, zero, 0x1
jal  0x80379410             ; M55_FUN_80379410(a1=1) -> setter(+0x1C = 0xFFFF84CD)
```
→ El disable ocurre **solo si `[0x8017DD92]==0`**.

Comparación con dumps del **emulador** (`work/debug/dump_gameplay.bin`, `dump_menu.bin`):
- `[0x8017DD92] = 0x00` (igual que el port) → el flag **no** distingue.
- **objeto `0x8024A990` +0x1C = `0x80135320` = `M7_FUN_80135320` (módulo 7)**; `0x8024AAF8` =
  `0x801CB71C`. En el port, `0x8024A990` acaba en `0xFFFF84CD`.

Conclusión: en el emulador el objeto conserva el callback del **módulo 7** (`0x80135320`), y en el
port **M10 lo deshabilita**. El flag no explica la diferencia → el desvío está en el **estado que
lleva a ejecutar `M10_FUN_8022c7ac`/disable en el port** (state machine M10→M7), no en el gate.

### Nota de base
- **Módulo 7** (rom `0x01000000`, `section_1_module7_funcs`) vive en `0x80107830` → `0x80135320` es
  suyo (offset `0x2DAF0`).
- La sección `section_7_module8_funcs` (rom `0x07000000`) se carga en `0x801BF1A0`; su `M8_FUN_801c1ee0`
  es la que corre en gameplay en `0x801C1EE0`.

### Siguientes diagnósticos
1. Reversear la transición **`0x802425F4` → módulo 7 (`0x80135320`)** y por qué en el port no
   ocurre (¿el armer `M12_FUN_802408f0` no re-arma? plan §0.5).
2. Comparar dumps port/emu del objeto `0x8024A990` y sus vecinos **inmediatamente antes** del trigger
   de combate (no al final).
3. (Opcional) dump comparativo de `0x801CC8C4` para cerrar el control negativo (dato de módulo).

## 10. Aclaración de nomenclatura y estado del último callback

- El callback `0x802425F4` es **`M12_FUN_802425f4`** (símbolo de módulo 12), de la **misma sección**
  que el armer `M12_FUN_802408f0`: la sección cargada en `0x802408F0` (`[OVL] src=599670 rom=0A000000`,
  array `section_9_module10_funcs`). Es decir, “M10” y “M12” en las notas son la misma sección según
  de dónde salga el símbolo (Ghidra quedó con dos prefijos). Los callbacks del objeto
  `0x8024A990` (`0x80241948`…`0x802425F4`) y el armer son de esa sección.
- `M12_FUN_802425f4` (0x18C bytes, leída): hace matemática float y escribe globales
  (`0x801BBCF0+0xF26/F28`), **no llama al setter** ni referencia `0x80135320` → la transición del
  objeto a **módulo 7** la debe disparar otro sitio (tabla/loop del dispatcher u otra función), no
  este callback.
- Pendiente de comparación fiable con el emulador: `dump_gameplay.bin`/`dump_menu.bin` (2026-09-15)
  pueden ser de otra fase; hay que alinear la escena antes de concluir con el valor `M7_FUN_80135320`.

## 11. Propuesta de siguiente paso eficiente (diferencial)

Dado que el port ya reproduce el freeze de forma fiel con el replay, la vía más corta para cerrar el
CaC es **diferencial port vs emulador en la misma escena**:

1. Ejecutar el emulador con el **mismo input** del replay (el harness `r64dump` + plugin de input
   sintético): si hhinput/`HH_PRESS*` puede reproducir el `.txt`, tendríamos una referencia exacta.
2. Capturar en el emulador la secuencia de `setter 0x800058DC` (o un watch equivalente) alrededor
   del trigger y comparar con la del port (sección 9): identificar en qué callback diverge.
3. Con eso, localizar la función que debería poner `M7_FUN_80135320` y corregir la condición.

Si el emulador no puede reproducir el input, alternativa: dump de emulador **en la misma fase**
(mismo objeto/escena) con `HH_DUMP_VI`-equivalente en el emulador (`HB_DUMP_VI`) y comparar el estado
del objeto antes del trigger.

## 12. Lead concreto: el plugin de input del emulador YA soporta replay

`work/hhinput.so` (cargado por `emu_ref.sh` vía `INPUT_PLUGIN`) contiene:
```
HH_KEYS_REPLAY   HH_KEYS_BASE   [HHR] replay %s: %ld muestras, base=%ld   [HHR] idx=%ld/%ld
```
Es decir, el emulador puede **reproducir un fichero de input** (`HH_KEYS_REPLAY`, con `HH_KEYS_BASE`
como índice base). Con eso se puede hacer el **diferencial port vs emulador con el mismo input**:
1. Colocar el save del emulador (`.mpk`) en su data dir (el `.pak` del port es byte-idéntico).
2. `HH_KEYS_REPLAY=<replay> tools/analysis/emu_ref.sh ...` y capturar la secuencia de `setter`
   (`0x800058DC`) o un watch equivalente en el emulador alrededor del trigger.
3. Comparar con la traza del port (sección 9) y localizar en qué callback diverge.

**Aviso**: el `.so` tiene esa funcionalidad pero **su fuente no está en el repo**
(`tools/analysis/hhinput.c` es una versión antigua sin replay). Recuperar/documentar esa fuente es un
pendiente de higiene antes de depender de ella.
