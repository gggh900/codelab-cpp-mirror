/* Thread-safe stack implementation.
lock_guard instead of <mutex_instance.lock()/unlock() - see p38 for reason to use:
lock_guard - provides RAII 
lock()/unlock() - have to remember to unlock on every possible error/exception scenario*/

#include <exception>
#include <memory>
#include <stack>
#include <mutex>

struct empty_stack: std::exception {
    const char * what() const throw();
};

template <typename T> 
class threadsafe_stack {

private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    threadsafe_stack() {}
    threadsafe_stack(const threadsafe_stack &other) {
        std::lock_guard<std::mutex> lock(other.m);
        data=other.data;
    }
        
    threadsafe_stack &  operator=(const threadsafe_stack&) = delete; 
    
    void push(T new_value) {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }
    std::shared_ptr<T> pop() {
        std::lock_guard<std::mutex> lock(m);
    
        if(data.empty()) throw empty_stack();
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }
    void pop(T& value) {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        value=data.top();
        data.pop();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
    
};

int main() {
    threadsafe_stack<int> s;
    for (unsigned int i = 0 ; i < 10 ; i++ ) {
        s.push(1);
    }
}
