/*
  Copyright (C) ACoder-doge. All rights reserved.
*/
#ifndef _DXX_CONFIG_H
#define _DXX_CONFIG_H
#define CEXTERN extern "C"
#ifdef _WIN32
#define DXX_API CEXTERN __declspec(dllexport)
#else
#define DXX_API
#endif
#endif // !_DXX_CONFIG_H
