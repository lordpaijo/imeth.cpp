cmake_minimum_required(VERSION 3.15)
project(MyProject CXX)

set(CMAKE_CXX_STANDARD 20)

# Find the installed imeth library
find_package(imeth REQUIRED)

add_executable(shapes main.cpp)

# Link against imeth
target_link_libraries(shapes PRIVATE imeth::imeth)
