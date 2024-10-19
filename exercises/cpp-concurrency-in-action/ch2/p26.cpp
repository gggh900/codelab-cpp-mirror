/*
std::move example.
*/
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
void some_function() { 
    cout << "some_function entered...\n" ; 
    this_thread::sleep_for(chrono::seconds(3));
}
void some_other_function() { 
    cout << "some_other_function entered ...\n"; 
    this_thread::sleep_for(chrono::seconds(3));
}

int main() {
    std::thread t1(some_function);
    // t1: some_function
    std::thread t2=std::move(t1);
    // t2: some_function
    t1=std::thread(some_other_function);
    // t1: some_other_function (final)
    t1.join();

    std::thread t3;
    t3=std::move(t2);
    // t3: some_function (final)
    t3.join();
}
