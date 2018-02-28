///////////////////////////////////////////////////////////////////////////////
// EASprintf.h
//
// Copyright (c) Electronic Arts. All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef EASTDC_EAALIGNMENT_H
#define EASTDC_EAALIGNMENT_H

#include <EABase/eabase.h>

#define EASTDC_API
#define EASTDC_LOCAL

	/// EA_StdC_IsAligned
	/// 
	/// Tells if a given integer is aligned to a given power-of-2 boundary.
	/// Returns true for an input x value of 0, regardless of the value of a.
	/// a value must be >= 1.
	/// Example:
	///    EA_StdC_IsAligned(8,64)  ->  true
	///    EA_StdC_IsAligned(8,67)  ->  false
	///
	/// To consider: wouldn't it be better if the template arguments were reversed?
	///
    #define EA_StdC_IsAlignedInteger(x,a) (((x) & ((a) - 1)) == 0)
    #define EA_StdC_IsAlignedPtr(p,a) (((uintptr_t)(p) & ((a) - 1)) == 0)


	/// GetAlignment
	/// 
	/// Returns the highest power-of-two alignment of the given value x.
	/// x must be a scalar value (integer or pointer), else the results are undefined.
	/// Returns 0 for an input a value of 0.
	/// Beware that GetAlignment returns the highest power-of-two alignment, which 
	/// may result in a return value that is higher than you expect. Consider using
	/// the IsAligned functions to test for a specific alignment.
	/// Example:
	///    GetAlignment(0)  ->  0
	///    GetAlignment(1)  ->  1
	///    GetAlignment(2)  ->  2
	///    GetAlignment(3)  ->  1
	///    GetAlignment(4)  ->  4
	///    GetAlignment(5)  ->  1
	///    GetAlignment(6)  ->  2
	///    GetAlignment(7)  ->  1
	///    GetAlignment(8)  ->  8
	///    GetAlignment(9)  ->  1
    #define EA_StdC_GetAlignmentInteger(x) ((size_t)(((x) ^ ((x) - 1)) >> 1) + 1)
    #define EA_StdC_GetAlignmentPtr(p) ((size_t)((((uintptr_t)(p)) ^ (((uintptr_t)(p)) - 1)) >> 1) + 1)

#endif  // EASTDC_EAALIGNMENT_H
