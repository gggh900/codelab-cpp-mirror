#include <iostream>
using namespace std;

struct StructA {
    StructA() { cout << "StructA constructor" << endl; }
    ~StructA() { cout << "StructA destructor" << endl; }
};

struct StructB {
    StructB() { cout << "StructB constructor" << endl; }
    ~StructB() { cout << "StructB destructor" << endl; }
};

void FuncB () {
    cout << "In function B" << endl;
    StructA objA;
    StructB objB;
    cout << "About to throw up! " << endl;
    throw "Throwing for the heck of it.";
}

void FuncA() {
    try {
        cout << "In function A" << endl;
        StructA objA;
        StructB objB;
        FuncB();
        cout << "About to throw up! " << endl;
        throw "Throwing for the heck of it."; 
    } catch (const char * exp) {
        cout << "FuncA: Caught an exception: " << exp << endl;
        cout << "Handled it, will not throw to caller" << endl;
        //throw;
    }
}

int main () {
    cout << "main(): Started execution" << endl;
    try {
        FuncA();
    } catch (const char * exp) {
        cout << "Exception: " << exp << endl;
    }
    cout << "main(): exiting gracefully." << endl;
    return 0;
}
