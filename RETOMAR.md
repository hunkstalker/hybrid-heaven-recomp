# RETOMAR — handoff RAMA `fps-interpolacion-tagging` (2026-10-04, sesión 5)

> **TAREA (rama): interpolación fiel / desbloquear FPS.** La **cámara** quedó resuelta (`46b3f0d`) y
> **A2.2d (efectos/2D pasada 2) CERRADA**: los efectos los dibuja `C768` (materializa); el resto de
> emisores queda huérfano por la frontera de workload; la opción core (a) fue **inerte** y se revirtió;
> las capturas de efectos son **transitorios**, no fallos. Detalle completo:
> `notes/2026-10-04-fps-a2-2d-emisores-y-capturas-transitorias.md`.
> Reglas: `AGENTS.md` y `docs/documentation.md`. La vista no valida 1 frame → capturas **+ ojo**.

## Estado — lo que funciona (MEDIDO, run del mantenedor)

- **Sesgado de cámara RESUELTO** (`46b3f0d`, port-only): `emitter_wrap()` emite un `gEXMatrixGroup` de
  PROYECCIÓN (`proj=1`) con id de cámara ligado a la generación → snap del encuadre en los cortes.
- **A2.2d CERRADA**: el emisor de los efectos es **`func_8000C768`** (tipo 6/12) y **materializa**
  (`hh_pairdump.log` 100% `id=EE0F…`; `explicit_ids` 0→~2.300/s). Cobertura **98.6%** con id.
- `emitter_wrap` (`7DE4/82C4/8754/8B9C/8F30/D1CC/A06C/13828`): sus grupos **NO** materializan (frontera
  de workload; `emitmat=[15:…]`). Por eso su geometría va AUTO/heurística (sin fallo visual observado).
- **Capturas = transitorios**: ningún id con racha de no-emparejado >3 frames; la transición de puerta
  es **cambio de generación** (mismas posiciones, ids nuevos) → snap correcto.
- **Arreglados** (previo): huesos del PJ, **#6/#8** (aura del jefe; gate de escala), minas/láseres.

## TAREA SIGUIENTE — partículas de sprites al curarse (visual)

- **Síntoma**: al **curarse**, las partículas de sprite se ven como **cuadrados con degradado**.
  Sospecha del mantenedor: **alpha** de sprite. Es **distinto de #10** (huesos) — #10 no se ha vuelto
  a ver.
- **A investigar**: path de sprite/2D (sprite `gEX`, `texrect`, o alpha del RDP). Reproducir al curar
  y comparar con emulador si hace falta.
- **A2.4 LOD**: localizar el campo de LOD del modelo o cerrar como "no aplica" (sin caso observado).
- **#10**: sin síntoma reciente → cubierto salvo indicios nuevos.

## Instrumentación (reutilizable; se conserva a propósito)

- `HH_MTXGROUP=1` tagging; `HH_MTXGROUP_LOG=1` → `[hh-types]`, `[hh-mtxgroup]`, `[hh-emit]`.
- `HH_EMIT_TAG=1` (alias `HH_FX_EMIT`) → tagging de emisores/cámara (`C768` incluido).
- `HH_FX_PASS2=1` → registra hooks de emisores de pasada 2 (traza).
- `HH_PAIRING=1` → `[hh-pair]`, ahora con **`emitmat=[code:count …]`** (materializaciones por emisor:
  codes 4–14 `emitter_wrap`, 15 `C768`).
- `HH_PAIRCAP=<min moved>` / `HH_GENCAP=1` → `paircap_*/gencap_*.bmp` + `[hh-cap]`.
- `HH_PAIRING_DUMP=<min moved>` → `hh_pairdump.log` (append: borrar antes de cada run).
- `HH_SCALE_GATE` (def. ON 2.0; `=0` off), `HH_ROT_GATE` (sonda), `HH_CAPMAX=<n>`.
- **OJO**: `unpaired` **no** mide mal-emparejamiento. Validar transitorios por **racha de frames** del
  `id` en el dump, no por capturas sueltas.

### Run del mantenedor (validación)

```powershell
hybrid-heaven-recomp\build_windows.local.bat
$env:HH_MTXGROUP='1'; $env:HH_PAIRING='1'; $env:HH_MTXGROUP_LOG='1'; $env:HH_FX_PASS2='1'; $env:HH_EMIT_TAG='1'; $env:HH_PAIRCAP='2'; $env:HH_GENCAP='1'; $env:HH_PAIRING_DUMP='1'
hybrid-heaven-recomp\run_windows.bat release
```
Logs en `build\windows\bin\Release\` (`hh.log`, `hh_pairdump.log`, capturas).

## Árbol

- `src/hooks/model_tagging.cpp` (tagging + `emitter_wrap` cámara/modelview + `C768` unificado),
  `sections.cpp` (hooks), `rt64_render_context.cpp` (`[hh-pair]` + `emitmat`),
  `patches/rt64/hh-interpolation-tagging.patch` (instrumentación del fork).
- `lib/rt64` SUCIO (fork): la instrumentación vive en el patch; **no commitear el submódulo**.

## Pitfalls (NO repetir)

- El tagging por emisor **solo** materializa donde la geometría va en el mismo workload (`C768`);
  materializar en el `push` (plan 1) **no** cruza la frontera. Solo la cruzaría el "grupo activo"
  cross-workload (rompe HUD) o un rewrite en `send_dl`.
- **NO** envolver los emisores 2D de menú (`7750/78AC/79B0`, `919C/11958`, `A828`): congela.
- `unpaired` **no** es "mal emparejado": un id nuevo en 1 frame es normal (efecto/estado/teletransporte).
- **NO** `git reset --hard`; no editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
