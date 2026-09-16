#!/usr/bin/env python3
"""Find the true Konami file table start and test lzkn64 decompression on Hybrid Heaven."""
import struct

def find_tables(data, lo=0, hi=0x400000):
    best = []
    p = lo
    n = len(data)
    while p < hi:
        a, b = struct.unpack_from('>II', data, p)
        if (a & 0x80000000) and (b & 0x80000000):
            aend = a & 0x7FFFFFFF
            bend = b & 0x7FFFFFFF
            if bend >= aend and bend < n:
                # count run forward
                run = 1
                q = p + 8
                prev_end = aend
                while q + 8 <= n:
                    x, y = struct.unpack_from('>II', data, q)
                    if not ((x & 0x80000000) and (y & 0x80000000)):
                        break
                    xend = x & 0x7FFFFFFF
                    yend = y & 0x7FFFFFFF
                    if (xend < prev_end) or (yend < xend) or (yend >= n):
                        break
                    prev_end = xend
                    run += 1
                    q += 8
                best.append((run, p, aend, bend))
                p = q  # skip the run
                continue
        p += 4
    best.sort(reverse=True)
    return best

def lzkn64_decompress(data, offset):
    """Port of Goemon64Recomp lzkn64_decompress."""
    input_pos = offset + 4
    size = struct.unpack_from('>I', data, offset)[0]
    total = size if size < len(data) - offset else len(data) - offset
    out = bytearray()
    while input_pos < offset + total:
        cmd = data[input_pos]; input_pos += 1
        if cmd <= 0x7F:
            length = ((cmd & 0x7C) >> 2) + 2
            off = ((cmd & 0x03) << 8 | data[input_pos]) & 0x3FF
            input_pos += 1
            base = len(out) - off
            for i in range(length):
                out.append(out[base + i])
        elif cmd <= 0x9F:
            length = cmd & 0x1F
            out += data[input_pos:input_pos+length]
            input_pos += length
        elif cmd <= 0xDF:
            length = (cmd & 0x1F) + 2
            v = data[input_pos]; input_pos += 1
            out += bytes([v]*length)
        elif cmd <= 0xFE:
            length = (cmd & 0x1F) + 2
            out += b'\x00'*length
        else:
            length = data[input_pos] + 2; input_pos += 1
            out += b'\x00'*length
    return bytes(out)

data = open('rom/baserom.us.z64','rb').read()
print("=== Top file-table candidates (US) ===")
for run, p, aend, bend in find_tables(data)[:10]:
    print(f"  run={run:3d} table@0x{p:07X} first_file@0x{aend:07X} end@0x{bend:07X}")

# Test decompressing first files of the top candidate
run, p, _, _ = find_tables(data)[0]
print(f"\n=== Testing lzkn64 decompression on table @ 0x{p:07X} ===")
p = p - 0  # keep at run start (first entry may be mid-run though)
# walk back to find start: entries are 8 bytes; start is p if run is maximal
# decompress first 3 files
pos = p
for i in range(12):
    a, b = struct.unpack_from('>II', data, pos)
    foff = a & 0x7FFFFFFF
    fend = b & 0x7FFFFFFF
    comp = (a >> 31) & 1
    sz = fend - foff
    blob = data[foff:fend]
    if comp:
        try:
            dec = lzkn64_decompress(blob, 0)
            print(f"  entry{i}: off=0x{foff:07X} size=0x{sz:X} COMPRESSED -> {len(dec)} bytes  head={dec[:16].hex()}")
        except Exception as e:
            print(f"  entry{i}: off=0x{foff:07X} size=0x{sz:X} COMPRESSED -> ERROR {e}")
    else:
        print(f"  entry{i}: off=0x{foff:07X} size=0x{sz:X} raw   head={blob[:16].hex()}")
    if a == 0 and b == 0:
        break
    pos += 8