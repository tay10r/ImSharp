/** @file app.h
 *
 * @brief Contains the declarations for the application object.
 */
#pragma once

#include "imsharp/common.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

IMSHARP_API struct imsharp_app* imsharp_create_app(void);

IMSHARP_API void imsharp_destroy_app(const struct imsharp_app* app);

IMSHARP_API uint32_t imsharp_get_nv_blob_count(const struct imsharp_app* app);

IMSHARP_API const char* imsharp_get_nv_blob_key(struct imsharp_app* app, uint32_t index);

IMSHARP_API void imsharp_store_nv_blob(struct imsharp_app* app, const char* key, const uint8_t* data, uint32_t size);

IMSHARP_API const uint8_t* imsharp_load_nv_blob(const struct imsharp_app* app, const char* key, uint32_t* size);

IMSHARP_API imsharp_boolean_int imsharp_nv_storage_dirty(const struct imsharp_app* app);

IMSHARP_API imsharp_boolean_int imsharp_nv_blob_dirty(const struct imsharp_app* app, uint32_t blob_index);

IMSHARP_API void imsharp_reset_nv_storage_dirty_flags(struct imsharp_app* app);

#ifdef __cplusplus
}
#endif
