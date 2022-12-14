#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

public:
    Date (int inMonth, int inDay, int inYear) : month(inMonth), day(inDay), year(inYear) {};

    // prefix increment.

    Date & operator ++ () {
        ++day;
        return *this;
    }

    Date & operator -- () {
        --day;
        return *this;
    } 

    void DisplayDate() {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main() {
    Date holiday(12,25,2016);
    cout << "Date object is initialized to: " ; 
    holiday.DisplayDate();

    ++ holiday;
    cout << "Date after a prefix-increment is: ";
    holiday.DisplayDate();

    --holiday;
    cout << "Date after a prefix-decre,ent is: ";
    holiday.DisplayDate();
    
    return 0;
}
