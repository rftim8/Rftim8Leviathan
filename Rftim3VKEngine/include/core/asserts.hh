#pragma once
#include "defines.hh"
#include "logger.hh"

#define RFT_ASSERTIONS_ENABLED

#ifdef RFT_ASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

RFT_API void report_assertion_failure(const char *expression, const char *message, const char *file, i32 line);

#define RFT_ASSERT(expr)                                             \
    {                                                                \
        if (expr)                                                    \
        {                                                            \
        }                                                            \
        else                                                         \
        {                                                            \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }

#define RFT_ASSERT_MSG(expr, message)                                     \
    {                                                                     \
        if (expr)                                                         \
        {                                                                 \
        }                                                                 \
        else                                                              \
        {                                                                 \
            report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }

#ifdef _DEBUG
#define RFT_ASSERT_DEBUG(expr)                                       \
    {                                                                \
        if (expr)                                                    \
        {                                                            \
        }                                                            \
        else                                                         \
        {                                                            \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }

#else
#define RFT_ASSERT_DEBUG(expr)
#endif

#else
#define RFT_ASSERT(expr)
#define RFT_ASSERT_MSG(expr, message)
#define RFT_ASSERT_DEBUG(expr)
#endif