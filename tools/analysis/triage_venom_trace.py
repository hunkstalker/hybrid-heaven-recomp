#!/usr/bin/env python3
"""Triaje compacto de las trazas del bug #14 (veneno/CaC).

Lee una carpeta de trazas producida por `run_windows_trace.bat` (o el
`hh_trace_console.log` + los `hh_*.log` sueltos) y resume, en orden temporal,
lo relevante para localizar la divergencia: cargas del loader, registro de
modulos, la cadena M10/M55, la puerta M7, la publicacion del handler b280 y la
escritura del centinela del veneno.

Uso:
    python3 tools/analysis/triage_venom_trace.py <carpeta_o_fichero> [--around N]

No pretende ser exhaustivo: agrupa y prioriza para poder leer 10k+ lineas de
consola en una pantalla.
"""

from __future__ import annotations

import argparse
import os
import re
import sys

# Formatos (ver lib/N64ModernRuntime/librecomp/src/overlays.cpp).
RE_LD384 = re.compile(
    r"\[LD384\] a0=(?P<a0>[0-9A-Fa-f]+) a1=(?P<a1>[0-9A-Fa-f]+) a2=(?P<a2>[0-9A-Fa-f]+) "
    r"a3=(?P<a3>[0-9A-Fa-f]+)"
    r"(?: vi=(?P<vi>\d+) gframe=(?P<gframe>\d+) s=(?P<s>\d+) ra=(?P<ra>[0-9A-Fa-f]+))?"
)
RE_LD384_POST = re.compile(r"\[LD384\] post dst=(?P<dst>[0-9A-Fa-f]+) 0x801CC8C4=(?P<sel>[0-9A-Fa-f]+)")
RE_OVL = re.compile(
    r"\[OVL\] src=(?P<src>[0-9A-Fa-f]+) -> section\[(?P<sec>\d+)\] rom=(?P<rom>[0-9A-Fa-f]+) at (?P<at>[0-9A-Fa-f]+)"
)
RE_SETCB = re.compile(r"\[SETCB\] obj=(?P<obj>[0-9A-Fa-f]+) cb=(?P<cb>[0-9A-Fa-f]+)")
RE_GATE_A = re.compile(
    r"\[GATE_A\] #(?P<hit>\d+)/(?P<total>\d+) a0=(?P<a0>[0-9A-Fa-f]+) a1=(?P<a1>[0-9A-Fa-f]+) "
    r"a2=(?P<a2>[0-9A-Fa-f]+) ret=(?P<ret>\d+) 42D0=(?P<p42d0>[0-9A-Fa-f]+) 181=(?P<p181>[0-9A-Fa-f]+) "
    r"188=(?P<p188>[0-9A-Fa-f]+) mode7DD92=(?P<flag>[0-9A-Fa-f]+)"
)
RE_B280CALL = re.compile(
    r"\[B280CALL\] n=(?P<n>\d+) vi=(?P<vi>\d+) tid=(?P<tid>-?\d+) depth=(?P<depth>-?\d+) "
    r"obj=(?P<obj>[0-9A-Fa-f]+) a1=(?P<a1>[0-9A-Fa-f]+) sp=(?P<sp>[0-9A-Fa-f]+) ra=(?P<ra>[0-9A-Fa-f]+) "
    r"objcount=(?P<cnt>\d+)"
)
RE_VENOM = re.compile(r"=== VENOM #(?P<n>\d+) \[(?P<tag>[^\]]+)\] obj=(?P<obj>[0-9A-Fa-f]+) cb=(?P<cb>[0-9A-Fa-f]+)")
RE_CHAIN = re.compile(
    r"\[CHAIN\] vi=(?P<vi>\d+) sample=(?P<sample>\d+) (?P<what>\S+)\s+a0=(?P<a0>[0-9A-Fa-f]+) "
    r"a1=(?P<a1>[0-9A-Fa-f]+) extra=(?P<extra>[0-9A-Fa-f]+)"
)
RE_DISP = re.compile(r"\[DISP\] head=(?P<head>[0-9A-Fa-f]+)")
RE_TAGS = ("[HANG]", "[BADMQ]", "[LOOKUP]", "[NO_B280]", "[NO_DISABLE]", "[CRASH]", "failed to find")


def hexv(s: str) -> int:
    return int(s, 16)


def load_files(target: str):
    """Devuelve {nombre: lineas} de las trazas relevantes."""
    names = [
        "hh_trace_console.log",
        "hh_b280call.log",
        "hh_b280set.log",
        "hh_venom.log",
        "hh_scheddisp.log",
        "hh_spchk.log",
        "hh_chain.log",
        "hh_crash.log",
        "hh_hang.log",
        "hh_state.log",
    ]
    out = {}
    if os.path.isdir(target):
        for n in names:
            p = os.path.join(target, n)
            if os.path.isfile(p):
                with open(p, "r", encoding="utf-8", errors="replace") as f:
                    out[n] = f.read().splitlines()
        # tambien cualquier log suelto que hayan dejado
        for n in sorted(os.listdir(target)):
            if n.startswith("hh_") and n.endswith(".log") and n not in out:
                with open(os.path.join(target, n), "r", encoding="utf-8", errors="replace") as f:
                    out[n] = f.read().splitlines()
    else:
        with open(target, "r", encoding="utf-8", errors="replace") as f:
            out[os.path.basename(target)] = f.read().splitlines()
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("trace", help="carpeta (junto al .exe) o fichero hh_trace_console.log")
    ap.add_argument("--around", type=int, default=40, help="cargas del loader a mostrar antes del veneno (def. 40)")
    args = ap.parse_args()

    if not os.path.exists(args.trace):
        print(f"ERROR: no existe {args.trace}", file=sys.stderr)
        return 2

    files = load_files(args.trace)
    if not files:
        print(f"ERROR: no encontre hh_*.log en {args.trace}", file=sys.stderr)
        return 2

    if "hh_trace_console.log" in files:
        console = files["hh_trace_console.log"]
    else:
        # fichero suelto (p. ej. un console.log de otra sesion): usa el mas grande.
        console = max(files.values(), key=len) if files else []
    for n, lines in sorted(files.items()):
        print(f"  {n:28s} {len(lines):>8d} lineas")
    print()

    loads = []       # (vi, a0, a1, a2, gframe, s)
    ovls = []        # (src, sec, rom, at)
    setcb = []       # (obj, cb)
    gates = []       # gate_a hits a1==0x39
    b280 = []        # b280call dicts
    venom = []       # venom dicts
    chain = []       # chain events
    disp = 0
    tags = []

    for line in console:
        m = RE_LD384.search(line)
        if m:
            loads.append((int(m["vi"]) if m["vi"] else -1, hexv(m["a0"]), hexv(m["a1"]), hexv(m["a2"]),
                          int(m["gframe"]) if m["gframe"] else -1, int(m["s"]) if m["s"] else -1))
            continue
        m = RE_OVL.search(line)
        if m:
            ovls.append((hexv(m["src"]), int(m["sec"]), hexv(m["rom"]), hexv(m["at"])))
            continue
        m = RE_SETCB.search(line)
        if m:
            setcb.append((hexv(m["obj"]), hexv(m["cb"])))
            continue
        m = RE_GATE_A.search(line)
        if m and hexv(m["a1"]) == 0x39:
            gates.append(m.groupdict())
            continue
        m = RE_CHAIN.search(line)
        if m:
            chain.append((int(m["vi"]), m["what"], hexv(m["a0"]), hexv(m["a1"]), hexv(m["extra"])))
            continue
        if RE_DISP.search(line):
            disp += 1
            continue
        for t in RE_TAGS:
            if t in line:
                tags.append(line.strip())
                break

    for line in files.get("hh_b280call.log", []):
        m = RE_B280CALL.search(line)
        if m:
            b280.append(m.groupdict())
    for line in files.get("hh_venom.log", []):
        m = RE_VENOM.search(line)
        if m:
            venom.append(m.groupdict())
    for line in files.get("hh_chain.log", []):
        m = RE_CHAIN.search(line)
        if m:
            chain.append((int(m["vi"]), m["what"], hexv(m["a0"]), hexv(m["a1"]), hexv(m["extra"])))

    print("=== Resumen ===")
    print(f"  cargas loader [LD384] : {len(loads)}")
    print(f"  registros [OVL]       : {len(ovls)}")
    print(f"  [SETCB] (setter cb)   : {len(setcb)}")
    print(f"  [GATE_A] a1=0x39      : {len(gates)}")
    print(f"  [B280CALL]            : {len(b280)}")
    print(f"  [CHAIN]               : {len(chain)}")
    print(f"  [DISP] disparos       : {disp}")
    print(f"  [VENOM] centinelas    : {len(venom)}")
    print(f"  avisos (HANG/BADMQ..) : {len(tags)}")
    print()

    if ovls:
        print("=== Modulos registrados [OVL] (src -> at) ===")
        for src, sec, rom, at in ovls:
            print(f"  src=0x{src:06X} seccion[{sec}] rom=0x{rom:08X} -> 0x{at:08X}")
        print()

    if venom:
        first = venom[0]
        print(f"=== Primer [VENOM] ===\n  obj={first['obj']} cb={first['cb']} tag={first['tag']}")
        print()
    else:
        print("=== sin [VENOM]: el centinela 0xFFFF84CD no se escribio en esta captura ===\n")

    # Timeline de la cadena M10/M55 (primeras 60 entradas).
    if chain:
        print("=== Cadena M10/M55 [CHAIN] (primeras 60) ===")
        for vi, what, a0, a1, extra in chain[:60]:
            print(f"  vi={vi:<8d} {what:<10s} a0=0x{a0:08X} a1=0x{a1:08X} extra=0x{extra:08X}")
        print()

    if b280:
        print("=== [B280CALL] (primeras 30) ===")
        for e in b280[:30]:
            print(f"  n={e['n']:<6s} vi={e['vi']:<8s} depth={e['depth']:<3s} obj=0x{e['obj']} a1=0x{e['a1']} count={e['cnt']}")
        print()

    if gates:
        print("=== [GATE_A] a1=0x39 (instalacion del disable; primeras 20) ===")
        for e in gates[:20]:
            print(f"  #{e['hit']}/{e['total']} a0=0x{e['a0']} ret={e['ret']} 42D0=0x{e['p42d0']} "
                  f"181={e['p181']} 188=0x{e['p188']} mode7DD92={e['flag']}")
        print()

    # Cargas alrededor del primer veneno/crash: usa el vi del veneno si existe; si no, las ultimas.
    if loads:
        pivot = len(loads)
        if venom:
            # no tenemos vi en hh_venom.log; usa las ultimas N cargas como contexto del crash.
            pivot = len(loads)
        start = max(0, pivot - args.around)
        print(f"=== Ultimas {min(args.around, len(loads))} cargas del loader antes del final ===")
        for i, (vi, a0, a1, a2, gframe, s) in enumerate(loads[start:], start=start + 1):
            print(f"  #{i:<3d} vi={vi:<8d} gframe={gframe:<8d} a0=0x{a0:08X} a1=0x{a1:08X} a2=0x{a2:08X}")
        print()

    if setcb:
        print("=== [SETCB] (primeros 20) ===")
        for obj, cb in setcb[:20]:
            print(f"  obj=0x{obj:08X} cb=0x{cb:08X}")
        print()

    if tags:
        print("=== Avisos destacados ===")
        for t in tags[:40]:
            print("  " + t)
        print()

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
