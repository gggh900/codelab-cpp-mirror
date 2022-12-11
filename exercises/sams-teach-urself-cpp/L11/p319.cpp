// Fixes problem of derived class's destructor not being called.
// Uncomment "Fish MyBreakFast to cause compiler error due to the fact Fish is abstract
// base class.

#include <iostream>
using namespace std;

class Fish {
public:
    virtual void Swim() = 0;
};

class Tuna: public Fish {
public:
    void Swim() {
        cout << "Tuna swims fast." << endl;
    }
};

class Carp: public Fish {
    void Swim() {
        cout << "Carp swims slow." << endl;
    }
};

void MakeFishSwim(Fish & inputFish) {
    inputFish.Swim();
}

int main() {
    Carp MyLunch;
    Tuna  MyDinner;
    Fish MyBreakfast;

    MakeFishSwim(MyLunch);
    MakeFishSwim(MyDinner);
    
    return 0;
}
