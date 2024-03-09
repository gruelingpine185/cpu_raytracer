#ifndef YK_COMMON_H
#define YK_COMMON_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEBUG 1

#if DEBUG
#define Assert(Expression)       \
    if (!(Expression))           \
    {                            \
        printf("Assert Failed"); \
        volatile int *ptr = 0;   \
        *ptr = 0;                \
    }

#define AssertM(Expression, format, ...)             \
    do                                               \
    {                                                \
        if (!(Expression))                           \
        {                                            \
            printf("Fatal: " format, ##__VA_ARGS__); \
            volatile int *ptr = 0;                   \
            *ptr = 0;                                \
        }                                            \
    } while (0)
#else
#define Assert(Expression)
#define AssertM(Expression, format, ...)
#endif

#define Kilobytes(Value) ((uint64_t)(Value) * 1024)
#define Megabytes(Value) (Kilobytes(Value) * 1024)
#define Gigabytes(Value) (Megabytes(Value) * 1024)
#define Terabytes(Value) (Gigabytes(Value) * 1024)

#define internal static
#define global static
#define local_persist static

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;

/*
Meant to be used as booleans
*/
typedef int8_t b8;

#define true 1
#define false 0

#if defined _WIN32
#define YK_API __declspec(dllexport)
#else
#define YK_API
#endif

#endif