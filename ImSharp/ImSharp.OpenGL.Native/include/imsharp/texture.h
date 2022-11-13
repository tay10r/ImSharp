#pragma once

#include "imsharp/common.h"

#ifdef __cplusplus
extern "C" {
#endif

IMSHARP_API struct imsharp_texture* imsharp_create_texture(struct imsharp_window* window);

IMSHARP_API void imsharp_destroy_texture(struct imsharp_texture* texture);

IMSHARP_API void imsharp_get_texture_size(struct imsharp_texture* texture, int* w, int* h);

IMSHARP_API void imsharp_resize_texture(struct imsharp_texture* texture, int w, int h);

IMSHARP_API void imsharp_sync_texture(struct imsharp_texture* texture);

IMSHARP_API void imsharp_set_texture_color(struct imsharp_texture* texture, int x, int y, float r, float g, float b,
                                           float a);

#ifdef __cplusplus
} /* extern "C" */
#endif // __cplusplus
