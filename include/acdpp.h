/*
  Copyright (C) ACoder-doge. All rights reserved.
*/
#ifndef _DXX_CONFIG_H
#define _DXX_CONFIG_H
#include <memory> // for std::shared_ptr and std::make_shared
#include "config.h"

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

template<typename T>
forceinline std::shared_ptr<T> create_ptr(T *ptr_) {
	auto ptr = std::make_shared<T>();
	ptr.reset(ptr_);
	
	return ptr;
}
#endif // !_DXX_CONFIG_H
