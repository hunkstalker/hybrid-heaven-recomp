# 2026-09-14 — Cadena `d550` → `bd6d` y registro del recurso `0x74` (bloqueo de la transición)

> Continúa `notes/2026-09-13-fix-corrupcion-audio-y-evento-modulo.md` y el work order
> `notes/2026-09-13-workorder-evento-modulo-0x7D.md` (ruta A: trazar el evento y sus productores).
> Evidencia de la sesión que localiza el bloqueo de la transición en el registro del recurso `0x74`.

## 1. Resumen

El audio ya es estable (300-420 s) y el nodo `0x801D0474` recibe el callback `801C2050` a t≈108 s
(emulador t≈63,0 s) y lo ejecuta cada frame. La transición no llega porque **el evento de módulo
`0x7D` nunca se encola**, y eso es consecuencia de una cadena de estado:

1. En el boot, `FUN_801267B8 → FUN_801267C0` (id `0x74`) inicializa el motor con
   `FUN_80125774(a1=0x3000)`, que pone **`[0x8008D550]=1`**.
2. El propio `FUN_801267C0` cierra con `FUN_801257DC()` (pone `d550=0`) **solo si**
   `FUN_80125808(id)` devuelve ≠ 0.
3. En el port `FUN_80125808(0x74)` devuelve **0 siempre** ⇒ `d550` queda 1 para siempre.
4. En la transición, `FUN_8012FE50` (llamada desde `FUN_801C5A00/0C`) empieza con
   `if ([0x801BBD6D]!=0) return; if ([0x8008D550]!=0) return;` ⇒ en el port sale por la segunda
   condición y **nunca escribe `[0x801BBD6D]=1`**.
5. Sin `bd6d`, el callback `FUN_80124C68` (nodo `0x801CFE20`) no llama a `FUN_8012FD1C` ni instala
   `80124CEC`; el script no encola `0x7D`; no hay burst del loader; `fe00=0`.

## 2. Evidencia (port vs emulador)

| Medida | Emulador | Port |
|---|---|---|
| `FUN_801C2050` (nodo `801D0474`) | instalado t=63,03; **1 llamada/VI** (`ra=8000535C`) | instalado t≈108 s; **1 llamada/frame** (`ra=0`) |
| `[0x8008D550]` (`d550`) | 0 en t=16 s y t=70 s (writes CPU solo de reset) | **1 desde VIS≈660** y se mantiene |
| `[0x801BBD6D]` (`bd6d`, gate de `FUN_8012FE50`) | transitorio 1 (t≈62,98) | **nunca** |
| `FUN_80125774` (set d550) | t=10,29 a0=0; t=10,49 a0=0x3000; t=10,50 a0=0; t=65,07 a0=0 | a0=0x3000 (gdb) y queda 1 |
| `FUN_801257DC` (reset d550) | t=10,30, 10,52 (`ra=8012680C`, desde `FUN_801267C0`), 65,09 | solo t≈0,3 s (boot) |
| `FUN_80125808(0x74)` | devuelve ≠0 (registra y resetea) | **devuelve 0** (repetido, `[TRC] STEP5808`) |
| directorio recursos `0x8008DFC0` | `0018 0073 0075 007C 012D 0074(80265FF8)` @16 s | `0018 0073 0075 007C 012D` @VI720; **sin 0074** |
| `FUN_80004560(0x74)` (registro) | t=10,49, `ra=0x801258BC` (dentro de `FUN_80125814`), → `FUN_8001752C` → `FUN_80016EAC` → SETID/SETPTR | no observado |

Timeline emulador (`HB_TRACE_EXEC`): `FUN_80016EAC(0x74)` t=10,49 `ra=0x80017540`;
`FUN_8001752C(0x74)` t=10,49 `ra=0x800045B8`; `FUN_80004560(0x74)` t=10,49 `ra=0x801258BC`;
SETID(0x74) t=19,06 (perturbado) `ra=0x80016F10`.

## 3. Mecanismo del registro de recursos (para la siguiente sesión)

- `FUN_80125808` (stub) → fallthrough → `FUN_80125814` (ambos con fix aplicado):
  - `t6 = [0x8008D550]`; si 0 → salida por `L_80125910`.
  - id=0: return 1; id≥0x271: return 0.
  - si `[0x8008D570]` (`c0`) ≠0 → `L_80125888`; si no → `FUN_80017064(id)`:
    - resultado `-1` → `L_80125874`: `[0x8008D570]=1`, `FUN_80004560(id)` (registra) →
      `[0x8008D578]` (`42C4`) = ptr; si ≠0 → `[0x8008D570]=2` y `FUN_80004BB0(id,ptr)` →
      return 1/0; si =0 → return 0.
    - resultado ≥0 → return 2.
- `FUN_80004560(id)` → `FUN_8001F290(size)` + `FUN_8001752C(id, ptr)` → `FUN_80016EAC` →
  `FUN_80017014`/`FUN_8001703C` + `FUN_80017384`/`FUN_800173B8` (escriben el directorio).
- `FUN_801267C0`: si `t6(=d550)==0` llama `FUN_80125774(a1)`; luego `FUN_80125808(id)`; si el
  resultado ≠0 llama `FUN_801257DC` (reset). En el port return=0 ⇒ d550 se queda en 1.

## 4. Nota metodológica (instrumentación)

- El build tiene `use_lookup_for_all_function_calls=false`: muchas llamadas son **directas** y NO
  pasan por `get_function`, así que los wrappers del runtime (`overlays.cpp`) **no siempre** se
  aplican (p.ej. `FUN_80004560`, `FUN_80017064`, `FUN_8001752C` no se ven; sí se ven los que se
  llaman indirectamente o vía LOOKUP). Para los directos: instrumentar temporalmente el C generado
  (copia + restaurar) o gdb (≈25× más lento; llegó a VIS 554 en 240 s).
- `[RND]` ahora incluye `d550=%02X`. Instrumentación `[TRC] STEP5808` ampliada con `c0/ff/d558`.
- `[REG]`/`[CHN]` añadidos (gated por `HH_TBLTRACE`), útiles aunque las llamadas directas no se vean.

## 5. Siguiente (work order)

1. **Instrumentar temporalmente `FUN_80125814`** (C generado) con trazas en `ENTER`, tras el lookup
   `FUN_80017064`, y antes de cada return, para ver qué rama toma con id=0x74 en el port
   (precondiciones ya medidas: `d550=1, c0=0, ff=0, d558=0`). La rama esperada es
   `lookup == -1 → L_80125874 → FUN_80004560`; el port devuelve 0, así que o el lookup devuelve ≥0
   (return 2, no observado) o el camino `FUN_80004560` corre con `[0x42C4]==0` / `FUN_80004BB0=0`.
2. Comparar con el emulador el **directorio de recursos** en el mismo hito (el port no tiene la
   entrada `0074`; ver §2) y el **origen de la entrada** (¿directory Nisitenma estático `0x80038FF0`
   vs registro dinámico?). Si es dinámico, por qué el port no llama `FUN_80004560(0x74)`.
3. Fix según hallazgo (syms/split/patch en `config/` o runtime) y validar: `d550=0` en el port →
   `[0x801BBD6D]=1` en la transición → `80124CEC` instalado → `[EVQ] 0x7D` → `[LD384] > 11` →
   `fe00 > 0` → primeras display lists de gameplay.

## 6. Artefactos (gitignored, `work/debug/`)

Port: `run_cb2050.log`, `run_evq3.log`, `run_m23cb.log`, `run_chain.log`, `run_gate550.log`,
`run_d550.log`, `run_5808.log`, `run_c0ff.log`, `run_find74.log`, `gdb_d550b.log`, `gdb_reg74*.log`,
`run_dbg_c{,2,3}.log` (instrumentación temporal del C generado, ya restaurada).
Emulador: `emu_cb70_parsed.txt`, `emu_evp70_wr.log`, `emu_chain_wr.log`, `emu_setid40_wr.log`,
`emu_reg74{,b,c}_wr.log`, `emu_dir_wr.log` (+ `emu_dir` dump), `emu_bbd_wr.log`.
Dumps: `port_vi720.bin` (port a VIS 720), `emu_ctxwp` (emulador a 16 s), `emu_cbd` (70 s).
