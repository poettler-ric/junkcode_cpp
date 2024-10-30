#include <chrono>
#include <iostream>
#include <vector>

static const unsigned int Elements = 100000;
static const unsigned int Iterations = 200;

void doAppend() {
    std::vector<unsigned int> v;
    for (unsigned int i = 0; i < Elements; ++i) {
        v.push_back(i);
    }
}

void doReserve() {
    std::vector<unsigned int> v;
    v.reserve(Elements);
    for (unsigned int i = 0; i < Elements; ++i) {
        v.push_back(i);
    }
}

void doAllocate() {
    std::vector<unsigned int> v;
    v.resize(Elements);
    for (unsigned int i = 0; i < Elements; ++i) {
        v[i] = i;
    }
}

void test(const char* name, void (*fn)(void)) {
    std::cout << name << ": ";

    auto start = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < Iterations; ++i) {
        fn();
    }
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = end - start;
    std::cout << std::chrono::duration<double, std::milli>(elapsed).count()
              << "ms\n";
}

int main() {
    std::cout << "Elements: " << Elements << ", Iterations: " << Iterations
              << '\n';

    test("doAppend", doAppend);
    test("doReserve", doReserve);
    test("doAllocate", doAllocate);
}