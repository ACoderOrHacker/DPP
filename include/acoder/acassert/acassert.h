//
// Created by ACoder on 2024/6/8.
//

#ifndef ACASSERT_H
#define ACASSERT_H
#include <iostream>
#include "acdpp.h"

typedef void(*_ACASSERT_HANDLE)(int, const char*, const char*);

forceinline void Dpp_AssertFailed(int line,
    const char *file,
    const char *expr) {
    std::cout << "Assertion Failed!\n";
    std::cout << "At " << file << ":" << line << ":\n";
    std::cout << "  " << expr;
}

forceinline void Dpp_Assert(int line,
    const char *file,
    bool isFailed,
    const char *expr,
    _ACASSERT_HANDLE handle = &Dpp_AssertFailed) {
    if (isFailed) {
        handle(line, file, expr);
        exit(EXIT_FAILURE);
    }
}

#if defined(_DEBUG)
#define acassert(expression) Dpp_Assert(__LINE__, __FILE__, !!(expression), #expression)
#define acassert_handle(expression, handle) Dpp_Assert(__LINE__, __FILE__, !!(expression), #expression, (handle))
#else
#define acassert(expression)
#define acassert_handle(expression, handle)
#endif

#if defined(_DEBUG) && defined(_USING_ACASSERT)
#undef assert
#define assert(expression) acassert(expression)
#endif // _DEBUG

#endif //ACASSERT_H
