//https://cplusplus.com/reference/memory/unique_ptr/reset/
// UNIQUE_PTR: does not allow copy or assignment (assignment creates another copy).
// unique_ptr::reset example

#include <iostream>
#include <memory>

int main () {
  std::unique_ptr<int> up;  // empty

  
  up.reset (new int);       // takes ownership of pointer
  *up=5;
  std::cout << up.get() << ": " << *up << '\n';

  up.reset (new int);       // deletes managed object, acquires new pointer
  *up=10;
  std::cout << up.get() << ": " << *up << '\n';

  up.reset();               // deletes managed object
  
  std::unique_ptr<int> up2 = up;

  return 0;
}
