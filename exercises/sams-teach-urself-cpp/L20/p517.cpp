#include <iostream>
#include <map>
#include <string>

using namespace std;
    
template <typename T>
void DisplayContents(const T& cont) {
    for (auto element = cont.cbegin(); element != cont.cend(); element ++ ) {
        cout << element->first << " -> " << element->second << endl;
    }
}
int main() {
    typedef map <int, string> MAP_INT_STRING;
    typedef multimap <int, string> MMAP_INT_STRING;

}
