/* Thread-safe stack implementation.*/

#include <exception>
#include <memory>
#include <stack>
#include <mutex>
#include <iostream>
#include <utility>

using namespace std;

hierarchical_mutex high_level_mutex(10000);
hierarchical_mutex low_level_mutex(5000);

int do_low_level_stuff() {
    cout << "do_low_level_stuff entered..." << endl;
}

// high_level_stuff ? function ?

int do_other_stuff() {
    cout << "do_other_stuff entere..." << endl;
}

int low_level_func() {
    std::lock_guard<hierarchical_mutex> lk(low_level_mutex);
    return do_low_level_stuff();
}

int high_level_func() {
    std::lock_guard<hierarchical_mutex> lk(high_level_mutex);
    high_level_stuff(low_level_func());
}

void thread_a() {
    high_level_func();
}

hierarchical_mutex other_mutex(100);

void other_stuff() {
    high_level_func();
    do_other_stuff();
}

void_thread_b() {
    std::lock_guard<hierarchical_mutex> lk(other_mutex);
    other_stuff();
}
int main() {
    
}
