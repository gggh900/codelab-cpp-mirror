/*
std::move example.
*/
#include <iostream>
#include <thread>
#include <chrono>

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
void some_function() { cout << "some_function entered...\n" ; }
void some_other_function() { cout << "some_other_function entered ...\n"; }

int main() {
    std::thread t1(some_function);
    // t1
    std::thread t2=std::move(t1);
    // t2
    t1=std::thread(some_other_function);
    // t2, t1
    std::thread t3;
    t3=std::move(t2);
    // t3, t1
    t1.join();
    t3.join();
    //t1=std::move(t3);
    //t1.join();
}
