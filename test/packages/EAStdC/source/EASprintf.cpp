/////////////////////////////////////////////////////////////////////////////
// EASprintf.h
//
// Copyright (c) Electronic Arts. All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include <EABase/eabase.h>

#include <EAAssert/eaassert.h>
#include <EAStdC/EASprintf.h>
#include <EAStdC/EAString.h>
#include <EAStdC/EATextUtil.h>

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

EASTDC_API int EA_StdC_Stricmp(const char* pString1, const char* pString2)
{
  T c1, c2;

  while ((c1 = std::tolower(*pString1++)) == (c2 = std::tolower(*pString2++)))
  {
    if (c1 == 0)
      return 0;
  }

  return c1 - c2;
}

EASTDC_API int EA_StdC_Strcmp(const char* pString1, const char* pString2)
{
  T c1, c2;

  while ((c1 = *pString1++) == (c2 = *pString2++))
  {
    if (c1 == 0)
      return 0;
  }

  return c1 - c2;
}

EASTDC_API int EA_StdC_Strcmp(const char* pString1, const char* pString2)
{
  return std::strcmp(pString1, pString2);
}

EASTDC_API size_t EA_StdC_Strlcpy(char* pDestination, const char* pSource,
    size_t nDestCapacity)
{
  const T *s = pSource;
  size_t n = nDestCapacity;

  if (n && --n)
  {
    do
    {
      if ((*pDestination++ = *s++) == 0)
        break;
    } while (--n);
  }

  if (!n)
  {
    if (nDestCapacity)
      *pDestination = 0;
    while (*s++)
    {
    }
  }

  return (size_t)(s - pSource - 1);
}

EASTDC_API size_t EA_StdC_Strlcpy(wchar_t* pDestination, const char* pSource,
    size_t nDestCapacity)
{
  return mbstowcs(pDestination, pSource, nDestCapacity);
}

EASTDC_API size_t EA_StdC_Strlcpy(char* pDestination, const wchar_t* pSource,
    size_t nDestCapacity)
{
  return wcstombs(pDestination, pSource, nDestCapacity);
}

EASTDC_API size_t EA_StdC_UTF8CharSize(char16_t c)
{
  if (c < 0x00000080)
    return 1;
  else if (c < 0x00000800)
    return 2;
  else
    // if(c < 0x00010000)
    return 3;

  // The following would be used if the input was 32 bit instead of 16 bit.
  //else if(c < 0x00010000)
  //    return 3;
  //else if(c < 0x00200000)
  //    return 4;
  //else if(c < 0x04000000)
  //    return 5;
  //else if(c <= 0x7fffffff)
  //    return 6;
  //
  //return 1; // Error
}
// EASTDC_API size_t    UTF8CharSize(char32_t c);

EASTDC_API char8_t* EA_StdC_UTF8WriteChar(char8_t* p, char16_t c)
{
  if (c < 0x80)
  {
    *p++ = (char8_t) (uint8_t) c;
  }
  else if (c < 0x0800)
  {
    *p++ = (char8_t)(uint8_t)((c >> 6) | 0xC0);
    *p++ = (char8_t)(uint8_t)((c & 0x3F) | 0x80);
  }
  else // if(c < 0x00010000)
  {
    *p++ = (char8_t)(uint8_t)((c >> 12) | 0xE0);
    *p++ = (char8_t)(uint8_t)(((c >> 6) & 0x3F) | 0x80);
    *p++ = (char8_t)(uint8_t)((c & 0x3F) | 0x80);
  }
  //else
  //{
  //    *p++ = (char8_t)(uint8_t)((c >> 18) | 0xF0);
  //    *p++ = (char8_t)(uint8_t)(((c >> 12) & 0x3F) | 0x80);
  //    *p++ = (char8_t)(uint8_t)(((c >> 6) & 0x3F) | 0x80);
  //    *p++ = (char8_t)(uint8_t)((c & 0x3F) | 0x80);
  //}

  return p;
}
