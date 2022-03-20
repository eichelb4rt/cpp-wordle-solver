#include <catch2/catch_test_macros.hpp>
#include "add.h"

TEST_CASE("1 + 2 = 3", "[trivial]") {
    constexpr int a = 1;
    constexpr int b = 2;
    constexpr int expected_result = 3;
    REQUIRE(add(a, b) == expected_result);
}

TEST_CASE("x + 0 = x", "[trivial]") {
    int x;
    x = 0;
    REQUIRE(add(x, 0) == x);
    x = 1;
    REQUIRE(add(x, 0) == x);
    x = 3;
    REQUIRE(add(x, 0) == x);
    x = 5;
    REQUIRE(add(x, 0) == x);
}