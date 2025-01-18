/**
 * @file test.cpp
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Tests for D++ APIs and functions.
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "catch2/catch_test_macros.hpp"
#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include <cstdlib>
#include "dpp/api.h"

#define REQUIRE_RUN(cmd) REQUIRE(std::system(cmd) == EXIT_SUCCESS)

TEST_CASE("Test D++ Command Line", "[cmdline]") {
    REQUIRE_RUN("dpp -v");
    REQUIRE_RUN("dpp -h");
}

TEST_CASE("Test APIs", "[apis]") {
    dpp::vm vm;
    REQUIRE(dpp::run(dpp::compile("a: int = 1;"), true) == EXIT_SUCCESS);
}

TEST_CASE("Examples run & benchmark", "[examples][!benchmark]") {
    BENCHMARK("Fibonacci") {
        // TODO:
    };
}