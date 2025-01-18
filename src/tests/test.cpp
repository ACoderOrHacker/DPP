/**
 * @file test.cpp
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Tests for D++ APIs and functions.
 *
 * @copyright Copyright (c) 2025
 *
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <cstdlib>
#include "dpp/api.h"

#define CHECK_RUN(cmd) CHECK(std::system(cmd) == EXIT_SUCCESS)

TEST_CASE("Test D++ Command Line") {
    CHECK_RUN("dpp -v");
    CHECK_RUN("dpp -h");
}

TEST_CASE("Test APIs") {
    dpp::vm vm;
    CHECK(dpp::run(dpp::compile("a: int = 1;"), true) == EXIT_SUCCESS);
}

TEST_CASE("Examples run") {
    
}
