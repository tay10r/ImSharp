#pragma once

#include "imsharp_common.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** Called when a new top-level widget is being rendered.
 *
 * @param window The window object creating by the initialization of this library.
 *
 * @param frame The frame to draw the widget on.
 * 
 * @param title The name of give the widget.
 */
IMSHARP_API void imsharp_begin_widget(struct imsharp_frame* frame, const char* title);

/** Called to complete a top-level widget.
 *
 * @param window The window object creating by the initialization of this library.
 *
 * @param frame The frame to draw the widget on.
 */
IMSHARP_API void imsharp_end_widget(struct imsharp_frame* frame);

IMSHARP_API void imsharp_set_next_widget_position(struct imsharp_frame* frame, int x, int y);

IMSHARP_API void imsharp_set_next_widget_size(struct imsharp_frame* frame, int w, int h);

IMSHARP_API void imsharp_same_line(struct imsharp_frame* frame);

IMSHARP_API void imsharp_separator(struct imsharp_frame* frame);

IMSHARP_API void imsharp_image(struct imsharp_frame* frame, struct imsharp_texture* texture);

/** Renders a progress bar.
 *
 * @param frame The frame to render the progress bar in.
 *
 * @param progress_fraction The ratio, between 0 and 1 inclusive, of how complete the progress is.
 */
IMSHARP_API void imsharp_progress_bar(struct imsharp_frame* frame, float progress_fraction);

IMSHARP_API void imsharp_int_slider(struct imsharp_frame* frame,
                                    const char* label,
                                    int* x,
                                    int min,
                                    int max);

IMSHARP_API void imsharp_float_slider(struct imsharp_frame* frame,
                                      const char* label,
                                      float* x,
                                      float min,
                                      float max);

IMSHARP_API void imsharp_color_edit_3(struct imsharp_frame* frame,
                                      const char* label,
                                      float* r,
                                      float* g,
                                      float* b);

IMSHARP_API void imsharp_color_edit_4(struct imsharp_frame* frame,
                                      const char* label,
                                      float* r,
                                      float* g,
                                      float* b,
                                      float* a);

IMSHARP_API void imsharp_color_picker_3(struct imsharp_frame* frame,
                                        const char* label,
                                        float* r,
                                        float* g,
                                        float* b);

IMSHARP_API void imsharp_color_picker_4(struct imsharp_frame* frame,
                                        const char* label,
                                        float* r,
                                        float* g,
                                        float* b,
                                        float* a);

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
IMSHARP_API imsharp_boolean_int imsharp_button(struct imsharp_frame* frame, const char* label);

IMSHARP_API imsharp_boolean_int imsharp_checkbox(struct imsharp_frame* frame, const char* label,
                                                 imsharp_boolean_int* checked);

IMSHARP_API imsharp_boolean_int imsharp_selectable(struct imsharp_frame* frame, const char* label);

IMSHARP_API imsharp_boolean_int imsharp_begin_main_menu_bar(struct imsharp_frame* frame);

IMSHARP_API void imsharp_end_main_menu_bar(struct imsharp_frame* frame);

IMSHARP_API imsharp_boolean_int imsharp_begin_menu_bar(struct imsharp_frame* frame);

IMSHARP_API void imsharp_end_menu_bar(struct imsharp_frame* frame);

IMSHARP_API imsharp_boolean_int imsharp_begin_menu(struct imsharp_frame* frame, const char* label);

IMSHARP_API void imsharp_end_menu(struct imsharp_frame* frame);

IMSHARP_API imsharp_boolean_int imsharp_menu_item(struct imsharp_frame* frame, const char* label);

IMSHARP_API void imsharp_show_style_editor(struct imsharp_frame* frame);

IMSHARP_API const int* imsharp_get_style_color_ids(void);

IMSHARP_API int imsharp_get_style_color_count(void);

IMSHARP_API const char* imsharp_get_style_color_name(int id);

IMSHARP_API void imsharp_push_style_color(struct imsharp_frame* frame, int color_id,
                                          unsigned char r,
                                          unsigned char g,
                                          unsigned char b,
                                          unsigned char a);

IMSHARP_API void imsharp_pop_style_color(struct imsharp_frame* frame);

#ifdef __cplusplus
}
#endif /* __cplusplus */
