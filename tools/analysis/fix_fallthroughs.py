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
    addr2name = {}
    inl = os.path.join(RECOMP_DIR, "recomp_overlays.inl")
    if os.path.exists(inl):
        txt = open(inl, encoding="utf-8", errors="replace").read()
        for m in re.finditer(r'\.func = (\w+),\s*\.offset = (0x[0-9A-Fa-f]+)', txt):
            addr2name[VRAM_BASE + int(m.group(2), 16)] = m.group(1)
    func_re = re.compile(r'^RECOMP_FUNC\s+void\s+(\w+)\s*\(')
    for fp in glob.glob(os.path.join(RECOMP_DIR, "funcs_*.c")):
        for ln in open(fp, encoding="utf-8", errors="replace"):
            m = func_re.match(ln)
            if not m: continue
            name = m.group(1)
            hm = re.search(r'([0-9A-Fa-f]{8})$', name)
            if hm:
                a = int(hm.group(1), 16)
                if 0x80000000 <= a < 0x80800000:
                    addr2name.setdefault(a, name)
    return addr2name
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
    addr2name = build_addr_map()
    func_re = re.compile(r'^RECOMP_FUNC\s+void\s+(\w+)\s*\(')

    # Mapa de continuaciones por sección (prefijo).
    by_prefix = {}
    for a, name in addr2name.items():
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
                    last = real[-1]
                    has_ret = any("return;" in l for l in real)
                    term_goto = last.startswith("goto ")
                    tail_call = bool(re.match(r'\w+\(rdram, ctx\);$', last))
                    is_ft = not has_ret and not term_goto and not tail_call
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
                    if cont and cont != cur:
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
