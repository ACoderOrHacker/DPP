# Make the D++ project, Copyright see LICENSE

# This is a sub cmake file

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/wd4251)
    # disable warning C4251: <type>: <member>: class <class> needs to have dll-interface to be used by clients of struct <struct>
    add_compile_options(/wd4275)
    # disable warning C4275: <derived>: '<base>' : dependent name is not a type
endif()

add_custom_target(BUILD_GRAMMAR
                  COMMAND antlr4 -visitor -no-listener templates/DXXLexer.g4 templates/DXXParser.g4 -o antlr4/)

#file(GLOB COMPILER_FILES compiler/*.cpp)
#add_library(compiler SHARED ${COMPILER_FILES})
#find_library(COMPILER_LIB antlr4-runtime ${DXX_LIBRARY_DIR})
#target_link_libraries(compiler ${COMPILER_LIB})

# Make shared library
file(GLOB VM_FILES runtime/*.cpp)
add_library(vm SHARED ${VM_FILES})

add_executable(dpp dpp.cpp)
target_link_libraries(dpp vm)