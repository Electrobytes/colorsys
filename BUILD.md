# BUILD

## Table of Contents

- Installing Dependencies
- Build with CMake

## Installing Dependencies

If your distro isn't listed, please do check if the dependencies are available to its corresponding package manager or use the package names of which your distro is derived from.

### Ubuntu/Debian
- libftxui-dev
- libfmt-dev

### Fedora
- ftxui-devel
- fmt-devel

### Arch Linux
- fmt
- *ftxui is not available*

### vcpkg
- fmt
- ftxui

## Build
```
git clone https://github.com/Electrobytes/colorsys.git

cd colorsys

cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
# Change 'Release' with 'Debug' if you want to contribute to the project.

cmake --build build --target all --clean-first
# You may add '-j' and a number to split the compilation to multiple jobs, speeding up the process.

```
Lastly, the binary is located in out/bin.