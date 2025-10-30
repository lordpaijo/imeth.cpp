# Installation

## Dependencies

- **C++20 Compatible Compilers**
- **CMake V3.15+**
- **Git**

## Clone the Repository

```sh
git clone https://github.com/lordpaijo/imeth.cpp imeth
cd imeth
```

## Build and Install with CMake

### Linux/MacOS

```sh
mkdir build && cd build
cmake ..
make -j
sudo make install
```

This will install:
- Library: `/usr/local/lib/libimeth.a`
- Headers: `/usr/local/include/imeth/`
- CMake config: `/usr/local/lib/cmake/imeth/`

### Windows

Using Visual Studio:
```sh
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
cmake --install . --config Release
```

Or using MinGW:
```sh
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make -j
mingw32-make install
```
