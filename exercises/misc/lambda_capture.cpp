//https://www.appsloveworld.com/cplus/100/20/difference-between-capturing-and-passing-an-argument-in-lambda-functions

#include <iostream>
using namespace std;

int main(int argc,char **argv)   {
    auto i=5;
    auto f = [=](int j) {cout<<"capture i="<<i<<", passing i as j="<<j<< endl; };
    while (i<30) {
        i += 10;
        f(i);
    }
}
