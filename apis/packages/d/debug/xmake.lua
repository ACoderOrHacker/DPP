package("debug")
    set_kind("binary")
    set_description("The debug package")

    add_deps("compiler", "vm")

    on_load(function (package)
        package:set("installdir", path.join(os.scriptdir(), package:plat(), package:arch(), package:mode()))
    end)

    on_fetch(function (package)
        return {program = path.join(package:installdir("bin"), "debug.exe")}
    end)
