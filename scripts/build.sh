#!/bin/sh
set -eu

cd -- "$(dirname -- "$0")/.."

CXX=${CXX:-g++}
if ! command -v "$CXX" >/dev/null 2>&1; then
    printf 'Error: C++ compiler "%s" not found. Install GCC/Clang or set CXX.\n' "$CXX" >&2
    exit 1
fi

mkdir -p build
"$CXX" -std=c++17 -Wall -Wextra -pedantic -O2 \
    src/main.cpp src/chip8.cpp -o build/chip8

printf 'Built build/chip8\n'
