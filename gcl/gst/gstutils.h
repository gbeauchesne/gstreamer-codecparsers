/*
 *  gstutils.h - GCL replacements for <gst/gstutils.h>
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

#ifndef GCL_GSTUTILS_H
#define GCL_GSTUTILS_H

#include <gcl/gcl_numeric.h>

#undef  GST_READ_UINT8
#define GST_READ_UINT8(mem)             gcl_read_uint8(mem)
#undef  GST_READ_UINT16_LE
#define GST_READ_UINT16_LE(mem)         gcl_read_uint16_le(mem)
#undef  GST_READ_UINT16_BE
#define GST_READ_UINT16_BE(mem)         gcl_read_uint16_be(mem)
#undef  GST_READ_UINT24_LE
#define GST_READ_UINT24_LE(mem)         gcl_read_uint24_le(mem)
#undef  GST_READ_UINT24_BE
#define GST_READ_UINT24_BE(mem)         gcl_read_uint24_be(mem)
#undef  GST_READ_UINT32_LE
#define GST_READ_UINT32_LE(mem)         gcl_read_uint32_le(mem)
#undef  GST_READ_UINT32_BE
#define GST_READ_UINT32_BE(mem)         gcl_read_uint32_be(mem)
#undef  GST_READ_UINT64_LE
#define GST_READ_UINT64_LE(mem)         gcl_read_uint64_le(mem)
#undef  GST_READ_UINT64_BE
#define GST_READ_UINT64_BE(mem)         gcl_read_uint64_be(mem)
#undef  GST_READ_FLOAT_LE
#define GST_READ_FLOAT_LE(mem)          gcl_read_float32_le(mem)
#undef  GST_READ_FLOAT_BE
#define GST_READ_FLOAT_BE(mem)          gcl_read_float32_be(mem)
#undef  GST_READ_DOUBLE_LE
#define GST_READ_DOUBLE_LE(mem)         gcl_read_float64_le(mem)
#undef  GST_READ_DOUBLE_BE
#define GST_READ_DOUBLE_BE(mem)         gcl_read_float64_be(mem)

#undef  GST_ROUND_UP_2
#define GST_ROUND_UP_2(v)               gcl_round_up_p2n(v, 1)
#undef  GST_ROUND_UP_4
#define GST_ROUND_UP_4(v)               gcl_round_up_p2n(v, 2)
#undef  GST_ROUND_UP_8
#define GST_ROUND_UP_8(v)               gcl_round_up_p2n(v, 3)
#undef  GST_ROUND_UP_16
#define GST_ROUND_UP_16(v)              gcl_round_up_p2n(v, 4)
#undef  GST_ROUND_UP_32
#define GST_ROUND_UP_32(v)              gcl_round_up_p2n(v, 5)
#undef  GST_ROUND_UP_64
#define GST_ROUND_UP_64(v)              gcl_round_up_p2n(v, 6)

#undef  GST_ROUND_DOWN_2
#define GST_ROUND_DOWN_2(v)             gcl_round_down_p2n(v, 1)
#undef  GST_ROUND_DOWN_4
#define GST_ROUND_DOWN_4(v)             gcl_round_down_p2n(v, 2)
#undef  GST_ROUND_DOWN_8
#define GST_ROUND_DOWN_8(v)             gcl_round_down_p2n(v, 3)
#undef  GST_ROUND_DOWN_16
#define GST_ROUND_DOWN_16(v)            gcl_round_down_p2n(v, 4)
#undef  GST_ROUND_DOWN_32
#define GST_ROUND_DOWN_32(v)            gcl_round_down_p2n(v, 5)
#undef  GST_ROUND_DOWN_64
#define GST_ROUND_DOWN_64(v)            gcl_round_down_p2n(v, 6)

#endif /* GCL_GSTUTILS_H */
