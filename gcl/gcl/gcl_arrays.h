/*
 *  gcl_arrays.h - Array utilities
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

#ifndef GCL_ARRAYS_H
#define GCL_ARRAYS_H

#include <gcl/gcl_types.h>

/* --- Fixed-size Arrays -------------------------------------------------- */

typedef struct gcl_array GclArray;
struct gcl_array {
    void               *data;
    uint32_t            length;
};

#define gcl_array_index(array, type, index) \
    (((type *)((array)->data))[index])

GclArray *
gcl_array_new(uint32_t element_size, uint32_t num_elements);

void
gcl_array_free(GclArray *array);

GclArray *
gcl_array_ref(GclArray *array);

void
gcl_array_unref(GclArray *array);

bool
gcl_array_reserve(GclArray *base_array, uint32_t num_elements);

bool
gcl_array_append(GclArray *array, const void *data);

#endif /* GCL_ARRAYS_H */
