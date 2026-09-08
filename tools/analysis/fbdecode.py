#!/usr/bin/env python3
# fbdecode.py  — decodifica el framebuffer N64 desde un dump RDRAM (word-swapped)
# Uso: fbdecode.py dump.bin [base_hex] [w] [h] [bpp16|32] [out.ppm]
# Sin args: barrido de candidatos y scoring para encontrar el framebuffer.
import sys

def load(d):
    return open(d,'rb').read()

def pixel_16(ch):
    # chunk de 4 bytes (word dump): [p1lo p1hi p0lo p0hi]
    p0 = (ch[2] | (ch[3]<<8)) & 0xFFFF
    p1 = (ch[0] | (ch[1]<<8)) & 0xFFFF
    r = lambda p: ((p>>11)&31)<<3
    g = lambda p: ((p>>6)&31)<<3
    b = lambda p: ((p>>1)&31)<<3
    return (r(p1),g(p1),b(p1)), (r(p0),g(p0),b(p0))

def pixel_32(ch):
    w = ch[3] | (ch[2]<<8) | (ch[1]<<16) | (ch[0]<<24)
    return ((w>>24)&0xff,(w>>16)&0xff,(w>>8)&0xff), ((w>>16)&0xff,(w>>8)&0xff,(w>>0)&0xff)

def render(data, base, w, h, bpp):
    out = bytearray()
    px = pixel_16 if bpp==16 else pixel_32
    for y in range(h):
        for x in range(w):
            o = base + (y*(w if False else w) + x)*4
            if o+4 > len(data): return None
            p0,p1 = px(data[o:o+4])
            if x & 1: c=p1
            else: c=p0
            out += bytes(c)
    return bytes(out)

def score(data, base, w, h, bpp):
    px = pixel_16 if bpp==16 else pixel_32
    # sample rows
    tot=0; n=0; mean=0; hits=0
    step = max(1, w//64)
    for y in range(0, h, max(1,h//48)):
        row=[]
        for x in range(w):
            o = base + (y*w+x)*4
            if o+4 > len(data): return -1,0
            p0,p1 = px(data[o:o+4])
            c=p0 if (x&1)==0 else p1
            row.append(c)
        for i in range(0,len(row)-max(1,w//64),max(1,w//64)):
            a,b=row[i],row[i+max(1,w//64)]
            d=abs(a[0]-b[0])+abs(a[1]-b[1])+abs(a[2]-b[2])
            tot+=d; n+=1
    return tot/max(1,n), tot

def main():
    if len(sys.argv)>=2:
        d=sys.argv[1]
        if len(sys.argv)>=6:
            base=int(sys.argv[2],16); w=int(sys.argv[3]); h=int(sys.argv[4]); bpp=int(sys.argv[5]); out=sys.argv[6]
            data=load(d)
            p=render(data,base,w,h,bpp)
            if p is None: print("out of range"); return
            open(out,'wb').write(b'P6\n%d %d\n255\n'%(w,h)+p)
            print("Wrote",out)
            return
    data=load(d)
    best=[]
    for base in [0, 0x500, 0xa00, 0x1000, 0x2000, 0x3000, 0x4000, 0x8000, 0x10000, 0x20000, 0x40000, 0x80000]:
        for w,h,bpp in [(640,480,16),(640,480,32),(320,240,16),(640,240,16)]:
            s,_=score(data,base,w,h,bpp)
            best.append((s,base,w,h,bpp))
    best.sort(reverse=True)
    for b in best[:12]:
        print("score=%8.2f base=0x%06x %dx%d bpp=%d" % b)

main()