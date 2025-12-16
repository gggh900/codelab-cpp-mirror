#include <iostream>
#include <sstream>
#include <lib.h>
#include <msgpack.hpp>
#define DEBUG 1

// hex_dump is not a part of msgpack-c. 
std::ostream& hex_dump(std::ostream& o, std::string const& v) {
    std::ios::fmtflags f(o.flags());
    o << std::hex;
    for (auto c : v) {
        o << "0x" << std::setw(2) << std::setfill('0') << (static_cast<int>(c) & 0xff) << ' ';
    }
    o.flags(f);
    return o;
}

void printDbg(const std::string & fname, const std::string & s1) {
    #if DEBUG == 1
    std::cout << "  DBG: " << fname.substr(fname.find_last_of('/')+1, fname.length()) << " " << s1 << std::endl;
    #endif
}

void printDbgIn(const std::string & fname) {
    #if DEBUG == 1
    std::cout << "DBG: " << fname.substr(fname.find_last_of('/')+1, fname.length()) << " entered... " << std::endl;
    #endif
}
