# Make the D++ project, Copyright see LICENSE

cmake_minimum_required(VERSION 3.10)

# Create 'compile_commands.json'
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(DPP VERSION 0.1 LANGUAGES CXX)

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/bin)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message(STATUS "Found MSVC Compiler, add compile option: /utf-8")
    add_compile_options(/utf-8)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug Mode")
    add_definitions(-D_COMPILE_TEST)
else()
    message(STATUS "Release Mode")
endif()

# configure the c++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Configuration the c standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# D++ Configurations
set(DXX_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/antlr4/)
set(DXX_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DXX_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DXX_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DXX_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH DXX_BINARY_DIR)
set(DXX_VERSION_MAJOR 0)
set(DXX_VERSION_MINOR 1)

# This policy must need because the CLion is need that
# I don't know why

if(CLION_IDE)
    cmake_policy(SET CMP6666 NEW)
endif()

# You can set the env variable 'Boost_ROOT' to help cmake find boost
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} $ENV{Boost_ROOT})
set(ANTLR4_JAR D:/Antlr4/antlr4.13.1-complete.jar)
set(Boost_ROOT D:/boost)

cmake_policy(SET CMP0074 NEW)
if (${CMAKE_VERSION} VERSION_GREATER_EQUAL 3.27)
    cmake_policy(SET CMP0144 NEW)
endif()

find_package(Boost REQUIRED COMPONENTS serialization program_options)
message(STATUS "Found Boost Headers: ${Boost_INCLUDE_DIRS}")
message(STATUS "Found Boost Libraries: ${Boost_LIBRARY_DIRS}")

set(FMT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/fmt/)
message(STATUS "{fmt}: ${FMT_DIR}")
add_subdirectory(${FMT_DIR} EXCLUDE_FROM_ALL)

set(INC_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/antlr4/antlr4-runtime/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/runtime/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/antlr4/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Serialization/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main/
        ${CMAKE_CURRENT_SOURCE_DIR}/src/
        ${Boost_INCLUDE_DIRS}/
        ${FMT_DIR}/include/)

include_directories(PUBLIC ${INC_DIRS})

link_directories(${Boost_LIBRARY_DIRS})

option(BUILD_TOOLS "-----Build The Tools-----" ON)
option(BUILD_TESTS "-----Build The Tests-----" ON)
option(BUILD_VM_SERIALIZATION "-----Build The Serialization-----" ON)

if(BUILD_TOOLS)
    # build the tools

endif()

if(BUILD_TESTS)
    # build the tests
    add_subdirectory(src/runtime/test/)
endif()

add_subdirectory(src/)
