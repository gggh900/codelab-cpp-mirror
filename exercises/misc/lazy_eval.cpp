//https://bartoszmilewski.com/2014/04/21/getting-lazy-with-c/
#include <functional>
#include <iostream>

template <class T> 
class Susp0 {
    public:
        explicit Susp0(std::function<T()> f)
        : _f(f)
    {}
    T get() {
        return _f(); 
    }
    private:
        std::function<T()> _f;
};


template <class T>
class Susp {

    // thunk

    static T const & thunkForce(Susp * susp) { return susp->setMemo(); }
    static T const & thunkGet(Susp * susp) { return susp->getMem(); }

    //

    T const & getMemo() { return _memo; }
    T const & setMemo() { 
        _memo = _f();
        _thunk = &thunkGet;
        return getMemo();
    }
public:
    explicit Susp(std::function<T()> f)
    : _f(f), _thunk(&thunkForce), _memo(T())
    {}
    
    T const & get () { return _thunk(this) ; }
    
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

int main() {

    /*
    for (int i = 1; i <= 200; i+= 100) {
        printNTriples(i);
    }*/
    int x = 2;
    int y = 3;

    Susp0<int> sum([x,y]() { return x + y; });
    /*Susp0<int> sum = [x,y]() { 
        return x + y; 
    };*/
    int z = sum.get();
}

