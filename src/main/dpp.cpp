#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <ios>
#include <memory>
#include <ostream>
#include <sstream>
#if defined(_WIN32) || defined(_WIN64)
#include <direct.h>
#else
#include <unistd.h>
#endif

#include "cereal/details/helpers.hpp"
#include "cxxopts.hpp"
#include "fmt.h"
#include "serialize.hpp"
#include "dpp/api.h"
#include "dpp/plugins.h"
#include "struct.hpp"
#include "vm.hpp"

namespace fmt = dpp::fmt;

/**
 * @brief the main application class
 * @details entry point for dpp program, defines the command line options and runs them
 * @code {.cpp}
 * application app;
 * int exit_code = app.run(argc, argv); // argc is ref to main:argc, argv is ref to main:argv
 * @endcode
 *
 */
class application {
public:
    application() = default;
    ~application() = default;

    /**
     * @brief compiles command line and runs it
     *
     * @param argc ref to main:argc
     * @param argv ref to main:argv
     * @return int exit code of the program
     */
    int run(int argc, char *argv[]) {
        try {
            cxxopts::Options options("dpp","Standard D++ Compiler & Runtime");
            options.set_width(70).add_options()
                ("help,h", "show help message")
                ("version,v", "get dpp version")
                ("compile,c", "compile sources", cxxopts::value<std::vector<std::string>>())
                ("run,r", "run object files", cxxopts::value<std::string>())
                ("run-script,s", "run sources as scripts", cxxopts::value<std::string>())
                ("debug, d", "debug codes", cxxopts::value<std::string>())
                ("list,l", "list information in object files", cxxopts::value<std::string>())
                ("plugin,p", "choose a plugin file", cxxopts::value<std::string>()->default_value("builtin"))
                ("output, o", "set output directory", cxxopts::value<std::string>())
                ("args,a", "set arguments for plugins or another custom tools", cxxopts::value<std::vector<std::string>>())
                ("command,cmd", "command in the custom tools", cxxopts::value<std::string>()->default_value("venv"))
            ;

            if (argc == 1) {
                fmt::print(options.help());
                return EXIT_SUCCESS;
            }

            auto result = options.parse(argc,argv);


            // options for cli
            if (result.count("output")) {
                output_dir = result["output"].as<std::string>();
                const auto &path = fs::path(output_dir);
                if (path.is_relative()) {
                    output_dir = fs::current_path() / path;
                }
            }

            if (result.count("args")) {
                args = result["args"].as<std::vector<std::string>>();
            }

            if (result.count("command")) {
                command = result["command"].as<std::string>();
            }

            if (result.count("help")) {
                fmt::print(options.help());
            } else if (result.count("version")) {
                fmt::print("Standard D++ Compiler & Runtime v", dpp::get_version_string(dpp::get_version()), "\n");
            } else if (result.count("compile")) {
                for (auto &it : result["compile"].as<std::vector<std::string>>()) {
                    std::ifstream ifs;

                    try {
                        ifs = dpp::open_file<std::ifstream>(it);
                    } catch(std::runtime_error &) {
                        fmt::print_error("error: cannot find '", it, "' source file\n");
                        return EXIT_FAILURE;
                    }
                    dpp::vm vm = dpp::compile(ifs, it, true);

                    dpp::close_file(ifs);
                    auto filename = std::filesystem::path(it).filename().stem().string();
                    std::ofstream fs = dpp::open_file<std::ofstream>((output_dir.string() + "/" + (filename + ".dppo")),
                        std::ios::binary,
                        [](const std::string &file, std::ofstream &) -> void {
                            fmt::print_error("cannot create file '", file + ".dppo", "'. maybe you have no premission to create.");
                            exit(EXIT_FAILURE);
                        });
                    dpp::serialize::save<FObject>(fs, *vm,
                        [](cereal::Exception &e) {
                            fmt::print_error("error: internal error\n");
                            fmt::print_error("    message: ", e.what(), "\n");
                            exit(EXIT_FAILURE);
                        });
                    fs.close();
                }
            } else if (result.count("run")) {
                dpp::vm vm = dpp::create_vm(false);

                std::string filename = result["run"].as<std::string>();
                std::ifstream ifs = dpp::open_file<std::ifstream>(filename, std::ios::binary,
                    [](const std::string &filename, std::ifstream &fs) -> void {
                        fmt::print_error("error: cannot find '", filename, "' binary file\n");
                        exit(EXIT_FAILURE);
                    });

                *vm = dpp::serialize::load<FObject>(dynamic_cast<std::istream &>(ifs),
                    [](cereal::Exception &e) {
                        fmt::print_error("error: invaild input file\n");
                        fmt::print_error("    message: ", e.what(), "\n");
                        exit(EXIT_FAILURE);
                    });

                ifs.close();
                dpp::run(vm);
            } else if (result.count("run-script")) {
                std::string filename = result["run-script"].as<std::string>();

                int exit_code = dpp::run_script(filename,
                    [](const std::string &filename, std::ifstream &fs) -> void {
                        fmt::print_error("error: cannot find '", filename, "' source file\n");
                        exit(EXIT_FAILURE);
                    }, true);
                exit(exit_code);
            } else if (result.count("debug")) {
                dpp::output_information();
                fmt::print("Standard Debug Tools\n\n");

                std::string filename = result["debug"].as<std::string>();
                std::ifstream ifs = dpp::open_file<std::ifstream>(filename, std::ios::binary,
                    [](const std::string &filename, std::ifstream &fs) -> void {
                        fmt::print_error("error: cannot find '", filename, "' binary file\n");
                        exit(EXIT_FAILURE);
                    });

                dpp::vm vm;
                *vm = dpp::serialize::load<FObject>(dynamic_cast<std::istream &>(ifs),
                    [](cereal::Exception &e) {
                        fmt::print_error("error: invaild input file\n");
                        fmt::print_error("    message: ", e.what(), "\n");
                        exit(EXIT_FAILURE);
                    });

                ifs.close();

                // TODO: debug tools
            } else if (result.count("list")) {
                dpp::output_information();
                std::cout << "\n\n";

                const std::string &file = result["list"].as<std::string>();
                std::ifstream ifs;
                dpp::vm vm;

                try {
                    ifs = dpp::open_file<std::ifstream>(file);
                } catch(std::runtime_error &) {
                    fmt::print_error("error: cannot find '", file, "' source file\n");
                    return EXIT_FAILURE;
                }
                vm = dpp::compile(ifs, file, true);
                dpp::close_file(ifs);

                dpp::output_vm(vm, false);
            } else if (result.count("plugin")) {
                dpp::output_information();
                std::cout << "\n\n";

                std::string plugin_file = result["plugin"].as<std::string>();
                if (plugin_file == "builtin") plugin_file = "plugins";
                try {
                    dylib plugin_lib(plugin_file, true);

                    fmt::print_success("plugin '", plugin_file, "' loaded\n\n");
                    if (plugin_lib.has_symbol(command)) {
                        auto plugin_func = plugin_lib.get_function<dpp::plugin_init_func>(command);
                        plugin_func(dpp::plugin_args{output_dir, argv[0], args}); // run plugin
                    } else {
                        fmt::print_error("command '", command, "' not found in plugin '", plugin_file, "'\n");
                        return EXIT_FAILURE;
                    }

                    fmt::print_success("\ncommand run successfully\n");
                } catch (dylib::exception &) {
                    fmt::print_error("error: cannot find command '", command, "' in plugin '", plugin_file, "'\n");
                    return EXIT_FAILURE;
                }
            }
        } catch (const cxxopts::exceptions::exception &e) {
            fmt::print_error("error: ", e.what());
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }

private:
    fs::path output_dir = fs::current_path();
    std::vector<std::string> args;
    std::string command;
};

int main(int argc, char *argv[] ) {
    application app;
    return app.run(argc, argv);
}
