// upcasting example. Result is not aligned with book expectation.
// book expects: casting derived to base can be done without explicit casting 
// but results in compile error.

#include <iostream>
using namespace std;

class Base {
public:
};

class Derived {
public:
};


int main() {

    Derived objDerived;
    Base * objBase;
    //Base * objBase = static_cast<Base*>&objDerived;

    Derived * objDer = dynamic_cast<Derived*> (objBase);
}
