#pragma once

#include <windows.h>

#ifdef SO2F3DLL_EXPORTS
#define DLL_IMP_API __declspec(dllexport)
#else
#define DLL_IMP_API __declspec(dllimport)
#endif

DLL_IMP_API double factor;

DLL_IMP_API double applyFactor(double v);