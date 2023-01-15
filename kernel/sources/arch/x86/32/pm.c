/*
 * Copyright (C) 2023 Javier Marrero
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <kernel/arch/x86/32/pm.h>

muOS_x86_GlobalDescriptorTableEntry_t muOS_x86_GlobalDescriptorTable[IA32_GDT_NUM_ENTRIES] = {
    [IA32_NULL_DES] =
    {
        0
    },
    [IA32_KTEXT_DES] =
    {
        .m_limit_low = 0xffffU,
        .m_access = IA32_GDT_SEGMENT_PRESENT | IA32_GDT_SEGMENT_CODE | IA32_GDT_SEGMENT_SUPERVISOR | IA32_GDT_SEGMENT_READWRITE,
        .m_limit_high = 0xfU,
        .m_longmode = 1,
        .m_granularity = 1
    },
    [IA32_KDATA_DES] =
    {
        .m_limit_low = 0xffffU,
        .m_access = IA32_GDT_SEGMENT_PRESENT | IA32_GDT_SEGMENT_DATA | IA32_GDT_SEGMENT_READWRITE | IA32_GDT_SEGMENT_SUPERVISOR,
        .m_limit_high = 0xfU,
        .m_granularity = 1
    },
    [IA32_UDATA_DES] =
    {
        .m_limit_low = 0xffffU,
        .m_access = IA32_GDT_SEGMENT_PRESENT | IA32_GDT_SEGMENT_DATA | IA32_GDT_SEGMENT_READWRITE | IA32_GDT_SEGMENT_USER,
        .m_limit_high = 0xfU,
        .m_special = 1,
        .m_granularity = 1
    },
    [IA32_UTEXT_DES] =
    {
        .m_limit_low = 0xffffU,
        .m_access = IA32_GDT_SEGMENT_PRESENT | IA32_GDT_SEGMENT_CODE | IA32_GDT_SEGMENT_USER,
        .m_limit_high = 0xfU,
        .m_longmode = 1,
        .m_granularity = 1
    },
    [IA32_KTEXT32_DES] =
    {
        .m_limit_low = 0xffffU,
        .m_access = IA32_GDT_SEGMENT_PRESENT | IA32_GDT_SEGMENT_CODE | IA32_GDT_SEGMENT_SUPERVISOR | IA32_GDT_SEGMENT_READWRITE,
        .m_limit_high = 0xfU,
        .m_special = 1,
        .m_granularity = 1
    },
    /*
     * TSS descriptor - set up will be completed later,
     * on AMD64 it is 64-bit - 2 items in the table
     */
    [IA32_TSS_DES] =
    {
        0
    },
    [IA32_TSS_DES + 1] =
    {
        0
    }
};
