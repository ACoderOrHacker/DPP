/*
  Copyright (C) ACoder-doge. All rights reserved.
*/
#ifndef _DXX_CONFIG_H
#define _DXX_CONFIG_H
#ifdef _WIN32
#define DXX_API __declspec(dllexport)
#else
#define DXX_API
#endif
#endif // !_DXX_CONFIG_H
