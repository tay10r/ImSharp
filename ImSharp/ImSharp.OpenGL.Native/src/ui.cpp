#include "imsharp/ui.h"

#include "texture.hpp"

#include <imgui.h>

void imsharp_image(struct imsharp_frame* frame, struct imsharp_texture* texture)
{
	int w = 0;
	int h = 0;
	imsharp_get_texture_size(texture, &w, &h);

	ImGui::Image(imsharp::get_texture_id(texture), ImVec2(w, h));
}

void imsharp_progress_bar(struct imsharp_frame* frame, const float progress_fraction)
{
	ImGui::ProgressBar(progress_fraction);
}

void imsharp_int_slider(struct imsharp_frame* frame,
                        const char* label,
                        int* x,
                        const int min,
                        const int max)
{
	ImGui::SliderInt(label, x, min, max);
}

void imsharp_float_slider(struct imsharp_frame* frame,
                          const char* label,
                          float* x,
                          const float min,
                          const float max)
{
	ImGui::SliderFloat(label, x, min, max);
}

void imsharp_color_edit_3(struct imsharp_frame* frame,
                          const char* label,
                          float* r,
                          float* g,
                          float* b)
{
	float color[3]{*r, *g, *b};

	ImGui::ColorEdit3(label, color);

	*r = color[0];
	*g = color[1];
	*b = color[2];
}

void imsharp_color_edit_4(struct imsharp_frame* frame,
                          const char* label,
                          float* r,
                          float* g,
                          float* b,
                          float* a)
{
	float color[4]{*r, *g, *b, *a};

	ImGui::ColorEdit4(label, color);

	*r = color[0];
	*g = color[1];
	*b = color[2];
	*a = color[3];
}

void imsharp_color_picker_3(struct imsharp_frame* frame,
                            const char* label,
                            float* r,
                            float* g,
                            float* b)
{
	float color[3]{*r, *g, *b};

	ImGui::ColorPicker3(label, color);

	*r = color[0];
	*g = color[1];
	*b = color[2];
}

void imsharp_color_picker_4(struct imsharp_frame* frame,
                            const char* label,
                            float* r,
                            float* g,
                            float* b,
                            float* a)
{
	float color[4]{*r, *g, *b, *a};

	ImGui::ColorPicker4(label, color);

	*r = color[0];
	*g = color[1];
	*b = color[2];
	*a = color[3];
}
