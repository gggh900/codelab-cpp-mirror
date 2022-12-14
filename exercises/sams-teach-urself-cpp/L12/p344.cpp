// Using smart pointer, which automatically implements * and -> operators, we are able to use
// those operators without explicitly implementing in the Date class here.

#include <iostream>
#include <sstream>
#include <string>
#include <memory>

#define EXPLICIT_CONVERSION 1
using namespace std;

class Date {
private:
    int day, month, year;
    string dateInString;

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

    Date operator ++ (int) {
        Date copy(month, day, year);
        ++day;
        return copy;
    }

    Date operator -- (int) {
        Date copy(month, day, year);
        --day;
        return copy;
    }

    #ifdef EXPLICIT_CONVERSION
    explicit operator const char*() {
        ostringstream formattedDate;
        formattedDate << month << "/" << day << "/" << year;
        dateInString = formattedDate.str();
        return dateInString.c_str();
    } 
    #else
    operator const char*() {
        ostringstream formattedDate;
        formattedDate << month << "/" << day << "/" << year;
        dateInString = formattedDate.str();
        return dateInString.c_str();
    }
    #endif

    void DisplayDate() {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main() {
    unique_ptr<int> smartIntPtr(new int);
    *smartIntPtr = 42;
    
    // Use smart pointer type like an int*

    cout << "Integer value is " << *smartIntPtr << endl;

    unique_ptr<Date> smartHoliday ( new Date (12,25,2016));
    cout << "The new instance of date contains: ";

    // use smartHoliday just as you would a date"

    smartHoliday->DisplayDate();
    return 0;
}
