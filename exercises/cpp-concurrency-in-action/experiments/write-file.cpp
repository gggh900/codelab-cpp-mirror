#include <iostream>
#include <assert.h>
#include <fstream>
#include <thread>

using namespace std;

void write_file(const string & s) {
    string filename="test.txt";
    fstream myfile;
    myfile.open(filename, ios::app);
    myfile << s << endl;
    myfile.close();
}
int main() {
    /*
    this block works fine.
    fstream myfile;
    string filename = "test.txt";
    int x = 1;
    myfile.open(filename, ios::app);
    myfile << x << endl;
    myfile.close();
    */
    int x = 100;
    write_file(to_string(x));
}
