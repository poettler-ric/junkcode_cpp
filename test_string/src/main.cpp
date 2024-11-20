#include <algorithm>
#include <cctype>
#include <print>
#include <string>
#include <vector>

std::string str_tolower(std::string s) noexcept {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return s;
}

std::string join(const std::vector<std::string> &v,
                 const std::string &sep) noexcept {
    std::string result{};
    for (auto it = v.begin(); it != v.end(); it++) {
        result += *it;
        if (it != v.end() - 1) {
            result += sep;
        }
    }
    return result;
}

int main() {
    std::string test{"SOME 3 small TeXt"};
    std::println("transformed: {}", str_tolower(test));

    std::string value{"VAlue"};
    if (str_tolower(value) == "value") {
        std::println("got value");
    }

    std::println(
        "{}",
        join(std::vector<std::string>{"this", "should", "be", "joined"}, ", "));

    return EXIT_SUCCESS;
}
