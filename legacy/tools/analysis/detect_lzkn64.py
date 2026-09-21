#!/usr/bin/env python3
"""Detect Konami 'lzkn64' file tables in Hybrid Heaven ROM.

Konami N64 games store a file table where each entry is 8 bytes BE:
  entry[0] = rom_offset | (0x80000000 if compressed else 0)
  entry[1] = end_offset | 0x80000000 (size marker, high bit set)
Terminated by a zero entry (both 0).
"""
import struct, sys

def scan(path, window=(0x0, 0x100000)):
    data = open(path,'rb').read()
    lo, hi = window
    hits = []
    for base in range(lo, hi-8, 4):
        off = base
        # first entry of a run
        e0, e1 = struct.unpack_from('>II', data, off)
        if e0 == 0 and e1 == 0:
            continue
        # heuristic: flag compressed bit on both? Typically bit31 set on offset and on size
        # We look for multiple consecutive valid entries
        count = 0
        p = off
        total_entries = 0
        # count consecutive entries with bit31 pattern and sensible sizes
        while p+8 <= hi:
            a, b = struct.unpack_from('>II', data, p)
            if a == 0 and b == 0:
                count += 1
                break
            if (a & 0x80000000) and (b & 0x80000000):
                foff = a & 0x7FFFFFFF
                fend = b & 0x7FFFFFFF
                if fend >= foff and fend < len(data):
                    total_entries += 1
                    p += 8
                    continue
            # not matching, maybe the size word is plain end offset
            if (a & 0x80000000):
                foff = a & 0x7FFFFFFF
                fend = b & 0x7FFFFFFF
                if fend >= foff and fend < len(data) and (b >> 30) == 2:
                    total_entries += 1
                    p += 8
                    continue
            break
        if total_entries >= 6 and count >= 1:
            hits.append((off, total_entries))
    print(f"\n{path}: {len(hits)} candidate file tables")
    for off, n in hits[:30]:
        print(f"  table @ 0x{off:07X}  ({n} entries)  first8: {data[off:off+8].hex()}")

for p in ['rom/baserom.us.z64','rom/baserom.eu.z64']:
    scan(p)

# Also: find any single entry with bit31 set that is plausible as a table start
print("\n-- First entries of scan in US at fixed offsets --")
data = open('rom/baserom.us.z64','rb').read()
for base in [0x1000, 0x1050, 0x2000, 0x3000, 0x4000, 0x5000, 0x10000]:
    print(f"  @0x{base:06X}: {' '.join('%08X'%v for v in struct.unpack_from('>8I', data, base))}")