#!/usr/bin/env python3
"""Deep analysis of Hybrid Heaven ROMs (US + EU)."""
import struct, sys, os, re

def parse_header(data):
    h = data[0:0x40]
    out = {}
    out['magic'] = h[0:4].hex()
    out['clock_rate'] = h[0x4:0x8].hex()
    out['pc'] = h[0x8:0xC].hex()
    out['release'] = h[0xC:0x10].hex()
    out['crc1'], out['crc2'] = struct.unpack('>II', h[0x10:0x18])
    out['country'] = chr(h[0x1E]) if 0x1E < len(h) else '?'
    out['version'] = h[0x1F]
    out['title'] = h[0x20:0x34].decode('ascii', errors='replace').rstrip('\x00 ')
    out['boot'] = h[0x38:0x40].hex()
    return out

def main(paths):
    for p in paths:
        data = open(p, 'rb').read()
        print(f"\n{'='*70}\nFILE: {p}  ({len(data)} bytes = {len(data)//1024//1024} MB)")
        h = parse_header(data)
        for k, v in h.items():
            print(f"  {k:10s}: {v}")

        # Check byte order: z64 big-endian has 0x80371240
        if data[0:4] == b'\x80\x37\x12\x40':
            print("  byte order : z64 (big-endian) native")
        elif data[0:4] == b'\x40\x12\x37\x80':
            print("  byte order : v64 (byteswapped) - needs conversion to z64")
        elif data[0:4] == b'\x37\x80\x40\x12':
            print("  byte order : n64 (word-swapped) - needs conversion to z64")

        # CRC check - N64 CRC is over first 1MB but let's just note
        # Entry point at 0x8 - usually 0x80000400 or 0x80000450
        print(f"  entry      : 0x{h['pc']}")

        # Look for boot code at first bytes after header
        # N64 OS strings
        for s in [b'osInitialize', b'osViInit', b'N64', b'nintendo']:
            idx = data.find(s)
            if idx >= 0:
                print(f"  found {s.decode(errors='replace')} at 0x{idx:X}")

        # Detect LZSS (Hybrid Heaven 'trans.c' mentions Lzss). 
        # Nintendo LZ10/LZ11 style: first byte usually controls
        # Count occurrences of common ascii text runs
        ascii_runs = re.findall(rb'[ -~]{10,}', data)
        n_runs = len(ascii_runs)
        # Japanese/Shift-JIS detection heuristic: look for kuten high bytes
        sjis = len(re.findall(rb'[\x81-\x9F\xE0-\xEF][\x40-\x7E\x80-\xFC]', data))
        print(f"  ASCII runs : {n_runs} ; Shift-JIS-ish byte pairs: {sjis}")

        # Find stretches of 0x00 padding (segment boundaries hint)
        # Count clusters
        zc = data.count(b'\x00'*16)
        print(f"  runs of 16+ zero bytes: {zc}")

        # Text-heavy segment estimation: scan for dense printable regions
        # sample first megabyte
        chinese = re.findall(rb'[\xE0-\xEF]', data[:0x100000])
        print(f"  high-byte count in first 1MB: {len(chinese)}")

if __name__ == '__main__':
    main(['rom/baserom.us.z64', 'rom/baserom.eu.z64'])