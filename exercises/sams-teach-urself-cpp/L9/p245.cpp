// problem fixed in p238.cpp by using copy constructor.
// GG!! study further. Did not seem to work according to book...

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
            cout << "Constructor: buffer points to: 0x" << hex << (unsigned int*)buffer << endl;
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
        
            cout << "Copy constructor: buffer points to: 0x" << hex << (unsigned int*)buffer << endl;
        }
    }

    // move constructor

    MyString(MyString&& moveSource) {
        cout << "Move constructor: moving from MyString" << endl;
        if (moveSource.buffer != NULL) {
            buffer = moveSource.buffer;         // take ownership i.e. move.
            moveSource.buffer = NULL;           // set the move source to NULL.
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

MyString Copy(MyString& source) {
    cout << "Copy entered." << endl;
    MyString copyForReturn(source.GetString());     // create copy.
    return copyForReturn;
}

int main() {
    MyString sayHello("Hello world of C++");
    //MyString sayHelloAgain(Copy(sayHello));
    MyString sayHelloAgain(sayHello);
}
