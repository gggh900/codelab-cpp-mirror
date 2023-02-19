#include <memory>
#include <utility>
#include <functional>
#include <iostream>
#include "test.h"
#include <typeinfo>

/* PRINT_SMART_PTR: c1_q1[0] -> returns lazy pointer obj will get unique_ptr member (changed to public) -> get() will call
unique_ptr obj's get() method to print out T * rawPtr in obj.
- in other words, PRINT_SMART_PTR prints:
class lazy_ptr {
    class std::unique_ptr { // let's say we implemented the std::unique_ptr inside lazy_ptr perfectly.
        raw * Ptr;
    }
    unique_ptr <T> obj 
}

- put in another way, it should print out pointer to T* in our case, pointer to class q1 instance.

*/

//#define PRINT_LAZYPTR_STATE  \
//    std::cout << "c1_q1[0].obj.get(): "  << c1_q1[0].obj.get() << ", c1_q1[0].func: " << c1_q1[0].func << std::endl;

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
    //c1_q1[0].reset([f1_lambda, this]() { return f1_lambda(); });
    c1_q1[0].print_state();
    c1_q1[0].reset(f1_lambda);
    c1_q1[0].touch();
    c1_q1[0].print_state();

    q1 * q1_ptr_2;
    q1_ptr_2 = new q1();

    // it is unclear commenting line c1_q1[0].reset(q1_ptr_2); causes  c1_q1[0]->print_q1(); to fail as it seems 
    // opposite should be the case (since reset(T* ptr resets func).
    
    c1_q1[0].reset(q1_ptr_2);
    c1_q1[0].print_state();
    c1_q1[0]->print_q1();
    c1_q1[0];

    /*
    if (c1_q1[0] == c1_q1[1]) {
        std::cout << "c1_q1[0] and [1] are equal" << std::endl;
    } else {
        std::cout << "c1_q1[0] and [1] are NOT equal" << std::endl;
    }*/
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
