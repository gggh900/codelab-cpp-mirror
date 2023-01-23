//https://www.appsloveworld.com/cplus/100/20/difference-between-capturing-and-passing-an-argument-in-lambda-functions

#include <iostream>
using namespace std;

int main(int argc,char **argv)   {
    auto i=5;
    auto m=1000;

    auto f = [i,m](int m) {cout<<"capture i="<<i<<", passing i as m="<<m<< endl; };
    while (i<4003) {
        i += m;
        f(m);
    }
}
