# CHIP-8 Emulator

An educational CHIP-8 emulator project, written in C++.

The project is currently in its early stages. The goal is to build the emulator step by step as a learning exercise without using AI or relying on vibe coding.

## Current stage

Basic machine state, fetch, reset and ROM loading with size and read validation implemented. Instruction execution is not implemented yet.

## Build

Requires a C++17 compiler: GCC or Clang on Unix; MinGW-w64 GCC or Clang on Windows.
The compiler must be available in your `PATH`. The scripts use `g++` by default.
Set `CXX` to `clang++` to use Clang, or to another compatible compiler executable.

Unix:

```sh
./scripts/build.sh
./build/chip8
```

Windows (Command Prompt):

```bat
scripts\build.bat
build\chip8.exe
```

Build scripts can be invoked from any directory. Run the executable from the
project root so it can find the ROM in `roms/`. Build output is ignored by Git.


## License

The emulator code is licensed under the [MIT License](LICENSE).
The bundled Timendus test ROM and its source are licensed separately under the
GNU GPL v3; see [roms/README.md](roms/README.md).
