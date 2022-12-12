#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

main () {
    // insert 50000, 100000, 150000,200000
    int data_size[]={50000, 100000, 150000, 200000, 250000, 300000};
    int data_type[]={"vector"}

    for (int i = 0 ; i < sizeof(data_size) / sizeof(int) ; i++ ) {
        auto start = std::chrono::high_resolution_clock::now();

        vector<int>data;
        cout << "-----------------------------------------" << endl;
        cout << "Inserting data size: " << data_size[i] << endl;

        for (int j = 0; j < data_size[i]; j++ ) {
            data.push_back(i);
        }
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = (end - start);
        auto us = std::chrono::duration_cast<std::chrono::microseconds>(duration); // Microsecond (as int)
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration); // Milliseconds (as int)
        const float ms_fractional = static_cast<float>(us.count()) / 1000;         // Milliseconds (as float)
        std::cout << "Duration = " << us.count() << "µs (" << ms_fractional << "ms)" << std::endl;
    }
}
