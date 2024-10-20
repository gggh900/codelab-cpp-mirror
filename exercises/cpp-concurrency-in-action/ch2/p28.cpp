/* This is similar to p13.cpp except it is using example of callable object, in this case
class with () operator defined */

#include <iostream>
#include <thread>
#include <vector>
#include <functional>

using namespace std;

#define DEBUG 1

void do_work(unsigned id) {
    cout << "do_work entered with id: " << id << endl; 
}

void f() {
    std::vector<std::thread> threads;
    for (unsigned int i = 0 ; i < 20 ; i ++ ) {
        threads.push_back(std::thread(do_work, i));
    }
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}

int main() {
    f();
}
