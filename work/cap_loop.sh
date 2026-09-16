#!/bin/sh
# cap_loop.sh SESSION_DIR [DISPLAY]
# Captura 1 frame cada 4s. SOLO guarda frames con cambio material (dedupe):
# - negros (mean=0,std=0) y frames identicos al ultimo guardado se ignoran.
# Mantiene <SESH>/live.ppm + work/debug/latest_ascii.txt + work/debug/latest_stats.txt.
SESH="$1"
D="${2:-:99}"
# Raiz del repo derivada de la ubicacion del propio script (work/ -> raiz).
ROOT="$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)"
mkdir -p "$SESH"
n=0
LAST=""
while true; do
  TMP="$(mktemp "$ROOT/work/debug/cap.XXXXXX.ppm")"
  "$ROOT/tools/analysis/xshot" "$D" "$TMP" >/dev/null 2>&1
  mv "$TMP" "$SESH/live.ppm"
  PNG="$SESH/live.png"
  convert "$SESH/live.ppm" "$PNG" 2>/dev/null
  STAT="$(convert "$PNG" -format "%k %[fx:int(mean*255)] %[fx:int(standard_deviation*255)]" info: 2>/dev/null)"
  MEAN="$(echo "$STAT" | awk '{print $2}')"
  STD="$(echo "$STAT" | awk '{print $3}')"
  DIFF=9999999
  if [ -n "$LAST" ] && [ -f "$LAST" ]; then
    AE="$(compare -metric AE "$LAST" "$PNG" null: 2>&1)"
    DIFF="${AE:-9999999}"
  fi
  STORED=0
  if [ "${MEAN:-1}" = "0" ] && [ "${STD:-1}" = "0" ]; then
    : # black -> ignore
  elif [ "$DIFF" -gt 20000 ] || [ -z "$LAST" ]; then
    N="$(printf '%04d' "$n")"
    cp "$SESH/live.ppm" "$SESH/$N.ppm"
    cp "$SESH/live.png" "$SESH/$N.png"
    LAST="$SESH/$N.png"
    n=$((n+1))
    STORED=1
  fi
  python3 "$ROOT/tools/analysis/ppmascii.py" "$SESH/live.ppm" 88 > "$ROOT/work/debug/latest_ascii.txt" 2>/dev/null
  echo "mean=$MEAN std=$STD colors=$(echo "$STAT" | awk '{print $1}') diff=$DIFF stored_sofar=$n stored_now=$STORED" > "$ROOT/work/debug/latest_stats.txt"
  sleep 4
done
