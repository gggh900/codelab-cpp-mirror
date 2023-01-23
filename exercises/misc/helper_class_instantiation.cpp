#include <iostream>

using namespace std;

class T1 {
public: 
    T1(int p1) : val(p1)
    {   
        cout << "T1 constructor entered." << endl;
    }
    int val;
};

int main() {
    T1 t1(100);
    cout << "t1.val: " << t1.val << endl;
}
