#include "imsharp.hpp"

#include <glad/glad.h>

#define GLFW_INCLUDE_NONE 1

#include <GLFW/glfw3.h>

#include <imgui.h>

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <algorithm>
#include <array>
#include <vector>

#include <cmrc/cmrc.hpp>

CMRC_DECLARE(ImSharpFonts);

namespace
{
	ImVec4 color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0xff)
	{
		return ImVec4(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
	}

	std::array<int, 3> g_color_id_table = {
		{

			{ImGuiCol_WindowBg},
			{ImGuiCol_TitleBg},
			{ImGuiCol_Text}
		}
	};

	std::array<const char*, 3> g_color_name_table = {
		{
			{"Window Background"},
			{"Title Background"},
			{"Text"}
		}
	};

	void setup_geometry_style()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 4);

		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1);

		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 2);
	}

	void setup_light_style()
	{
		ImGui::PushStyleColor(ImGuiCol_WindowBg, color(0xf2, 0xf2, 0xf2));

		ImGui::PushStyleColor(ImGuiCol_TitleBg, color(0xda, 0xda, 0xda));

		ImGui::PushStyleColor(ImGuiCol_TitleBgActive, color(0xda, 0xda, 0xff));

		ImGui::PushStyleColor(ImGuiCol_Text, color(0, 0, 0));

		ImGui::PushStyleColor(ImGuiCol_Button, color(0xfd, 0xfd, 0xfd));
	}
} // namespace

int imsharp_global_init()
{
	return glfwInit() == GLFW_TRUE;
}

void imsharp_global_cleanup()
{
	glfwTerminate();
}

void imsharp_poll_events()
{
	glfwPollEvents();
}

struct imsharp_window final
{
	GLFWwindow* window{nullptr};

	ImGuiContext* imgui_context{nullptr};

	ImVec4 background_color = color(0xf0, 0xf0, 0xf0);

	float font_size = 16.0f;
};

struct imsharp_frame final
{
	ImVec2 window_size;

	ImVec2 framebuffer_size;

	imsharp_frame(imsharp_window* window)
	{
		int w = 0;
		int h = 0;

		glfwGetWindowSize(window->window, &w, &h);
		window_size.x = w;
		window_size.y = h;

		glfwGetFramebufferSize(window->window, &w, &h);
		framebuffer_size.x = w;
		framebuffer_size.y = h;
	}
};

namespace
{
	ImFont* load_font(imsharp_window* window, const char* path)
	{
		const auto fs = cmrc::ImSharpFonts::get_filesystem();

		const auto file = fs.open(path);

		const auto size = file.size();

		auto* data = static_cast<unsigned char*>(std::malloc(size));

		const auto* src_data = static_cast<const char*>(file.begin());

		std::copy_n(src_data, size, data);

		return ImGui::GetIO().Fonts->AddFontFromMemoryTTF(data, static_cast<int>(size), window->font_size);
	}

	void load_fonts(imsharp_window* window)
	{
		load_font(window, "fonts/JetBrainsMono/JetBrainsMonoNL-Bold.ttf");
		load_font(window, "fonts/JetBrainsMono/JetBrainsMonoNL-Light.ttf");
		load_font(window, "fonts/JetBrainsMono/JetBrainsMonoNL-Medium.ttf");
		load_font(window, "fonts/JetBrainsMono/JetBrainsMonoNL-Regular.ttf");
		load_font(window, "fonts/JetBrainsMono/JetBrainsMonoNL-Thin.ttf");

		load_font(window, "fonts/OpenSans/OpenSans-Bold.ttf");
		load_font(window, "fonts/OpenSans/OpenSans-Italic.ttf");
		load_font(window, "fonts/OpenSans/OpenSans-Light.ttf");
		load_font(window, "fonts/OpenSans/OpenSans-Medium.ttf");
		load_font(window, "fonts/OpenSans/OpenSans-Regular.ttf");

		ImGui::GetIO().Fonts->Build();
	}
} // namespace

imsharp_window* imsharp_create_window()
{
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	GLFWwindow* window = glfwCreateWindow(640, 480, "", nullptr, nullptr);
	if (!window)
		return nullptr;

	glfwMakeContextCurrent(window);

	gladLoadGLES2Loader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

	glEnable(GL_DEPTH);

	glfwSwapInterval(1);

	IMGUI_CHECKVERSION();

	auto* imgui_context = ImGui::CreateContext();

	ImGui_ImplGlfw_InitForOpenGL(window, true);

	ImGui_ImplOpenGL3_Init("#version 300 es");

	setup_geometry_style();

	setup_light_style();

	auto* api_window = new imsharp_window{window, imgui_context};

	load_fonts(api_window);

	return api_window;
}

void imsharp_destroy_window(imsharp_window* window)
{
	glfwMakeContextCurrent(window->window);

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window->window);

	delete window;
}

int imsharp_window_should_close(imsharp_window* window)
{
	return glfwWindowShouldClose(window->window);
}

void imsharp_set_window_should_close(imsharp_window* window, int should_close)
{
	glfwSetWindowShouldClose(window->window, should_close);
}

void imsharp_show_window(imsharp_window* window)
{
	glfwShowWindow(window->window);
}

void imsharp_hide_window(imsharp_window* window)
{
	glfwHideWindow(window->window);
}

imsharp_frame* imsharp_begin_frame(imsharp_window* window)
{
	glfwMakeContextCurrent(window->window);

	ImGui::SetCurrentContext(window->imgui_context);

	ImGui_ImplOpenGL3_NewFrame();

	ImGui_ImplGlfw_NewFrame();

	ImGui::NewFrame();

	auto* frame = new imsharp_frame(window);

	glViewport(0, 0, frame->framebuffer_size.x, frame->framebuffer_size.y);

	glClearColor(window->background_color.x, window->background_color.y, window->background_color.z,
	             window->background_color.w);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	return frame;
}

void imsharp_end_frame(imsharp_window* window, imsharp_frame* frame)
{
	ImGui::Render();

	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glfwSwapBuffers(window->window);

	delete frame;
}

int imsharp_window_width(struct imsharp_window* window, struct imsharp_frame* frame)
{
	return frame->window_size.x;
}

int imsharp_window_height(struct imsharp_window* window, struct imsharp_frame* frame)
{
	return frame->window_size.y;
}

int imsharp_framebuffer_width(struct imsharp_window* window, struct imsharp_frame* frame)
{
	return frame->framebuffer_size.x;
}

int imsharp_framebuffer_height(struct imsharp_window* window, struct imsharp_frame* frame)
{
	return frame->framebuffer_size.y;
}

void imsharp_set_next_widget_position(struct imsharp_window* window, struct imsharp_frame* frame, int x, int y)
{
	ImGui::SetNextWindowPos(ImVec2(x, y));
}

void imsharp_set_next_widget_size(struct imsharp_window* window, struct imsharp_frame* frame, int w, int h)
{
	ImGui::SetNextWindowSize(ImVec2(w, h));
}

void imsharp_same_line(struct imsharp_window* window, struct imsharp_frame* frame)
{
	ImGui::SameLine();
}

void imsharp_separator(struct imsharp_window* window, struct imsharp_frame* frame)
{
	ImGui::Separator();
}

void imsharp_begin_widget(imsharp_window* context, imsharp_frame* frame, const char* title)
{
	ImGui::Begin(title);
}

void imsharp_end_widget(imsharp_window* context, imsharp_frame* frame)
{
	ImGui::End();
}

void imsharp_show_style_editor(imsharp_window* window, imsharp_frame* frame)
{
	ImGui::ShowStyleEditor();
}

int imsharp_button(imsharp_window* window, imsharp_frame* frame, const char* label)
{
	return ImGui::Button(label) ? 1 : 0;
}

int imsharp_checkbox(struct imsharp_window* window, struct imsharp_frame* frame, const char* label,
                     imsharp_boolean_int* checked)
{
	bool boolean_checked = *checked ? true : false;

	const auto changed = ImGui::Checkbox(label, &boolean_checked);

	*checked = boolean_checked ? 1 : 0;

	return changed ? 1 : 0;
}

int imsharp_selectable(struct imsharp_window* window, struct imsharp_frame* frame, const char* label)
{
	return ImGui::Selectable(label);
}

int imsharp_begin_main_menu_bar(struct imsharp_window* window, struct imsharp_frame* frame)
{
	return ImGui::BeginMainMenuBar();
}

void imsharp_end_main_menu_bar(struct imsharp_window* window, struct imsharp_frame* frame)
{
	ImGui::EndMainMenuBar();
}

int imsharp_begin_menu_bar(struct imsharp_window* window, struct imsharp_frame* frame)
{
	return ImGui::BeginMenuBar();
}

void imsharp_end_menu_bar(struct imsharp_window* window, struct imsharp_frame* frame)
{
	ImGui::EndMenuBar();
}

int imsharp_begin_menu(struct imsharp_window* window, struct imsharp_frame* frame, const char* label)
{
	return ImGui::BeginMenu(label);
}

void imsharp_end_menu(struct imsharp_window* window, struct imsharp_frame* frame)
{
	ImGui::EndMenu();
}

int imsharp_menu_item(struct imsharp_window* window, struct imsharp_frame* frame, const char* label)
{
	return ImGui::MenuItem(label);
}

const int* imsharp_get_style_color_ids()
{
	return g_color_id_table.data();
}

int imsharp_get_style_color_count()
{
	return g_color_id_table.size();
}

const char* imsharp_get_style_color_name(int id)
{
	for (auto i = 0; i < g_color_id_table.size(); i++)
	{
		if (g_color_id_table[i] == id)
			return g_color_name_table[i];
	}

	return "<unknown-color>";
}

void imsharp_push_style_color(imsharp_window* window,
                              imsharp_frame* frame,
                              int color_id,
                              unsigned char r,
                              unsigned char g,
                              unsigned char b,
                              unsigned char a)
{
	ImGui::PushStyleColor(color_id, color(r, g, b, a));
}

void imsharp_pop_style_color(imsharp_window* window, imsharp_frame* frame)
{
	ImGui::PopStyleColor();
}

void imsharp_set_background_color(imsharp_window* window, unsigned char r, unsigned char g, unsigned char b,
                                  unsigned char a)
{
	window->background_color.x = r / 255.0f;
	window->background_color.y = g / 255.0f;
	window->background_color.z = b / 255.0f;
	window->background_color.w = a / 255.0f;
}
