# RETOMAR — handoff

> Handoff para **sesión nueva**. **Última sesión: 2026-09-23.**

## Estado

- **High frame rate por defecto (v0.4.0)**: `PresentEarly` + `Refresh Rate = Display` → el port
  presenta al refresco del monitor (~109 fps validados con RTSS; la lógica sigue a 30 Hz). Revertir:
  `HH_REFRESH_RATE=original` / `HH_PRESENT_EARLY=0`. `notes/2026-09-22-fps-y-present-early.md`.
- **Atajos**: **F2** aspecto (widescreen/4:3), **F3** ventana, **F4** MSAA; **F1** = Inspector de
  RT64 (solo con `HH_DEVELOPER=1`). Diagnóstico: `HH_FPS=1` (FPS a `hh.log`), `HH_GRAPHICS_API`.
- **Publicado**: **v0.3.0** (widescreen HUD/minimapa, cursor, `rom/`, README). `lib/rt64` fork en
  `hunkstalker/rt64` (`hybrid-heaven` = `a8f0a70`).

## Pendiente inmediato (mantenedor)

- **Publicar Release `v0.4.0`**:
  ```powershell
  git -C hybrid-heaven-recomp push origin main
  # esperar CI verde
  git -C hybrid-heaven-recomp tag -a v0.4.0 -m v0.4.0
  git -C hybrid-heaven-recomp push origin v0.4.0
  ```
  `release.yml` usa `docs/releases/v0.4.0.md` (título + notas).

## Qué toca ahora

Ver **`TODO.md`** §Ahora. Foco: **menú IN-GAME de opciones PC (ADR 0008)**, smoke de arranque,
definir **ADR 0009**. Backlog: textos/traducción, barra HP y elementos `right`/`stretch` del HUD
(POWER/STAMINA ya validados), Steam Deck, `osAiGetStatus`, mejoras de interpolación, etc.

## Método

- **Mapa / HUD**: solo se valida en Windows; Linux headless solo para compilar
  (`cmake --build build/linux -j`). Trazas a `hh.log` junto al exe (`HH_HUD_*`, `HH_RECT_TRACE=1`).
  Ajuste en caliente: `+`/`-` (crop del panel/scissor del mapa). **No** retomar el quad del fondo.
- **Rendimiento**: medir con `HH_FPS=1`; FPS en pantalla con `HH_DEVELOPER=1` + **F1** (o RTSS).
  Con dev-mode, RT64 consume F1-F4 (el F2/F3/F4 del port no actúa).
- Envs: `HH_REFRESH_RATE`, `HH_PRESENT_EARLY`, `HH_GRAPHICS_API`, `HH_RES`, `HH_FULL_FRAME=0`,
  `HH_NO_HUD_REWRITE=1`.

## Build Windows

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
hybrid-heaven-recomp\run_windows_release.bat
```

## Git

- **`main`**: versión `0.4.0`; pendiente de push (high frame rate + atajos + diagnósticos).
- **`lib/rt64`** (fork `hunkstalker/rt64`): `hybrid-heaven` = `a8f0a70`.
- **`N64ModernRuntime` / `N64Recomp`**: en sync.
- Tags: `v0.1.x`, `v0.2.0`, `v0.3.0` (publicados); **`v0.4.0` pendiente de tag**.
