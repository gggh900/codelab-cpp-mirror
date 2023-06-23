#include <iostream>
#include <string>

template <typename A, typename B, typename C>
struct A1 {
    A a1;
    B b1;
    C c1;
};
template <typename A, typename B, typename C = long>

struct B1 {
    A a1;
    B b1;
    C c1;
};

int main() {
    struct A1<int, float, long>inst_a;
    inst_a.a1 = 100;
    inst_a.b1 = 150.0;
    inst_a.c1 = 200;
    std::cout << inst_a.a1 << std::endl;
    struct A1<int, float>inst_a1;

    struct B1<int, float, std::string>inst_b;
    struct B1<int, float>inst_b1;
    return 0;
}
