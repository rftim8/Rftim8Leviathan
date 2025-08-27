#include "logger.hh"

b8 initialize_logging()
{
    // create log file
    return TRUE;
}

void shutdown_logging()
{
    // cleanup logging / write queued entries
}

void log_output(log_level level, const char *message, ...)
{
    const char *level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
    b8 is_error = level < LOG_LEVEL_WARN;

    // 32k character limit
    // stack level
    const i32 msg_length = 32000;
    char out_message[msg_length];
    memset(out_message, 0, sizeof(out_message));

    va_list args;
    va_start(args, message);
    vsnprintf(out_message, msg_length, message, args);
    va_end(args);

    char out_message2[msg_length];
    sprintf(out_message2, "%s%s\n", level_strings[level], out_message);

    // platform specific output
    if (is_error)
        platform_console_write_error(out_message2, level);
    else
        platform_console_write(out_message2, level);
}
