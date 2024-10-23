#include <iostream>
#include <assert.h>
#include <fstream>
#include <thread>
#include <mutex>
#define DEBUG 0

using namespace std;

class file {
    mutable mutex m;
    fstream myfile;
    string filename = "output3.txt";

public:
    void write_to_file(const string & s) {
        if (DEBUG == 1) {
            cout << "file::write_to_file() entered..." << endl;
        }
        m.lock();
        this->myfile.open(filename, ios::app);
        this->myfile << s << endl;
        this->myfile.close();
        m.unlock();
    }

    void sum(int & a, int & b) {
        cout << "sum entered with a=" << a << ", b=" << b << endl;
        /*
        this->write_to_file(to_string(a));
        this->write_to_file(to_string(b));
        int sum = a + b;
        this->write_to_file(to_string(sum));
        */
    }
    void sum1() {
        cout << "sum1() entered" << endl;
    }
};

int main() {

    // create two threads.
    // each thread:
    //  race condition:
    // lock mutex, write op1 value to file, unlock mutex
    // lock mutex, write op2 value to file, unlock mutex
    // lock mutex, write op1+op2 value to file, unlock mutex
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    file f;
    thread ta(&file::sum1, &f);
    thread tb(&file::sum1, &f);
    /*
    thread ta(&file::sum, &f, a, b);
    thread tb(&file::sum, &f, c, d);
    */
    ta.join();
    tb.join();

    /*
    class X {
        public:
            void do_lenghty_work() {
                cout << "do_lengthy_work() entered....\n";
            }
    };

    int main() {
        X my_x;
        std::thread t(&X::do_lenghty_work, &my_x);
        t.join();
    }
*/
}
