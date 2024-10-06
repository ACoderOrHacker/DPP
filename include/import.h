#undef DXX_API
#ifdef _MSC_VER
#define DXX_API __declspec(dllimport)
#else
#define DXX_API
#endif