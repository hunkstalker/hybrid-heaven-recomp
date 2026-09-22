# Hybrid Heaven Recomp (N64 → PC)

Port nativo a PC de **Hybrid Heaven** (N64, Konami/KCEO, 1999, proyecto interno **RZ011**),
por **recompilación estática** (sin emulador) con el stack N64Recomp + RT64 + N64ModernRuntime.
Plataformas objetivo: **Windows, Linux y Steam Deck**.

> **⚠️ Proyecto EN DESARROLLO (fase temprana).** Puede haber fallos, incompatibilidades y
> regresiones que rompan partidas guardadas; las builds de *Releases* son de prueba. El estado real
> y las tareas viven en `PROYECTO.md` y `TODO.md` (aquí no se duplican).

## Características

- **Recompilación estática** del binario original (sin emulador), microcódigo gfx **F3DEX2** y
  **audio `aspMain` del ROM** recompilado (~43.2 kHz, sin petardeo).
- **Widescreen** con **anclaje del HUD/minimapa** a los bordes; ajustes `[video]` en `config.ini`
  (aspecto, resolución nativa/4K/8K, MSAA, borderless/windowed) y atajos **F2** (aspecto) y **F3**
  (ventana); **F1** abre el Inspector de RT64 con `HH_DEVELOPER=1`.
- **Mando + teclado** (mapeo fijo; D-pad↔stick para navegar menús).
- **Guardado** en cápsula (Controller Pak emulado → `saves/*.pak`).
- **Cache de assets** + descompresor **LZKN64** nativo; módulos de código vía `trans`.
- Build **reproducible**, CI y *Releases* (Windows `.zip`, Linux `.tar.gz`, imagen Docker).

## Estado (punto de control)

**Sin bloqueantes conocidos para terminar el juego** (revisión del mantenedor, 2026-09-22):

- **Validado en Windows**: START → menú → GAME START → gameplay, primer NPC, cajas, primer CaC y
  combate, y una sesión de ~30 min hasta el **6º combate** sin cuelgues ni crashes.
- **Guardado/carga** (cápsula) y **mando** validados; **widescreen** con HUD/minimapa anclados.
- Teardown limpio (sin SEGV al salir).

Limitaciones y pendientes (detalle en `TODO.md`): menú multijugador (SEGV, fuera de alcance),
audio atado al tick de 30 Hz, extracción/traducción de textos, y validación de Steam Deck.

## Jugar (recomendado)

Descarga el `.zip` (Windows) o `.tar.gz` (Linux) de **Releases**, descomprime y **coloca tu ROM** en
la carpeta `rom/` junto al ejecutable: `rom/baserom.us.z64` (Hybrid Heaven **USA**, `NHVE`, 16 MB).
La ROM **no se distribuye** (© Konami): la aporta cada usuario.

## Compilar (rápido)

Compilar requiere la ROM **una vez** (para regenerar el C recompilado) y las dependencias del
sistema; el C generado **no se versiona** (ADR 0009).

| Plataforma | Comando |
|---|---|
| Windows | `build_windows.bat` |
| Linux | `tools/build_linux.sh` |

Guías completas: `docs/BUILDING_windows.md`, `docs/BUILDING_linux.md`, `docs/workflows.md`.
Regenerar el C (solo mantenedores): `python3 tools/regenerate.py`.

## Documentación

- `PROYECTO.md` — contexto maestro y estado. · `TODO.md` — tareas. · `RETOMAR.md` — handoff de sesión.
- `docs/` — arquitectura, ADRs, workflows y guías de build. · `notes/` — notas de sesión (histórico).

## Licencia y créditos

**GPL-3.0** — ver [`LICENSE`](LICENSE). Es un proyecto **público y comunitario**: nace de
recompilación estática con ayuda de IA (entrenada con código de la comunidad) y devuelve el
resultado a la comunidad con las mismas libertades. Se apoya en **N64ModernRuntime** (GPL-3.0),
**N64Recomp** y **RT64** (MIT) y xxHash/miniz/o1heap; autoría y commits exactos: [`CREDITS.md`](CREDITS.md).
El repositorio **no** incluye la ROM de Hybrid Heaven (© Konami).
