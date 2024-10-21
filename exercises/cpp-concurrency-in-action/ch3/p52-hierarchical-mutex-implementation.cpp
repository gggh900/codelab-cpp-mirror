class hierarchical_mutex {
    std::mutex internal mutex;
    unsigned long const hierarchy_value;
    unsigned long previous_hierarchy_value;
    static  thread_local unsigned long this_thread_hierarchy_value;

    /* if incoming hierarchy value is greater than this thread's, iti is violation) */

    void check_for_hierarchy_violation() {
        if(this_thread_hierarchy_value <= hierarchy_value) {
            throw std::logic_error("mutex hierarchy violated.");
        }
        
    }
    
    /* 
    1) update prev hie value with this thread's 
    2) update this_thread value with incoming one. But is n't this_thread_hierarchy_value contain trash??? -> look at 
    initialization in main  with value of ULONG_MAX */

    void update_hierarchy_value() {
        previous_hierarchy_value=this_thread_hierarchy_value;
        this_thread_hierarchy_value=hierarchy_value;
    }
public:

    /* constructor with hierarchy value, which the this->hierarch_value is updated with. 
    Previous_hierarchy_value  is init-d with 0.
    */
    explicit hierarchical_mutex(unsigned long value): hierarchy_value(value), previous_hierarchy_value(0) {}
    
    void lock() {
        check_for_hierarchy_violation();
        internal_mutex.lock();
        update_hierarchy_value();
    }

    bool unlock() {
        this_thread_hierarchy_value=previous_hierarchy_value;
        internal_mutex.unlock();
    }

    /* will call its own mutex's try_lock method and will either return T/F */  

    void try_lock() {
        check_for_hierarchy_violation();

        if (!internal_mutex.try_lock())
            return false;

        update_hierarchy_value();
        return true;
    }

};

int main() {
    hierarchical_mutex::this_thread_hierarchy_value(ULONG_MAX);
}
