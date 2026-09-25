-- bizhawk_eu_glyph_capture.lua  (v2, LIGERO)
-- Captura EMPIRICA del buffer de glifos EU SIN hook de escritura (que bloqueaba el emulador).
--
-- Mecanismo: no engancha nada. Espera a que el jugador pulse un BOTON del mando (por defecto
-- "Start") y, en ese instante, hace UN volcado de RDRAM (8 MB) a un fichero. Repite: cada pulsacion
-- es un snapshot. Offline se localiza el buffer de glifos por diff entre snapshots de pantallas
-- distintas (tools/analysis/eu_glyphs_find.py).
--
-- Uso (BizHawk, ROM EU):
--   1) DIR = carpeta existente con barra final.
--   2) Tools -> Lua Console -> Script -> Open -> este fichero.
--   3) Llega a una pantalla con TEXTO; pulsa el boton marcador (Start) en 2-3 entradas/idiomas
--      distintos. Cada pulsacion escribe eu_rdram_<NNN>.bin (8 MB) + eu_rdram_index.txt.
--
-- No bloquea: solo hace I/O en el frame de la pulsacion.

DIR = "E:/dev/docker/hybrid-heaven-pc-port/hybrid-heaven-recomp/work/eu_glyphs/"
-- Contenedor Linux: /app/hybrid-heaven-recomp/work/eu_glyphs/

MARK_BUTTON = "Start"   -- boton del mando que marca el snapshot (evita depender de teclas de PC)
RDRAM_SIZE = 0x800000
RDRAM_BASE = 0x80000000

local DOMAIN = nil
local count = 0
local prev = false

local function pick_domain()
  local ok, domains = pcall(memory.getmemorydomains)
  if not ok or not domains then return false end
  for _, d in ipairs(domains) do
    local size = nil
    pcall(function() size = memory.getmemorydomainsize(d) end)
    if size == RDRAM_SIZE then DOMAIN = d return true end
  end
  return false
end

local function snapshot()
  if not DOMAIN then return end
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
  local idx = io.open(DIR .. "eu_rdram_index.txt", "a")
  if idx then idx:write(string.format("%d frame=%d %s\n", count, emu.framecount(), name)) idx:close() end
  count = count + 1
  console.writeline("snapshot " .. name)
end

-- Aviso: la carpeta DIR debe existir (BizHawk Lua no crea directorios).
local probe = io.open(DIR .. "eu_rdram_index.txt", "a")
if probe then probe:close() else console.writeline("Crea la carpeta: " .. DIR) end
console.writeline("eu_glyph_capture v2: pulsa '" .. MARK_BUTTON .. "' en el juego para cada snapshot.")

while true do
  if not DOMAIN then pick_domain() end
  local jp = joypad.get(1) or {}
  local down = jp[MARK_BUTTON] == true
  if down and not prev then
    snapshot()
  end
  prev = down
  emu.frameadvance()
end
