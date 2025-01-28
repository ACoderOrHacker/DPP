/**
 * @file fmt.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief format string and output to console
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef FMT_H
#define FMT_H
#include <iostream>
#include "macros.hpp"

NAMESPACE_DPP_BEGIN
NAMESPACE_BEGIN(fmt)

/**
 * @brief prints something to console
 * 
 * @tparam Args
 * @param args the messages
 */
template<typename ...Args>
void print(Args ...args) {
    (std::cout << ... << args);
}

/**
 * @brief prints errors to console
 * 
 * @tparam Args
 * @param args the messages
 */
template<typename ...Args>
void print_error(Args...args) {
    (std::cout << ... << args);
}

/**
 * @brief prints warnings to console
 * 
 * @tparam Args
 * @param args the messages
 */
template<typename ...Args>
void print_warning(Args...args) {
    (std::cout << ... << args);
}

/**
 * @brief prints success messages to console
 * 
 * @tparam Args
 * @param args the messages
 */
template<typename ...Args>
void print_success(Args...args) {
    (std::cout << ... << args);
}

NAMESPACE_END
NAMESPACE_DPP_END

#endif // !FMT_H