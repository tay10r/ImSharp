#pragma once

#include <GLFW/glfw3.h>

#ifdef _WIN32
#define IMSHARP_API __declspec(dllexport)
#else
#define IMSHARP_API
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct imsharp_window;
struct imsharp_frame;

/** Performs the initialization of global data.
 *
 * This library does not declare any global data itself, but GLFW does.
 *
 * @return Non-zero on success, zero on failure. The integer returned here acts as a boolean success indicator.
 */
IMSHARP_API int imsharp_global_init(void);

/** Performs cleanup of global data. */
IMSHARP_API void imsharp_global_cleanup(void);

/** Checks for user events, such as mouse clicks or keyboard presses. */
IMSHARP_API void imsharp_poll_events(void);

/** Creates a new window.
 *
 * @return A pointer to the window data.
 * */
IMSHARP_API struct imsharp_window* imsharp_create_window(void);

/** Indicates whether or not the window should close.
 *
 * @param window The window to check the closing flag of.
 *
 * @return Non-zero if the window should close, zero otherwise.
 */
IMSHARP_API int imsharp_window_should_close(struct imsharp_window* window);

/** Releases resources allocated by the ImSharp native library.
 *
 * @param window The window object created by @ref imsharp_setup.
 * */
IMSHARP_API void imsharp_destroy_window(struct imsharp_window* window);

/** Called at the beginning of each frame.
 *
 * @param window The window object creating by the initialization of this library.
 *
 * @return A new frame object. A null pointer indicates failure.
 * */
IMSHARP_API struct imsharp_frame* imsharp_begin_frame(struct imsharp_window* window);

/** Called at the end of each frame. Used to flush operations queued for the GPU.
 *
 * @param window The window object creating by the initialization of this library.
 *
 * @param frame The object created by @ref imsharp_begin_frame.
 * */
IMSHARP_API void imsharp_end_frame(struct imsharp_window* window, struct imsharp_frame* frame);

/** Called when a new top-level widget is being rendered.
 *
 * @param window The window object creating by the initialization of this library.
 *
 * @param frame The frame to draw the widge on.
 * 
 * @param title The name of give the widget.
 */
IMSHARP_API void imsharp_begin_widget(struct imsharp_window* window, struct imsharp_frame* frame, const char* title);

/** Called to complete a top-level widget.
 *
 * @param window The window object creating by the initialization of this library.
 *
 * @param frame The frame to draw the widge on.
 */
IMSHARP_API void imsharp_end_widget(struct imsharp_window* window, struct imsharp_frame* frame);

IMSHARP_API const int* imsharp_get_style_color_ids(void);

IMSHARP_API int imsharp_get_style_color_count(void);

IMSHARP_API const char* imsharp_get_style_color_name(int id);

IMSHARP_API void imsharp_push_style_color(struct imsharp_window* window,
    struct imsharp_frame* frame,
    int color_id,
    unsigned char r,
    unsigned char g,
    unsigned char b,
    unsigned char a);

IMSHARP_API void imsharp_pop_style_color(struct imsharp_window* window, struct imsharp_frame* frame);

IMSHARP_API void imsharp_set_background_color(struct imsharp_window* window, unsigned char r, unsigned char g, unsigned char b, unsigned char a);

#ifdef __cplusplus
}
#endif /* __cplusplus */
