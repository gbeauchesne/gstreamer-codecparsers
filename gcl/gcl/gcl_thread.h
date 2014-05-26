/*
 *  gcl_thread.h - Thread utilities
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

#ifndef GCL_THREAD_H
#define GCL_THREAD_H

#include <pthread.h>
#include <gcl/gcl_types.h>

typedef struct gcl_once_init_data {
    uintptr_t *value_ptr;
    pthread_mutex_t mutex;
} GclOnceInitData;

// Prepares GclOnceInitData for gcl_once_init_enter()
#define GCL_DECLARE_ONCE_INIT_DATA(location)                    \
    static GclOnceInitData g_once_init_data = {                 \
        location, PTHREAD_MUTEX_INITIALIZER };                  \
    static const char g_once_init_data_check[                   \
        1-2*(sizeof(*(location)) != sizeof(uintptr_t))];        \
    (void)g_once_init_data_check[0]

bool
gcl_once_init_enter(GclOnceInitData *d);

void
gcl_once_init_leave(GclOnceInitData *d, uintptr_t value);

#endif /* GCL_THREAD_H */
