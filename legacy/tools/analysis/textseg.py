#!/usr/bin/env python3
"""Locate text segments + code segments in Hybrid Heaven ROMs."""
import re, struct

def analyze(p):
    data = open(p,'rb').read()
    print(f"\n{'='*70}\n{p}  ({len(data)} bytes)")
    
    # 1. Find key English strings and their offsets
    keys = [
        b'WASHINGTON D.C.', b'PLEASE SELECT', b'HYBRID HEAVEN',
        b'TRAINING', b'MISSION', b'BATTLE', b'DIAZ', b'DIED',
        b'STATUS', b'WEAPON', b'MOVE', b'SAVE', b'GAME OVER',
        b'DEMO SELECT', b'attack selection',
    ]
    print("\n-- Key string offsets --")
    for k in keys:
        offs = [m.start() for m in re.finditer(re.escape(k), data)]
        if offs:
            # Print context around first occurrence
            o = offs[0]
            ctx = data[max(0,o-8):o+len(k)+8]
            ascii_ctx = ''.join(chr(c) if 32<=c<127 else '.' for c in ctx)
            print(f"  {k.decode(errors='replace')!r}: {len(offs)}x  first@0x{o:07X}  ctx=[{ascii_ctx}]")

    # 2. EU-only: language selector strings
    if 'PAL' in data[0x20:0x34].decode('ascii'):
        for k in [b'ENGLISH', b'FRENCH', b'GERMAN', b'ITALIAN', b'SPANISH']:
            offs = [m.start() for m in re.finditer(re.escape(k), data)]
            print(f"  EU lang {k.decode()}: {len(offs)}x first@0x{offs[0]:07X}" if offs else f"  EU lang {k.decode()}: none")

    # 3. Find dense printable-ASCII regions (text blocks) - scan 64KB windows
    print("\n-- Dense ASCII text regions (windows with >200 printable runs) --")
    ws = 0x10000  # 64KB
    window_text = {}
    for start in range(0, len(data)-ws, ws):
        chunk = data[start:start+ws]
        runs = re.findall(rb'[ -~]{6,}', chunk)
        n = len(runs)
        if n > 200:
            total = sum(len(r) for r in runs)
            window_text[start//ws] = (n, total, start)
    for w,(n,total,start) in sorted(window_text.items()):
        print(f"  0x{start:07X} (window {w:4d}): {n} runs, {total} printable bytes")

    # 4. Estimate code region: count of 0x0000xxxx-style MIPS instructions
    # MIPS NOP = 0x00000000; bnez/lui etc. Look at first 1MB
    print("\n-- First 64KB entropy probe (code vs data) --")
    import math
    for start in range(0x1000, 0x100000, 0x10000):
        chunk = data[start-0x1000:start]
        # count DWORD gaps - NOP density
        words = struct.unpack('>'+'I'*(len(chunk)//4), chunk[:len(chunk)//4*4])
        nops = sum(1 for w in words if w==0)
        zeros = sum(1 for w in words if w==0x3C1A00FF)  # lui k0,0xFFFF (code marker)
        print(f"  0x{start:07X}: nop-density {nops/len(words):.1%}")

if __name__ == '__main__':
    analyze('rom/baserom.us.z64')
    analyze('rom/baserom.eu.z64')