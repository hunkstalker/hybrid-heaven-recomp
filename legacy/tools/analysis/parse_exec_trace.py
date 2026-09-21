import re, sys
log = sys.argv[1] if len(sys.argv)>1 else 'work/debug/emu_ld.log'
pat_stop = re.compile(r"\[dbg\] stop pc=0x([0-9A-Fa-f]+) \(t=([\d.]+)s\).*")
pat_vi   = re.compile(r"\[dbg\] vi_count=(\d+) t=")
pat_args = re.compile(r"\[dbg\]   a0=0x([0-9A-Fa-f]+) a1=0x([0-9A-Fa-f]+) a2=0x([0-9A-Fa-f]+) a3=0x([0-9A-Fa-f]+) ra=0x([0-9A-Fa-f]+)")
cur=None
for line in open(log, errors='replace'):
    m=pat_stop.search(line)
    if m:
        cur={'pc':int(m.group(1),16),'t':float(m.group(2)),'vi':None,'args':None}
        continue
    m=pat_vi.search(line)
    if m and cur and cur['vi'] is None:
        cur['vi']=int(m.group(1)); continue
    m=pat_args.search(line)
    if m and cur and cur['args'] is None:
        cur['args']=tuple(int(m.group(i),16) for i in range(1,6))
        print(f"pc={cur['pc']:08X} t={cur['t']:7.2f} vi={cur['vi']:5} a0={cur['args'][0]:08X} a1={cur['args'][1]:08X} a2={cur['args'][2]:08X} a3={cur['args'][3]:08X} ra={cur['args'][4]:08X}")
        cur=None
