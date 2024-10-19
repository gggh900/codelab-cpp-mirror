/* This is similar to p13.cpp except it is using example of callable object, in this case
class with () operator defined */

#include <iostream>
#include <thread>

using namespace std;

#define DEBUG 1

class thread_guard 
{
    std::thread  & t;
public:
    explicit thread_guard(std::thread& t_) : t(t_) 
    {}

    ~thread_guard() 
    {
        if(t.joinable())
        {
            t.join();
        }
    }

    thread_guard(thread_guard const & )=delete;
    thread_guard & operator=(thread_guard const )=delete;
};

struct func {
    int & i;
    
    func(int & i_) : i(i_){
        if (DEBUG == 1) {
            std::cout << "func::func() (constructor) entered..." << std::endl;
        }
    };

    void operator() () {
        if (DEBUG == 1) {
            std::cout << "func::operator() entered..." << std::endl;
        }

        for (unsigned j=0; j < 1000000 ; ++j) {
            if (j % 100000 == 0) {
                std::cout << "loop idx j: " << j << ", i: " << i << std::endl;
            }
        }
        this_thread::sleep_for(chrono::seconds(3));
    }
};

void do_something_in_current_thread() {
    cout << "do_something_in_current_thread() entered...\n";
}
void f() {
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);

    do_something_in_current_thread();
}

int main() {
    f();
}
