#include "imsharp_ui.h"

#include "style.hpp"

#include <imgui.h>

#include <string>
#include <vector>

namespace
{
	class style_editor final
	{
	public:
		style_editor(imsharp_window* window, imsharp_frame* frame)
			: window_(window), frame_(frame)
		{
		}

		void render() const
		{
			auto* s = imsharp::style::get_from_window(window_);

			if (ImGui::BeginTabBar("Style Editor Tabs"))
			{
				if (ImGui::BeginTabItem("Colors"))
				{
					for (auto i = 0; i < ImGuiCol_COUNT; i++)
					{
						const auto* name = ImGui::GetStyleColorName(i);

						ImGui::ColorEdit4(name, s->colors[i].rgba);
					}

					ImGui::EndTabItem();
				}

				/* TODO
				if (ImGui::BeginTabItem("Geometry"))
				{
					ImGui::EndTabItem();
				}
				 */

				ImGui::EndTabBar();
			}

			s->apply_to_context();
		}

	private:
		imsharp_window* window_{nullptr};

		imsharp_frame* frame_{nullptr};
	};
} // namespace

void imsharp_show_style_editor(imsharp_window* window, imsharp_frame* frame)
{
	const style_editor editor(window, frame);

	editor.render();
}
