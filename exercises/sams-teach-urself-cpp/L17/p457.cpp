// plain vector ops.

#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<int> integers;
    vector<int> initVector{202, 2017, -1};
    vector<int> tenElements(10);
    vector<int> tenElemInit(10, 90);
    vector<int> copyVector(tenElemInit);
    vector<int> partialCopy(tenElements.cbegin(), tenElements.cbegin() + 5);

    for (int i ; i < 100000000;i< i++)
    integers.push_back(50*i);
    
    cout << "The vector contains: " << integers.size() << " Elements: " << endl;
    return 0;
}
