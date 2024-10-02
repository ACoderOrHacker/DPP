#include <fstream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <process.h>
#include <boost/program_options.hpp>

#include "compiler.hpp"
#include "vm.hpp"
#include "modules.h"
#include "dpp/api.h"

#if defined (_DEBUG) || defined (DEBUG)
#define TEST
#endif

namespace opt = boost::program_options;

int main(int argc, char *argv[] ) {
    try {
        opt::options_description desc;
        desc.add_options()
            ("help,h", "Produce help message")
            ("compile,c", opt::value<std::vector<std::string>>(),"Compile a D++ source file")
            ("list,l", opt::value<std::vector<std::string>>(), "List Opcodes of files")
            ("run,r", opt::value<std::string>(), "Run a D++ source file")
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
        else if(vm.count("run")) {
            std::string filename = vm["run"].as<std::string>();
            std::fstream ifs = dpp::open_file(filename, std::ios_base::in,
                [](const std::string &filename, std::fstream &fs) {
                    fmt::print(fmt::fg(fmt::color::red), "error: cannot find '{}' source file\n", filename);
                    exit(1);
                });

            dpp::vm _vm = compile(ifs);
            dpp::close_file(ifs);

            int exit_code = dpp::run(_vm, false);
            exit(exit_code);
        }
        else if (vm.count("list")) {
            dpp::output_information();
            std::cout << "\n\n";

            uint32_t i = 0;
            for (auto &it : vm["list"].as<std::vector<std::string>>()) {
                fmt::print("[{}] {}", i, it);

                std::fstream ifs;

                try {
                    ifs = dpp::open_file(it);
                } catch(std::runtime_error &) {
                    fmt::print(fmt::fg(fmt::color::red), "error: cannot find {} source file\n", it);
                    continue;
                }
                fObj = compile(ifs);
                dpp::close_file(ifs);

                dpp::output_vm(fObj, false);
                dpp::clean_vm();

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


                fmt::print("[{}] {}\n", i, it.filename().string());

                std::stringstream out;
                std::ifstream ifs;
                ifs.open(it.string());
                fObj = compile(ifs);
                ifs.close();

                dpp::switch_ostream(out.rdbuf());
                VM_Run(fObj, true);
                std::string str = out.str();
                std::cout << "Output result: " << str << "\n";
                dpp::check_test(it.filename().string(), str);
                dpp::switch_ostream(dpp::__stdout);

                std::cout << "\n\n";
                ++i;
            }

            fmt::print(fmt::fg(fmt::color::green), "\nAll tests passed\n");
        }
#endif
    } catch (std::exception &e) {
        std::cerr << "error: " << e.what();
        return 1;
    }
    return 0;
}