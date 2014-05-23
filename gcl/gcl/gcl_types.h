/*
 *  gcl_types.h - Utility types
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

#ifndef GCL_TYPES_H
#define GCL_TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <limits.h>
#include <unistd.h>

#define GCL_MAXINT                      INT_MAX
#define GCL_MAXUINT                     UINT_MAX
#define GCL_MAXINT8                     INT8_MAX
#define GCL_MAXUINT8                    UINT8_MAX
#define GCL_MAXINT16                    INT16_MAX
#define GCL_MAXUINT16                   UINT16_MAX
#define GCL_MAXINT32                    INT32_MAX
#define GCL_MAXUINT32                   UINT32_MAX
#define GCL_MAXINT64                    INT64_MAX
#define GCL_MAXUINT64                   UINT64_MAX

#define GCL_LITTLE_ENDIAN               1
#define GCL_BIG_ENDIAN                  2
#if defined __BYTE_ORDER__ && __BYTE_ORDER__ == ___ORDER_LITTLE_ENDIAN__
# define GCL_BYTE_ORDER                 GCL_LITTLE_ENDIAN
#elif defined __LITTLE_ENDIAN__
# define GCL_BYTE_ORDER                 GCL_LITTLE_ENDIAN
#elif defined __i386__ || defined __x86_64__
# define GCL_BYTE_ORDER                 GCL_LITTLE_ENDIAN
#elif defined __BYTE_ORDER__ && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
# define GCL_BYTE_ORDER                 GCL_BIG_ENDIAN
#elif defined __BIG_ENDIAN__
# define GCL_BYTE_ORDER                 GCL_BIG_ENDIAN
#else
# error "failed to determine plaform endianess"
#endif

#endif /* GCL_TYPES_H */
