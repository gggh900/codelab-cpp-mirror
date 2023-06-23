/*
Modification from following example
https://en.cppreference.com/w/cpp/language/template_specialization
*/
#define SPECIALIZA_FLOAT 0

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
 


#if SPECIALIZA_FLOAT == 1
template<>           // explicit specialization for T = void
struct is_void<float> {
    float value;
    is_void(float pValue) { 
        std::cout << "template<typeName T> struct is_void<float> constructor(T pValue) entered." << std::endl;
        value = pValue; 
    }
    is_void() { 
        std::cout << "template<typeName T> struct is_void<float> constructor entered." << std::endl;
        value = 100; 
    }
};
#endif
 
int main()
{
    struct is_void<int> s1a(10);
    struct is_void<std::string> s1b("s1b");
    struct is_void<float> s1c(2.1);
    struct is_void<void> s2;
    std::cout << "s1a: " << s1a.value << std::endl;
    std::cout << "s1b: " << s1b.value << std::endl;
    std::cout << "s1c: " << s1c.value << std::endl;
    std::cout << "s2: " << s2.value << std::endl;
}
