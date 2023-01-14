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
 * File:   ipc.h
 * Author: Javier Marrero
 *
 * Created on January 12, 2023, 11:16 PM
 */

#ifndef IPC_H
#define IPC_H

// C
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Ports are IPC rendezvous objects. They encapsulate the transmission channel over which communication between
 * processes is performed.
 */
typedef struct muOS_ipc_port
{
    int m_id;
} muOS_ipc_port_t;

#ifdef __cplusplus
}
#endif

#endif /* IPC_H */

