/** @file common.h
 *
 * @brief Contains code used across different header files.
 */
#pragma once

#ifdef _WIN32
#define IMSHARP_API __declspec(dllexport)
#else
#define IMSHARP_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

/** The boolean value for true. */
#define IMSHARP_TRUE 1

/** The boolean value for false. */
#define IMSHARP_FALSE 0

/** A type definition for an integer that acts as a boolean type.
 * Use @ref IMSHARP_TRUE and @ref IMSHARP_FALSE when appropriate.
 * Assume 0 is false and 1 is true in all other cases.
 */
typedef int imsharp_boolean_int;

struct imsharp_app;

struct imsharp_window;

struct imsharp_frame;

struct imsharp_texture;

#ifdef __cplusplus
}
#endif
