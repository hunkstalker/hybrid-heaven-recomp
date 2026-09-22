# 2026-09-22 — Cursor, carpeta `rom/` en release y README

> Sesión de cierre tras validar el fix del mapa (fase 07b). Tres tareas pequeñas + hallazgo del
> fork de RT64. Commits: `8c1f5ce` (cursor) y `45921d0` (release `rom/` + README).

## Hecho

1. **Ocultar el cursor** sobre la ventana del juego (`src/platform/support.cpp` +
   `src/subsystems/input.cpp`): se oculta al crear la ventana y al recuperar foco
   (`SDL_WINDOWEVENT_FOCUS_GAINED`), y se vuelve a mostrar al perderlo (`FOCUS_LOST`). **Validado en
   Windows.**
2. **Carpeta `rom/` en los artefactos de release** (`.github/workflows/ci.yml`, Linux y Windows): al
   empaquetar se crea `rom/PON_AQUI_LA_ROM.txt`, para que al descomprimir quede claro dónde va la
   ROM. El `rom/` del repo sigue gitignored; el del usuario es lo único que falta para jugar.
3. **README renovado**: menos detalle de compilación (remite a `docs/` y a `build_windows.bat` /
   `tools/build_linux.sh`), sección de **características** y **punto de control de estado**
   (validado en Windows, sin bloqueantes conocidos para terminar el juego). La compilación sigue
   requiriendo la ROM una vez (ADR 0009).

## Hallazgo: `lib/rt64` no apunta a un fork

- `.gitmodules` y el remoto `origin` de `lib/rt64` apuntan a **`https://github.com/rt64/rt64.git`**
  (upstream), **no** a un fork propio. El patrón de los otros submódulos sí usa fork
  (`hunkstalker/N64ModernRuntime`, `hunkstalker/N64Recomp`).
- Nuestros parches están commiteados en `lib/rt64` = `a8f0a70`, pero en **detached HEAD** y sin
  remoto de fork → **no se pueden subir** hasta crear/apuntar el fork.
- Los otros dos forks están **en sync** (NMR `0 0`, N64Recomp `0 0`): no requieren push.

## Pendiente

- Crear (o confirmar) el fork `hunkstalker/rt64`, apuntar `lib/rt64` (`origin`/`.gitmodules`) al fork
  y subir `a8f0a70` (rama `hybrid-heaven`). Luego push de `main` (`--force-with-lease`). Detalle:
  ver `AGENTS.md` (orden de push) y `runtime.lock`.
