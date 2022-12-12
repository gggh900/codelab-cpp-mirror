#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <list> 
#include <map>

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
    vector <map<int, float>>benchmark_vector;
    vector <map<int, float>>benchmark_set;
    vector<int> ops={OP_INSERT, OP_FIND};
    vector<int> datatypes={DATATYPE_VECTOR, DATATYPE_SET};

    int currOp;
    int currDataType;
    cout << "=========================================";
    cout << "1. Vector insert benchmar.";

    map<int, float>benchmark_tmp;

    for (int n = 0; n < NO_DATATYPES ; n ++ ) {
        currDataType = datatypes[n];
        for (int m = 0; m < NO_OPS; m ++ ) {
            currOp = ops[m];
            for (int i = 0 ; i < sizeof(data_size) / sizeof(int) ; i++ ) {
                auto start = std::chrono::high_resolution_clock::now();
    
                benchmark_tmp.clear();
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
    
                benchmark_tmp.insert(pair <int, float>(data_size[i], us.count()));
                switch(currDataType) {
                    case DATATYPE_VECTOR:
                        benchmark_vector.push_back(benchmark_tmp);
                        break;
                    case DATATYPE_SET:
                        benchmark_set.push_back(benchmark_tmp);
                        break;
                }                    
            }
        }
    }
    switch(currDataType) {
        case DATATYPE_VECTOR:
            cout << "===============================================";
            for (int i = 0 ; i < NO_OPS; i ++ ) {
                for (auto element = benchmark_vector[i].cbegin() ; element != benchmark_vector[i].cend(); element ++ )
                        std::cout << "Data size: " << benchmark_vector[i]->first <<  "Duration = " benchmark_vector[i]->second << "µs (" << ms_fractional << "ms)" << endl;
            }
            break;
        case DATATYPE_SET:
            cout << "===============================================";
            for (int i = 0 ; i < NO_OPS; i ++ ) {
                for (auto element = benchmark_set[i].cbegin() ; element != benchmark_vector[i].cend(); element ++ )
                        std::cout << "Data size: " << benchmark_vector[i]->first <<  "Duration = " benchmark_vector[i]->second << "µs (" << ms_fractional << "ms)" << endl;
            }
        }
}
