#include "lib.hpp"

#include <catch2/catch_test_macros.hpp>

int add(int a, int b) noexcept { return a + b; }

TEST_CASE(
    "test add"
    "[add]") {
    REQUIRE(add(1, 2) == 3);
    REQUIRE(add(4, 9) == 13);
    REQUIRE(add(2, 3) == 5);
    REQUIRE(add(0, 3) == 3);
}