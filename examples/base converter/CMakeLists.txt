cmake_minimum_required(VERSION 3.15)
project(MyProject CXX)

set(CMAKE_CXX_STANDARD 20)

# Find the installed imeth library
find_package(imeth REQUIRED)

add_executable(base_converter main.cpp)

# Link against imeth
target_link_libraries(base_converter PRIVATE imeth::imeth)
