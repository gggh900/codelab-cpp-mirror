/*
Modification from following example
https://en.cppreference.com/w/cpp/language/template_specialization
*/

#include <type_traits>
#include <iostream>

template<typename T> // primary template
struct is_void {
    T value;
    is_void(T pValue) { 
        std::cout << "template<typeName T> struct is_void constructor(T pValue) entered." << std::endl;
        value = pValue; 
    }
    is_void() { 
        std::cout << "template<typeName T> struct is_void constructor() entered." << std::endl;
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
    struct is_void<int> s1a(10);
    struct is_void<std::string> s1b("s1b");
    struct is_void<void> s2;
    std::cout << "s1a: " << s1a.value << std::endl;
    std::cout << "s1b: " << s1b.value << std::endl;
    std::cout << "s2: " << s2.value << std::endl;
}
