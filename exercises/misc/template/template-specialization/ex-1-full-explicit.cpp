/*
Modification from following example
https://en.cppreference.com/w/cpp/language/template_specialization
*/

#include <type_traits>
#include <iostream>

template<typename T> // primary template
struct is_void {
    T value;
    is_void(T pValue = 10) { 
        std::cout << "template<typeName T> struct is_void constructor entered." << std::endl;
        value = pValue; 
    }
};

template<>           // explicit specialization for T = void
struct is_void<void> {
    int value;
    is_void() { 
        std::cout << "template<typeName T> struct is_void<void> constructor entered." << std::endl;
        value = 100; 
    }
};
 
int main()
{
    struct is_void<int> s1;
    struct is_void<void> s2;
    std::cout << "s1: " << s1.value << ", s2: " << s2.value << std::endl;
}
