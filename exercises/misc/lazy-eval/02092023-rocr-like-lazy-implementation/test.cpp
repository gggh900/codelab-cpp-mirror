#include <memory>
#include <utility>
#include <functional>
#include <iostream>
#include "test.h"
#include <typeinfo>

/*void f1(void) {
    std::cout << "f1..." << std::endl;
    return;
}
void f2(void) {
    std::cout << "f2..." << std::endl;
    return;
}
*/

void c1::c1_f1(void) {

    //auto queue_lambda = [this]() {... };

    auto f1_lambda = [this]() {
        std::cout << "f1_lambda entered." << std::endl;
        //c1 c1local;
        //return c1local;
        q1 * q1_ptr;
        q1_ptr = new q1();
        return q1_ptr;
    };

    //c1_q1[0].reset(f1_lambda);
    c1_q1[0].reset([f1_lambda, this]() { return f1_lambda(); });
    //std::cout << "&c1_q1[0]: " << &c1_q1[0] << std::endl;

    c1_q1[0]->print_q1();
    /*
    std::cout << "DBG: f1_lambda: " << typeid(f1_lambda).name() << std::endl;
    std::cout << "DBG: type c1_q1: " << typeid(c1_q1).name() << std::endl;
    std::cout << "DBG: type c1_q1[0]: " << typeid(c1_q1[0]).name() << std::endl;
    */
    //std::cout << " &c1_q1[0]: " << &c1_q1[0] << std::endl;
    //c1_q1[0]->print_q1();
}

int main() {
    
    // lazy pointer, pass c1 class, name c1_lazy with 3 array members. o

    // create standard function based on f1 named f1_std.
    //std::function<void(void)> f1_std = f1;

    // instantiate c1.

    c1 c1i;
    //std::cout << "DBG/ADDR: type c1 c1i: " << typeid(c1i).name() << &c1i << std::endl;
    c1i.c1_f1();
    //std::cout << "DBG/ADDR: type c1i.c1_f1(): " << typeid(c1i.c1_f1()).name() << "??" << std::endl;
}
