/*
Passing class member function as an argument.
"...If you are familiar with the std::bind, the parameter passing semantics will be unsurprising, because
both the operation of the std::thread constructor and the operation of std::bind are defined in terms of 
same mechanism...??? This means that for example, you can pass a member function pointer as the function, 
provided you supply a suitable pointer as first argument:
*/
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
};

int main() {
    X my_x;
    std::thread t(&X::do_lenghty_work, &my_x);
    t.join();
}
