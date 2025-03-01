

#ifndef _DPP_MODULE_SEARCHER
#define _DPP_MODULE_SEARCHER
#include <vector>
#include <filesystem>
#include "macros.hpp"
#include "paths.hpp"

NAMESPACE_DPP_BEGIN

Dpp_DEFINE_ERROR(ModuleNotFoundError)

class searcher {
private:
    std::vector<std::filesystem::path> searchdirs;
    
public:
    searcher() {
        std::filesystem::path packages_path = dpp::get_installdir() / "pkgs-dpp";
        searchdirs = {
            packages_path / "std" / "native",
            packages_path / "3rd" / "native",
            dpp::get_exepath().parent_path()
        };
    }
    ~searcher() = default;

    explicit searcher(const std::vector<std::filesystem::path> &dirs) : searchdirs(dirs) {}

    std::filesystem::path search(const std::string &module) {
        for (auto &searchdir : searchdirs) {
            const auto &module_fullpath = searchdir / module;

            if (std::filesystem::exists(module_fullpath)) return module_fullpath;
        }

        throw ModuleNotFoundError(module + " cannot find in searchdirs");
    }
};

NAMESPACE_DPP_END

#endif // !_DPP_MODULE_SEARCHER