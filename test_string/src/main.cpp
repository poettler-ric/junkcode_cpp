#include <algorithm>
#include <cctype>
#include <print>
#include <string>

std::string str_tolower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return s;
}

int main() {
    std::string test{"SOME 3 small TeXt"};
    std::println("transformed: {}", str_tolower(test));

    std::string value{"VAlue"};
    if (str_tolower(value) == "value") {
        std::println("got value");
    }

    return 0;
}
