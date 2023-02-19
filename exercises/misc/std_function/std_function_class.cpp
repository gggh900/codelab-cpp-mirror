#include <functional>
#include <iostream>

using namespace std;

class c1 {
    void operator () () {
        cout "DBG: c1::operator() is entered...";
    }
    ostream& operator<<(ostream& os, int p1, int p2) {
        cout "DBG: c1::operator<< is entered...";
    } 
};

main() {
    function <int(int)> func;

    /*
    auto f1_l = [] (int p1) {
        cout << "Entered f1_l(" << p1 << ")..." << endl;
        return p1 + 100;
    };*/

    func = c1;
    cout << "function: " << func << endl;

}

