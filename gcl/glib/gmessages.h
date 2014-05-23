/*
 *  gmessages.h - GCL replacements for <glib/gmessages.h>
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

#ifndef GCL_GMESSAGES_H
#define GCL_GMESSAGES_H

#include <gcl/gcl_messages.h>

#undef  g_assert
#define g_assert(expr)                  gcl_abort_if_fail(expr)
#undef  g_return_if_fail
#define g_return_if_fail(expr)          gcl_return_if_fail(expr)
#undef  g_return_val_if_fail
#define g_return_val_if_fail(expr, val) gcl_return_val_if_fail(expr, val)

#endif /* GCL_GMESSAGES_H */
