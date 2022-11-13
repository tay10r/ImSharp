#include "imsharp.h"

int main()
{
	imsharp_global_init();

	auto* window = imsharp_create_window();

	imsharp_show_window(window);

	while (!imsharp_window_should_close(window))
	{
		imsharp_poll_events();

		auto* frame = imsharp_begin_frame(window);

		imsharp_begin_widget(window, frame, "Test Widget");

		imsharp_button(window, frame, "Click me!");

		imsharp_end_widget(window, frame);

		imsharp_end_frame(window, frame);
	}

	imsharp_destroy_window(window);

	imsharp_global_cleanup();

	return 0;
}
