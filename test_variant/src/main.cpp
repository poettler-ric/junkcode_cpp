#include <optional>
#include <print>
#include <string>
#include <variant>

class Material {
   public:
    int id;
    std::string name;
    std::variant<int, double, std::optional<std::string>> value;
};

int main() {
    Material m1{1, "testmat", 5};
    std::println("m1: {}, {}", m1.id, m1.name);
    if (std::holds_alternative<int>(m1.value)) {
        std::println("holds an int");
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

    Material m_string{1, "testmat", "something"};
    if (const auto ov =
            std::get_if<std::optional<std::string>>(&m_string.value)) {
        if (const auto v = *ov) {
            std::println("m_string: {}", *v);
        }
    }

    Material m_null{1, "testmat", std::nullopt};
    if (const auto ov =
            std::get_if<std::optional<std::string>>(&m_null.value)) {
        if (const auto v = *ov) {
            std::println("m_null: {}", *v);
        } else {
            std::println("m_null: get_if evaluates to true but value is null");
        }
    }

    return 0;
}
