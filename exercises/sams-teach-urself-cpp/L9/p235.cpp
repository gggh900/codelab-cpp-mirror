// Destructor implemented, needed because constructor creates buffer object and 
// needs deallocation during desctruction to prevent memory leak.

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

int main() {
    MyString sayHello("Hello from String Class");
    cout << "String buffer is SayHello is " << sayHello.GetString();
    cout << "characters long" << endl;
    cout << "Buffer contains: " << sayHello.GetString() << endl;
}
