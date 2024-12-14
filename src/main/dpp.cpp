#include <fstream>
#include <ios>
#include <memory>
#include <ostream>

#include "cxxopts.hpp"
#include "fmt.h"
/*
#include "CLI/CLI.hpp"
#include "compiler.hpp"

#include "serialize.hpp"
#include "vm.hpp"
#include "modules.h"
#include "dpp/api.h"
*/
#if defined (_DEBUG) || defined (DEBUG)
#define TEST
#endif

/**
 * @brief the main application class
 */
class application {
public:
    application() = default;
    ~application() = default;
    int run(int argc, char *argv[]) {
        if (argc == 1) {
            fmt::print("dpp: try 'dpp --help' for more information");
            return 0;
        }


    
        // initialize the command line parser
        std::vector<std::string> compile_files;
        app.add_option("-c,--compile", compile_files, "compile single or more file")->check(CLI::ExistingFile);

        std::string run_file;
        app.add_option("-r,--run", run_file, "run a compiled file")->check(CLI::ExistingFile);

        CLI11_PARSE(app, argc, argv);
        return 0;
    }

private:
    CLI::App app{"D++ Programming Language\nCopyright (c) 2023 ACoderOrHacker, All rights reserved.\n"};
};

int main(int argc, char *argv[] ) {
/*
#ifndef _DEBUG
    try {
#endif // !_DEBUG
        opt::options_description desc;
        desc.add_options()
            ("help,h", "Produce help message")
            ("compile,c", opt::value<std::vector<std::string>>(),"Compile a D++ source file")
            ("run,r", opt::value<std::string>(), "Run D++ Object file")
            ("list,l", opt::value<std::vector<std::string>>(), "List Opcodes of files")
            ("run-script,s", opt::value<std::string>(), "Run D++ Program as a script")
#ifdef _COMPILE_TEST
            ("compile-test,t", "Compile the test")
#endif
            ;

        opt::positional_options_description p;
        opt::variables_map vm;
        opt::store(opt::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
        opt::notify(vm);

        if (vm.count("help") || vm.empty()) {
            dpp::output_information();
            std::cout << "\n\n";

            fmt::print("Usage: dpp [options]\n\n");
            std::cout << desc;
            return 0;
        }
        else if(vm.count("compile")) {
            dpp::output_information();

            for (auto &it : vm["compile"].as<std::vector<std::string>>()) {
                std::ifstream ifs;

                try {
                    ifs = dpp::open_file<std::ifstream>(it);
                } catch(std::runtime_error &) {
                    fmt::print_error("error: cannot find '", it, "' source file\n");
                    exit(1);
                }
                dpp::vm _vm = compile(ifs);

                dpp::close_file(ifs);
                auto filename = std::filesystem::path(it).filename().string();
                const std::fstream &fs = dpp::open_file((filename + ".dppo"),
                                                        std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
                dpp::serialize::save<std::unique_ptr<FObject>>(dynamic_cast<std::ostream &>(const_cast<std::fstream &>(fs)), std::unique_ptr<FObject>(_vm));
            }
        }
        else if(vm.count("run-script")) {
            std::string filename = vm["run"].as<std::string>();
            std::ifstream ifs = dpp::open_file<std::ifstream>(filename, std::ios_base::in,
                [](const std::string &filename, std::ifstream &fs) -> void {
                    fmt::print_error("error: cannot find '", filename, "' source file\n");
                    exit(1);
                });

            dpp::vm _vm = compile(ifs);
            dpp::close_file<std::ifstream>(ifs);

            int exit_code = dpp::run(_vm, false);
            exit(exit_code);
        }
        else if (vm.count("run")) {
            dpp::vm _vm;

            std::string filename = vm["run"].as<std::string>();
            std::ifstream ifs = dpp::open_file<std::ifstream>(filename, std::ios_base::binary | std::ios_base::in,
                [](const std::string &filename, std::ifstream &fs) -> void {
                    fmt::print_error("error: cannot find '", filename, "' binary file\n");
                    exit(1);
                });
            _vm = dpp::serialize::load<std::unique_ptr<FObject>>(dynamic_cast<std::istream &>(const_cast<std::ifstream &>(ifs))).get();

            dpp::run(_vm);
        }
        else if (vm.count("list")) {
            dpp::output_information();
            std::cout << "\n\n";

            uint32_t i = 0;
            for (auto &it : vm["list"].as<std::vector<std::string>>()) {
                fmt::print("[", i, "]", " ", it);

                std::ifstream ifs;

                try {
                    ifs = dpp::open_file<std::ifstream>(it);
                } catch(std::runtime_error &) {
                    fmt::print_error("error: cannot find '", it, "' source file\n");
                    continue;
                }
                fObj = compile(ifs);
                dpp::close_file(ifs);

                dpp::output_vm(fObj, false);
                dpp::delete_vm(fObj);

                std::cout << "\n\n";
                ++i;
            }
        }
#ifdef _COMPILE_TEST
        else if (vm.count("compile-test")) {
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
        }
#endif
#ifndef _DEBUG
    } catch (std::exception &e) {
        std::cerr << "error: " << e.what();
        return 1;
    }
#endif
    return 0;*/

    application app;
    return app.run(argc, argv);
}
