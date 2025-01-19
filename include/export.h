/**
 * @file export.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief let the compiler force use export when compiling
 *
 * @copyright Copyright (c) 2025
 *
 */

#undef DXX_API
#ifdef _MSC_VER
#define DXX_API __declspec(dllexport)
#else
#define DXX_API
#endif