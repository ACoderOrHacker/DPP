/// Format Library

#ifndef FMT_H
#define FMT_H
#include <iostream>
// #include <termcolor/termcolor.hpp>

#include "macros.hpp"

NAMESPACE_DPP_BEGIN
NAMESPACE_BEGIN(fmt)

template<typename ...Args>
void print(Args ...args) {
    (std::cout << ... << args);
}

template<typename ...Args>
void print_error(Args...args) {
    (std::cout << ... << args);
}

template<typename ...Args>
void print_warning(Args...args) {
    (std::cout << ... << args);
}

template<typename ...Args>
void print_success(Args...args) {
    (std::cout << ... << args);
}

NAMESPACE_END
NAMESPACE_DPP_END

#endif // !FMT_H