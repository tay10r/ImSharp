#include "imsharp_ui.h"

#include <imgui.h>

void imsharp_int_slider(struct imsharp_window* window, struct imsharp_frame* frame,
                        const char* label,
                        int* x,
                        const int min,
                        const int max)
{
	ImGui::SliderInt(label, x, min, max);
}

void imsharp_float_slider(struct imsharp_window* window, struct imsharp_frame* frame,
                          const char* label,
                          float* x,
                          const float min,
                          const float max)
{
	ImGui::SliderFloat(label, x, min, max);
}

void imsharp_color_edit_3(struct imsharp_window* window, struct imsharp_frame* frame,
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

void imsharp_color_edit_4(struct imsharp_window* window, struct imsharp_frame* frame,
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

void imsharp_color_picker_3(struct imsharp_window* window, struct imsharp_frame* frame,
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

void imsharp_color_picker_4(struct imsharp_window* window, struct imsharp_frame* frame,
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
