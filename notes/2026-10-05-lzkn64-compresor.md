# 2026-10-05 — LZKN64: compresor propio (Fase 4 de verificación)

> Rama `verificacion-byte-match`. Reimplementación **clean-room** del compresor LZKN64 (el
> descompresor ya existía). Objetivo: cerrar la ida y vuelta de la ROM (recomprimir == retail). No
> toca el port.

## Formato (reverso del descompresor + observación del stream real)

Cabecera: `u32 BE` = longitud total del stream comprimido (incluye la cabecera).

| cmd | token |
|---|---|
| `0x00-0x7F` | **backref**: `len = ((cmd>>2)&0x1F)+2` (2..33); `off = ((cmd&3)<<8)|sig` (0..1023) |
| `0x80-0x9F` | **copia literal**: `len = cmd&0x1F` (1..31) |
| `0xA0-0xDF` | **RLE de valor** (el original emite con base **`0xC0`**; bits 5-6 ignorados por el decompresor) |
| `0xE0-0xFE` | **RLE de ceros**: `len = (cmd&0x1F)+2` (2..32) |
| `0xFF` | **RLE de ceros largo**: `len = sig+2` (2..257) |

## Reglas de tokenizado (derivadas, medidas)

- Backref: **solo si el match ≥4**; se elige el **match más largo** (≤33) con desempate por **offset
  más pequeño**; **ventana máxima off ≤ 991** (el original nunca usa >991).
- Runs de ceros: RLE (≥2); `0xFF` si >32 (hasta 257).
- Runs de byte repetido: `rlev` (≥3, hasta 32); a partir de ahí, el propio offset=1 da backrefs `(33,1)`.
- Selección: en cada posición se emite **un token**: se toma el que **más consume** entre
  cero-repetición-backref; en empate gana RLE; si no, se acumula `raw` (≤31) parando ante RLE/backref.
- El decompresor **ignora bits del cmd**; el original los usa (`rlev` con base `0xC0`, no `0xA0`).
- **Quirk del original (clave)**: el run de ceros se corta en la próxima posición
  `(i+pos) & 0xFFF ∈ {0x21, 0x421, 0x821, 0xC21}`, es decir `pos ≡ 0x21 (mod 0x400)`. Esto explica
  el troceado "raro" de runs largos (`65 → 34+31`, `1024 → 257,257,207,257,46`, etc.).
- **Padding**: la cabecera = longitud **sin** el pad; si es impar se añade un byte `0x00`.

## Resultado

`tools/verify/verify_lzkn64_roundtrip.py` sobre los 482 ficheros comprimidos:

- **Round-trip semántico `decompress(compress(x)) == x`: 482/482.**
- **Byte-exacto vs retail: 482/482 (`rec == raw` completo, incluido el padding).**

El codec LZKN64 está clonado exactamente. (El `rommy.py compress` a nivel de ROM da otro tamaño/SHA1
porque **compacta el contenedor**; no es un test del codec. El test válido —y superado— es por fichero.)

## Herramienta

- `tools/lzkn64/lzkn64.py` — `decompress` (ya existía) + `compress` (nuevo, byte-exacto). El algoritmo
  original fue revertido por Fluvian / LiquidCat64 (`Fluvian/lzkn64`, referencias MIT).
- `tools/verify/verify_lzkn64_roundtrip.py` — validación contra la ROM.
