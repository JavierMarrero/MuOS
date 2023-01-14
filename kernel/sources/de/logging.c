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
#include <kernel/printf.h>

static const char* ml_level_to_string(muOS_LogLevel_t level)
{
    switch (level)
    {
    case L_DEBUG:
        return "DEBUG";
    case L_ERROR:
        return "ERROR";
    case L_INFO:
        return "INFO";
    case L_TRACE:
        return "TRACE";
    case L_WARNING:
        return "WARNING";
    default:
        return "x";
    }
}

muOS_Logger_t muOS_Logger_Init(const char* name, muOS_LogLevel_t level)
{
    muOS_Logger_t self;

    self.m_name = name;
    self.m_level = level;

    self.m_writers[0] = muOS_LoggerUartOutput;
    for (int i = 1; i < ML_MAX_LOGGING_OUTPUTS; ++i)
    {
        self.m_writers[i] = NULL;
    }
    return self;
}

bool muOS_Logger_IsLoggable(const muOS_Logger_t * restrict self, muOS_LogLevel_t level)
{
    return self->m_level >= level;
}

void muOS_Logger_Log_(const muOS_Logger_t* self,
                    muOS_LogLevel_t level,
                    const char* file,
                    const char* func,
                    const int line,
                    const char* fmt,
                    ...)
{
    if (muOS_Logger_IsLoggable(self, level))
    {
        va_list va;
        va_start(va, fmt);

        char buffer[0x4000] = {0};
        size_t addendum = sprintf(buffer, "[%s] (%s) <%s> (%s : %d): ",
                                  ml_level_to_string(level),
                                  self->m_name,
                                  file,
                                  func,
                                  line);
        vsnprintf(buffer + addendum, 0x4000, fmt, va);

        for (int i = 0; i < ML_MAX_LOGGING_OUTPUTS; ++i)
        {
            if (self->m_writers[i] != NULL)
            {
                self->m_writers[i](buffer);
            }
        }

        va_end(va);
    }
}

const muOS_Logger_t* muOS_GetGlobalLogger()
{
    static muOS_Logger_t m_global_logger;
    return &m_global_logger;
}
