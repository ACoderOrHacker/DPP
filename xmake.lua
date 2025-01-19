-- D++ Build & Package Script
set_xmakever("2.9.3")

set_project("D++")
set_version("0.1.0")

includes("@builtin/xpack")

add_rules("mode.debug", "mode.release") -- debug mode and release mode
set_languages("c++17") -- set c++ standard
add_defines("_DXX_EXPORT") -- for export

set_configdir("include")
add_configfiles("include/config.h.in")

-- requires
add_requires("cereal 1.3.2", "cxxopts 3.2.1", "antlr4-runtime 4.13.2", "antlr4 4.13.2")
-- add_requires("termcolor 2.1.0")
add_requires("doctest 2.4.11")

-- include directories
add_includedirs("include", "src")

set_optimize("fastest")

target("vm")
    set_kind("shared")
    add_files("src/runtime/*.cpp")

    add_packages("cereal")
target_end()

target("compiler")
    set_kind("shared")
    add_files("src/compiler/*.cpp")
    add_files("src/compiler/templates/*.g4")

    add_rules("@antlr4/lexer", "@antlr4/parser", {visitor = true, listener = false})
    add_deps("vm")
    add_packages("antlr4-runtime", "antlr4", "cereal")
target_end()

target("dpp")
    set_kind("binary")
    add_files("src/main/dpp.cpp")
    add_headerfiles("include/*")

    add_deps("compiler", "vm")
    add_packages("cxxopts", "cereal")
target_end()

target("tests")
    add_files("src/tests/*.cpp")

    add_deps("compiler", "vm")
    add_packages("doctest", "cereal")
target_end()

target("io")
    set_kind("shared")
    add_files("src/std/io/*.cpp")

    add_deps("vm")
    add_packages("cereal")
target_end()

xpack("dpp")
    -- set formats
    set_formats("zip", "targz", "nsis", "runself")

    set_basename("dpp-$(version)-$(plat)-$(arch)")

    -- set base information
    set_homepage("https://ACoderOrHacker.github.io/DPP")
    set_description("A Programming Language based on c++17")
    set_author("ACoderOrHacker")
    set_license("MIT")
    set_licensefile("LICENSE")
    set_title("D++ Programming Language")

    -- set install targets
    add_targets("dpp", "vm", "compiler")
    add_installfiles("include/*", {prefixdir = "include"})
    add_installfiles("include/dpp/*", {prefixdir = "include/dpp"})
    add_installfiles("CHANGELOG")
    add_installfiles("LICENSE")
    add_installfiles("README.md")

    -- std libraries
    add_targets("io", {prefixdir = "libs"})
xpack_end()
