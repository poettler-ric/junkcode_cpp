#include <print>
#include <string>
#include <variant>

class Material {
   public:
    int id;
    std::string name;
    std::variant<std::string, int, double> value;
};

int main() {
    Material m1{1, "testmat", 5};
    std::println("m1: {}, {}", m1.id, m1.name);
    if (std::holds_alternative<std::string>(m1.value)) {
        std::println("holds a sting");
    }
    if (std::holds_alternative<int>(m1.value)) {
        std::println("holds an int");
    }
    if (std::holds_alternative<double>(m1.value)) {
        std::println("holds a double");
    }
    if (const auto v = std::get_if<int>(&m1.value)) {
        std::println("got int: {}", *v);
    }

    Material m0{1, "zero mat", 0};
    if (const auto v = std::get_if<int>(&m0.value)) {
        std::println("get_if with 0 evaluates to true: {}", *v);
    } else {
        std::println("get_if with 0 evaluates to false");
    }
    return 0;
}
