#pragma once

#include "imsharp/common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

IMSHARP_API imsharp_boolean_int imsharp_begin_plot(struct imsharp_window* window, struct imsharp_frame* frame,
                                                   const char* label);

IMSHARP_API void imsharp_end_plot(struct imsharp_window* window, struct imsharp_frame* frame);

#ifdef __cplusplus
}
#endif /* __cplusplus */
