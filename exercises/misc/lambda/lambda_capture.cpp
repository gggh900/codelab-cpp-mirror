//https://www.appsloveworld.com/cplus/100/20/difference-between-capturing-and-passing-an-argument-in-lambda-functions

#include <iostream>
using namespace std;

int main(int argc,char **argv)   {
    auto i=5;

    // at this point, when lambda declared [i] appears to capture value of i=5.
    // this value was maintained throughout the loop below, even though i itself 
    // was changed during loop. j will pass the actual value of updated of i value.

    auto f = [i](int j) {
        cout<<"capture i="<<i<<", passing i as j="<<j<< endl; 
        cout << "inside lambda:" << endl;
        cout << "i: " << i << endl;
        cout << "j: " << j << endl;
    };
    while (i<30) {
        cout << "======" << endl;
        i += 10;
        cout << "i outside lambda: " << i << endl;
        f(i);
    }
}
