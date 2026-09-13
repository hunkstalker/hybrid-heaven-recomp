# 2026-09-13 — Arranque: memoria (Expansion Pak) y accesorios (Controller/Rumble Pak)

> Nota de evidencia. No es fuente operativa; el estado vive en `TODO.md`/`PROYECTO.md`.

## 1. Contexto

Tras resolver input/controller y mid-entries (nota 2026-09-11), el port seguía **estancado tras el
arranque**: el hilo principal giraba sin avanzar la fase. Verificado que:

- El estado del port era **idéntico al del harness** `r64dump` (misma tabla de recursos, `fase=0/1`,
  `fe00` contando), pero **BizHawk sí progresa** (sesión larga `work/gameplay screenshots/session2`).
- RT64 **sí funciona** (Vulkan `setup SUCCESS`, display lists procesadas; su log va a
  `/root/.local/share/HybridHeavenRecomp/hh.log`, no a stderr).
- La entrada **sí llega al juego** (verificado con logs `[IN]`/`[PAD]`: Start=0x1000, `err_no=0`).
- El retrace VI **sí entrega mensajes** (7187 envíos / 7188 recepciones en la cola del hilo 19).

## 2. Causa raíz: `osGetMemSize` (Expansion Pak)

El calltrace del port (`HH_CALLTRACE`) mostró un ciclo cerrado de 93 M iteraciones:

```
osGetTime -> FUN_80026f58 (mul 64-bit) -> FUN_80026e58 (div 64-bit)
          -> FUN_80034c24 / FUN_80034ab8 (int->double) -> osGetTime -> ...
```

Ese ciclo es la **contabilidad de frame-time** del hilo principal (`FUN_80001454`), y se repite
mientras `*(0x8008D545) != 0` (modo/estado). Siguiendo el flag con **watchpoints de gdb**:

1. El boot `FUN_80001078` decide el modo:
   ```c
   v0 = osGetMemSize();                 // FUN_8002C0B0 = osGetMemSize (libultra)
   if (v0 != 0x00400000) {              // 4 MB
       0x80037754 = 1; 0x80037758 = 1;  // modo 1 -> bucle de espera
   } else {
       0x80037754 = 0; 0x80037758 = 0;  // modo 0 -> arranca
   }
   ```
2. `osGetMemSize()` (runtime) devolvía **8 MB** y `osMemSize` (`0x80000318`) = 8 MB.
3. Port **y** `r64dump` reportaban 8 MB; **BizHawk usa 4 MB** → por eso allí el juego arranca.
4. Confirmado por volcado: `0x80000318 = 0x00800000` en ambos; `0x80037758 = 1`.

**Hybrid Heaven exige la máquina base de 4 MB** (sin Expansion Pak). El port arrancaba por defecto
como máquina con Expansion Pak.

## 3. Fix aplicado

`lib/N64ModernRuntime/librecomp/src/recomp.cpp` (runtime vendored del port):

- `osGetMemSize_recomp`: `8MB` → `4 * 1024 * 1024`.
- `osMemSize` (`0x80000318`): `8MB` → `4 * 1024 * 1024`.

**Verificado**: `0x8008D544/545 = 0` (modo 0); el spin de `osGetTime` desaparece (el calltrace cae de
468 M a ~1 M entradas en 25 s); el juego pasa a un bucle de mensajes (`osRecvMesg`,
`osVirtualToPhysical`) y **emite 4 display lists** (antes 3). Sigue en fase temprana (`fase=0`,
`fe00=0`): queda un **segundo gate** por localizar.

## 4. Lecciones de método (para próximas sesiones)

- **RDRAM word-swapped**: para un watchpoint sobre el byte CPU `0x8008Dxxx`, la dirección física en el
  buffer del port es `(0x8Dxxx ^ 3)`. Un watchpoint sobre el byte equivocado no dispara y confunde.
- **Los logs `hh::log` van a `hh.log`** en la carpeta de app (`~/.local/share/HybridHeavenRecomp/`),
  no a stderr. `HH_VERBOSE=1` solo afecta a los logs de consola.
- El log `[RND]` y `[TBL]` son la instrumentación barata para ver fase/estado/tabla por frame.
- **Persistencia**: todo artefacto debe quedar bajo `/app` (p. ej. `work/debug/`); `/tmp` se pierde
  entre sesiones. El entorno puede resetearse a Alpine mínima; ver `AGENTS.md` para la lista `apk`.

## 5. AVISO: accesorios N64 que alteran el arranque (Controller Pak, Rumble Pak, …)

El arranque del juego **ramifica según el estado del hardware SI**. Ya nos ha pasado dos veces:

- **Ausencia/presencia de mando** (puertos conectados): `get_input` respondía por los 4 puertos y
  `osContGetReadData` no escribía los ausentes → el boot tomaba otra rama (nota 2026-09-11).
- **Expansion Pak** (tamaño de RDRAM): este documento.

Es **muy probable** que el juego ramifique también según **Controller Pak (mempak)** y **Rumble Pak**.
Puntos a auditar cuando el segundo gate no se explique por otra vía:

| Mecanismo | Dónde | Qué comprobar |
|---|---|---|
| Bitpattern de mandos (`osContInit`) | `osContInit_recomp` / `librecomp/src/cont.cpp` | bits por puerto; que coincidan con el emulador |
| `OSContStatus` (device/pak type) | `osContStatus` / `osContStartQuery` | tipo de pak reportado por puerto |
| `get_connected_device_info` | `src/game/input.cpp` | hoy `connected_pak = Pak::None`; ¿debe reportar **Mempak**/Rumble? |
| Detección de Controller Pak | funciones del juego / `__osContPak` | si el juego salta a "sin pak" vs "pak presente" |
| Detección de Rumble Pak | `osMotorInit` / `__osMotorAccess` | que no se quede en un camino de error |
| Escritura/lectura del Controller Pak | `osPfs*` | stub actual vs comportamiento real (¿bloquea el boot?) |

**Recomendación**: al igual que con el tamaño de memoria, hacer que el port **reproduzca exactamente**
la configuración del emulador de referencia (BizHawk por defecto: sin Expansion Pak, mando estándar,
**sin Controller Pak y sin Rumble Pak**), y solo después permitir variantes. Cualquier diferencia en
estos "accesorios" puede cambiar las **entradas de arranque** del sistema, como ya ha ocurrido.

## 6. Artefactos de esta sesión

- `work/debug/`: `port_mem_long.log`, `port_fixmem.log`, `trace_mem.bin` (calltrace), `gdb_watch545*.log`,
  `gdb_watch544.log`, `gdb_watch758.log`, `emu_smoke`, `watch*.gdb`.
- Cambios de código: `recomp.cpp` (memsize), `events.cpp` (`[RND]` con `f545/f544`; dump VI a
  `work/debug/`), `input.cpp` (`HH_INLOG`), `cont.cpp` (`[PAD]` con `HH_INLOG`).

## 7. Referencia de emulador que SÍ progresa (clave para comparar)

Tras el fix de memsize el port quedaba igual que nuestro `r64dump` (tabla `800F41C0`, `fase=0`), pero
BizHawk seguía avanzando. **La pieza que faltaba era el vídeo real (RDP)**: con

```
4 MB (DisableExtraMem=1) + input (hhinput.so) + RSP-HLE + mupen64plus-video-rice.so + Xvfb :99 con GLX
```

el emulador **progresa y su tabla coincide EXACTAMENTE con la de BizHawk** a t=30 s:

```
0x801FA948 0x8020B5C8 0x8020B938 0x80225468 0x80235078 0x80265FF8
(= ids 0018 0073 0075 007C 012D 0074)
```

Encapsulado en `tools/analysis/emu_ref.sh` (persistente). Requisitos de entorno: `apk add
mesa-dri-gallium libsamplerate` + Xvfb :99 con GLX (`+extension GLX +render`).

Implicación: el segundo gate del port está en **algo que el RDP/vídeo real proporciona** (p. ej.
interrupción DP/scanout). El port usa RT64 (RDP real) pero se estanca igual que el emulador sin vídeo →
comparar ahora port vs emulador-con-vídeo (RDRAM alineada por frame + call trace) para localizar la
divergencia exacta.
