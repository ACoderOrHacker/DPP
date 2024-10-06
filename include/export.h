#undef DXX_API
#ifdef _MSC_VER
#define DXX_API __declspec(dllexport)
#else
#define DXX_API
#endif