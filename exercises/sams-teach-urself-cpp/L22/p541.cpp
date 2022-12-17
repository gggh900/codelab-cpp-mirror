// struct that can behave as a unary function.

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename elementType>
struct DisplayElementKeepCount {
    int count;
    void operator () (const elementType & element) {
        ++ count;
        cout << element << endl;
    }
    DisplayElementKeepCount () { count = 0; }
};

int main () {
    vector <int> numsInVec{0,1,2,3,-1,-9,0,-999};
    cout << "Vector of integers contains: " << endl;

    DisplayElementKeepCount<int> result;
    result = for_each (numsInVec.begin(), numsInVec.end(), DisplayElementKeepCount<int> ());
    
    cout << "Functor invoked " << result.count << " times." << endl;
    // Display the list of characters.

    list <char> charsInList{'a', 'z', 'k', 'd'};
    cout << endl << "List of characters contains: " << endl;

    for_each (charsInList.begin(), charsInList.end(), DisplayElementKeepCount<char>());        
}

