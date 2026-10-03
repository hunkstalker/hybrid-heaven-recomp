# RETOMAR — handoff RAMA `fps-interpolacion-tagging` (2026-10-03)

> **Esta rama = fix de interpolación/desbloquear FPS**, mergeada con `main` (v0.6.2). La tarea v0.6.2
> vive en `main` (abajo, "Tarea de main"). **TAREA ACTUAL (rama): REHACER la identidad del tagging
> según el modelo de Pilotwings64Recomp** (el de las direcciones NO funciona; ver §3c/§3d).
> **Detalle COMPLETO (medido/inferido):** `notes/2026-10-03-fps-tagging-dobj-y-handoff.md` §0–§6.
> Reglas: `AGENTS.md` y `docs/documentation.md`.

## Estado (esta rama) — qué funciona y qué no

- `[MEDIDO]` **Resuelto**: el tagging llega a RT64 (faltaba `#define F3DEX_GBI_2`); el **widescreen** y
  el **recuadro negro** (era el walker de `snap_overscan` abortando en el opcode extendido `0x64`);
  **#8 puertas** estable.
- `[MEDIDO]` Punto de enganche: **dispatch DOBJ `func_800069A8`** (`src/hooks/model_tagging.cpp`,
  `HH_MTXGROUP=1`). `gEXSetRDRAMExtended` **rompía el widescreen** (quitado).
- `[MEDIDO]` **Fallos pendientes**: #6 (rebobinado de la textura al crecer) y **parpadeos de cámara**.
  ~27% de frames con `unpaired_moved>0` (picos hasta ~70/s).
- `[MEDIDO]` **Ninguna dirección es identidad estable** (nodo, modelo `+0x2C`, root+orden): todas se
  reciclan → probadas y **fallidas** (§3b). `dump6.log` lo prueba.

## Siguiente paso (esta rama) — rehacer según §3c/§3d

1. **ID lógica** = hash(`slot` de objeto/actor, `modelId`, `lod`) **+ generación de cámara** (NO
   direcciones). Buscar el slot en la lista de modelos/actores de HH.
2. **Generación de cámara** con detección de **cortes** (salto/giro de la matriz de cámara) → arregla
   el parpadeo de cámara (la cámara va bakeada en cada matriz).
3. **Un grupo por objeto** (no por nodo), `G_EX_ORDER_LINEAR`; **efectos** `G_EX_ORDER_AUTO`; **2D**
   `G_EX_ID_IGNORE`; **cámara** grupo de proyección aparte.
4. **Quitar** el skip-spawn propio (RT64 lo hace solo). **Validar** con `HH_PAIRING`. Después, fps.
5. Fuente exacta del modelo: **§3c** y `patches/interpolation.c` de Pilotwings64Recomp (citados en la nota).

## Instrumentación

- `HH_PAIRING=1` → `[hh-pair]`; `HH_MTXGROUP=1` activa el tagging; `HH_MTXGROUP_LOG=1` traza;
  `HH_PAIRING_DUMP=<n>` vuelca identidad de no-emparejados.
- **Headless propio:** `Xvfb :99` + `VK_ICD_FILENAMES=.../lvp_icd.x86_64.json` (lavapipe) → logos/menús,
  **no** gameplay 3D. Logs de referencia en `tests/logs/` (gitignored).

---

# Tarea de main — v0.6.2 (release GitHub rota)

> **`main` = `v0.6.1` + v0.6.2 (pusheada y validada; solo falta el tag)**. **TAREA: taggear/publicar
> la v0.6.2** — la release **v0.6.1 de GitHub estaba rota**; reproducida, arreglada y **validada en
> Windows**.
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
