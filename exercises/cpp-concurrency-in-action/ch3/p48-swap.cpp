/* Thread-safe stack implementation.*/

#include <exception>
#include <memory>
#include <stack>
#include <mutex>
#include <iostream>
#include <utility>

//class some_big_object;
typedef int some_big_object;
using namespace std;

void swap(some_big_object & lhs, some_big_object & rhs) {
    some_big_object tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

class X {
private:
    some_big_object some_detail;
    std::mutex m;

public:
    some_big_object get() {
        return this->some_detail;
    }
    X(some_big_object const & sd ) : some_detail(sd) {}

    friend void swap(X & lhs, X & rhs) {
        if (&lhs == &rhs)
            return ;
        
        std::lock(lhs.m, rhs.m);
        std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
        std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
        swap(lhs.some_detail, rhs.some_detail);

    }
};
int main() {
    X X_1(1);
    X X_2(2);

    cout << "X_1: " << X_1.get() << endl;
    cout << "X_2: " << X_2.get() << endl;
    swap(X_1, X_2);
    cout << "after swap: " << endl;
    cout << "X_1: " << X_1.get() << endl;
    cout << "X_2: " << X_2.get() << endl;
    
}
