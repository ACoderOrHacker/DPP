-- D++ Build & Package Script
set_xmakever("2.2.2")

set_project("DPP")
set_version("0.1.0")

includes("@builtin/xpack")

add_rules("mode.debug", "mode.release") -- debug mode and release mode
set_languages("c++20") -- set c++ standard
add_defines("_DXX_EXPORT") -- for export

-- requires
add_requires("cereal", "cli11", "nlohmann_json", "termcolor")
add_requires("vcpkg::antlr4", {configs = {shared = true}})

if is_mode("debug") then
    -- for tests and benchmarks
    add_requires("gtest", "benchmark")
end

-- include directories
add_includedirs("include", "src", "src/compiler/antlr4",  "src/main", "include/antlr4")

set_optimize("fastest")

target("vm")
    set_kind("shared")
    add_files("src/runtime/*.cpp")

    add_packages("cereal", "termcolor")
target_end()

target("compiler")
    set_kind("shared")
    add_files("src/compiler/*.cpp", "src/compiler/antlr4/*.cpp")

    add_deps("vm")
    add_packages("vcpkg::antlr4", "cereal", "termcolor")
target_end()

target("dpp")
    set_kind("binary")
    add_files("src/main/dpp.cpp")

    add_deps("compiler", "vm")
    add_packages("cli11", "termcolor", "cereal", "nlohmann_json")
target_end()

target("debug")
    set_kind("binary")
    add_files("src/main/debug.cpp")
    add_deps("compiler", "vm")
target_end()

xpack("DPP")
    -- set formats
    if is_os("windows") then
        set_formats("zip", "targz", "runself", "nsis")
    else
        set_formats("zip", "targz", "runself")
    end

    -- set base information
    set_homepage("https://ACoderOrHacker.github.io/DPP")
    set_description("A Programming Language based on c++20")
    set_author("ACoderOrHacker")
    set_license("MIT")
    set_licensefile("LICENSE")
    set_title("D++ Programming Language")

    -- set install targets
    add_targets("dpp", "debug", "vm", "compiler")
    add_installfiles("include/*", {prefixdir = "include"})
    add_installfiles("include/acoder/*", {prefixdir = "include/acoder"})
    add_installfiles("include/dpp/*", {prefixdir = "include/dpp"})    --[[
    add_installfiles("include/antlr")--]]
xpack_end()