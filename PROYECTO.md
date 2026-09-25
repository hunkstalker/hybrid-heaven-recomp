# PROYECTO — Hybrid Heaven: Recompiled (contexto maestro)

> **Fuente de verdad del contexto y el estado.** Mantenerlo corto (≈1-2 pantallas).
> Tareas → `TODO.md`. Arquitectura y decisiones → `docs/architecture.md` + `docs/adr/`.
> Histórico y evidencia → `notes/` (no editar). Última actualización: **2026-09-22**.

## 1. Objetivo

Port nativo a PC de **Hybrid Heaven** (N64, Konami/KCEO, 1999, proyecto interno **RZ011**) por
**recompilación estática** (N64Recomp + RT64 + N64ModernRuntime), **sin emulador**, leyendo la ROM
del usuario. Sub-objetivo obligatorio: **extraer y traducir todo el texto**. Plataformas:
**Windows + Linux + Steam Deck** (mismo código). Legal: no se distribuyen ROM ni assets.

## 2. Entorno

| Ítem | Valor |
|---|---|
| Proyecto | raíz de este repo |
| Toolchain | gcc/g++ 15, cmake 4.2, ninja, SDL2, LLVM MIPS (`llvm-mc`/`ld.lld`) + splat/spimdisasm; Ghidra + N64LoaderWV solo vía legacy |
| Repos de referencia | N64Recomp, N64ModernRuntime, RT64, Zelda64Recomp y un port de Konami coetáneo (`toolchain/`, gitignored) |
| Derivados | `work/` y `toolchain/` gitignored (datos derivados, Ghidra, builds, artefactos) |

## 3. Arquitectura (resumen)

Stack: **N64Recomp** (MIPS→C) + **N64ModernRuntime** (`ultramodern`+`librecomp`) + **RT64** +
SDL2. Microcode gfx **F3DEX2 fifo 2.06** (RT64 lo soporta nativo). Audio: **`aspMain` del ROM**
recompilado con RSPRecomp (`build/recomp/rsp/hh_aspMain.cpp`, generado), reproducción a **43200 Hz** (720 frames/VI) con
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

**Estado actual (2026-09-26, v0.4.4)**: **issues #3 y #7 CERRADOS y validados en Windows** — el HUD
de combate y el **minimapa** se anclan enteros en widescreen en todas las escenas/capítulos:
POWER/STAMINA por hash de contenido (`d820d8e`), disco plateado del radial por hash+caja
`27,19,59,51`, barra de combo (4 `G_FILLRECT` en `y=28..30`) y **stamina gastada** (`G_FILLRECT` en
`y=34..38`) por posición, y **minimapa** por hash de contenido de su lista. Herramienta: **F7 =
captura pareada** (traza + imagen). `notes/2026-09-25-f-hud-combate-contenido.md` ·
`notes/2026-09-26-fix-minimapa-contenido.md`. Antes: **mapa widescreen (fase 07b)
validado** (`notes/2026-09-22-fix-mapa-rect-negro-widescreen.md`); **migración ELF (ADR 0011) hasta M4**
validada en Windows (playtest CaC ~30 min sin cuelgues). **M5** (saneamiento) y **M4c** (SEGV
teardown, fix en fork NMR) hechos. Plan general:
`notes/2026-09-21-migracion-via-referencia-elf.md`. Además: `lib/` como **submódulos** (ADR 0010).
**Historial (detalle en `notes/`)**: reset per-file 2026-09-20 (causa del bloqueo de boot/CaC, superado
por la vía ELF); antes, live 30 ticks/s + replay y CaC investigado por el scheduler de eventos; 2026-09-18
cacheo de flags de `get_function` (stalls); 2026-09-16 guardado en cápsula y fixes de M55/`HH_S0FIX`.

| Fase | Estado | Nota |
|---|---|---|
| 0. Entorno | ✅ | toolchain + repos + Ghidra + assets |
| 1. Análisis estático | ✅/en curso | syms Ghidra; mapa overlay→RAM = tarea #3 (camino crítico, ver ADR 0001) |
| 2. Recompilación | ✅ base | boot + game loop corren (Linux/Windows); pipeline **ELF/splat** (ADR 0011; vía Ghidra multi-módulo archivada en `legacy/`) |
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

Ver **`TODO.md`** (sección "Ahora"). Foco actual (2026-09-22): menú IN-GAME, smoke de arranque,
ADR 0009. Pendiente inmediato: **publicar Release `v0.3.0`** (tag; ver `RETOMAR.md`). Visión:
`docs/README.md`.
