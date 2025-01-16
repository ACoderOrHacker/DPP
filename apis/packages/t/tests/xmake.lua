package("tests")
    set_kind("binary")
    set_description("The tests package")

    on_load(function (package)
        package:set("installdir", path.join(os.scriptdir(), package:plat(), package:arch(), package:mode()))
    end)

    on_fetch(function (package)
        return {program = path.join(package:installdir("bin"), "tests.exe")}
    end)
