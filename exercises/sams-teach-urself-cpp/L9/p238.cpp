// should runtime crash when compiling and run because copy constructor did not implement and copied char buffer
// so when second copy's destructor is called, pointer to buffer was already nulL (after 1st copy's destructor) 
// so attempted to deallocate already deallocated char buffer.

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
            buffer = new char\
             [initString.length() + 1];
            strcpy(buffer, initString.c_str());
        } else {
            buffer = NULL;
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
