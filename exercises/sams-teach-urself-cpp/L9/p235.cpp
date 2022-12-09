#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString {
private:
    char * buffer;

public:
    MyString(string * initString) {
        if (initString != NULL) {
            buffer = new char [strlen(initString) + 1];
            strcpy(buffer, initString);
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
