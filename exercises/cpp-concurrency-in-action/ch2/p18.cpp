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
            std::cout << "background_task::operator()() entered...\n";
        }
};

#define DEBUG 1
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
    }
};
int main() {
    /*std::thread t(hello);
    background_task f;
    std::thread my_thread(f);
    */

    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);

    /*Detach() does nothing ?? not sure what happened.. join will print out j-loop.*/
    my_thread.detach();
    //my_thread.join();
}
