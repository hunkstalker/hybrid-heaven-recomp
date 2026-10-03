# RETOMAR — handoff RAMA `fps-interpolacion-tagging` (2026-10-03)

> **Esta rama es SOLO el fix de interpolación/desbloquear FPS.** La otra tarea abierta (release
> **v0.6.2**, "GitHub rota") vive en **`main`** (ver el `RETOMAR.md` de `main`). No mezclar.
> **TAREA ACTUAL (rama): validar y cerrar el tagging de transforms** para quitar los artefactos de
> interpolación (#6 Procyon, #8 puertas, #10 curar, #12 Life Charger S).
> **Detalle completo (medido/inferido):** `notes/2026-10-03-fps-tagging-dobj-y-handoff.md` §1–§6.
> Reglas: `AGENTS.md` y `docs/documentation.md`.

## Estado (esta rama)

- `[MEDIDO]` El **tagging por hook del port** ya **llega a RT64** (`explicit_ids≈2300/s`) y baja
  `unpaired_moved` de picos 60–98/s a **media 3.4/s** (**77% frames limpios**). Causa raíz de por qué
  antes no llegaba: faltaba `#define F3DEX_GBI_2` (opcode del hook extendido, `0xE0`).
- `[MEDIDO]` Punto de enganche: **dispatch DOBJ `func_800069A8`** (pasa TODO nodo: malla y demás
  tipos). Cubre `src/hooks/model_tagging.cpp` (hook `hh_bone_draw_hook`, `HH_MTXGROUP=1`).
- `[MEDIDO]` Techo del mantenedor = **120 fps** (`target=swapChain=120, vsync=1`): los 70–110 son
  **caídas bajo el techo**, no falta de GPU.
- `[MEDIDO]` `unpaired_tagged=0`: lo restante sin emparejar era **1 transform/frame de tipos que no
  pasaban por la malla** → por eso el hook se movió al dispatch. **Aún NO validado en gameplay.**
- `[MEDIDO]` El "brillo de 1 frame" de #6 es una discontinuidad de visibilidad/alfa; el **skip-spawn**
  que se probó causó microdesfases y está **revertido**.

## Siguiente paso concreto

1. **Validar** el hook en `func_800069A8` (run Windows): `HH_MTXGROUP=1 HH_PAIRING=1`. Criterio:
   `unpaired` base (~29/s = 1/frame) **baja**, `unpaired_moved` baja, y **sin microdesfases**.
2. **`skip` en discontinuidades** (el "brillo de 1 frame" de #6): con **frame boundary fiable** (no el
   VI, que iba a mitad de frame). Opciones: señal desde la lógica (patrón Goemon) o detectar el reset
   de pose/escala en el nodo.
3. Medir **#8 / #10 / #12** con la métrica (no con la vista).
4. **Repaso de fps** (techo 120; medir `HH_FPS=1` `present` vs `target`) **después** de la interpolación.

## Instrumentación

- `HH_PAIRING=1` → `[hh-pair]` en `hh.log` (`transforms`, `explicit_ids`, `groups_seen`, `ignored`,
  `unpaired`, `unpaired_tagged`, `unpaired_moved`, `target/vi/swapChain/refresh/vsync`).
- `HH_MTXGROUP=1` activa el tagging; `HH_MTXGROUP_LOG=1` traza nodos/ID; `HH_PAIRING_DUMP=<n>` vuelca
  identidad de no-emparejados (stderr).
- **Headless propio:** `Xvfb :99` + `VK_ICD_FILENAMES=.../lvp_icd.x86_64.json` (lavapipe). Itera sin el
  mantenedor, pero **solo llega a logos/menús**, no a gameplay 3D.
- Logs de referencia en `tests/logs/` (gitignored). No commitear logs ni capturas.

## Árbol / commits

- `main` (aparte): `v0.6.1` + docs de handoff de v0.6.2.
- Esta rama: `a217319` (métrica + tagging), `b95f3c2` (hook a dispatch + revertir skip),
  `0ad2ba1` (docs). Incluye `patches/rt64/hh-interpolation-tagging.patch` (submódulo `lib/rt64`).

## Pitfalls (NO repetir)

- **F7** = captura del HUD 2D; no sirve para artefactos 3D transitorios.
- **La vista no valida** (run con `.exe` viejo "pareció mejorar"): validar por métrica.
- **La reescritura de DL en submit** para el tagging **se descartó** (falló 2×): la vía es el hook.
- No editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
