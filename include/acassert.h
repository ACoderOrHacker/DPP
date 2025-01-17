/**
 * @file acassert.h

 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Assertion module in D++
 *
 * @details you can use acassert(expr) to assert, and you can use '_USING_ACASSERT' to replace acassert to assert macro.
 *          and you can use acassert_handle(expr, handle) to assert with a handle function
 * @code {.cpp}
 * acassert(someVariable == 1); // if someVariable is not 1, the program will terminate
 * acassert_handle(someVariable == 1, [](int line, const char* file, const char* expr) {
 *     std::cout << "Assertion Failed!\n";
 * }) // if someVariable is not 1, the handle will output 'Assertion Failed!\n'
 * @endcode
 */

#ifndef ACASSERT_H
#define ACASSERT_H
#include <iostream>
#include "acdpp.h"

typedef void(*_ACASSERT_HANDLE)(int, const char*, const char*);

/**
 * @brief
 *
 * @param line ref to __LINE__
 * @param file ref to __FILE__
 * @param expr expression string
 * @return void
 *
 * @internal
 */
forceinline void Dpp_AssertFailed(int line,
    const char *file,
    const char *expr) {
    std::cout << "Assertion Failed!\n";
    std::cout << "At " << file << ":" << line << ":\n";
    std::cout << "  " << expr;
}

/**
 * @brief
 *
 * @param line ref to __LINE__
 * @param file ref to __FILE__
 * @param isFailed if is true, the assertion failed
 * @param expr expression string to assert
 * @param handle if is failed, the handle function will be called
 * @return void
 *
 * @internal
 */
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
