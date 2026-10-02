# RETOMAR — handoff (2026-10-02)

> Handoff para la próxima sesión. **Estado: `main` = `v0.6.0` (publicada) + fix del mapa (#13) + fix del
> recompilador (jump tables, #14) + fix de textos al guardar + número de Área del título**.
> **TAREA ACTUAL**: **artefactos gráficos en el diálogo del ordenador = los acentos pisan la KANA**
> (colisión de `value` en color0). Causa raíz **medida**; solución robusta **pendiente** (donantes ASCII,
> preparada para JA). Handoff completo: **`notes/2026-10-02-handoff-glifos-acentos-colision-kana.md`**.
> Reglas: `AGENTS.md` y `docs/documentation.md`. Otro pendiente: **versionar el parche del recompilador**.

## Integrado en `main` (2026-10-02)

- **Menú propio de CARGAR/GUARDAR**: `.pak` de **74 slots** (45 partidas + 29 plantillas, trailer de
  metadatos); **migra** el `.pak` de 4 slots de 0.5.x (un solo sentido; sin downgrade). UI 1:1 de
  DATA LOAD/SAVE, carga real desde `CONTINUAR`, borrado de slots. ADR **0013**; notas `notes/2026-09-30-*`.
- **Editor de partida** (`EXTRAS`): atributos/estado/items/habilidades/nivel, plantillas, `IR A ÁREA`,
  `DEBUG NIVELES`. Notas `notes/2026-09-27-f-*`, `notes/2026-09-28-*`.
- **MODO HEAVEN**, VENTAJA, PODER ∞, RESISTENCIA ∞, daño de campo. `notes/2026-09-28-editor-*-heaven.md`.
- **i18n unificado** (`assets/lang/*.txt`, clave = inglés; ADR **0014**), acentos/`¿¡` en los mensajes
  (`font.cpp`), JA en kana; **título del Área** al cargar (Work Sans, fade/hold) y rótulo `AREA` traducido.
- **Vibración desacoplada del Controller Pak** (hook `func_80002BE0` + PFS de un solo `.pak`):
  `notes/2026-10-02-desacoplo-vibracion-controller-pak.md`.
- Pulido de menú/vídeo (CONTINUAR gris, SALIDA stepper, fullscreen) y remapeo CONTROLES.
- **Dependencias**: rt64 **`a8f0a70`** (revertido; `5b11988` apuntaba a un plume no publicado) y
  N64ModernRuntime **`a11fbf2`**.

## Hecho en la sesión 2026-10-02 (todo VALIDADO en Windows)

- #13 minimapa (panel, sin hash; ADR 0015). #14 jump tables del recompilador. Textos al guardar
  (`set_file_select_active(false)`). Número de Área del título (derivar de `[0x801BBBF4]`).

## Pendiente

- **[TAREA ACTUAL] Glifos: los acentos pisan la KANA (artefactos en el diálogo del ordenador).** El hook
  `hh_accent_bfe4` sustituye el bitmap **por `value`** (200..248) sin mirar color/código; esos valores
  son **kana real** de color0 (`include/hh/jp_kana.h`). Solución robusta acordada: **donantes ASCII**
  (no inventar `value`), preparada para JA. Plan + evidencia:
  **`notes/2026-10-02-handoff-glifos-acentos-colision-kana.md`**. Primer paso: `HH_FONT_TRACE=1` para
  confirmar color/valores del diálogo.
- **Versionado (mantenedor)**: reconciliar `recomp/n64recomp_changes/` con el toolchain actual (estaba
  desincronizado) e incluir el parche del fix; y/o publicarlo en el fork `hunkstalker/N64Recomp`.
- **Modo VS / 2P** (futuro): input del puerto 1 (`get_input`/`get_connected_device_info` solo sirven el 0),
  mapeo `controller_num → gamepad`; local primero, online después.
- **EDICIÓN DE PARTIDA**: "mover mi partida a una Área-Parte" (§6bis de
  `notes/2026-09-29-editor-area-parte-plan.md`); validar `IR A ÁREA` + `DEBUG NIVELES`.
- **JA**: verificar los textos del menú contra la ROM japonesa.

## Salvaguardas del merge

- Tags: `backup-premerge-main` (`cf2d883`), `backup-premerge-edicion` (`9fbe2e8`),
  `backup-premerge-carga` (`fc09cd8`).
- Revert local: `git checkout main && git reset --hard backup-premerge-main` (análogo por rama).

## Cómo trabajar (rápido)

- Build Linux: `cmake --build build/linux --parallel $(nproc)`.
- Build Windows: borrar `build/windows` + `build_windows_release.bat`.
- Regenerar C recompilado: `python3 tools/regenerate.py`; tras regenerar,
  `python3 tools/analysis/fix_fallthroughs.py` (ADR 0009/0011).
- Docs: `python3 tools/analysis/docs_index.py` (regenera; `--check` valida enlaces y presupuesto).
- **Release**: el `.exe` deja **solo `hh.log`**; el resto de trazas son opt-in (`HH_*`).

## Git / forks

- Orden de push: forks primero (`N64Recomp` → `N64ModernRuntime` → `rt64`), luego el repo principal.
- `runtime.lock`: RT64 `a8f0a70`, NMR `a11fbf2`, N64Recomp `cab94d9`.
