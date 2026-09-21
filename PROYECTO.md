# PROYECTO — Hybrid Heaven: Recompiled (contexto maestro)

> **Fuente de verdad del contexto y el estado.** Mantenerlo corto (≈1-2 pantallas).
> Tareas → `TODO.md`. Arquitectura y decisiones → `docs/architecture.md` + `docs/adr/`.
> Histórico y evidencia → `notes/` (no editar). Última actualización: **2026-09-21**.

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

**Estado actual (2026-09-21)**: **migración a la vía de recompilación de la referencia (ADR 0011)
COMPLETADA hasta M4**, y **validada en Windows**: se abandonó Ghidra-per-file por **ELF desde
splat/spimdisasm + residente limpio + gates** (M0–M3). Causa raíz de la regresión (título sin 3D):
N64Recomp en ELF mode no aplicaba `use_lookup_for_all_function_calls` (llamadas directas saltaban los
hooks de loader); arreglado en el tool. **Playtest del mantenedor**: START → menú → GAME START →
gameplay, primer NPC, cajas, **primer CaC y combate**, y ~30 min hasta el **6º combate sin cuelgues ni
crashes** → **el bloqueante original (entrar al CaC) está RESUELTO**. **M5 HECHO** (saneamiento y
estructura: vía Ghidra→`legacy/`, `config/`→`recomp/`, intermedios→`build/recomp/`, docs vivas +
créditos, purga `HH_*`; **pendiente solo el push**). **M4c HECHO** (SEGV de teardown resuelto: el
runtime liberaba RDRAM y el planificador seguía despachando hilos al salir; fix en el fork NMR: no
liberar RDRAM + parar el planificador). Plan general:
`notes/2026-09-21-migracion-via-referencia-elf.md`; detalle: `notes/2026-09-21-m4c-teardown-segv.md`.
Además: `lib/` como **submódulos** (ADR 0010) y el C recompilado materializado como dir real.
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

Ver **`TODO.md`** (sección "Ahora"). Foco actual (2026-09-21): cerrar el **push** (forks + main) y
validar el cierre en Windows (M4c). Visión a largo plazo: `docs/README.md`.
