/**
 * @file acdpp.h

 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Some base macros and functions for D++ Compoments
 */

#ifndef _DXX_CONFIG_H
#define _DXX_CONFIG_H
#include <memory> // for std::shared_ptr and std::make_shared
#include "config.h"

/**
 * @brief DXX_API macro
 *
 * @details DXX_API is a macro for export/import dll function
 */
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

/**
 * @brief forceinline macro
 *
 * @details forceinline is a macro to let function always inline
 */
#ifdef _MSC_VER // for MSVC
#define forceinline __forceinline
#elif defined __GNUC__ // for gcc on Linux/Apple OS X
#define forceinline __inline__ __attribute__((always_inline))
#else
#define forceinline
#endif

/*
 * If Returned 'NONE', then the grammar doesn't have object to return
 */
#define NONE nullptr
#define _cast(type, val) ((type)(val))
#define anycast(type, val) (std::any_cast<type>(val)) // for std::any

/**
 * @brief create a smart pointer
 *
 * @tparam T the type of the raw pointer
 * @param ptr_ a raw pointer
 * @return std::shared_ptr<T> a ptr with smart pointer
 */
template<typename T>
forceinline std::shared_ptr<T> create_ptr(T *ptr_) {
	auto ptr = std::make_shared<T>();
	ptr.reset(ptr_);

	return ptr;
}
#endif // !_DXX_CONFIG_H
