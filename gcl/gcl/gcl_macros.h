/*
 *  gcl_macros.h - Utility macros
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

#ifndef GCL_MACROS_H
#define GCL_MACROS_H

/* Determine the size of a static array */
#define GCL_ARRAY_LENGTH(a) \
    (sizeof(a) / sizeof((a)[0]))

#define GCL_MIN(a, b)                   (((a) < (b)) ? (a) : (b))
#define GCL_MAX(a, b)                   (((a) > (b)) ? (a) : (b))

#if defined __GNUC__
# define GCL_LIKELY(expr)               (__builtin_expect(!!(expr), 1))
# define GCL_UNLIKELY(expr)             (__builtin_expect(!!(expr), 0))
#else
# define GCL_LIKELY(expr)               (expr)
# define GCL_UNLIKELY(expr)             (expr)
#endif

#define GCL_GEN_STRING(x)               GCL_GEN_STRING_I(x)
#define GCL_GEN_STRING_I(x)             #x

#define GCL_GEN_CONCAT(a1, a2)          GCL_GEN_CONCAT2_I(a1, a2)
#define GCL_GEN_CONCAT2(a1, a2)         GCL_GEN_CONCAT2_I(a1, a2)
#define GCL_GEN_CONCAT2_I(a1, a2)       a1 ## a2
#define GCL_GEN_CONCAT3(a1, a2, a3)     GCL_GEN_CONCAT3_I(a1, a2, a3)
#define GCL_GEN_CONCAT3_I(a1, a2, a3)   a1 ## a2 ## a3
#define GCL_GEN_CONCAT4(a1, a2, a3, a4) GCL_GEN_CONCAT4_I(a1, a2, a3, a4)
#define GCL_GEN_CONCAT4_I(a1, a2, a3, a4) a1 ## a2 ## a3 ## a4

#ifdef __cplusplus
# define GCL_BEGIN_DECLS                extern "C" {
# define GCL_END_DECLS                  }
#else
# define GCL_BEGIN_DECLS
# define GCL_END_DECLS
#endif

#endif /* GCL_MACROS_H */
