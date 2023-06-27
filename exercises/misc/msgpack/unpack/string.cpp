// https://github.com/msgpack/msgpack-c/wiki/v2_0_cpp_tutorial

#include <iostream>
#include <sstream>
#include <lib.h>
#include <msgpack.hpp>

int main() {
    std::stringstream ss;
    msgpack::pack(ss, "compact");
    hex_dump(std::cout, ss.str()) << std::endl;
}
