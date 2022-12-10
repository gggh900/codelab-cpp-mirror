#include <iostream>
using namespace std;

class Fish {
protected:
    bool isFreshWaterFish;

public:
    Fish(bool isFreshWater) : isFreshWaterFish(isFreshWater) {}

    void Swim() {
        if (isFreshWaterFish) 
            cout << "Swims in lake."  << endl;
        else
            cout << "Swims in ocean." << endl;
    }    
};

class Tuna: public Fish {
public:
    Tuna() : Fish(false) {}
};

class Carp: public Fish {
public:
    Carp() : Fish(true) {}
};

int main() {
    Carp myLunch;
    Tuna myDinner;

    cout << "About my food " << endl;
    cout << "Lunch: ";
    myLunch.Swim();

    cout << "Dinner: ";
    myDinner.Swim();

    return 0;
}
