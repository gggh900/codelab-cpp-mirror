// class does not permit copying. To implement that, places all constructor under private 
// by uncomming private: line in this working example.

#include <iostream>
#include <string>

using namespace std;

class President {
public:
//private:
    President() { 
        cout << "constructor..." << endl;        
    }
    President(const President&) {                    // private copy constructor.
        cout << "copy constructor..." << endl;        
    }
    President &operator=(const President&) {    // private copy assignment operator.
        cout << "copy assignment constructor..." << endl;        
    }
};

int main () {
    President p1;
    President p2(p1);
    President p3;
    p3 = p1;
}
