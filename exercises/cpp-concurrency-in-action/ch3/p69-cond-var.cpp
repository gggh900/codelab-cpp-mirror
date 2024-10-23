/*queue is used to pass data between two thread: (to) data processing and (from) data preparation
other cond var  example to try: https://en.cppreference.com/w/cpp/thread/condition_variable/wait
*/

#include <iostream>
#include <thread>
#include <assert.h>
#include <string>
#include <mutex> 
#include <queue>
#include <condition_variable>

using namespace std;

struct data_chunk
{};

data_chunk prepare_data()
{
    cout << __FUNCTION__ << " entered..." << endl;
    return data_chunk();
}

void process(data_chunk&)
{}

bool is_last_chunk(data_chunk&)
{
    return true;
}

mutex mut;
queue<data_chunk> data_queue;
condition_variable data_cond;

int more_data_to_prepare() {
    cout << __FUNCTION__ << " entered..." << endl;
    return false;
}

void data_preparation_thread() {
    while(!more_data_to_prepare()) {
        data_chunk const data=prepare_data();
        lock_guard<mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }

}
void data_processing_thread() {
    while(true) {
        unique_lock<mutex> lk(mut);
        // data_cond: wait till data_queue.empty is not true.
        /* mechanism:
            lambda function: []{return !data_queue.empty();} - will return 0 if empty, 1 if not (no longer) empty.
            return from lambda function, 0 or 1 is predicate:
            if 0 - will continue waiting.
            if 1 - will stop waiting.
        */
        data_cond.wait(lk, []{return !data_queue.empty();});
        data_chunk data = data_queue.front();
        data_queue.pop();
        lk.unlock();
        process(data);
        if (is_last_chunk(data))
            break;
    }    
}

int main() {
    thread prep(data_preparation_thread);
    thread processing(data_processing_thread);
    prep.join();
    processing.join();
}


