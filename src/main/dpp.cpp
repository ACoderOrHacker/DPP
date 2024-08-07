#include <fstream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <boost/program_options.hpp>

#include "compiler.hpp"
#include "vm.hpp"
#include "modules.h"

#if defined (_DEBUG) || defined (DEBUG)
#define TEST
#endif

namespace opt = boost::program_options;

boost::filesystem::path root = boost::filesystem::initial_path<boost::filesystem::path>().parent_path();
const boost::filesystem::path examples_path = root / "examples" / "compiler";

int main(int argc, char *argv[] ) {
    OutputInformation();
    std::cout << "\n\n";

#ifndef TEST
    try {
#endif // !TEST
        opt::options_description desc;
        desc.add_options()
            ("help,h", "Produce help message")
            ("compile,c", opt::value<std::vector<std::string>>(), "Compile a D++ source file")
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
#ifdef _COMPILE_TEST
        else if (vm.count("compile-test")) {
            std::vector<boost::filesystem::path> files;
            GetFiles(files, examples_path);

            FObject *fObj;
            uint32_t i = 1;
            for (auto &it : files) {
                fmt::print("[{}] {}", i, it.filename().string());

                std::ifstream ifs;
                ifs.open(it.string());
                fObj = compile(ifs);
                ifs.close();

                OutputFObject(fObj, false);
                delete fObj;
                fObj = nullptr;

                std::cout << "\n\n";
                ++i;
            }
        }
#endif
#ifndef TEST
    } catch (std::exception &e) {
        std::cerr << "error: " << e.what();
        return 1;
    }
#endif
    return 0;
}