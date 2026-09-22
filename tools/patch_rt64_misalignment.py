#!/usr/bin/env python3
"""patch_rt64_misalignment.py - aplica el arreglo de RT64 issue #82 al submódulo lib/rt64.

RT64 issue #82 (abierta, etiqueta bug): la corrección de misalignment de rects y scissors
extendidos redondea SIEMPRE hacia abajo (`coord - (coord % resScale[1])`), pero con
`G_EX_ORIGIN_RIGHT` debería redondear hacia arriba. Consecuencia: un elemento anclado a la
derecha (p. ej. el fondo del mapa, `fill:0x00000000@197,143,277,223`) queda desfasado
~0.667 px de juego respecto a su contenido (triángulos), y ningún nudge de cuarto de píxel
lo cuadra.

Arregla `correctMisalignment` en `src/render/rt64_framebuffer_renderer.cpp` (las dos:
`convertFixedRect` y `convertViewportRect`): si el origen es `G_EX_ORIGIN_RIGHT`, redondea
hacia arriba.

Idempotente: si ya está aplicado (marcador), no hace nada. Si el código de RT64 no coincide
(p. ej. tras actualizar el submódulo), avisa y no toca nada (salida != 0).

Uso:
    python3 tools/patch_rt64_misalignment.py            # aplica
    python3 tools/patch_rt64_misalignment.py --check     # solo comprueba (0 = aplicado)
    python3 tools/patch_rt64_misalignment.py --revert    # revierte (deja RT64 como upstream)
"""

import argparse
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TARGET = REPO / "lib" / "rt64" / "src" / "render" / "rt64_framebuffer_renderer.cpp"

MARKER = "HH patch: rt64#82"

# Emparejamos solo la linea `return` (la indentacion de los bloques es 16/20 espacios).
OLD_FIXED = "                    return int32_t(coord - (coord % std::lround(resScale[1]))) - horizontalMisalignment;"

NEW_FIXED = (
    f"                    // {MARKER}: con origen a la derecha, redondear hacia ARRIBA (no hacia abajo).\n"
    "                    const int32_t align = std::lround(resScale[1]);\n"
    "                    const int32_t rem = coord % align;\n"
    "                    const int32_t aligned = (origin == G_EX_ORIGIN_RIGHT) ? (coord + ((align - rem) % align)) : (coord - rem);\n"
    "                    return aligned - horizontalMisalignment;"
)

OLD_VIEWPORT = "                return (coord - std::fmod(coord, resScale[1])) - horizontalMisalignment;"

NEW_VIEWPORT = (
    f"                // {MARKER}: con origen a la derecha, redondear hacia ARRIBA (no hacia abajo).\n"
    "                const float rem = std::fmod(coord, resScale[1]);\n"
    "                const float aligned = (origin == G_EX_ORIGIN_RIGHT) ? (coord + std::fmod(resScale[1] - rem, resScale[1])) : (coord - rem);\n"
    "                return aligned - horizontalMisalignment;"
)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true", help="solo comprueba si está aplicado")
    ap.add_argument("--revert", action="store_true", help="revierte el parche")
    args = ap.parse_args()

    if not TARGET.exists():
        print(f"ERROR: no existe {TARGET}. ¿Falta el submódulo lib/rt64?")
        print("       Traelo con: git submodule update --init --recursive")
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
        text = text.replace(NEW_FIXED, OLD_FIXED).replace(NEW_VIEWPORT, OLD_VIEWPORT)
        TARGET.write_text(text, encoding="utf-8")
        print(f"revertido: {TARGET}")
        return 0

    if patched:
        print("ya estaba aplicado; nada que hacer")
        return 0

    if OLD_FIXED not in text or OLD_VIEWPORT not in text:
        print("ERROR: el código de RT64 no coincide con el esperado (¿submódulo actualizado?).")
        print(f"       Revisa {TARGET} y actualiza este script.")
        return 1

    text = text.replace(OLD_FIXED, NEW_FIXED).replace(OLD_VIEWPORT, NEW_VIEWPORT)
    TARGET.write_text(text, encoding="utf-8")
    print(f"aplicado: {TARGET}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
