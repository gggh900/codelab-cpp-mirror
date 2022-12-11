#include <iostream>
using namespace std;

class Fish {
public:
    Fish() {
        cout << "Constructed Fish." << endl;
    }

    ~Fish() {
        cout << "Destructed Fish." << endl;
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
};

void DeleteFishMemory(Fish * pFish) {
    delete pFish;
}

int main() {
    cout << "Allocating a Tuna on the free store:" << endl;
    Tuna * pTuna = new Tuna;
    cout << "Deleting the Tuna: " << endl;
    DeleteFishMemory(pTuna);

    cout << "Instantiating a Tuna on the stack:" << endl;
    Tuna MyDinner;
    cout << "Automatic destruction as it goes out of scope." << endl;
    
    return 0;
}
