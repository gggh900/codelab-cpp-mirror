#include <iostream>
#include <memory>
using namespace std;

int main() {
    
    // Pointer declaration
    auto_ptr<int> ptr1(new int(10));
    cout << "*ptr1: " << *ptr1 << endl;
    
    // Transfer ownership to
    // pointer ptr2, 
    auto_ptr<int> ptr2 = ptr1;
    cout << "*ptr2: " << *ptr2;
    cout << std::endl;
    return 0;
}
