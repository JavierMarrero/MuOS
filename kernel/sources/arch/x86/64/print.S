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
.file "print.S"
.section KTEXT32, "ax", @progbits
.align 4
.code32

#include <kernel/arch/asm.h>

FUNCTION(_puts32):
    pusha

1:
    lodsb               // Character to %al

    orb     %al, %al
    jz      .done

    mov     $0x3F8, %dx
    outb    %al, %dx

    jmp 1b

.done:
    popa
    ret

