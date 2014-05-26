/*
 *  vapl_core.h - VAPL Core Definitions
 *
 *  Copyright (C) 2011-2014 Intel Corporation
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

#ifndef VAPL_CORE_H
#define VAPL_CORE_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/* Visibility attributes */
#if defined __GNUC__ && __GNUC__ >= 4
# define VAPL_DLL_PUBLIC __attribute__((visibility("default")))
# define VAPL_DLL_HIDDEN __attribute__((visibility("hidden")))
#else
# define VAPL_DLL_PUBLIC
# define VAPL_DLL_HIDDEN
#endif

#endif /* VAPL_CORE_H */
