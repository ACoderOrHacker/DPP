/**
 * @file test.cpp`
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

TEST_CASE("Test APIs") {
    dpp::vm vm;
    CHECK(dpp::run(dpp::compile("a: int = 1; fun main(): void {}"), true) == EXIT_SUCCESS);
}

TEST_CASE("Examples run") {

}
