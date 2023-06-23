#include <iostream>
#include <string>

template <typename A1, typename A2, typename A3>
class classA {
    private:
    A1 a1;
    A2 a2;
    A3 a3;
};

template <typename B1, typename B2>
class classB {
    private:
    B1 b1;
    B2 b2;
};

int main() {
    classA<int, float, long>inst_a1;
    classB<int, float>inst_b;
    classA<int, classB<float, long>, long>inst_b2;
    return 0;
}
