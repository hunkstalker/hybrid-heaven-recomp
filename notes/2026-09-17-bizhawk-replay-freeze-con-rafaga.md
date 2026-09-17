# 2026-09-17 — Replay de BizHawk: freeze CaC reproducido CON la ráfaga #22 (teoría del burst saltado, refutada)

> Continúa `2026-09-17-replay-clock-y-desfase-frames-wip.md` (§4b) y
> `2026-09-17-cac-timeline-modulo24-periodo.md`. Grabación del mantenedor en BizHawk (10,7 min,
> frames 10574-38546; input por frame con `bizhawk_hh_tracker_v3.lua`).

## 1. Setup del par port↔emulador (alineado)

- Conversión: `tools/analysis/bizhawk_to_replay.py "work/gameplay screenshots/replay.log"
  work/debug/cac/bizhawk1/hh_replay_off100.txt --vis-offset -100`.
  - El reloj VI del emulador va ~100 VI por delante del port para el mismo estado (medido con el
    contador de la transición `[0x801D8DA8]`: a VI 11309, emu=0x0D15 y port=0x0D12 → 3 ticks/6 VI).
    Por eso el port usa `--vis-offset -100` y el emulador el fichero sin desplazar (`hh_replay_bizhawk.txt`).
  - La grabación original de BizHawk empieza en frame 10574 (el mantenedor adjuntó el script con el
    juego ya arrancado; F11 no resetea `emu.framecount()`). El tramo 0..10573 va relleno sin input.
- Comandos: ver `work/debug/cac/bizhawk1/consola_off100.log` (port) y
  `work/debug/cac/emu_bizhawk1/stdout.log` (emulador).

## 2. Resultado: FREEZE reproducido en el port (y el emulador no se cuelga)

- Port: `polls` congelados en **15326** (VI≈32122, t≈535 s) mientras audio/VI siguen; watchdog
  `[HANG] volcado escrito (polls 15.0s, audio 0.0s, VI=32122)`; cascada
  `[BADMQ] fields mq=8005C084 msgCount=0 valid=… first=… msg=80000000 (msg=8005C4B0)`.
  Dump: `work/debug/cac/bizhawk1/hh_hang_rdram_20526_0.bin` (+ `hh_hang.log`).
- Emulador (mismo replay): corre hasta el final sin freeze; objeto `0x8024A990` **sano** en todos los
  dumps (`+0x00=8024AAF8`, `+0x1C=80135320`): `emu.vi30000.bin`, `emu.vi38400.bin`, `emu` final.
- Port a VI 30000 (dump): `0x8024A990` con relleno `F0F0F0F0` → el objeto no está creado/está muerto
  ya antes de VI 30000.
- **La ráfaga #22 SÍ se ejecuta en el port** en esta pasada: cargas #23-35
  (`00B7BAF0@8025D168`, `007F375C@80264EC8`, `00B7C55A@80265F68`, … `007554BE@8028A668`) idénticas al
  emulador. → **La hipótesis "el port se salta la ráfaga #22 y eso cuelga el CaC" queda REFUTADA**:
  con la ráfaga hecha, el port se cuelga igual.

## 3. Primera divergencia de flujo (nueva, con la ráfaga hecha): carga #49 (~VI 20500)

Secuencias de cargas alineadas 1:1 hasta la **#48**; en la #49:

- Emulador (t=342,0 s): recarga de recursos de menú/módulo (`005F1190@801BF1A0`, `0068BF26@803837E0`,
  `005F1190@801FA948`, …) — el demo/attract termina y vuelve a menú/escena.
- Port: **sigue con ráfaga de escena** (`00B7EF20@8025D168`, `00B7F42A@80263358`, `00B80216@80264BA8`,
  … 14 cargas) y **14 cargas más tarde** engancha la cadena del emulador (`005F1190@801BF1A0` en port
  #63 = emu #49). Después, las cadenas vuelven a parecerse (#70-82 ≈ emu #80-92) con diferencias
  puntuales (port `00594B50` vs emu `00599670`; port `006FEDCC/0074247A/006DFF86/00055F00` vs emu
  `006E8E0A/00D87B1E/00D87CC0/007F6830`).
- Es decir: el primer desvío real está en el **flujo de escena/recursos al final del demo** (~VI
  20500), no en la ráfaga.

## 4. Siguiente paso exacto

1. **Recompilar** para tener `[LD384] … s=<muestra>` (el binario de esta pasada es anterior al cambio;
   el `s=` está ya en `overlays.cpp`): así la carga #49 del port queda con VI/muestra exactos.
2. Dumps finos alrededor de VI 20500 en ambos lados (p. ej. 20400/20500/20600/20800) y comparar:
   estado de la línea temporal del módulo 24 (`0x801D8CE8` g2, `0x801D8DA8`, `0x801D8D00`, `0x801D8CFC`),
   directorio de módulos (`0x8008DFC8` base), objeto de transición `0x801FDA70` y colas del loader.
3. Con la primera diferencia de estado localizada, seguir aguas arriba (mismo método, dumps en el
   VI donde aparece).

## 5. Reparto de tareas

- **El test de juego sigue siendo del mantenedor (usuario)**; el entorno de dev solo corre pasadas
  headless (replay/emulador). No hace falta más input por ahora: el replay de BizHawk ya llega y
  reproduce el freeze. El ofrecimiento del mantenedor de "grabar con un script lo que haga falta
  mientras juega" queda como fallback si hiciera falta otro tramo.
- Ficheros de esta ronda: `work/debug/cac/bizhawk1/` (replay convertido, logs del port),
  `work/debug/cac/emu_bizhawk1/` (logs y dumps del emulador), `work/debug/cac/bizhawk1/hh_hang_*_20526_*`,
  `work/gameplay screenshots/{replay,state,buttons}.log` (grabación original).
