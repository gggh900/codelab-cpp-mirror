#include <iostream>
#include <atomic>
#include <assert.h>
#include <thread>

std::atomic<bool> x,y;
std::atomic<int> z;

using namespace std;

void write_x_then_y() 
{
    y.store(true,std::memory_order_relaxed);
    x.store(true,std::memory_order_release);
}

void read_y_then_x() {
    while(!y.load(std::memory_order_acquire));
    if(y.load(std::memory_order_relaxed))
        ++z;
}

int main() 
{
    x=false;
    y=false;
    z=0;
    std::thread a(write_x_then_y);
    std::thread b(read_y_then_x);
    a.join();
    b.join();
    assert(z.load()!=0);
}
