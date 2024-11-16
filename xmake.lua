-- D++ Build & Package Script

set_project("DPP")
set_xmakever("2.2.2")

-- debug mode and release mode
add_rules("mode.debug", "mode.release")
set_languages("c++20")
add_defines("_DXX_EXPORT") -- for export

-- requires
--add_requires("nlohmann_json", "termcolor", "antlr4-runtime", "gtest", "benchmark")

-- include directories
add_includedirs("include", "include/antlr4", "src", "src/compiler/antlr4",  "src/main")
add_includedirs("D:\\vcpkg\\installed\\x64-windows\\include")

set_optimize("fastest")

target("vm")
    set_kind("shared")
    add_files("src/runtime/*.cpp")
target_end()

target("compiler")
    set_kind("shared")
    add_files("src/compiler/*.cpp")
    add_deps("vm")
target_end()

target("dpp")
    set_kind("binary")
    add_files("src/main/dpp.cpp")
    add_deps("compiler", "vm")
target_end()

target("debug")
    set_kind("binary")
    add_files("src/main/debug.cpp")
    add_deps("compiler", "vm")
target_end()
