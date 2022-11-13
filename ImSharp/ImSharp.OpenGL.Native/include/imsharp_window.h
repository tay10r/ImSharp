#pragma once

#include "imsharp_common.h"

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
