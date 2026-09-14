# 2026-09-14 — Registro dinámico de módulos (bases reutilizadas): transición funcional

> Continúa `notes/2026-09-14-fix-strict-aliasing-transicion.md`. **Por qué era la tarea**: con la
> transición cruzada el juego carga los módulos del burst (Nisitenma 24/25/99) en bases de VRAM
> **reutilizadas** (idx 24 sobre la base de idx 23, idx 99 sobre la de idx 54); el modelo de
> pre-enlazado fijo + registro estático (`register_flat_code`) no podía ejecutarlos. Era el paso
> obligatorio entre "transición" y **geometría/píxeles** (ADR 0001 / TODO #3).

## 1. Qué se implementó

### Runtime (`lib/N64ModernRuntime`, gitignored; documentado en `architecture.md` §5)
- `overlays.hpp/.cpp`: **`ModuleSource { src_rom, rom_addr }`**, `register_module_sources()` y
  `load_module_by_source()`; `register_flat_code()` **omite** las secciones de módulos (se registran
  al cargarse). `load_module_by_source` busca la sección por `rom_addr` **en la tabla ya ordenada**
  por `init_overlays` (no por índice fijo).
- `hh_wrap_FUN_80003824` (loader de módulos) ahora se instala **siempre** en `get_function`; tras
  descomprimir el blob, registra la sección recompilada en la base real que pidió el juego
  (`a1`). Soporta que un módulo reemplace a otro en la misma VRAM.

### Pipeline
- `setup_module.py`: `MODULES` ahora **7/23/54/24/25/99** (idx 24 = ROM `0x5FBEC6`, 25 = `0x60F476`,
  99 = `0x6DCA78`; CRC verificados); prefijo por módulo (`M24_FUN_...`, evita colisiones C);
  genera `config/module_sources.inc` (para el port) y `config/keep_syms.txt`.
- `tools/analysis/gen_module_extras.py` (nuevo): deriva mid-entries de una traza `HH_JALTRACE` del
  emulador, con **desambiguación por fase** (`--boot-trace` pre-burst → módulos de boot; solo
  post-burst → módulos del burst) y filtro de delay-slots.
- `tools/analysis/validate_syms.py`: ahora es **consciente de sección** (los módulos solapan VRAM) y
  acepta `--keep`/`--keep-file` (entradas indirectas que no se fusionan).
- `tools/analysis/fix_fallthroughs.py`: resuelve continuaciones **dentro de la misma sección**
  (prefijo `M<n>_`), no por dirección global.
- `recomp.py` pasa `keep_syms.txt` al validador.
- `tools/analysis/add_missing_funcs.py` (ya existía) usado iterativamente para mid-entries planos:
  `+14` entradas en `config/us_ghidra.syms.toml` (`0x8001E87C`, `0x80020D3C`, `0x80024EB8`,
  `0x80024F18`, `0x800257F8`, `0x80025A00`, `0x80025A38`, `0x80025AF8`, `0x80025B10`, `0x80025B4C`,
  `0x80025C90`, `0x80025ED4`, `0x8002D4A8`, `0x80024D50`).
- `config/game_combined.toml`: el parche de instrucción pasa a `func = "M7_FUN_80125814"` (prefijo).
- Extras manuales relevantes: m23 `0x801C0C08`; m24 `0x801BF610`, `0x801BF61C`, `0x801CDBF0`,
  `0x801C2420`; m24 auto/json `0x801C5A00`.

### Port
- `src/main/register_overlays.cpp` incluye `module_sources.inc` y llama
  `recomp::overlays::register_module_sources(...)`.

## 2. Resultados (run de ~234 s, `work/debug/run_clean_ovl.log` / `run_soft4.log`)

- **Loader `[LD384] = 20`** ⇒ burst completo; `[OVL]` registra secciones 1..6 (módulo7, 54, 23,
  24 en `0x801BF1A0`, 25 en `0x801E1BE0`, 99 en `0x8038B7E0`).
- **`fe00=0x3C01`, `fe02=0x80`** y `node=53200004` (objeto de boot con código decodificado).
- **0 `Failed to find function`** en un run `HH_SOFT_LOOKUP=1` de 220 s (13+1 mid-entries planos
  resueltos iterativamente).
- **3953 tasks gfx (type=1) y 14058 audio (type=2)** en 234 s ⇒ RT64 recibe DLs continuamente.
- Sin crash durante el run (el SEGV ocasional al final es el quit del `timeout`; stack con hilos/colas).

## 3. Frontera actual

1. **`0x80037750` (fase) sigue 0** pese a `fe00`/burst ⇒ la progresión de gameplay no arranca.
2. **Crash determinista en módulo25** (`M25_FUN_801e2d94`, `funcs_59.c` ~0x801E31xx) en runs largos:
   `ctx->r25 = 0` (cadena `a0+0xE8 → +0x2C`) ⇒ store a `0x8`. Es estado de juego, no símbolo:
   comparar `a0` y el objeto contra el emulador en el mismo punto (posible mid-entry con convención
   de registros, o divergencia previa del script de gameplay).
3. **Verificar píxeles/geometría**: RT64 procesa DLs (conteo), pero falta confirmar en pantalla
   (dump de frame) que ya hay gameplay y no solo boot/attract.

## 4. Herramientas/comandos nuevos

```sh
# Traza de saltos del emulador (para extras) y derivacion con fases
HH_JALTRACE=work/debug/emu_jal130.bin tools/analysis/emu_ref.sh ...   # (o r64dump directo)
python3 tools/analysis/gen_module_extras.py work/debug/emu_jal130.bin \
    --boot-trace work/debug/emu_jal60.bin

# Anadir mid-entries a partir de un log del port (iterativo)
python3 tools/analysis/add_missing_funcs.py --syms config/us_ghidra.syms.toml --log <run.log>

# Pipeline completo tras tocar MODULES/extras
python3 tools/setup_module.py && python3 tools/recomp.py --config config/game_combined.toml --build
```

## 5. Artefactos (gitignored, `work/debug/`)

`emu_jal60.bin`, `emu_jal70.bin`, `emu_jal130.bin` (traza de saltos del emulador);
`run_ovl{,2,3,4,5}.log`, `run_extras{,2}.log`, `run_soft{,2,3,4}.log`, `run_clean_ovl.log`,
`run_final200.log`, `run_crash25.log`; `setup6*.log`, `recomp6*.log`.
