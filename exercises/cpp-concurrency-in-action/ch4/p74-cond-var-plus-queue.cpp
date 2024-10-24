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

template<typename T>
class threadsafe_queue {
private:
    mutable mutex mut;
    queue<T> data_queue;
    condition_variable data_cond;
public:
    threadsafe_queue() {}
    threadsafe_queue(threadsafe_queue, const threadsafe_queue & other) {
        lock_guard<mutex> lk (other.mut);
        data_queue=other.data_queue;
    }

    void push(T new_value) {
        lock_guard<mutex> lk(mut);
        data_queue.push(new_value);
        data_cond.notify_one();        
    }

    void wait_and_pop(T& value) {
        unique_lock<mutex> lk(mut);
        data_cond.wait(lk, [this] { return !data_queue.empty();});
        value=data_queue.front();
        data_queue.pop();
    }

    shared_ptr<T> wait_and_pop() {
        unique_lock<mutex> lk(mut);
        data_cond.wait(lk, [this] { return !data_queue.empty();});
        shared_ptr<T> res(make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }        
        
    bool try_pop(T&value) {
        lock_guard<mutex> lk(mut);
        if(data_queue.empty()) {
            return false;
        }
        
        value=data_queue.front();
        data_queue.pop();
        return true;
    }

    shared_ptr <T> try_pop() {
        lock_guard<mutex> lk(mut);
        if(data_queue.empty())
            return false;
        shared_ptr<T> res(make_shared<T> (data_queue.front()));
        data_queue.pop();
        return res;
    }

    bool empty() const {
        lock_guard<mutex> lk(mut);
        return data_queue.empty();
    }
};

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

int more_data_to_prepare() {
    cout << __FUNCTION__ << " entered..." << endl;
    return false;
}

threadsafe_queue<data_chunk> data_queue;
void data_preparation_thread() {
    while(!more_data_to_prepare()) {
        data_chunk const data=prepare_data();
        data_queue.push(data);
    }
}

void data_processing_thread() {
    while(true) {
        data_chunk data;
        data_queue.wait_and_pop(data);
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


