#include <iostream>
#include <string>
using namespace std;

class Human {
private:
    string name;
    int age;

public:
    Human(string humansName, int humansAge) {
        name = humansName;
        age = humansAge;
        cout << "overloaded constructor created name and age: " << name << age << endl;
    }

    void IntroduceSelf() {
        cout << "I am " << name << " and age " << age << endl;
    }
};

int main() {
    Human firstMan("Adam", 25);
    Human firstWoman("Eve", 28);
    Human binary("Binary");
    firstMan.IntroduceSelf();
    firstWoman.IntroduceSelf();
}
