# AGENTS.md — arranque obligatorio para cualquier sesión

Proyecto: portar **Hybrid Heaven (N64, `work/roms/us_dec.z64`)** a PC (N64Recomp). Fase actual:
**tarea #3 — mapa overlay→RAM base** (qué overlay se carga en qué dirección RAM y en qué momento).

## LEE ESTO EN PRIMER LUGAR (en este orden)

1. **`/app/sesion.md`** — handoff operativo completo. Léelo entero antes de tocar nada.
   Contiene: objetivo, entorno, calibración crítica, recetas, hallazgos y, al final, **§1/§12/§15**
   con el estado ACTUAL y las tareas pendientes priorizadas.
2. **`/app/notes/2026-09-08-overlay-directory.md`** — detalle técnico (byte-order, directorio
   0x8008DFC0, write-bp, sets confirmados). **§10.7** = los 2 sets de pantalla confirmados por
   captura+usuario (combate por turnos = `010F`+`01AA…01B8`+`0125/0127`; menú pausa =
   `0113…0121`).
3. `work/gameplay screenshots/README_bizhawk.md` — cómo funciona el flujo Windows/BizHawk.

## Calibración crítica (resumen; detalle en sesion.md §3)

- **El modelo NO ve imágenes.** Nunca afirmar haber visto una pantalla. El USUARIO ve los PNG
  desde su filesystem y describe. Percepción = ASCII (`ppmascii.py`) + ImageMagick + logs.
- **El usuario no ve adjuntos del chat**: todo PNG se guarda en archivo (`work/gameplay screenshots/`).
- Dumps RDRAM del harness Linux vienen **word-swapped** → bswap32. En BizHawk leer CPU BE.
- Reglas de etiquetado del usuario (ground truth): A rápidas = diálogos; R+A = pistola contra
  robots **sin HUD**; combate de mutantes = **por turnos con menú de golpes (sí HUD)**.

## Estado actual rápido

- Vía principal = usuario juega en **BizHawk/Windows** con el script **v5**
  `work/gameplay screenshots/bizhawk_hh_tracker.lua` (NOTA: ignorar el `.lua` viejo en `work/`).
- El script vuelca `game.log`/`buttons.log` + en cada F12 un `.png` y `.txt` **emparejados por
  wall-clock** en la carpeta compartida (auto). Dominio de memoria detectado: "System Bus".
- Lo pendiente AHORA (ver sesion.md §12): procesar la partida larga del usuario (¡aún no está en
  el contenedor!), correlacionar PNG↔dump, y etiquetar sets de pantalla con el usuario.

## Inventario mínimo de archivos

- `/app/sesion.md` — handoff (LEER PRIMERO). · `/app/notes/2026-09-08-overlay-directory.md` — notas.
- `/app/work/gameplay screenshots/` — folder compartida (logs + capturas + `session1/` archivada).
- `/app/work/scratch/sess42.dir.bin` — set gameplay de 31 entradas (referencia).
- `/app/tools/analysis/hhinput.c` — parche stick (4B) SIN commit todavía.
- GUI: no tocar `/app/work/*.so`, ROM, ni commits a menos que el usuario lo pida.