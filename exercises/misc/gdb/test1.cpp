#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main() {
    std::vector<int>A1={1,2,2,3};
    //shared_ptr<float>
    shared_ptr<int> n1;
    n1 = std::make_shared<int>(1234);
    
    return 0;
}
