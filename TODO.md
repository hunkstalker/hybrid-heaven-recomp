# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` y `notes/` (no duplicar). Histórico: `notes/`, `notes/archive/`.

## Ahora (priorizado)

- [•] **Migrar a la vía de recompilación de la referencia (ELF + splat + residente limpio)**. Decisión
  2026-09-21 (ADR 0011): se abandona Ghidra-per-file (fronteras de imagen incompleta; el build llega
  al título sin fondo 3D). Plan por fases M0–M5 con gates:
  `notes/2026-09-21-migracion-via-referencia-elf.md`. **M0 HECHO** (splat 0.50.0 + spimdisasm 1.42.4
  en `toolchain/splat-venv`; MIPS por LLVM `llvm-mc`/`ld.lld`; `tools/install_splat.sh`,
  `tools/splat_headless.sh`). **M1 HECHO** (`tools/unpack_rom.py`: imagen expandida + `segments.json`
  + `file_table.h`; 91 code files, 0x368070 bytes). **M2 HECHO** (`tools/build_elf.sh` + `gen_link_syms.py`:
  splat → `llvm-mc` → `ld.lld` → `elf/hybrid-heaven.us.elf`; gate: reconstruye la imagen byte a byte).
  **M3 HECHO** (N64Recomp ELF mode, rc=0). **M4 HECHO — regresión resuelta**: N64Recomp ELF mode no
  aplicaba `use_lookup_for_all_function_calls` (fix en `main.cpp` del tool) + nombres libultra
  (`symbol_addrs.txt`) + 47 funciones del runtime registradas → boot carga 8/55/24 y **título con fondo
  3D**. **VALIDADO EN WINDOWS** (mantenedor): gameplay, primer NPC, cajas, **primer CaC**, ~30 min hasta
  el 6º combate **sin cuelgues ni crashes** → **bloqueante original RESUELTO**. **Siguiente: M5**
  (saneamiento y estructura: `legacy/` para la vía Ghidra, `config/`→`recomp/`, purgar `HH_*`, docs, pins
  y **push**). Aparte: **M4c** (SEGV al salir/teardown).
- [ ] **Migración a submódulos (hecho, sin commitear)**: `lib/{N64ModernRuntime,rt64}` como submódulos
  (ADR 0010); `regenerate.py` materializa el C como dir real; falta el push/force-push de los forks
  para que un clon limpio los resuelva.
- [ ] **Audio: sincronizar la tasa** (feedback del error de cola SDL en `osAiGetLength`) para quitar
  los descartes periódicos del watermark. Ver `notes/2026-09-18-suavizado-fase1-y-cache-loader.md` §2.
- [ ] **Menú IN-GAME de opciones PC (ADR 0008)**: reutilizar el menú del `expansionram` (módulo idx 23).
  **Antes: spike go/no-go** (nota 09-18 §6: handler de módulo end-to-end, rótulo con fuentes del juego,
  aplicar/persistir `GraphicsConfig`).
- [ ] **Definir ADR 0009** (estrategia de cobertura nativa / clean-room) **cuando se adopte la visión**
  de `docs/README.md`. Incluye el **manifiesto de reimplementadas** + **métrica de cobertura** (§5).
- [ ] **Teardown SEGV** al cerrar en Windows (`exe +0x12A602`): mapear con el `.map`, reproducir en
  Linux y arreglar el orden de deinit (respuesta a `EXCEPTION_EXECUTE_HANDLER`).
- [ ] **Mando**: identificar el botón N64 que abre el menú de **acciones/lucha en CaC** y asignarlo a
  **X** (`config.ini`). **Bloqueado por el CaC** (el juego se congela antes del combate): revisar cuando
  se resuelva la entrada al combate. Lo normal (pausa/inventario) sale con **Start** y está bien.
  Decidir también `LB` y el atajo de cámara/1ª persona.
- [ ] **Limpieza de instrumentación**: decidir sobre `requeue_pi=true`, los `[MQDROP]`, la sombra
  `hh_sh_*` y el watchpoint (ya está todo gated tras `HH_DIAG`).
- [ ] **Smoke de arranque** (opcional, requiere ROM): con la ROM en `rom\` junto al `.exe`, comprobar
  que la encuentra y que no hay `Failed to find function`. En Docker: `HH_HEADLESS=1` + `rom/`.

## Backlog (priorizado)

- [x] **CaC: el port no entra al combate (RESUELTO 2026-09-21)**. Con la migración a la vía ELF/splat
  (ADR 0011) y el fix de `use_lookup_for_all_function_calls` en ELF mode, el port entra al CaC. Histórico
  de la etapa per-file: `notes/2026-09-20-nodo-8005bf14-origen-y-captura.md` y `notes/2026-09-19-*`.
- [ ] **Textos/traducción** (requisito de producto): encoding + extracción + re-inserción.
- [ ] **Guardado**: validar Controller Pak contra el emulador; ficheros en disco + **Rumble**.
- [ ] **Builds/empaquetado**: validar "build once, promote" en GitHub y empaquetado **Steam Deck**.
- [ ] **Tarea #3**: mapa overlay→RAM por BizHawk (complementa la medición empírica de bases).
- [ ] **Cadencia/hitches de puertas** (mejora): precarga/decode y enganche a VI
  (`notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md`).
- [ ] **Símbolos**: fronteras gruesas (`0xADDR:0xSIZE`) y auto-mid del módulo 12 (datos como código).
- [ ] **Data-as-code** (189 sospechosas): limpiar → permite reevaluar `use_lookup_for_all_function_calls`.
- [ ] **Ramas del toolchain**: publicar `hybrid-heaven-tool` (13 ficheros) para reproducir la
  regeneración (el build no la necesita).
- [ ] **Higiene del repo** (`notes/2026-09-16-limpieza-repo-inventario.md`): archivar scripts one-off
  de `tools/analysis/`, variantes obsoletas de `config/`, decidir el `work/` rastreado. **NO borrar**
  `*.syms.toml.keep`, `keep_syms*.txt`, `module_extras.json`, `recomp/n64recomp_changes/*`.
- [ ] **Sanear menciones a la ROM en docs/notas** (frases cortas del juego en `notes/`).

## Hecho (resumen; detalle en `notes/`)

- [x] **Vía de recompilación ELF/splat (ADR 0011)** + **entrada al CaC validada en Windows (2026-09-21)**:
  START → menú → GAME START → gameplay, primer NPC, cajas, **primer CaC**, ~30 min hasta el **6º combate**
  sin cuelgues; **mando** y **guardado/carga** correctos.
- [x] Arranque completo, gameplay, menús, combate y cinemáticas en Windows (RTX 4080) con mando Xbox.
- [x] Guardado en cápsula (Controller Pak) validado (`osPfsFindFile`→5) y carga en el playtest del 2026-09-21.
- [x] Audio `aspMain` del ROM recompilado a 43200 Hz; perfiles de mando por contexto.
- [x] Fase B (ADR 0007): cache de assets + loader LZKN64 nativo.
- [x] Rendimiento: `get_function` sin `getenv` por llamada → stalls de 1-4 s a 0 y 30 ticks/s
  (`notes/2026-09-18-faseb-cache-trans-implementado.md` §8/§8b).
- [x] Replay fiel (`HH_REPLAY_MODE=vi`); build reproducible + CI/Releases (ADR 0005).

## Documentos de detalle (no duplicar)

`PROYECTO.md` · `docs/README.md` (visión) · `docs/architecture.md` · `docs/adr/` · `docs/workflows.md`
· `notes/2026-09-1*.md`.
