#include <iostream>
#include <set>
using namespace std;

template <typename T>
struct SortDescending {
    bool operator() (const T& lhs, const T& rhs) const {
        return (lhs > rhs);
    }
};

int main() {
    // simple set or multiset of integeres (usingd default sort predicate)

    set<int> setInts1;
    multiset<int> msetInts2;

    // creating one set from another, or part of another container 
    
    set<int> setInts3(setInts1);
    multiset<int> mSetInts3(setInts1.cbegin(), setInts1.cend());
    
    return 0;
        
}

