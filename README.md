# File Encryption/Decryption

A small C++ CLI that encrypts and decrypts text files. It now supports both a classic Caesar cipher (fixed +3 shift) and a spiral route cipher with a user-provided column key. The codebase is organized with SOLID-inspired classes so each concern (cipher logic, file I/O, orchestration) stays isolated.

## Features

- Choose to encrypt or decrypt an existing file in place.
- Pick the cipher: Caesar (+3) or Route (columnar spiral). Route cipher uppercases, strips non-letters, and pads with `X` to fill the grid.
- Input validation for file paths and route cipher keys.

## Project Layout

- [src/Main.cpp](src/Main.cpp): CLI orchestration and user prompts.
- [include/Cipher.h](include/Cipher.h): Abstract cipher interface.
- [include/CaesarCipher.h](include/CaesarCipher.h) / [src/CaesarCipher.cpp](src/CaesarCipher.cpp): Caesar implementation.
- [include/RouteCipher.h](include/RouteCipher.h) / [src/RouteCipher.cpp](src/RouteCipher.cpp): Route cipher implementation and spiral logic.
- [include/FileService.h](include/FileService.h) / [src/FileService.cpp](src/FileService.cpp): File I/O helpers.

## Build and Run

### Option 1: CMake (recommended)

If you see an error mentioning `nmake` on Windows, it means CMake picked an NMake generator but the build tools aren't installed/configured. Use one of the explicit commands below.

If you see `CMAKE_CXX_COMPILER not set`, you don't have a C++ compiler installed (or it's not on PATH). Install one of:

- **Visual Studio Build Tools** (MSVC) + "Desktop development with C++" workload, then use the `msvc` preset.
- **MSYS2/MinGW-w64** (g++), then use the `mingw` preset.
- **Ninja** + a compiler (MSVC or MinGW), then use the `ninja` preset.

### MSYS2 (your setup)

Your system has `g++` under `C:\msys64\mingw64\bin`, but CMake also needs a build tool like `mingw32-make.exe`.

Open **MSYS2 MinGW x64** and run:

```bash
pacman -S --needed mingw-w64-x86_64-toolchain mingw-w64-x86_64-make
```

Then back in PowerShell:

```bash
cmake --preset mingw
cmake --build --preset mingw
```

#### Using presets (easiest)

This repo includes [CMakePresets.json](CMakePresets.json):

```bash
cmake --preset mingw
cmake --build --preset mingw
```

If you don't have `mingw32-make.exe` installed, you can use the MSYS2 `make.exe` instead:

```bash
cmake --preset msys
cmake --build --preset msys
```

Or:

```bash
cmake --preset msvc
cmake --build --preset msvc
```

#### Without presets

```bash
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
```

Run:

- Windows (PowerShell): `./build/Debug/file-crypto.exe` or `./build/Release/file-crypto.exe` (depends on config)
- Linux/macOS: `./build/file-crypto`

### Option 2: Single command (g++)

```bash
g++ -std=c++17 -O2 -I include src/Main.cpp src/CaesarCipher.cpp src/RouteCipher.cpp src/FileService.cpp -o file-crypto
./file-crypto
```

## Usage

1. Choose Encrypt/Decrypt.
2. Select a cipher.
3. If Route cipher is selected, enter the positive column count (secret key).
4. Provide the file path. The tool reads, transforms, and overwrites the same file.

## Contributing

Fork, branch, and open a PR. Please keep new features modular and covered by small examples or notes in the README.
