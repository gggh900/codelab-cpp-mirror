#include <iostream>

int main() {
    int K = 10;
    const int M = 5;
    const int * ptr;
    ptr = &K;
    // uncomment to cause error. because value pointed by ptr is not supposed to change.
    (*ptr)++;
    K++;
    ptr++; // error
    ptr = &M; // OK

}
