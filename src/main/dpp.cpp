#include <fstream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <process.h>
#include <boost/program_options.hpp>

#include "compiler.hpp"
#include "vm.hpp"
#include "modules.h"

#if defined (_DEBUG) || defined (DEBUG)
#define TEST
#endif

namespace opt = boost::program_options;

int main(int argc, char *argv[] ) {
    OutputInformation();
    std::cout << "\n\n";


    try {
        opt::options_description desc;
        desc.add_options()
            ("help,h", "Produce help message")
            ("compile,c", opt::value<std::vector<std::string>>(), "Compile a D++ source file")
            ("list,l", opt::value<std::vector<std::string>>(), "List Opcodes of files")
#ifdef _COMPILE_TEST
            ("compile-test,t", "Compile the test")
#endif
            ;

        opt::positional_options_description p;
        opt::variables_map vm;
        opt::store(opt::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
        opt::notify(vm);

        if (vm.count("help") || vm.empty()) {
            fmt::print("Usage: dpp [options]\n\n");
            std::cout << desc;
            return 0;
        }
        else if (vm.count("file")) {
            // TODO: Not Success
        }
        else if (vm.count("list")) {
            uint32_t i = 0;
            for (auto &it : vm["list"].as<std::vector<std::string>>()) {
                fmt::print("[{}] {}", i, it);

                std::ifstream ifs;
                ifs.open(it);
                fObj = compile(ifs);
                ifs.close();

                OutputFObject(fObj, false);
                delete fObj;
                fObj = nullptr;

                std::cout << "\n\n";
                ++i;
            }
        }
#ifdef _COMPILE_TEST
        else if (vm.count("compile-test")) {
            std::vector<boost::filesystem::path> files;
            GetFiles(files, examples_path);

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

                SetOstream(out);
                VM_Run(fObj, true);
                std::string str((std::istreambuf_iterator<char>(GetOstream())), std::istreambuf_iterator<char>());
                CheckTest(it.filename().string(), str);
                RestoreOstream();

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