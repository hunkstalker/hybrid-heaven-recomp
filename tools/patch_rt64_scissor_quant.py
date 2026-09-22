#!/usr/bin/env python3
"""patch_rt64_scissor_quant.py - cuantiza el scissor de rects igual que el de triangulos.

RT64 convierte el mismo rectangulo de scissor a pixeles con DOS funciones distintas segun lo
que recorta:

  - Rects (`DrawExtendedType::None` / fill): `convertFixedRect` (linea ~68)
        coord - (coord % resScale)      -> truncado
  - Triangulos 2D (proyeccion Orthographic): `convertViewportRect` (linea ~100)
        coord - fmod(coord, resScale)   -> flotante

Con resoluciones no enteras (framebuffer 320x240, `resScale` como 6.0x/6.0x) el truncado y el
fmod pueden dar 1 px de diferencia para el MISMO scissor. Consecuencia: el fondo del mapa (rect
negro) y el mapa verde + la flecha roja (triangulos) se recortan en lineas distintas aunque
compartan el scissor recortado. El `horizontalMisalignment` (rt64#82) es aparte.

Arreglo: en la rama de triangulos, para `DataFormat` del scissor, usar la MISMA cuantizacion que
el viewport del propio triangulo. No cambia ninguna posicion; solo que ambos caminos redondeen
igual.

Idempotente (marcador). Si el codigo de RT64 no coincide, avisa y sale != 0 sin tocar nada.

Uso:
    python3 tools/patch_rt64_scissor_quant.py            # aplica
    python3 tools/patch_rt64_scissor_quant.py --check     # 0 = aplicado
    python3 tools/patch_rt64_scissor_quant.py --revert    # revierte
"""

import argparse
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TARGET = REPO / "lib" / "rt64" / "src" / "render" / "rt64_framebuffer_renderer.cpp"

MARKER = "HH patch: scissor quant"

OLD = (
    "                        triangles.scissor = convertFixedRect(call.callDesc.scissorRect, p.resolutionScale, p.fbWidth, invRatioScale, extOriginPercentage, int32_t(horizontalMisalignment), call.callDesc.scissorLeftOrigin, call.callDesc.scissorRightOrigin);"
)

NEW = (
    "                        triangles.scissor = convertFixedRect(call.callDesc.scissorRect, p.resolutionScale, p.fbWidth, invRatioScale, extOriginPercentage, int32_t(horizontalMisalignment), call.callDesc.scissorLeftOrigin, call.callDesc.scissorRightOrigin);\n"
    f"                        // {MARKER}: el scissor de los triangulos 2D debe cuantizarse igual que su\n"
    "                        // viewport (si no, un rect y los triangulos bajo el MISMO scissor se recortan\n"
    "                        // en lineas distintas por el truncado vs fmod).\n"
    "                        if ((proj.type == Projection::Type::Orthographic) && (call.callDesc.scissorLeftOrigin >= G_EX_ORIGIN_NONE) && (call.callDesc.scissorRightOrigin >= G_EX_ORIGIN_NONE)) {\n"
    "                            triangles.scissor = convertFixedRect(call.callDesc.scissorRect, p.resolutionScale, p.fbWidth, invRatioScale, extOriginPercentage, int32_t(horizontalMisalignment), call.callDesc.scissorLeftOrigin, call.callDesc.scissorRightOrigin);\n"
    "                        }"
)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--revert", action="store_true")
    args = ap.parse_args()

    if not TARGET.exists():
        print(f"ERROR: no existe {TARGET}. ¿Falta el submódulo lib/rt64?")
        return 1

    text = TARGET.read_text(encoding="utf-8")
    patched = MARKER in text

    if args.check:
        print("aplicado" if patched else "NO aplicado")
        return 0 if patched else 1

    if args.revert:
        if not patched:
            print("no estaba aplicado; nada que revertir")
            return 0
        text = text.replace(NEW, OLD)
        TARGET.write_text(text, encoding="utf-8")
        print(f"revertido: {TARGET}")
        return 0

    if patched:
        print("ya estaba aplicado; nada que hacer")
        return 0

    if OLD not in text:
        print("ERROR: el código de RT64 no coincide con el esperado (¿submódulo actualizado?).")
        print(f"       Revisa {TARGET} y actualiza este script.")
        return 1

    text = text.replace(OLD, NEW, 1)
    TARGET.write_text(text, encoding="utf-8")
    print(f"aplicado: {TARGET}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
