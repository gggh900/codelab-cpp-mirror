#include <iostream>

int main() {
    int x = 10;
    const int M = 5;
    int * const ptr = &x;
    (*ptr)++; // OK

     //ptr++;
    //ptr = &M; // error

}
