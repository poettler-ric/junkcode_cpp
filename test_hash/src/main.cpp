#include <boost/container_hash/hash.hpp>
#include <memory>
#include <print>
#include <unordered_set>

class Point {
   public:
    double x;
    double y;

    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }
};

// normal hash function for Point
template <>
struct std::hash<Point> {
    std::size_t operator()(const Point& p) const noexcept {
        std::size_t seed = 0;
        boost::hash_combine(seed, boost::hash_value(p.x));
        boost::hash_combine(seed, boost::hash_value(p.y));
        return seed;
    }
};

// needed since unordered_set uses == first to check if a element is present
template <>
struct std::equal_to<std::shared_ptr<Point>> {
    bool operator()(const std::shared_ptr<Point>& lhs,
                    const std::shared_ptr<Point>& rhs) const noexcept {
        return *lhs == *rhs;
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

int main(int argc, char* argv[]) {
    std::unordered_set<Point> points01 = {Point{1.5, 2.6}, Point{1.6, 7.9},
                                          Point{1.5, 2.6}};
    std::println("normal points");
    for (const auto& p : points01) {
        std::println("{} {}", p.x, p.y);
    }

    std::println("smart pointers");
    auto points02 = std::unordered_set<std::shared_ptr<Point>>{
        std::make_shared<Point>(Point{1.5, 2.6}),
        std::make_shared<Point>(Point{1.6, 7.9}),
        std::make_shared<Point>(Point{1.5, 2.6})};
    for (const auto& p : points02) {
        std::println("{} {}", p->x, p->y);
    }

    return EXIT_SUCCESS;
}
