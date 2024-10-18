/*
Same as p24b.cpp plus do_lenghty_work_with_param added showing how to pass arg to member function */
#include <iostream>
#include <thread>
#include <chrono>

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

class X {
    public:
        void do_lenghty_work() {
            cout << "do_lengthy_work() entered....\n";
        }
        void do_lenghty_work_with_param(int x) {
            cout << "do_lengthy_work(x: " << x << ") entered....\n";
        }
};

int main() {
    X my_x;
    std::thread t(&X::do_lenghty_work_with_param, &my_x, 5);
    t.join();
}
