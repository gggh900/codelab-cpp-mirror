#include <iostream>
#include <atomic>
#include <assert.h>
#include <thread>

std::atomic<bool> x,y;
std::atomic<int> z;

using namespace std;

#define DEBUG 0

void write_x() {
    if (DEBUG==1) 
        cout << "write_x entered" << endl;
    x.store(true,std::memory_order_seq_cst);
}

void write_y() {
    if (DEBUG==1) 
        cout << "write_y entered" << endl;
    y.store(true,std::memory_order_seq_cst);
}

void read_x_then_y() {
    if (DEBUG==1) 
        cout << "read_x_then_y entered" << endl;
    while(!x.load(std::memory_order_seq_cst));
    if(y.load(std::memory_order_seq_cst))
        ++z;
}

void read_y_then_x() {
    if (DEBUG==1) 
        cout << "read_y then_x entered" << endl;
    while(!y.load(std::memory_order_seq_cst));
    if(x.load(std::memory_order_seq_cst))
        ++z;
}

int main() {
    x=false;
    y=false;
    z=0;
    std::thread a(write_x);
    std::thread b(write_y);
    std::thread c(read_x_then_y);
    std::thread d(read_y_then_x);
    a.join();
    b.join();
    c.join();
    d.join();
    cout << "z: " << z << endl; 
    assert(z.load()!=0);
}
