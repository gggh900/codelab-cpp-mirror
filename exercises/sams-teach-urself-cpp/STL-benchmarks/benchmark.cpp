#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <list> 
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

int main (void) {
    const int OP_INSERT = 0;
    const int OP_FIND = 1;
    const int NO_OPS = 2;
    const int DATATYPE_VECTOR = 0;
    const int DATATYPE_SET = 1;
    const int NO_DATATYPES = 2;
    const int DEBUG = 0;
    const int entriesPerLine = 2;
    const int fieldWidth = 30;

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
                                //vector<int>::iterator it;

                                for (int j = 0; j < data_size[i]; j++ )
                                    find(data1.begin(), data1.end(), rand() % data_size[i]);
                                
                                break;
                            case DATATYPE_SET:
                                for (int j = 0; j < data_size[i]; j++ )
                                    data2.find(rand() & data_size[i]);
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

        for (int i = 0 ; i < entriesPerLine ; i++ )
            cout <<  setw(fieldWidth) << setiosflags(ios::left) << datatype_names[i];
        cout << endl;

        auto element_vector = benchmark_vector[i].cbegin();
        auto element_set = benchmark_vector[i].cbegin();

        int counter = 0;
        while(true) {
            cout << \
                setw(fieldWidth) << setiosflags(ios::left) << to_string(element_vector->first) + ": " + to_string(element_vector->second) + " ms." << \
                setw(fieldWidth) << setiosflags(ios::left) << to_string(element_set->first) + ": " + to_string(element_set->second) + " ms." << \
                endl;
            element_vector++;
            element_set ++;

            if (element_vector == benchmark_vector[i].cend())
                break;
            if (counter > 100) 
                break;
            counter++;
        }
    }
    cout << endl;
}
