# Usage

## Using with CMake (Recommended)

In your project's `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.15)
project(MyProject CXX)

set(CMAKE_CXX_STANDARD 20)

# Find the installed imeth library
find_package(imeth REQUIRED)

add_executable(my_app main.cpp)

# Link against imeth
target_link_libraries(my_app PRIVATE imeth::imeth)
```

Then build:
```shell
cmake -B build
cmake --build build
```

## Using with Compiler Directly

After installation, compile your code with:

```shell
# Using g++
g++ -std=c++20 your_code.cpp -I/usr/local/include -L/usr/local/lib -limeth -o your_program

# Using clang++
clang++ -std=c++20 your_code.cpp -I/usr/local/include -L/usr/local/lib -limeth -o your_program
```
