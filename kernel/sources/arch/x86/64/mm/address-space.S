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
.file "address-space.S"
.section .data, "aw", @progbits

#include <kernel/arch/x86/64/mm/globals.h>
#include <kernel/arch/x86/64/mm/page.h>
#include <kernel/arch/asm.h>

/**
 * Paging structures for the x86-64 architecture. This initial mapping describes the initial address space layout for
 * the MEL microkernel.
 */

#define PAGING_SYMBOL(x) \
    .align 4096; \
    .global x; \
    x

PAGING_SYMBOL(ptl_3_1):
    .fill 512, 8, 0
PAGING_SYMBOL(ptl_3_2):
    .fill 512, 8, 0

PAGING_SYMBOL(ptl_2_1):
    .quad VA2PA(ptl_3_1) + (PTL_PRESENT | PTL_WRITEABLE)
    .fill 511, 8, 0

PAGING_SYMBOL(ptl_1_1):
    .quad VA2PA(ptl_2_1) + (PTL_PRESENT | PTL_WRITEABLE)
    .fill 511, 8, 0

PAGING_SYMBOL(ptl_1_2):
    .fill 511, 8, 0
    .quad VA2PA(ptl_2_1) + (PTL_PRESENT | PTL_WRITEABLE)

PAGING_SYMBOL(ptl_0):
    .quad VA2PA(ptl_1_1) + (PTL_PRESENT | PTL_WRITEABLE)
    .fill 510, 8, 0
    .quad VA2PA(ptl_1_2) + (PTL_PRESENT | PTL_WRITEABLE)


