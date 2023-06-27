// https://github.com/msgpack/msgpack-c/wiki/v2_0_cpp_tutorial

#include <iostream>
#include <sstream>
#include <lib.h>
#include <msgpack.hpp>

int main() {
    std::stringstream ss;
    std::map<std::string, int> v { { "ABC", 5 }, { "DEFG", 2 } };
    msgpack::pack(ss, v);
    hex_dump(std::cout, ss.str()) << std::endl;
}
