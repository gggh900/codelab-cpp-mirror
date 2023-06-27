// https://github.com/msgpack/msgpack-c/wiki/v2_0_cpp_tutorial

#include <iostream>
#include <sstream>
#include <lib.h>
#include <msgpack.hpp>

// hex_dump is not a part of msgpack-c. 

int main() {
    std::stringstream ss;
    std::vector<int> v { 1, 5, 8, 2, 6 };
    msgpack::pack(ss, v);
    hex_dump(std::cout, ss.str()) << std::endl;

}
