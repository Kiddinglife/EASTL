///////////////////////////////////////////////////////////////////////////////
// EAString.h
//
// Copyright (c) Electronic Arts. All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef EASTDC_EASTRING_H
#define EASTDC_EASTRING_H

#include <ctype.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>

#define EASTDC_API
#define EASTDC_LOCAL

EASTDC_API int EA_StdC_Stricmp(const char* pString1, const char* pString2);

EASTDC_API int EA_StdC_Strcmp(const char* pString1, const char* pString2);

EASTDC_API int EA_StdC_Strcmp(const char* pString1, const char* pString2);

EASTDC_API size_t EA_StdC_Strlcpy(char* pDestination, const char* pSource,
    size_t nDestCapacity);

EASTDC_API size_t EA_StdC_Strlcpy(wchar_t* pDestination, const char* pSource,
    size_t nDestCapacity);

EASTDC_API size_t EA_StdC_Strlcpy(char* pDestination, const wchar_t* pSource,
    size_t nDestCapacity);

#endif  // EASTDC_EASTRING_H
