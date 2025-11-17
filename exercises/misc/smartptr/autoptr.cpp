#include <iostream>
#include <memory>
using namespace std;
#define TRIG_ERR 0

// Uncomment to trigger runtime error due to unallocated ptr usage/printout.
//#define TRIG_ERR 1

int main() {
    
    // Pointer declaration
    auto_ptr<int> ptr1(new int(10));
    cout << "*ptr1: " << *ptr1 << endl;
    
    // Transfer ownership to
    // pointer ptr2, 
    auto_ptr<int> ptr2 = ptr1;
    cout << "*ptr2: " << *ptr2;
    cout << std::endl;

    #if TRIG_ERR == 1 
        cout << "*ptr1: " << *ptr1 << endl;
    #endif
    return 0;
}
