# RETOMAR — handoff

> Handoff para **sesión nueva**. **Última sesión: 2026-09-22.**

## Estado

La tarea del **mapa widescreen (fase 07b)** está **cerrada y validada en Windows**:
- Anclaje del HUD/mapa: `notes/2026-09-22-anclaje-hud-widescreen-fase07b.md`
- Fix del rect negro del minimapa: `notes/2026-09-22-fix-mapa-rect-negro-widescreen.md`
- **`RETOMAR2.md` eliminado** (se fusionó aquí + en las notas).

## Qué toca ahora

Ver **`TODO.md`** §Ahora (priorizado). Foco: menú IN-GAME de opciones PC (ADR 0008), smoke de
arranque, ADR 0009.

## Método (mapa / HUD — seguir si se retoca)

- El mapa **solo se valida en Windows**; Linux headless solo para compilar
  (`cmake --build build/linux -j`).
- Release es GUI: trazas a `hh.log` junto al exe (`HH_HUD_*`, `HH_RECT_TRACE=1`).
- Ajuste en caliente sin recompilar: `+`/`-` (crop del panel/scissor del mapa).
- **No** retomar el quad del fondo del mapa sin leer la nota de fix (§ por qué se abandonó).

## Build Windows

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
hybrid-heaven-recomp\run_windows_release.bat
```

## Git (estado tras la sesión)

- **`lib/rt64` (fork)**: `a8f0a70` — misalign Ortopédico + parches 2D.
- **`main`**: `61c8b9f` `cleanup(hud)` · `e751b48` `fix(map)` · `13062ab` `docs`.
- **Ahead**, pendiente de push (forks primero; ver `AGENTS.md`).
