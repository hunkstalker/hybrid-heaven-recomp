# RETOMAR — handoff (2026-10-03)

> Handoff corto. **`main` = `v0.6.1` + v0.6.2 lista (código, sin push)**. **TAREA ACTUAL: publicar la
> v0.6.2** — la release **v0.6.1 de GitHub estaba rota**; reproducida y arreglada en local.
> **Detalle (medido/inferido):** `notes/2026-10-03-release-v0.6.2-empaquetado-y-secrets.md`.
> **Otra tarea (otra rama, NO mezclar):** interpolación/desbloquear FPS en
> **`fps-interpolacion-tagging`** (ver §"Otras ramas").
> Reglas: `AGENTS.md` y `docs/documentation.md`.

## Tarea actual — v0.6.2 (release GitHub rota)

**Reproducido `[MEDIDO]`:**

- El `.zip` de la v0.6.1 **no incluye** `assets/`, `saves/templates` ni `licences/`. El ejecutable los
  busca junto a sí. `ci.yml` empaquetaba a mano y divergía del `POST_BUILD` de CMake.
- **Los forks NO eran el problema**: rt64 `a8f0a70`, NMR `a11fbf2` y N64Recomp `cab94d9` están
  publicados y `git fetch --depth 1 <url> <sha>` los resuelve. Hipótesis descartada.
- **Causa real de #14/veneno**: el repo privado de **secretos** (de donde CI clona el `RecompiledFuncs`,
  ADR 0009) seguía en **2026-09-21**, antes del fix de jump tables. El `func_8035A3D8` del secrets tenía
  2 casos; el `build/recomp` regenerado tiene 9. Solo difieren **6 ficheros**.

**Hecho (local, sin push):**

- `tools/package_release.py` (**fuente única**: mismo subconjunto de datos que CMake) + `ci.yml`
  (jobs `windows` y `linux`).
- `hh-recomp-secrets` commit `3993e72` con los 6 `funcs_*.c` regenerados.
- `include/hh.h` → patch `2`; `docs/releases/v0.6.2.md`; docs vivos.

### Pasos que faltan

1. **Push del secrets** `3993e72` a `hunkstalker/hh-recomp-secrets` (`git -C hh-recomp-secrets push`).
   Si no, CI sigue compilando el C viejo y el #14 no entra en la release.
2. **Commit + push `main`** (fast-forward). Eso dispara CI (`windows`+`linux`).
3. Esperar CI **verde** y **revalidar en Windows** sobre el ZIP de CI: `assets/` presentes, guardado
   `.pak`, veneno/ataque a distancia (#14).
4. **Publicar v0.6.2**: tag `v0.6.2` (o `Release` a mano con `version=v0.6.2`); `release.yml` descarga
   el artefacto de CI del commit y crea el Release.

## Otras ramas

- **`fps-interpolacion-tagging`** (2 commits `wip` + 1 `docs`, **sin mergear**): tagging de
  interpolación por hook del port. **Funciona** (llega a RT64, `unpaired_moved` de picos 60–98/s a
  media 3.4/s, 77% frames limpios) pero **sin validar en gameplay**. Detalle y siguiente paso:
  `notes/2026-10-03-fps-tagging-dobj-y-handoff.md` §1–§6. Incluye
  `patches/rt64/hh-interpolation-tagging.patch` (cambios del submódulo `lib/rt64` como patch).

## Árbol

- `main` = `v0.6.1` + 2 commits locales (empaquetado `8a7e076`, release pendiente), **submódulos
  limpios** en sus pins.
- `hh-recomp-secrets` = commit `3993e72` local (sin push).
- Instrumentación reutilizable (`HH_PAIRING`, `HH_MTXGROUP`) y banco headless (Xvfb+lavapipe): nota §4.

## Pitfalls (NO repetir)

- **F7** = captura del HUD 2D; no sirve para artefactos 3D transitorios.
- **La vista no valida** (el mantenedor vio "mejoras" con un `.exe` viejo): validar por métrica.
- No editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
- **"Local va, GitHub no"** puede ser **dos** fallos distintos: datos no empaquetados **y** C
  recompilado no re-publicado. No culpar a los forks sin comprobar los pins por SHA.
