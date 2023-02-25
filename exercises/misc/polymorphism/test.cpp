#include <iostream>

class Base {
public:
    virtual void vf1() {
        std::cout << "base.vf1.entered." << std::endl;
    }
    void f1() {
        std::cout << "base.f1.entered." << std::endl;
    }
};

class Derived : public Base {
public:
    virtual void vf1() {
        std::cout << "derived.vf1.entered." << std::endl;
    }
    void f1() {
        std::cout << "derived.f1.entered." << std::endl;
    }
};

void f2ext(Base & pBase) {
    pBase.f1();
    pBase.vf1();
}
int main() {
    Derived d1;
    Base * b1;
    f2ext(d1); 
    d1.f1();
    d1.vf1();
    b1 = &d1;
    b1->f1();
    b1->vf1();
    Base b2;
    
//    std::cout << "b2: f1/vf1: " << &(b2.f1) << "/" &(b2.vf1) << std::endl;
//    std::cout << "d1: f1/vf1: " << &(d1.f1) << "/" &(d1.vf1) << std::endl;
    std::cout << "f2ext: " << &f2ext << std::endl;
}
