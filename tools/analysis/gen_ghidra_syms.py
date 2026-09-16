import os, re

# Raiz del repo derivada de la ubicacion del propio script (tools/analysis/ -> raiz).
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

ghidra = {}
with open(os.path.join(ROOT, 'work/ghidra_funcs.txt')) as f:
    for line in f:
        m = re.match(r'\s*\{\s*name\s*=\s*"([^"]+)",\s*vram\s*=\s*0x([0-9A-Fa-f]+),\s*size\s*=\s*0x([0-9A-Fa-f]+)\s*\},?', line)
        if m:
            name, vram, size = m.group(1), int(m.group(2), 16), int(m.group(3), 16)
            ghidra[vram] = (name, size)

n64sym = {}
with open(os.path.join(ROOT, 'notes/reference/n64sym_osfuncs_us_retail.txt')) as f:
    for line in f:
        p = line.strip().split()
        if len(p) == 2 and p[0].startswith('8'):
            n64sym[int(p[0], 16)] = p[1]

out = []
# Build ONLY from Ghidra functions within the .text section range (flat main code).
for vram in sorted(ghidra.keys()):
    if vram < 0x80000400 or vram >= 0x804E5F40:
        continue
    gname, size = ghidra[vram]
    name = n64sym.get(vram, gname)
    if size <= 0:
        size = 0x10
    out.append('    { name = "%s", vram = 0x%X, size = 0x%X },' % (name, vram, size))

with open(os.path.join(ROOT, 'config/us_ghidra.syms.toml'), 'w') as f:
    f.write("# Full function syms from Ghidra (function boundaries) + n64sym (os func names).\n")
    f.write("# Single .text section spanning the boot and flat main code.\n")
    f.write("# vram 0x80000400..0x804E5F40 <-> rom 0x1000..\n")
    f.write("\n[[section]]\n")
    f.write('name = ".text"\n')
    f.write("rom = 0x00001000\n")
    f.write("vram = 0x80000400\n")
    f.write("size = 0x4E5B40\n")
    f.write("\nfunctions = [\n")
    for line in out:
        f.write(line + "\n")
    f.write("]\n")

print("total funcs:", len(out))
print("os funcs named:", sum(1 for v in ghidra if v in n64sym))
