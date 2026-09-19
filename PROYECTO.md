# PROYECTO — Hybrid Heaven: Recompiled (contexto maestro)

> **Fuente de verdad del contexto y el estado.** Mantenerlo corto (≈1-2 pantallas).
> Tareas → `TODO.md`. Arquitectura y decisiones → `docs/architecture.md` + `docs/adr/`.
> Histórico y evidencia → `notes/` (no editar). Última actualización: **2026-09-19**.

## 1. Objetivo

Port nativo a PC de **Hybrid Heaven** (N64, Konami/KCEO, 1999, proyecto interno **RZ011**) por
**recompilación estática** (N64Recomp + RT64 + N64ModernRuntime), **sin emulador**, leyendo la ROM
del usuario. Sub-objetivo obligatorio: **extraer y traducir todo el texto**. Plataformas:
**Windows + Linux + Steam Deck** (mismo código). Legal: no se distribuyen ROM ni assets.

## 2. Entorno

| Ítem | Valor |
|---|---|
| Proyecto | raíz de este repo |
| Toolchain | gcc/g++ 15, cmake 4.2, ninja, SDL2, JDK 21 + Ghidra 12.1.3 + N64LoaderWV |
| Repos de referencia | N64Recomp, N64ModernRuntime, RT64, Zelda64Recomp y un port de Konami coetáneo (`toolchain/`, gitignored) |
| Derivados | `work/` y `toolchain/` gitignored (datos derivados, Ghidra, builds, artefactos) |

## 3. Arquitectura (resumen)

Stack: **N64Recomp** (MIPS→C) + **N64ModernRuntime** (`ultramodern`+`librecomp`) + **RT64** +
SDL2. Microcode gfx **F3DEX2 fifo 2.06** (RT64 lo soporta nativo). Audio: **`aspMain` del ROM**
recompilado con RSPRecomp (`rsp/hh_aspMain.cpp`), reproducción a **43200 Hz** (720 frames/VI) con
feedback de cola; dispositivo WASAPI vía SDL. Release por defecto (Debug caía a 30 fps).

**Modelo unificado: imagen plana + módulos.** El boot es una imagen de código plana; el juego
descomprime módulos de código de la ROM a RAM y los ejecuta vía `trans`. → `docs/architecture.md`.

Decisiones de fondo pendientes: `docs/adr/0001-modelo-de-modulos.md`.

## 4. Hallazgos técnicos clave del binario

- Formato **z64 BE**, entry `0x80000400`, cartucho 16 MB.
- Símbolos de debug del original (paths `/game/source/*.c`, 62 fuentes) → anclas de análisis.
- **Compresión**: tabla **Nisitenma-Ichigo** + **LZKN64** (`tools/rommy.py`, `tools/lzkn64`).
  El código plano NO está comprimido; se comprimen assets y módulos. Variantes **LZSS 5/7** del
  `trans` por caracterizar.
- Carga de módulos por el loader `trans` (`seg_RomDecode_sep`); directorio `id→base` en
  `0x8008DFC0`. Mapa dinámico = tarea #3 (BizHawk).
- **Textos**: encoding custom (USA) en varias zonas; anclas: `WASHINGTON D.C.` @`0x061CD7A`,
  `PLEASE SELECT` @`0x05FB543`, `BATTLE` @`0x05FAF4C`, `ITEM...WEAPON` @`0x06C33AF`.
- Herramientas: `tools/rommy.py` (Nisitenma US/EU, manifests en `notes/`), `tools/lzkn64`.

## 5. Estado de avance

**Estado actual (2026-09-19 noche-3)**: se juega en Windows; **live a 30 ticks/s** y replay con
`HH_REPLAY_MODE=poll`. **Fase B (ADR 0007)**: cache `cache/trans.bin` + loader LZKN64 nativo.
**CaC en investigación (BLOQUEANTE)**: el port no entra al combate. Dentro del port está demostrado
que la **rama M10/M12 del disable** (freeze/softlock) es causada por el **cambio de escena
prematuro**, y que el input grabado reproduce el fallo. **Pero la comparación port↔emu con ese
replay está en cuestión**: verificado (2026-09-19 noche-3) que el port ejecuta el frame
`FUN_80001454` a **1,03 VI/frame** y el emulador a **2,0**, y que el emulador consume el replay
**~2× más rápido** (0,86-1,0 polls/VI vs 0,5), de modo que sus hitos son inestables
(#12 = `vi 1535` → `vi 2959` con padding → >70 s con stride 2) y el "port ~20 s adelantado" **no
está confirmado**. `HH_VI_EVERY=2` corrige la cadencia pero no el adelanto (vi 436 → 516) ⇒ la
cadencia de frames **no** es la causa. **Siguiente paso**: alinear el input del emulador al `vis`
grabado y re-medir. Detalle y plan: `notes/2026-09-19-verificacion-cadencia-y-harness-replay.md`,
`RETOMAR.md`.
**Estado anterior (2026-09-19 noche-2)**: (era la lectura de la sesión anterior, hoy en cuestión)
se creía el port **~20 s por delante** en la fase pre-transición (objeto de transición `0x801D0474`
en `vi 200` vs emu `347`; loader #12/M24 en `vi 417` vs emu `1535`), con el START capturado por el
port y perdido por el emulador. `ADVANCE=0`/`EVQCHECK=0`/veneno serían síntomas aguas abajo.
Descartados como causa: reloj (`HH_DET_CLOCK`/`quant`), `mode=vi`/`REPLAY_CLOCK`/`PACE=vi`, limiter,
cadencia del replay/callback, cache de assets y `HH_NO_*`. Detalle:
`notes/2026-09-19-inventario-y-nueva-evidencia-fase-previa.md`.
**Estado anterior (2026-09-18)**: `get_function` hacía 4-5 `getenv()` por llamada recompilada; cachear
los flags eliminó los stalls de 1-4 s (8 -> 0) y subió la cadencia tras la puerta a `d2=29-30` (30/s).
**Estado anterior (2026-09-16)**: gameplay en Windows (menús → escenas 3D → combate y cinemáticas) con
mando Xbox y audio a 43200 Hz; **guardado en cápsula validado**; entrega de objeto del NPC, regresión
de escaleras y cuelgue por daño del robot arreglados (fallthroughs de M55 + `HH_S0FIX`); mid-entries
resueltos con `add_mid_entry.py`. Detalle: `notes/2026-09-15-*` y `notes/2026-09-16-*`.

| Fase | Estado | Nota |
|---|---|---|
| 0. Entorno | ✅ | toolchain + repos + Ghidra + assets |
| 1. Análisis estático | ✅/en curso | syms Ghidra; mapa overlay→RAM = tarea #3 (camino crítico, ver ADR 0001) |
| 2. Recompilación | ✅ base | boot + game loop corren (Linux/Windows); pipeline **multi-módulo** + validador (`tools/recomp.py`, `setup_module.py`, `validate_syms.py`) |
| 3. Render (RT64) | ✅ | RT64 renderiza logo/título/attract, cutscenes 3D, **gameplay con HUD** y combate; resolución auto (`HH_RES`). Historia del arranque/VI en `notes/2026-09-1*.md` y `docs/architecture.md` §5. |
| 4. Audio | ✅ base | `aspMain` del ROM + SDL; 43200 Hz; estable. **Futuro**: desacoplar de los fps (ver TODO). |
| 5. Guardado | ✅ | PFS emulado (`pak.cpp`); guardado en cápsula **validado en Windows** (UI de slots + `.pak` en `saves\`) tras el fix `osPfsFindFile`→5 (nota 2026-09-16) |
| 6. Textos/traducción | pendiente | encoding parcialmente localizado |
| 7. Robustez/empaquetado | en curso | build reproducible Linux (`tools/build_linux.sh`) + Docker + CI/Releases (ADR 0005); falta validar en GitHub y empaquetado Deck |

Detalle actual: `TODO.md`. Fuente de verdad técnica: `docs/architecture.md`.

## 6. Riesgos

1. **Módulos de código dinámicos (`trans`)**: base del módulo de boot determinista (ADR 0001);
   riesgo residual = bases de módulos posteriores (aún no medibles).
2. **Símbolos sin decompilación**: límites de Ghidra frágiles → mitigar con validador (TODO A3).
3. **Símbolos con fronteras mal acotadas** (datos absorbidos): causan stubs `do_break` silenciosos
   (caso `M9_FUN_802169ac`, 2026-09-15). Mitigar con `0xADDR:0xSIZE` y revisando avisos
   *"analysis failed (data absorbed...)"* del recompilador.
4. **LZSS 5/7** del `trans`: bloqueante para módulos.
5. **Efectos framebuffer / cinematografía**: verificar en RT64.
6. **Rendimiento/multiplataforma**: RDRAM 32-bit BE + 3 backends.
7. **Accesorios N64 (Controller Pak / Rumble Pak / device type)**: el boot ramifica según el estado
   del SI; ya han mordido input y Expansion Pak. Auditar contra el emulador de referencia (sin mempak
   ni rumble) — ver `notes/2026-09-13-arranque-memsize-y-accesorios.md` §5.

## 7. Estructura de documentación (modelo por capas)

```
/AGENTS.md          # arranque de sesión (1 pantalla)
/PROYECTO.md        # ESTE archivo: contexto + estado (vivo, corto)
/TODO.md            # única lista de tareas (viva, corta)
/RETOMAR.md         # punto de retomada de la sesión actual (handoff, corto)
/docs/
  README.md         # visión y roadmap a largo plazo
  architecture.md   # modelo técnico canónico (vivo)
  documentation.md  # cómo documentar (normativo, leer cada sesión)
  workflows.md      # procedimientos (build, regen, protocolo de imágenes)
  adr/NNNN-*.md     # decisiones inmutables
/notes/             # ARCHIVO histórico append-only (no se mantiene)
  archive/          # docs legacy congelados
  reference/        # datos generados (syms, manifests)
/tools/             # scripts propios; /work y /toolchain gitignored
```

**Normativa detallada: `docs/documentation.md`** (dónde va cada cosa, ciclo de sesión, cuándo crear
un ADR, consolidación y anti-patrones). Resumen: una fuente de verdad por tema; docs vivos cortos;
`notes/` es evidencia (no se edita); ADRs inmutables; nunca editar a mano el C generado.

## 8. Próximos pasos

Ver **`TODO.md`** (sección "Ahora"). Foco actual (2026-09-18): audio (sync de tasa), menú in-game
(ADR 0008, con spike), ADR 0009 (formalizar la estrategia de cobertura nativa) y el teardown SEGV.
**CaC/veneno** sigue en espera (ver Backlog y `notes/2026-09-17-cac-*.md`). Visión a largo plazo:
`docs/README.md`.
