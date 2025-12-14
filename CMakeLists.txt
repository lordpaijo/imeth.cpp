cmake_minimum_required(VERSION 3.15)

# ======================
# Version detection
# ======================
find_package(Git QUIET)

set(IMETH_VERSION "1.0.0")

if(GIT_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} describe --tags --abbrev=0
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
    if(GIT_VERSION)
        string(REGEX REPLACE "^v" "" IMETH_VERSION "${GIT_VERSION}")
    endif()
endif()

project(imeth VERSION ${IMETH_VERSION} LANGUAGES CXX)

# ======================
# Build settings
# ======================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ======================
# Library
# ======================
file(GLOB_RECURSE IMETH_SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_library(imeth STATIC ${IMETH_SOURCES})

add_library(imeth::imeth ALIAS imeth)

target_include_directories(imeth
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# ======================
# Installation
# ======================
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(
    TARGETS imeth
    EXPORT imethTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT imethTargets
    NAMESPACE imeth::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/imeth
)

# ======================
# Config files
# ======================
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/imethConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/imethConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/imeth
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/imethConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/imethConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/imethConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/imeth
)

# ======================
# Tests (build-only)
# ======================
add_executable(imeth_test tests/main.cpp)
target_link_libraries(imeth_test PRIVATE imeth)
