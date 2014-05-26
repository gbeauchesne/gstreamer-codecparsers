/*
 *  vapl_arrays.h - Array utilities
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

#ifndef VAPL_ARRAYS_H
#define VAPL_ARRAYS_H

#include <vapl/vapl_core.h>

/* --- Fixed-size Arrays -------------------------------------------------- */

typedef struct vapl_array VaplArray;
struct vapl_array {
    void               *data;
    uint32_t            length;
};

#define vapl_array_index(array, type, index) \
    (((type *)((array)->data))[index])

VAPL_DLL_PUBLIC
VaplArray *
vapl_array_new(uint32_t element_size, uint32_t num_elements);

VAPL_DLL_PUBLIC
void
vapl_array_free(VaplArray *array);

VAPL_DLL_PUBLIC
VaplArray *
vapl_array_ref(VaplArray *array);

VAPL_DLL_PUBLIC
void
vapl_array_unref(VaplArray *array);

VAPL_DLL_PUBLIC
bool
vapl_array_reserve(VaplArray *base_array, uint32_t num_elements);

VAPL_DLL_PUBLIC
bool
vapl_array_append(VaplArray *array, const void *data);

#endif /* VAPL_ARRAYS_H */
