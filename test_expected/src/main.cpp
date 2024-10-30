#include <expected>
#include <format>
#include <print>

std::expected<int, std::string> subtract(int i, int j) {
    const auto result = i - j;
    if (result < 0) {
        return std::unexpected(std::format(
            "negative result ({}) when calculating {}-{}", result, i, j));
    }
    return result;
}

int main() {
    auto result = subtract(4, 2);
    if (result) {
        std::print("result: {}\n", *result);
    } else {
        std::print("got an error: {}\n", result.error());
    }

    result = subtract(2, 4);
    if (result) {
        std::print("result: {}\n", *result);
    } else {
        std::print("got an error: {}\n", result.error());
    }
    return 0;
}
