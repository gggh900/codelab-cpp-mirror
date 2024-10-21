// polymorphism, plain example: Tuna nad Carp is derived from Fish. When calling makeFishSwim(), 
// it is passed on as baseclass which behaves differently (based on derived base) inside the 
// makeFishSwim().

#include <iostream>
#include <vector>

using namespace std;

class Fish {
public:
    void Swim() {
    // comment above and uncomment below to remove polymorphic behavior.
    //void Swim() {
        cout << "Fish swims!" << endl;
    }    
    Fish operator->() {
        return operator->();
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
    Fish * MyMeal;

    //MakeFishSwim(MyDinner);
    //MakeFishSwim(MyLunch);

    vector<Fish *> Meals;
    Meals.push_back(&MyDinner);
    Meals.push_back(&MyLunch);
    /*
    for (auto i = Meals.begin(); i !=  Meals.end(); i++ ) {
        printf("%x\n". i);
        //i->Swim();
    }*/
    for (int i = 0 ; i <= sizeof(Meals)/sizeof(Fish); i++ ) {
        printf("%d. %x.\n", i, Meals[i]);
        Meals[i]->Swim();
    }
    return 0;
}
