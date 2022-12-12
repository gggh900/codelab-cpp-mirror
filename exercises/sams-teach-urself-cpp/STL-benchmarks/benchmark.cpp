#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <list> 

using namespace std;

#define     OP_INSERT 0
#define     OP_FIND 1
#define     NO_OPS 2

#define     DATATYPE_VECTOR 0
#define     DATATYPE_SET 1
#define     NO_DATATYPES 2

main () {
    // insert 50000, 100000, 150000,200000
    int data_size[]={50000, 100000, 150000, 200000, 250000, 300000};
    list <list<float>>benchmark_vector;
    list <list<float>>benchmark_set;
    vector<int> ops={OP_INSERT, OP_FIND};
    vector<int> datatypes={DATATYPE_VECTOR, DATATYPE_SET};

    int currOp;
    int currDataType;
    cout << "=========================================";
    cout << "1. Vector insert benchmar.";
    list<float>benchmark_tmp;

    for (int n = 0; n < NO_DATATYPES ; n ++ ) {
        currDataType = datatypes[n];
        for (int m = 0; m < NO_OPS; m ++ ) {
            currOp = ops[m];
            for (int i = 0 ; i < sizeof(data_size) / sizeof(int) ; i++ ) {
                auto start = std::chrono::high_resolution_clock::now();
    
                cout << "-----------------------------------------" << endl;
                cout << "Inserting data size: " << data_size[i] << endl;

                vector<int>data1;
                set<int> data2;

                switch(currOp) {
                    case OP_INSERT:
                        switch(currDataType) {
                            case DATATYPE_VECTOR:
                                for (int j = 0; j < data_size[i]; j++ )
                                    data1.push_back(j);
                            break;
                            case DATATYPE_SET:
                                for (int j = 0; j < data_size[i]; j++ )
                                    data2.insert(j);
                            break;
                         }
                    break;
                    case OP_FIND:
                        switch(currDataType) {
                            case DATATYPE_VECTOR:
                                for (int j = 0; j < data_size[i]; j++ )
                                    data1.push_back(j);
                            break;
                            case DATATYPE_SET:
                                for (int j = 0; j < data_size[i]; j++ )
                                    data2.insert(j);
                            break;
                        }
                    break;
                }
                auto end = std::chrono::high_resolution_clock::now();
        
                auto duration = (end - start);
                auto us = std::chrono::duration_cast<std::chrono::microseconds>(duration); // Microsecond (as int)
                auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration); // Milliseconds (as int)
                const float ms_fractional = static_cast<float>(us.count()) / 1000;         // Milliseconds (as float)
    
                benchmark_tmp.push_back(us.count());
                //std::cout << "Duration = " << us.count() << "µs (" << ms_fractional << "ms)" << std::endl;
            }
        }
    }
}
