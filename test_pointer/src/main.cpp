#include <memory>
#include <print>
#include <string>

class Point {
   public:
    double x;
    double y;
};

template <>
struct std::formatter<Point> : std::formatter<string_view> {
    auto format(const Point &p, std::format_context &ctx) const {
        std::string buffer;
        std::format_to(std::back_inserter(buffer), "Point(x: {}, y: {})", p.x,
                       p.y);
        return std::formatter<string_view>::format(buffer, ctx);
    }
};

int main() {
    const auto p = std::make_shared<Point>(5, 10);

    std::print("point: {}\n", *p);

    return 0;
}
