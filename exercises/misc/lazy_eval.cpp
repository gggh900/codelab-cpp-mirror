//https://bartoszmilewski.com/2014/04/21/getting-lazy-with-c/
#include <functional>
#include <iostream>

#define DEBUG 1

template <class T> 
class Susp0 {
    public:
        explicit Susp0(std::function<T()> f)
        : _f(f)
    {
        #if DEBUG  == 1 
        printf("Susp0.constructor entered\n");
        #endif
    }
    T get() {
        #if DEBUG  == 1 
        printf("Susp0.get1 entered\n");
        printf("Returning _f(): size of _f(): %x.\n",sizeof(_f()));
        #endif
        return _f(); 
    }
    private:
        std::function<T()> _f;
};

template <class T>
class Susp {

    // thunk

    static T const & thunkForce(Susp * susp) { 
        #if DEBUG == 1
        printf("Susp.thunkForce entered...\n");
        #endif
        return susp->setMemo(); 
    }
    static T const & thunkGet(Susp * susp) { 
        #if DEBUG == 1
        printf("Susp.thunkGet entered...\n");
        #endif
        return susp->getMemo(); 
    }

    //

    T const & getMemo() { 
        #if DEBUG == 1
        printf("Susp.getMemo entered...\n");
        #endif
        return _memo; 
    }
    T const & setMemo() { 
        #if DEBUG == 1
        printf("Susp.setMemo entered...\n");
        #endif
        _memo = _f();
        _thunk = &thunkGet;
        return getMemo();
    }
public:
    // constructor will accept function type std::function and assign to _f.
    // _thunk will be assigned to thunkForce() function.
    // _memo will assigned to T() type.
   
    explicit Susp(std::function<T()> f)
    : _f(f), _thunk(&thunkForce), _memo(T())
    { 
        #if DEBUG == 1
        printf("Susp.constructor entered...\n");
        #endif
    }
    
    T const & get () { 
        #if DEBUG == 1
        printf("Susp.get() entered...\n");
        #endif
        return _thunk(this) ; 
    }
    
private:
    T const & (* _thunk)(Susp *);
    mutable T _memo;
    std::function<T()> _f; 

}; 
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

Susp0<int> sum2(x,y) {
    return x + y;
}
int main() {

    /*
    for (int i = 1; i <= 200; i+= 100) {
        printNTriples(i);
    }*/
    int x = 2;
    int y = 3;

    printf("Creating Susp0 lambda...\n");
    Susp0<int> sum0([x,y]() { return x + y * 2; });
    printf("Calling sum.lambda...\n");
    int z0 = sum0.get();
    printf("z0: %d.\n", z0);
    printf("---------------------\n");
    printf("Creating Susp lambda...\n");

    /* creates instances of Susp class with type int.
    name of object instantiated is same.
    passed value to constructor is std::function, in this case: [x,y]() { return x + y; }. 
    In another words, anything inside parenthesis.
    For same example but using simpler type see helper_class_instantiation.cpp where class constructor is called 
    the same fashion with initializing value: T1 val(100); where 100 sets class member val to 100.
    */ 
    Susp<int> sum([x,y]() { return x + y; });

    printf("Calling sum.lambda...\n");
    int z = sum.get();
    printf("z: %d.\n", z);
}

