// https://github.com/msgpack/msgpack-c/wiki/v2_0_cpp_tutorial

#include <iostream>
#include <sstream>

#include <msgpack.hpp>

// hex_dump is not a part of msgpack-c. 
inline std::ostream& hex_dump(std::ostream& o, std::string const& v) {
    std::ios::fmtflags f(o.flags());
    o << std::hex;
    for (auto c : v) {
        o << "0x" << std::setw(2) << std::setfill('0') << (static_cast<int>(c) & 0xff) << ' ';
    }
    o.flags(f);
    return o;
}

int main() {
    std::stringstream ss;
    msgpack::pack(ss, "compact");
    hex_dump(std::cout, ss.str()) << std::endl;
}
