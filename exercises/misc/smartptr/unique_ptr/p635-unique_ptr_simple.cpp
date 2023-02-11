// problem with conventional raw pointers too hard to track deallocation.
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
class smart_pointer {
private:
    T * rawPtr;
    string string_output;
    smart_pointer (const smart_pointer & anotherSP);
    smart_pointer & operator = (const smart_pointer  & anotherSP);

public:
    smart_pointer () { 
    }

    T * get() {
        return rawPtr;
    }
    void reset(T* pData) {
        // I am not sure if this is right. Do we delete old rawPtr

        // caused runtime error.
        //rawPtr = pData;
        //delete rawPtr;
        rawPtr = pData;
    }

    void reset() {
        // caused runtime error.
        //delete rawPtr;
    }
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

    operator const char*() {
        ostringstream stream_output;
        stream_output << rawPtr << std::endl;
        string_output = stream_output.str();
        return string_output.c_str();
    }

};

int main() {

  /*
    smart_pointer <int> smartint (new int);
    std::cout << smartint << std::endl;
    //smart_pointer <int> smartint2=smartint;

  */
  smart_pointer<int> up;  // empty
  
  up.reset (new int);       // takes ownership of pointer
  *up=5;
  std::cout << up << ": " << *up << '\n';

  up.reset (new int);       // deletes managed object, acquires new pointer
  *up=10;
  //std::cout << up.get() << ": " << *up << '\n';
  std::cout << up << ": " << *up << '\n';

  up.reset();               // deletes managed object

  smart_pointer<int> up2=up;  // empty
    
  return 0;
}
