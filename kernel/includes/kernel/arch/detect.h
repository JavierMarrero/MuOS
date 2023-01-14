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
 * File:   detect.h
 * Author: Javier Marrero
 *
 * Created on January 13, 2023, 10:16 PM
 */

#ifndef ARCH_DETECT_H
#define ARCH_DETECT_H

#if defined(__x86_64__) || defined(_x86_64) || defined(x86_64)
#   define MEL_TARGET_AMD64
#elif defined (__x86__) || defined(__ia32__)
#   define MEL_TARGET_IA32
#else
#error "Your system is not configured for the target architecture. Please, fix before it starts destroying the world.F"
#endif

#endif /* DETECT_H */

