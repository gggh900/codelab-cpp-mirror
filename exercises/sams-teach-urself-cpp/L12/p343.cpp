// implements cout << operator. Uncomment member function "operator const char *" to deliberate cause
// compile error with "cout << holiday".
#include <iostream>
#include <sstream>
#include <string>
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
    Date holiday(12,25,2016);
    cout << "Date object is initialized to: " ; 
    holiday.DisplayDate();

    ++ holiday;
    cout << "Date after a prefix-increment is: ";
    holiday.DisplayDate();

    --holiday;
    cout << "Date after a prefix-decrement is: ";
    holiday.DisplayDate();

    holiday ++ ;
    cout << "Date after a postfix-increment is: ";
    holiday.DisplayDate();

    holiday--;
    cout << "Date after a postfix-decrement is: ";
    holiday.DisplayDate();

    #ifdef EXPLICIT_CONVERSION
    string strHoliday(static_cast<const char*>(holiday));
    cout << "strHoliday: " << strHoliday << endl;
    strHoliday = static_cast<const char*>(Date(11, 11, 2016));
    cout << "strHoliday: " << strHoliday << endl;
    #else
    cout << holiday << endl;
    string strHoliday(holiday);
    cout << "strHoliday: " << strHoliday << endl;
    strHoliday = Date(11, 11, 2016);
    cout << "strHoliday: " << strHoliday << endl;
    #endif
    return 0;
}
