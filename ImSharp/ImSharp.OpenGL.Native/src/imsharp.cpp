#include "imsharp.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <imgui.h>

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <implot.h>

#include <algorithm>
#include <array>
#include <vector>

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

void imsharp_set_next_widget_position(struct imsharp_frame* frame, int x, int y)
{
	ImGui::SetNextWindowPos(ImVec2(x, y));
}

void imsharp_set_next_widget_size(struct imsharp_frame* frame, int w, int h)
{
	ImGui::SetNextWindowSize(ImVec2(w, h));
}

void imsharp_same_line(struct imsharp_frame* frame)
{
	ImGui::SameLine();
}

void imsharp_separator(struct imsharp_frame* frame)
{
	ImGui::Separator();
}

void imsharp_begin_widget(imsharp_frame* frame, const char* title)
{
	ImGui::Begin(title);
}

void imsharp_end_widget(imsharp_frame* frame)
{
	ImGui::End();
}

int imsharp_button(imsharp_frame* frame, const char* label)
{
	return ImGui::Button(label) ? 1 : 0;
}

int imsharp_checkbox(imsharp_frame* frame, const char* label,
                     imsharp_boolean_int* checked)
{
	bool boolean_checked = *checked ? true : false;

	const auto changed = ImGui::Checkbox(label, &boolean_checked);

	*checked = boolean_checked ? 1 : 0;

	return changed ? 1 : 0;
}

int imsharp_selectable(imsharp_frame* frame, const char* label)
{
	return ImGui::Selectable(label);
}

int imsharp_begin_main_menu_bar(imsharp_frame* frame)
{
	return ImGui::BeginMainMenuBar();
}

void imsharp_end_main_menu_bar(imsharp_frame* frame)
{
	ImGui::EndMainMenuBar();
}

int imsharp_begin_menu_bar(imsharp_frame* frame)
{
	return ImGui::BeginMenuBar();
}

void imsharp_end_menu_bar(struct imsharp_frame* frame)
{
	ImGui::EndMenuBar();
}

int imsharp_begin_menu(imsharp_frame* frame, const char* label)
{
	return ImGui::BeginMenu(label);
}

void imsharp_end_menu(imsharp_frame* frame)
{
	ImGui::EndMenu();
}

int imsharp_menu_item(imsharp_frame* frame, const char* label)
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

/*******************
 * ImPlot Bindings *
 *******************/

imsharp_boolean_int imsharp_begin_plot(struct imsharp_frame* frame, const char* label)
{
	return ImPlot::BeginPlot(label);
}

void imsharp_end_plot(struct imsharp_frame* frame)
{
	ImPlot::EndPlot();
}
