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
#define     DEBUG 1
main () {
    // insert 50000, 100000, 150000,200000
    int data_size[]={50000, 100000, 150000, 200000, 250000, 300000};
    vector <map<int, float>>benchmark_vector;
    vector <map<int, float>>benchmark_set;
    vector<int> ops={OP_INSERT, OP_FIND};
    vector<string> op_names={"Insert", "Find"};
    vector<int> datatypes={DATATYPE_VECTOR, DATATYPE_SET};
    vector<string> datatype_names={"vector", "set"};

    int currOp;
    int currDataType;

    map<int, float>benchmark_tmp;

    for (int n = 0; n < NO_DATATYPES ; n ++ ) {
        currDataType = datatypes[n];
        for (int m = 0; m < NO_OPS; m ++ ) {
            currOp = ops[m];
            cout << "=========================================" << endl;
            cout << "Performing benchmark for data type: " << datatype_names[n] << ", operation: " << op_names[m] << endl;
            benchmark_tmp.clear();
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
    
                if (DEBUG) 
                    cout << "Inserting benchmark entries to benchmark_tmp: " << data_size[i] << ", " << us.count() << endl;
               
                benchmark_tmp.insert(pair <int, float>(data_size[i], us.count()));

                if (DEBUG)
                    cout << "benchmark_tmp size: " << benchmark_tmp.size() << endl;
            }                    

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
    cout << "===============================================" << endl;
    for (int i = 0 ; i < NO_OPS; i ++ ) {
        if (DEBUG) 
            cout << "benchmark_vector[i] size: " << benchmark_vector[i].size() << endl;
        cout << "Benchmark times for op: " << op_names[i] << endl;
        for (auto element = benchmark_vector[i].cbegin() ; element != benchmark_vector[i].cend(); element ++ )
            std::cout << "Data size: " << element->first <<  ", Duration = " << element->second << "ms)" << endl;
    }
    cout << "===============================================" << endl;
    for (int i = 0 ; i < NO_OPS; i ++ ) {
        if (DEBUG) 
            cout << "benchmark_set[i] size: " << benchmark_set[i].size() << endl;
        cout << "Benchmark times for op: " << op_names[i] << endl;
        for (auto element = benchmark_set[i].cbegin() ; element != benchmark_set[i].cend(); element ++ )
            std::cout << "Data size: " << element->first <<  ", Duration = " << element->second << "ms)" << endl;
    }
}
