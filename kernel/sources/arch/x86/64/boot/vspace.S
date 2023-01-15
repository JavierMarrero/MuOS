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
.file "vspace.S"
.section KTEXT32, "ax", @progbits
.align 4
.code32

#include <kernel/arch/x86/64/mm/globals.h>
#include <kernel/arch/x86/64/mm/page.h>
#include <kernel/arch/asm.h>

//
// This function performs the mapping of the kernel virtual address space. The kernel virtual address space, initially
// consists of two different mappings: the identity mapping and the virtual address higher half mapping. The kernel
// is loaded at 1MiB and also paged to 0xFFFFFFFFE0000000. The kernel claims the final 512MiB of address space for
// itself.
// Since the mapping in the AMD64 architecture is done in 4 levels:
//
// Identity mapping:
//
// PML4:    0
// PDPT:    0
// PDT:     0
// PT:      0
//
// Virtual address mapping:
//
// PML4:    512
// PDPT:
// PDT:
// PT:
//
FUNCTION(muOS_BootMapVSpace):
    // Save context
    pusha

    movl    $status_mapping, %esi
    call    _puts32

    // Create the stack frame up to which all the local variables will be created
    movl    %esp, %ebp

    // Begin mapping
    movl    $VA2PA(ptl_3_1), %edi
    movl    $0, %esi

1:
    cmpl    $VA2PA(kernel_end_address), %esi
    jge     3f

    movl    %esi, %edx

    cmpl    $VA2PA(mapped_rw_lo), %esi
    jae     .L2

    orl     $PTL_PRESENT, %edx
    jmp     .L3
.L2:
    orl     $(PTL_PRESENT | PTL_WRITEABLE), %edx

.L3:
    movl    %edx, (%edi)

2:
    addl    $0x1000, %esi
    addl    $8, %edi
    jmp     1b

3:

    // Pop context and return
    popa
    ret

status_mapping: .string "[x86-64] Mapping kernel virtual address space...\r\n"
