// problem fixed in p238.cpp by using copy constructor.

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString {
private:
    char * buffer;

public:
    MyString(const char * pInitString) {
        string initString = pInitString;
        if (!initString.empty()) {
            buffer = new char [initString.length() + 1];
            strcpy(buffer, initString.c_str());
            cout << "buffer points to: 0x" << hex << (unsigned int*)buffer << endl;
        } else {
            buffer = NULL;
        }
    }

    // copy constructor
    MyString(const MyString & copySource) {
        buffer = NULL;
        cout << "Copy constructor: copying from Mystring" << endl;
        if (copySource.buffer != NULL) {
        
            // allocate own buffer.
            
            buffer = new char[strlen(copySource.buffer) + 1];

            // deep copy from the source into local buffer.

            strcpy(buffer, copySource.buffer);
        
            cout << "buffer points to: 0x" << hex << (unsigned int*)buffer << endl;
        }
    }

    ~MyString() {
        cout << "Invoking destructor, clearing up" << endl;
        delete [] buffer;
    }

    int GetLength() {
        return strlen(buffer);
    }
    
    const char * GetString() {
        return buffer;
    }
};

void UseMyString(MyString str) {
    cout << "String buffer in MyString is " << str.GetLength();
    cout << "characters long" << endl;
    cout << "buffer contains " <<  str.GetString() << endl;
    return;
}

int main() {
    MyString sayHello("Hello from String Class");
    UseMyString(sayHello);
}
