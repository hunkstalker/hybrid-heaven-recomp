# CaC Parte B (B1) — Solape de módulos 23/8 y entry interior `0x801C1EE0`

> Evidencia de la ronda B1 del plan `notes/2026-09-17-plan-revision-bloqueo-cac.md`.
> Fecha: 2026-09-17. Contexto: pacing ya corregido; el freeze del combate persiste.

## 1. Firma del cuelgue (volcado de hoy, `hh_hang_rdram_31612_0.bin`)

- `cd4c=0`, `M23 sel (0x801CC8C4)=0xAF`, gate `0x8017DD92=0`, todas las colas vacías.
- `0x8005C288.blocked_on_recv = 0x80059D80` (**tid 5**), `0x8005C4F0.blocked=tid17`,
  `0x8005C528.blocked=tid16`, `0x8005C4B8.blocked=tid18`, `0x8005C560.blocked=tid19`.
- `0xFFFF84CD` presente en RDRAM en **`0x8024A2A4`** (el objeto/campo varía por partida).
- Comparado con dumps anteriores (`3692`, `5292`, `7304`, `19840`, `21912`): **misma firma**
  (cd4c=0, M23=0xAF, q288=tid5, q4F0=tid17) con el callback corrupto en direcciones distintas
  (`0x8024A990+0x1C` a veces, otras veces `0x8024AAF8+0x1C`, etc.). No es una regresión de esta
  sesión.

## 2. B1 — solape de símbolos y registro dinámico (hallazgo nuevo)

- La sección de **módulo 23 es la tabla índice 2** (`section_2_module23_funcs`):
  `rom=0x03000000, ram=0x801BF1A0, size=0x10B50, index=2`
  (`config/RecompiledFuncs_combined/recomp_overlays.inl:5601`).
- Cargas observadas (`hh_ovl.log` de `logs_fix2`):
  - `section=3` (= idx 2, módulo 23) → **`ram=0x801BF1A0`** (t=1.768) y luego **`0x801FA948`**
    (t=1.926): el `trans` **reubica** el mismo módulo.
  - `section=7` (módulo 7) → **`ram=0x801BF1A0`** (t=17.335): **reutiliza la base** de la primera
    carga del módulo 23.
  - Módulo 8 → `ram=0x801E4AA0`; módulo 9 → `0x8021B150`; módulo 10 → `0x802408F0`.
- **`0x801C1EE0` es símbolo de módulo 8** (`M8_FUN_801c1ee0`, size 0x60) y a la vez cae **dentro**
  de `M23_FUN_801c1dc0` (0x801C1DC0+0x290; offset 0x2D40 < 0x2EB0). No es un prólogo de función en
  el C de M23: es código interior (`andi $t2,$v0,0xB000`).
- Los conjuntos de símbolos de **M8 y M23 solapan en 420 rangos** (misma ventana `0x801BF1A0+`).
- Registro del port (`librecomp/src/overlays.cpp`): `load_overlay()` hace `func_map[ram+offset]=func`
  (sobrescribe); `unload_overlay*()` borra solo las direcciones de sus propios símbolos. Si un módulo
  se reubica o se reutiliza su base sin descargar, quedan **entradas rancias** de otro módulo en
  direcciones que el nuevo no cubre (p.ej. `0x801C1EE0`).
- Hipótesis B1: si la lógica de módulo 23 llama/usa un puntero a su código interior `0x801C1EE0`
  cuando M23 es residente, el port resuelve `M8_FUN_801c1ee0` (código de **otro módulo**) → state
  machine divergente → el `case 2` de `M23_FUN_801c1dc0` nunca se arma. El experimento revertido de
  la nota del plan (desregistro al reutilizar base) no lo descartaba con datos de ejecución.

## 3. Replay: lo que falta para reproducir en Linux

- `hh_replay_fight.txt` (08:08) **no reproduce el combate**: se grabó cargando partida y el replay
  solo reproduce input (no restaura el save) → en Linux arranca una partida nueva y la secuencia no
  llega al CaC (verificado: `M23_mask` solo en boot; `M23_entry/arm/setup` = 0 llamadas).
- **Necesario**: grabar con `run_corrupt.bat` una pasada **desde partida nueva (sin cargar)** hasta
  el freeze. Ese `.txt` permite reproducirlo en Linux y trazar en el momento exacto:
  - registros de sección (`hh_ovl.log`) y base activa de M23/M8/M7,
  - quién llama a `0x801C1EE0` y a qué función resuelve (`func_map`),
  - estado de la cadena `0x801C40F8/0x801C43BC/0x801C44C4/0x801C45C8`.

## 4. Siguiente (tras el replay)

1. Reproducir y volcar `func_map` (o trazar `get_function`) para el rango `0x801BF1A0-0x801C4000`
   durante la entrada a combate: ¿qué módulo dueña cada dirección?
2. Si se confirma entrada rancia: fix candidato v3 = al cargar una sección, **borrar el rango
   completo** `[ram, ram+size)` antes de registrar (y registrar las dos bases activas). Validar que
   no rompe boot (la v1 lo rompía) y que el CaC avanza.
3. En paralelo, re-medir `cd4c` en limpio (medición ligera) para descartar problemas del gate.
