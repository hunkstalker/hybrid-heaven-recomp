-- bizhawk_eu_glyph_capture.lua
-- Captura EMPIRICA del buffer de glifos del motor de texto EU, sin conocer su direccion.
--
-- Mecanismo: hook de escritura a RDRAM (`event.onmemorywrite`). Cada vez que el motor escribe en
-- RDRAM, guardamos una copia de los 64 B alrededor de la direccion escrita (con PC y A1/A2 si la
-- API de registros esta disponible) en un log de texto. Al navegar por una pantalla con acentos,
-- las escrituras del buffer de glifos quedan registradas con su contenido real.
--
-- Uso (BizHawk, ROM EU):
--   1) DIR = carpeta existente con barra final.
--   2) Tools -> Lua Console -> Script -> Open -> este fichero.
--   3) Llega a una pantalla con TEXTO y pulsa F12 en el juego unas cuantas veces (cambia de entrada)
--      durante ~10 s, para que se compongan glifos (incluidos acentos).
--   Salida: eu_glyph_writes.log (una linea por escritura relevante, con el hex de 64 B).
--
-- Nota: filtra escrituras cuyo bloque de 64 B contiene bytes "tipo glifo" (muchos 0x00/0x33/0xCC),
-- que reduce mucho el ruido. Ajusta FILTER si hace falta.

DIR = "E:/dev/docker/hybrid-heaven-pc-port/hybrid-heaven-recomp/work/eu_glyphs/"
-- Contenedor Linux: /app/hybrid-heaven-recomp/work/eu_glyphs/

RDRAM_BASE = 0x80000000
RDRAM_END  = 0x807FFFFF
WINDOW     = 64          -- bytes a volcar alrededor de la escritura
MIN_GLYPH  = 8           -- min. de bytes en {0x00,0x33,0xCC,0x03,0x0C,0x30,...} para considerarlo glifo
LOG = DIR .. "eu_glyph_writes.log"

local f = io.open(LOG, "w")
if not f then
  console.writeline("ERROR: no puedo escribir " .. LOG .. " (¿existe la carpeta DIR?)")
  return
end

local function reg(name)
  local v = nil
  pcall(function() v = memory.getregister(name) end)
  if v == nil then pcall(function() v = cpu.getregister(name) end) end
  return v
end

-- Filtro: cuenta pares "tipo 2bpp" (nibbles repetidos 3/3, C/C) y ceros, que abundan en los glifos.
local function looks_like_glyph(bytes)
  local n = 0
  for i = 1, #bytes do
    local b = bytes[i]
    if b == 0x00 or b == 0x33 or b == 0xCC or b == 0x0C or b == 0x30 or b == 0x03 then
      n = n + 1
    end
  end
  return n >= MIN_GLYPH
end

local writes = 0

local function on_write(addr, size, value)
  if addr < RDRAM_BASE or addr > RDRAM_END then return end
  -- Volcar una ventana alineada a 16 B alrededor de la escritura.
  local start = (addr - RDRAM_BASE) & 0xFFFFFFF0
  if start + WINDOW > 0x800000 then start = 0x800000 - WINDOW end
  local bytes = {}
  for i = 0, WINDOW - 1 do
    bytes[#bytes + 1] = memory.read_u8(RDRAM_BASE + start + i)
  end
  if not looks_like_glyph(bytes) then return end
  local pc = reg("PC")
  local a1 = reg("A1")
  local line = string.format("frame=%d addr=0x%08X size=%d val=0x%02X pc=%s a1=%s | %s\n",
    emu.framecount(), addr, size or 1, value or 0,
    pc and string.format("0x%08X", pc) or "?",
    a1 and string.format("0x%04X", a1) or "?",
    (function()
      local t = {}
      for i = 1, #bytes do t[#t + 1] = string.format("%02X", bytes[i]) end
      return table.concat(t, " ")
    end)())
  f:write(line)
  writes = writes + 1
  if writes % 50 == 0 then f:flush() end
end

if event and event.onmemorywrite then
  event.onmemorywrite(on_write)
  console.writeline("eu_glyph_capture: hook activo. Pulsa F12 en el juego en pantallas con texto.")
else
  console.writeline("ERROR: event.onmemorywrite no disponible en este BizHawk.")
end

-- Mantener el script vivo y hacer flush periodico.
while true do
  f:flush()
  emu.frameadvance()
end
