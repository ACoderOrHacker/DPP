#include <stdio.h>
#include "modules.h"
#include "vm.hpp"
#include "serialization/Serialization.hpp"


void OutputS_FObject(S_FObject *s_fObj) {
    OutputInformation();

    /*
     * Output the file header
     */
    fmt::print("\n");

    for(auto it: s_fObj->)
}

void OutputFObject(FObject *fObj) {
    OutputS_FObject(GetS_FObject(fObj));
}

int main() {
    OutputFObject(nullptr);

    return 0;
}

