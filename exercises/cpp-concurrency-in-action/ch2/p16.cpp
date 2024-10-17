/* This is similar to p13.cpp except it is using example of callable object, in this case
class with () operator defined */
#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello concurrent world.\n";
}

class background_task {
    public:
        void operator()() const {
            std::cout << "background_task::operator()() entered...";
        }
};

int main() {
    //std::thread t(hello);
    background_task f;
    std::thread my_thread(f);

/*
From  https://en.cppreference.com/w/cpp/thread/thread/join
Blocks the current thread until the thread identified by *this finishes its execution.
The completion of the thread identified by *this synchronizes with the corresponding 
successful return from join(). No synchronization is performed on *this itself. Concurrently 
calling join() on the same thread object from multiple threads constitutes a data race that 
results in undefined behavior. 
*/
    my_thread.join();
}
