#include <cstdarg>
#include <iostream>
#include <string> 
#include "template-1.hpp"

template <typename A, typename B, typename C>
void simple_printf2(const A& s1, const B & s2, const C & s3) {
    std::cout << s1 << " " << s2 << " " << s3 << std::endl;
} 

int main()
{

    simple_printf2<std::string>("aaa", "bbb", "ccc");
    //simple_printf2<, std::string, int>("aaa", "bbb", 1);
    simple_printf2("aaa", "bbb");
    simple_printf2("aaa", "bbb", 1);
    simple_printf2("aaa", "bbb", 1.123);
    simple_printf2("aaa", "bbb", 'c');
    simple_printf2("aaa", 23);
    simple_printf2(1.2331);
}
