/*
 *  gcl_memory.h - Memory utilities
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

#ifndef GCL_MEMORY_H
#define GCL_MEMORY_H

#include <stddef.h>
#include <stdlib.h>
#include <gcl/gcl_types.h>

#if SIZE_MAX == UINT32_MAX
#define gcl_reallocp(mem_ptr, size_ptr, new_size)                       \
    (MVT_LIKELY(sizeof(*(size_ptr)) == 4) ?                             \
     gcl_reallocp32((mem_ptr), (uint32_t *)(size_ptr), (new_size)) :    \
     gcl_reallocp64((mem_ptr), (uint64_t *)(size_ptr), (new_size)))
#elif SIZE_MAX == UINT64_MAX
#define gcl_reallocp(mem_ptr, size_ptr, new_size)                       \
    (MVT_LIKELY(sizeof(*(size_ptr)) == 8) ?                             \
     gcl_reallocp64((mem_ptr), (uint64_t *)(size_ptr), (new_size)) :    \
     gcl_reallocp32((mem_ptr), (uint32_t *)(size_ptr), (new_size)))
#else
#error "unsupported sizeof(size_t)"
#endif

bool
gcl_reallocp32(void *mem_ptr, uint32_t *size_ptr, size_t new_size);

bool
gcl_reallocp64(void *mem_ptr, uint64_t *size_ptr, size_t new_size);

void
gcl_freep(void *mem_ptr);

void *
gcl_memdup(const void *mem, size_t size);

void *
gcl_slice_alloc(size_t size);

void *
gcl_slice_alloc0(size_t size);

void *
gcl_slice_dup(void *mem);

void
gcl_slice_free(void *mem);

#endif /* GCL_MEMORY_H */
