#pragma once
#include "defines.hh"
#include "platform.hh"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <iostream>

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// disable debug and trace when release builds
#if RFT_RELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level
{
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} log_level;

b8 initialize_logging();
void shutdown_logging();

RFT_API void log_output(log_level level, const char *message, ...);

// fatal-level log message
#define RFT_FATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef RFT_ERROR
// error-level log message
#define RFT_ERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
// warning-level log message
#define RFT_WARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
// nothing if not enabled
#define RFT_WARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
// info-level log message
#define RFT_INFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
// nothing if not enabled
#define RFT_INFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
// debug-level log message
#define RFT_DEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
// nothing if not enabled
#define RFT_DEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
// trace-level log message
#define RFT_TRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
// nothing if not enabled
#define RFT_TRACE(message, ...)
#endif




