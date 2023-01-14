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

// C
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct muOS_x86_GlobalDescriptorTableEntry
{
    
} __attribute__((packed));
typedef struct muOS_x86_GlobalDescriptorTableEntry muOS_x86_GlobalDescriptorTableEntry_t;


#ifdef __cplusplus
}
#endif

#endif /* PM_H */

