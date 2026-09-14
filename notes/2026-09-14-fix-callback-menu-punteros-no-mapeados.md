# 2026-09-14 — Fix del callback del menú (accesos a direcciones no mapeadas)

**Objetivo**: eliminar el SEGV de `M24_FUN_801cb71c` al quedarse en el menú / volver al menú.

## Causa raíz

- El dispatcher `FUN_80005270` llama al callback `nodo+0x1C` (aquí `0x801CB71C`, módulo 24) con
  `$t5 = 0x8008D5D8` (registro heredado, la función es una continuación). El callback hace
  `lw $t6, 0x30($t5)` y luego `sb $v1, 0x4A($t6)`.
- **El emulador también llama a ese callback** (5010 veces en un run de 180 s; `HH_PCDUMP` en el core
  instrumentado: mismos `$t5/$s0/$s1` que el port) y **no crashea**: `[0x8008D608] = 0`, así que
  escribe a la dirección 0x4A, que en mupen cae dentro de RDRAM (física) y se ignora.
- El port calculaba `rdram + ((v) - 0xFFFFFFFF80000000)`: para `v = 0x4A` eso da un offset
  `0x8000004A` (>1 GB, PROT_NONE) → **SEGV**.

## Fix (runtime, documentado en `docs/architecture.md` §5)

1. `lib/N64ModernRuntime/N64Recomp/include/recomp.h` (`MEM_*`): `MEM_OFF(v)` mantiene la fórmula
   original para direcciones mapeadas (KSEG0/KSEG1, incluida la ventana MMIO en `0x20000000+`);
   para no mapeadas: bajas (<8 MB físicos) → RDRAM física (como mupen), resto → scratch en
   `0x0FFFFF0` (bajo el heap `[16 MB, 1 GB)`). Copia de referencia en `config/n64recomp_changes/`.
2. `lib/N64ModernRuntime/ultramodern/include/ultramodern/ultra64.h` (`TO_PTR`): misma conversión
   segura para los reimplementados del runtime. Sin esto, el siguiente crash era
   `osSendMesg` con cola NULL (`MQ_GET_COUNT` sobre `rdram+0x1000000`).

**Nota**: un primer intento con `addr & 0x1FFFFFFF` rompió el render (mapeaba los registros MMIO
`0xA44xxxxx` a `0x044xxxxx` en vez de la ventana `0x244xxxxx` que usa el runtime). El A/B con
capturas y un log de diferencias viejo/nuevo lo detectó; la versión final solo cambia lo no mapeado.

## Verificación

- Escenario que crasheaba (START único a 60 s y menú en reposo): **185 s, exit=0, 0 SEGV, 0 símbolos
  faltantes**; capturas `work/debug/port_verify_{90,110,140,165,180}.png` (menú, títulos, cutscene).
- STARTs repetidos (60..270 s cada 15 s): 290 s sin crash; aparece un miss nuevo
  (`0x801FF260`, ver abajo).

## Frontera nueva (separada)

- `0x801FF260` (módulo 25, cola del módulo): **el emulador también salta ahí** (3 veces en
  `emu_menu2.jal`), pero nuestras syms/blob de módulo 25 solo cubren hasta `0x801FD420`
  (112704 bytes). Al soft-stubbearlo el estado se estanca (pantalla negra). Hay que revisar la
  extracción/loader del módulo 25 (posible cola sin cubrir) — no es parte del fix del callback.

## Evidencia

- `work/debug/run_verify.log`, `port_verify_*.png` (verificación limpia).
- `work/debug/gdb_setter.log`, `gdb_wp*.log`, `run_pcdump.log` (instrumentación del emulador).
- `work/debug/emu_menu2.jal` (traza; `0x801CB71C` × 5010).
