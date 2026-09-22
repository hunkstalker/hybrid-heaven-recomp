# RETOMAR — handoff

> Handoff para **sesión nueva**. **Última sesión: 2026-09-23.**

## Tarea de ESTA sesión: spike de traducción — empezar por los textos del menú

Objetivo: probar que podemos **traducir en runtime** y ver cambiar textos del **menú** en pantalla
(base del selector de idioma del ADR 0008). Sería la **primera traducción al español** del juego.

Plan (detalle en `TODO.md` §Textos y `notes/archive/2026-09-11-proyecto-legacy.md` §4.5):
1. **Charset** (encoding custom USA). Anclas: `PLEASE SELECT` @`0x05FB543`, `BATTLE` @`0x05FAF4C`,
   `ITEM...WEAPON` @`0x06C33AF`, `WASHINGTON D.C.` @`0x061CD7A`. Zona `0x0530000-0x06D0000` (+ overlays
   **262/264/303**). Paso: **volcar bytes alrededor de las anclas** y derivar la tabla byte→glifo
   comparando con ASCII.
2. **Text-emit**: localizar la rutina que dibuja un string (la que recibe esos punteros) y
   **engancharla** (`[[patches.hook]]` o reimplementación ADR 0002) para sustituir el texto en runtime.
3. **Prueba mínima**: traducir **un** texto de menú y verlo en pantalla (Windows).
4. Si sale: variable `language` + persistencia + **cambio en vivo** desde el menú del Expansion Pak.

**IMPORTANTE (permisos)**: hace falta **leer** la ROM del mantenedor
(`build\windows\bin\Release\hh.us.z64`) — **solo lectura**; confirmar antes (regla: no tocar ROMs sin
pedirlo). **No** modificar la ROM ni meterla en el repo. Herramientas nuevas en `tools/` (p. ej.
`tools/text/`). Herramientas ya disponibles: `tools/lzkn64/lzkn64.py`, `tools/rommy.py`,
`notes/us_manifest.yaml` (módulos; `expansionram` = idx 23).

## Estado (ya cerrado)

- **High frame rate por defecto (v0.4.0)**: `PresentEarly` + `Refresh Rate = Display` → presenta al
  refresco del monitor (~109 fps validados con RTSS; lógica a 30 Hz). Revertir: `HH_REFRESH_RATE=original`
  / `HH_PRESENT_EARLY=0`. `notes/2026-09-22-fps-y-present-early.md`.
- **Atajos**: **F2** aspecto, **F3** ventana, **F4** MSAA; **F1** = Inspector de RT64 (con
  `HH_DEVELOPER=1`). Diagnóstico: `HH_FPS=1`, `HH_GRAPHICS_API`.
- **Publicado**: **v0.3.0**. `lib/rt64` en el fork `hunkstalker/rt64` (`hybrid-heaven` = `a8f0a70`).

## Pendiente inmediato (mantenedor)

- **Push de 2 commits de docs** y **tag `v0.4.0`** tras CI verde:
  ```powershell
  git -C hybrid-heaven-recomp push origin main
  # esperar CI verde
  git -C hybrid-heaven-recomp tag -a v0.4.0 -m v0.4.0
  git -C hybrid-heaven-recomp push origin v0.4.0
  ```
  (`release.yml` usa `docs/releases/v0.4.0.md`.)

## Qué toca después

Ver **`TODO.md`** §Ahora: menú IN-GAME de opciones PC (ADR 0008, donde vivirá el selector de idioma),
smoke de arranque, ADR 0009. Backlog: textos/traducción, barra HP + `right`/`stretch` del HUD, etc.

## Método

- **Mapa/HUD**: solo se valida en Windows; Linux headless solo para compilar
  (`cmake --build build/linux -j`). Trazas a `hh.log` (`HH_HUD_*`, `HH_RECT_TRACE=1`).
- **Rendimiento**: medir con `HH_FPS=1`; FPS en pantalla con `HH_DEVELOPER=1` + F1 (o RTSS).
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso explícito.

## Build Windows

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
hybrid-heaven-recomp\run_windows_release.bat
```

## Git

- **`main`**: `origin/main` = `c977bd5` (v0.4.0 versionada); **este handoff y los docs recientes**
  sin push (haz `git log origin/main..HEAD` para verlos).
- **`lib/rt64`** (fork): `hybrid-heaven` = `a8f0a70`.
- **`N64ModernRuntime` / `N64Recomp`**: en sync.
- Tags publicados: `v0.1.x`, `v0.2.0`, `v0.3.0`. **`v0.4.0` pendiente de tag.**
