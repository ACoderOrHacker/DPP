#include "venv.h"
#include <string_view>
#include "acdpp.h"
#include "dpp/api.h"
#include "dpp/plugins.h"
#include "fmt.h"
#include "macros.hpp"

NAMESPACE_DPP_BEGIN
NAMESPACE_BEGIN(venv)

void create(const std::string &path,
    const std::vector<fs::path> &dpp_executables,
    bool is_cover) {
    if (fs::exists(path) && !is_cover) {
        fmt::print_error("the directory ", path, " is already exists.\n");
        return;
    }

    fs::create_directories(path);
    fmt::print("creating virtual environment in ", path, "\n");

    const fs::path &opt_path = fs::path(path);
    fs::create_directory(opt_path / "scripts"); // storge D++ binary files and active scripts
    fs::create_directory(opt_path / "packages"); // storge 3rd packages in D++
    for (auto &it : dpp_executables) {
        fs::copy_file(it, opt_path / "scripts" / it.filename(), fs::copy_options::overwrite_existing);
    }

    /// Write activate/deactivate script
    std::ofstream activate_bat;
    activate_bat.open(opt_path / "scripts" / "activate.bat");
    activate_bat << "set DXX_OLD_VIRTUAL_ENV=%PATH%\n";
    activate_bat << "set PATH=" << path << "/scripts;%PATH%\n";
    activate_bat.close();

    std::ofstream deactivate_bat;
    deactivate_bat.open(opt_path / "scripts" / "deactivate.bat");
    deactivate_bat << "set PATH=%DXX_OLD_VIRTUAL_ENV%\n";
    deactivate_bat << "set DXX_OLD_VIRTUAL_ENV=\n";
    deactivate_bat.close();

    std::ofstream activate_sh;
    activate_sh.open(opt_path / "scripts" / "activate.sh");
    activate_sh << "export DXX_OLD_VIRTUAL_ENV=$PATH\n";
    activate_sh << "export PATH=" << path << "/scripts:$PATH\n";
    activate_sh.close();

    std::ofstream deactivate_sh;
    deactivate_sh.open(opt_path / "scripts" / "deactivate.sh");
    deactivate_sh << "export PATH=$DXX_OLD_VIRTUAL_ENV\n";
    deactivate_sh << "export DXX_OLD_VIRTUAL_ENV=\n";
    deactivate_sh << "export DXX_VIRTUAL_ENV=\n";
    deactivate_sh.close();

    fmt::print_success("virtual environment created successfully.\n");
}

void activate(const std::string &path) {
    if (!fs::exists(path)) {
        fmt::print_error("the directory ", path, " is not exists.\n");
        return;
    }

    fmt::print("activating virtual environment in ", path, "\n");
    const fs::path &venv_path = fs::path(path);
    std::string activate_file =
#if defined(_WIN32) || defined(_WIN64)
    (venv_path / "scripts" / "activate.bat").string();
#else
    (venv_path / "scripts" / "activate.sh").string();
#endif

    std::string shell =
#if defined(_WIN32) || defined(_WIN64)
    "cmd.exe";
#else
    "sh";
#endif
    if (fs::exists(activate_file)) {
        std::ignore = system((shell + " " + activate_file).c_str());
    } else {
        fmt::print_error("activate file not found.\n");
        return;
    }
}

void deactivate(const std::string &path) {
    if (!fs::exists(path)) {
        fmt::print_error("the directory ", path, " is not exists.\n");
        return;
    }

    fmt::print("deactivating virtual environment in ", path, "\n");
    const fs::path &venv_path = fs::path(path);
    std::string deactivate_file =
#if defined(_WIN32) || defined(_WIN64)
    (venv_path / "scripts" / "deactivate.bat").string();
#else
    (venv_path / "scripts" / "deactivate.sh").string();
#endif

    std::string shell =
#if defined(_WIN32) || defined(_WIN64)
    "cmd.exe";
#else
    "sh";
#endif
    if (fs::exists(deactivate_file)) {
        std::ignore = system((shell + " " + deactivate_file).c_str());
    } else {
        fmt::print_error("deactive file not found.\n");
        return;
    }
}

NAMESPACE_END
NAMESPACE_END


/// Cli Interfaces

_DXX_EXPORT_API void venv(const dpp::plugin_args &args) {
    std::vector<fs::path> files;
    dpp::get_files(files, args.dpp_executable_file.parent_path());


    if (args.args.empty()) {
        dpp::venv::create(args.output_dir.string(),
            files,
            true);
    }
    for (auto &it : args.args) {
        if (it == "create") {
            dpp::venv::create(args.output_dir.string(),
                files,
                true);
        }else if (dpp::startswith(it, "activate:")) {
            dpp::venv::activate(it.substr(std::string_view("activate:").size()));
        } else if (dpp::startswith(it, "deactivate:")) {
            dpp::venv::activate(it.substr(std::string_view("deactivate:").size()));
        } else {
            dpp::fmt::print_error("error: invalid argument: ", it, "\n");
        }
    }
}