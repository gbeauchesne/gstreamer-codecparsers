/*
 *  gtypes.h - GCL replacements for <glib/gtypes.h>
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

#ifndef GCL_GTYPES_H
#define GCL_GTYPES_H

#include <gcl/gcl_types.h>

#undef  FALSE
#define FALSE                           false
#undef  TRUE
#define TRUE                            true
typedef bool                            gboolean;

typedef char                            gchar;
typedef short                           gshort;
typedef int                             gint;
typedef long                            glong;

typedef unsigned char                   guchar;
typedef unsigned short                  gushort;
typedef unsigned int                    guint;
typedef unsigned long                   gulong;

typedef ssize_t                         gssize;
typedef size_t                          gsize;
#define G_GSIZE_FORMAT                  "zu"

typedef int8_t                          gint8;
typedef int16_t                         gint16;
typedef int32_t                         gint32;
typedef int64_t                         gint64;
#define G_MAXINT                        GCL_MAXINT
#define G_MAXINT8                       GCL_MAXINT8
#define G_MAXINT16                      GCL_MAXINT16
#define G_MAXINT32                      GCL_MAXINT32
#define G_MAXINT64                      GCL_MAXINT64

typedef uint8_t                         guint8;
typedef uint16_t                        guint16;
typedef uint32_t                        guint32;
typedef uint64_t                        guint64;
#define G_MAXUINT                       GCL_MAXUINT
#define G_MAXUINT8                      GCL_MAXUINT8
#define G_MAXUINT16                     GCL_MAXUINT16
#define G_MAXUINT32                     GCL_MAXUINT32
#define G_MAXUINT64                     GCL_MAXUINT64

typedef float                           gfloat;
typedef double                          gdouble;

typedef void                           *gpointer;
typedef const void                     *gconstpointer;

#endif /* GCL_GTYPES_H */
