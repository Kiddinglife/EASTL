/////////////////////////////////////////////////////////////////////////////
// EAMemory.cpp
//
// Copyright (c) Electronic Arts. All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#include <EABase/eabase.h>
#include <EAStdC/EAMemory.h>
	
EASTDC_API const void* EA_StdC_Memcheck8(const void* p, uint8_t c, size_t byteCount)
{
	for(const uint8_t* p8 = (const uint8_t*)p; byteCount > 0; ++p8, --byteCount)
	{
		if(*p8 != c)
			return p8;
	}

	return NULL;
}


EASTDC_API const void* EA_StdC_Memcheck16(const void* p, uint16_t c, size_t byteCount)
{
	union U16 {
		uint16_t c16;
		uint8_t  c8[2];
	};
	const U16 u = { c };
	size_t    i = (size_t)((uintptr_t)p % 2);

	for(const uint8_t* p8 = (const uint8_t*)p, *p8End = (const uint8_t*)p + byteCount; p8 != p8End; ++p8, i ^= 1)
	{
		if(*p8 != u.c8[i])
			return p8;
	}

	return NULL;
}


EASTDC_API const void* EA_StdC_Memcheck32(const void* p, uint32_t c, size_t byteCount)
{
	union U32 {
		uint32_t c32;
		uint8_t  c8[4];
	};
	const U32 u = { c };
	size_t    i = (size_t)((uintptr_t)p % 4);

	// This code could be a little faster if it could work with an aligned 
	// destination and do word compares. There are some pitfalls to be careful
	// of which may make the effort not worth it in practice for typical uses 
	// of this code. In particular we need to make sure that word compares are 
	// done with word-aligned memory, and that may mean using a version of 
	// the c argument which has bytes rotated from their current position.
	for(const uint8_t* p8 = (const uint8_t*)p, *p8End = (const uint8_t*)p + byteCount; p8 != p8End; ++p8, i = (i + 1) % 4)
	{
		if(*p8 != u.c8[i])
			return p8;
	}

	return NULL;
}


EASTDC_API const void* EA_StdC_Memcheck64(const void* p, uint64_t c, size_t byteCount)
{
	union U64 {
		uint64_t c64;
		uint8_t  c8[8];
	};
	const U64 u = { c };
	size_t    i = (size_t)((uintptr_t)p % 8);

	for(const uint8_t* p8 = (const uint8_t*)p, *p8End = (const uint8_t*)p + byteCount; p8 != p8End; ++p8, i = (i + 1) % 8)
	{
		if(*p8 != u.c8[i])
			return p8;
	}

	return NULL;
}

EASTDC_API inline uint8_t* EA_StdC_Memset8(void* pDest, uint8_t c, size_t uint8Count)
{
    return (uint8_t*)memset(pDest, c, uint8Count);
}


EASTDC_API inline uint16_t* EA_StdC_Memset16(void* pDest, uint16_t c, size_t count)
{
    EA_ASSERT(((uintptr_t)pDest & 1) == 0);

    uint16_t*             cur = (uint16_t*)pDest;
    const uint16_t* const end = (uint16_t*)pDest + count;
    while(cur < end)
        *cur++ = c;

    return (uint16_t*)pDest;
}


EASTDC_API inline uint32_t* EA_StdC_Memset32(void* pDest, uint32_t c, size_t count)
{
    EA_ASSERT(((uintptr_t)pDest & 3) == 0);

    uint32_t*             cur = (uint32_t*)pDest;
    const uint32_t* const end = (uint32_t*)pDest + count;
    while(cur < end)
        *cur++ = c;

    return (uint32_t*)pDest;
}


EASTDC_API inline uint64_t* EA_StdC_Memset64(void* pDest, uint64_t c, size_t count)
{
    EA_ASSERT(((uintptr_t)pDest & 7) == 0);

    uint64_t*             cur = (uint64_t*)pDest;
    const uint64_t* const end = (uint64_t*)pDest + count;

    while(cur < end)
        *cur++ = c;

    return (uint64_t*)pDest;
}
