#include <functional>
#include <iostream>

using namespace std;

main() {
    function <int(int)> func;

    auto f1_l = [] (int p1) {
        cout << "Entered f1_l(" << p1 << ")..." << endl;
        return p1 + 100;
    };

    bool avail;
    avail = func ? 1 : 0;
    cout << "func before assignment:                        " << &func << ", target_type: " << func.target_type().name() << ", avail?: " << avail << endl; 
    func = f1_l;
    avail = func ? 1 : 0;
    cout << "func after  assignment(lambda function:        " << &func << ", target_type: " << func.target_type().name() << ", avail?: " << avail << endl; 
    
    //cout << func(100) << endl;
    //cout << "function: " << func << endl;
}

