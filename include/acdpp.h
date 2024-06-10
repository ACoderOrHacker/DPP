/*
  Copyright (C) ACoder-doge. All rights reserved.
*/
#ifndef _DXX_CONFIG_H
#define _DXX_CONFIG_H

#ifdef _WIN32
#ifdef _DXX_API
#define DXX_API __declspec(dllimport)
#else
#define DXX_API __declspec(dllexport)
#endif // _DXX_API
#else
#define DXX_API
#endif

#ifdef _MSC_VER // for MSVC
#define forceinline __forceinline
#elif defined __GNUC__ // for gcc on Linux/Apple OS X
#define forceinline __inline__ __attribute__((always_inline))
#else
#define forceinline
#endif

#define cast(type, val) ((type)(val))
#define anycast(type, val) (std::any_cast<type>(val)) // for std::any

#endif // !_DXX_CONFIG_H
