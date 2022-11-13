#include "imsharp.h"

int main()
{
	imsharp_global_init();

	auto* app = imsharp_create_app();

	auto* window = imsharp_create_window(app);

	imsharp_show_window(window);

	while (!imsharp_window_should_close(window))
	{
		imsharp_poll_events();

		auto* frame = imsharp_begin_frame(window);

		imsharp_begin_widget(frame, "Style Editor");

		imsharp_show_style_editor(frame);

		imsharp_end_widget(frame);

		imsharp_end_frame(frame);
	}

	imsharp_destroy_window(window);

	imsharp_global_cleanup();

	return 0;
}
