# 2026-09-13 — Directorio Nisitenma, loader y gate de tareas RSP

> Nota de evidencia (continúa `2026-09-13-segundo-gate-libultra.md`). No operativa.
> Tarea de esta sesión: comparar el directorio Nisitenma (+0xC/+0x14) port↔emulador para el
> módulo que el port "se salta", y el chequeo previo del directorio en `FUN_80003824`.

## 1. Resultado corto

- El **directorio Nisitenma es estático** (está en la imagen plana, con magic ASCII
  `Nisitenma-Ichigo` en `0x80038FE0`; entradas u32 desde `0x80038FF0`). Port y emulador son
  **byte-idénticos**. Las entradas usadas por el caller (`A[id-1]` start|bit31, `A[id]` end) son
  correctas y el chequeo del loader (nibble alto del header en `0x80089518` = raw/comprimido)
  también.
- El port **sí carga** el módulo que la nota anterior daba por saltado (`id=0x37` → ROM
  `0x68BF26`, Nisitenma idx54): la 3.ª llamada a `FUN_80003824` existe y la dispara el init del
  módulo 7 (`FUN_801079B0`, call site `0x80107A0C`, igual que el emulador con `ra=0x80107A14`).
- El **bloqueo real** es posterior: el bucle principal `FUN_80001454` deja de llamar al dispatcher
  de tareas `FUN_80005270` porque un contador de tareas RSP pendientes (`0x8005CD4C`) queda clavado
  en 2 y un gate (`0x80001820`) corta el cuerpo principal cuando `[0x8008D545]==0 && count>=2`.

## 2. El directorio Nisitenma (estático)

- ROM `0x39BE0` = CPU `0x80038FE0`: `4E697369...` = `"Nisitenma-Ichigo"` + tabla de offsets u32
  acumulativos (bit31 = comprimido). Mapeo `rom = vram - 0x7FFFF400`.
- `FUN_8000469c(id, dest)` (caller de `FUN_80003824`) lee:
  `start = A[id-1] & 0x7FFFFFFF` (bit31 = usar loader), `end = A[id] & 0x7FFFFFFF`,
  `a2 = end - start` (tamaño comprimido), y `FUN_800037C5C[id-1] = {start,end}` da el tamaño
  descomprimido para el zero-fill posterior.
- Verificación: en `port_vi60.bin` vs `emu_ld.vi60.bin`, rangos `0x80038F00..0x80039F00` y
  `0x80037C00..0x80038C00`: **0 diferencias**. También idénticos el buffer DMA `0x80089518` y el
  directorio trans `0x8008DFC0` en el momento alineado correspondiente.
- `FUN_80003824` (loader LZKN): guarda `a0` en `0x8005D010/14`, `a2` en `0x8005D018`, `a2-1` en
  `0x8005D01C`; lee el header de 4 B vía `FUN_80003D3C` (bit-reader con reload de chunks de 0x2000
  en `0x80089518`) y si el nibble alto (`0xF0000000`) es != 0 toma el camino "raw" (`0x80003A7C`).
  No es un chequeo del directorio sino del stream. Idéntico en ambos.

## 3. Secuencia real de cargas (port = emulador)

Trazas: port `HH_CALLTRACE` (u32 por `get_function`) y emulador `HB_TRACE_EXEC` por dirección
(`tools/analysis/parse_exec_trace.py <log>`).

| Evento | Emulador (vis) | Port (índice de traza) |
|---|---|---|
| carga idx7 (`0x4E69A8`→`0x80107830`, `0x55DD4`) | 19 | temprano |
| carga idx0 (`0x4E5F40`→`0x800F41C0`, `0xA68`) | 68 | temprano |
| `FUN_801079B0` (init módulo 7) → carga id0x37/idx54 (`0x68BF26`→`0x803837E0`, `0x4006`) | 81 | ~478.000 (≈10 s) |

El port ejecuta la cadena de callbacks del módulo 7 (`FUN_80107830 → …7864 → …78A4 → …78E0
→ …7968 → …79B0`) **una vez por ronda del dispatcher**, y `FUN_801079B0` llama a
`FUN_80004484(0x37)` en `0x80107A0C` exactamente como el emulador. La sonda gdb anterior decía
"2 llamadas" porque el log se cortaba antes de la 3.ª.

## 4. Bloqueo real: gate del bucle principal por tareas RSP pendientes

En `FUN_80001454` (hilo 5), desensamblado `0x800017AC..0x80001854` (capstone sobre la ROM):

```
v0 = FUN_80001060()                 ; u16 @0x80037758
[0x8008D544] = (v0 != 0)
t4 = [0x8008D545]                   ; valor del frame anterior
if (t4==1) goto 0x8000181C          ; actualiza 0x8008D545 = 0x8008D544
t5 = [0x8008D544]
if (t5!=1) goto 0x8000181C
v0 = FUN_80000EC8(0x8005C4B0)       ; = [0x8005C4B0+0x89C] = 0x8005CD4C
if (v0>=2) goto 0x80001820
0x8000181C: [0x8008D545] = t6
0x80001820: v0 = FUN_80000EC8(0x8005C4B0)
t7 = [0x8008D545]
if (t7!=0) goto 0x80001854          ; CUERPO PRINCIPAL (llama FUN_80005270 en 0x80001974)
v0 = FUN_80000EC8(0x8005C4B0)
if (v0>=2) goto 0x80001B24          ; EPÍLOGO: se salta el dispatcher
0x80001854: ...
```

Es decir: **si `[0x8008D545]==0` y `[0x8005CD4C] >= 2`, el frame no llama a `FUN_80005270`**.

- Port: `0x80037758=0` ⇒ flag 0; `0x8005CD4C = 2` desde VI60 hasta VI1500 (20 s), con
  `FUN_80005270` llamado **6 veces** (solo durante el arranque). Traza `HH_CALLTRACE`: a partir de
  la ronda de `FUN_801079B0` (índice ~478k) no vuelve a llamarse; el bucle sigue vivo
  (`FUN_80001454` + `osRecvMesg` + `FUN_8002Dxxx`), pero sin dispatcher ⇒ sin más callbacks del
  módulo 7/23 y `fase=0`.
- Emulador: `0x80037758=0` y `0x8005CD4C` oscila 0/1 ⇒ `FUN_80005270` **544 veces en 15 s**
  (wplog: `wr 0x8005CD4C=1 pc=0x80000F58` / `wr =0 pc=0x80000D80`).

Quién mantiene el contador:
- **Incremento** `FUN_80000ed0` (submit de task): si `[msg+8] & 0x40` ⇒ `[0x8005C4B0+0x89C]++`
  y `osSendMesg(mq=[0x8005CD78]=0x8005C4F0, msg)`.
- **Decremento** hilo 17 `FUN_80000bf0` (`0x80000D74`): al consumir un msg con `[msg+8]&0x40` ⇒
  `osSendMesg(a0+0x78,msg)` y `[a0+0x89C]--`; luego `osSendMesg([msg+0x50],[msg+0x54])`.
- gdb (run lento): el contador va 0/1 y a veces vuelve a 0 ⇒ el decremento funciona a veces. En el
  run normal queda en 2 y nunca baja.

## 5. Estado del hilo 17 / colas en el bloqueo (trabajo siguiente)

- `HH_QLOG=1 HH_VERBOSE=1`: el hilo 17 (`t=0x8005C9D8`, arg `0x8005C4B0`) recibe de `0x8005C4F0`,
  hace `osSpTaskLoad/StartGo` y espera completions SP (`0x8005C598`, evento 4, msg 0x29B) y DP
  (`0x8005C5D0`, evento 9, msg 0x29C). Las completions **sí llegan** (`sp_complete`/`dp_complete`).
- PERO al final del run la cola `0x8005C4F0` queda:
  - Port: `blocked_on_recv=0x80049930`, `blocked_on_send=0x80049930`, `validCount=1`.
  - Emulador: `mtqueue=0x8005C9D8` (hilo 17), `fullqueue=0x80049930`, `validCount=0`.
  - `0x80049930` **no es un OSThread del runtime** (no está en la lista de `[TH] osCreateThread`);
    `0x8005C9D8` sí es el hilo 17. Los campos del runtime en `0x80049930` están corruptos
    (`next` autorreferente, `pri=0xFFFFFFFF`, `queue=0xFFFFFFFF`).
- `__osRunningThread` (`0x80049940`): emulador `0x80059D80` (hilo 5) vs port `0x00011BF0` (basura).
  El runtime solo sincroniza `0x80049940` en `_thread_func` (threads.cpp); algo lo pisa o nunca se
  actualiza por cambio de contexto.

**Hipótesis principal**: el estado de hilos/colas del juego se corrompe al convivir el scheduler
del runtime con código libultra del ROM recompilado (los `FUN_8002Dxxx/0x8002Exxx` del tail son
rutinas de scheduler, p. ej. `__osDispatchThread`), o el sync de `__osRunningThread` es
insuficiente. El contador de tareas pendientes nunca drena y el gate apaga el dispatcher.

## 6. Reproducción / herramientas

```sh
# Emulador: secuencia de cargas + quién escribe el contador
HB_TRACE_EXEC=0x80004484,0x800044bc,0x800045e8,0x80004664,0x80004310,0x80003824 \
  tools/analysis/emu_ref.sh work/debug/emu_h 12 10
python3 tools/analysis/parse_exec_trace.py work/debug/emu_h.log
DISPLAY=:99 ... CORE_SO=work/libmupen64plus-wplog.so HH_WPLOG=1 HH_WPLO=0x5CD40 HH_WPHI=0x5CD60 \
  timeout 17 ./work/r64dump work/roms/us_retail.z64 work/debug/emu_wc 15   # escribe 0x8005CD4C

# Port: secuencia de llamadas + estado de hilos/colas
cd port/HybridHeavenRecomp/build_dbg
HH_CALLTRACE=/app/hybrid-heaven-recomp/work/debug/port_ct.bin ./...   # traza de get_function
HH_QLOG=1 HH_VERBOSE=1 ./...                                          # envíos/recvs de colas
```

Artefactos de esta sesión (en `work/debug/`, gitignored): `port_ct.bin`, `port_qlog.log`,
`emu_h.log`, `emu_jal3.bin`, `emu_wc.log`, `gdb_ed0.*`, `gdb_t17*.*`, `parse_exec_trace.py`
(promovido a `tools/analysis/`).
