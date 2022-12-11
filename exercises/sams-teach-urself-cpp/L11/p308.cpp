#include <iostream>
using namespace std;

class Fish {
public:
    virtual void Swim() {
    // comment above and uncomment below to remove polymorphic behavior.
    //void Swim() {
        cout << "Fish swims!" << endl;
    }    
};

class Tuna: public Fish {
public:
    void Swim() {
        cout << "Tuna swims." << endl;
    }
};

class Carp: public Fish {
public:
    void Swim() {
        cout << "Carp swims." << endl;
    }
};

void MakeFishSwim(Fish & inputFish) {
    inputFish.Swim();
}

int main() {
    Tuna MyDinner;
    Carp MyLunch;
    
    MakeFishSwim(MyDinner);
    MakeFishSwim(MyLunch);
    return 0;
}
