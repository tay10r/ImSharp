#include "imsharp.h"

int main()
{
	imsharp_global_init();

	auto* app = imsharp_create_app();

	auto* window = imsharp_create_window(app);

	imsharp_show_window(window);

	auto* texture = imsharp_create_texture(window);

	const int w = 640;
	const int h = 480;
	imsharp_resize_texture(texture, w, h);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			const float r = (x / static_cast<float>(w));
			const float g = (y / static_cast<float>(h));
			const float b = 1 - (r * g);
			const float a = 1;
			imsharp_set_texture_color(texture, x, y, r, g, b, a);
		}
	}

	imsharp_sync_texture(texture);

	while (!imsharp_window_should_close(window))
	{
		imsharp_poll_events();

		auto* frame = imsharp_begin_frame(window);

		imsharp_begin_widget(frame, "Test Widget");

		imsharp_image(frame, texture);

		imsharp_end_widget(frame);

		imsharp_end_frame(frame);
	}

	imsharp_destroy_texture(texture);

	imsharp_destroy_window(window);

	imsharp_global_cleanup();

	return 0;
}
