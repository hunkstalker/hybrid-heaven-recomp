import re, subprocess
from capstone import Cs, CS_ARCH_MIPS, CS_MODE_MIPS32, CS_MODE_BIG_ENDIAN

rom = 'work/roms/us_retail.z64'
data = open(rom, 'rb').read()
md = Cs(CS_ARCH_MIPS, CS_MODE_MIPS32 | CS_MODE_BIG_ENDIAN)
md.skipdata = True

# parse syms
syms_path = 'config/us_ghidra.syms.toml'
funcs = {}
order = []
with open(syms_path) as f:
    txt = f.read()
# extract functions array
m = re.search(r'functions\s*=\s*\[(.*?)\]', txt, re.S)
body = m.group(1)
for line in body.split('\n'):
    mm = re.match(r'\s*\{\s*name\s*=\s*"([^"]+)",\s*vram\s*=\s*0x([0-9A-Fa-f]+),\s*size\s*=\s*0x([0-9A-Fa-f]+)\s*\},?', line)
    if mm:
        name, vram, size = mm.group(1), int(mm.group(2), 16), int(mm.group(3), 16)
        funcs[vram] = (name, size)
        order.append(vram)
order.sort()
# map vram -> next function vram
next_vram = {}
for i, v in enumerate(order):
    next_vram[v] = order[i+1] if i+1 < len(order) else 0x804E5F40

def rom_off(vram):
    return vram - 0x7FFFF400

def find_func_end(vram, upper):
    off = rom_off(vram)
    # disassemble up to (upper - vram) bytes
    maxbytes = (upper - vram)
    if maxbytes <= 0: return None
    end = vram
    for ins in md.disasm(data[off:off+maxbytes], vram):
        if ins.mnemonic == 'jr' and 'ra' in ins.op_str:
            end = ins.address + 4
    return end

fixed = 0
for vram in order:
    name, size = funcs[vram]
    upper = next_vram[vram]
    # Make the function contiguous: extend to the next function's vram. This fixes
    # truncated functions (cut mid-branch) without relying on jr-ra heuristics.
    real_size = upper - vram
    if real_size > size:
        funcs[vram] = (name, real_size)
        fixed += 1

# rewrite
out = []
for vram in order:
    name, size = funcs[vram]
    out.append('    { name = "%s", vram = 0x%X, size = 0x%X },' % (name, vram, size))
with open(syms_path, 'w') as f:
    f.write(txt[:m.start(1)])  # header before functions = [
    for line in out:
        f.write(line + "\n")
    f.write(txt[m.end(1):])  # trailing ] etc

print("fixed sizes:", fixed, "/", len(order))
