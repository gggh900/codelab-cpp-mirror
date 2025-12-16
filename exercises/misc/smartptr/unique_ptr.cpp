#include <iostream>
#include <memory>
using namespace std;

#define TRIG_ERR 0

//  Uncomment to trig runtime error due to unalloc p1.

//#define TRIG_ERR 1

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

    // both pointer and data is init-d.

    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << "P1 area: " << P1->area() << endl;

    // pointer is initialized but no data initialization.

    unique_ptr<Rectangle> P2;

    // Copy the addres of P1 into p2

    P2 = move(P1);
    cout << "P2 area: " << P2->area();

    #if TRIG_ERR == 1
        cout << "P1 area: " << P1->area();
    #endif

    cout << std::endl ;
    return 0;
}
