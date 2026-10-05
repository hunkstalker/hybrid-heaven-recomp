import struct

# LZKN64 (Konami / Nisitenma-Ichigo). Formato:
#   u32 BE: longitud total del stream comprimido (incluye la cabecera).
#   tokens hasta esa longitud:
#     0x00-0x7F  backref: len = ((cmd>>2)&0x1F)+2 (2..33); off = ((cmd&3)<<8)|byte (0..1023)
#     0x80-0x9F  copia literal: len = cmd&0x1F (1..31)
#     0xA0-0xDF  RLE de un valor: len = (cmd&0x1F)+2 (2..33); byte siguiente = valor
#     0xE0-0xFE  RLE de ceros: len = (cmd&0x1F)+2 (2..33)
#     0xFF       RLE de ceros largo: len = byte+2 (2..257)
# El descompresor original del repo solo implementaba `decompress`; `compress` es una
# reimplementacion limpia (reverse-engineered) que reproduce el tokenizado del compresor
# original salvo 5 casos exoticos de troceado de runs de ceros (ver tools/verify).


def decompress(data):
    if isinstance(data, memoryview):
        data = data.tobytes()
    if len(data) < 5:
        raise ValueError("input too short")
    size = struct.unpack_from('>I', data, 0)[0]
    if size < 4 or size > len(data):
        raise ValueError(f"bad decompressed size {size} for input len {len(data)}")
    out = bytearray()
    pos = 4
    while pos < size:
        cmd = data[pos]; pos += 1
        if cmd <= 0x7F:
            ln = ((cmd & 0x7C) >> 2) + 2
            off = (((cmd & 0x03) << 8) | data[pos]) & 0x3FF
            pos += 1
            base = len(out) - off
            if base < 0:
                raise ValueError("bad sliding offset")
            for i in range(ln):
                out.append(out[base + i])
        elif cmd <= 0x9F:
            ln = cmd & 0x1F
            if pos + ln > size:
                raise ValueError("raw copy overrun")
            out += data[pos:pos+ln]
            pos += ln
        elif cmd <= 0xDF:
            ln = (cmd & 0x1F) + 2
            if pos >= size:
                raise ValueError("rle value overrun")
            v = data[pos]; pos += 1
            out += bytes([v]) * ln
        elif cmd <= 0xFE:
            ln = (cmd & 0x1F) + 2
            out += b'\x00' * ln
        else:
            if pos >= size:
                raise ValueError("rle len overrun")
            ln = data[pos] + 2; pos += 1
            out += b'\x00' * ln
    return bytes(out)


class _Matcher:
    def __init__(self, data):
        self.d = data
        self.n = len(data)
        self.idx = {}
        for i in range(self.n - 3):
            self.idx.setdefault(data[i:i+4], []).append(i)

    def longest(self, p, window=991, maxlen=33):
        d = self.d; n = self.n
        if p + 4 > n:
            return 0, 0
        best = 0; bo = 0
        for q in reversed(self.idx.get(d[p:p+4], [])):
            if q >= p:
                continue
            off = p - q
            if off > window:
                break
            l = 4
            while l < maxlen and p + l < n and d[q+l] == d[p+l]:
                l += 1
            if l > best:
                best = l; bo = off
                if best == maxlen:
                    break
        return best, bo


def compress(data):
    """Comprime `data` a un stream LZKN64 (cabecera + tokens)."""
    if isinstance(data, memoryview):
        data = data.tobytes()
    n = len(data)
    m = _Matcher(data)

    def zero_at(p):
        z = 0
        while p + z < n and data[p+z] == 0:
            z += 1
        return z

    def rep_at(p):
        if data[p] == 0:
            return 0
        r = 1
        while p + r < n and data[p+r] == data[p]:
            r += 1
        return r

    body = bytearray()
    pos = 0
    while pos < n:
        M, mo = m.longest(pos)
        zr = zero_at(pos)
        rr = rep_at(pos)
        cands = []
        if zr >= 2:
            # Quirk del compresor original: el run de ceros se capa en la proxima
            # posicion (i+pos) & 0xFFF == 0x21 (mod 0x400). Ver tools/verify.
            fwm = 257 if (n - pos - 1) > 257 else (n - pos)
            if fwm > 33:
                for i in range(34, fwm + 1):
                    if (i + pos) & 0xFFF in (0x021, 0x421, 0x821, 0xC21):
                        fwm = i
                        break
            cands.append(('zero', min(zr, fwm), 0))
        if rr >= 3:
            cands.append(('rlev', min(rr, 32), data[pos]))
        if M >= 4:
            cands.append(('back', M, mo))
        kind = None; best = 0
        for c in cands:  # empate: RLE antes que back (orden zero, rlev, back)
            if c[1] > best:
                kind, best = c, c[1]
        if kind is None:
            start = pos
            run = 1; pos += 1
            while pos < n and run < 31:
                if zero_at(pos) >= 2: break
                if rep_at(pos) >= 3: break
                if m.longest(pos)[0] >= 4: break
                run += 1; pos += 1
            body.append(0x80 | run)
            body += data[start:start+run]
            continue
        k, ln, val = kind
        if k == 'zero':
            c = ln
            if c >= 33:
                body.append(0xFF); body.append(c - 2)
            else:
                body.append(0xE0 | (c - 2))
            pos += c
        elif k == 'rlev':
            c = min(32, rr)
            body.append(0xC0 | (c - 2)); body.append(data[pos])
            pos += c
        else:  # back
            body.append(((ln - 2) << 2) | ((val >> 8) & 0x03))
            body.append(val & 0xFF)
            pos += ln

    total = 4 + len(body)
    out = struct.pack('>I', total) + bytes(body)
    if total % 2 != 0:          # el original alinea a par (cabecera = longitud sin el pad)
        out += b'\x00'
    return out
