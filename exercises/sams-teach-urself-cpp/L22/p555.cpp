// struct that can behave as a unary function.

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
template <typename elementType>
struct DisplayElementKeepCount {
    int count;
    void operator () (const elementType & element) {
        ++ count;
        cout << element << endl;
    }
    DisplayElementKeepCount () { count = 0; }
};
*/
int main () {
    vector <int> numsInVec{0,1,2,3,-1,-9,0,-999};
    list <char> charsInList{'a', 'z', 'k', 'd'};

    cout << "Display elements in a vector using a lamba: " << endl;
    for_each (numsInVec.begin(), numsInVec.end(), [](const int & element) { cout << element << ' ' << endl; } );
    
    cout << "Display elements in a list using lambda" << endl;

    for_each (charsInList.begin(), charsInList.end(), []( const char & element) { cout << element << ' ' << endl; } );        
}

