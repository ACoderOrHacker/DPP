#ifndef _INC_DXX_API
#define _INC_DXX_API

#include <cstring>
#include <locale>
#include <codecvt>
#include <string>

namespace dxx {
	namespace api {
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
// warning C4996: 'mbstowcs': This function or variable may be unsafe. Consider using mbstowcs_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
#endif // _MSC_VER
		inline std::wstring stringToWString(std::string str) {
			std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
			return converter.from_bytes(str);
		}

		inline std::string stringToWString(std::wstring str) {
			std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
			return converter.to_bytes(str);
		}
#ifdef _MSC_VER
#pragma warning(pop)
#endif // _MSC_VER
	}
}
#endif // !_INC_DXX_API
