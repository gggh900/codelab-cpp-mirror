// struct that can behave as a unary function.

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename elementType>
struct DisplayElement {
    void operator () (const elementType & element) const {
        cout << element << endl;
    }
};

int main () {
    vector <int> numsInVec{0,1,2,3,-1,-9,0,-999};
    cout << "Vector of integers contains: " << endl;
    for_each (numsInVec.begin(), numsInVec.end(), DisplayElement<int> ());
    
    // Display the list of characters.

    list <char> charsInList{'a', 'z', 'k', 'd'};
    cout << endl << "List of characters contains: " << endl;

    for_each (charsInList.begin(), charsInList.end(), DisplayElement<char>());        
}

