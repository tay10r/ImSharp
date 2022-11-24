#pragma once

#include "imsharp/window.h"

#include <imgui.h>

namespace imsharp
{
	struct style final
	{
		struct color final
		{
			float rgba[4]{};
		};

		color colors[ImGuiCol_COUNT];

		float alpha = {1};

		float disabled_alpha{0.5f};

		float window_padding[2]{1, 1};

		float window_rounding{1};

		float window_border_size{1};

		float window_title_align[2]{0.5f, 0.5f};

		float child_rounding{1};

		float child_border_size{1};

		float popup_rounding{1};

		float popup_border_size{1};

		float frame_padding[2]{1, 1};

		float frame_rounding{1};

		float frame_border_size{1};

		float item_spacing[2]{1, 1};

		float item_inner_spacing[2]{1, 1};

		float indent_spacing{1};

		float cell_padding[2]{1, 1};

		float scroll_bar_size{1};

		float scroll_bar_rounding{1};

		float tab_rounding{1};

		float tab_border_size{1};

		static style get_from_context()
		{
			const auto& input_style = ImGui::GetStyle();

			style s;

			for (auto i = 0; i < ImGuiCol_COUNT; i++)
			{
				const auto c = input_style.Colors[i];
				s.colors[i].rgba[0] = c.x;
				s.colors[i].rgba[1] = c.y;
				s.colors[i].rgba[2] = c.z;
				s.colors[i].rgba[3] = c.w;
			}

			s.alpha = input_style.Alpha;
			s.disabled_alpha = input_style.Alpha;

			s.window_padding[0] = input_style.WindowPadding[0];
			s.window_padding[1] = input_style.WindowPadding[1];
			s.window_rounding = input_style.WindowRounding;
			s.window_border_size = input_style.WindowBorderSize;
			s.window_title_align[0] = input_style.WindowTitleAlign[0];
			s.window_title_align[1] = input_style.WindowTitleAlign[1];

			s.child_rounding = input_style.ChildRounding;
			s.child_border_size = input_style.ChildBorderSize;

			s.popup_rounding = input_style.PopupRounding;
			s.popup_border_size = input_style.PopupBorderSize;

			s.frame_padding[0] = input_style.FramePadding[0];
			s.frame_padding[1] = input_style.FramePadding[1];
			s.frame_rounding = input_style.FrameRounding;
			s.frame_border_size = input_style.FrameBorderSize;

			s.item_spacing[0] = input_style.ItemSpacing[0];
			s.item_spacing[1] = input_style.ItemSpacing[1];
			s.item_inner_spacing[0] = input_style.ItemInnerSpacing[0];
			s.item_inner_spacing[1] = input_style.ItemInnerSpacing[1];

			s.indent_spacing = input_style.IndentSpacing;

			s.cell_padding[0] = input_style.CellPadding[0];
			s.cell_padding[1] = input_style.CellPadding[1];

			s.scroll_bar_size = input_style.ScrollbarSize;
			s.scroll_bar_rounding = input_style.ScrollbarRounding;

			s.tab_rounding = input_style.TabRounding;
			s.tab_border_size = input_style.TabBorderSize;

			return s;
		}

		void apply_to_context() const
		{
			auto& out = ImGui::GetStyle();

			for (auto i = 0u; i < ImGuiCol_COUNT; i++)
			{
				out.Colors[i].x = colors[i].rgba[0];
				out.Colors[i].y = colors[i].rgba[1];
				out.Colors[i].z = colors[i].rgba[2];
				out.Colors[i].w = colors[i].rgba[3];
			}
		}

		static style* get_from_window(imsharp_window* window);
	};
} // namespace imsharp
