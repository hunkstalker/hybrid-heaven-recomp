# syntax=docker/dockerfile:1
#
# Hybrid Heaven Recomp — imagen Linux (Debian bookworm, glibc).
#
#   deps    : dependencias de compilacion (la usa tambien el devcontainer).
#   build   : usa los submodulos (rt64 upstream + runtime del FORK propio, fijados en
#             runtime.lock como fallback) y compila el port. El C recompilado
#             (build/recomp/RecompiledFuncs/) NO se versiona (ADR 0009): el contexto Docker
#             debe traerlo ya generado (tools/regenerate.py) o montarlo.
#   runtime : solo ejecucion (GUI X11 o headless Xvfb+lavapipe).
#
# La ROM NO se distribuye: monta tu carpeta `rom/` en /work/rom (el binario busca
# `rom/baserom.us.z64` junto a si mismo). Ver README.
#
#   docker build --target runtime -t hybrid-heaven-recomp .
#   docker run --rm -v "$PWD/rom:/work/rom:ro" hybrid-heaven-recomp
#   HH_HEADLESS=1 docker run --rm -v "$PWD/rom:/work/rom:ro" -e HH_HEADLESS=1 hybrid-heaven-recomp

FROM debian:bookworm-slim AS deps
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential cmake ninja-build git ca-certificates pkg-config python3 \
        libsdl2-dev libvulkan-dev \
        libx11-dev libxext-dev libxrandr-dev libxtst-dev \
        libgtk-3-dev \
    && rm -rf /var/lib/apt/lists/*
# git sobre arboles montados (safe.directory para todos los repos)
RUN git config --global --add safe.directory '*'
WORKDIR /src

FROM deps AS build
# Capa cacheable: reproduce las dependencias (rt64 upstream + runtime del fork,
# commits fijados en runtime.lock) sin depender del codigo del port.
COPY tools/build_linux.sh /src/tools/build_linux.sh
COPY runtime.lock /src/runtime.lock
RUN sh /src/tools/build_linux.sh --libs-only
# Codigo del port + build (ver .dockerignore para lo que NO entra en el contexto).
COPY . .
RUN sh tools/build_linux.sh --build-dir build/docker \
    && mkdir -p /out \
    && cp "build/docker/Hybrid Heaven Recomp" /out/hybrid-heaven-recomp

FROM debian:bookworm-slim AS runtime
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
        libsdl2-2.0-0 libgtk-3-0 libvulkan1 mesa-vulkan-drivers \
        libx11-6 libxext6 libxrandr2 libxtst6 \
        xvfb xauth ca-certificates \
    && rm -rf /var/lib/apt/lists/*
COPY --from=build /out/hybrid-heaven-recomp /work/hybrid-heaven-recomp
COPY docker/entrypoint.sh /usr/local/bin/hh-entrypoint
COPY CREDITS.md /usr/local/share/doc/hybrid-heaven-recomp/CREDITOS.md
COPY LICENSE /usr/local/share/doc/hybrid-heaven-recomp/LICENSE
RUN chmod +x /work/hybrid-heaven-recomp /usr/local/bin/hh-entrypoint && mkdir -p /work/rom
WORKDIR /work
ENTRYPOINT ["/usr/local/bin/hh-entrypoint"]
