// problem with conventional raw pointers too hard to track deallocation.
#include <iostream>
using namespace std;

class Fish {
public:
    Fish() {
    cout << "Constructed Fish." << endl;
    }

    virtual ~Fish() {
        cout << "Destructed Fish." << endl;
    }
};

class Tuna: public Fish {
public:
    Tuna () {   
        cout << "Constructed Tuna." << endl;
    }

    ~Tuna() {
    cout << "Destructed Tuna." << endl;
    }

    void Swim() {
        cout << "Tuna swims real fast." << endl;
    }
};

template <typename T>
class smart_pointer {
private:
    T * rawPtr;
    smart_pointer (const smart_pointer & anotherSP);
    smart_pointer & operator = (const smart_pointer  & anotherSP);

public:
    smart_pointer (T* pData) { 
        rawPtr = pData; 
    }   
    
    ~smart_pointer () {
       delete rawPtr;
    }

    T& operator * () const { 
        return *(rawPtr);
    }
    T* operator->() const { 
        return rawPtr;
    }
};

int main() {
    smart_pointer <Tuna> smartTuna (new Tuna);
    smartTuna->Swim();
    (*smartTuna).Swim();
    return 0;
}
