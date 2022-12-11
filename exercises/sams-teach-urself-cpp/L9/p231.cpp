// Same as p229 however, default value is defined for constructor parameters so that
// Human binary("Binary") can be compiled which is missing to supply second parameter.

#include <iostream>
#include <string>
using namespace std;

class Human {
private:
    string name;
    int age;

public:
    Human(string humansName, int humansAge = 70) {
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
    binary.IntroduceSelf();
}
