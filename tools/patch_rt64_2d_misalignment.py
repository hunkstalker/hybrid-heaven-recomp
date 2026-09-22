#!/usr/bin/env python3
"""patch_rt64_2d_misalignment.py - alinea los triangulos ortograficos 2D con los rects en RT64.

Problema (nuestro, NO el issue #82): en `rt64_framebuffer_renderer.cpp` la ruta de los rects
(fill/texrect) recibe `horizontalMisalignment` (una correccion de sub-pixel que alinea la 2D a la
rejilla nativa), pero la rama `Projection::Type::Orthographic` de los triangulos deja
`horizontalMisalignment = 0.0f`. Consecuencia: un panel cuyo fondo es un rect y cuyo contenido son
triangulos (p. ej. el mapa: fondo `fill:0x00000000@197,143,277,223` + contenido en listas `dl`)
queda desfasado ~0.67 px de juego, y ningun nudge de cuarto de pixel lo cuadra.

Arreglo: en el bucle por proyeccion, tras fijar `triangles.screenOffset.x`, restar el mismo
desplazamiento para las proyecciones ortograficas.

Idempotente (`--check` / `--revert`). Si el codigo de RT64 no coincide, avisa y no toca nada.

Uso:
    python3 tools/patch_rt64_2d_misalignment.py           # aplica
    python3 tools/patch_rt64_2d_misalignment.py --check    # 0 = aplicado
    python3 tools/patch_rt64_2d_misalignment.py --revert   # deja RT64 como upstream
"""

import argparse
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TARGET = REPO / "lib" / "rt64" / "src" / "render" / "rt64_framebuffer_renderer.cpp"

MARKER = "HH patch: 2D ortho misalignment"

OLD = (
    "                    if (viewportOrigin < G_EX_ORIGIN_NONE) {\n"
    "                        const float centerOffset = ((middleViewport * viewportOrigin) / G_EX_ORIGIN_CENTER) * extOriginPercentage + middleViewport * (1.0f - extOriginPercentage);\n"
    "                        triangles.screenOffset.x = halfPixelOffset.x + ((centerOffset - middleViewport) / halfViewportSize.x);\n"
    "                    }\n"
    "                }\n"
)

NEW = (
    "                    if (viewportOrigin < G_EX_ORIGIN_NONE) {\n"
    "                        const float centerOffset = ((middleViewport * viewportOrigin) / G_EX_ORIGIN_CENTER) * extOriginPercentage + middleViewport * (1.0f - extOriginPercentage);\n"
    "                        triangles.screenOffset.x = halfPixelOffset.x + ((centerOffset - middleViewport) / halfViewportSize.x);\n"
    "                    }\n"
    "\n"
    f"                    // {MARKER}: los rects (fill/texrect) reciben la correccion\n"
    "                    // horizontalMisalignment; los triangulos ortograficos 2D no. Sin esto, el\n"
    "                    // contenido de un panel (triangulos) queda desfasado respecto a su fondo (rect).\n"
    "                    // 2.0/wideWidth: el viewport cubre 2 unidades NDC, asi que 1 px = 2/wideWidth.\n"
    "                    if (proj.type == Projection::Type::Orthographic) {\n"
    "                        triangles.screenOffset.x -= p.horizontalMisalignment * 2.0f / wideWidth;\n"
    "                    }\n"
    "                }\n"
)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true", help="solo comprueba si esta aplicado")
    ap.add_argument("--revert", action="store_true", help="revierte el parche")
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

    text = text.replace(OLD, NEW)
    TARGET.write_text(text, encoding="utf-8")
    print(f"aplicado: {TARGET}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
