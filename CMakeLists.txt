# Make the D++ project, Copyright see LICENSE

cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(D++ VERSION 0.1 LANGUAGES CXX)

# You can use "-DBOOST_ROOT=(Your Boost Root Path)" to set the boost root
set(Boost_ROOT D:\\boost)
cmake_policy(SET CMP0074 NEW)
find_package(Boost REQUIRED COMPONENTS serialization)
message(STATUS "Found Boost Headers: ${Boost_INCLUDE_DIRS}")
message(STATUS "Found Boost Libraries: ${Boost_LIBRARY_DIRS}")


if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/bin)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
endif()

# configure the c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Configuration the c standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# D++ Configurations
set(DXX_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(DXX_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DXX_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DXX_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DXX_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH DXX_BINARY_DIR)
set(DXX_VERSION_MAJOR 0)
set(DXX_VERSION_MINOR 1)

include_directories(PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/
                           ${CMAKE_CURRENT_SOURCE_DIR}/include/antlr4-runtime/
                           ${CMAKE_CURRENT_SOURCE_DIR}/src/runtime/
                           ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/antlr4/
                           ${Boost_INCLUDE_DIRS})

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
