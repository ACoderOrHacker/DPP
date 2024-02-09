#include "runtime/vm.h"
#include <iostream>

int main() {
    std::cout << "Hello D++!";
    FObject *fObj = new FObject();
    std::cout << std::endl << fObj << std::endl;
    VM_Run(fObj);
    return 0;
}