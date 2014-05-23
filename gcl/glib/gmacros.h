/*
 *  gmacros.h - GCL replacements for <glib/gmacros.h>
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

#ifndef GCL_GMACROS_H
#define GCL_GMACROS_H

#include <gcl/gcl_macros.h>

#undef  G_BEGIN_DECLS
#define G_BEGIN_DECLS                   GCL_BEGIN_DECLS
#undef  G_END_DECLS
#define G_END_DECLS                     GCL_END_DECLS
#undef  G_STMT_START
#define G_STMT_START                    do
#undef  G_STMT_END
#define G_STMT_END                      while (0)

#undef  G_LIKELY
#define G_LIKELY(x)                     GCL_LIKELY(x)
#undef  G_UNLIKELY
#define G_UNLIKELY(x)                   GCL_UNLIKELY(x)
#undef  G_N_ELEMENTS
#define G_N_ELEMENTS(a)                 GCL_ARRAY_LENGTH(a)

#undef  MIN
#define MIN(a, b)                       GCL_MIN((a), (b))
#undef  MAX
#define MAX(a, b)                       GCL_MAX((a), (b))

#endif /* GCL_GMACROS_H */
