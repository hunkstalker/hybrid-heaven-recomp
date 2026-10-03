# RETOMAR — handoff (2026-10-02)

> Handoff para la próxima sesión. **Estado: `main` = `v0.6.1` (publicada)** + fixes del día (#13 minimapa,
> #14 jump tables, textos al guardar, número de Área, glifos del ordenador).
> **TAREA ACTUAL (épica): desbloquear los FPS** — presentar al máximo del hardware **sin artefactos** de
> interpolación. Cubre los **4 issues abiertos**: #6 Procyon, #8 puertas, #10 enemigos al curar,
> #12 Life Charger S. **Plan + catálogo + análisis:** `notes/2026-10-02-workorder-desbloquear-fps-interpolacion.md`.
> **Estado de la sesión (2026-10-02, noche):** el fallo ya se **mide** (contador de emparejamiento
> `HH_PAIRING`, fork `lib/rt64`); #6 `unpaired_moved` pica a ~98/s (aura), #8 ~30/s; **ignored=0**
> (no hay tagging). Plan siguiente = reescribir la DL en submit (dedupe de matrices + orden +
> `gEXMatrixGroup`). Detalle: `notes/2026-10-02-fps-instrumentacion-pairing-y-plan-identidad.md`.
> Los gates `HH_ROT_GATE`/`HH_SCALE_GATE` y F9 quedan **aparcados** (sonda, no arreglo); `lib/rt64`
> sucio; **nada validado en Windows ni commiteado**.
> Detalle y aviso de método: `notes/2026-10-02-fps-interpolacion-estado-y-handoff.md`.
> Reglas: `AGENTS.md` y `docs/documentation.md`.

## Tarea actual — desbloquear FPS / arreglar interpolación

- **Medido:** la lógica de HH es **30 fps**; RT64 **interpola** 30→refresco del monitor. Sin
  `gEXMatrixGroup` el emparejamiento es **heurístico** (`matchScenes`/`computeTransformMatch`) y
  `updateAngular` **siempre** interpola rotación/escala (`// FIXME`), a diferencia de la traslación
  (que sí tiene *auto-gate* en `updateLinear`).
- **Los 4 issues son de interpolación** (workaround `HH_REFRESH_RATE=original` / F9).
- **Fase A** (elegida): lógica 30 Hz + present a refresco, quitando artefactos. **Fase B** (después):
  spike de simulación 60 Hz real (→ ADR). Fases A0–A3/B/C en el work-order.

### Ya implementado

- **Métrica de emparejamiento (validada Linux build; usada en Windows esta sesión):**
  `lib/rt64/src/hle/rt64_game_frame.cpp` cuenta transforms totales/ignorados/no-emparejados/
  no-emparejados-movidos y los expone por `RT64_GetTransformPairing`; el port los imprime a
  `hh.log` con **`HH_PAIRING=1`** (`[hh-pair]`). **`HH_PAIRING_DUMP=<n>`** vuelca en picos la
  identidad de cada uno (a stderr). Logs de referencia en `tests/logs/` (gitignored).
- **Aparcado (sonda, no arreglo):** `HH_ROT_GATE`/`HH_SCALE_GATE` (snap global; no cubren #8) y
  **F9** (`src/subsystems/input.cpp`, interpolación ON/OFF). Off por defecto.
- `lib/rt64` está **sucio** (submódulo por commitear). **No** validado en Windows como arreglo.

### Pitfall (NO repetir)

**F7** (`hh_cap_N.bmp/.log`) es la **captura pareada del HUD (identidades 2D)**, no sirve para
artefactos 3D. Y **un still no muestra** un flash de 1 frame ni una animación que se repite. Para
discontinuidades: **A/B visual**, **Inspector F1** (`HH_DEVELOPER=1`) o vídeo + `ffmpeg` (en el
contenedor). No pedir capturas F7 para esto.

### Siguiente paso concreto

1. **Vía Goemon** (la reescritura de DL se **descartó** tras fallar 2×; ver nota §6b/§6c). Goemon
   (en `/app/goemon-sourcecode`, mismo motor Konami) **no reescribe DLs**: **parchea las funciones del
   juego** (`RECOMP_PATCH`) y emite `gEXMatrixGroup*`/`gEXPopMatrixGroup` envolviendo el draw, con ID
   **estable = puntero del objeto** (`TAGGING_GENERATE_ID((u64)root_object<<32 | dl_addr)`) y `skip`
   desde la lógica. **Localizar en HH** las funciones de dibujo de esqueleto/objeto (análogas a
   `func_80018908`/`func_80018CA0` de Goemon). **[HECHO] Localizada** la cadena de dibujo de HH:
   traversal `func_800068C0_74C0` → dispatch `func_800069A8_75A8` → malla `func_8000C768_D368` →
   **`G_MTX` de hueso `func_8000C4A8_D0A8`** (nodo DOBJ: `+0x1C` gmtx, `+0x2C` modelo). **[HECHO] El
   encaje ya existe**: los hooks del port (`recomp::overlays::add_loaded_function`, ~20 ya en uso)
   son el `RECOMP_PATCH` de Goemon; no hay que montar `patches.elf`. Siguiente: hook sobre
   `0x8000C4A8` con `gEXMatrixGroup*` + ID = puntero DOBJ + `gEXPopMatrixGroup`. Detalle:
   `notes/2026-10-02-fps-instrumentacion-pairing-y-plan-identidad.md` §6c/§8.
2. **Validar** con `HH_PAIRING=1` en Windows (una run): `unpaired_moved` de #6/#8 debe bajar a ~0.
   (Medir cámara/vista es solo comprobación, no cambia el arreglo.)
3. Descartado: replay determinista y "jugar y mirar" como test (el mantenedor acertó: no es fiable).
   La observación visual **no** cuenta como validación.

## Sin commitear (esta sesión)

`lib/rt64` (sucio), `src/subsystems/input.cpp`, `RETOMAR.md`, `TODO.md`, `docs/INDEX.md`,
`PROYECTO.md` y las notas nuevas (work-order + estado). `main` en `bebd76e` (`v0.6.1`).
**No** pushear ni commitear sin pedirlo.

## Otros pendientes

- **Acentos in-game por color (color4/color3)** — hoy sólo color0
  (`notes/2026-10-02-fix-glifos-acentos-colision-value-color3.md` §4).
- **Versionado (mantenedor)**: reconciliar/versionar el parche del recompilador.
- **Modo VS/2P**, **EDICIÓN DE PARTIDA** (mover partida a Área-Parte), **JA** (textos vs ROM JP).

## Cómo trabajar (rápido)

- Build Linux: `cmake --build build/linux --parallel $(nproc)`.
- Build Windows: borrar `build/windows` + `build_windows_release.bat`; para usar `lib/` tal cual
  (gates del fork) → **`build_windows.local.bat`**.
- Docs: `python3 tools/analysis/docs_index.py` (`--check` valida enlaces y presupuesto).
- Push: forks primero (`N64Recomp` → `N64ModernRuntime` → `rt64`), luego `main`.
