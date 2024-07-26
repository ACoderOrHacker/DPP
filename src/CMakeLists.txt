# Make the D++ project, Copyright see LICENSE

# This is a sub cmake file

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/wd4251)
    # disable warning C4251: <type>: <member>: class <class> needs to have dll-interface to be used by clients of struct <struct>
    add_compile_options(/wd4275)
    # disable warning C4275: <derived>: '<base>' : dependent name is not a type
endif()

# Make shared library
file(GLOB VM_FILES runtime/*.cpp runtime/*.hpp runtime/*.h)
if (BUILD_VM_SERIALIZATION)
    message(STATUS "Build The Serialization")

    file(GLOB SERIALIZATION_FILES serialization/*.cpp)
    add_library(vm SHARED ${VM_FILES} ${ACASSERT_FILES} ${SERIALIZATION_FILES})
    target_link_libraries(vm Boost::serialization)
else ()
    add_library(vm SHARED ${VM_FILES} ${ACASSERT_FILES})
endif ()

set(GRAMMAR_WORKING_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/)
message(STATUS "Starting build grammar, Working directory: ${GRAMMAR_WORKING_DIR}")
add_custom_target(BUILD_GRAMMAR
                  COMMAND java -jar ${ANTLR4_JAR} %* -visitor -no-listener templates/DXXLexer.g4 templates/DXXParser.g4 -o /antlr4/
                  WORKING_DIRECTORY ${GRAMMAR_WORKING_DIR})
message(STATUS "Ending build grammar")

file(GLOB COMPILER_FILES compiler/*.cpp
        compiler/*.hpp
        compiler/*.h
        compiler/antlr4/*.cpp
        compiler/antlr4/*.hpp
        compiler/antlr4/*.h)
add_library(compiler SHARED ${COMPILER_FILES} ${ACASSERT_FILES})
target_link_libraries(compiler antlr4_shared vm fmt::fmt-header-only)

add_executable(dpp main/dpp.cpp ${ACASSERT_FILES})
target_link_libraries(dpp vm compiler fmt::fmt-header-only Boost::program_options Boost::filesystem)

add_executable(debug main/debug.cpp main/modules.h ${ACASSERT_FILES})
target_link_libraries(debug vm fmt::fmt-header-only Boost::filesystem)