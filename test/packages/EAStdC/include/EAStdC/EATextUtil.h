/////////////////////////////////////////////////////////////////////////////
// EATextUtil.h
//
// Copyright (c) Electronic Arts. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef EASTDC_EATEXTUTIL_H
#define EASTDC_EATEXTUTIL_H

#define EASTDC_API
#include <uchar.h>

EASTDC_API size_t EA_StdC_UTF8CharSize(char16_t c);
// EASTDC_API size_t    UTF8CharSize(char32_t c);

EASTDC_API char8_t* EA_StdC_UTF8WriteChar(char8_t* p, char16_t c);
// EASTDC_API char8_t*  UTF8WriteChar(char8_t* p, char32_t c);

#endif  // EASTDC_EATEXTUTIL_H
