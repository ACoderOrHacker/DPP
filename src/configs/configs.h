#ifndef _CONFIG_H
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <fmt/core.h>
#include <fmt/color.h>

#include "dpp/api.h"
#include "macros.hpp"

NAMESPACE_DPP_BEGIN

struct tests {
    std::map<std::string, std::string> tests;
};

struct tests load_tests(const std::string &path) {
    std::ifstream fs = dpp::open_file<std::ifstream>(path, std::ios_base::in,
                        [](const std::string &, std::ifstream &) -> void {
                            fmt::print(fmt::fg(fmt::color::red), "\nerror: cannot find tests.json file\n");
                            exit(1);
                        });
    Json::Value root;
    fs >> root;
    struct tests tests;
    for (const auto &test : root["tests"]) {
        tests.tests[test["id"].asString()] = test["buf"].asString();
    }

    dpp::close_file(fs);
    return tests;
}

NAMESPACE_DPP_END

#endif // !_CONFIG_h