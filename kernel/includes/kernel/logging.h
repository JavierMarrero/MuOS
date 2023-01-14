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
 * File:   logging.h
 * Author: Javier Marrero
 *
 * Created on January 12, 2023, 3:35 AM
 */

#ifndef LOGGING_H
#define LOGGING_H
#ifdef __cplusplus
extern "C"
{
#endif

// C
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

// KERNEL
#include <kernel/config.h>

#define ML_MAX_LOGGING_OUTPUTS  4

/**
 * This is a function pointer that acts as an output function for the log messages.
 */
typedef void (*muOS_LoggerPrintFunctionType)(const char* str);

// =========================================
//          Log output functions
// =========================================
void muOS_LoggerUartOutput(const char* str);

/**
 * This enumeration type holds all the possible values for the log messages.
 */
typedef enum muOS_LogLevel
{
    L_ALL = -1,
    L_DEBUG,
    L_TRACE,
    L_INFO,
    L_WARNING,
    L_ERROR,
    L_OFF = INT_MAX
} muOS_LogLevel_t;

/**
 * Objects of this type handle debug logging. Using an object explicitly allows for easily discriminating by level and
 * filter log messages for different routines. There's a global logging object just in case you don't want to initialize
 * your own logging object. Notice how all the logging functions only have effect if the appropriate configuration macro
 * is enabled.
 * <p>
 * The function pointers should point to any of the debug output functions. By default, the first of these points to the
 * UART serial output. There are 4 slots for debugging functions, in case alternative output methods are used.
 * <p>
 * The structure is designed to be instantiated on the stack. Please, do not use the heap for initializing logging
 * objects, is a waste of time and space. The object itself is about 48 bytes long. This is why we don't provide a
 * 'new' operator function.
 * <p>
 * You may use the C default initialization array syntax to initialize this structure. Just be sure to initialize
 * correctly all the fields. If a <code>m_writers</code> field is not <code>NULL</code> but also ain't no valid
 * pointer, a page fault will arise. <b>All the writers must be NULL if they don't point to a valid memory location</b>.
 * One may find easier to use the initialization function instead.
 *
 * @author J. Marrero
 */
typedef struct muOS_Logger
{
    const char*         m_name;
    muOS_LogLevel_t       m_level;

    muOS_LoggerPrintFunctionType m_writers[ML_MAX_LOGGING_OUTPUTS];
} muOS_Logger_t;

muOS_Logger_t   muOS_Logger_Init(const char* name, muOS_LogLevel_t level);  /// Initializes the objects

bool muOS_Logger_IsLoggable(const muOS_Logger_t* restrict self, muOS_LogLevel_t level); /// Can a logger log messages of this level?
void muOS_Logger_Log_(const muOS_Logger_t* self, muOS_LogLevel_t level, const char* file, const char* func, const int line, const char* fmt, ...); /// Log a message

/**
 * Log function. The parameters are:
 *
 * @param l the logger instance
 * @param lv the level of the message
 * @param fmt the format of the string (printf-like)
 */
#define muOS_Logger_Log(l, lv, ...)  muOS_Logger_Log_(l, lv, __FILE__, __func__, __LINE__, __VA_ARGS__)

// ====================
// Static methods
// ====================
const muOS_Logger_t* muOS_GetGlobalLogger();

#ifdef __cplusplus
}
#endif
#endif /* LOGGING_H */

