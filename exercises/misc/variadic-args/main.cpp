#include <cstdarg>
#include <iostream>
#include <string> 

#include "template-1.hpp"

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
