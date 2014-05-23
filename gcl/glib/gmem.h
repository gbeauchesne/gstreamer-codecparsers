/*
 *  gmem.h - GCL replacements for <glib/gmem.h>
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

#ifndef GCL_GMEM_H
#define GCL_GMEM_H

#include <gcl/gcl_memory.h>

#undef  G_GNUC_MALLOC
#define G_GNUC_MALLOC /* nothing */

#undef  g_free
#define g_free(mem)                     free(mem)
#undef  g_try_malloc
#define g_try_malloc(size)              malloc(size)
#undef  g_try_malloc0
#define g_try_malloc0(size)             calloc(size, 1)
#undef  g_try_malloc_n
#define g_try_malloc_n(nb, bs)          g_try_malloc((bs) * (nb))
#undef  g_try_new
#define g_try_new(type, n)              g_try_malloc((n) * sizeof(type))
#undef  g_try_new0
#define g_try_new0(ype, n)              g_try_malloc0((n) sizeof(type))

/* XXX: not same semantics */
#undef  g_try_realloc
#define g_try_realloc(mem, size)        realloc(mem, size)
#undef  g_try_realloc_n
#define g_try_realloc_n(mem, nb, bs)    g_try_realloc(mem, (bs) * (nb))

#undef  g_malloc
#define g_malloc(size)                  g_mem_check(g_try_malloc(size))
#undef  g_malloc0
#define g_malloc0(size)                 g_mem_check(g_try_malloc0(size))
#undef  g_malloc_n
#define g_malloc_n(nb, bs)              g_mem_check(g_try_malloc_n(nb, bs))
#undef  g_realloc
#define g_realloc(mem, size)            g_mem_check(g_try_realloc(mem, size))
#undef  g_realloc_n
#define g_realloc_n(mem, nb, bs)        g_mem_check(g_try_realloc_n(mem, nb, bs))
#undef  g_new
#define g_new(type, n)                  g_malloc(sizeof(type) * (n))
#undef  g_new0
#define g_new0(type, n)                 g_malloc0(sizeof(type) * (n))
#undef  g_mem_check
#define g_mem_check(mem)                g_mem_check_I(mem, __FILE__, __LINE__)

static inline void *
g_mem_check_I(void *mem, const char *file, int line)
{
    if (!mem)
        gcl_failed_expr_error_I(mem != NULL, file, line);
    return mem;
}

#undef  g_memdup
#define g_memdup(mem, size)             gcl_memdup((mem), (size))

#endif /* GCL_GMEM_H */
