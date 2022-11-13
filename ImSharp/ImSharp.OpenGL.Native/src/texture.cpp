#include "texture.hpp"

#include "imsharp/texture.h"

#include "window.hpp"

#include <glad/glad.h>

#include <vector>

namespace
{
	class texture_impl final
	{
	public:
		static texture_impl* cast(imsharp_texture* self)
		{
			return reinterpret_cast<texture_impl*>(self);
		}

		explicit texture_impl(imsharp_window* window)
			: window_(window)
		{
			glGenTextures(1, &texture_);

			glBindTexture(GL_TEXTURE_2D, texture_);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		}

		texture_impl() = delete;

		texture_impl(const texture_impl&) = delete;

		texture_impl(texture_impl&&) = delete;

		texture_impl& operator =(const texture_impl&) = delete;

		texture_impl& operator =(texture_impl&&) = delete;

		~texture_impl()
		{
			glDeleteTextures(1, &texture_);
		}

		ImTextureID get_texture_id() const { return reinterpret_cast<ImTextureID>(texture_); }

		void get_size(int* w, int* h) const
		{
			*w = width_;
			*h = height_;
		}

		void resize(const int w, const int h)
		{
			color_buffer_.resize(w * h * 4);
			width_ = w;
			height_ = h;
			glBindTexture(GL_TEXTURE_2D, texture_);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, w, h, 0, GL_RGBA, GL_FLOAT, nullptr);
		}

		void sync() const
		{
			imsharp_make_window_context_current(window_);

			glBindTexture(GL_TEXTURE_2D, texture_);

			glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width_, height_, GL_RGBA, GL_FLOAT, &color_buffer_[0]);
		}

		void set_color(const int x, const int y, const float r, const float g, const float b, const float a)
		{
			color_buffer_[(y * width_ + x) * 4 + 0] = r;
			color_buffer_[(y * width_ + x) * 4 + 1] = g;
			color_buffer_[(y * width_ + x) * 4 + 2] = b;
			color_buffer_[(y * width_ + x) * 4 + 3] = a;
		}

	private:
		imsharp_window* window_{nullptr};

		GLuint texture_{0};

		std::vector<float> color_buffer_;

		int width_{0};

		int height_{0};
	};
} // namespace

imsharp_texture* imsharp_create_texture(imsharp_window* window)
{
	return reinterpret_cast<imsharp_texture*>(new texture_impl(window));
}

void imsharp_destroy_texture(imsharp_texture* texture)
{
	delete texture_impl::cast(texture);
}

void imsharp_get_texture_size(struct imsharp_texture* texture, int* w, int* h)
{
	texture_impl::cast(texture)->get_size(w, h);
}

void imsharp_resize_texture(imsharp_texture* texture, const int w, const int h)
{
	texture_impl::cast(texture)->resize(w, h);
}

void imsharp_sync_texture(imsharp_texture* texture)
{
	texture_impl::cast(texture)->sync();
}

void imsharp_set_texture_color(imsharp_texture* texture, const int x, const int y, const float r, const float g,
                               const float b, const float a)
{
	texture_impl::cast(texture)->set_color(x, y, r, g, b, a);
}

namespace imsharp
{
	ImTextureID get_texture_id(imsharp_texture* texture)
	{
		return texture_impl::cast(texture)->get_texture_id();
	}
} // namespace imsharp
