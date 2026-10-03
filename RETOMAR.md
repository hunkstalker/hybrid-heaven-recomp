# RETOMAR — handoff RAMA `fps-interpolacion-tagging` (2026-10-03)

> **Esta rama = fix de interpolación/desbloquear FPS**, ya mergeada con `main` (v0.6.2). La tarea de
> la release v0.6.2 vive en `main` (ver más abajo, "Tarea de main"). **TAREA ACTUAL (rama): validar y
> cerrar el tagging de transforms** (#6 Procyon, #8 puertas, #10 curar, #12 Life Charger S).
> **Detalle completo (medido/inferido):** `notes/2026-10-03-fps-tagging-dobj-y-handoff.md` §1–§6.
> Reglas: `AGENTS.md` y `docs/documentation.md`.

## Estado (esta rama)

- `[MEDIDO]` El **tagging por hook del port** ya **llega a RT64** (`explicit_ids≈2300/s`) y baja
  `unpaired_moved` de picos 60–98/s a **media 3.4/s** (**77% frames limpios**). Causa raíz de por qué
  antes no llegaba: faltaba `#define F3DEX_GBI_2` (opcode del hook extendido, `0xE0`).
- `[MEDIDO]` Punto de enganche: **dispatch DOBJ `func_800069A8`** (pasa TODO nodo: malla y demás
  tipos). `src/hooks/model_tagging.cpp`, `HH_MTXGROUP=1`.
- `[MEDIDO]` `gEXSetRDRAMExtended` **rompía el widescreen** (HH usa direcciones KSEG0 = bit 31 =
  `ExtendedMask`; con `extendRDRAM=1` RT64 reinterpreta TODAS las direcciones). **Quitado** (`bcc222d`).
- `[MEDIDO]` Techo del mantenedor = **120 fps** (`target=swapChain=120, vsync=1`).
- `[MEDIDO]` `unpaired_tagged=0`: el hueco era **1 transform/frame de tipos que no pasaban por la
  malla** → por eso el hook se movió al dispatch. **Aún NO validado en gameplay.**
- `[MEDIDO]` El "brillo de 1 frame" de #6 es discontinuidad de visibilidad/alfa; el **skip-spawn** que
  se probó causó microdesfases y está **revertido**.

## Siguiente paso (esta rama)

1. **Validar** el hook en `func_800069A8` (run Windows; `HH_MTXGROUP=1 HH_PAIRING=1`): `unpaired` base
   (~29/s) **baja**, `unpaired_moved` baja, widescreen OK y **sin microdesfases**.
2. **`skip` en discontinuidades** (el "brillo de 1 frame" de #6) con **frame boundary fiable** (no el VI).
3. Medir **#8 / #10 / #12** por métrica. 4) Repaso de fps (`HH_FPS=1`) **después**.

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
