/**
 * @file errors.hpp
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Compiler errors
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef _DXX_COMPILER_ERRORS_HPP
#define _DXX_COMPILER_ERRORS_HPP
#include "fmt.h"

uint32_t error_count = 0;
uint32_t warning_count = 0;

inline void reset_count() {
    error_count = 0;
    warning_count = 0;
}

/**
 * @brief Error print macro
 *
 * @param line line number
 * @param pos char position in line
 */
#define E(...) \
    do { \
        dpp::fmt::print_error("error(", line, ", ", pos, "): ", __VA_ARGS__, "\n"); \
        ++error_count; \
    } while(0);

/**
 * @brief Error print macro
 *
 * @param line line number
 * @param pos char position in line
 */
#define E_NO_LP(...) \
    do { \
        dpp::fmt::print_error("error: ", __VA_ARGS__, "\n"); \
        ++error_count; \
    } while(0);

/**
 * @brief Warning print macro
 *
 * @param line line number
 * @param pos char position in line
 */
#define W(...) \
    do { \
        dpp::fmt::print_warning("warning(", line, ", ", pos, "): ", __VA_ARGS__, "\n"); \
        ++warning_count; \
    } while(0);

/**
 * @brief Warning print macro without line and position
 *
 */
#define W_NO_LP(...) \
    do { \
        dpp::fmt::print_warning("warning: ", __VA_ARGS__, "\n"); \
        ++warning_count; \
    } while(0);

#define LP int line, int pos

NAMESPACE_BEGIN(errors)

/**
 * @brief E0001: no object named '{}'
 *
 * @param id identifier
 */
inline void E0001(LP,
    const std::string &id) {
    E("no object named '", id, "'");
}

/**
 * @brief E0002: '{}' was defined
 *
 * @param id identifier
 */
inline void E0002(LP,
    const std::string &id) {
    E("'", id, "' was defined");
}

/**
 * @brief E0003: cannot find '{}'
 *
 * @param object object name
 */
inline void E0003(LP,
    const std::string &object) {
    E("cannot find '", object, "'");
}

/**
 * @brief E0004: object '{}' was not a container
 *
 * @param object object name
 */
inline void E0004(LP,
    const std::string &object) {
    E("object '", object, "' was not a container");
}

/**
 * @brief E0005: '{}' did not have a member named '{}'
 *
 * @param container container name
 * @param member member name
 */
inline void E0005(LP,
    const std::string &container,
    const std::string &member) {
    E("'", container, "' did not have a member named '", member, "'");
}

/**
 * @brief E0006: main is not a function
 *
 */
inline void E0006() {
    E_NO_LP("main is not a function");
}

/**
 * @brief E0007: main function has much than 0 paramter
 *
 */
inline void E0007() {
    E_NO_LP("main function has much than 0 paramter");
}

/**
 * @brief E0008: paramters are invalid
 *
 */
inline void E0008(LP) {
    E("paramters are invalid");
}

/**
 * @brief E0009: cannot find '{}' label
 *
 */
inline void E0009(LP,
    const std::string &label) {
    E("cannot find '", label, "' label");
}

/**
 * @brief E0010: cannot use operator on void type
 *
 */
inline void E0010(LP) {
    E("cannot use operator on void type");
}

/**
 * @brief E0011: return paramter cannot be void
 *
 */
inline void E0011(LP) {
    E("return paramter cannot be void");
}

/**
 * @brief E0012: return paramter type is not match
 *
 */
inline void E0012(LP) {
    E("return paramter type is not match");
}

/**
 * @brief E0013: no return paramter
 *
 */
inline void E0013(LP) {
    E("no return paramter");
}

/**
 * @brief E0014: the data type of 'while' loop must be integer
 *
 */
inline void E0014(LP) {
    E("the data type of 'while' loop must be integer");
}

/**
 * @brief E0015: break is not in loop
 *
 */
inline void E0015(LP) {
    E("break is not in loop");
}

/**
 * @brief E0016: continue is not in loop
 *
 */
inline void E0016(LP) {
    E("continue is not in loop");
}

/**
 * @brief E0017: return must in function
 *
 */
inline void E0017(LP) {
    E("return must in function");
}

/**
 * @brief E0018: cannot call '{}' because it is not a function
 *
 */
inline void E0018(LP,
    const std::string &object) {
    E("cannot call '", object, "' because it is not a function");
}

/**
 * @brief E0019: function '{}' was not defined
 *
 */
inline void E0019(LP,
    const std::string &object) {
    E("function '", object, "' was not defined");
}

/**
 * @brief E0020: '{}' has different paramters
 *
 */
inline void E0020(LP,
    const std::string &object) {
    E("'", object, "' has different paramters");
}

/**
 * @brief E0021: cannot find '{}' library
 *
 */
inline void E0021(LP,
    const std::string &lib) {
    E("cannot find '", lib, "' library");
}

/**
 * @brief E0022: too many parameters to provide in '{}'
 *
 */
inline void E0022(LP,
    const std::string &object) {
    E("too many parameters to provide in '", object, "'");
}

/**
 * @brief E0022: too few parameters to provide in '{}'
 *
 */
inline void E0023(LP,
    const std::string &object) {
    E("too few parameters to provide in '", object, "'");
}

/**
 * @brief E0024: argument is void
 *
 */
inline void E0024(LP) {
    E("argument is void");
}

/**
 * @brief E0025: cannot convert from type to other type
 *
 */
inline void E0025(LP,
    const std::string &src,
    const std::string &dst) {
    E("cannot convert from ", src, " to ", dst);
}

/**
 * @brief E0026: fatal to genrate mapping id because the state has too much objects
*/
inline void E0026() {
    E_NO_LP("fatal to genrate mapping id because the state has too much objects")
}

/**
 * @brief W0001: object value to not object type value maybe error
 *
 */
inline void W0001(LP) {
    W("object value to not object type value maybe error");
}

/**
 * @brief W0002: no main function in program
 *
 */
inline void W0002() {
    W_NO_LP("no main function in program");
}

NAMESPACE_END

#endif // !_DXX_COMPILER_ERRORS_HPP
