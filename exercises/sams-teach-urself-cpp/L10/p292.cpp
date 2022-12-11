#include <iostream>

using namespace std;

class Motor {
public:
    void SwitchIgnition () {
        cout << "Ignition ON" << endl;
    }
    void PumpFuel() {
        cout << "Fuel in cylinders" << endl;
    }
    void FireCylinders() {
        cout << "Vroom" << endl;
    }
};

class Car:private Motor  {
public:
    void Move() {
        SwitchIgnition();
        PumpFuel();
        FireCylinders();
    }
};

int main() {
    Car myDreamCar;
    myDreamCar.Move();

//  Uncomment to cause compiler error since main() can not access Car's SwitchIgnition due to it is private in 
//  privately inherited class.
//  myDreamCar.SwitchIgnition();
    return 0;
}
