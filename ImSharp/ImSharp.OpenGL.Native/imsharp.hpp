#pragma once

#ifdef _WIN32
#define IMSHARP_API __declspec(dllexport)
#else
#define IMSHARP_API
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** A type definition for an integer that acts as a boolean type.
 */
typedef int imsharp_boolean_int;

struct imsharp_window;
struct imsharp_frame;

/** Performs the initialization of global data.
 *
 * This library does not declare any global data itself, but GLFW does.
 *
 * @return Non-zero on success, zero on failure. The integer returned here acts as a boolean success indicator.
 */
IMSHARP_API imsharp_boolean_int imsharp_global_init(void);

/** Performs cleanup of global data. */
IMSHARP_API void imsharp_global_cleanup(void);

/** Checks for user events, such as mouse clicks or keyboard presses. */
IMSHARP_API void imsharp_poll_events(void);

/** Creates a new window.
 *
 * @return A pointer to the window data.
 * */
IMSHARP_API struct imsharp_window* imsharp_create_window(void);

/** Releases resources allocated by the ImSharp native library.
 *
 * @param window The window object created by @ref imsharp_setup.
 * */
IMSHARP_API void imsharp_destroy_window(struct imsharp_window* window);

/** Indicates whether or not the window should close.
 *
 * @param window The window to check the closing flag of.
 *
 * @return Non-zero if the window should close, zero otherwise.
 */
IMSHARP_API imsharp_boolean_int imsharp_window_should_close(struct imsharp_window* window);

/** Sets whether or not the window should close.
 *
 * @param window The window to set the close flag of.
 * 
 * @param should_close The flag to indicate whether or not the window should close.
 */
IMSHARP_API void imsharp_set_window_should_close(struct imsharp_window* window, imsharp_boolean_int should_close);

/** Makes the window visible to the user.
* 
* @param window The window to make visible.
* 
* @note This function can be harmlessly called successively.
 */
IMSHARP_API void imsharp_show_window(struct imsharp_window* window);

/** Hides the window from the user.
 * 
 * @param window The window to hide.
 *
 * @note This function can be harmlessly called successively.
 */
IMSHARP_API void imsharp_hide_window(struct imsharp_window* window);

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

IMSHARP_API int imsharp_window_width(struct imsharp_window* window, struct imsharp_frame* frame);

IMSHARP_API int imsharp_window_height(struct imsharp_window* window, struct imsharp_frame* frame);

IMSHARP_API int imsharp_framebuffer_width(struct imsharp_window* window, struct imsharp_frame* frame);

IMSHARP_API int imsharp_framebuffer_height(struct imsharp_window* window, struct imsharp_frame* frame);

/** Called when a new top-level widget is being rendered.
 *
 * @param window The window object creating by the initialization of this library.
 *
 * @param frame The frame to draw the widget on.
 * 
 * @param title The name of give the widget.
 */
IMSHARP_API void imsharp_begin_widget(struct imsharp_window* window, struct imsharp_frame* frame, const char* title);

/** Called to complete a top-level widget.
 *
 * @param window The window object creating by the initialization of this library.
 *
 * @param frame The frame to draw the widget on.
 */
IMSHARP_API void imsharp_end_widget(struct imsharp_window* window, struct imsharp_frame* frame);

IMSHARP_API void imsharp_set_next_widget_position(struct imsharp_window* window, struct imsharp_frame* frame, int x,
                                                  int y);

IMSHARP_API void imsharp_set_next_widget_size(struct imsharp_window* window, struct imsharp_frame* frame, int w, int h);

IMSHARP_API void imsharp_same_line(struct imsharp_window* window, struct imsharp_frame* frame);

IMSHARP_API void imsharp_separator(struct imsharp_window* window, struct imsharp_frame* frame);

/** Called to render a button.
 * 
 * @param window The window to render the button in.
 * 
 * @param frame The current frame being rendered.
 * 
 * @param label The text to appear on the button.
 * 
 * @return Non-zero if the button was pressed, zero otherwise.
 */
IMSHARP_API imsharp_boolean_int imsharp_button(struct imsharp_window* window, struct imsharp_frame* frame,
                                               const char* label);

IMSHARP_API imsharp_boolean_int imsharp_checkbox(struct imsharp_window* window, struct imsharp_frame* frame,
                                                 const char* label, imsharp_boolean_int* checked);

IMSHARP_API imsharp_boolean_int imsharp_selectable(struct imsharp_window* window, struct imsharp_frame* frame,
                                                   const char* label);

IMSHARP_API imsharp_boolean_int imsharp_begin_main_menu_bar(struct imsharp_window* window, struct imsharp_frame* frame);

IMSHARP_API void imsharp_end_main_menu_bar(struct imsharp_window* window, struct imsharp_frame* frame);

IMSHARP_API imsharp_boolean_int imsharp_begin_menu_bar(struct imsharp_window* window, struct imsharp_frame* frame);

IMSHARP_API void imsharp_end_menu_bar(struct imsharp_window* window, struct imsharp_frame* frame);

IMSHARP_API imsharp_boolean_int imsharp_begin_menu(struct imsharp_window* window, struct imsharp_frame* frame,
                                                   const char* label);

IMSHARP_API void imsharp_end_menu(struct imsharp_window* window, struct imsharp_frame* frame);

IMSHARP_API imsharp_boolean_int imsharp_menu_item(struct imsharp_window* window, struct imsharp_frame* frame,
                                                  const char* label);

IMSHARP_API void imsharp_show_style_editor(struct imsharp_window* window, struct imsharp_frame* frame);

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

IMSHARP_API void imsharp_set_background_color(struct imsharp_window* window, unsigned char r, unsigned char g,
                                              unsigned char b, unsigned char a);

#ifdef __cplusplus
}
#endif /* __cplusplus */
