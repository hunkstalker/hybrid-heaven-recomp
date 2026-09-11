# Workflows operativos

> Procedimientos recurrentes. Documento vivo. Las decisiones van a `docs/adr/`; el detalle
> histórico, a `../notes/`.

## 0. Primer setup (reconstruir los artefactos del módulo desde la ROM)

El módulo de código idx 7 no está plano en la ROM (Konami lo comprime con **LZKN64**, tabla
Nisitenma-Ichigo). Se reconstruye **determinísticamente** desde la ROM del usuario:

```sh
python3 tools/setup_module.py --build
# ROM -> blob (lzkn64, CRC 0xA9213032) -> config/us_module7.syms.toml
#     -> work/scratch/us_combined.z64 -> config/us_combined.syms.toml
#     -> recompila el set combinado y construye (--build)
```

Sin `--build`, solo regenera los artefactos; luego `recomp.py --config config/game_combined.toml --build`.
Requisito: ROM US retail en `work/roms/us_retail.z64` (gitignored; la aporta el usuario).

## 1. Recompilar y construir (pipeline)

Un solo comando: valida syms → regenera (N64Recomp) → copia al port → `fix_fallthroughs` → build.

```sh
python3 tools/recomp.py                 # valida + regenera + copia + fixes
python3 tools/recomp.py --build         # + cmake build_dbg
python3 tools/recomp.py --fix-syms      # intenta corregir la syms si el validador falla
python3 tools/recomp.py --dry-run       # muestra los pasos sin ejecutar
```

Validador de símbolos (detecta **delay-slot cortado**, **ramas cruzadas** y **data-as-code**):

```sh
python3 tools/analysis/validate_syms.py config/us_ghidra.syms.toml
python3 tools/analysis/validate_syms.py config/us_ghidra.syms.toml --fix --out /tmp/fixed.syms.toml
```

Regla: **nunca editar a mano el C generado**. Todo fix va a `config/*.syms.toml` y el validador
lo propone (`--fix`). Windows (usuario): `cmake --build build --target HybridHeavenRecomp --config Debug`.

## 2. Ejecutar headless (Linux)

```sh
cd port/HybridHeavenRecomp/build_dbg
DISPLAY=:99 SDL_VIDEODRIVER=x11 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  timeout 60 "./Hybrid Heaven Recomp"
# Requiere Xvfb :99 (crear si falta) — ver note histórico de sesión.
```

## 3. Protocolo de imágenes (visión por lotes)

**Regla dura**: la plataforma limita a ~**4 imágenes por prompt**, y **cada imagen se queda en el
contexto**. Por eso NUNCA se adjunta un lote grande: se reduce a pocas y **se resume a texto**.

### Paso 1 — Triaje barato (sin visión)
```sh
python3 tools/analysis/triage_screenshots.py "work/gameplay screenshots" --recursive \
  --max 20 --batch 3 --out /tmp/opencode/triage
```
Genera:
- `triage.csv` — una fila por PNG: `ts, w, h, bytes, bright, hash, flag (selected/dup), dup_of, txt`.
- `triage.selection.txt` — rutas candidatas a visión.
- `triage.batches.txt` — selección troceada en lotes de `--batch`.

El script decodifica PNG (RGB/RGBA/paleta/gris, 8-bit) con `zlib`+`numpy`, sin ImageMagick.
Duplicados = dHash con distancia Hamming ≤ `--dup-threshold` (def. 6). Escena nueva = supera el
umbral (o cambio de brillo > `--bright-threshold`).

### Paso 2 — Visión en lotes pequeños
- Leer **2-3 imágenes por turno** (nunca >4), siguiendo `triage.batches.txt`.
- **Volcar cada imagen a texto inmediatamente** (una línea por archivo, p. ej. en la nota del día):
  qué se ve, HUD sí/no, menú/tipo de escena, texto legible.
- Ese texto es el artefacto duradero. **No re-adjuntar** la imagen en turnos posteriores.

### Paso 3 — Correlación PNG ↔ dumps
El tracker BizHawk nombra los PNG con wall-clock y escribe un `.txt` por captura; emparejar por
nombre base y por tiempo (`triage.csv` ya marca `txt=yes/no`). Así se ata overlay↔pantalla↔botones.

## 4. Cómo NO usar imágenes

- No adjuntar una carpeta entera ni "analiza estas 50 imágenes".
- No re-adjuntar lo ya resumido a texto.
- Para inspección masiva/de frames, preferir ASCII/estadísticas (barato) y reservar la visión a
  casos concretos.

## 5. Completar símbolos faltantes (evidencia runtime)

La detección estática es poco fiable (jump-tables). La fuente fiable son los `Failed to find
function`. Bucle determinista:

```sh
# 1) run con soft-lookup (loguea faltantes y sigue con stub)
cd port/HybridHeavenRecomp/build_dbg && HH_SOFT_LOOKUP=1 timeout 90 "./Hybrid Heaven Recomp" > /tmp/hh_soft.log 2>&1
# 2) añadir faltantes a la syms correspondiente (flat o módulo)
python3 tools/analysis/add_missing_funcs.py --syms config/us_ghidra.syms.toml --log /tmp/hh_soft.log
# 3) re-merge + recomp + build (ver §1) y repetir hasta 0 faltantes
```

- `tools/analysis/fix_function_bounds.py <syms> --rom <rom> --report-only`: asesor CFG (propone
  inicios; **no** auto-aplicar: sobre-parte).
- `HH_SOFT_LOOKUP=1` es solo para depurar símbolos (los stubs no-op falsean la lógica del juego).
