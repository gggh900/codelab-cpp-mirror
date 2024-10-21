#include <iostream>

class X {
    int x;
public:
    void func1() const {
        //x++;
        this->func2();
    }
    
    void func2() {}
};

int main() {
    X x;
    x.func1();
}
