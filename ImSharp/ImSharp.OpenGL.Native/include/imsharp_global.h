/** @file imsharp_global.h
 *
 * @brief Contains the API for global state.
 */
#pragma once

#include "imsharp_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Performs the initialization of global data.
 *
 * This library does not declare any global data itself, but some dependencies do.
 *
 * @return Non-zero on success, zero on failure. The integer returned here acts as a boolean success indicator.
 */
IMSHARP_API imsharp_boolean_int imsharp_global_init(void);

/** Performs cleanup of global data. */
IMSHARP_API void imsharp_global_cleanup(void);

/** Checks for user events, such as mouse clicks or keyboard presses. */
IMSHARP_API void imsharp_poll_events(void);

#ifdef __cplusplus
} /* extern "C" */
#endif
