# PROYECTO — Hybrid Heaven: Recompiled (contexto maestro)

> **Fuente de verdad del contexto y el estado.** Mantenerlo corto (≈1-2 pantallas).
> Tareas → `TODO.md`. Arquitectura y decisiones → `docs/architecture.md` + `docs/adr/`.
> Histórico y evidencia → `notes/` (no editar). Última actualización: **2026-09-13**.

## 1. Objetivo

Port nativo a PC de **Hybrid Heaven** (N64, Konami/KCEO, 1999, proyecto interno **RZ011**) por
**recompilación estática** (N64Recomp + RT64 + N64ModernRuntime), **sin emulador**, leyendo la ROM
del usuario. Sub-objetivo obligatorio: **extraer y traducir todo el texto**. Plataformas:
**Windows + Linux + Steam Deck** (mismo código). Legal: no se distribuyen ROM ni assets.

## 2. Entorno

| Ítem | Valor |
|---|---|
| Proyecto | `/app/hybrid-heaven-recomp/` |
| ROM USA | `/app/baserom.us.z64` (z64 BE, ID NHVE, MD5 `da861c4d9202f661575466450a27c412`) |
| ROM Europa | `/app/baserom.eu.z64` (ID NHVP, MD5 `c47e95bb32ab132c41d67bd243f9e02a`) |
| Toolchain | gcc/g++ 15, cmake 4.2, ninja, SDL2, JDK 21 + Ghidra 12.1.3 + N64LoaderWV |
| Repos | N64Recomp, N64ModernRuntime, RT64, Zelda64Recomp, Goemon64Recomp (en `toolchain/src/`) |
| Derivados | `work/` y `toolchain/` gitignored (ROMs descomprimidas, Ghidra, builds, artefactos) |

## 3. Arquitectura (resumen)

Stack: **N64Recomp** (MIPS→C) + **N64ModernRuntime** (`ultramodern`+`librecomp`) + **RT64** +
SDL2. Microcode gfx **F3DEX2 fifo 2.06** (RT64 lo soporta nativo). Audio: microcode custom KCEO
**sin identificar** (no matchea `aspMain`); bloquea audio real, no el render.

**Modelo unificado: imagen plana + módulos.** El boot es una imagen de código plana; el juego
descomprime módulos de código de la ROM a RAM y los ejecuta vía `trans`. → `docs/architecture.md`.

Decisiones de fondo pendientes: `docs/adr/0001-modelo-de-modulos.md`.

## 4. Hallazgos técnicos clave (ROM)

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

| Fase | Estado | Nota |
|---|---|---|
| 0. Entorno | ✅ | toolchain + repos + Ghidra + assets |
| 1. Análisis estático | ✅/en curso | syms Ghidra; mapa overlay→RAM = tarea #3 (camino crítico, ver ADR 0001) |
| 2. Recompilación | ✅ base | boot + game loop corren (Linux/Windows); pipeline **multi-módulo** + validador (`tools/recomp.py`, `setup_module.py`, `validate_syms.py`) |
| 3. Render (RT64) | ✅ arranque/attract | RT64 **procesa DLs** (wiring OK) y renderiza logo/título/attract 3D (capturas `work/debug/port_shot_*.png`); falta el gameplay. Arranque corregido en dos tandas: (1) 4 MB de RDRAM, (2) **des-stubbing de la init de libultra** (ADR 0002: `osInitialize`, PI manager, VI, `__osEventStateTab`…). El port **no aborta** y su cadena de boot coincide con el emulador. **Desbloqueado (ADR 0003)**: subsistema VI generado del ROM (`osCreateViManager` + familia `osVi*`), runtime solo hardware (registros MMIO → RT64); `OSViContext` correcto, dispatcher 430/45 s, loader 10 módulos, **1359 DLs** a RT64, 0 símbolos faltantes. **Deadlock SP resuelto** (completaciones dirigidas al hilo emisor; dispatcher 3723/300 s, `[0x8005CD4C]` oscila) y **mapa task→hilo corregido** (audio dirigido a t18). Sigue en `fase=0` con **causa raíz identificada y primer hito hecho**: la transición del emulador (burst a t≈65 s, evento de módulo `0x7D`) depende del **ucode de audio**; su **aspMain ya está recompilado con `RSPRecomp` e integrado** (`port/HybridHeavenRecomp/rsp/hh_aspMain.cpp`, `config/rsp_hh_aspMain.toml`, registro en `hh::get_rsp_microcode`), corre sin errores y procesa los comandos reales (incluidos cmd `0x0E/0x0F`, targets `0x170C/0x144C` añadidos). **Fix del protocolo gfx/audio**: `sp_complete` del gfx en el submit + `HH_SP_SHARED` (cola compartida) ⇒ **~60 tasks/s con 0 yields**. **Resuelta la corrupción de contextos de audio** (cadena: burst de ticks → cola virtual sobre la ventana del driver → tamaño `s16` negativo ~4 GiB en `osAiSetNextBuffer` → `osAiGetLength` envenenado → command lists runaway que DMA sobre las voces): fixes en `ai.cpp` (ignorar byte_counts absurdos) y `support.cpp` (cola virtual acotada a ~1 VI); **300-420 s sin crash, ~18k tasks, voces intactas**. **Frontera actual (2026-09-14)**: **geometría y píxeles alcanzados** — RT64 renderiza el logo, la pantalla de título ("PRESS START BUTTON" + copyright Konami) y el attract 3D (`work/debug/port_shot_{45,80,120,160}.png`; `notes/2026-09-14-geometria-pixeles.md`), tras implementar el **registro dinámico de módulos** (bases de VRAM reutilizadas) y los fixes de símbolos/aliasing. Siguiente: **entrar en gameplay** (input para "PRESS START"; fase `0x80037750`) y robustez de cierre (SEGV del teardown en código de módulo). Detalle: `notes/2026-09-14-registro-dinamico-modulos.md`, ADR 0004 |
| 4. Audio | en curso | ucode **aspMain del ROM** recompilado y corriendo (~60 tasks/s); sin crashes en 420 s. Falta la cadena de eventos de módulo (transición) |
| 5. Guardado | pendiente | Controller Pak → disco |
| 6. Textos/traducción | pendiente | encoding parcialmente localizado |
| 7. Robustez/empaquetado | pendiente | 3 builds (Win/Linux/Deck) |

Detalle actual: `TODO.md`. Fuente de verdad técnica: `docs/architecture.md`.

## 6. Riesgos

1. **Módulos de código dinámicos (`trans`)**: base del módulo de boot determinista (ADR 0001);
   riesgo residual = bases de módulos posteriores (aún no medibles).
2. **Símbolos sin decompilación**: límites de Ghidra frágiles → mitigar con validador (TODO A3).
3. **Cadena de eventos de módulo hasta la transición** (`0x7D`): el ucode de audio ya corre
   (aspMain estándar recompilado); el bloqueo es la programación del motor de audio y los callbacks
   del nodo `0x801D0474`.
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
/docs/
  README.md         # plan de alto nivel por fases
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

Ver **`TODO.md`**. Modelo de módulos caracterizado y ADR 0001 aceptado. Foco inmediato: **cadena de
eventos de módulo / nodo `0x801D0474`** (work order `notes/2026-09-13-workorder-evento-modulo-0x7D.md`)
para disparar la transición y llegar a geometría/píxeles.
