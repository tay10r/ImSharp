#pragma once

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct imsharp_context;

struct imsharp_frame;

/** Performs initialization required before entering the window loop.
 *
 * @return A pointer to the data used across iterations of the window loop. A null pointer indicates failure.
 * */
struct imsharp_context* imsharp_setup();

/** Releases resources allocated by the ImSharp native library.
 *
 * @param context The context object created by @ref imsharp_setup.
 * */
void imsharp_cleanup(struct imsharp_context* context);

/** Called at the beginning of each frame.
 *
 * @param context The context object creating by the initialization of this library.
 *
 * @return A new frame object. A null pointer indicates failure.
 * */
struct imsharp_frame* imsharp_begin_frame(struct imsharp_context* context);

/** Called at the end of each frame. Used to flush operations queued for the GPU.
 *
 * @param context The context object creating by the initialization of this library.
 *
 * @param frame The object created by @ref imsharp_begin_frame.
 * */
void imsharp_end_frame(struct imsharp_context* context, struct imsharp_frame* frame);

#ifdef __cplusplus
}
#endif /* __cplusplus */
