#define TEST

#include <signal.h>
#include <fmt/core.h>
#include <fmt/color.h>

#include "compiler.hpp"
#include "vm.hpp"
#include "modules.h"

void segfault(int s) {
    fmt::print(fg(fmt::color::red), "Segfault");
}

int main() {
    signal(SIGSEGV, &segfault);
    OutputInformation();

    FObject *fObj = compile("enum x{A=1,B=2,C=3}");
    OutputFObject(fObj);
    return 0;
}