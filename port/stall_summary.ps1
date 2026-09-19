# stall_summary.ps1 - Resumen de una pasada de port\run_stall_check.bat (via de los stalls).
# Uso: powershell -NoProfile -ExecutionPolicy Bypass -File stall_summary.ps1 <carpeta_logs>
# Genera <carpeta_logs>\stall_summary.txt y lo imprime por consola.
param(
    [Parameter(Mandatory = $true)][string]$Dir
)

$ErrorActionPreference = 'SilentlyContinue'
try { [System.Threading.Thread]::CurrentThread.CurrentCulture = [System.Globalization.CultureInfo]::InvariantCulture } catch {}

$lines = New-Object System.Collections.Generic.List[string]
function Add-Line([string]$s) { [void]$lines.Add($s) }

function Read-Log([string]$name) {
    $p = Join-Path $Dir $name
    if (Test-Path -LiteralPath $p) { return @(Get-Content -LiteralPath $p) }
    return @()
}

Add-Line '=== STALL CHECK - resumen de la pasada ==='
Add-Line ("carpeta : " + $Dir)
Add-Line ("fecha   : " + (Get-Date).ToString('yyyy-MM-dd HH:mm:ss'))
Add-Line ''

# --- hh_tick.log: cuantizacion por tick (dN = ticks que abarcan N VI) ---
$tick = Read-Log 'hh_tick.log'
Add-Line '--- hh_tick.log: cuantizacion por tick (dN = ticks que abarcan N VI) ---'
if (@($tick).Count -eq 0) {
    Add-Line '  (sin datos)'
}
else {
    [long]$d1 = 0; [long]$d2 = 0; [long]$d3 = 0; [long]$d4 = 0
    [double]$maxdt = 0; [int]$secs = 0
    foreach ($l in $tick) {
        if ($l -match 'd1=(\d+) d2=(\d+) d3=(\d+) d4\+=(\d+) max_dt=([0-9.]+)ms') {
            $d1 += [long]$Matches[1]; $d2 += [long]$Matches[2]
            $d3 += [long]$Matches[3]; $d4 += [long]$Matches[4]
            if ([double]$Matches[5] -gt $maxdt) { $maxdt = [double]$Matches[5] }
            $secs++
        }
    }
    $tot = $d1 + $d2 + $d3 + $d4
    Add-Line ("  segundos={0}  ticks={1}  max_dt={2} ms" -f $secs, $tot, $maxdt)
    if ($tot -gt 0) {
        $p1 = [math]::Round(100.0 * $d1 / $tot, 1)
        $p2 = [math]::Round(100.0 * $d2 / $tot, 1)
        $p3 = [math]::Round(100.0 * $d3 / $tot, 1)
        $p4 = [math]::Round(100.0 * $d4 / $tot, 1)
        Add-Line ("  d1={0} ({1}%)  d2={2} ({3}%)  d3={4} ({5}%)  d4+={6} ({7}%)" -f $d1, $p1, $d2, $p2, $d3, $p3, $d4, $p4)
        if (($d3 + $d4) -gt 0) {
            Add-Line ("  AVISO: {0} ticks ({1}%) no caben en 1 tick/2 VI (3+ VI)." -f ($d3 + $d4), [math]::Round(100.0 * ($d3 + $d4) / $tot, 1))
        }
    }
}
Add-Line ''

# --- hh_framelog.log: por tick (t_s dt_ms vi dvi guest_busy_ms) ---
$fr = Read-Log 'hh_framelog.log'
Add-Line '--- hh_framelog.log: por tick (t_s dt_ms vi dvi guest_busy_ms) ---'
if (@($fr).Count -eq 0) {
    Add-Line '  (sin datos; lo activa este .bat con HH_FRAMELOG=1)'
}
else {
    [int]$n = 0; [int]$nOver33 = 0; [int]$nOver36 = 0
    [double]$sumDt = 0; [double]$maxDt = 0
    [long]$f1 = 0; [long]$f2 = 0; [long]$f3 = 0; [long]$f4 = 0
    [long]$prevVi = -1
    [long]$sumBusy = 0; [long]$maxBusy = 0; [int]$nBusy = 0
    [long]$sumBusy3 = 0; [int]$nBusy3 = 0
    [bool]$five = $false
    foreach ($l in $fr) {
        $p = @($l -split '\s+')
        if ($p.Count -lt 3) { continue }
        [double]$dtms = [double]$p[1] / 1000.0
        [long]$vi = [long]$p[2]
        $sumDt += $dtms
        if ($dtms -gt $maxDt) { $maxDt = $dtms }
        if ($dtms -gt 33.3) { $nOver33++ }
        if ($dtms -gt 36.0) { $nOver36++ }
        $n++
        [long]$dvi = 0
        if ($p.Count -ge 5) {
            $five = $true
            $dvi = [long]$p[3]
            [long]$busy = [long]$p[4]
            $sumBusy += $busy; $nBusy++
            if ($busy -gt $maxBusy) { $maxBusy = $busy }
            if ($dvi -ge 3) { $sumBusy3 += $busy; $nBusy3++ }
        }
        elseif ($prevVi -ge 0 -and $vi -ge $prevVi) {
            $dvi = $vi - $prevVi
        }
        $prevVi = $vi
        if ($dvi -eq 1) { $f1++ }
        elseif ($dvi -eq 2) { $f2++ }
        elseif ($dvi -eq 3) { $f3++ }
        elseif ($dvi -ge 4) { $f4++ }
    }
    if ($n -gt 0) {
        Add-Line ("  ticks={0}  dt medio={1} ms  dt>33.3ms={2}  dt>36ms={3}  dt max={4} ms" -f $n, [math]::Round($sumDt / $n, 2), $nOver33, $nOver36, [math]::Round($maxDt, 1))
        Add-Line ("  dvi (VI por tick): d1={0}  d2={1}  d3={2}  d4+={3}" -f $f1, $f2, $f3, $f4)
        if (($f3 + $f4) -gt 0) {
            Add-Line ("  AVISO: {0} ticks ({1}%) abarcan 3+ VI." -f ($f3 + $f4), [math]::Round(100.0 * ($f3 + $f4) / $n, 1))
        }
        if ($five -and ($nBusy -gt 0)) {
            Add-Line ("  guest_busy/tick: medio={0} ms  max={1} ms" -f [math]::Round($sumBusy / $nBusy, 1), $maxBusy)
            if ($nBusy3 -gt 0) {
                Add-Line ("  guest_busy en ticks de 3+ VI: medio={0} ms  (n={1})" -f [math]::Round($sumBusy3 / $nBusy3, 1), $nBusy3)
            }
        }
        else {
            Add-Line '  NOTA: el binario no vuelca dvi/guest_busy en hh_framelog (recompila con build_windows.local.bat).'
        }
    }
    else {
        Add-Line '  (fichero sin lineas validas)'
    }
}
Add-Line ''

# --- hh_slow.log: ticks >36 ms con desglose ---
$slow = Read-Log 'hh_slow.log'
Add-Line '--- hh_slow.log: ticks >36 ms (desglose) ---'
if (@($slow).Count -eq 0) {
    Add-Line '  (sin ticks >36 ms)'
}
else {
    [int]$n = 0; [long]$s1 = 0; [long]$s2 = 0; [long]$s3 = 0; [long]$s4 = 0
    [long]$sumBusy = 0; [long]$maxBusy = 0; [int]$minBusy = -1
    [double]$sumDt = 0; [double]$maxDt = 0
    [double]$sumSend = 0; [double]$maxSend = 0
    [double]$sumUpd = 0; [double]$maxUpd = 0
    [long]$maxPend = 0
    foreach ($l in $slow) {
        if ($l -match 'dt=([0-9.]+)ms dvi=(\d+) send_dl=([0-9.]+)ms update_screen=([0-9.]+)ms guest_busy=(\d+)ms pending_ext=(\d+)') {
            [double]$dt = [double]$Matches[1]
            [long]$dvi = [long]$Matches[2]
            [double]$sd = [double]$Matches[3]
            [double]$us = [double]$Matches[4]
            [long]$busy = [long]$Matches[5]
            [long]$pend = [long]$Matches[6]
            $n++
            $sumDt += $dt; if ($dt -gt $maxDt) { $maxDt = $dt }
            if ($dvi -eq 1) { $s1++ }
            elseif ($dvi -eq 2) { $s2++ }
            elseif ($dvi -eq 3) { $s3++ }
            elseif ($dvi -ge 4) { $s4++ }
            $sumBusy += $busy
            if ($busy -gt $maxBusy) { $maxBusy = $busy }
            if (($minBusy -lt 0) -or ($busy -lt $minBusy)) { $minBusy = $busy }
            $sumSend += $sd; if ($sd -gt $maxSend) { $maxSend = $sd }
            $sumUpd += $us; if ($us -gt $maxUpd) { $maxUpd = $us }
            if ($pend -gt $maxPend) { $maxPend = $pend }
        }
    }
    if ($n -gt 0) {
        Add-Line ("  n={0}  dvi: d1={1} d2={2} d3={3} d4+={4}" -f $n, $s1, $s2, $s3, $s4)
        Add-Line ("  guest_busy: min={0} medio={1} max={2} ms" -f $minBusy, [math]::Round($sumBusy / $n, 1), $maxBusy)
        Add-Line ("  dt: medio={0} max={1} ms | send_dl: medio={2} max={3} ms | update_screen: medio={4} max={5} ms | pending_ext max={6}" -f [math]::Round($sumDt / $n, 1), [math]::Round($maxDt, 1), [math]::Round($sumSend / $n, 2), [math]::Round($maxSend, 1), [math]::Round($sumUpd / $n, 2), [math]::Round($maxUpd, 1), $maxPend)
    }
    else {
        Add-Line '  (lineas no reconocidas)'
    }
}
Add-Line ''

# --- hh_slice.log: muestras de stalls ---
$slice = Read-Log 'hh_slice.log'
Add-Line '--- hh_slice.log: stalls (polls parados >200 ms) ---'
if (@($slice).Count -eq 0) {
    Add-Line '  (sin datos)'
}
else {
    $stalls = @($slice | Where-Object { $_ -like '=== stall*' })
    Add-Line ("  muestras de stall: {0}" -f @($stalls).Count)
    if (@($stalls).Count -gt 0) {
        Add-Line ("  ultimo: " + $stalls[-1])
    }
    Add-Line '  ultimas 6 lineas:'
    foreach ($l in @($slice | Select-Object -Last 6)) { Add-Line ('    ' + $l) }
}
Add-Line ''

# --- hh_state.log: ultimo snapshot de hilos ---
$state = Read-Log 'hh_state.log'
Add-Line '--- hh_state.log: ultimo snapshot ---'
if (@($state).Count -eq 0) {
    Add-Line '  (sin datos)'
}
else {
    $snaps = @($state | Where-Object { $_ -like '=== HH estado*' })
    if (@($snaps).Count -gt 0) { Add-Line ('  ' + $snaps[-1]) }
    else { Add-Line '  (sin cabeceras de estado)' }
}
Add-Line ''

# --- cuelgue (watchdog) ---
Add-Line '--- cuelgue ---'
$hang = Read-Log 'hh_hang.log'
if (@($hang).Count -eq 0) {
    Add-Line '  hh_hang.log: no (el watchdog no detecto cuelgue)'
}
else {
    $cuelgues = @($hang | Where-Object { $_ -like '=== HH cuelgue*' })
    Add-Line ("  hh_hang.log: {0} cuelgue(s) detectado(s)" -f @($cuelgues).Count)
    if (@($cuelgues).Count -gt 0) { Add-Line ('  ultimo: ' + $cuelgues[-1]) }
}
Add-Line ''
Add-Line 'Fin del resumen.'

$out = Join-Path $Dir 'stall_summary.txt'
Set-Content -LiteralPath $out -Value $lines -Encoding UTF8
Write-Host ("Resumen escrito en: " + $out)
