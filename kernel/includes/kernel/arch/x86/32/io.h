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
 * File:   io.h
 * Author: Javier Marrero
 *
 * Created on January 12, 2023, 3:04 PM
 */

#ifndef IO_H
#define IO_H

// C
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef uint16_t ioport_t;

/**
 * Outputs a byte through the specified I/O port.
 *
 * @param port
 * @param byte
 */
static inline void ml_ia32_pio_o8(ioport_t port, uint8_t byte)
{
    __asm__ __volatile__ ("outb %0, %1" : : "a"(byte), "Nd"(port));
}

#ifdef __cplusplus
}
#endif
#endif /* IO_H */

