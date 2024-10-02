#include <iostream>
#include "acassert.h"

void Dpp_AssertFailed(int line,
    const char *file,
    const char *expr) {
    std::cout << "Assertion Failed!\n";
    std::cout << "At " << file << ":" << line << ":\n";
    std::cout << "  " << expr;
}

void Dpp_Assert(int line,
    const char *file,
    bool isFailed,
    const char *expr,
    _ACASSERT_HANDLE handle) {
    if (isFailed) {
        handle(line, file, expr);
        exit(EXIT_FAILURE);
    }

}