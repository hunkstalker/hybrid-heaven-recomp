# Work order — Evento de módulo `0x7D` y cadena de callbacks del nodo `0x801D0474`

> Documento operativo autocontenido para retomar ESTA tarea en una sesión nueva.
> Evidencia de la sesión previa: `notes/2026-09-13-fix-corrupcion-audio-y-evento-modulo.md`.
> Estado al escribir: audio estable (300-420 s sin crash); la transición (burst del loader) no se
> dispara porque el evento `0x7D` no llega y el callback `801C2050` no se despacha.

## ACTUALIZACIÓN 2026-09-14 (ruta A ejecutada)

El bloqueo ya está localizado con precisión; ver **`notes/2026-09-14-cadena-d550-y-registro-0x74.md`**
(evidencia completa). Resumen:

- El port **sí** instala `801C2050` (t≈108 s) y lo ejecuta cada frame (como el emulador a t≈63 s).
- El `0x08` se consume y su handler corre; el script se para porque `FUN_8012FE50` tiene el gate
  `if ([0x8008D550]!=0) return;` y el port tiene **`[0x8008D550]=1`** (el emulador lo resetea).
- `d550` lo pone `FUN_80125774(a0=0x3000)` desde la cadena `FUN_801267B8 → FUN_801267C0` (id `0x74`)
  y solo lo resetea `FUN_801257DC` **si `FUN_80125808(0x74)` devuelve ≠0**. En el port devuelve 0.
- El emulador registra el recurso `0x74` en t=10,49 (`FUN_80004560(0x74)` desde `ra=0x801258BC`,
  dentro de `FUN_80125814` → `FUN_8001752C` → `FUN_80016EAC` → SETID/SETPTR); la entrada
  `0074:80265FF8` aparece en el directorio `0x8008DFC0` y **falta en el port**.
- Siguiente: ver §5 de la nota (instrumentar temporalmente `FUN_80125814` y comparar el directorio
  de recursos) y validar con `d550=0` → `bd6d=1` → `80124CEC` → `[EVQ] 0x7D` → `[LD384] > 11`.

## 0. TL;DR

El port ya no crashea por el audio (resuelto) y alcanza los hitos del emulador hasta t≈10,5 s. La
transición del emulador (t≈65,2 s) la dispara el evento de módulo `0x7D` encolado por
`FUN_800207D0` en `0x800CBB28` y consumido por `FUN_80020F60` → `FUN_80021EB8` (que pide la carga).
El port encola `0x08` a t≈108 s (tarde) y el setter instala `cb=801C2050` en el nodo `0x801D0474`,
pero ese callback **nunca se ejecuta**; `[0x801D03C0+0x1C]` sigue en `0x801BF1CC` y `fe00=0`.

## 1. Objetivo y criterio de éxito

- **Objetivo**: que aparezcan los eventos `0x08` y `0x7D`, se consuman, y el callback del nodo
  avance hasta el burst del loader ⇒ `[LD384] > 11`, `fe00 > 0` y display lists de juego.
- **Criterios medibles**:
  1. `[EVQ] id=0x7D` en el port (hoy no aparece).
  2. `[MDLE]` (FUN_80021EB8) con ids > 0x10 (hoy solo `0x87`).
  3. `[LD384]` > 11 con `a0=005FBEC6 a1=801BF1A0 a2=000135B0`.
  4. `fe00` (`u16 @0x801CFE00`) > 0 y `[0x801D03C0+0x1C] != 0x801BF1CC`.

## 2. Mecanismo (verificado)

- **Productor** `FUN_800207D0` (0x800207D0): inserta el id en `0x800CBB28[i]` y sube el contador
  `0x800CBB22` (máx. 8). Llamado desde `FUN_80020718` (a0=id) y desde `0x8002095C` (id 0x87).
- **Consumidor** `FUN_80020F60` (0x80020F60): recorre la cola; ids `0x10..0xFF` → `FUN_80021EB8`
  (escribe la petición `0x800CBB4C`); ids `<0x10` → tabla de handlers en `0x80047E0C`; ≥0x100 →
  `FUN_80021968`/`FUN_80022C8C`.
- **Alcanzabilidad**: `FUN_80020F60` solo se llama desde `FUN_8002059C` (0x80020564), que solo se
  llama desde `FUN_80020460` (0x80020484) cuando `[0x800CBAF0] == 8`.
- `FUN_800203C4` (0x800203CC) fija `[0x800CBAF0] = 8`; `FUN_80020460` la decrementa. `FUN_800203C4`
  no tiene caller directo en el código recompilado ni puntero en RDRAM (buscar jalr/tabla).
- **Timeline emulador** (`work/debug/emu_evp70_wr.log`): `0x87` t=10,49 s; `0x08` t=62,94 s;
  `0x7D` t=65,21 s (justo antes del burst 65,22-65,26 s); `0x1C9` periódico desde 68,2 s.
- **Port** (`work/debug/run_trans300.log`): `0x87` t≈10,5 s; `0x08` t≈108 s; `[SETCB] obj=801D0474
  cb=801C2050` justo después; `801C2050` no se despacha; sin `0x7D`.

## 3. Preguntas a responder (en orden)

1. **¿Se consume el `0x08`?** **Parcialmente respondido**: `FUN_80020F60` sí corre y consume eventos
   individuales (`[EVQC] cnt0=1 cnt1=0`, p.ej. n=20769 en `work/debug/run_evqc.log`). Falta
   identificar *qué id* se consumió en cada caso (loguear el id leído de `0x800CBB28` antes/después)
   y si el handler del `0x08` (tabla `0x80047E0C`) ejecuta y qué callback instala.
   **Nota**: ese run (con `HH_TBLTRACE`) acabó con SEGV **al final del timeout** (stack con
   `80059D80`/`8005C288`, hilos/colas); los runs sin `HH_TBLTRACE` de 300-420 s terminan en 0 ⇒
   sospecha de carrera de *teardown*, no del camino de juego. Confirmar y, si es del quit, aparte.
2. **¿Quién fija `estado=8`?** En el emulador `0x800CBAF0` solo se escribe una vez (memset) en 70 s,
   y el port lo mantiene 0 — pero `FUN_80020F60` necesita `estado==8` según el disasm de
   `FUN_80020460`… y aun así se ejecuta. Re-verificar la semántica del estado (o si hay otro caller
   indirecto de `FUN_80020F60`/`FUN_8002059C`); instrumentar `FUN_8002059C`.
3. **¿Quién debe invocar `801C2050`?** El setter lo instala en el nodo `0x801D0474`; comparar con el
   emulador (`HB_TRACE_EXEC=0x801C2050`) quién lo llama y con qué argumentos, y por qué el
   dispatcher del port no lo recorre (ver el patrón del setter-chain de `FUN_800058DC`). Comparar
   además la secuencia `[SETCB]` del port (que avanza hasta `801C2050`) con la del emulador.
4. **Cadencia**: el `0x08` llega 45 s tarde; medir si el avance de scripts depende de samples de
   audio (`osAiGetLength`/número de tasks) o de VIs, y si el fix de cola virtual (1 VI) lo afecta.

## 4. Instrumentación existente (gated)

- Port (`HH_TBLTRACE=1`): `[EVQ]` (productor, `overlays.cpp`), `[MDLE]` (FUN_80021EB8), `[MDL]`
  (FUN_80022044), `[MDLB]` (FUN_80020460, ahora con `st=` de `0x800CBAF0`), `[SETCB]` (FUN_800058DC),
  `[M23]` (FUN_801BF1CC/801CBDC0/801CBE88), `[LD384]` (loader).
- Port (`HH_CTXWATCH=1`): `[CTXW]` (voces + tabla `0x80091BE0`), `[RSPW] PISA`.
- `HH_TRCTRACE=1` para el flood de tabla.
- Emulador: `HB_TRACE_EXEC=<pc>` (para, perturba), `HH_WPLOG=1 HH_WPLO/HH_WPHI` (stores CPU en RDRAM).

## 5. Comandos base

```sh
# Port (Xvfb :99 viva)
cd port/HybridHeavenRecomp/build_dbg
DISPLAY=:99 SDL_VIDEODRIVER=x11 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  HH_VERBOSE=1 HH_TBLTRACE=1 timeout 420 "./Hybrid Heaven Recomp" > <log> 2>&1

# Emulador: productor de eventos / callback / loader
HB_TRACE_EXEC=0x800207D0 tools/analysis/emu_ref.sh work/debug/emu_evp 70
HB_TRACE_EXEC=0x801C2050 tools/analysis/emu_ref.sh work/debug/emu_cb 70
HB_TRACE_EXEC=0x80003824 tools/analysis/emu_ref.sh work/debug/emu_ld 70

# Wplog de un rango de RDRAM (stores de CPU)
HH_WPLOG=1 HH_WPLO=0xCBAEC HH_WPHI=0xCBAF4 CORE_SO=work/libmupen64plus-wplog.so ...
```

## 6. Reglas y trampas

- **GDB/breakpoints cambian el timing**; el burst es sensible. Preferir wplog + wrappers del runtime.
- No editar a mano `RecompiledFuncs/`; instrumentar solo `lib/N64ModernRuntime` (gitignored) o
  configs. El ucode se regenera con `RSPRecomp` (ver `config/rsp_hh_aspMain.toml`).
- `[AI ] set_next IGNORADO` = defensa; si aparece, investigar por qué el juego calculó un tamaño
  negativo (cola de audio).
- Artefactos persistentes en `work/debug/` (nunca en temporales del sistema).
