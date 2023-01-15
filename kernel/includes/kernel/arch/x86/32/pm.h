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

/* 
 * File:   pm.h
 * Author: Javier Marrero
 *
 * Created on January 14, 2023, 1:11 AM
 */

#ifndef IA32_PROTECTED_MODE_H
#define IA32_PROTECTED_MODE_H

// =================================================
//             GDT ACCESS BYTE CONSTANTS
// =================================================
#define IA32_GDT_SEGMENT_ACCESS_BYTE_MASK   0xFFu
#define IA32_GDT_SEGMENT_PRESENT            (1 << 7)
#define IA32_GDT_SEGMENT_USER               (3 << 5)
#define IA32_GDT_SEGMENT_SUPERVISOR         (0 << 5)
#define IA32_GDT_SEGMENT_SYSTEM            ~(1 << 4)
#define IA32_GDT_SEGMENT_DATA               (2 << 3)
#define IA32_GDT_SEGMENT_CODE               (3 << 3)
#define IA32_GDT_SEGMENT_CONFORMING        ~(1 << 2)
#define IA32_GDT_SEGMENT_NONCONFORMING      (1 << 2)
#define IA32_GDT_SEGMENT_READWRITE          (1 << 1)
#define IA32_GDT_SEGMENT_ACCESSED           (1)

// =================================================
//             GDT FLAGS NIBBLE CONSTANTS
// =================================================
#define IA32_GDT_SEGMENT_GRANULARITY_4K     (1 << 3)
#define IA32_GDT_SEGMENT_GRANULARITY_1B    ~(1 << 3)
#define IA32_GDT_SEGMENT_PROTECTED_MODE     (1 << 2)
#define IA32_GDT_SEGMENT_LONG_MODE          (1 << 1)

// =================================================
//                  MISC CONSTANTS
// =================================================
#define IA32_GDT_NUM_ENTRIES    8
#define IA32_IDT_NUM_ENTRIES    64

#define IA32_NULL_DES     0
/* Warning: Do not reorder the following items, unless you look into syscall.c! */
#define IA32_KTEXT_DES    1
#define IA32_KDATA_DES    2
#define IA32_UDATA_DES    3
#define IA32_UTEXT_DES    4
#define IA32_KTEXT32_DES  5
/* End of warning */
#define IA32_TSS_DES      6

#define IA32_GDT_SELECTOR(des)  ((des) << 3)

#ifndef __ASSEMBLER__

// C
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct muOS_x86_GlobalDescriptorTableEntry
{
    uint16_t    m_limit_low;
    unsigned    m_base_low      : 24;
    uint8_t     m_access;
    unsigned    m_limit_high    : 4;
    unsigned    m_available     : 1;
    unsigned    m_longmode      : 1;
    unsigned    m_special       : 1;
    unsigned    m_granularity   : 1;
    uint8_t     m_base_high;
} __attribute__((packed));
typedef struct muOS_x86_GlobalDescriptorTableEntry muOS_x86_GlobalDescriptorTableEntry_t;

struct muOS_Pointer16_32
{
    uint16_t    m_limit;
    uint32_t    m_base;
} __attribute__((packed));
typedef struct muOS_Pointer16_32 muOS_Pointer16_32_t;

struct muOS_Pointer16_64
{
    uint16_t    m_limit;
    uint64_t    m_base;
} __attribute__((packed));
typedef struct muOS_Pointer16_64 muOS_Pointer16_64_t;

#ifdef __cplusplus
}
#endif

#endif
#endif /* PM_H */

