# RETOMAR — handoff

> Handoff para **sesión nueva**. **Última sesión: 2026-09-22.**

## Estado

- **Mapa widescreen (fase 07b): CERRADO y validado en Windows.** Notas:
  `notes/2026-09-22-fix-mapa-rect-negro-widescreen.md`,
  `notes/2026-09-22-anclaje-hud-widescreen-fase07b.md`.
- **Cierre de sesión (2026-09-22)**: cursor oculto sobre la ventana, carpeta `rom/` guía en los
  artefactos de release, README renovado (features + estado) y **versión `0.3.0`**
  (`notes/2026-09-22-cursor-release-rom-readme.md`).
- **Publicado**: `main` y el fork de RT64 ya están en GitHub.

## Pendiente inmediato (mantenedor)

- **Publicar Release `v0.3.0`** cuando CI esté verde en `fc0dda1`:
  ```powershell
  git -C hybrid-heaven-recomp tag -a v0.3.0 -m v0.3.0
  git -C hybrid-heaven-recomp push origin v0.3.0
  ```
  (dispara `release.yml`; requiere un run de CI exitoso para ese commit).

## Qué toca ahora

Ver **`TODO.md`** §Ahora (priorizado). Foco: **menú IN-GAME de opciones PC (ADR 0008)**, smoke de
arranque, definir **ADR 0009** (cobertura nativa). Backlog: textos/traducción, barra HP y elementos
`right`/`stretch` del HUD (POWER/STAMINA ya validados), Steam Deck, `osAiGetStatus`, etc.

## Método (mapa / HUD — seguir si se retoca)

- El mapa **solo se valida en Windows**; Linux headless solo para compilar
  (`cmake --build build/linux -j`).
- Release es GUI: trazas a `hh.log` junto al exe (`HH_HUD_*`, `HH_RECT_TRACE=1`).
- Ajuste en caliente sin recompilar: `+`/`-` (crop del panel/scissor del mapa).
- **No** retomar el quad del fondo del mapa sin leer la nota de fix.

## Build Windows

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
hybrid-heaven-recomp\run_windows_release.bat
```

## Git

- **`main`**: pusheado hasta `fc0dda1` (mapa + cursor + release `rom/` + README + `0.3.0`). El
  commit de **este handoff** queda pendiente de push (junto con el tag `v0.3.0`).
- **`lib/rt64`** (fork `hunkstalker/rt64`): rama `hybrid-heaven` = `a8f0a70` (parches 2D + misalign
  Ortopédico). `.gitmodules` apunta al fork.
- **`N64ModernRuntime` / `N64Recomp`**: en sync (sin cambios).
- Tags previos: `v0.1.x`, `v0.2.0`. **`v0.3.0` pendiente de tag.**
