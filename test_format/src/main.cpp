#include <iostream>
#include <print>

class Point {
public:
  int x;
  int y;
};

// Template:
//
// template <>
// struct std::formatter<MyType> {
//     constexpr auto parse(std::format_parse_context& ctx) {
//         return /* */;
//     }
//
//     auto format(const MyType& obj, std::format_context& ctx) const {
//         return std::format_to(ctx.out(), /* */);
//     }
// };

// template <> struct std::formatter<Point> {
//   constexpr auto parse(std::format_parse_context &ctx) { return ctx.begin();
//   }
//
//   auto format(const Point &p, std::format_context &ctx) const {
//     return std::format_to(ctx.out(), "Point(x: {}, y: {})", p.x, p.y);
//   }
// };

template <> struct std::formatter<Point> : std::formatter<string_view> {
  auto format(const Point &p, std::format_context &ctx) const {
    std::string buffer;
    std::format_to(std::back_inserter(buffer), "Point(x: {}, y: {})", p.x, p.y);
    return std::formatter<string_view>::format(buffer, ctx);
  }
};

int main() {
  Point p1{1, 3};
  std::print("point1: {}\n", p1);
  int x, y;
  std::cin >> x >> y;
  Point p2{x, y};
  std::print("point2: {}\n", p2);

  return 0;
}
