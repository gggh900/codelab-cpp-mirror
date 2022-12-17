#include <iostream>
#include <memory>
using namespace std;

// set this 1 to cause unique ptr copy assignment failure.

#define ENABLE_FAILURE 0
class Fish {
public:
    Fish() {
    cout << "Constructed Fish." << endl;
    }

    virtual ~Fish() {
        cout << "Destructed Fish." << endl;
    }

    void MakeFishSwim(Fish & inputFish) {
        inputFish.Swim();
    }

    void Swim() {
        cout << "Tuna swims real fast." << endl;
    }
};

class Tuna: public Fish {
public:
    Tuna () {   
        cout << "Constructed Tuna." << endl;
    }

    ~Tuna() {
    cout << "Destructed Tuna." << endl;
    }

    void Swim() {
        cout << "Tuna swims real fast." << endl;
    }
};

int main() {
    unique_ptr<Fish> smartFish (new Fish);
    smartFish->Swim();

    unique_ptr<Fish> copySmartFish;

    #if  ENABLE_FAILURE==1
    copySmartFish = smartFish;
    #endif
}
