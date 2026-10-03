# RETOMAR — handoff (2026-10-03)

> Handoff corto. **`main` = `v0.6.1` + v0.6.2 (pusheada y validada; solo falta el tag)**. **TAREA
> ACTUAL: taggear/publicar la v0.6.2** — la release **v0.6.1 de GitHub estaba rota**; reproducida,
> arreglada y **validada en Windows**.
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

**Hecho:**

- `tools/package_release.py` (**fuente única**: mismo subconjunto de datos que CMake) + `ci.yml`
  (jobs `windows` y `linux`); pusheado (`8a7e076`).
- `hh-recomp-secrets` `3993e72` con los 6 `funcs_*.c` regenerados; **pusheado**.
- `main` `f3de254` (bump `hh.h` + notas + docs); CI **verde** (`run 37119539631`).
- Artefacto verificado: el zip real trae `assets/`, `saves/templates/` y `licences/` (el doble zip que
  se ve en la web de Actions es solo el wrapper del artefacto; `release.yml` publica el interno).
- **Validado en Windows (2026-10-03)**: guardado `.pak` y veneno/ataque a distancia (#14) OK.

### Pasos que faltan

1. **Commit + push** de esta actualización de docs (la nota de release ya no dice "pendiente").
2. Esperar CI **verde** de ese commit.
3. **Taggear/publicar** `v0.6.2`:
   `git -C hybrid-heaven-recomp tag -a v0.6.2 -m "v0.6.2" && git -C hybrid-heaven-recomp push origin v0.6.2`
   (`release.yml` descarga el artefacto de CI del commit y crea el Release).

## Otras ramas

- **`fps-interpolacion-tagging`** (2 commits `wip` + 1 `docs`, **sin mergear**): tagging de
  interpolación por hook del port. **Funciona** (llega a RT64, `unpaired_moved` de picos 60–98/s a
  media 3.4/s, 77% frames limpios) pero **sin validar en gameplay**. Detalle y siguiente paso:
  `notes/2026-10-03-fps-tagging-dobj-y-handoff.md` §1–§6. Incluye
  `patches/rt64/hh-interpolation-tagging.patch` (cambios del submódulo `lib/rt64` como patch).

## Árbol

- `main` = `f3de254` (+ esta actualización de docs), **submódulos limpios** en sus pins; `origin/main`
  al día tras el push.
- `hh-recomp-secrets` = `3993e72` **pusheado**.
- Instrumentación reutilizable (`HH_PAIRING`, `HH_MTXGROUP`) y banco headless (Xvfb+lavapipe): nota §4.

## Pitfalls (NO repetir)

- **F7** = captura del HUD 2D; no sirve para artefactos 3D transitorios.
- **La vista no valida** (el mantenedor vio "mejoras" con un `.exe` viejo): validar por métrica.
- No editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
- **"Local va, GitHub no"** puede ser **dos** fallos distintos: datos no empaquetados **y** C
  recompilado no re-publicado. No culpar a los forks sin comprobar los pins por SHA.
