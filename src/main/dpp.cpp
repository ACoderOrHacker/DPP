#include <cstdlib>
#include <fstream>
#include <ios>
#include <memory>
#include <ostream>

#include "cereal/details/helpers.hpp"
#include "cxxopts.hpp"
#include "fmt.h"
#include "serialize.hpp"
#include "dpp/api.h"
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
                ("list,l", "list information in object files", cxxopts::value<std::string>())
            ;

            if (argc == 1) {
                fmt::print(options.help());
                return EXIT_SUCCESS;
            }

            auto result = options.parse(argc,argv);

            if (result.count("help")) {
                fmt::print(options.help());
            } else if (result.count("version")) {
                fmt::print("Standard D++ Compiler & Runtime v", dpp::get_version_string(dpp::get_version()), "\n");
                return EXIT_SUCCESS;
            } else if (result.count("compile")) {
                for (auto &it : result["compile"].as<std::vector<std::string>>()) {
                    std::ifstream ifs;

                    try {
                        ifs = dpp::open_file<std::ifstream>(it);
                    } catch(std::runtime_error &) {
                        fmt::print_error("error: cannot find '", it, "' source file\n");
                        return EXIT_FAILURE;
                    }
                    dpp::vm vm = dpp::compile(ifs);

                    dpp::close_file(ifs);
                    auto filename = std::filesystem::path(it).filename().stem().string();
                    std::ofstream fs;
                    fs.open(filename + ".dppo");
                    dpp::serialize::save<FObject>(fs, *vm,
                        [](cereal::Exception &e) {
                            fmt::print_error("error: internal error\n");
                            fmt::print_error("    message: ", e.what(), "\n");
                            exit(EXIT_FAILURE);
                        });
                    fs.close();
                }
            } else if (result.count("run")) {
                dpp::vm vm = dpp::create_vm();

                std::string filename = result["run"].as<std::string>();
                std::ifstream ifs = dpp::open_file<std::ifstream>(filename, std::ios_base::in,
                    [](const std::string &filename, std::ifstream &fs) -> void {
                        fmt::print_error("error: cannot find '", filename, "' binary file\n");
                        exit(EXIT_FAILURE);
                    });

                *vm = dpp::serialize::load<FObject>(dynamic_cast<std::istream &>(const_cast<std::ifstream &>(ifs)),
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
                    });
                exit(exit_code);
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
                vm = dpp::compile(ifs);
                dpp::close_file(ifs);

                dpp::output_vm(vm, false);
                dpp::delete_vm(vm);
            }
        } catch (const cxxopts::exceptions::exception &e) {
            fmt::print_error("error: ", e.what());
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }

private:
};

int main(int argc, char *argv[] ) {
    application app;
    return app.run(argc, argv);
}
