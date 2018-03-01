///////////////////////////////////////////////////////////////////////////////
// EASprintf.h
//
// Copyright (c) Electronic Arts. All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef EASTDC_EASPRINTF_H
#define EASTDC_EASPRINTF_H

#include <EABase/eabase.h>
#include <EABase/eastdarg.h>
#include <stdio.h>

#define EASTDC_API

EASTDC_API int EA_StdC_Vsnprintf(char8_t* EA_RESTRICT pDestination, size_t n, const char8_t* EA_RESTRICT pFormat, va_list arguments);
EASTDC_API int EA_StdC_Vsnprintf(char16_t* EA_RESTRICT pDestination, size_t n, const char16_t* EA_RESTRICT pFormat, va_list arguments);
EASTDC_API int EA_StdC_Vsnprintf(char32_t* EA_RESTRICT pDestination, size_t n, const char32_t* EA_RESTRICT pFormat, va_list arguments);

#if defined(EA_WCHAR_UNIQUE) && EA_WCHAR_UNIQUE
EASTDC_API int Vsnprintf(wchar_t* EA_RESTRICT pDestination, size_t n, const wchar_t* EA_RESTRICT pFormat, va_list arguments);
#endif

EASTDC_API int EA_StdC_Sprintf(T* EA_RESTRICT pDestination, const T* EA_RESTRICT pFormat, ...);

#endif  // EASTDC_EASPRINTF_H
