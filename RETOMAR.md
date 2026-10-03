# RETOMAR — handoff (2026-10-03)

> Handoff corto. **`main` = `v0.6.1`** (esta rama). **TAREA ACTUAL: lanzar la v0.6.2** — la release
> **v0.6.1 publicada en GitHub está rota**: el `.zip` no incluye `assets/` y probablemente compila con
> **forks viejos** → el juego se comporta "como una versión anterior a 0.5.0" (guardado, crashes de
> veneno, etc.), mientras que el build **local sí va**.
> **Detalle completo (medido/inferido, plan):** `notes/2026-10-03-fps-tagging-dobj-y-handoff.md` §7.
> **Otra tarea en curso (otra rama):** interpolación/desbloquear FPS en **`fps-interpolacion-tagging`**
> (no mergeada; ver §"Otras ramas" abajo y la misma nota).
> Reglas: `AGENTS.md` y `docs/documentation.md`.

## Tarea actual — v0.6.2 (release GitHub rota)

- `[MEDIDO]` `.github/workflows/ci.yml` (job `windows`, paso *Empaquetar*) copia al `.zip` **solo**
  `Hybrid Heaven Recomp.exe`, `*.dll`, LEEME/CRÉDITOS/LICENCIA y `rom/`. **No copia `assets/`**
  (logos, `lang/*.txt`, `sounds/*.wav`, `saves/templates`). El ejecutable los busca junto a sí.
- `[INFERIDO, fuerte]` El build de GitHub cae en **forks viejos**: `.gitmodules` → `hunkstalker/*` y
  `runtime.lock` pinea `RT64=a8f0a70`, `NMR=a11fbf2`. Si el commit del fork no está **publicado** en
  el remoto, el clon limpio no lo resuelve → runtime anterior → faltan PFS 74 slots, vibración↔pak,
  jump-table #14, server teardown.
- `[MEDIDO]` El build **local** (`build_windows.local.bat`) usa `lib/` en disco y CMake copia
  `assets/` junto al exe (`CMakeLists.txt` ~214–255). Por eso local va y GitHub no.

### Pasos

1. **Reproducir:** descargar el `.zip` de la v0.6.1 de GitHub; comparar con un build local (¿faltan
   `assets/`? ¿qué commit de runtime trae? ¿guardado/veneno fallan?).
2. **Empaquetado:** copiar `assets/` (+ `saves/templates`) al `.zip` de CI; reconciliar el paso de
   `ci.yml` con `tools/package_release.ps1`/`.py` (hoy empaqueta a mano y divergen).
3. **Forks:** verificar que `a8f0a70` (rt64) y `a11fbf2` (NMR) existen en los remotos y que el
   checkout del clon los resuelve; si no, **pushear los forks** (orden AGENTS: N64Recomp → NMR → rt64
   → main).
4. **Revalidar en Windows** lo que faltaba (guardado `.pak`, veneno, #14).
5. **Publicar v0.6.2** (`include/hh.h`, `docs/releases/v0.6.2.md`, `release.yml`).

## Otras ramas

- **`fps-interpolacion-tagging`** (2 commits `wip` + 1 `docs`, **sin mergear**): tagging de
  interpolación por hook del port. **Funciona** (llega a RT64, `unpaired_moved` de picos 60–98/s a
  media 3.4/s, 77% frames limpios) pero **sin validar en gameplay**. Detalle y siguiente paso:
  `notes/2026-10-03-fps-tagging-dobj-y-handoff.md` §1–§6. Incluye
  `patches/rt64/hh-interpolation-tagging.patch` (cambios del submódulo `lib/rt64` como patch).

## Árbol

- `main` = `v0.6.1`, **submódulos restaurados** (limpios).
- Instrumentación reutilizable (`HH_PAIRING`, `HH_MTXGROUP`) y banco headless (Xvfb+lavapipe): ver la
  nota §4.

## Pitfalls (NO repetir)

- **F7** = captura del HUD 2D; no sirve para artefactos 3D transitorios.
- **La vista no valida** (el mantenedor vio "mejoras" con un `.exe` viejo): validar por métrica.
- No editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
