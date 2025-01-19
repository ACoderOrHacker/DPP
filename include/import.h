/**
 * @file import.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief let the compiler force use import when compiling
 *
 * @copyright Copyright (c) 2025
 *
 */

#undef DXX_API
#ifdef _MSC_VER
#define DXX_API __declspec(dllimport)
#else
#define DXX_API
#endif