#pragma once
// unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// signed int types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// floating point types
typedef float f32;
typedef double f64;

// boolean types
typedef int b32;
typedef char b8;

// defining static assertions
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// verify types are correct on different platforms
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes.");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes.");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes.");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes.");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes.");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");

#define TRUE 1
#define FALSE 0

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define RFT_PLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required!"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
// Linux OS
#define RFT_PLATFORM_LINUX 1
#if defined(__ANDROID__)
#define RFT_PLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
// Everything else
#define RFT_PLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
// POSIX
#define RFT_PLATFORM_POSIX 1
#elif __APPLE__
// Apple platforms
#define RFT_PLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#define RFT_PLATFORM_IOS 1
#define RFT_PLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define RFT_PLATFORM_IOS 1
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#else
#error "Unknown Apple platform"
#endif
#else
#error "Unknown platform!"
#endif

// functions for externals
#ifdef BUILDING_Rftim3VKEngine
// Exports
#ifdef _MSC_VER
#define RFT_API __declspec(dllexport)
#else
#define RFT_API __attribute__((visibility("default")))
#endif
#else
// Imports
#ifdef _MSC_VER
#define RFT_API __declspec(dllimport)
#else
#define RFT_API
#endif
#endif
