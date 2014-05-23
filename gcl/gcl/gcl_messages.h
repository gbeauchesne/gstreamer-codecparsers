/*
 *  gcl_messages.h - Logging utilities
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

#ifndef GCL_MESSAGES_H
#define GCL_MESSAGES_H

#include <gcl/gcl_macros.h>

typedef struct gcl_debug_info GclDebugInfo;

GclDebugInfo *
gcl_debug_info_new(const char *name, const char *desc);

void
gcl_error(const GclDebugInfo *info, const char *format, ...);

void
gcl_fatal_error(const GclDebugInfo *info, const char *format, ...);

void
gcl_warning(const GclDebugInfo *info, const char *format, ...);

void
gcl_info(const GclDebugInfo *info, const char *format, ...);

void
gcl_debug(const GclDebugInfo *info, const char *format, ...);

void
gcl_log(const GclDebugInfo *info, const char *format, ...);

#define gcl_failed_expr_error_I(expr, cfile, cline) do {        \
        gcl_error(NULL, "%s:%d: Assertion `%s' failed\n",       \
            cfile, cline, GCL_GEN_STRING(expr));                \
    } while (0)

#define gcl_failed_expr_error(expr) do {                        \
        gcl_failed_expr_error_I(expr, __FILE__, __LINE__);      \
    } while (0)

#define gcl_abort_if_fail(expr) do {                            \
        if (!(expr)) {                                          \
            gcl_failed_expr_error(expr);                        \
            abort();                                            \
        }                                                       \
    } while (0)

#define gcl_return_if_fail(expr) do {                           \
        if (!(expr)) {                                          \
            gcl_failed_expr_error(expr);                        \
            return;                                             \
        }                                                       \
    } while (0)

#define gcl_return_val_if_fail(expr, val) do {                  \
        if (!(expr)) {                                          \
            gcl_failed_expr_error(expr);                        \
            return (val);                                       \
        }                                                       \
    } while (0)

#endif /* GCL_MESSAGES_H */
