/*Example from p24 is somewhat changed but idea is same. int used instead of widget_data 
if int is passed as reference int i &, it results in compile error, not sure why. Only as a value
it compiles. 
With p24a (this file), once std::ref is used, compile error is eliminated. Still uncertain why 
p24.cpp fails with data passed as reference. 
*/
#include <iostream>
#include <thread>
#include <chrono>

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

// does not work: void update_data_for_widget(int id, int & pData) {
void update_data_for_widget(int id, int & pData) {
    cout << "update_data_for_widget(int &) entered..." << endl;
    cout << "pData in (" << &pData << "): " << pData << endl;
    pData += 1;
    cout << "pData out(after increment): " << pData << endl;
}

void oops_again(int some_param) {
    int data = 10;
    cout << "data before update(" << &data << "): " << data << endl;
    std::thread t(update_data_for_widget, 1, std::ref(data));
    t.join();
    cout << "data after update: " << data << endl;
}
int main() {
    oops_again(8);
    this_thread::sleep_for(chrono::seconds(3));
}
