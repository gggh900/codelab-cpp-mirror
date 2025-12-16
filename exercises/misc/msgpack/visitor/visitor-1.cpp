
#include <iostream>
#include <sstream>
#include <lib.h>
#include <msgpack.hpp>

struct json_like_visitor : msgpack::null_visitor {
    json_like_visitor(std::string& s):m_s(s) {}

    bool visit_nil() {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        m_s += "null";
        return true;
    }
    bool visit_boolean(bool v) {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        if (v) m_s += "true";
        else m_s += "false";
        return true;
    }
    bool visit_positive_integer(uint64_t v) {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        std::stringstream ss;
        ss << v;
        m_s += ss.str();
        return true;
    }
    bool visit_negative_integer(int64_t v) {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        std::stringstream ss;
        ss << v;
        m_s += ss.str();
        return true;
    }
    bool visit_str(const char* v, uint32_t size) {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        m_s += '"' + std::string(v, size) + '"';
        return true;
    }
    bool start_array(uint32_t /*num_elements*/) {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        m_s += "[";
        return true;
    }
    bool end_array_item() {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        m_s += ",";
        return true;
    }
    bool end_array() {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        m_s.erase(m_s.size() - 1, 1); // remove the last ','
        m_s += "]";
        return true;
    }
    bool start_map(uint32_t /*num_kv_pairs*/) {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        m_s += "{";
        return true;
    }
    bool end_map_key() {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        m_s += ":";
        return true;
    }
    bool end_map_value() {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        m_s += ",";
        return true;
    }
    bool end_map() {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        m_s.erase(m_s.size() - 1, 1); // remove the last ','
        m_s += "}";
        return true;
    }
    void parse_error(size_t /*parsed_offset*/, size_t /*error_offset*/) {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        // report error.
    }
    void insufficient_bytes(size_t /*parsed_offset*/, size_t /*error_offset*/) {
        printDbgIn(std::string(__FILE__) + "::" + std::string(__FUNCTION__));
        // report error.
    }
    std::string& m_s;
};

int main()
{
    /*
    std::stringstream ss;
    msgpack::packer<std::stringstream> p(ss);
    p.pack_map(1);
    p.pack("key");
    p.pack_array(3);
    p.pack(42);
    p.pack_nil();
    p.pack(true);
    */
    
    std::stringstream ss;
    std::vector<int> vec { 1, 5, 8, 2, 6 };
    int vec_c[]={1,5,8,2,6};
    msgpack::packer<std::stringstream> p(ss);

    p.pack_map(1);
    p.pack("key");

    // DBG: visitor-1.cpp::insufficient_bytes entered... will result if pack_array() size does not exactly equal
    // the packed values (vec_c):

    p.pack_array(5);
    for (int i = 0 ; i < sizeof(vec_c) / sizeof(int); i++ ) {
        std::cout << "packing " << vec_c[i] << std::endl;
        p.pack(vec_c[i]);
    }
    std::string json_like;
    json_like_visitor v(json_like);
    std::size_t off = 0;
    std::string const& str = ss.str();
    bool ret = msgpack::parse(str.data(), str.size(), off, v);
    //assert(ret);
    //assert("{\"key\":[42,null,true]}" == json_like);
    std::cout << "json: " << json_like << std::endl;
}
