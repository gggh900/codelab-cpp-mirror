#include <cstdarg>
#include <iostream>
#include <string> 

//#define simple_printf_macro(...) simple_printf(__VA_ARGS__)
#define DEBUG 1

template <typename A=std::string, typename B=std::string, typename C=std::string>
void simple_printf2(const A& s1 = "" , const B & s2 = "", const C & s3 = "") {
    std::cout << s1 << " " << s2 << " " << s3 << std::endl;
} 

void simple_printf(const char* fmt...) // C-style "const char* fmt, ..." is also valid
{
    va_list args;
    va_start(args, fmt);
     
    while (*fmt != '\0')
    {
        if (*fmt == 'd')
        {
            #if DEBUG == 1
            std::cout << "\n----\nd:" ;
            #endif
            int i = va_arg(args, int);
            std::cout << i << '\n';
        }
        else if (*fmt == 'c')
        {
            #if DEBUG == 1
            std::cout << "\n----\nc:" ;
            #endif
            // note automatic conversion to integral type
            int c = va_arg(args, int);
            std::cout << static_cast<char>(c) << '\n';
        }
        else if (*fmt == 'f')
        {
            #if DEBUG == 1
            std::cout << "\n----\nf:" ;
            #endif
            double d = va_arg(args, double);
            std::cout << d << '\n';
        }
        else {
            std::cout << "??" << std::endl;
        }
        ++fmt;
    }
 
    va_end(args);
}
 
int main()
{
    /*
    std::string s1 = "dcaa";
    simple_printf(s1.c_str(), "dcff", 3, 'a', 1.999, 42.5); 
    simple_printf_macro(s1.c_str(), "dcff", 3, 'a', 1.999, 42.5); 
    simple_printf("dcff", 3, 'a', 1.999, 42.5, "abc"); 
    simple_printf_macro("dcff", 3, 'a', 1.999, 42.5, "abc"); 
    */
    simple_printf2<std::string>("aaa", "bbb", "ccc");
    //simple_printf2<, std::string, int>("aaa", "bbb", 1);
    simple_printf2("aaa", "bbb");
    simple_printf2("aaa", "bbb", 1);
}
