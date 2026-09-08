#!/usr/bin/env python3
"""Scan Hybrid Heaven ROM for Konami lzkn64 file tables using exact Goemon structure.

Table structure (port of goemon64::lzkn64_decompress_rom):
  entry[i][0] = (compressed<<31) | input_rom_offset
  entry[i][1] = input_rom_end_offset (high bit typically set too)
  loop starts at table; first entry[0] also gives initial output base.
  terminates when entry[0]==0 and entry[1]==0.
"""
import struct

def lzkn64_decompress(blob):
    if len(blob) < 5:
        return None
    size = struct.unpack_from('>I', blob, 0)[0]
    if size < 4 or size > len(blob):
        return None
    out = bytearray()
    pos = 4
    while pos < size:
        cmd = blob[pos]; pos += 1
        if cmd <= 0x7F:
            length = ((cmd & 0x7C) >> 2) + 2
            off = (((cmd & 0x03) << 8) | blob[pos]) & 0x3FF
            pos += 1
            base = len(out) - off
            if base < 0:
                return None
            for i in range(length):
                out.append(out[base + i])
        elif cmd <= 0x9F:
            length = cmd & 0x1F
            if pos + length > size:
                return None
            out += blob[pos:pos+length]
            pos += length
        elif cmd <= 0xDF:
            length = (cmd & 0x1F) + 2
            if pos >= size:
                return None
            v = blob[pos]; pos += 1
            out += bytes([v])*length
        elif cmd <= 0xFE:
            length = (cmd & 0x1F) + 2
            out += b'\x00'*length
        else:
            if pos >= size:
                return None
            length = blob[pos] + 2; pos += 1
            out += b'\x00'*length
    return bytes(out)

def scan(path):
    data = open(path,'rb').read()
    n = len(data)
    results = []
    # walk 4-byte aligned over the whole ROM (table could be anywhere)
    o = 0
    while o + 8 <= n:
        a, b = struct.unpack_from('>II', data, o)
        # invalid start
        if a == 0 and b == 0:
            o += 8
            continue
        # first entry: high bit on a typically
        if not (a & 0x80000000):
            o += 4
            continue
        # iterate entries
        q = o
        entries = []
        ok = True
        prev = None
        for _ in range(400):
            x, y = struct.unpack_from('>II', data, q)
            if x == 0 and y == 0:
                break
            xo = x & 0x7FFFFFFF
            xc = (x >> 31) & 1
            ye = y & 0x7FFFFFFF if y & 0x80000000 else None
            if ye is None:
                # maybe end offset is plain
                ye = y
            if ye < xo or ye >= n:
                ok = False
                break
            entries.append((xo, xc, ye))
            q += 8
            prev = ye
            if q + 8 > n:
                ok = False
                break
        num = len(entries)
        if ok and num >= 5:
            # verify at least one compressed file decompresses sanely
            decomp_ok = 0
            tested = 0
            for xo, xc, ye in entries[:6]:
                if xo >= ye:
                    continue
                blob = data[xo:ye]
                if xc:
                    tested += 1
                    d = lzkn64_decompress(blob)
                    if d is not None and len(d) >= 4:
                        decomp_ok += 1
                else:
                    tested += 1
                    if len(blob) >= 4:
                        decomp_ok += 1
            if tested and decomp_ok >= max(1, tested - 0):
                results.append((o, num, entries))
        o += 4
    print(f"\n== {path}: {len(results)} candidate tables ==")
    for o, num, entries in results[:12]:
        xo0 = entries[0][0]; xc0 = entries[0][1]
        print(f"  table@0x{o:07X} n={num} first=(off=0x{xo0:06X} comp={xc0} end=0x{entries[0][2]:06X})")
        # test-decompress first compressed entry
        for xo, xc, ye in entries[:4]:
            if xc:
                blob = data[xo:ye]
                d = lzkn64_decompress(blob)
                print(f"    {xo=:07X}->{ye:07X} COMPRESSED -> {len(d) if d else 'FAIL'} bytes, head={d[:8].hex() if d else ''}")

for p in ['/app/baserom.us.z64','/app/baserom.eu.z64']:
    scan(p)