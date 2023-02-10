#include <memory>
#include <utility>
#include <functional>
#include <iostream>
#include "test.h"

/*void f1(void) {
    std::cout << "f1..." << std::endl;
    return;
}
void f2(void) {
    std::cout << "f2..." << std::endl;
    return;
}
*/
void c1::c1_f1(void) {

    //auto queue_lambda = [this]() {... };

    auto f1_lambda = [this]() {
        std::cout << "f1_lambda" << std::endl;
        //c1 c1local;
        //return c1local;
    };
    //c1_q1[0].reset([] () {return f1_lambda(); } ); // did not work.

    // queues_[QueueBlitOnly].reset(queue_lambda); // ROCR example.

    c1_q1[0].reset(f1_lambda);
        }
    );
}

int main() {
    
    // lazy pointer, pass c1 class, name c1_lazy with 3 array members. o

    // create standard function based on f1 named f1_std.
    //std::function<void(void)> f1_std = f1;

    // instantiate c1.

    c1 c1i;

    // create f1_lambda function.

    //std::function<c1(void)> f1_lambda_std = f1_lambda;

    // pass f1_lambda function to c1_lazy.

}
