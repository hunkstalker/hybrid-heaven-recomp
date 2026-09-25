-- bizhawk_eu_glyphs_dump.lua
-- Captura de los glifos acentuados (gaiji) de la ROM EU: el motor de texto los compone en un buffer
-- de RDRAM. No depende de direcciones de codigo conocidas (el layout del motor EU difiere del US):
-- vuelca RDRAM completa cada N frames durante unos segundos; offline se localiza el buffer y su
-- layout comparando volcanes de pantallas con texto distinto.
-- Ver notes/2026-09-25-c-font-eu-color4-localizada.md.
--
-- Uso (BizHawk, ROM EU):
--   1) Pon DIR a una carpeta EXISTENTE (con barra final).
--   2) Tools -> Lua Console -> Script -> Open -> este fichero.
--   3) Llega a una pantalla con TEXTO (menu de pausa/opciones: la ayuda DE/FR tiene acentos) y
--      pulsa F12 en el juego varias veces para cambiar de entrada mientras corre (~8 s).
--   4) Repite en 2-3 pantallas con texto distinto.
--   Salida: eu_rdram_<NNN>_<frame>.bin (8 MB c/u) + eu_rdram_index.txt.

DIR = "E:/dev/docker/hybrid-heaven-pc-port/hybrid-heaven-recomp/work/eu_glyphs/"
-- En el contenedor Linux: /app/hybrid-heaven-recomp/work/eu_glyphs/

PERIOD_FRAMES = 45      -- un volcan cada ~0.75 s (60 Hz)
MAX_SNAPSHOTS = 16

RDRAM_SIZE = 0x800000   -- 8 MB
RDRAM_BASE = 0x80000000

local DOMAIN = nil
local count = 0
local last = -1

local function pick_domain()
  local ok, domains = pcall(memory.getmemorydomains)
  if not ok or not domains then return false end
  for _, d in ipairs(domains) do
    local size = nil
    pcall(function() size = memory.getmemorydomainsize(d) end)
    if size == RDRAM_SIZE then DOMAIN = d return true end
  end
  for _, d in ipairs(domains) do
    local size = nil
    pcall(function() size = memory.getmemorydomainsize(d) end)
    if size and size >= RDRAM_SIZE then DOMAIN = d return true end
  end
  return false
end

local function write_file(name, data)
  local f = io.open(name, "wb")
  if not f then return false end
  f:write(data)
  f:close()
  return true
end

-- Traza ligera de registros (si la API esta disponible): loguea PC/A0/A1/R4/R5 para correlacionar.
local function reg(name)
  local v = nil
  pcall(function() v = memory.getregister(name) end)
  if v == nil then pcall(function() v = cpu.getregister(name) end) end
  return v
end

local function snapshot()
  if not DOMAIN then return end
  local buf = {}
  for off = 0, RDRAM_SIZE - 1, 4 do
    local v = 0
    pcall(function() v = memory.read_u32_be(RDRAM_BASE + off, DOMAIN) end)
    buf[#buf + 1] = string.char((v >> 24) & 0xFF, (v >> 16) & 0xFF, (v >> 8) & 0xFF, v & 0xFF)
  end
  local name = string.format("%seu_rdram_%03d_%d.bin", DIR, count, emu.framecount())
  if write_file(name, table.concat(buf)) then
    local pc = reg("PC")
    local idx = io.open(DIR .. "eu_rdram_index.txt", "a")
    if idx then
      idx:write(string.format("%d frame=%d pc=%s %s\n", count, emu.framecount(),
                              pc and string.format("0x%08X", pc) or "?", name))
      idx:close()
    end
    console.writeline("snapshot " .. name)
  else
    console.writeline("ERROR: no puedo escribir en DIR (¿existe la carpeta?): " .. DIR)
  end
  count = count + 1
end

write_file(DIR .. "eu_rdram_index.txt", "")
console.writeline("eu_glyphs_dump: dirigiendo a " .. DIR .. " (crea la carpeta si falla).")

while count < MAX_SNAPSHOTS do
  if not DOMAIN then pick_domain() end
  local fr = emu.framecount()
  if DOMAIN and (fr - last) >= PERIOD_FRAMES then
    last = fr
    snapshot()
  end
  emu.frameadvance()
end
console.writeline("eu_glyphs_dump: hecho, " .. count .. " volcanes.")
