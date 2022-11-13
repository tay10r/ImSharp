#pragma once

namespace imsharp
{
	struct font_entry final
	{
		const char* name{""};

		const unsigned int* data{nullptr};

		const unsigned int size{0};
	};

	extern const font_entry all_fonts[];

	extern const unsigned int all_fonts_count;
} // namespace imsharp
