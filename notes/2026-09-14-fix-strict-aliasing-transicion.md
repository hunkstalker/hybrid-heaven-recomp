# 2026-09-14 — `-fno-strict-aliasing`: resuelta la transición (`fe00`) y nueva frontera de símbolos

> Continúa `notes/2026-09-14-cadena-d550-y-registro-0x74.md`. **Hito**: el juego cruza la
> transición (`fe00=0x3C01`, burst del loader, callback `80124CEC`) gracias a un fix de compilación.

## 1. Causa raíz: aliasing estricto en el C recompilado

`FUN_80125814` (registro de recursos) lee el id con `lhu $v0, 0x1A($sp)` **después** de
`sw $a0, 0x18($sp)`. En el port el id leído era **basura** (`0x7D30`, `0xA3C1`) mientras la palabra
en el slot era `0x00000074` (comprobado con instrumentación temporal: `raw18=00000074`,
`id=7D30`). Con `id >= 0x271` la función devolvía 0 → `d550` no se reseteaba → `bd6d` nunca se
escribía → la transición no llegaba.

Causa: los macros `MEM_W`/`MEM_H`/`MEM_BU` acceden al **mismo `rdram` con tipos distintos**
(`int32_t*`, `uint16_t*`, `int8_t*`). GCC a `-O2` con *strict aliasing* puede reordenar el load
antes del store (UB) y leer el valor viejo/basura. Los ports de referencia (Zelda64Recomp,
Goemon64Recomp) ya compilan con `-fno-strict-aliasing`; el CMake del port **no lo tenía**.

**Fix** (tracked): `port/HybridHeavenRecomp/CMakeLists.txt` → `add_compile_options(-O2 -msse4.1
-fno-strict-aliasing)` (rama no-MSVC). Reconfigurar (`cmake .`) y rebuild completo.

Efecto inmediato (run 25 s): `[TRC] STEP5808 id=0x0074 ... -> r=0x00000001` y `[CHN] 801257DC ...
d550=01` (reset) → `d550=0`. La cadena de la transición se desbloquea.

## 2. Hito: transición alcanzada

Run de 200 s (`work/debug/run_e768.log`, `HH_VERBOSE=1 HH_TBLTRACE=1`):

- `[LD384]` = **19** cargas (11 de boot + burst) ⇒ criterio del work order (`> 11`) **cumplido**.
- `[RND] vis=6720 ... fe00=0x3C01 fe02=0x80` ⇒ `fe00 > 0` **cumplido**; `node=53200004`
  (el objeto `0x801D03C0` ahora contiene código/datos decodificados).
- `[DISP] ... f1C=80124CEC` ⇒ el callback `80124CEC` se instaló (el eslabón que antes se quedaba en
  `80124C54`).
- `[EVQ] 0x08` (t≈108 s) consumido; después llega el burst y el juego sigue.
- El throw final ya no es el de antes: `Failed to find function at 0x801BF610` (símbolo que falta).

## 3. Símbolo añadido: `FUN_8001e768`

Durante el burst, el juego llama `0x8001E768`, que estaba dentro de `FUN_8001e66c`
(`size 0x1C4`). Es un mid-entry limpio (tras `jr $ra` en `0x8001E760`). **Split aplicado** en
`config/us_combined.syms.toml` y `config/us_ghidra.syms.toml`:

```
FUN_8001e66c  vram 0x8001E66C  size 0xFC
FUN_8001e768  vram 0x8001E768  size 0xC8
```

Recompilado (`python3 tools/recomp.py --config config/game_combined.toml --build`). Con esto el juego
llega a `fe00=0x3C01` y sigue hasta el siguiente símbolo ausente.

## 4. Nueva frontera: `0x801BF610` (colisión de secciones / modelo multi-módulo)

Tras la transición el juego llama `0x801BF610` y `0x801BF61C` (callers en módulo 19:
`funcs_19.c` 0x80126094/0x801260A0). El código **real** en RDRAM (dump `emu_cbd`) es:

```
0x801BF610: 3C01801E  lui at, 0x801E
0x801BF614: 03E00008  jr  ra
0x801BF618: AC24E828  sw  a0, -0x17D8(at)   ; 0x801DE828
0x801BF61C: 3C01801E  lui at, 0x801E
0x801BF620: 03E00008  jr  ra
0x801BF624: AC248CE4  sw  a0, -0x731C(at)   ; 0x801D8CE4
```

Son **setters de 0xC**. Pero al declararlos en las syms el recompilador falla:
`Unhandled link branch at end of FUN_801bf610` — la sección que mapea esa VRAM (la que generó
`funcs_35.c`) decodifica ahí **otro código** (`lui a1,0x801C; addiu; jal 0x800058DC; lw a0,0x20(sp)`),
es decir, el mismo VRAM aloja módulos distintos según lo que cargue `trans` en cada momento. Las
syms globales no distinguen por sección; el split colisiona y se revirtió (build restaurado).

**Pendiente**: resolver el mapa overlay→RAM por sección (ADR 0001 / TODO #3) o registrar estos
mid-entries por sección (como hacen los módulos idx 7/23/54 en `setup_module.py`), para poder
declarar `FUN_801bf610`/`FUN_801bf61c` sin romper la otra sección.

## 5. Implicaciones

- `-fno-strict-aliasing` es un fix **global** de compilación: puede corregir otras divergencias
  latentes del C recompilado (candidato a re-verificar TODO/notas previas).
- El port ya supera la transición ⇒ quedan al alcance la fase >1, los DLs de gameplay y geometría/
  píxeles una vez resueltos los siguientes símbolos del burst.

## 6. Comandos

```sh
# Reconfigurar flags tras tocar CMakeLists (build_dbg)
cd port/HybridHeavenRecomp/build_dbg && cmake . && make -j28
# Regenerar tras split de syms
python3 tools/recomp.py --config config/game_combined.toml --build
# Run con trazas
HH_VERBOSE=1 HH_TBLTRACE=1 timeout 200 "./Hybrid Heaven Recomp"
```

## 7. Artefactos (gitignored, `work/debug/`)

`run_nostrict.log`, `run_nostrict150.log` (antes del split), `run_e768.log` (transición alcanzada),
`recomp_e768.log`, `recomp_bf610.log`, `recomp_revert.log`, `run_dbg_{c,c2,c3,d,e,f}.log`
(instrumentación temporal del C generado, restaurada), `gdb_reg74*.log`.
