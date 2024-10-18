/*tried doing interesting mod by inheriting std::thread as thread_dbg and inserting debugging messages*
(INCOMPLETE!!)/
#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello concurrent world.\n";
}

class thread_dbg : public std::thread {
    thread() {
        std::thread() {
        }
    }
}

int main() {
    std::thread t(hello);

/*
From  https://en.cppreference.com/w/cpp/thread/thread/join
Blocks the current thread until the thread identified by *this finishes its execution.
The completion of the thread identified by *this synchronizes with the corresponding 
successful return from join(). No synchronization is performed on *this itself. Concurrently 
calling join() on the same thread object from multiple threads constitutes a data race that 
results in undefined behavior. 
*/
    //t.join();
    t.detach();
}
