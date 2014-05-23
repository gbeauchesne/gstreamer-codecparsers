/*
 *  garray.h - GCL replacements for <glib/garray.h>
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

#ifndef GCL_GARRAY_H
#define GCL_GARRAY_H

#include <gcl/gcl_arrays.h>

/* GArray */
#undef  GArray
#define GArray                          GclArray
#undef  g_array_new
#define g_array_new(z,c,e)              g_compat_array_new((z), (c), (e), 0)
#undef  g_array_sized_new
#define g_array_sized_new(z,c,e,n)      g_compat_array_new((z), (c), (e), (n))
#undef  g_array_ref
#define g_array_ref(a)                  gcl_array_ref((a))
#undef  g_array_unref
#define g_array_unref(a)                gcl_array_unref((a))
#undef  g_array_append_val
#define g_array_append_val(a, v)        gcl_array_append((a), &(v))

static inline GArray *
g_compat_array_new(bool opt_zero, bool opt_clear, uint32_t element_size,
    uint32_t num_elements)
{
    gcl_return_val_if_fail(!opt_zero, NULL);
    gcl_return_val_if_fail(!opt_clear, NULL);

    return gcl_array_new(element_size, num_elements);
}

#endif /* GCL_GARRAY_H */
