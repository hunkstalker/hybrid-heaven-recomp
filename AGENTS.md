# AGENTS.md — arranque de sesión

Port nativo de **Hybrid Heaven (N64)** a PC (N64Recomp + RT64 + N64ModernRuntime). Windows + Linux + Steam Deck.
Fase actual: **fundaciones de diseño** (modelo de módulos `trans`). El boot corre pero se bloquea al
ejecutar un módulo descomprimido (`0x80107830`). Ver `TODO.md` y `docs/adr/0001-modelo-de-modulos.md`.

## Lee esto (y solo esto) al empezar

1. **`docs/documentation.md`** — cómo documentar (normativo; leer cada sesión).
2. **`PROYECTO.md`** — contexto y estado (corto).
3. **`TODO.md`** — qué toca ahora.
4. **`docs/architecture.md`** — modelo técnico (memoria, `trans`, runtime).
5. Bajo demanda: `docs/workflows.md` (procedimientos), `docs/adr/`, `notes/` (evidencia), `notes/archive/`.

## Al cerrar sesión

Sigue el checklist de `docs/documentation.md` §3: actualizar `TODO.md` y `PROYECTO.md`, escribir una
nota fechada en `notes/`, y crear un ADR si hubo decisión estructural. No commitear salvo petición.

## Calibración crítica

- **Visión disponible** (verificado 2026-09-11; modelo DeepSeek V4.1 Flash): puedo leer imágenes.
  Aun así el usuario **no ve adjuntos del chat** → los PNG se guardan en archivo y él los abre desde
  su filesystem. Usar la visión con criterio (cada imagen consume contexto); para análisis masivo de
  frames preferir representaciones baratas (ASCII/estadísticas). Si cambia el modelo, re-verificar.
- **Imágenes por lotes**: triaje con `tools/analysis/triage_screenshots.py` y lectura en lotes de
  2-3 volcando cada imagen a texto. Ver `docs/workflows.md` §3.
- Dumps RDRAM del harness Linux vienen **word-swapped** → bswap32. En BizHawk leer CPU BE.
- Regla de oro: **nunca editar a mano el C generado** (`RecompiledFuncs/`). Todo fix va a `config/*.syms.toml`.
- Tras regenerar: `python3 tools/analysis/fix_fallthroughs.py` y añadir `osYieldThread_recomp` a `funcs.h` si falta.
- No commitear sin pedirlo. No tocar ROMs ni `work/*.so` sin pedirlo.

## Comandos y workflows

Ver **`docs/workflows.md`** (recompilar, build, run headless, protocolo de imágenes).

## Inventario

- `PROYECTO.md`, `TODO.md`, `AGENTS.md` — docs vivos. · `docs/` (architecture, workflows,
  documentation) y `docs/adr/` — técnico/decisiones.
- `config/` — `game_unified.toml`, `us_ghidra.syms.toml`, `RecompiledFuncs_unified/`.
- `port/HybridHeavenRecomp/` — port (CMake, `RecompiledFuncs/`, `src/`, `lib/`, builds).
- `tools/` — scripts propios. · `notes/` — histórico (no editar). · `work/`, `toolchain/` — gitignored.
