#include <cstdarg>
#include <iostream>
#include <string> 
#include "template-1.hpp"

template <typename A, typename B, typename C>
void simple_printf2(const A& s1, const B & s2, const C & s3) {
    std::cout << s1 << " " << s2 << " " << s3 << std::endl;
} 
