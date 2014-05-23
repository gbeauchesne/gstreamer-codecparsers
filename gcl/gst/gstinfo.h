/*
 *  gstinfo.h - GCL replacements for <gst/gstinfo.h>
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

#ifndef GCL_GSTINFO_H
#define GCL_GSTINFO_H

#include <gcl/gcl_messages.h>

#undef  GstDebugCategory
#define GstDebugCategory                GclDebugInfo
extern  GstDebugCategory               *GST_CAT_DEFAULT;
#define GST_DEBUG_CATEGORY(cat)         GclDebugInfo *cat = NULL;
#define GST_DEBUG_CATEGORY_EXTERN(cat)  extern GclDebugInfo *cat
#define GST_DEBUG_CATEGORY_STATIC(cat)  static GclDebugInfo *cat

#define GST_DEBUG_CATEGORY_INIT(cat, name, color, desc) do {    \
        if (!(cat))                                             \
            cat = _gst_debug_category_new(name, color, desc);   \
    } while (0)

#undef  _gst_debug_category_new
#define _gst_debug_category_new(name, color, desc) \
    gcl_debug_info_new(name, desc)

#define GST_ERROR(...) \
    gcl_error(GST_CAT_DEFAULT, __VA_ARGS__)
#define GST_WARNING(...) \
    gcl_warning(GST_CAT_DEFAULT, __VA_ARGS__)
#define GST_INFO(...) \
    gcl_info(GST_CAT_DEFAULT, __VA_ARGS__)
#define GST_DEBUG(...) \
    gcl_debug(GST_CAT_DEFAULT, __VA_ARGS__)
#define GST_LOG(...) \
    gcl_log(GST_CAT_DEFAULT, __VA_ARGS__)
#define GST_TRACE(...) \
    /* nothing */

#endif /* GCL_GSTINFO_H */
