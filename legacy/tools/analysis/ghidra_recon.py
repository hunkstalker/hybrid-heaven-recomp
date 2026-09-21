from ghidra.program.model.address import AddressSet

import re

program = getCurrentProgram()
listing = program.getListing()
refMgr = program.getReferenceManager()
funcMgr = program.getFunctionManager()

patterns = {
    'seginfo': re.compile(r'seginfo', re.I),
    'romNo': re.compile(r'romNo\['),
    'nisitenma': re.compile(r'Nisitenma', re.I),
    'func_map': re.compile(r'func_map|function_map', re.I),
    'trans': re.compile(r'trans', re.I),
    'ucode': re.compile(r'ucode|asp|aaudio|audio', re.I),
    'seg': re.compile(r'\bseg\b|\bseg ')
}

found = {}
count = 0
for d in listing.getDefinedData(True):
    if not d.hasStringValue():
        continue
    val = d.getValue()
    for name, rgx in patterns.items():
        if rgx.search(str(val)):
            found.setdefault(name, []).append((d.getAddress(), str(val)))
            break
    count += 1

print('strings checked: %d' % count)
for name, items in found.items():
    print('### %s (%d)' % (name, len(items)))
    for addr, s in items[:60]:
        rfuns = set()
        for r in refMgr.getReferencesTo(addr):
            f = funcMgr.getFunctionContaining(r.getFromAddress())
            if f is not None:
                rfuns.add('%s@%s' % (f.getName(), f.getEntryPoint()))
        print('  %s %r  funcs=%s' % (addr, s[:90], sorted(rfuns)[:4]))