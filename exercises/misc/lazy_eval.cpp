//https://bartoszmilewski.com/2014/04/21/getting-lazy-with-c/
#include <iostream>

void printNTriples(int n) {
    int i = 0;
    for (int z=1 ; ; ++z) {
        for (int x =1 ; x <= z; x++) {
            for (int y = x ; y <= z; y++ ) {
                if (x*x + y*y == z*z) {
                    printf("%d, %d, %d\n", x,y,z);
                    if (++i == n) {
                        return ;
                    } 
                }            
            }
        }
    }
}

int main() {

    for (int i = 1; i <= 200; i+= 100) {
        printNTriples(i);
    }
}

