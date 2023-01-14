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
#ifdef __cplusplus
extern "C"
{
#endif

// ==== Paging constants ====
#define PAGE_SIZE   0x1000u     /// The size of a page

struct muOS_x86_64_PageMapLevel4Entry
{
    unsigned    m_present : 1;
    unsigned    m_writeable : 1;
    unsigned    m_user : 1;
    unsigned    m_writethrough : 1;
    unsigned    m_cache_disabled : 1;
    unsigned    m_accessed : 1;
    unsigned    : 1;
    unsigned    m_size : 1;
    unsigned    : 4;
    unsigned    m_page_ppm : 28;
    unsigned    m_reserved : 12;
    unsigned    : 11;
    unsigned    m_cache_disabled : 1;
} __attribute__((packed));
typedef struct muOS_x86_64_PageMapLevel4Entry muOS_x86_64_PageMapLevel4Entry_t;

#ifdef __cplusplus
}
#endif
#endif /* PAGE_H */

