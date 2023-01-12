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
 * File:   libc.h
 * Author: Javier Marrero
 *
 * Created on January 12, 2023, 2:05 PM
 */

#ifndef LIBC_H
#define LIBC_H
#ifdef __cplusplus
extern "C"
{
#endif

// C
#include <stddef.h>

void*   memset(void* buffer, int c, size_t len);
size_t  strlen(const char* __restrict__ str);

#ifdef __cplusplus
}
#endif
#endif /* LIBC_H */

