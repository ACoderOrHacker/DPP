/// Format Library

#ifndef FMT_H
#define FMT_H
#include <iostream>
#include <termcolor/termcolor.hpp>

#include "macros.hpp"

NAMESPACE_DPP_BEGIN
NAMESPACE_BEGIN(fmt)

template<typename END>
void print(END first) {
    std::cout << first;
}

template<typename T, typename ...Args>
void print(T first, Args...args) {
    std::cout << first;
    print(args...);
}

template<typename END>
void print_error(END first) {
    std::cout << termcolor::red << first << termcolor::reset;
}

template<typename T, typename ...Args>
void print_error(T first, Args...args) {
    std::cout << termcolor::red << first << termcolor::reset;
    print_error(args...);
}

template<typename END>
void print_warning(END first) {
    std::cout << termcolor::yellow << first << termcolor::reset;
}

template<typename T, typename ...Args>
void print_warning(T first, Args...args) {
    std::cout << termcolor::yellow << first << termcolor::reset;
    print_warning(args...);
}

template<typename END>
void print_success(END first) {
    std::cout << termcolor::green << first << termcolor::reset;
}

template<typename T, typename ...Args>
void print_success(T first, Args...args) {
    std::cout << termcolor::green << first << termcolor::reset;
    print_success(args...);
}

NAMESPACE_END
NAMESPACE_DPP_END

#endif // !FMT_H