import struct

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

def compress(data):
    raise NotImplementedError(
        "compress shim not implemented; only decompress is needed for extraction"
    )