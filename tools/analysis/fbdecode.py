#!/usr/bin/env python3
# fbdecode.py v2 — framebuffer N64 16bpp desde dump RDRAM (word-swapped)
# Con pitch correcto (2 B/pixel) y metricas de "ruido" (correlacion vecinos).
# Uso: fbdecode.py dump.bin [base _ hex] [w] [h] [out.ppm]
import sys

def load(d):
    return open(d,'rb').read()

def word16(buf, o):
    # grupo de 4 bytes del file = palabra dump (LE); dos pixeles 5551
    pe = (buf[o+2] | (buf[o+3]<<8)) & 0xFFFF   # posicion par  -> pixel x (even)
    po = (buf[o+0] | (buf[o+1]<<8)) & 0xFFFF   # posicion impar -> pixel x+1
    return pe, po

def px(v):
    return ((v>>11)&31)<<3, ((v>>6)&31)<<3, ((v>>1)&31)<<3

def render(data, base, w, h):
    stride = w*2
    if base + stride*h + 4 > len(data): return None
    out = bytearray()
    corr_same = 0
    corr_next = 0
    nn = 0
    for y in range(h):
        row = []
        ob = base + y*stride
        for c in range(w//2):
            pe, po = word16(data, ob + c*4)
            row.append(px(pe)); row.append(px(po))
        for c in range(w):
            out += bytes(row[c])
        # correlacion: brilla entre pixel c y c+1 (horizontal) y vs fila anterior
        for c in range(w-1):
            d = abs(row[c][0]-row[c+1][0])+abs(row[c][1]-row[c+1][1])+abs(row[c][2]-row[c+1][2])
            if d <= 12: corr_same += 1
            nn += 1
    return bytes(out), corr_same/max(1,nn)

def info(data, base, w, h):
    r = render(data, base, w, h)
    if r is None: return None
    return r[1]

def main():
    d = sys.argv[1]
    data = load(d)
    if len(sys.argv) >= 5:
        base=int(sys.argv[2],16); w=int(sys.argv[3]); h=int(sys.argv[4])
        out = sys.argv[5] if len(sys.argv)>5 else 'work/debug/fb.ppm'
        r = render(data, base, w, h)
        if r is None: print("out of range"); return
        open(out,'wb').write(b'P6\n%d %d\n255\n'%(w,h)+r[0])
        print("Wrote %s  (neighbor-similar=%.3f)" % (out, r[1]))
        return
    # barrido
    rows=[]
    for base in [0x0,0x500,0xa00,0x1000,0x1400,0x1800,0x2000,0x4000,0x8000,0x10000,0x20000,0x40000,0x80000,0xB0000]:
        for w,h in [(640,480),(640,240),(320,480)]:
            s=info(data,base,w,h)
            if s is not None: rows.append((s,base,w,h))
    rows.sort(reverse=True)
    for s,b,w,h in rows[:14]:
        print("sim=%.3f base=0x%06x %dx%d" % (s,b,w,h))

main()