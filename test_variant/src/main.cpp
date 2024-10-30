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
    std::print("m1: {}, {}\n", m1.id, m1.name);
    if (std::holds_alternative<std::string>(m1.value)) {
        std::print("holds a sting\n");
    }
    if (std::holds_alternative<int>(m1.value)) {
        std::print("holds an int\n");
    }
    if (std::holds_alternative<double>(m1.value)) {
        std::print("holds a double\n");
    }
    if (const auto v = std::get_if<int>(&m1.value)) {
        std::print("got int: {}\n", *v);
    }
    return 0;
}
