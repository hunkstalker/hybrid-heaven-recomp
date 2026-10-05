# FPS/interpolación — integración de la épica en `main` + release (2026-10-05)

> La épica de **interpolación de frames** (rama `fps-interpolacion-tagging`) queda **integrada en
> `main`** (merge fast-forward) y **activada por defecto**. Este documento cierra la integración y
> recoge los arreglos de build/CI que hicieron falta. Reglas: `AGENTS.md`, `docs/documentation.md`.

## 1. TL;DR

- **Integrada en `main`** y **ON por defecto** (tagging de objeto/nodo **y** de emisores/cámara);
  apagable con `HH_MTXGROUP=0` / `HH_EMIT_TAG=0`.
- **RT64**: el gate de discontinuidad **escala/rotación (#6)** pasa de patch a **commit permanente**
  del fork (`7c46232`); gitlink y `runtime.lock` actualizados.
- **Stubs de instrumentación RT64** para que `main` compile **sin** el patch de diagnóstico, ahora
  **portables a MSVC** (`/alternatename`); sin esto el CI de **Windows** habría fallado el enlace.
- **CI Linux** (`Dockerfile` → `tools/build_linux.sh`) usaba **upstream de rt64** porque el script no
  leía `RT64_URL/RT64_COMMIT` de `runtime.lock`; **arreglado**.
- **Versión**: subida a **v0.7.0** (MINOR: feature).

## 2. Integración (plan de RETOMAR, pasos 1–5)

1. **Sincronizar** `main` → rama (merge `1768580`); sin conflictos.
2. **Re-validar** en Windows con flags ON (cámara, identidad, #6/#8). Hecho por el mantenedor.
3. **Promover ON por defecto** (`292024f`):
   - `g_enabled` (`HH_MTXGROUP`) **y** `g_emit_tag` (`HH_EMIT_TAG`/`HH_FX_EMIT`) → **ON**; `=0` apaga.
     Ambos: el fix de **cámara** vive en `emitter_wrap()` y su gate es `g_emit_tag && g_enabled`.
   - `sections.cpp`: los emisores que **taggean** (`C768` + `7DE4/82C4/8754/8B9C/8F30/D1CC/A06C/13828`)
     se registran **siempre**; los de **solo-traza** (`7328/736C/73AC`, setup/2D `7750/78AC/79B0/
     11958/A828/919C`) siguen bajo `HH_FX_PASS2`.
   - La **instrumentación** (`HH_PAIRING`, `HH_MTXGROUP_LOG`, `HH_PAIRCAP`, `HH_GENCAP`,
     `HH_PAIRING_DUMP`, `HH_TEXDUMP`, `HH_FX_PASS2`) sigue **OFF**.
4. **RT64 → commit del fork** (`f144881`): el gate de escala/rotación (#6) es commit permanente del
   fork `hunkstalker/rt64` rama `hybrid-heaven` (**`7c46232`**, sobre `5b11988`; pusheado). Gitlink +
   `runtime.lock` a `7c46232`. El patch `patches/rt64/hh-interpolation-tagging.patch` se regenera a
   **solo instrumentación**.
5. **Merge/PR a `main`**: **fast-forward** (`9b45c3a`), más el fix de build de los stubs. **Pendiente
   del mantenedor**: `git push origin main` (+ tag/release).

## 3. Stubs de instrumentación RT64 (y fix MSVC)

El port llama a funciones que **solo existen en el fork con el patch** (`RT64_GetTransformPairing`,
`RT64_GetGroupSeenCount`, `RT64_GetEmitterMatHist`, `RT64_GetGbiProbeCounters`, `RT64_TakePairCapture`).
Para que `main` con **RT64 limpio** (sin patch) enlace, se definen **stubs débiles** en
`src/platform/rt64_render_context.cpp` (`9b45c3a`): sin patch devuelven 0/vacío; con patch, gana la
versión fuerte del fork.

- **Bug**: los stubs se guardaron con `__attribute__((weak))`, que **MSVC no soporta** → en
  `windows-latest` (MSVC) los stubs no se compilaban y el enlace fallaba. Solo se había probado Linux.
- **Fix** (`8460932`): rama `#if defined(_MSC_VER)` que define los stubs con otro nombre (`hh_stub_*`)
  y los mapea con `/alternatename`; GCC/Clang mantienen `weak`. Validado: Linux enlaza; rama MSVC
  verificada por sintaxis (sin MSVC en el contenedor).
- Sin LTO/IPO en el proyecto → el linker no elimina los stubs.

## 4. CI: pin de rt64 en Linux/Docker

`tools/build_linux.sh` (que usa el `Dockerfile`, por tanto el job `linux`) tenía
`RT64_URL/RT64_COMMIT` con **defaults de upstream** y **no** leía el `runtime.lock` (solo leía NMR).
Consecuencia: **Linux compilaba rt64 upstream**, sin el fix 2D ni el gate de escala, aunque
`runtime.lock`/Windows sí usaban el fork → binarios **distintos** Linux vs Windows.

- **Fix**: leer `RT64_URL`/`RT64_COMMIT` de `runtime.lock` (env > lock > fallback upstream), como NMR.
- `build_windows.bat` ya leía el lock; `Dockerfile` (comentario) corregido a "fork de rt64".

## 5. Validación

- **Windows (MSVC)**: compila y enlaza (mantenedor); comportamiento bueno sin variables (cámara,
  huesos, #6, #8).
- **Linux**: build completo OK.
- `python3 tools/analysis/docs_index.py --check`: OK.

## 6. Versión / release

- `include/hh.h`: **v0.7.0** (MINOR: feature). Notas: `docs/releases/v0.7.0.md`.
- Tag/release: `git tag v0.7.0 && git push origin v0.7.0` (o Actions → Release). `release.yml` usa el
  título de la primera línea de `docs/releases/v0.7.0.md`.

## 7. Pendiente

- **Push** de `main` (mantenedor) + tag/release.
- **Pendiente de la épica**: **A1 (tick lógico)** y **A3 (validar 120/240)** (ver `RETOMAR.md`).
