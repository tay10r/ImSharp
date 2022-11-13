/** @file imsharp_frame.h
 *
 * @brief Contains the API for the rendering of a frame.
 */
#pragma once

#include "imsharp_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Called at the beginning of each frame.
 *
 * @param window The window object creating by the initialization of this library.
 *
 * @return A new frame object. A null pointer indicates failure.
 * */
IMSHARP_API struct imsharp_frame* imsharp_begin_frame(struct imsharp_window* window);

/** Called at the end of each frame. Used to flush operations queued for the GPU.
 *
 * @param frame The object created by @ref imsharp_begin_frame.
 * */
IMSHARP_API void imsharp_end_frame(struct imsharp_frame* frame);

/** Gets the window associated with a frame object.
 *
 * @param frame The frame to get the owning window of.
 *
 * @return A pointer to the window that owns the frame.
 */
IMSHARP_API struct imsharp_window* imsharp_get_frame_window(struct imsharp_frame* frame);

/** Gets the width of the window for this frame.
 *
 * @param frame The frame to get the width of.
 *
 * @return The width of the window, in terms of pixels.
 */
IMSHARP_API int imsharp_window_width(const struct imsharp_frame* frame);

/** Gets the height of the window for this frame.
 *
 * @param frame The frame to get the window height of.
 *
 * @return The height of the window, in terms of pixels.
 */
IMSHARP_API int imsharp_window_height(const struct imsharp_frame* frame);

/** Gets the width of the frame buffer for this frame.
 *
 * @param frame The frame to get the frame buffer width of.
 *
 * @return The width of the frame buffer, in terms of pixels.
 */
IMSHARP_API int imsharp_frame_buffer_width(const struct imsharp_frame* frame);

/** Gets the height of the frame buffer for this frame.
 *
 * @param frame The frame to get the frame buffer height of.
 *
 * @return The height of the frame buffer, in terms of pixels.
 */
IMSHARP_API int imsharp_frame_buffer_height(const struct imsharp_frame* frame);

#ifdef __cplusplus
} /* extern "C" */
#endif
