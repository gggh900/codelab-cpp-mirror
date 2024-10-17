#include <iostream>
#include <thread>
#include <chrono>

void hello() {
    std::cout << "Hello concurrent world.\n";
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
    std::this_thread::sleep_for(std::chrono::seconds(1));

}
