/*
 *  gcl_thread.c - Thread utilities
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

#include "gcl_thread.h"

bool
gcl_once_init_enter(GclOnceInitData *d)
{
    pthread_mutex_lock(&d->mutex);
    if (!*d->value_ptr)
        return true;
    pthread_mutex_unlock(&d->mutex);
    return false;
}

void
gcl_once_init_leave(GclOnceInitData *d, uintptr_t value)
{
    *d->value_ptr = value;
    pthread_mutex_unlock(&d->mutex);
}
