#include <optional>
#include <print>
#include <string>

std::optional<int> mightFail(int i) {
    if (i < 0) {
        return std::nullopt;
    }
    return i;
}

int main() {
    const auto v1 = mightFail(1);
    if (v1) {
        std::print("v1 true: {}\n", v1.value());
    } else {
        std::print("v1 false\n");
    }

    std::print("v1 value_or: {}\n", v1.value_or(0));

    const auto v2 = mightFail(-1);
    if (v2) {
        std::print("v2 true: {}\n", v2.value());
    } else {
        std::print("v2 false\n");
    }
    std::print("v2 value_or: {}\n", v2.value_or(0));
    return 0;
}
