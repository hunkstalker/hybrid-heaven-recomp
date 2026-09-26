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
- **Alta tasa de refresco (movimiento suave)**: RT64 presenta hasta el refresco del monitor
  interpolando los frames de 30 Hz del juego (la lógica sigue a 30 Hz). `HH_REFRESH_RATE=original`
  y/o `HH_PRESENT_EARLY=0` recuperan el comportamiento anterior.
- **Widescreen** con **anclaje del HUD/minimapa** a los bordes; ajustes `[video]` en `config.ini`
  (aspecto, resolución nativa/4K/8K, MSAA, borderless/windowed) y atajos **F2** (aspecto) y **F3**
  (ventana); **F1** abre el Inspector de RT64 con `HH_DEVELOPER=1`.
- **Mando + teclado** (mapeo fijo; D-pad↔stick para navegar menús).
- **Guardado** en cápsula (Controller Pak emulado → `saves/*.pak`).
- **Cache de assets** + descompresor **LZKN64** nativo; módulos de código vía `trans`.
- Build **reproducible**, CI y *Releases* (Windows `.zip`, Linux `.tar.gz`, imagen Docker).

## Estado (punto de control)

**Sin bloqueantes conocidos**: validado en Windows, jugado **hasta el nivel 2-1** (tras el primer
jefe) sin cuelgues ni crashes.

- **Guardado/carga** (cápsula) y **mando** validados; **widescreen** con HUD/minimapa anclados en
  todas las escenas.
- **Alta tasa de refresco**: presenta hasta el refresco del monitor mediante **interpolación de frames**.
- Teardown limpio (sin SEGV al salir).
- **Único problema conocido**: fallos **visuales** por la **interpolación de frames** (p. ej. una
  puerta y el primer jefe del nivel 1); con `Refresh Rate = Original` desaparecen. El arreglo de
  fondo implica desacoplar la lógica del juego del render (ver `TODO.md`).

Limitaciones y pendientes (detalle en `TODO.md`): menú multijugador (SEGV, fuera de alcance),
audio atado al tick de 30 Hz, extracción/traducción de textos, y validación de Steam Deck.

## Jugar (recomendado)

Descarga el `.zip` (Windows) o `.tar.gz` (Linux) de **Releases**, descomprime y **coloca tu ROM** en
la carpeta `rom/` junto al ejecutable (o en la propia carpeta del `.exe`). Vale **cualquier `.z64`**:
el port los detecta **por formato**, el nombre da igual (si hay varios, usa la primera válida).

Debe ser la versión **USA** de Hybrid Heaven (`NHVE`, 16 MB, ROM big-endian, sin byteswap). Para
comprobar que es la correcta, su **SHA-1** es:

```
16dbc21620b52deab5c5abf8a309ac60adfbee85
```

En Windows puedes verificarlo con `certutil -hashfile TU_ROM.z64 SHA1`. Si el ROM no es válido, el
port lo avisa al arrancar indicando el hash esperado. La ROM **no se distribuye** (© Konami): la
aporta cada usuario.

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

### Créditos

- **Repo de referencia**: [danielgomesvieira2000/hybrid-heaven-recomp](https://github.com/danielgomesvieira2000/hybrid-heaven-recomp)
  (**MIT**) — tooling de recompilación por ELF adaptado (detalle en [`CREDITS.md`](CREDITS.md)).
- **Sonidos del menú** (de [Pixabay](https://pixabay.com/); [licencia de contenido de Pixabay](https://pixabay.com/service/license-summary/):
  uso libre y modificación permitidos, **sin obligación de atribución** — la damos igualmente):
  - *Menu Move* — «Game UI Confirm Selection Sound #2 UI» de **Vadim_Makes_Sound**.
  - *Menu Accept* — «UI Sound 115» de **juniorsoundays**.
  - *Menu Back* — «UI Sound 116» de **juniorsoundays**.
