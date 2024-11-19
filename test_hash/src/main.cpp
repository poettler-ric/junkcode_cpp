#include <boost/container_hash/hash.hpp>
#include <memory>
#include <print>
#include <unordered_set>

class Point {
   public:
    double x;
    double y;

    auto operator<=>(const Point&) const = default;
};

// needed since unordered_set uses == first to check if a element is present
template <>
struct std::equal_to<std::shared_ptr<Point>> {
    bool operator()(const std::shared_ptr<Point>& lhs,
                    const std::shared_ptr<Point>& rhs) const noexcept {
        return *lhs == *rhs;
    }
};

// normal hash function for Point
template <>
struct std::hash<Point> {
    std::size_t operator()(const Point& p) const noexcept {
        std::size_t seed = 0;
        boost::hash_combine(seed, std::hash<double>{}(p.x));
        boost::hash_combine(seed, std::hash<double>{}(p.y));
        return seed;
    }
};

// specialize the hash funciton for shared_ptr<Point> to just use the one on
// Point
template <>
struct std::hash<std::shared_ptr<Point>> {
    std::size_t operator()(const std::shared_ptr<Point>& p) const noexcept {
        return std::hash<Point>{}(*p);
    }
};

class Edge {
   public:
    std::shared_ptr<Point> first;
    std::shared_ptr<Point> second;

    auto operator<=>(const Edge& other) const noexcept {
        if (const auto res = (*first <=> *other.first); res != 0) {
            return res;
        }
        return *second <=> *other.second;
    }
};

template <>
struct std::equal_to<Edge> {
    bool operator()(const Edge& lhs, const Edge& rhs) const noexcept {
        return (lhs <=> rhs) == 0;
    }
};

template <>
struct std::hash<Edge> {
    std::size_t operator()(const Edge& e) const noexcept {
        std::size_t seed = 0;
        boost::hash_combine(seed, std::hash<std::shared_ptr<Point>>{}(e.first));
        boost::hash_combine(seed,
                            std::hash<std::shared_ptr<Point>>{}(e.second));
        return seed;
    }
};

int main(int argc, char* argv[]) {
    std::unordered_set<Point> points01{Point{1.5, 2.6}, Point{1.6, 7.9},
                                       Point{1.5, 2.6}};
    std::println("normal points");
    for (const auto& p : points01) {
        std::println("{} {}", p.x, p.y);
    }

    std::println("smart pointers");
    std::unordered_set<std::shared_ptr<Point>> points02{
        std::make_shared<Point>(Point{1.5, 2.6}),
        std::make_shared<Point>(Point{1.6, 7.9}),
        std::make_shared<Point>(Point{1.5, 2.6})};
    for (const auto& p : points02) {
        std::println("{} {}", p->x, p->y);
    }

    std::println("edges");
    const Point point1{1.5, 3.5};
    const Point point2{2.1, 8.3};
    const Point eq_point{2.1, 8.3};
    std::unordered_set<Edge> edges{
        Edge{std::make_shared<Point>(point1), std::make_shared<Point>(point2)},
        Edge{std::make_shared<Point>(point2),
             std::make_shared<Point>(eq_point)},
        Edge{std::make_shared<Point>(point1),
             std::make_shared<Point>(eq_point)}};
    for (const auto& e : edges) {
        std::println("({}, {}) - ({}, {})", e.first->x, e.first->y, e.second->x,
                     e.second->y);
    }

    std::println("variant");
    std::variant<Point, Edge> varaint{point1};
    std::println("variant: {} point: {} equal: {}",
                 std::hash<std::variant<Point, Edge>>{}(varaint),
                 std::hash<Point>{}(point1),
                 std::hash<std::variant<Point, Edge>>{}(varaint) ==
                     std::hash<Point>{}(point1));
    Edge edge{std::make_shared<Point>(point1), std::make_shared<Point>(point2)};
    varaint = edge;
    std::println("variant: {} edge: {} equal: {}",
                 std::hash<std::variant<Point, Edge>>{}(varaint),
                 std::hash<Edge>{}(edge),
                 std::hash<std::variant<Point, Edge>>{}(varaint) ==
                     std::hash<Edge>{}(edge));

    return EXIT_SUCCESS;
}
