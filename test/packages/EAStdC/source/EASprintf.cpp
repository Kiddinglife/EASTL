/////////////////////////////////////////////////////////////////////////////
// EASprintf.h
//
// Copyright (c) Electronic Arts. All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include <EABase/eabase.h>
#include <EAAssert/eaassert.h>
#include <EAStdC/EASprintf.h>
#include <wchar.h>

EASTDC_API int EA_StdC_Vsnprintf(char8_t* EA_RESTRICT pDestination, size_t n, const char8_t* EA_RESTRICT pFormat, va_list arguments)
	{ return vsnprintf(pDestination, n, pFormat, arguments); }

EASTDC_API int EA_StdC_Vsnprintf(char16_t* EA_RESTRICT pDestination, size_t n, const char16_t* EA_RESTRICT pFormat, va_list arguments)
    { return vswprintf((wchar_t*)pDestination, n, (wchar_t*)pFormat, arguments); }

EASTDC_API int EA_StdC_Vsnprintf(char32_t* EA_RESTRICT pDestination, size_t n, const char32_t* EA_RESTRICT pFormat, va_list arguments)
 	{ return vswprintf((wchar_t*)pDestination, n, (wchar_t*)pFormat, arguments); }

#if defined(EA_WCHAR_UNIQUE) && EA_WCHAR_UNIQUE
EASTDC_API int EA_StdC_Vsnprintf(wchar_t* EA_RESTRICT pDestination, size_t n, const wchar_t* EA_RESTRICT pFormat, va_list arguments)
	{ return vswprintf(pDestination, n, pFormat, arguments); }
#endif

EASTDC_API int EA_StdC_Sprintf(T* EA_RESTRICT pDestination, const T* EA_RESTRICT pFormat, ...)
{
    va_list arguments;
    va_start(arguments, pFormat);

    auto result = vsprintf(pDestination, pFormat, arguments);

    va_end(arguments);

    return result;
}
