// https://learn.microsoft.com/en-us/cpp/cpp/template-specialization-cpp?view=msvc-170

// partial_specialization_of_class_templates.cpp

#include <stdio.h>

template <class T> struct PTS {
   enum {
      IsPointer = 0,
      IsPointerToDataMember = 0
   };
};

template <class T> struct PTS<T*> {
   enum {
      IsPointer = 1,
      IsPointerToDataMember = 0
   };
};

template <class T, class U> struct PTS<T U::*> {
   enum {
      IsPointer = 0,
      IsPointerToDataMember = 1
   };
};

struct S{};

int main() {
   printf("PTS<S>::IsPointer == %d \nPTS<S>::IsPointerToDataMember == %d\n",
           PTS<S>::IsPointer, PTS<S>:: IsPointerToDataMember);
   printf("PTS<S*>::IsPointer == %d \nPTS<S*>::IsPointerToDataMember == %d\n"
           , PTS<S*>::IsPointer, PTS<S*>:: IsPointerToDataMember);
   printf("PTS<int S::*>::IsPointer == %d \nPTS"
           "<int S::*>::IsPointerToDataMember == %d\n",
           PTS<int S::*>::IsPointer, PTS<int S::*>::
           IsPointerToDataMember);
}
