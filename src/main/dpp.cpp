#define TEST

#include <signal.h>
#include <fmt/core.h>

#include "compiler.hpp"
#include "vm.hpp"
#include "modules.h"

void ssignal(int s) {
    std::cout << "segfault";
}

int main() {
    signal(SIGSEGV, &ssignal);
    OutputInformation();

    FObject *fObj = compile("enum x{A=1,B=2}");
    OutputFObject(fObj);
    return 0;
}