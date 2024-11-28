#include <iostream>
#include <print>
#include <string>

int main() {
    std::string line{};
    int end{};
    int i{0};
    std::getline(std::cin, line);

    if (std::from_chars(line.data(), line.data() + line.size(), end).ec !=
        std::errc{}) {
        std::println(std::cerr, R"(error while parsing "{}" to int)", line);
        return EXIT_FAILURE;
    }

    std::println("counting to: {}", end);
    while (i < end) {
        i++;
    }
    std::println("result: {}", i);

    return EXIT_SUCCESS;
}
