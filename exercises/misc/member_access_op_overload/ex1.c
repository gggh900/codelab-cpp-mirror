// https://www.ibm.com/docs/en/xcfbg/121.141?topic=operators-overloading-class-member-access

#include <iostream>

struct Y {
  void f() {  std::cout << "f() entered..." << std::endl; };
};

struct X {
    Y* ptr;
    Y* operator->() {
    return ptr;
    };
};

int main() {
    X x;
    x->f();
}
