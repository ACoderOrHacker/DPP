//
// Created by ACoder on 2024/6/8.
//

#ifndef ACASSERT_H
#define ACASSERT_H
#include <cassert>
#include <cstddef>
#include <iostream>

typedef void(*_ACASSERT_HANDLE)(int, const char*, const char*);

void Dpp_AssertFailed(int line,
    const char* file,
    const char* expr);

void Dpp_Assert(int line,
    const char* file,
    bool isFailed,
    const char* expr,
    _ACASSERT_HANDLE handle = &Dpp_AssertFailed);


#define acassert(expression) Dpp_Assert(__LINE__, __FILE__, !!(expression), #expression)
#define acassert_handle(expression, handle) Dpp_Assert(__LINE__, __FILE__, !!(expression), #expression, (handle))

#if defined(_DEBUG) && defined(_USING_ACASSERT)
#undef assert
#define assert(expression) acassert(expression)
#endif // _DEBUG

#endif //ACASSERT_H
