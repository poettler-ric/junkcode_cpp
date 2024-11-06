#include <fstream>
#include <print>

int main() {
    int ivalue;
    float fvalue;
    double dvalue;

    std::ifstream input{"fdump", std::ios::binary};
    input.read(reinterpret_cast<char *>(&ivalue), sizeof(int));
    input.read(reinterpret_cast<char *>(&fvalue), sizeof(float));
    input.read(reinterpret_cast<char *>(&dvalue), sizeof(double));

    std::println("ivalue: {}", ivalue);
    std::println("fvalue: {}", fvalue);
    std::println("dvalue: {}", dvalue);

    return EXIT_SUCCESS;
}
