#include <cmath>
#include <print>

int main() {
  const auto a = 5.0;
  const auto b = 3.0;
  const auto c = 6.0;

  const auto alpha = std::acos(
      (std::pow(b, 2) + std::pow(c, 2) - std::pow(a, 2)) / (2 * b * c));
  const auto beta = std::acos(
      (std::pow(a, 2) + std::pow(c, 2) - std::pow(b, 2)) / (2 * a * c));
  const auto gamma = std::acos(
      (std::pow(a, 2) + std::pow(b, 2) - std::pow(c, 2)) / (2 * a * b));

  std::println("alpha: {}", alpha);
  std::println("beta: {}", beta);
  std::println("gamma: {}", gamma);

  return 0;
}
