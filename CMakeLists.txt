cmake_minimum_required(VERSION 3.15)
project(imeth LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ======================
# Main library
# ======================
add_library(imeth STATIC
    src/algebra.cpp
    src/matrix.cpp
    src/shape_2d.cpp
    src/shape_3d.cpp
)

# Proper include handling (for both build & install)
target_include_directories(imeth
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# ======================
# Installation
# ======================
include(GNUInstallDirs)

install(
    TARGETS imeth
    EXPORT imethTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    DIRECTORY include/imeth/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/imeth
)

install(
    EXPORT imethTargets
    FILE imethConfig.cmake
    NAMESPACE imeth::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/imeth
)

# ======================
# Test executable
# ======================
add_executable(imeth_test tests/main.cpp)

target_link_libraries(imeth_test PRIVATE imeth)

# Add include dir for test only
target_include_directories(imeth_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
