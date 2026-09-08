import sys
def loadppm(p):
    d=open(p,'rb').read()
    # header: P6 + whitespace W H whitespace MAXVAL whitespace
    i=0; n=len(d)
    while i<n and d[i:i+1].isspace(): i+=1
    assert d[i:i+1]==b'P', d[i:i+6]
    i+=2
    toks=[]
    while len(toks)<3:
        while i<n and d[i:i+1].isspace(): i+=1
        j=i
        while j<n and not d[j:j+1].isspace(): j+=1
        toks.append(int(d[i:j])); i=j
    while i<n and d[i:i+1].isspace(): i+=1
    W,H,M=toks
    return W,H,bytearray(d[i:])
W,H,body=loadppm(sys.argv[1])
pw=int(sys.argv[2]) if len(sys.argv)>2 else 80
ph=pw*H//(2*W)
Cs=' .,:;irsXA253hMHGS#9B&@'
def lum(r,g,b): return int(0.299*r+0.587*g+0.114*b)
out=[]
for y in range(ph):
    row=''
    for x in range(pw):
        s=0;n=0
        for yy in range(int(y*H/ph),int((y+1)*H/ph)):
            for xx in range(int(x*W/pw),int((x+1)*W/pw)):
                o=(yy*W+xx)*3; s+=lum(body[o],body[o+1],body[o+2]); n+=1
        row+=Cs[min(len(Cs)-1,int(s/n)//(255//len(Cs)))]
    out.append(row)
print('\n'.join(out))
