/*
Original code...
https://cplusplus.com/reference/memory/unique_ptr/reset/
*/

#include <iostream>
#include <sstream>
#include <string>
#include <memory>

#define CONGIG_USE_STDLIB 0
#define DEBUG_L2 0
using namespace std;

#if CONGIG_USE_STDLIB == 0
template <typename T>
class smart_pointer {
private:
    smart_pointer (const smart_pointer & anotherSP);
    smart_pointer & operator = (const smart_pointer  & anotherSP);

public:
    T * rawPtr;
    string string_output;
    //smart_pointer () { 
    //}

    T * get() {
        #if DEBUG_L2 == 1
        std::cout << "  smart_pointer::get() entered..." << std::endl;
        #endif
        return rawPtr;
    }
    void reset(T* pData) {
        std::cout << "  smart_pointer::reset(T* pData) entered..." << std::endl;
        // I am not sure if this is right. Do we delete old rawPtr

        // caused runtime error.
        //rawPtr = pData;
        if (rawPtr) {
            std::cout << "  smart_pointer::reset(..): Deleting rawPtr..." << std::endl;
            delete rawPtr;
        } else {
            std::cout << "  smart_pointer::reset(..): Bypassing deleting rawPtr as it is set to null." << std::endl;
        }
        rawPtr = pData;
    }

    void reset() {
        std::cout << "  smart_pointer::reset() entered..." << std::endl;
        // caused runtime error.
        delete rawPtr;
        rawPtr = nullptr;
    }

    smart_pointer() { 
        std::cout << "  smart_pointer::smart_pointer() constructor entered..." << std::endl;
        rawPtr = 0;
    }
    smart_pointer (T* pData) { 
        std::cout << "  smart_pointer::smart_pointer(T*pData) constructor entered..." << std::endl;
        rawPtr = pData; 
    }   
    
    ~smart_pointer () {
       std::cout << "  smart_pointer::~smart_pointer() desctructor entered..." << std::endl;
       delete rawPtr;
    }

    T& operator * () const { 
        #if DEBUG_L2 == 1
        std::cout << "  smart_pointer::operator*() entered..." << std::endl;
        #endif
        return *(rawPtr);
    }
    T* operator->() const { 
        #if DEBUG_L2 == 1
        std::cout << "  smart_pointer::operator->() entered..." << std::endl;
        #endif
        return rawPtr;
    }

    operator const char*() {
        ostringstream stream_output;
        stream_output << rawPtr << std::endl;
        string_output = stream_output.str();
        return string_output.c_str();
    }

};

#endif // CONGIG_USE_STDLIB

#define PRINT_SMART_PTR up.get() == nullptr ? \
    std::cout << "up.get(): " << up.get() << std::endl :\
    std::cout << "up.get(): " << up.get() << ", *up: " << *up << ", *a: " << a << ", a: " << a << std::endl;

/*
#else
    #define PRINT_SMART_PTR up.rawPtr == nullptr ? \
    std::cout << "up.rawPtr: " << up.rawPtr << std::endl :\
    std::cout << "up.rawPtr: " << up.rawPtr << ", *up: " << *up << ", *a: " << a << ", a: " << a << std::endl;
#endif
*/

int main() {

  #if CONGIG_USE_STDLIB == 1
  std::cout << "Using stdlib for unique_ptr..." << std::endl;
  std::unique_ptr<int> up; 
  #else
  std::cout << "Using implemented class for unique_ptr..." << std::endl;
  std::cout << "Creating smart_pointer..." << std::endl;
  smart_pointer<int> up;  // empty
  #endif
  int * a =  new int (10);

  try {
    PRINT_SMART_PTR
  } catch (int e) {
    std::cout << "std::cout of up and up.rawPtr caused exception..." << e << std::endl;
  }

  std::cout << "up.reset() with a which is initialized with 10..." << std::endl;

  try {
    up.reset (a);       // takes ownership of pointer
  } catch (int e) {
    std::cout << "std::cout of up and up.rawPtr caused an exception..." << e << std::endl;
  }

  try {
    PRINT_SMART_PTR
  } catch (int e) {
    std::cout << "std::cout of up and up.rawPtr caused an exception..." << e << std::endl;
  }

  std::cout << "update *a to  25..." << std::endl;
  *a=25;
  PRINT_SMART_PTR
   
  std::cout << "up.reset()..." << std::endl;
  up.reset();
  PRINT_SMART_PTR

  return 0;
}
