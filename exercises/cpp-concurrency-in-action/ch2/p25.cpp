/*
std::move example.
*/
#include <iostream>
#include <thread>
#include <chrono>

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
//typedef int big_object;
class big_object {
    public:
        int x;

    void prepare_data(int pX) { this->x = pX; } 
};

void process_big_object(std::unique_ptr<big_object>) {
    cout << "process_big_object() entered...\n";
}
int main() {
    std::unique_ptr<big_object> p(new big_object);
    cout << "p managed pointer value: " << p.get() << endl;
    p->prepare_data(42);
    std::thread t(process_big_object, p); //<-- tried to see if cout after t.join() will printer same address but huge compiler error.
    //std::thread t(process_big_object, std::move(p));
    t.join();
    cout << "p managed pointer value: " << p.get() << endl;
}
