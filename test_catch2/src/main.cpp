#include <print>

#include "lib.hpp"

int main() {
    std::println("{} + {} = {}", 1, 2, add(1, 2));
    return EXIT_SUCCESS;
}