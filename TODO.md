# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` y `notes/` (no duplicar). Histórico: `notes/`, `notes/archive/`.

## Ahora (priorizado)

- [ ] **Cerrar la publicación (2026-09-21)**: push de `main` + **re-publicar `RecompiledFuncs`** en el
  repo privado de secretos (`HH_SECRETS_REPO`/`HH_SECRETS_PAT`; ADR 0009) → CI verde (Windows debe
  compilar con la tabla runtime de 47) → **Release `v0.1.1`** (tag o `workflow_dispatch`).
  **Validar en Windows**: cierre limpio (M4c) y gameplay.
- [ ] **Audio: sincronizar la tasa**: quitar los descartes periódicos del watermark con el *feedback*
  del error de cola SDL en `osAiGetLength` (`notes/2026-09-18-suavizado-fase1-y-cache-loader.md` §2).
- [ ] **Mando (desbloqueado por el CaC)**: identificar el botón N64 que abre el menú de **acciones/lucha
  en CaC** y asignarlo a **X** (`config.ini`); decidir `LB` y el atajo de cámara/1ª persona.
- [ ] **Menú IN-GAME de opciones PC (ADR 0008)**: reutilizar el menú del `expansionram` (idx 23).
  **Antes: spike go/no-go** (nota 09-18 §6).
- [ ] **Limpieza de instrumentación**: decidir sobre `requeue_pi=true`, `[MQDROP]`, la sombra `hh_sh_*`,
  el watchpoint y `HH_NO_STREAMED_LOADS` (`src/hooks/sections.cpp:149`). Todo gated tras `HH_DIAG` salvo
  el último; los workarounds per-file (`HH_S0FIX`/`HH_VI_EVERY`/`HH_FLAT_ALL`) ya no existen.
- [ ] **Smoke de arranque** (opcional, requiere ROM): ROM en `rom\` junto al `.exe` (o `HH_HEADLESS=1` +
  `rom/` en Docker): la encuentra y sin `Failed to find function`.
- [ ] **Definir ADR 0009** (cobertura nativa / clean-room) cuando se adopte la visión de
  `docs/README.md`: manifiesto de reimplementadas + métrica de cobertura.

## Backlog (priorizado)

- [ ] **Textos/traducción** (requisito de producto): encoding + extracción + re-inserción.
- [ ] **Guardado**: validar Controller Pak contra el emulador; ficheros en disco + **Rumble**.
- [ ] **Builds/empaquetado**: **Steam Deck**; validar `release.yml` end-to-end.
- [ ] **Tarea #3**: mapa overlay→RAM por BizHawk (complementa la medición empírica de bases).
- [ ] **Cadencia/hitches de puertas** (mejora): precarga/decode y enganche a VI
  (`notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md`).
- [ ] **Símbolos**: fronteras gruesas (`0xADDR:0xSIZE`) y auto-mid del módulo 12 (datos como código).
- [ ] **Data-as-code**: limpiar sospechosas → permite reevaluar `use_lookup_for_all_function_calls`.
- [ ] **Ramas del toolchain**: publicar `hybrid-heaven-tool` (13 ficheros) para reproducir la
  regeneración (el build no la necesita).
- [ ] **Higiene**: archivar scripts one-off de `tools/analysis/`. **NO borrar** los `*.keep`,
  `keep_syms*.txt`, `module_extras.json`, `recomp/n64recomp_changes/*`.
- [ ] **Sanear menciones a la ROM en docs/notas** (frases cortas del juego en `notes/`).

## Hecho (resumen; detalle en `notes/`)

- [x] **Vía de recompilación ELF/splat (ADR 0011), M0–M5** + **entrada al CaC validada en Windows
  (2026-09-21)**: START → menú → GAME START → gameplay, primer NPC, cajas, **primer CaC**, ~30 min
  hasta el **6º combate** sin cuelgues; **mando** y **guardado/carga** correctos.
- [x] **Estructura/higiene (M5)**: port en la raíz (`src/{platform,hooks,subsystems}`), `recomp/tools/`,
  intermedios → `build/recomp/`, vía Ghidra → `legacy/`, `config/`→`recomp/`, `work/` fuera del repo
  (scratch gitignored), purga `HH_*`, docs vivas + créditos.
- [x] **Teardown SEGV (M4c) RESUELTO** (Linux): el runtime liberaba RDRAM y el planificador seguía
  despachando hilos al salir; fix en el fork NMR (no liberar RDRAM + parar el planificador).
  `notes/2026-09-21-m4c-teardown-segv.md`.
- [x] **CI con el C recompilado (ADR 0009)**: repo privado de secretos + PAT
  (`notes/2026-09-21-ci-recompilado-desde-repo-privado.md`).
- [x] **Submódulos** `lib/{N64ModernRuntime,rt64}` publicados (forks propios; ADR 0010).
- [x] Arranque completo, gameplay, menús, combate y cinemáticas en Windows con mando Xbox.
- [x] Guardado en cápsula (Controller Pak) validado (`osPfsFindFile`→5).
- [x] Audio `aspMain` del ROM recompilado a 43200 Hz; perfiles de mando por contexto.
- [x] Fase B (ADR 0007): cache de assets + loader LZKN64 nativo.
- [x] Rendimiento: `get_function` sin `getenv` por llamada → stalls de 1-4 s a 0 y 30 ticks/s.
- [x] Replay fiel (`HH_REPLAY_MODE=vi`); build reproducible + CI/Releases (ADR 0005).

## Documentos de detalle (no duplicar)

`PROYECTO.md` · `docs/README.md` (visión) · `docs/architecture.md` · `docs/adr/` · `docs/workflows.md`
· `notes/2026-09-1*.md`.
