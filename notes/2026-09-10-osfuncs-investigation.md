# SESIÓN 2026-09-10 — Investigación emulador (harness Linux) + mapeo de os funcs

> Documenta la tanda de trabajo posterior a `notes/2026-09-10-render-investigation.md` §7:
> ejecución del **harness Linux (mupen64plus)** para identificar quién publica a `0x8005be40`,
> y el **escaneo del mapeo de os funcs** del recompilador. Complementa
> `notes/2026-09-10-scheduler-diagnosis.md` y `notes/2026-09-10-render-blocker.md`.

## 0. Resumen ejecutivo

- Se puso a funcionar el **harness Linux** (`work/r64dump`, mupen64plus) en el entorno de desarrollo
  (faltaban deps: xvfb, libx11, glu, libSDL2, libopcodes, python3+capstone, git — reinstaladas).
- **Confirmado**: el juego inicializa `0x8005be40` como cola y thread 5 recibe de ella. Pero el
  **write-bp en `0x8005be40` está contaminado** (la región se solapa con la pila del thread 5) y el
  **`ra` del harness se lee como 0** → no se pudo aislar el emisor por esta vía.
- **Hallazgo principal**: el **mapeo de os funcs del recompilador parece incorrecto**. Varios os funcs
  mapeados en `us_unified.syms.toml`/`recomp_overlays.inl` apuntan a **funciones de juego**, no a
  libultra (verificado por disasm + decodificación manual).
- **Contradicción sin resolver**: pese al mapeo sospechoso, el port bootea y usa los os funcs del
  runtime (traza `[TR]`). Requiere análisis más profundo (Ghidra interactivo) para resolver.

---

## 1. Puesta en marcha del harness (deps reinstaladas)

El entorno perdió varias dependencias (probablemente por `apk add`/reset). Se reinstalaron:

```sh
apk add --no-cache xvfb libx11 glu libsamplerate sdl2 binutils python3 py3-pip git
pip install --break-system-packages capstone
```

- **Xvfb**: `Xvfb :99 -screen 0 640x480x24 +extension GLX +render >work/debug/xvfb.log 2>&1 &`
- **Harness**: `work/r64dump` (fuente `tools/analysis/r64dump.cpp`). Plugins en
  `work/wsl_package/plugins/`. El plugin glide necesita `Glide64mk2.ini` en `./plugins/` (relativo al
  CWD) — se copió temporalmente.
- **ROM**: el harness usa `work/roms/us_dec.z64` (overdump). Se verificó que `us_dec` y
  `us_retail` comparten **código idéntico** en las mismas direcciones (0x800266B0 idéntico).
- **Invocación** (write-bp `HB_RES_DIR`, exec-bp `HB_EXEC`):
  ```sh
  export DISPLAY=:99
  SDL_AUDIODRIVER=dummy CORE_SO=.../libmupen64plus-debug.so \
    RSP_PLUGIN=.../mupen64plus-rsp-hle.so INPUT_PLUGIN=.../hhinput.so \
    VIDEO_PLUGIN=.../mupen64plus-video-glide64mk2.so AUDIO_PLUGIN=.../mupen64plus-audio-sdl.so \
    HB_RES_DIR=0x8005be40 HH_WP_ARM=2 M64P_CONFIG_DIR=.../work/wsl_package \
    M64P_PLUGINDIR=.../work/wsl_package/plugins timeout 20 ./work/r64dump work/roms/us_dec.z64 work/debug/harness 15
  ```

## 2. Resultados del write-bp en 0x8005be40

- Se confirmó que el juego **inicializa `0x8005be40` como cola** (writes a `+0x0/+0x4/+0x8/+0x10/+0x14`
  = `osCreateMesgQueue`) y que **thread 5 recibe de ella** (writes a `validCount`).
- **PERO** la región `0x8005be40` se solapa con la **pila del thread 5** → el write-bp dispara en
  decenas de escrituras de pila no relacionadas (saves de stack, funciones de copia de bytes a
  `0x8002630C`, `0x80031194`, `0x80004344`, etc.). **Ruido, no señal** — confirma la advertencia de
  la nota anterior ("no usar write-bp en 0x8005be40").
- El único patrón "de post" (incremento de `validCount` en `0x5BE48`) apareció en `0x8002630C`
  (mapeado como osSendMesg) pero esa función es en realidad **copia de bytes**, no un post limpio.

## 3. Resultados del exec-bp (sin señal útil)

- `HB_EXEC=0x800266C4` (sospecha de post): dispara **cada ~0.1s** (función periódica, no un post
  puntual); registros a0/a1 ruidosos.
- **Bug del harness**: `ra` se lee **siempre 0** en los hits (write-bp y exec-bp) → no se puede
  identificar el caller por esta vía.
- Conclusión: el emulador (write-bp + exec-bp) **no permite aislar el emisor** de forma fiable.

## 4. HALLAZGO PRINCIPAL — mapeo de os funcs incorrecto

Al desensamblar los os funcs mapeados en la syms (`config/RecompiledFuncs_unified/recomp_overlays.inl`):

| os func (mapeado) | vram mapeado | código real en esa vram |
|---|---|---|
| osSendMesg | 0x80026300 | función de **copia de bytes** (no hace ops de cola) |
| osRecvMesg | 0x800266B0 | **accessor** corto (jr/ra a los 0x1C bytes, no los 0x140 de osRecvMesg) |
| osCreateMesgQueue | 0x80030610 | función compleja (move a0,t4; andi; subu; slt…) — no inicializa cola |
| osJamMesg | 0x80030A10 | float math (mul.s/swc1) |
| osSetEventMesg | 0x8002FB60 | función de juego |
| osCreateThread | 0x80028260 | función de lista/cola |

- Verificado por **decodificación manual** de bytes (`0x01D94821` = `addu t1,t6,t9`) → el
  desensamblador es byte-accurate.
- El **escaneo por patrón** (capstone, `skipdata`) de la región plana `0x80000400-0x8004E5B40`
  (1.28M instrucciones) **no encontró ningún `osCreateMesgQueue`** real (patrón "sw zero a
  +0/+4/+8/+0xc + sw a2,0x10 + sw a1,0x14") → **el libultra del juego NO está en la región plana**.

### 4.1 Contradicción (sin resolver)
Si el mapeo es tan incorrecto, ¿cómo bootea el port y crea threads/colas correctamente? El runtime
`osCreateMesgQueue`/`osRecvMesg` SÍ se llaman (lo confirma la traza `[TR]` de sesiones previas). Hay
una discrepancia entre:
- el mapeo de la syms (apunta a funciones de juego), y
- el hecho de que el boot funciona y usa los os funcs del runtime.

**Hipótesis a investigar:** el libultra del juego vive en un **segmento cargado vía el cargador
`trans`** (no en la región plana), y el mapeo de os funcs del recompilador se hizo por **byte-matching
con Goemon** pero con una **base de offset incorrecta** (la ROM `la ROM del proyecto de referencia` de Goemon, 32MB, no mapea
vram→offset como `vram-0x80000000`; verificado: `osRecvMesg` de Goemon en `0x80040110` no es
osRecvMesg con ese offset).

## 5. Método byte-matching con Goemon — NO sirve con el offset actual

- `la lista de os funcs del proyecto de referencia` lista os funcs en `0x8003xxxx-0x8004xxxx` (p.ej.
  `osRecvMesg=0x80040110`, `osSendMesg=0x80040250`).
- Al desensamblar `la ROM del proyecto de referencia` en `vram-0x80000000`, `0x80040110` da el **fin de una función**
  (`lw ra; addiu sp; jr ra`), no osRecvMesg → la base de offset de Goemon es distinta.
- Por tanto **hay que re-derivar las direcciones reales de los os funcs** sin depender del
  byte-matching por offset (o corregir la base de Goemon primero).

## 6. Conclusión / estado

- **No se ha identificado de forma fiable** el emisor del mensaje a `0x8005be40` (write-bp
  contaminado, `ra` roto).
- **Se ha detectado un fuerte candidato a causa raíz**: el mapeo de os funcs del recompilador
  apunta a funciones de juego, y el libultra real no está en la región plana.
- **Próximo paso recomendado (fiable):** identificar con **Ghidra interactivo** el segmento/libultra
  real del juego y re-derivar las direcciones de los os funcs. La decompilación headless de Ghidra
  devolvía funciones vacías (funciones mal delimitadas), por lo que se recomienda la **GUI** de
  Ghidra con el proyecto `work/ghidra/proj` (HH.gpr).

## 7. Archivos / estado

- Harness `work/r64dump` — sin cambios de esta sesión (solo deps reinstaladas).
- `port/.../N64ModernRuntime` — la instrumentación `[TR]` de sesiones previas fue **revertida** en
  esta sesión (queda limpio salvo el submódulo N64Recomp preexistente).
- `tools/analysis/ghidra_scripts/TimerScanX.java` — script Ghidra nuevo (escaneo de refs a
  `0x8004ae60` + decompile de `FUN_80031498`/`FUN_80031190`), **sin trackear**.
- Herramientas temporales (antiguas): `mips_dis.py`, `find_mq.py`, `find_mq2.py` (escaneos por
  patrón), `TimerScanX.java` (copia en ghidra_scripts).
- El repo queda en baseline conocido-bueno (boot OK, thread 5 bloqueado en `0x8005be40`); solo
  `funcs_6.c` modificado (preexistente, diff NAN_CHECK de una sesión anterior, no de esta).
