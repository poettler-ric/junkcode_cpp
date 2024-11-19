#include <print>
#include <set>
#include <vector>

class Point {
   public:
    int x;
    int y;

    auto operator<=>(const Point &) const = default;
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
    std::println("int set:");
    std::set<int> ints{1, 2, 3, 4, 5, 5};
    for (int i : ints) {
        std::println("{}", i);
    }

    Point p1{1, 2};
    Point p2{1, 3};
    Point p3{2, 1};
    Point p4{3, 1};
    Point p5{6, 3};
    Point p6{3, 1};  // p4 == p6

    std::println("comparing:");
    std::println("{} < {}: {}", p1, p2, p1 < p2);
    std::println("{} < {}: {}", p2, p1, p2 < p1);
    std::println("{} < {}: {}", p3, p4, p3 < p4);
    std::println("{} < {}: {}", p4, p3, p4 < p3);
    std::println("{} < {}: {}", p4, p6, p4 < p6);
    std::println("{} < {}: {}", p6, p4, p6 < p4);

    std::println("creating vector:");
    std::vector<Point> point_vec{p1, p2, p3, p4, p5, p6};

    std::println("creating set:");
    std::set<Point> point_set{p1, p2, p3, p4, p5, p6};

    std::println("iterating:");
    for (const auto &p : point_set) {
        std::println("{}", p);
    }

    std::println("= emptying");
    std::vector<Point> vector(point_set.size());
    for (auto [it, i] = std::tuple{point_set.begin(), 0}; it != point_set.end();
         i++) {
        vector[i] = std::move(point_set.extract(it++).value());
    }
    std::println("set:");
    for (const auto &p : point_set) {
        std::println("{}", p);
    }
    std::println("vector:");
    for (const auto &p : vector) {
        std::println("{}", p);
    }

    return 0;
}
