-- D++ Build & Package Script
set_xmakever("2.9.3")

set_project("D++")
set_version("0.1.4")

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
    add_installfiles("$(projectdir)/scripts/*", {prefixdir = "scripts"})
    add_installfiles("$(projectdir)/CHANGELOG.md")
    add_installfiles("$(projectdir)/LICENSE")
    add_installfiles("$(projectdir)/README.md")

    after_build(function (target)
        os.rm("$(buildir)/$(plat)/$(arch)/*.dppo")
        for _, file in ipairs("$(projectdir)/examples/*.dpp") do
            os.cp(file, "$(buildir)/$(plat)/$(arch)/" .. (is_mode("debug") and "debug/" or "release/"))
        end
    end)

    add_tests("test-enum-compile", {runargs = {"-c", "enum.dpp"}})
    add_tests("test-enum-run", {runargs = {"-r", "enum.dppo"}, pass_outputs = "1 2 114514"})

    add_tests("test-typedef-compile", {runargs = {"-c", "typedef.dpp"}})
    add_tests("test-typedef-run", {runargs = {"-r", "typedef.dppo"}, pass_outputs = "1"})

    add_tests("test-variable-compile", {runargs = {"-c", "variable.dpp"}})
    add_tests("test-variable-run", {runargs = {"-r", "variable.dppo"}, pass_outputs = "114514 1919810 \"Hello, world!\""})

    -- add_tests("test-operators-compile", {runargs = {"-c", "operators.dpp"}})
    -- add_tests("test-operators-run", {runargs = {"-r", "operators.dppo"}, pass_outputs = "opt-start-2 0 0 1 0 1 12 2 3 7 -1 48 0 1 0 1 0 7 0 7 -12opt-end"})

    add_tests("test-new-delete-compile", {runargs = {"-c", "new-delete.dpp"}})
    add_tests("test-new-delete-run", {runargs = {"-r", "new-delete.dppo"}, pass_outputs = ""})

    add_tests("test-when-compile", {runargs = {"-c", "when.dpp"}})
    add_tests("test-when-run", {runargs = {"-r", "when.dppo"}, pass_outputs = "a == 1 in whenb == 2defaulta == 1"})

    add_tests("test-loop-compile", {runargs = {"-c", "loop.dpp"}})
    add_tests("test-loop-run", {runargs = {"-r", "loop.dppo"}, pass_outputs = "01234 12346789100"})

    add_tests("test-goto-compile", {runargs = {"-c", "goto.dpp"}})
    add_tests("test-goto-run", {runargs = {"-r", "goto.dppo"}, pass_outputs = "start end"})

    add_tests("test-function-compile", {runargs = {"-c", "function.dpp"}})
    add_tests("test-function-run", {runargs = {"-r", "function.dppo"}, pass_outputs = "2"})

    add_tests("test-test-compile", {runargs = {"-c", "test.dpp"}})
    add_tests("test-test-run", {runargs = {"-r", "test.dppo"}, pass_outputs = "Hello World"})
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

option("enable-plugins")
    set_default(true)
    set_showmenu(true)

    target("plugins")
        set_kind("shared")

        add_files("src/plugins/*.cpp")

        add_deps("vm")
        add_packages("cereal")
    target_end()
option_end()

task("tag")
    on_run(function ()
        import("core.base.option")
        import("core.project.project")

        local tag_action = option.get("action")
        local tag_version = "v" .. project.version()

        if tag_action == "create" then
            os.runv("git", {"switch", "master"})
            os.runv("git", {"merge", "dev"})
            os.runv("git", {"tag", "-a", tag_version, "-m", "release " .. tag_version})
            os.runv("git", {"push", "origin", "--tags"})
            os.runv("git", {"switch", "dev"})

            os.runv("git", {"tag"})
            cprint("${green}tag " .. tag_version .. " created")
        else
            os.runv("git", {"tag", "-d", tag_version})
            os.runv("git", {"push", "origin", "--delete", tag_version})

            os.runv("git", {"tag"})
            cprint("${green}tag " .. tag_version .. " deleted")
        end
    end)

    set_menu {
        usage = "xmake tag [create|delete]",
        description = "create/delete a tag for the current version",

        options =
        {
            {"a", "action", "kv", "create", "set action to create or delete"
                          , "    - create"
                          , "    - delete"}
            , {}
        }
    }
task_end()

xpack("dpp")
    -- set formats
    set_formats("zip", "targz", "nsis", "runself", "deb")

    set_basename("dpp-$(version)-$(plat)-$(arch)")

    -- set base information
    set_homepage("https://ACoderOrHacker.github.io/DPP")
    set_description("A Programming Language based on c++17")
    set_author("ACoderOrHacker")
    set_license("MIT")
    set_licensefile("LICENSE")
    set_title("The D++ Programming Language")

    add_sourcefiles("$(projectdir)/(src/*)")
    add_sourcefiles("$(projectdir)/(include/*)")
    add_sourcefiles("$(projectdir)/examples/*")
    add_sourcefiles("$(projectdir)/scripts/*")
    add_sourcefiles("$(projectdir)/CHANGELOG.md")
    add_sourcefiles("$(projectdir)/LICENSE")
    add_sourcefiles("$(projectdir)/README.md")

    -- set install targets
    add_targets("dpp", "vm", "compiler")

    -- std libraries
    add_targets("io")

xpack_end()

