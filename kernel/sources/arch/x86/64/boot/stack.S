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
.file "stack.S"
.section KBSS32, "aw", @nobits
.align 16

#include <kernel/arch/asm.h>

GLOBAL_SYMBOL(stack32_bottom):
    .skip   0x400               // 1024 bytes initial stack. Seems more than fair
GLOBAL_SYMBOL(stack32_top):

.section .bss, "aw", @nobits
.align 16

GLOBAL_SYMBOL(stack64_bottom):
    .skip   0x8000              // 32KiB stack size
GLOBAL_SYMBOL(stack64_top):
