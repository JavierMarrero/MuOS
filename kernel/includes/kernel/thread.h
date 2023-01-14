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
 * File:   thread.h - Kernel threading API
 * Author: Javier Marrero
 *
 * Created on January 12, 2023, 10:37 PM
 */

#ifndef THREAD_H
#define THREAD_H

// C
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * It seems rather implausible that a given process has more than 2^16 threads.
 */
typedef uint16_t tid_t;

/**
 * The thread control block structure holds all the information related to threads.
 */
typedef struct muOS_tcb
{
    uintptr_t   m_stack;    /// The stack address
    tid_t       m_tid;      /// The thread ID
} muOS_tcb_t;

#ifdef __cplusplus
}
#endif

#endif /* THREAD_H */

