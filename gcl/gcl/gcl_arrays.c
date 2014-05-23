/*
 *  gcl_arrays.c - Array utilities
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
#include "gcl.h"
#include "gcl_arrays.h"

/* Number of scratch elements for dynamic growth of the arrays */
#define SCRATCH_ELEMENTS 4

/* --- Fixed-size Arrays -------------------------------------------------- */

#define GCL_ARRAY_PRIVATE(ptr) \
    ((GclArrayPrivate *)(ptr))

typedef struct gcl_array_private GclArrayPrivate;
struct gcl_array_private {
    GclArray            base;
    uint32_t            element_size;
    uint32_t            max_elements;
    volatile int        ref_count;
};

GclArray *
gcl_array_new(uint32_t element_size, uint32_t num_elements)
{
    GclArrayPrivate *array;

    gcl_return_val_if_fail(element_size > 0, NULL);

    array = malloc(sizeof(*array));
    if (!array)
        return NULL;

    if (!num_elements)
        num_elements = SCRATCH_ELEMENTS;

    array->base.length = 0;
    array->base.data = NULL;
    array->max_elements = 0;
    array->element_size = element_size;
    if (!gcl_array_reserve(&array->base, num_elements))
        goto error;
    return &array->base;

error:
    gcl_array_free(&array->base);
    return NULL;
}

void
gcl_array_free(GclArray *array)
{
    if (!array)
        return;
    free(array->data);
    free(array);
}

GclArray *
gcl_array_ref(GclArray *base_array)
{
    GclArrayPrivate * const array = GCL_ARRAY_PRIVATE(base_array);

    ++array->ref_count;
    return base_array;
}

void
gcl_array_unref(GclArray *base_array)
{
    GclArrayPrivate * const array = GCL_ARRAY_PRIVATE(base_array);

    if (--array->ref_count == 0)
        gcl_array_free(base_array);
}

bool
gcl_array_reserve(GclArray *base_array, uint32_t num_elements)
{
    GclArrayPrivate * const array = GCL_ARRAY_PRIVATE(base_array);
    void **new_elements;

    if (!array)
        return false;

    if (num_elements < array->max_elements)
        return true;

    num_elements += SCRATCH_ELEMENTS;
    new_elements = realloc(base_array->data,
        num_elements * array->element_size);
    if (!new_elements)
        return false;

    base_array->data = new_elements;
    array->max_elements = num_elements;
    return true;
}

bool
gcl_array_append(GclArray *base_array, const void *data)
{
    GclArrayPrivate * const array = GCL_ARRAY_PRIVATE(base_array);

    gcl_return_val_if_fail(data != NULL, false);

    if (!gcl_array_reserve(base_array, base_array->length + 1))
        return false;

    memcpy(base_array->data + base_array->length * array->element_size,
        data, array->element_size);
    base_array->length++;
    return true;
}
