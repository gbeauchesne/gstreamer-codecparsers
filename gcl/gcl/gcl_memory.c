/*
 *  gcl_memory.c - Memory utilities
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

#include <stdlib.h>
#include <string.h>
#include "gcl_memory.h"

// Implemented below
#undef gcl_reallocp

/**
 * \brief Reallocates memory to the expected size
 *
 * Reallocates the memory pointed by \c *mem_ptr and updates the \c
 * size object on success. If memory allocation fails, the original
 * memory block pointed is preserved and the \c size value is not
 * updated.
 *
 * @param[in,out] mem_ptr       the pointer to memory (any pointer)
 * @param[in,out] size_ptr      the pointer to size value to update on success
 * @param[in] size              the new size in bytes
 * @return \c true on success
 */
static bool
gcl_reallocp(void *mem_arg, size_t *size_ptr, size_t new_size)
{
    void ** const mem_ptr = (void **)mem_arg;
    void *new_mem;

    if (!mem_ptr)
        return false;

    new_mem = realloc(*mem_ptr, new_size);
    if (!new_mem)
        return false;

    *mem_ptr = new_mem;
    if (size_ptr)
        *size_ptr = new_size;
    return true;
}

// Reallocates memory to the expected size (32-bit output size)
bool
gcl_reallocp32(void *mem_arg, uint32_t *size_ptr, size_t new_size)
{
    size_t tmp_size;

    if (sizeof(size_t) == 4)
        return gcl_reallocp(mem_arg, (size_t *)size_ptr, new_size);

    if (!gcl_reallocp(mem_arg, &tmp_size, new_size))
        return false;

    if (size_ptr)
        *size_ptr = tmp_size;
    return true;
}

// Reallocates memory to the expected size (64-bit output size)
bool
gcl_reallocp64(void *mem_arg, uint64_t *size_ptr, size_t new_size)
{
    size_t tmp_size;

    if (sizeof(size_t) == 8)
        return gcl_reallocp(mem_arg, (size_t *)size_ptr, new_size);

    if (!gcl_reallocp(mem_arg, &tmp_size, new_size))
        return false;

    if (size_ptr)
        *size_ptr = tmp_size;
    return true;
}

/**
 * \brief Duplicates a memory block.
 *
 * Duplicates a memory block. If \ref mem is \c NULL, the function
 * returns \c NULL. The returned memory block should be deallocated
 * with free() when it is no longer needed.
 *
 * @param[in] mem       the memory block to duplicate
 * @param[in] size      the size of the memory block
 * @return a newly allocated copy of \ref mem
 */
void *
gcl_memdup(const void *mem, size_t size)
{
    void *new_mem;

    if (!mem || size == 0)
        return NULL;

    new_mem = malloc(size);
    if (!new_mem)
        return NULL;

    memcpy(new_mem, mem, size);
    return new_mem;
}

typedef struct gcl_slice GclSlice;
struct gcl_slice {
    uint32_t    tag;
    uint32_t    size;
    uint8_t     data[1];
};

#define GCL_SLICE_PRIVATE_SIZE  (offsetof(GclSlice, data))
#define GCL_SLICE_TAG           (0x534c4330) /* SLC0 */
#define GCL_SLICE(slice) \
    ((GclSlice *)((uintptr_t)(slice) - GCL_SLICE_PRIVATE_SIZE))

static GclSlice *
gcl_slice_new_internal(size_t size)
{
    GclSlice *slice;

    slice = malloc(GCL_SLICE_PRIVATE_SIZE + size);
    if (!slice)
        return NULL;

    slice->tag = GCL_SLICE_TAG;
    slice->size = size;
    return slice;
}

static inline void
gcl_slice_free_internal(GclSlice *slice)
{
    free(slice);
}

void *
gcl_slice_alloc(size_t size)
{
    GclSlice *slice;

    slice = gcl_slice_new_internal(size);
    if (!slice)
        return NULL;
    return slice->data;
}

void *
gcl_slice_alloc0(size_t size)
{
    GclSlice *slice;

    slice = gcl_slice_new_internal(size);
    if (!slice)
        return NULL;
    memset(slice->data, 0, size);
    return slice->data;
}

void *
gcl_slice_dup(void *mem)
{
    GclSlice *slice, *new_slice;

    if (!mem || ((slice = GCL_SLICE(mem))->tag != GCL_SLICE_TAG))
        return NULL;

    new_slice = gcl_slice_new_internal(slice->size);
    if (!new_slice)
        return NULL;

    memcpy(new_slice->data, slice->data, slice->size);
    return new_slice->data;
}

void
gcl_slice_free(void *mem)
{
    GclSlice *slice;

    if (!mem || ((slice = GCL_SLICE(mem))->tag != GCL_SLICE_TAG))
        return;
    gcl_slice_free_internal(slice);
}
