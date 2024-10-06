/*
  Copyright (C) ACoder-doge. All rights reserved.
*/
#ifndef _DXX_CONFIG_H
#define _DXX_CONFIG_H

#define VERSION_HIGH 0
#define VERSION_LOW 1
#define DXX_VERSION "0.1"

#ifdef _MSC_VER // for MSVC
#ifndef _DXX_EXPORT
#define DXX_API __declspec(dllimport)
#else
#define DXX_API __declspec(dllexport)
#endif // _DXX_API
#define _DXX_EXPORT_API extern "C" __declspec(dllexport)
#else
#define DXX_API
#define _DXX_EXPORT_API extern "C"
#endif

#ifdef _MSC_VER // for MSVC
#define forceinline __forceinline
#elif defined __GNUC__ // for gcc on Linux/Apple OS X
#define forceinline __inline__ __attribute__((always_inline))
#else
#define forceinline
#endif

/*
 * If Returned 'NONE', then the grammer doesn't have object to return
 */
#define NONE nullptr
#define _cast(type, val) ((type)(val))
#define anycast(type, val) (std::any_cast<type>(val)) // for std::any
#endif // !_DXX_CONFIG_H
