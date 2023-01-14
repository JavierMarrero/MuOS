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
 * File:   capabilities.h
 * Author: Javier Marrero
 *
 * Created on January 14, 2023, 2:53 AM
 */

#ifndef CAPABILITIES_H
#define CAPABILITIES_H

// C
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct muOS_CapabilityObject
{
    uint64_t    m_uid;
    uint32_t    m_version;
    uint32_t    m_type;
} muOS_CapabilityObject_t;

#ifdef __cplusplus
}
#endif

#endif /* CAPABILITIES_H */

