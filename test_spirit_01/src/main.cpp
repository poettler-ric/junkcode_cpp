#include <boost/spirit/include/qi.hpp>
#include <print>

template <typename Iterator>
bool parse_numbers(Iterator first, Iterator last) {
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;
    bool r = qi::phrase_parse(first, last, qi::double_ >> *(',' >> qi::double_),
                              ascii::space);
    if (first != last) {
        return false;
    }
    return r;
}

int main() {
    std::string line{};
    while (std::getline(std::cin, line)) {
        if (line.empty() || line[0] == 'q' || line[0] == 'Q') {
            break;
        }
        if (parse_numbers(line.begin(), line.end())) {
            std::println("ok: {}", line);
        } else {
            std::println("failed: {}", line);
        }
    }
    return EXIT_SUCCESS;
}
