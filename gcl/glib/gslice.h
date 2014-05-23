/*
 *  gslice.h - GCL replacements for <glib/gslice.h>
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

#ifndef GCL_GSLICE_H
#define GCL_GSLICE_H

#include <gcl/gcl_memory.h>

#undef  g_slice_alloc
#define g_slice_alloc(size)             gcl_slice_alloc(size)
#undef  g_slice_alloc0
#define g_slice_alloc0(size)            gcl_slice_alloc0(size)
#undef  g_slice_new
#define g_slice_new(type)               gcl_slice_alloc(sizeof(type))
#undef  g_slice_new0
#define g_slice_new0(type)              gcl_slice_alloc0(sizeof(type))
#undef  g_slice_free1
#define g_slice_free1(mem)              gcl_slice_free(mem)
#undef  g_slice_free
#define g_slice_free(type, mem)         gcl_slice_free(mem)
#undef  g_slice_dup
#define g_slice_dup(mem)                gcl_slice_dup(mem)

#endif /* GCL_GSLICE_H */
