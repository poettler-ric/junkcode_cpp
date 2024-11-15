#include <iostream>
#include <memory>
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

template <>
struct std::formatter<Point> : std::formatter<string_view> {
    auto format(const Point &p, std::format_context &ctx) const {
        std::string buffer;
        std::format_to(std::back_inserter(buffer), "Point(x: {}, y: {})", p.x,
                       p.y);
        return std::formatter<string_view>::format(buffer, ctx);
    }
};

class Edge {
   public:
    Point first;
    Point second;
};

template <>
struct std::formatter<Edge> : std::formatter<string_view> {
    auto format(const Edge &e, std::format_context &ctx) const {
        std::string buffer;
        std::format_to(std::back_inserter(buffer), "Edge({} -> {})", e.first,
                       e.second);
        return std::formatter<string_view>::format(buffer, ctx);
    }
};

class EdgePtr {
   public:
    std::shared_ptr<Point> first;
    std::shared_ptr<Point> second;
};

template <>
struct std::formatter<EdgePtr> : std::formatter<string_view> {
    auto format(const EdgePtr &e, std::format_context &ctx) const {
        std::string buffer;
        std::format_to(std::back_inserter(buffer), "EdgePtr({} -> {})",
                       *e.first, *e.second);
        return std::formatter<string_view>::format(buffer, ctx);
    }
};

int main() {
    Point p1{1.0, 3.2};
    Point p2{5.3, 4.4};
    std::println("point1: {}", p1);
    std::println("point2: {}", p2);

    Edge e{p1, p2};
    std::println("edge: {}", e);

    EdgePtr ep{std::make_shared<Point>(p1), std::make_shared<Point>(p2)};
    std::println("edge nodepointer: {}", ep);
    std::println("edge nodepointer: {} -> {}", *ep.first, *ep.second);

    return 0;
}
