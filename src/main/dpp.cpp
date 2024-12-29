#include <cstdlib>
#include <fstream>
#include <ios>
#include <memory>
#include <ostream>

#include "cereal/details/helpers.hpp"
#include "cxxopts.hpp"
#include "fmt.h"
#include "serialize.hpp"
#include "modules.h"
#include "dpp/api.h"
#include "vm.hpp"

/**
 * @brief the main application class
 */
class application {
public:
    application() = default;
    ~application() = default;
    int run(int argc, char *argv[]) {
        try {
            cxxopts::Options options("dpp","Standard D++ Compiler & Runtime");
            options.set_width(70).add_options()
                ("help,h", "show help message")
                ("compile,c", "compile sources", cxxopts::value<std::vector<std::string>>())
                ("run,r", "run object files", cxxopts::value<std::string>())
                ("run-script,s", "run sources as scripts", cxxopts::value<std::string>())
                ("list,l", "list information in object files", cxxopts::value<std::string>())
                ("version,v", "get dpp version")
            ;

            if (argc == 1) {
                fmt::print(options.help());
                return EXIT_SUCCESS;
            }

            auto result = options.parse(argc,argv);

            if (result.count("help")) {
                fmt::print(options.help());
            } else if (result.count("version")) {
                fmt::print("Standard D++ Compiler & Runtime v", DXX_VERSION);
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
                    dpp::vm vm = compile(ifs);

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
                vm = compile(ifs);
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
/*
            dpp::output_information();
            std::cout << "\n\n";

            std::vector<fs::path> files;
            dpp::get_files(files, examples_path);

            FObject *fObj;
            uint32_t i = 1;
            for (auto &it : files) {
                if (it.extension() != ".dpp") {
                    continue;
                }


                fmt::print("[", i, "] ", it.filename().string(), "\n");

                std::stringstream out;
                std::ifstream ifs;
                ifs.open(it.string());
                fObj = compile(ifs);
                ifs.close();

                dpp::switch_ostream(out.rdbuf());
                dpp::run(fObj, true);
                std::string str = out.str();
                dpp::check_test(it.filename().string(), str);


                std::cout << "\n\n";
                ++i;
            }

            fmt::print_success("All tests passed\n");
*/
    application app;
    return app.run(argc, argv);
}
