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
#include <stdbool.h>

typedef void (*ml_logger_print_function)(const char* str);

typedef enum ml_log_level
{
    ALL = -1,
    DEBUG,
    TRACE,
    INFO,
    WARNING,
    ERROR,
    OFF = INT_MAX
} ml_log_level_t;

typedef struct ml_logger
{
    const char*     m_name;
    ml_log_level_t  m_level;
} ml_logger_t;

ml_logger_t* ml_logger_init(ml_logger_t* self, const char* name, ml_log_level_t level);

/**
 * Returns true if the given logger will dispatch messages with the provided level or higher.
 *
 * @param self
 * @param level
 * @return
 */
bool ml_logger_is_loggable(const ml_logger_t* restrict self, ml_log_level_t level);

void ml_logger_log(const ml_logger_t* self, ml_log_level_t level, const char* fmt, ...);

#ifdef __cplusplus
}
#endif
#endif /* LOGGING_H */

