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

#include <kernel/logging.h>

ml_logger_t* ml_logger_init(ml_logger_t* self, const char* name, ml_log_level_t level)
{
    self->m_name = name;
    self->m_level = level;

    return self;
}

bool ml_logger_is_loggable(const ml_logger_t * restrict self, ml_log_level_t level)
{
    return self->m_level >= level;
}

void ml_logger_log(const ml_logger_t* self, ml_log_level_t level, const char* fmt, ...)
{
    if (ml_logger_is_loggable(self, level))
    {
        
    }
}
