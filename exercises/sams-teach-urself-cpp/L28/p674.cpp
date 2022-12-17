#include <iostream>
using namespace std;

int main () {
    cout << "Enter number of integers you wish to reserve: ";
    try {
        int input = 0;
        cin >> input;

        int * numArray = new int [input];
        delete[] numArray;
    } catch (std::bad_alloc & exp) {
        cout << "Exception occurred." << exp.what() << endl;
    }
    return 0;
}
