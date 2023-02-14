/*
Original code...
https://cplusplus.com/reference/memory/unique_ptr/reset/
*/
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
class smart_pointer {
private:
    smart_pointer (const smart_pointer & anotherSP);
    smart_pointer & operator = (const smart_pointer  & anotherSP);

public:
    T * rawPtr;
    string string_output;
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
        delete rawPtr;
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

  std::cout << "Creating smart_pointer..." << std::endl;
  smart_pointer<int> up;  // empty
  try {
    std::cout << "up: " << *up << "up.rawPtr: " << up.rawPtr << std::endl;
  } catch (int e) {
    std::cout << "std::cout of up and up.rawPtr caused exception..." << e << std::endl;
  }

  std::cout << "up.reset() with a which is initialized with 10..." << std::endl;
  int * a =  new int (10);
  std::cout << "*a/a: " << *a << ", " << a << std::endl;
  up.reset (a);       // takes ownership of pointer
  std::cout << "*up: " << *up << ", up.rawPtr: " << up.rawPtr << ", *a: " << *a << ", a: " << a << std::endl;

  std::cout << "update *a to  25..." << std::endl;
  *a=25;
  std::cout << "*up: " << *up << ", up.rawPtr: " << up.rawPtr << ", *a: " << *a << ", a: " << a << std::endl;
   

  std::cout << "up.reset()..." << std::endl;
  up.reset();
  std::cout << "*up: " << *up << ", up.rawPtr: " << up.rawPtr << ", *a: " << *a << ", a: " << a << std::endl;

  return 0;
}
