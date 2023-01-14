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
 * File:   globals.h
 * Author: Javier Marrero
 *
 * Created on January 14, 2023, 1:27 AM
 */

#ifndef x86_64_MM_GLOBALS_H
#define x86_64_MM_GLOBALS_H

// MACROS
#define KERNEL_VIRTUAL_BASE     0xFFFFFFFFE0000000

#ifdef __ASSEMBLER__

#define VA2PA(x)    ((x) - KERNEL_VIRTUAL_BASE)
#define PA2VA(x)    ((x) + KERNEL_VIRTUAL_BASE)

#else

#define VA2PA(x)    (((uintptr_t)(x)) - KERNEL_VIRTUAL_BASE)
#define PA2VA(x)    (((uintptr_t)(x)) + KERNEL_VIRTUAL_BASE)

#endif

#ifndef __ASSEMBLER__

// C
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif



#ifdef __cplusplus
}
#endif
#endif
#endif /* GLOBALS_H */

