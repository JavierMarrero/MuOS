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
.file "start.S"
.section KTEXT32, "ax", @progbits
.align 4
.code32

#include <kernel/arch/asm.h>

.macro print msg
    movl    \msg, %esi
    call    _puts32
.endm

FUNCTION(multiboot_entry_point):

    // Set up the initial stack
    movl    $stack32_top, %esp

    // Print the initial status
    print   $status_begin

    // Halt the kernel. Reaching this statement indicates a boot failure.
    // So, we probably would have to print an error message.
.epilogue:
    hlt
    jmp .epilogue

// ==================
//      MESSAGES
// ==================

err_no_cpuid: .string "Error: Hardware does not supports CPUID instruction."

status_begin: .string "[x86_64] Loading kernel..."
