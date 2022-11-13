#include "imsharp_app.h"

#include <vector>
#include <map>
#include <string>
#include <iterator>

namespace
{
	struct blob final
	{
		std::vector<uint8_t> data;

		bool dirty{true};
	};
} // namespace

struct imsharp_app final
{
	std::map<std::string, blob> nv_blob_map;

	bool nv_blob_map_dirty{false};
};

namespace
{
}

imsharp_app* imsharp_create_app()
{
	return new imsharp_app();
}

void imsharp_destroy_app(const imsharp_app* app)
{
	delete app;
}

uint32_t imsharp_get_nv_blob_count(const imsharp_app* app)
{
	return static_cast<uint32_t>(app->nv_blob_map.size());
}

const char* imsharp_get_nv_blob_key(const imsharp_app* app, uint32_t index)
{
	for (const auto& entry : app->nv_blob_map)
	{
		if (index == 0)
			return entry.first.c_str();

		--index;
	}

	return "";
}

void imsharp_store_nv_blob(imsharp_app* app, const char* key, const uint8_t* data, uint32_t size)
{
	app->nv_blob_map.emplace(key, blob{std::vector<uint8_t>(data, data + size)});

	app->nv_blob_map_dirty = true;
}

const uint8_t* imsharp_load_nv_blob(imsharp_app* app, const char* key, uint32_t* size)
{
	const auto it = app->nv_blob_map.find(key);

	if (it == app->nv_blob_map.end())
	{
		*size = 0;
		return nullptr;
	}

	*size = static_cast<uint32_t>(it->second.data.size());

	return it->second.data.data();
}

imsharp_boolean_int imsharp_nv_storage_dirty(const struct imsharp_app* app)
{
	return app->nv_blob_map_dirty ? IMSHARP_TRUE : IMSHARP_FALSE;
}

imsharp_boolean_int imsharp_nv_blob_dirty(const struct imsharp_app* app, uint32_t blob_index)
{
	for (const auto& entry : app->nv_blob_map)
	{
		if (blob_index == 0)
			return entry.second.dirty ? IMSHARP_TRUE : IMSHARP_FALSE;

		--blob_index;
	}

	return IMSHARP_FALSE;
}

void imsharp_reset_nv_storage_dirty_flags(struct imsharp_app* app)
{
	app->nv_blob_map_dirty = false;

	for (auto& entry : app->nv_blob_map)
		entry.second.dirty = false;
}
