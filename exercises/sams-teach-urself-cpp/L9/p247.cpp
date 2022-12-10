// class that permits only one instance.

#include <iostream>
#include <string>

using namespace std;

class President {
private:
    President() { 
        cout << "constructor..." << endl;        
    }
    President(const President&) {                    // private copy constructor.
        cout << "copy constructor..." << endl;        
    }
    President &operator=(const President&) {    // private copy assignment operator.
        cout << "copy assignment constructor..." << endl;        
    }
    
    string name;

public:
    static President & GetInstance() {
        cout << "static constructor..." << endl;
        // static objects are constructed only once.
    
        static President onlyInstance;
        return onlyInstance;       
    }

    string GetName() {
        return name;
    }

    void SetName ( string InputName) {
        name = InputName;               
    }
    
};

int main () {
    President & onlyPresident = President::GetInstance();
    onlyPresident.SetName("Abraham Lincoln");
    
    // uncomment lines to see how compile failures prohibit duplicates.

    /*    
    President second;                       // can not access constructor.
    President * third = new President()     // can not access constructor.
    President fourth = onlyPresident;       // can not access copy constructor.
    onlyPresident = President::GetInstace() // can not access operator=.
    */

    cout << "The name of the president is " << onlyPresident.GetName() << endl;
}
