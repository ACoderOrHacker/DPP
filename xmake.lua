-- D++ Build & Package Script

set_project("DPP")
set_xmakever("2.2.2")

add_rules("mode.debug", "mode.release") -- debug mode and release mode
set_languages("c++20") -- set c++ standard
add_defines("_DXX_EXPORT") -- for export

-- requires
--add_requires("cli11") , "antlr4-runtime"
add_requires("cli11", "nlohmann_json", "termcolor", "vcpkg::antlr4")

if is_mode("debug") then
    -- for tests and benchmarks
    add_requires("gtest", "benchmark")
end

-- include directories
add_includedirs("include", "src", "src/compiler/antlr4",  "src/main")

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
    add_packages("cli11")
    add_deps("compiler", "vm")
target_end()

target("debug")
    set_kind("binary")
    add_files("src/main/debug.cpp")
    add_deps("compiler", "vm")
target_end()
