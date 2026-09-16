#!/usr/bin/env python3
"""
fix_fallthroughs.py — repair N64Recomp split-function fallthroughs.
Adapted for Hybrid Heaven. Chains split functions so the first half calls its
continuation (mimics hardware fallthrough), fixing uninitialized-global crashes.
Idempotent — re-run after every regeneration.
"""
import re, glob, os, sys, bisect

RECOMP_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                          "..", "..", "port", "HybridHeavenRecomp", "RecompiledFuncs")
RECOMP_DIR = os.path.normpath(RECOMP_DIR)
VRAM_BASE = 0x80000400
MARKER = "@fallthrough-fix"
PROLOGUE = ("uint64_t hi = 0, lo = 0, result = 0;", "int c1cs = 0;")

def load_ignored():
    ign = set()
    cfg = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "config", "game_unified.toml")
    with open(cfg) as f:
        in_ign = False
        for l in f:
            if "ignored" in l and "[" in l:
                in_ign = True; continue
            if in_ign and "]" in l:
                in_ign = False; continue
            if in_ign:
                m = re.search(r'"\s*(\w+)\s*"', l)
                if m: ign.add(m.group(1))
    return ign

def build_addr_map():
    """[(vram, nombre)] de todas las funciones generadas, SIN deduplicar por dirección.

    Importante: los módulos pueden compartir base de VRAM (23/24 en 0x801BF1A0), así que un
    mapa `addr -> nombre` pierde una de las dos y encadena fallthroughs a la sección equivocada.
    La dirección se toma del sufijo de 8 hex del nombre (absoluta); el `.inl` no sirve para
    módulos porque sus offsets son relativos a la sección."""
    pairs = []
    func_re = re.compile(r'^RECOMP_FUNC\s+void\s+(\w+)\s*\(')
    for fp in glob.glob(os.path.join(RECOMP_DIR, "funcs_*.c")):
        for ln in open(fp, encoding="utf-8", errors="replace"):
            m = func_re.match(ln)
            if not m:
                continue
            a = func_addr(m.group(1))
            if a is not None and 0x80000000 <= a < 0x80800000:
                pairs.append((a, m.group(1)))
    return pairs
def func_addr(name):
    hm = re.search(r'([0-9A-Fa-f]{8})$', name)
    return int(hm.group(1), 16) if hm else None


def section_prefix(name):
    """Prefijo de sección del símbolo (`M23_` para módulos; '' para la imagen plana).

    Varios módulos comparten base de VRAM: la continuación de un fallthrough debe resolverse
    DENTRO de la misma sección, no por dirección global (que mezcla módulos)."""
    m = re.match(r'(M\d+_)', name)
    return m.group(1) if m else ''


def main():
    dry = "--dry-run" in sys.argv
    stubs = load_ignored()
    pairs = build_addr_map()
    func_re = re.compile(r'^RECOMP_FUNC\s+void\s+(\w+)\s*\(')

    # Mapa de continuaciones por sección (prefijo).
    by_prefix = {}
    for a, name in pairs:
        by_prefix.setdefault(section_prefix(name), []).append((a, name))
    for v in by_prefix.values():
        v.sort()
    prefix_addrs = {k: [a for a, _ in v] for k, v in by_prefix.items()}

    fixed = 0; skipped_noaddr = 0; total_ft = 0
    for fp in sorted(glob.glob(os.path.join(RECOMP_DIR, "funcs_*.c"))):
        lines = open(fp, encoding="utf-8", errors="replace").read().split("\n")
        out = []; i = 0; n = len(lines)
        cur = None; body_start = None; changed = False
        while i < n:
            ln = lines[i]
            m = func_re.match(ln)
            if m:
                cur = m.group(1); body_start = len(out)
                out.append(ln); i += 1; continue
            if cur is not None and ln.strip() == ";}":
                body = out[body_start+1:]
                code = [l.strip() for l in body if l.strip() and not l.strip().startswith("//")]
                real = [l for l in code if l not in PROLOGUE]
                is_ft = False
                if real and cur not in stubs and MARKER not in "\n".join(body):
                    # La decision debe mirar solo la ULTIMA sentencia real: una funcion puede
                    # tener ramas con `return` (p. ej. LOOKUP + return) y aun asi caer al final
                    # hacia la funcion contigua (caso M55_FUN_80379690 -> 0x803796E4: fuga 0x48).
                    stmts = list(real)
                    while stmts and stmts[-1] in ("}", "{"):
                        stmts.pop()
                    last = stmts[-1] if stmts else ""
                    term_goto = last.startswith("goto ")
                    term_ret = last == "return;"
                    tail_call = bool(re.match(r'\w+\(rdram, ctx\);$', last))
                    # Direccion de la ultima instruccion emitida (ultimo comentario // 0xADDR:)
                    last_addr = None
                    last_mnem = ""
                    for l in reversed(body):
                        am = re.match(r'\s*// 0x([0-9A-Fa-f]{8}):\s*(\S+)', l)
                        if am:
                            last_addr = int(am.group(1), 16)
                            last_mnem = am.group(2)
                            break
                    # Rama condicional como ultima instruccion: su fall-through sigue en la
                    # instruccion contigua (p.ej. M55_FUN_8037a6f4 -> 0x8037A884, fuga 0x38/frame
                    # en el estado de caida). En ese caso el `return;`/`goto` final es condicional
                    # (dentro del if) y NO garantiza terminacion.
                    cond_branch = last_mnem in (
                        "beq", "bne", "beql", "bnel", "beqz", "bnez",
                        "bgtz", "bgez", "bltz", "blez", "bgtzl", "bgezl", "bltzl", "blezl",
                        "bgezal", "bltzal")
                    is_ft = bool(stmts) and (
                        (not term_ret and not term_goto and not tail_call) or cond_branch)
                if is_ft:
                    total_ft += 1
                    a = func_addr(cur)
                    cont = None
                    if a is not None:
                        pref = section_prefix(cur)
                        lst = by_prefix.get(pref, [])
                        j = bisect.bisect_right(prefix_addrs.get(pref, []), a)
                        if j < len(lst):
                            cont = lst[j][1]
                    if cont and cont != cur and last_addr is not None and func_addr(cont) == last_addr + 4:
                        out.append("    // %s: split fallthrough -> chain to continuation" % MARKER)
                        out.append("    %s(rdram, ctx);" % cont)
                        fixed += 1; changed = True
                    else:
                        skipped_noaddr += 1
                out.append(ln); cur = None; body_start = None; i += 1; continue
            out.append(ln); i += 1
        if changed and not dry:
            open(fp, "w", encoding="utf-8").write("\n".join(out))

    print("fallthrough functions found:         %d" % total_ft)
    print("chained to continuation:             %d" % fixed)
    print("skipped (no resolvable continuation):%d" % skipped_noaddr)
    if dry:
        print("(dry run — no files written)")

if __name__ == "__main__":
    main()
