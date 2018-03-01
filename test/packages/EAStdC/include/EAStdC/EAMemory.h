///////////////////////////////////////////////////////////////////////////////
// EAMemory.h
//
// Copyright (c) Electronic Arts. All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef EASTDC_EASPRINTF_H
#define EASTDC_EASPRINTF_H

#include <EABase/eabase.h>
#include <EAAssert/eaassert.h>

#include <string.h>

#define EASTDC_API

EASTDC_API const void* EA_StdC_Memcheck8 (const void* p, uint8_t  c, size_t byteCount);
EASTDC_API const void* EA_StdC_Memcheck16(const void* p, uint16_t c, size_t byteCount);
EASTDC_API const void* EA_StdC_Memcheck32(const void* p, uint32_t c, size_t byteCount);
EASTDC_API const void* EA_StdC_Memcheck64(const void* p, uint64_t c, size_t byteCount);


EASTDC_API inline uint8_t* EA_StdC_Memset8(void* pDest, uint8_t c, size_t uint8Count);
EASTDC_API inline uint16_t* EA_StdC_Memset16(void* pDest, uint16_t c, size_t count);
EASTDC_API inline uint32_t* EA_StdC_Memset32(void* pDest, uint32_t c, size_t count);
EASTDC_API inline uint64_t* EA_StdC_Memset64(void* pDest, uint64_t c, size_t count);
EASTDC_API inline int EA_StdC_Memcmp(const void* p1, const void* p2, size_t n);

#endif  // EASTDC_EASPRINTF_H
