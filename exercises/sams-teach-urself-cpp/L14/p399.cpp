#include <assert.h>
#include <stdio.h>
#define ASSERT_NULL 1
int main() {
    char * sayHello = NULL;

    if (ASSERT_NULL == 0) 
        sayHello = new char[25];

    assert(sayHello != NULL) ;    
}
