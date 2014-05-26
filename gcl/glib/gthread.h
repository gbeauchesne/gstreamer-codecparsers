/*
 *  gthread.h - GCL replacements for <glib/gthread.h>
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

#ifndef GCL_GTHREAD_H
#define GCL_GTHREAD_H

#include <gcl/gcl_thread.h>

#define g_once_init_enter(location)                     \
    1) {                                                \
        GCL_DECLARE_ONCE_INIT_DATA(location);           \
        if (gcl_once_init_enter(&g_once_init_data)

#define g_once_init_leave(location, value)              \
        gcl_once_init_leave(&g_once_init_data, value);  \
    }

#endif /* GCL_GTHREAD_H */
