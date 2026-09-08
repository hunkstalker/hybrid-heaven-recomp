# usage: python3 tools/analysis/overlay_chunks.py <dump1> <dump2> ...
# Prints RAM regions (base/size) that appeared since dump1 (4KB page alignment),
# a heuristic for overlays loaded at runtime (chunks that stay static between dumps).
import glob, sys, os

dumps = sys.argv[1:] or sorted(glob.glob('work/scratch/hh3.t*.bin'))
if not dumps:
    print("no dumps given; pass files or use default glob names"); sys.exit(1)
imgs = {d: open(d, 'rb').read() for d in dumps}
PS = 0x1000

def pagediff(a, b):
    n = len(a) // PS
    runs, cur = [], None
    for p in range(n):
        diff = a[p*PS:(p+1)*PS] != b[p*PS:(p+1)*PS]
        if diff and cur is None: cur = [p, p]
        elif diff: cur[1] = p
        elif cur is not None: runs.append(cur); cur = None
    if cur: runs.append(cur)
    return [(lo*PS, (hi+1)*PS) for lo, hi in runs]

prv = imgs[dumps[0]]
for d in dumps[1:]:
    regs = pagediff(prv, imgs[d])
    big = [(s, e) for s, e in regs if e-s >= 0x1000]
    print(f"{os.path.basename(d)} vs prev:")
    for s, e in big:
        print(f"    RAM 0x{0x80000000+s:08X}  size 0x{e-s:X}")
    prv = imgs[d]