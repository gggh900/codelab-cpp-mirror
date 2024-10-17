/* This is similar to p13.cpp except it is using example of callable object, in this case
class with () operator defined */

#include <iostream>
#include <thread>
#include <chrono>

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

void f(int i, string const & s) {
    cout << "f(int i, string const & s) is entered..." << endl;
    cout << "i: "<< i<< ", s: "<< s << endl;
    this_thread::sleep_for(chrono::seconds(2)); // Simulate some work}
}

void oops(int some_param) {
    char buffer[1024];
    sprintf(buffer, "%i", some_param);

    // thread parameters: (<function_name>, [<function_name_parameters>])

    thread t(f,3,buffer);
    t.detach();
}
int main() {
    oops(8);
    this_thread::sleep_for(chrono::seconds(3));
}
