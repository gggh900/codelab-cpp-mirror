#include <iostream>
using namespace std;

double Divide(double divident, double divisor) {
    if (divisor == 0) {
        throw "Divisor must be non-zero";
    }
}
int main() {
    int input;

    cout << "Enter divident: ";
    double divident = 0 ;
    cin >> divident;

    cout << "Enter divisor: ";
    double divisor = 0;
    cin >> divisor;

    try {
        Divide(divident, divisor);
    } catch (const char * exp) {
        cout << "Exception: " << exp << endl;
        cout << "Sorry: can not continue" << endl;
    }
}
