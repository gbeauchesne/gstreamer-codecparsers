/*
 *  gcl_messages.c - Logging utilities
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

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "gcl_messages.h"
#include "gcl_memory.h"
#include "gcl_string.h"

struct gcl_debug_info {
    struct gcl_debug_info *next;
    char *name;
    char *desc;
};

static GclDebugInfo *g_info;

static void
gcl_debug_info_free(GclDebugInfo *info);

static void
gcl_debug_info_free_all(void);

static bool
gcl_debug_info_init(void)
{
    static bool g_init;

    if (!g_init) {
        atexit(gcl_debug_info_free_all);
        g_init = true;
    }
    return g_init;
}

GclDebugInfo *
gcl_debug_info_new(const char *name, const char *desc)
{
    GclDebugInfo *info;

    if (!gcl_debug_info_init())
        return NULL;

    info = malloc(sizeof(*info));
    if (!info)
        return NULL;

    info->name = gcl_strdup(name);
    info->desc = gcl_strdup(desc);
    if (!info->name || !info->desc)
        goto error;

    info->next = g_info;
    g_info = info;
    return info;

error:
    gcl_debug_info_free(info);
    return NULL;
}

void
gcl_debug_info_free(GclDebugInfo *info)
{
    if (!info)
        return;
    free(info->name);
    free(info->desc);
    free(info);
}

void
gcl_debug_info_free_all(void)
{
    GclDebugInfo *next, *info = g_info;

    while (info) {
        next = info->next;
        gcl_debug_info_free(info);
        info = next;
    }
}

#define DEFINE_LOGGER(NAME, PREFIX, STREAM, CODE)       \
void                                                    \
NAME(const GclDebugInfo *info, const char *format, ...) \
{                                                       \
    va_list args;                                       \
                                                        \
    fprintf(STREAM, PREFIX ": ");                       \
    if (info)                                           \
        fprintf(STREAM, "%s: ", info->name);            \
    va_start(args, format);                             \
    vfprintf(STREAM, format, args);                     \
    va_end(args);                                       \
    fprintf(STREAM, "\n");                              \
    CODE;                                               \
}

DEFINE_LOGGER(gcl_error,        "error",        stderr, )
DEFINE_LOGGER(gcl_fatal_error,  "fatal error",  stderr, exit(1))
DEFINE_LOGGER(gcl_warning,      "warning",      stdout, )
DEFINE_LOGGER(gcl_info,         "info",         stdout, )
DEFINE_LOGGER(gcl_debug,        "debug",        stdout, )
DEFINE_LOGGER(gcl_log,          "log",          stdout, )

#undef DEFINE_LOGGER
