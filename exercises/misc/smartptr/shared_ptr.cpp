#include <iostream>
#include <memory>
using namespace std;

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }
    int area() { return length * breadth; }
};

int main() {

    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << "P1 area: " << P1->area() << endl;

    shared_ptr<Rectangle> P2;

    // P1 and P2 are pointing
    // to same object
    P2 = P1;
    cout << "P2 area: " << P2->area() << endl;
    cout << "P1 area: " << P1->area() << endl;
    cout << "use count P1: " << P1.use_count() << endl;
    cout << "use count P2: " << P2.use_count() << endl;
    cout << endl;  
    return 0;
}
    
