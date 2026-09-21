-- bizhawk_hh_tracker_v3.lua
-- v3 = v2 (directorio de overlays + botones + F12/F11) + GRABACION DE INPUT PARA REPLAY:
--   replay.log : una linea por frame -> "frame buttons_hex x y"  (botones N64 crudos, encoding del port)
--   state.log  : una linea por frame -> "frame 89478 8DA8 8CE8 8D00 CF C" (estado clave de la transicion)
--
-- Uso (igual que v2):
--   Tools -> Lua Console -> Script -> Open -> este fichero.
--   Config -> Controllers -> N64 Controller 1 = tu mando (Xbox).
--   Pulsa F11 al empezar (reset de logs) y juega DESDE EL ARRANQUE hasta el combate.
--
-- Salidas en LOGDIR:
--   game.log/buttons.log (v2), replay.log (input por frame), state.log (estado por frame),
--   capturas F12 (PNG + .txt).
--
-- Notas:
--  - replay.log NO depende del dominio de memoria: se escribe siempre (solo necesita joypad).
--  - state.log requiere el dominio de memoria N64 (se escribe cuando el directorio esta listo).
--  - Los ficheros se mantienen abiertos y se hace flush ~1/s para no frenar BizHawk.

LOGDIR = "E:/dev/docker/hybrid-heaven-pc-port/hybrid-heaven-recomp/work/gameplay screenshots/"
GAMENAME = "Hybrid Heaven (USA)"            -- prefijo exacto de las capturas de BizHawk
SS_KEY   = "F12"                            -- tecla de captura (puedes cambiarla)
RESET_KEY = "F11"                           -- tecla de reset

DIR    = 0x8008DFC0                        -- directorio de overlays (0x100 slots x 8 bytes)
NSLOTS = 0x100

BTN_KEYS = {"A","B","Z","Start","L","R",
            "Dpad-U","Dpad-D","Dpad-L","Dpad-R",
            "C-Up","C-Down","C-Left","C-Right"}

-- Encoding N64 del port (src/subsystems/input.cpp, enum N64Buttons).
BTN_BITS = {
  ["A"]        = 0x8000,
  ["B"]        = 0x4000,
  ["Z"]        = 0x2000,
  ["Start"]    = 0x1000,
  ["Dpad-U"]   = 0x0800,
  ["Dpad-D"]   = 0x0400,
  ["Dpad-L"]   = 0x0200,
  ["Dpad-R"]   = 0x0100,
  ["L"]        = 0x0020,
  ["R"]        = 0x0010,
  ["C-Up"]     = 0x0008,
  ["C-Down"]   = 0x0004,
  ["C-Left"]   = 0x0002,
  ["C-Right"]  = 0x0001,
}

-- Direcciones del estado clave de la transicion (ver notes/2026-09-17-cac-timeline-modulo24-periodo.md).
STATE_ADDRS = {0x80089478, 0x801D8DA8, 0x801D8CE8, 0x801D8D00, 0x801D8CFC, 0x801D8CE4}

local file_game = LOGDIR .. "game.log"
local file_btn  = LOGDIR .. "buttons.log"
local file_rep  = LOGDIR .. "replay.log"
local file_state= LOGDIR .. "state.log"

local t_start      = emu.framecount()
local last_btn     = {}
local last_dump_fr = -1
local last_setkey  = ""
local domains      = {}
local dom_idx      = 0
local DOMAIN       = nil
local bad_scans    = 0
local log_wait     = ""
local last_ss      = false

local rep_f, state_f = nil, nil
local last_flush_fr = 0

-- vuelca un rango de memoria en hex (para diagnostico del mecanismo de tareas)
function dump_range(addr, len)
  local out = {}
  for off = 0, len - 1, 16 do
    local row = {}
    for k = 0, 15 do
      local v = nil
      if DOMAIN then v = memory.read_u8(addr + off + k, DOMAIN)
               else v = memory.read_u8(addr + off + k) end
      row[#row + 1] = string.format("%02X", v or 0)
    end
    out[#out + 1] = string.format("  0x%08X: %s", addr + off, table.concat(row, " "))
  end
  return out
end

function append(path, line)
  local f = io.open(path, "a")
  if f then f:write(line, "\n") f:close() end
end

function close_logs()
  if rep_f   then rep_f:close()   rep_f = nil   end
  if state_f then state_f:close() state_f = nil end
end

function open_logs()
  close_logs()
  rep_f   = io.open(file_rep,   "w")
  state_f = io.open(file_state, "w")
  if rep_f   then rep_f:write("# frame buttons_hex stick_x stick_y\n")     rep_f:flush()   end
  if state_f then state_f:write("# frame " .. string.format("%08X", STATE_ADDRS[1]) .. " ...\n") state_f:flush() end
end

function reset_logs()
  local f = io.open(file_game, "w"); if f then f:write("") f:close() end
  local b = io.open(file_btn,  "w"); if b then b:write("") b:close() end
  open_logs()
  t_start = emu.framecount()
end

function build_domains()
  local out = {}
  local list = memory.getmemorydomainlist() or {}
  local pref = {"N64 RAM", "RDRAM", "System Bus", "System"}
  for _, p in ipairs(pref) do
    for _, d in ipairs(list) do
      if string.find(d, p, 1, true) then
        out[#out + 1] = d
      end
    end
  end
  for _, d in ipairs(list) do
    local seen = false
    for _, o in ipairs(out) do if o == d then seen = true end end
    if not seen then out[#out + 1] = d end
  end
  return out
end

function next_domain()
  dom_idx = dom_idx + 1
  if #domains == 0 then domains = build_domains() end
  if #domains == 0 then DOMAIN = nil; return false end
  local d = domains[((dom_idx - 1) % #domains) + 1]
  if d ~= DOMAIN then
    DOMAIN = d
    append(file_game, string.format("### probando dominio de memoria: %s", tostring(d)))
  end
  return true
end

function read_entry(i)
  local addr = DIR + i * 8
  local hex = {}
  for k = 0, 7 do
    local v = nil
    if DOMAIN then v = memory.read_u8(addr + k, DOMAIN)
             else v = memory.read_u8(addr + k) end
    hex[k] = v or 0
  end
  local id   = hex[0] * 256 + hex[1]
  local base = hex[4] * 16777216 + hex[5] * 65536 + hex[6] * 256 + hex[7]
  local raw  = string.format("%02X%02X%02X%02X%02X%02X%02X%02X",
     hex[0],hex[1],hex[2],hex[3],hex[4],hex[5],hex[6],hex[7])
  return id, base, raw
end

function dir_lines()
  local out = {}
  for i = 0, NSLOTS - 1 do
    local id, base, raw = read_entry(i)
    if not (id == 0 and base == 0) then
      local swapped = (id % 256) * 256 + math.floor(id / 256)
      out[#out + 1] = string.format("  s%03d id=0x%04X base=0x%08X (swap id=0x%04X base=0x%08X) raw=%s",
         i, id, base, swapped, base, raw)
    end
  end
  return out
end

function dump_directory(pfx)
  local frame = emu.framecount()
  local t     = (frame - t_start) / 60.0
  local wh    = os.date("%H:%M:%S")
  local lines = dir_lines()
  append(file_game, pfx .. string.format("--- frame %d %.3fs %s ---", frame, t, wh))
  for _, l in ipairs(lines) do append(file_game, l) end
  return #lines
end

-- clave del estado del directorio (para detectar cambios de fase)
function set_key()
  local key = {}
  for i = 0, NSLOTS - 1 do
    local id, base = read_entry(i)
    if not (id == 0 and base == 0) then
      key[id] = (key[id] or "") .. "," .. string.format("%X", base)
    end
  end
  local parts = {}
  for k, v in pairs(key) do parts[#parts + 1] = k .. "@" .. v end
  table.sort(parts)
  return table.concat(parts, "|")
end

-- ¿slot 0 apunta a RAM valida? (dominio/offset correcto)
function dir_ready()
  local id0, b0 = read_entry(0)
  return id0 ~= 0 and b0 >= 0x80000000 and b0 <= 0x803FFFFF
end

local last_stick_x, last_stick_y = 0, 0

-- Devuelve el estado actual del pad de jugador 1
function update_buttons()
  local now = joypad.get(1) or {}
  local frame = emu.framecount()
  local t     = (frame - t_start) / 60.0
  local wh    = os.date("%H:%M:%S")
  for _, b in ipairs(BTN_KEYS) do
    local cur = now[b] == true
    local prev = last_btn[b] == true
    if cur and not prev then
      append(file_btn, string.format("%d %.3f %s PRESS %s", frame, t, wh, b))
    elseif prev and not cur then
      append(file_btn, string.format("%d %.3f %s RELEASE %s", frame, t, wh, b))
    end
    last_btn[b] = cur
  end
  return now
end

-- Stick analogico del pad 1 (numeros; claves con "Stick" y "X"/"Y" en BizHawk).
function stick_xy(now)
  local x, y = 0, 0
  if now then
    for k, v in pairs(now) do
      if type(v) == "number" and string.find(k, "Stick", 1, true) then
        if string.find(k, "X", 1, true) then x = v
        elseif string.find(k, "Y", 1, true) then y = v end
      end
    end
  end
  return x, y
end

function update_stick(now)
  local x, y = stick_xy(now)
  if math.abs(x - last_stick_x) > 40 or math.abs(y - last_stick_y) > 40 then
    local frame = emu.framecount()
    local t     = (frame - t_start) / 60.0
    append(file_btn, string.format("%d %.3f %s STICK %.0f,%.0f",
            frame, t, os.date("%H:%M:%S"), x, y))
    last_stick_x, last_stick_y = x, y
  end
end

-- Botones N64 crudos (encoding del port) a partir de joypad.get(1).
function n64_mask(now)
  local m = 0
  if now then
    for _, b in ipairs(BTN_KEYS) do
      if now[b] == true then m = m + BTN_BITS[b] end
    end
  end
  return m
end

-- Lectura de estado (u32 BE) con fallback a bytes.
function read_u32_be(addr)
  if DOMAIN and memory.read_u32_be then
    local ok, v = pcall(memory.read_u32_be, addr, DOMAIN)
    if ok and v then return v end
  end
  local v = 0
  for k = 0, 3 do
    local b = nil
    if DOMAIN then b = memory.read_u8(addr + k, DOMAIN)
             else b = memory.read_u8(addr + k) end
    v = v * 256 + (b or 0)
  end
  return v
end

-- Log por frame del input (siempre) y del estado (cuando hay dominio).
function log_frame(now)
  local frame = emu.framecount()
  local x, y = stick_xy(now)
  if rep_f then
    rep_f:write(string.format("%d %04X %.1f %.1f\n", frame, n64_mask(now), x, y))
  end
  if state_f and DOMAIN then
    local parts = {}
    for _, a in ipairs(STATE_ADDRS) do parts[#parts + 1] = string.format("%08X", read_u32_be(a)) end
    state_f:write(string.format("%d %s\n", frame, table.concat(parts, " ")))
  end
  if frame - last_flush_fr >= 60 then
    last_flush_fr = frame
    if rep_f then rep_f:flush() end
    if state_f then state_f:flush() end
  end
end

function take_capture()
  local frame = emu.framecount()
  -- nombre UNICO por F12 (segundo + centesimas de frame): evita el " (N)"
  -- que BizHawk anade si dos capturas caen en el mismo segundo, de modo que
  -- el .txt y el .png compartan EXACTAMENTE el mismo nombre.
  local stamp  = os.date("%Y-%m-%d %H.%M.%S") .. string.format(".%03d", frame % 60)
  local png    = GAMENAME .. "." .. stamp .. ".png"
  local txt    = png:gsub("%.png$", ".txt")
  local t      = (frame - t_start) / 60.0

  local written = false
  if pcall(function() client.screenshot(LOGDIR .. png) end) then
    written = true
  else
    client.screenshot()   -- fallback: captura nativa (nombre con " (N)" en el peor caso)
  end

  local f = io.open(LOGDIR .. txt, "w")
  if f then
    f:write("# captura: ", png, " escrita=", tostring(written), "\n")
    f:write("# frame=", frame, " t=", string.format("%.3fs", t),
            " wall=", os.date("%Y-%m-%d %H:%M:%S"), "\n")
    f:write("# directorio 0x8008DFC0 (", string.format("0x%X", DIR), "):\n")
    for _, l in ipairs(dir_lines()) do f:write(l, "\n") end
    f:write("# === estado de la transicion (v3) ===\n")
    for _, a in ipairs(STATE_ADDRS) do
      f:write(string.format("  0x%08X = 0x%08X\n", a, read_u32_be(a)))
    end
    f:write("# joypad.get(1) (diagnostico: aqui se ve el nombre real del stick):\n")
    local jp = joypad.get(1) or {}
    for k, v in pairs(jp) do f:write(string.format("  %s = %s\n", tostring(k), tostring(v))) end
    f:close()
  end

  local live = dump_directory("# F12 " .. png .. "\n")
  append(file_game, string.format("### F12 shot=%s txt=%s escrita=%s live=%d",
          png, txt, tostring(written), live))
  console.log("Captura tomada:", png, "| datos en", LOGDIR .. txt,
              "| pad minimo:", #(joypad.get(1) or {}), "keys")
end

append(file_game, string.format("### script arrancado (core=%s) frame=%d",
        tostring(emu.getsystemid()), emu.framecount()))
open_logs()

while true do
  local frame = emu.framecount()
  local keys  = input.get() or {}

  if keys[RESET_KEY] then
    reset_logs()
    append(file_game, string.format("### F11 reset frame=%d", frame))
  end

  local now = update_buttons()
  update_stick(now)
  log_frame(now)

  local sys = tostring(emu.getsystemid())
  if sys ~= "NULL" then
    if DOMAIN == nil then next_domain() end
    if dir_ready() then
      bad_scans = 0
      if log_wait ~= "ready" then
        append(file_game, string.format("### directorio inicializado frame=%d dominio=%s",
                frame, tostring(DOMAIN)))
        log_wait = "ready"
      end
      if frame % 30 == 0 then
        local curkey = set_key()
        local timer  = (frame - last_dump_fr) >= 60
        if curkey ~= last_setkey or timer then
          last_setkey  = curkey
          last_dump_fr = frame
          dump_directory("")
        end
      end
    else
      bad_scans = bad_scans + 1
      if log_wait ~= "wait" then
        append(file_game, string.format("### esperando directorio (dominio=%s) frame=%d",
                tostring(DOMAIN), frame))
        log_wait = "wait"
      end
      -- tras ~2s sin leer bien el directorio, probar otro dominio
      if bad_scans > 120 then
        bad_scans = 0
        next_domain()
      end
    end
  else
    if log_wait ~= "norom" then
      append(file_game, "### dominio de memoria NO disponible (sin ROM). Esperando...")
      log_wait = "norom"
    end
    DOMAIN = nil
    domains = {}
  end

  local ss_down = keys[SS_KEY] == true
  if ss_down and not last_ss then
    take_capture()        -- disparo por flanco: 1 captura por pulsacion, sin duplicados
  end
  last_ss = ss_down

  emu.frameadvance()
end
