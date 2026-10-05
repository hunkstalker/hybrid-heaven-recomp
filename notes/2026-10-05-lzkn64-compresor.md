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

## Resultado

`tools/verify/verify_lzkn64_roundtrip.py` sobre los 482 ficheros comprimidos:

- **Round-trip semántico `decompress(compress(x)) == x`: 482/482.**
- **Byte-exacto vs retail: 477/482.**

Casos no byte-exactos (chunking exótico de runs de ceros; el original los parte de forma no obvia):

| idx | dec size |
|---|---|
| 0 | 4096 |
| 54 | 42464 |
| 21 | 73648 |
| 24 | 124112 |
| 7 | 564464 |

Se probó una hipótesis `primer chunk = 256-(pos%256)+33` (encajaba en 4 de ellos) pero **rompía otros**
(469/482) → descartada. **Pendiente**: clonar el troceado exacto para lograr SHA1 retail (si algún día
se necesita; el port no comprime).

## Herramienta

- `tools/lzkn64/lzkn64.py` — `decompress` (ya existía) + `compress` (nuevo).
- `tools/verify/verify_lzkn64_roundtrip.py` — validación contra la ROM.
