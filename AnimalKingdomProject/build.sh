#!/usr/bin/env bash
set -euo pipefail

# Ensure the script runs from its own directory (the project folder)
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$script_dir"

# Creates the build folder (if missing) and runs CMake + build.
mkdir -p build
cmake -S . -B build
cmake --build build --config Debug
# Binary will be in the build output (e.g. build/ or build/bin/ depending on your CMake settings)