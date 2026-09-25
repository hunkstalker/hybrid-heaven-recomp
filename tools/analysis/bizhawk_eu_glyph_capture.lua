-- bizhawk_eu_glyph_capture.lua  (v3)
-- Captura EMPIRICA del buffer de glifos EU sin hooks (no bloquea). Al pulsar el BOTON MARCADOR,
-- guarda: (a) un volcado de RDRAM (8 MB) y (b) los REGISTROS de CPU (PC/A1/A2/R4/R5) de ese frame,
-- para correlacionar el valor de glifo compuesto con el buffer.
--
-- Uso (BizHawk, ROM EU):
--   1) DIR = carpeta existente con barra final.
--   2) Tools -> Lua Console -> Script -> Open -> este fichero.
--   3) Cambia de boton marcador con MARK_BUTTON si quieres (por defecto "L"; "Start" tambien vale).
--      Llega a una pantalla con TEXTO y pulsa el boton marcador en textos/idiomas distintos.
--   Salida: eu_rdram_<NNN>_<frame>.bin (8 MB) + eu_rdram_index.txt (incluye PC/A1/A2).
--
-- No bloquea: solo hace I/O en el frame de la pulsacion.

DIR = "E:/dev/docker/hybrid-heaven-pc-port/hybrid-heaven-recomp/work/eu_glyphs/"
-- Contenedor Linux: /app/hybrid-heaven-recomp/work/eu_glyphs/

MARK_BUTTON = "L"       -- boton del mando que marca el snapshot (L/R del N64 = gatillos)
RDRAM_SIZE = 0x800000
RDRAM_BASE = 0x80000000

local DOMAIN = nil
local count = 0
local prev = false

local function pick_domain()
  local ok, list = pcall(memory.getmemorydomainlist)
  if not ok or not list then return false end
  local pref = { "RDRAM", "N64 RAM", "System Bus" }
  for _, p in ipairs(pref) do
    for _, d in ipairs(list) do
      if d == p or string.find(d, p, 1, true) then DOMAIN = d return true end
    end
  end
  for _, d in ipairs(list) do
    local size = nil
    pcall(function() size = memory.getmemorydomainsize(d) end)
    if size and size >= RDRAM_SIZE then DOMAIN = d return true end
  end
  return false
end

local function reg(name)
  local v = nil
  pcall(function() v = memory.getregister(name) end)
  if v == nil then pcall(function() v = cpu.getregister(name) end) end
  if v == nil then pcall(function() v = emu.getregister(name) end) end
  return v
end

local function snapshot()
  if not DOMAIN then return end
  local pc = reg("PC")
  local a1 = reg("A1")
  local a2 = reg("A2")
  local r4 = reg("R4")
  local r5 = reg("R5")
  local buf = {}
  for off = 0, RDRAM_SIZE - 1, 4 do
    local v = memory.read_u32_be(RDRAM_BASE + off, DOMAIN)
    buf[#buf + 1] = string.char((v >> 24) & 0xFF, (v >> 16) & 0xFF, (v >> 8) & 0xFF, v & 0xFF)
  end
  local name = string.format("%seu_rdram_%03d_%d.bin", DIR, count, emu.framecount())
  local f = io.open(name, "wb")
  if not f then
    console.writeline("ERROR: no puedo escribir en DIR (¿existe la carpeta?): " .. DIR)
    return
  end
  f:write(table.concat(buf))
  f:close()
  -- Captura de pantalla emparejada (facilita saber QUE texto se mostraba).
  pcall(function() client.screenshot(name:gsub("%.bin$", ".png")) end)
  local idx = io.open(DIR .. "eu_rdram_index.txt", "a")
  if idx then
    idx:write(string.format("%d frame=%d pc=%s a1=%s a2=%s r4=%s r5=%s %s\n", count,
      emu.framecount(), pc and string.format("0x%08X", pc) or "?",
      a1 and string.format("0x%04X", a1) or "?", a2 and string.format("0x%04X", a2) or "?",
      r4 and string.format("0x%08X", r4) or "?", r5 and string.format("0x%08X", r5) or "?", name))
    idx:close()
  end
  count = count + 1
  console.writeline("snapshot " .. name)
end

local probe = io.open(DIR .. "eu_rdram_index.txt", "a")
if probe then probe:close() else console.writeline("Crea la carpeta: " .. DIR) end

local dbg = io.open(DIR .. "eu_glyph_capture_debug.txt", "w")
if dbg then
  dbg:write("MARK_BUTTON=" .. MARK_BUTTON .. "\n")
  local jp0 = joypad.get(1) or {}
  local keys = {}
  for k, _ in pairs(jp0) do keys[#keys + 1] = tostring(k) end
  table.sort(keys)
  dbg:write("joypad keys: " .. table.concat(keys, ", ") .. "\n")
  local ok, list = pcall(memory.getmemorydomainlist)
  if ok and list then
    local names = {}
    for _, d in ipairs(list) do names[#names + 1] = tostring(d) end
    dbg:write("domains: " .. table.concat(names, ", ") .. "\n")
  end
  if pick_domain() then dbg:write("DOMAIN elegido: " .. tostring(DOMAIN) .. "\n") end
  dbg:flush()
end

console.writeline("eu_glyph_capture v3: pulsa '" .. MARK_BUTTON .. "' en el juego para cada snapshot.")

local frame = 0
while true do
  if not DOMAIN then pick_domain() end
  local jp = joypad.get(1) or {}
  local down = jp[MARK_BUTTON] == true
  if down and not prev then
    if dbg then dbg:write(string.format("frame=%d PRESS %s\n", emu.framecount(), MARK_BUTTON)) dbg:flush() end
    snapshot()
  end
  prev = down
  frame = frame + 1
  if dbg and frame % 300 == 0 then
    dbg:write(string.format("heartbeat frame=%d domain=%s snapshots=%d\n",
                            emu.framecount(), DOMAIN or "nil", count))
    dbg:flush()
  end
  emu.frameadvance()
end
