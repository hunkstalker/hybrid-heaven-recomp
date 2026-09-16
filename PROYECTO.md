# PROYECTO — Hybrid Heaven: Recompiled (contexto maestro)

> **Fuente de verdad del contexto y el estado.** Mantenerlo corto (≈1-2 pantallas).
> Tareas → `TODO.md`. Arquitectura y decisiones → `docs/architecture.md` + `docs/adr/`.
> Histórico y evidencia → `notes/` (no editar). Última actualización: **2026-09-16**.

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
SDL2. Microcode gfx **F3DEX2 fifo 2.06** (RT64 lo soporta nativo). Audio: **`aspMain` del ROM**
recompilado con RSPRecomp (`rsp/hh_aspMain.cpp`), reproducción a **43200 Hz** (720 frames/VI) con
feedback de cola; dispositivo WASAPI vía SDL. Release por defecto (Debug caía a 30 fps).

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

**Estado actual (2026-09-16)**: se juega en Windows (menús → GAME START → escenas 3D y combate) con
mando Xbox (perfiles `config.ini`), audio a 43200 Hz y guardado/Controller Pak emulado. Arreglados y
**validados en Windows**: la **entrega del objeto del NPC** (fallthrough en módulo 55 — fuga `0x48`/
frame + animación saltada — y mid-entries `0x80379954`/`0x803798E8`; el módulo 55 es el overlay de
la secuencia de objeto, ver `docs/architecture.md` §2.2), la **regresión de las escaleras** (partir
un switch fusionado) y el **cuelgue por daño del robot** en dos capas: `s0` (r16) machacado por la
cadena del frame (fix runtime `HH_S0FIX`) y, ya caído, el personaje que no se levantaba por un
**fallthrough ausente al final de `M55_FUN_8037a6f4`** (fuga `0x38`/frame + lógica de caída saltada;
nueva regla de ramas condicionales en `fix_fallthroughs.py`). Instrumentación de crash/cuelgue y
bats de regresión en el repo. Detalle: `notes/2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md`
y `notes/2026-09-16-fix-caida-fallthrough-m55-8037a6f4.md`.

| Fase | Estado | Nota |
|---|---|---|
| 0. Entorno | ✅ | toolchain + repos + Ghidra + assets |
| 1. Análisis estático | ✅/en curso | syms Ghidra; mapa overlay→RAM = tarea #3 (camino crítico, ver ADR 0001) |
| 2. Recompilación | ✅ base | boot + game loop corren (Linux/Windows); pipeline **multi-módulo** + validador (`tools/recomp.py`, `setup_module.py`, `validate_syms.py`) |
| 3. Render (RT64) | ✅ | RT64 renderiza logo/título/attract, cutscenes 3D, **gameplay con HUD** y combate; resolución auto (`HH_RES`). Historia del arranque/VI en `notes/2026-09-1*.md` y `docs/architecture.md` §5. |
| 4. Audio | ✅ base | `aspMain` del ROM + SDL; 43200 Hz; estable. **Futuro**: desacoplar de los fps (ver TODO). |
| 5. Guardado | pendiente | Controller Pak → disco |
| 6. Textos/traducción | pendiente | encoding parcialmente localizado |
| 7. Robustez/empaquetado | pendiente | 3 builds (Win/Linux/Deck) |

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

Ver **`TODO.md`**. Foco inmediato: **abrir cajas de ítem y seguir la partida** (con el ciclo del
robot re-verificado: daño → caída → levantarse). Después: teardown SEGV al cerrar, limpieza de
instrumentación, botón de los menús de combate para X y validación del guardado contra el emulador.
