cmake_minimum_required(VERSION 3.15)
find_package(Git QUIET)
if(GIT_FOUND)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} describe --tags --abbrev=0
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            OUTPUT_VARIABLE GIT_VERSION
            OUTPUT_STRIP_TRAILING_WHITESPACE
            ERROR_QUIET
    )
    if(GIT_VERSION)
        string(REGEX REPLACE "^v" "" GIT_VERSION ${GIT_VERSION})
        project(imeth LANGUAGES CXX VERSION ${GIT_VERSION})
    else()
        project(imeth LANGUAGES CXX VERSION 1.0.0)
    endif()
else()
    project(imeth LANGUAGES CXX VERSION 1.0.0)
endif()
project(imeth LANGUAGES CXX VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ======================
# Main library
# ======================
file(GLOB_RECURSE IMETH_SOURCES
    CONFIGURE_DEPENDS
    "src/*.cpp"
)
add_library(imeth STATIC ${IMETH_SOURCES})

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
