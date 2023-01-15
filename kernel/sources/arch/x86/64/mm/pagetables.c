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

#include <kernel/arch/x86/64/mm/globals.h>
#include <kernel/arch/x86/64/mm/page.h>

//
// This file contains the global variables that compose the initial address space.
// Please, do not modify the alignment of the following structures, nor its compositions, or bad things will happen.
// You may get haunted, for instance.
//

extern muOS_x86_64_PageDirectoryTableEntry_t           ptl_2[512];
extern muOS_x86_64_PageDirectoryPointerTableEntry_t    ptl_1[512];
extern muOS_x86_64_PageMapLevel4Entry_t                ptl_0[512];

void muOS_x86_64_TlbShutdown()
{
    __asm__ __volatile__ ("movq %cr3, %rax; movq %rax, %cr3");
}
