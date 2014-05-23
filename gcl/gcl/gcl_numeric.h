/*
 *  gcl_numeric.h - Numeric utilities
 *
 *  Copyright (C) 2014 Intel Corporation
 *    Author: Gwenole Beauchesne <gwenole.beauchesne@intel.com>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation; either version 2.1
 *  of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA 02110-1301 USA
 */

#ifndef GCL_NUMERIC_H
#define GCL_NUMERIC_H

#include <gcl/gcl_macros.h>
#include <gcl/gcl_types.h>

#if (defined __i386__ || defined __x86_64__) && 0
# define GCL_HAVE_UNALIGNED_MEMORY 1
#endif

// Reads an 8-bit unsigned integer value from memory
static inline uint8_t
gcl_read_uint8(const void *mem)
{
    return *((uint8_t *)mem);
}

// Reads a 16-bit unsigned integer value in little endian format from memory
static inline uint16_t
gcl_read_uint16_le(const void *mem)
{
#if GCL_BYTE_ORDER == GCL_LITTLE_ENDIAN && defined GCL_HAVE_UNALIGNED_MEMORY
    return *((uint16_t *)mem);
#else
    const uint8_t * const v = mem;
    return ((uint16_t)v[1] << 8) | v[0];
#endif
}

// Reads a 16-bit unsigned integer value in big endian format from memory
static inline uint16_t
gcl_read_uint16_be(const void *mem)
{
#if GCL_BYTE_ORDER == GCL_BIG_ENDIAN && defined GCL_HAVE_UNALIGNED_MEMORY
    return *((uint16_t *)mem);
#else
    const uint8_t * const v = mem;
    return ((uint16_t)v[0] << 8) | v[1];
#endif
}

// Reads a 24-bit unsigned integer value in little endian format from memory
static inline uint32_t
gcl_read_uint24_le(const void *mem)
{
    const uint8_t * const v = mem;
    return ((uint32_t)v[2] << 24) | gcl_read_uint16_le(&v[0]);
}

// Reads a 24-bit unsigned integer value in big endian format from memory
static inline uint32_t
gcl_read_uint24_be(const void *mem)
{
    const uint8_t * const v = mem;
    return ((uint32_t)v[0] << 24) | gcl_read_uint16_le(&v[1]);
}

// Reads a 32-bit unsigned integer value in little endian format from memory
static inline uint32_t
gcl_read_uint32_le(const void *mem)
{
#if GCL_BYTE_ORDER == GCL_LITTLE_ENDIAN && defined GCL_HAVE_UNALIGNED_MEMORY
    return *((uint32_t *)mem);
#else
    const uint16_t * const v = mem;
    return ((uint32_t)gcl_read_uint16_le(&v[1]) << 16) |
        gcl_read_uint16_le(&v[0]);
#endif
}

// Reads a 32-bit unsigned integer value in big endian format from memory
static inline uint32_t
gcl_read_uint32_be(const void *mem)
{
#if GCL_BYTE_ORDER == GCL_BIG_ENDIAN && defined GCL_HAVE_UNALIGNED_MEMORY
    return *((uint32_t *)mem);
#else
    const uint16_t * const v = mem;
    return ((uint32_t)gcl_read_uint16_be(&v[0]) << 16) |
        gcl_read_uint16_be(&v[1]);
#endif
}

// Reads a 64-bit unsigned integer value in little endian format from memory
static inline uint64_t
gcl_read_uint64_le(const void *mem)
{
#if GCL_BYTE_ORDER == GCL_LITTLE_ENDIAN && defined GCL_HAVE_UNALIGNED_MEMORY
    return *((uint64_t *)mem);
#else
    const uint32_t * const v = mem;
    return ((uint64_t)gcl_read_uint32_le(&v[1]) << 32) |
        gcl_read_uint32_le(&v[0]);
#endif
}

// Reads a 64-bit unsigned integer value in big endian format from memory
static inline uint64_t
gcl_read_uint64_be(const void *mem)
{
#if GCL_BYTE_ORDER == GCL_BIG_ENDIAN && defined GCL_HAVE_UNALIGNED_MEMORY
    return *((uint64_t *)mem);
#else
    const uint32_t * const v = mem;
    return ((uint64_t)gcl_read_uint32_be(&v[0]) << 32) |
        gcl_read_uint32_be(&v[1]);
#endif
}

// Reads a 32-bit float value in little endian format from memory
static inline float
gcl_read_float32_le(const void *mem)
{
    union { uint32_t v; float f; } x;
    x.v = gcl_read_uint32_le(mem);
    return x.f;
}

// Reads a 32-bit float value in big endian format from memory
static inline float
gcl_read_float32_be(const void *mem)
{
    union { uint32_t v; float f; } x;
    x.v = gcl_read_uint32_be(mem);
    return x.f;
}

// Reads a 64-bit float value in little endian format from memory
static inline double
gcl_read_float64_le(const void *mem)
{
    union { uint64_t v; double f; } x;
    x.v = gcl_read_uint64_le(mem);
    return x.f;
}

// Reads a 64-bit float value in big endian format from memory
static inline double
gcl_read_float64_be(const void *mem)
{
    union { uint64_t v; double f; } x;
    x.v = gcl_read_uint64_be(mem);
    return x.f;
}

// Rounds the integer value up to the next power-of-two multiple of n
static inline uint32_t
gcl_round_up_p2n(uint32_t v, uint32_t n)
{
    const uint32_t m = (1U << n) - 1;
    return (v + m) & ~m;
}

// Rounds the integer value down to the nearest power-of-two multiple of n
static inline uint32_t
gcl_round_down_p2n(uint32_t v, uint32_t n)
{
    const uint32_t m = (1U << n) - 1;
    return v & ~m;
}

#endif /* GCL_NUMERIC_H */
