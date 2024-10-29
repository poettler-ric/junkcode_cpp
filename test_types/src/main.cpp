#include <print>

int main() {
  int i = -100;
  unsigned int j = 10;
  auto k = i + j;
  std::print("result: {}\n", k);
}
