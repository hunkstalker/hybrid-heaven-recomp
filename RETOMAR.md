# RETOMAR — handoff (2026-10-03)

> Handoff corto. **`main` = `bebd76e` (`v0.6.1`) LIMPIA** (submódulos restaurados), a propósito para
> abordar una **v0.6.2**. El trabajo de interpolación vive en la rama **`fps-interpolacion-tagging`**
> (2 commits `wip`, **sin mergear**).
> **2 tareas para la próxima sesión** (una en `main`, otra en la rama):
> 1. **Release GitHub rota → v0.6.2** (`main`): la v0.6.1 publicada no trae `assets/` y probablemente
>    compila con forks viejos → "como una versión anterior a 0.5.0" (guardado, crashes de veneno…).
> 2. **Interpolación/desbloquear FPS** (rama `fps-interpolacion-tagging`): el tagging de transforms
>    ya llega a RT64 y reduce mucho los artefactos; falta cerrar lo que resta y validar.
> **Detalle completo:** `notes/2026-10-03-fps-tagging-dobj-y-handoff.md` (contexto, medido, plan).
> Reglas: `AGENTS.md` y `docs/documentation.md`.

## Tarea 1 (main) — Release GitHub rota → v0.6.2

- `[MEDIDO]` El `.zip` de CI (`.github/workflows/ci.yml`, job `windows`, paso *Empaquetar*) **no copia
  `assets/`** (logos, `lang/*.txt`, `sounds/*.wav`, `saves/templates`). El ejecutable los busca junto
  a sí → sin traducciones, sin logos HD, sin SFX, sin plantillas.
- `[INFERIDO, fuerte]` El build de GitHub cae en **forks viejos** (`.gitmodules` → `hunkstalker/*`;
  `runtime.lock` pinea `RT64=a8f0a70`, `NMR=a11fbf2`): si el commit del fork no está publicado en el
  remoto, el clon no lo tiene → runtime anterior → faltan PFS 74 slots, vibración↔pak, jump-table #14.
- `[MEDIDO]` Local (`build_windows.local.bat`) **sí** va (usa `lib/` en disco + `assets/` por CMake);
  GitHub no. → causa del "local sí, GitHub no".
- **Hacer:** reproducir con el `.zip` de v0.6.1; arreglar el empaquetado (copiar `assets/` y
  `saves/templates`, reconciliar con `package_release.ps1/.py`); garantizar/pushear los forks
  (orden: N64Recomp → NMR → rt64 → main); revalidar guardado/veneno/#14; publicar **v0.6.2**.

## Tarea 2 (rama `fps-interpolacion-tagging`) — interpolación

- `[MEDIDO]` El tagging **ya llega a RT64**: `explicit_ids≈2300/s`, y `unpaired_moved` bajó de picos
  60–98/s a **media 3.4/s** (**77% frames limpios**). Causa raíz de por qué antes no llegaba:
  faltaba `#define F3DEX_GBI_2` (opcode hook). Punto de enganche: **dispatch DOBJ `func_800069A8`**.
- `[MEDIDO]` Techo del mantenedor = **120 fps** (`target=swapChain=120, vsync=1`). Los 70–110 son
  caídas bajo el techo, no falta de GPU.
- `[MEDIDO]` `unpaired_tagged=0`: lo restante sin emparejar era **1 transform/frame de tipos de nodo
  que no pasaban por la malla** → por eso el hook se movió a `func_800069A8` (cubre todos los tipos).
  **Esto último aún NO validado en gameplay.**
- `[MEDIDO]` El "brillo de 1 frame" de #6 es un cambio de visibilidad/alfa en discontinuidad; necesita
  `skip` bien hecho (no un umbral global). El **skip-spawn** que se probó causó microdesfases y está
  **revertido**.
- **Hacer:** validar el hook en `func_800069A8` (run Windows); cerrar el `skip` con frame boundary
  fiable; medir #8/#10/#12; **después**, repaso de fps.

## Ramas y árbol

- **`main`** = `bebd76e` (`v0.6.1`), limpia.
- **`fps-interpolacion-tagging`**: `a217319` (métrica + tagging en `func_8000C768`) y `b95f3c2`
  (hook a `func_800069A8` + revertir skip-spawn). Incluye
  `patches/rt64/hh-interpolation-tagging.patch` (cambios del submódulo `lib/rt64` como patch).
- `lib/rt64` **sucio** solo en la rama (por el patch); en `main` restaurado.

## Instrumentación (reutilizable)

- `HH_PAIRING=1` → `[hh-pair]` en `hh.log`: `transforms`, `explicit_ids`, `groups_seen`, `ignored`,
  `unpaired`, `unpaired_tagged`, `unpaired_moved`, `target/vi/swapChain/refresh/vsync`.
- `HH_MTXGROUP=1` activa el tagging; `HH_MTXGROUP_LOG=1` traza nodos/ID; `HH_PAIRING_DUMP=<n>` vuelca
  identidad de no-emparejados (stderr).
- **Headless propio**: `Xvfb :99` + `VK_ICD_FILENAMES=.../lvp_icd.x86_64.json` (lavapipe) → iterar sin
  el mantenedor (pero **solo llega a logos/menús**, no a gameplay 3D).
- Logs de referencia en `tests/logs/` (gitignored). No commitear logs ni capturas.

## Pitfalls (NO repetir)

- **F7** = captura del HUD 2D; no sirve para artefactos 3D transitorios. Un still no muestra un flash.
- **La vista no valida**: el mantenedor vio "mejoras" con un `.exe` viejo. Validar por métrica.
- **La reescritura de DL en submit** para el tagging **se descartó** (falló 2×); la vía es el **hook
  del port** (patrón Goemon).
- No editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
