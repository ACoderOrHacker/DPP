package("dpp")
    set_kind("library", {headeronly = true})
    set_homepage("https://github.com/ACoderOrHacker/DPP")
    set_description("A Programming Language")
    set_license("MIT")

    add_urls("https://github.com/ACoderOrHacker/DPP.git")

    add_includedirs("include", "src", "src/compiler/antlr4")

    on_load("@windows", "@msys", "@cygwin", function (package)
        package:addenv("PATH", "bin")
    end)

    on_install(function (package)
        import("package.tools.xmake").install(package)
    end)

    on_test(function (package)
        assert(package:check_cxxsnippets({test = [[
            void test() {
                dpp::vm vm;
            }
        ]]}, {configs = {languages = "c++20"}, includes = "dpp/api.h"}))
        os.vrun("dpp --help")
        os.vrun("debug --help")
    end)
