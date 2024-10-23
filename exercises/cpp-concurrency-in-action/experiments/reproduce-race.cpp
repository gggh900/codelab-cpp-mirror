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
    string filename = "reproduce-race.txt";

public:
    void write_to_file(const string & s) {
        if (DEBUG == 1) 
            cout << "file::write_to_file() entered..." << endl;

        m.lock();
        this->myfile.open(filename, ios::app);
        if (!this->myfile.is_open()) {
            cout << "file open fail. " << endl;
            m.unlock();
        }
        this->myfile << s << endl;
        this->myfile.close();
        m.unlock();
    }

    void sum(int a, int b) {
        if (DEBUG == 1)
            cout << "sum entered with a=" << a << ", b=" << b << endl;

        for (unsigned int i = 0 ; i < 10000000; i ++ )  {
            string line = to_string(i) + ": " + to_string(a) + " + " + to_string(b) + " = " + to_string(a+b);
            this->write_to_file(line);
        }
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
    int c = 1;
    int d = 2;
    file f;
    /*
    thread ta(&file::sum1, &f);
    thread tb(&file::sum1, &f);
    */
    thread ta(&file::sum, &f, a, b);
    thread tb(&file::sum, &f, c, d);
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
