# 2026-09-15 — Cuelgue del NPC: bisect, causa raíz (módulo 9) y punto de retomada

> Nota de sesión. **Estado: fix aplicado y compilado en Linux; PENDIENTE validar en Windows** con la
> secuencia del NPC (paso 1 de §5). Evidencia y procedimientos para retomar sin re-investigar.

## 1. Resumen ejecutivo

El cuelgue **no es una regresión**: el build de la era "sin audio" (`e23e64c`, sin `SDL_INIT_AUDIO`)
también se cuelga, con **3 × `do_break` en `0x802169AC`** antes del cuelgue (verificado por bisect).
Causa raíz: el símbolo **`M9_FUN_802169ac` tenía tamaño 0x4604** (arrastraba datos: *"analysis failed
(data absorbed by coarse boundary?)"*), así que N64Recomp lo dejaba en **stub `do_break`**. El módulo 55
llama 3 veces a esa función (dispatcher de diálogo); al no hacer nada, el flujo de la entrega del
objeto se rompía. **Fix**: acotar el símbolo a su tamaño real **0x1C0** (la función acaba en
`0x80216B6C`; el resto del rango son datos) + mecanismo de override de tamaño en el pipeline.

Con el fix, la petición DMA que antes quedaba pendiente (dirección basura `0x008DE1E6`) ahora se emite
con la correcta (`0x108DD82E`, `region=rom`) y **completa**. Queda validar el NPC en Windows.

## 2. Cronología y cambios de la sesión

| Área | Cambios | Commits |
|---|---|---|
| Audio | 43200 Hz (720 frames/VI), feedback de cola, sin SDL_AudioCVT, Release por defecto, `HH_AI_QUEUE_REPORT`/`HH_AI_RATE` | `76551ff` `e3c460d` `3d7d388` `0519d0d` `b61db7e` |
| Mando | Perfiles `config.ini` [game]/[menu] con flag de UI `0x802690D0`; mapeo moderno (B=Z, Select=B, Y=C-Down, X libre); `[PAD]` logs | `b3a0421` `ebc1eca` `4c643ac` `274ad54` `c4734eb` `791c143` |
| Diagnóstico | Volcado de crash (RDRAM/DMEM/registros del juego, SEH del entrypoint, nombres únicos, `/MAP`); watchdog de cuelgue (polls **y** audio); `hh_pi.log` con `t=` | `57e15d1` `88a76c2` `245928f` `6338889` `46f3286` `ccc5f99` `9053d7a` |
| Fix | `M9_FUN_802169ac` 0x4604→0x1C0 + override `0xADDR:0xSIZE` en el pipeline | `fa02e24` |
| Pruebas | Bats `run_test_{input,audio,both,debug}.bat`; `bisect_build.bat` (+`bisect_extra.patch`, **sin commitear**) | `8475563` |

## 3. Evidencia del cuelgue (volcados)

- `hh_hang.log` (watchdog): los **9 hilos del juego quedan aparcados**. `ctx2` está en
  `FUN_80001f30` esperando la completación de un `osEPiStartDma` en la cola `0x8005C268`; la petición
  (`mb` en `0x8005CD80`) tenía `devAddr=0x008DE1E6` (basura) → región **desconocida** → `do_dma` no
  publica completación → el cargador no avanza.
- `hh_pi.log` (con el fix M9): la misma petición sale como `dev=0x108DD82E … dram=800631B0 size=30
  mq=8005C268 region=rom` y **completa**.
- Bisect: `e23e64c` (sin audio) reproduce los 3 `do_break` y el cuelgue ⇒ **no regresión**; el fallo
  está en los símbolos del módulo 9 desde que se añadieron los overlays.

## 4. Causa raíz y fix (detalle)

- `0x802169AC` es una **función real** del módulo 9 (0x1C0 bytes): lee argumentos del caller, indexa la
  jump-table `0x80171CEC` (0x80170000 + 0x1CEC) y llama `FUN_80146088` (módulo 7) y `FUN_80006214`
  (plana). Callers: módulo 55 en `0x803783CC/0x80378428/0x80378484`.
- El símbolo estaba a `0x4604` porque el generador de syms usa `siguiente símbolo - vram` y no había
  entrada entre `0x802169AC` y el final de sección (`0x8021AFB0`); el rango posterior es **datos**.
- **Fix de pipeline**: `gen_module_syms.py` acepta extras `0xADDR:0xSIZE` (override de tamaño);
  `setup_module.py` los conserva; `config/module_extras.json` → `"9": ["…","0x802169AC:0x1C0"]`.
  Regenerado solo el set combinado; `funcs_93.c` compila la función real.
- Nota: regenerar **todos** los syms a la vez produjo regresiones colaterales (auto-mid de módulo 12
  metía datos como código → `0 = cop0_register_read(...)`); por eso el fix se aplicó puntual y no se
  regeneró todo. Ver §6.backlog.

## 5. Punto de retomada (sesión nueva) — empieza aquí

1. **VALIDAR LA BUILD (objetivo inmediato)**
   - `build_windows.bat` (Release) y reproducir la entrega del objeto del NPC.
   - Si se congela: **esperar ≥20 s con la ventana congelada** (el watchdog dispara por polls parados
     **o** por audio parado) y después leer `hh_hang.log` + `hh_pi.log` + `hh_crash*.log` (si hubo).
   - Si funciona: cerrar el objetivo y seguir con 2.
2. **Si sigue el cuelgue**: analizar `hh_hang.log` (registros `r4..r7/sp` por hilo) y `hh_pi.log`.
   Herramientas: ver §6.decoded (ehang) y el `.map` de `build_win`.
3. **Mando**: identificar el botón N64 que abre el menú de combate cuerpo a cuerpo y asignarlo a **X**
   (`config.ini`). Pendiente además: decidir `LB` (¿L?) y el atajo de cámara/1ª persona.
4. **Teardown SEGV** al cerrar (`Hybrid Heaven Recomp.exe +0x12A602` en Windows).
5. **Guardado**: validar PFS/Controller Pak contra el emulador; valorar el `saves\*.pak` para depurar
   (guardar antes del NPC y compartir el `.pak` permite reproducir el cuelgue en local).
6. **Futuro**: desacoplar el audio de los fps (ver TODO).

## 6. Referencia rápida de la instrumentación (usa esto, no reproduzcas a ciegas)

### Ficheros que el port escribe junto al exe (CWD)
| Fichero | Contenido |
|---|---|
| `hh_crash.log` | crash: código, dirección, módulo+offset, registros host y **del juego** (ra/sp/args) |
| `hh_crash_rdram_<pid>_<n>.bin` | 8 MB de RDRAM en el crash (nombres únicos: no se pisan) |
| `hh_crash_dmem_<pid>_<n>.bin` | 4 KB de DMEM del RSP |
| `hh_hang.log` | cuelgue: `vi_ticks`, `pending_ext_msgs`, registros de **todos** los hilos |
| `hh_hang_rdram_<pid>_<n>.bin` | 8 MB de RDRAM en el cuelgue |
| `hh_pi.log` | cada PI DMA con `t=` (s), dev/phys/dram/size/mq/región |
| `hh_missing.log` | `Failed to find function at 0x...` |
| `hh_audio.log`, `hh_rsp.log` | tasa/cola de audio y duración de la task RSP por segundo |

### Envs útiles
`HH_HANG_SECS` (umbral watchdog, defecto 15) · `HH_HANG_FORCE=<s>` (volcado forzado) ·
`HH_AI_RATE=<hz>` · `HH_AI_QUEUE_REPORT=full` · `HH_PAD_CONFIG=<ini>` · `HH_NOAUDIO=1` ·
`HH_INPUTLOG=1` · `HH_PRESS*`/`HH_STICK`/`HH_CSTICK` (input sintético) · `HH_RES` · `HH_RECORD`/`HH_REPLAY`.

### Bats
`run_windows.bat` (Release) · `run_noaudio.bat` · `run_audlog.bat` ·
`run_test_{input,audio,both,debug}.bat` (regresión) · `bisect_build.bat` (build de bisect: runtime a
base + patch del commit actual; **sin commitear**).

### Mapas
MSVC genera `build_win/HybridHeavenRecomp-Release.map` (traducir `exe+0xNNNN` a función).

## 7. Estado de git y entorno al cerrar

- **HEAD = `8475563`**; árbol limpio salvo los docs de esta nota (sin commitear) y los bats de bisect
  (untracked).
- Runtime `lib/N64ModernRuntime`: base `fd6b0d0` + **patch del commit actual aplicado** (correcto).
- `build_win/bin/Release` contiene el **exe del bisect (commit viejo `e23e64c`)** → hay que
  **recompilar** antes de validar.
- Linux: `build_dbg` compila y arranca (smoke). Los tests locales no llegan al NPC (queda lejos en el
  replay disponible).
