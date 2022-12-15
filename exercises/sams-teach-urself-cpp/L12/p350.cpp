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

    Date operator + (int daysToAdd) {
        Date newDate(month, day + daysToAdd, year);
        return newDate;
    }

    Date operator - (int daysToSubtract) {
        Date newDate(month, day - daysToSubtract, year);
        return newDate;
    }

    Date operator+= (int daysToAdd) {
        day += daysToAdd;
    }

    Date operator-= (int daysToSubtract) {
        day -= daysToSubtract;
    }

    void DisplayDate() {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main() {
    Date holiday(12, 25,2016);  
    cout << "Holiday on: ";
    holiday.DisplayDate();

    cout << "holiday -= 19 gives: ";
    holiday-=19;
    holiday.DisplayDate();

    cout << "holiday += 25 gives: ";
    holiday+=6;
    holiday.DisplayDate();
    return 0;
}
