-- D++ Build & Package Script
set_xmakever("2.9.3")

set_project("D++")
set_version("0.1.2")

includes("@builtin/xpack")

add_rules("mode.debug", "mode.release") -- debug mode and release mode
set_languages("c++17") -- set c++ standard
add_defines("_DXX_EXPORT") -- for export
add_defines("Dpp_USING_STRING") -- for string

--local vs_runtime_MD = is_mode("debug") and "MDd" or "MD"
--set_runtimes(vs_runtime_MD)

set_configdir("include")
add_configfiles("include/config.h.in")

-- requires
add_requires("antlr4-runtime 4.13.2")
add_requires("antlr4 4.13.2")
add_requires("cxxopts 3.2.1")
add_requires("cereal 1.3.2")
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

    add_deps("compiler", "vm")
    add_packages("cxxopts", "cereal")

    add_installfiles("$(projectdir)/include/*", {prefixdir = "include"})
	add_installfiles("$(projectdir)/include/dpp/*", {prefixdir = "include/dpp"})
    add_installfiles("$(projectdir)/examples/*", {prefixdir = "examples"})
    add_installfiles("$(projectdir)/CHANGELOG.md")
    add_installfiles("$(projectdir)/LICENSE")
    add_installfiles("$(projectdir)/README.md")
target_end()

target("tests")
    set_kind("binary")
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
    set_formats("zip", "targz", "nsis", "runself", "deb", "rpm", "srpm")

    set_basename("dpp-$(version)-$(plat)-$(arch)")

    -- set base information
    set_homepage("https://ACoderOrHacker.github.io/DPP")
    set_description("A Programming Language based on c++17")
    set_author("ACoderOrHacker")
    set_license("MIT")
    set_licensefile("LICENSE")
    set_title("D++ Programming Language")

    add_sourcefiles("$(projectdir)/(src/*)")
    add_sourcefiles("$(projectdir)/(include/*)")
    add_sourcefiles("$(projectdir)/examples/*")
    add_sourcefiles("$(projectdir)/CHANGELOG.md")
    add_sourcefiles("$(projectdir)/LICENSE")
    add_sourcefiles("$(projectdir)/README.md")

    -- set install targets
    add_targets("dpp", "vm", "compiler")

    -- std libraries
    add_targets("io")
xpack_end()
