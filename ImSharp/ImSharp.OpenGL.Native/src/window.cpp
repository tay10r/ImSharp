#include "imsharp_window.h"

#include "imsharp_frame.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <imgui.h>

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <implot.h>

#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <memory>

#include <cstring>

#include "all_fonts.hpp"
#include "style.hpp"

namespace
{
	class window_impl;

	struct font_set final
	{
		ImFont* large_heading{nullptr};

		ImFont* medium_heading{nullptr};

		ImFont* small_heading{nullptr};

		ImFont* regular_text{nullptr};

		ImFont* italic_text{nullptr};

		ImFont* bold_text{nullptr};

		ImFont* default_code{nullptr};
	};

	class frame_impl final
	{
	public:
		static frame_impl* cast(imsharp_frame* frame)
		{
			return reinterpret_cast<frame_impl*>(frame);
		}

		static const frame_impl* cast(const imsharp_frame* frame)
		{
			return reinterpret_cast<const frame_impl*>(frame);
		}

		explicit frame_impl(window_impl* window, GLFWwindow* g_window)
			: window_(window)
		{
			glfwGetWindowSize(g_window, &window_w_, &window_h_);

			glfwGetFramebufferSize(g_window, &frame_buffer_w_, &frame_buffer_h_);
		}

		imsharp_window* get_window() const { return reinterpret_cast<imsharp_window*>(window_); }

		int get_window_width() const { return window_w_; }

		int get_window_height() const { return window_h_; }

		int get_frame_buffer_width() const { return frame_buffer_w_; }

		int get_frame_buffer_height() const { return frame_buffer_h_; }

	private:
		window_impl* window_;

		int window_w_ = 0;
		int window_h_ = 0;

		int frame_buffer_w_ = 0;
		int frame_buffer_h_ = 0;
	};

	class window_impl final
	{
	public:
		static window_impl* cast(imsharp_window* window)
		{
			return reinterpret_cast<window_impl*>(window);
		}

		explicit window_impl(imsharp_app* app)
			: app_(app)
		{
			glfwMakeContextCurrent(window_);

			glfwSwapInterval(1);

			gladLoadGLES2Loader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

			glEnable(GL_DEPTH);

			IMGUI_CHECKVERSION();

			gui_context_ = ImGui::CreateContext();

			ImGui_ImplGlfw_InitForOpenGL(window_, true);

			ImGui_ImplOpenGL3_Init("#version 300 es");

			plot_context_ = ImPlot::CreateContext();

			style_ = imsharp::style::get_from_context();

			load_fonts(1.0);
		}

		void make_context_current() const
		{
			glfwMakeContextCurrent(window_);
		}

		imsharp_app* get_app() const { return app_; }

		bool created() const { return window_ != nullptr; }

		bool should_close() const { return glfwWindowShouldClose(window_); }

		void set_should_close(const bool should_close) const
		{
			glfwSetWindowShouldClose(window_, should_close ? GLFW_TRUE : GLFW_FALSE);
		}

		void show() const { glfwShowWindow(window_); }

		void hide() const { glfwHideWindow(window_); }

		frame_impl* begin_frame()
		{
			glfwMakeContextCurrent(window_);

			ImGui::SetCurrentContext(gui_context_);

			ImPlot::SetCurrentContext(plot_context_);

			frame_ = frame_impl(this, window_);

			ImGui_ImplOpenGL3_NewFrame();

			ImGui_ImplGlfw_NewFrame();

			ImGui::NewFrame();

			glViewport(0, 0, frame_.get_frame_buffer_width(), frame_.get_frame_buffer_height());

			glClearColor(0, 0, 0, 1);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			ImGui::PushFont(font_set_.regular_text);

			return &frame_;
		}

		void end_frame(frame_impl* /* frame */) const
		{
			ImGui::PopFont();

			ImGui::Render();

			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(window_);
		}

		const imsharp::style* get_style() const { return &style_; }

		imsharp::style* get_style() { return &style_; }
	private:
		void load_fonts(const float font_scale)
		{
			ImGui::GetIO().Fonts->Clear();

			font_set_.regular_text = load_font("OpenSans Regular", font_scale * 18);
			font_set_.italic_text = load_font("OpenSans Italic", font_scale * 18);
			font_set_.bold_text = load_font("OpenSans Bold", font_scale * 18);

			font_set_.small_heading = load_font("OpenSans Semi Bold", font_scale * 20);
			font_set_.medium_heading = load_font("OpenSans Semi Bold", font_scale * 24);
			font_set_.large_heading = load_font("OpenSans Semi Bold", font_scale * 32);

			font_set_.default_code = load_font("JetBrainsMono Regular", font_scale * 18);

			ImGui::GetIO().Fonts->Build();
		}

		static ImFont* load_font(const char* name, const float size)
		{
			for (auto i = 0u; i < imsharp::all_fonts_count; i++)
			{
				if (std::strcmp(imsharp::all_fonts[i].name, name) != 0)
					continue;

				const auto* compressed_data = imsharp::all_fonts[i].data;

				const auto compressed_size = imsharp::all_fonts[i].size;

				auto* font = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(
					compressed_data, static_cast<int>(compressed_size),

					size);

				return font;
			}

			return nullptr;
		}

	private:
		imsharp_app* app_{nullptr};

		GLFWwindow* window_{glfwCreateWindow(640, 480, "", nullptr, nullptr)};

		ImGuiContext* gui_context_{nullptr};

		ImPlotContext* plot_context_{nullptr};

		frame_impl frame_{this, window_};

		font_set font_set_;

		imsharp::style style_;
	};
} // namespace

imsharp_window* imsharp_create_window(imsharp_app* app)
{
	return reinterpret_cast<imsharp_window*>(new window_impl(app));
}

void imsharp_destroy_window(imsharp_window* window)
{
	delete window_impl::cast(window);
}

imsharp_app* imsharp_get_window_app(imsharp_window* window)
{
	return window_impl::cast(window)->get_app();
}

void imsharp_make_window_context_current(imsharp_window* window)
{
	window_impl::cast(window)->make_context_current();
}

imsharp_boolean_int imsharp_window_created(imsharp_window* window)
{
	return window_impl::cast(window)->created() ? IMSHARP_TRUE : IMSHARP_FALSE;
}

imsharp_boolean_int imsharp_window_should_close(imsharp_window* window)
{
	return window_impl::cast(window)->should_close() ? IMSHARP_TRUE : IMSHARP_FALSE;
}

void imsharp_set_window_should_close(imsharp_window* window, imsharp_boolean_int should_close)
{
	return window_impl::cast(window)->set_should_close(should_close == IMSHARP_TRUE ? true : false);
}

void imsharp_show_window(imsharp_window* window)
{
	window_impl::cast(window)->show();
}

void imsharp_hide_window(imsharp_window* window)
{
	window_impl::cast(window)->hide();
}

imsharp_frame* imsharp_begin_frame(imsharp_window* window)
{
	return reinterpret_cast<imsharp_frame*>(window_impl::cast(window)->begin_frame());
}

void imsharp_end_frame(imsharp_frame* frame)
{
	auto* derived_frame = frame_impl::cast(frame);

	window_impl::cast(derived_frame->get_window())->end_frame(derived_frame);
}

imsharp_window* imsharp_get_frame_window(imsharp_frame* frame)
{
	return frame_impl::cast(frame)->get_window();
}

int imsharp_window_width(const imsharp_frame* frame)
{
	return frame_impl::cast(frame)->get_window_width();
}

int imsharp_window_height(const imsharp_frame* frame)
{
	return frame_impl::cast(frame)->get_window_height();
}

int imsharp_frame_buffer_width(const imsharp_frame* frame)
{
	return frame_impl::cast(frame)->get_frame_buffer_width();
}

int imsharp_frame_buffer_height(const imsharp_frame* frame)
{
	return frame_impl::cast(frame)->get_frame_buffer_height();
}

namespace imsharp
{
	style* style::get_from_window(imsharp_window* window)
	{
		return window_impl::cast(window)->get_style();
	}
} // namespace imsharp
