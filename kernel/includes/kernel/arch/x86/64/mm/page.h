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
 * File:   page.h
 * Author: Javier Marrero
 *
 * Created on January 12, 2023, 3:31 AM
 */

#ifndef x64_PAGE_H
#define x64_PAGE_H

// ==== Paging constants ====
#define PAGE_SIZE   0x1000u     /// The size of a page

#define PTL_NO_EXEC        (1 << 63)
#define PTL_ACCESSED       (1 << 5)
#define PTL_CACHE_DISABLE  (1 << 4)
#define PTL_CACHE_THROUGH  (1 << 3)
#define PTL_USER           (1 << 2)
#define PTL_WRITEABLE      (1 << 1)
#define PTL_PRESENT        1
#define PTL_2MB_PAGE       (1 << 7)

#ifndef __ASSEMBLER__
#ifdef __cplusplus
extern "C"
{
#endif

struct muOS_x86_64_PageMapLevel4Entry
{
    unsigned    m_present           : 1;
    unsigned    m_writeable         : 1;
    unsigned    m_user              : 1;
    unsigned    m_writethrough      : 1;
    unsigned    m_cache_disabled    : 1;
    unsigned    m_accessed          : 1;
    unsigned    : 1;
    unsigned    m_size              : 1;
    unsigned    : 4;
    unsigned    m_page_ppm          : 28;
    unsigned    m_reserved          : 12;
    unsigned    : 11;
    unsigned    m_no_execute        : 1;
} __attribute__((packed));
typedef struct muOS_x86_64_PageMapLevel4Entry muOS_x86_64_PageMapLevel4Entry_t;

struct muOS_x86_64_PageDirectoryPointerTableEntry
{
    unsigned    m_present           : 1;
    unsigned    m_writeable         : 1;
    unsigned    m_user_access       : 1;
    unsigned    m_writethrough      : 1;
    unsigned    m_cache_disabled    : 1;
    unsigned    m_accessed          : 1;
    unsigned    : 1;
    unsigned    m_size              : 1;
    unsigned    : 4;
    unsigned    m_page_ppn          : 28;
    unsigned    m_reserved          : 12;
    unsigned    : 11;
    unsigned    m_no_execute        : 1;
} __attribute__((packed));
typedef struct muOS_x86_64_PageDirectoryPointerTableEntry muOS_x86_64_PageDirectoryPointerTableEntry_t;

struct muOS_x86_64_PageDirectoryTableEntry
{
    unsigned    m_present           : 1;
    unsigned    m_writeable         : 1;
    unsigned    m_user              : 1;
    unsigned    m_writethrough      : 1;
    unsigned    m_cache_disabled    : 1;
    unsigned    m_accessed          : 1;
    unsigned    : 1;
    unsigned    m_size              : 1;
    unsigned    : 4;
    unsigned    m_page_ppn          : 28;
    unsigned    m_reserved          : 12;
    unsigned    : 11;
    unsigned    m_no_execute        : 1;
} __attribute__((packed));
typedef struct muOS_x86_64_PageDirectoryTableEntry muOS_x86_64_PageDirectoryTableEntry_t;

struct muOS_x86_64_PageTableEntry
{
    unsigned    m_present           : 1;
    unsigned    m_writeable         : 1;
    unsigned    m_user              : 1;
    unsigned    m_writethrough      : 1;
    unsigned    m_cache_disabled    : 1;
    unsigned    m_accessed          : 1;
    unsigned    m_dirty             : 1;
    unsigned    m_size              : 1;
    unsigned    m_global            : 1;
    unsigned    : 3;
    unsigned    m_page_ppn          : 28;
    unsigned    m_reserved          : 12;
    unsigned    : 11;
    unsigned    m_no_execute        : 1;
} __attribute__((packed));
typedef struct muOS_x86_64_PageTableEntry muOS_x86_64_PageTableEntry_t;

void muOS_x86_64_TlbShutdown();

#ifdef __cplusplus
}
#endif
#endif
#endif /* PAGE_H */

