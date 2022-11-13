#include "all_fonts.hpp"

#include "JetBrainsMono_Bold/font.h"
#include "JetBrainsMono_BoldItalic/font.h"
#include "JetBrainsMono_ExtraBold/font.h"
#include "JetBrainsMono_ExtraBoldItalic/font.h"
#include "JetBrainsMono_ExtraLight/font.h"
#include "JetBrainsMono_ExtraLightItalic/font.h"
#include "JetBrainsMono_Italic/font.h"
#include "JetBrainsMono_Light/font.h"
#include "JetBrainsMono_LightItalic/font.h"
#include "JetBrainsMono_Medium/font.h"
#include "JetBrainsMono_MediumItalic/font.h"
#include "JetBrainsMono_Regular/font.h"
#include "JetBrainsMono_SemiBold/font.h"
#include "JetBrainsMono_SemiBoldItalic/font.h"
#include "JetBrainsMono_Thin/font.h"
#include "JetBrainsMono_ThinItalic/font.h"

#include "OpenSans_Bold/font.h"
#include "OpenSans_BoldItalic/font.h"
#include "OpenSans_ExtraBold/font.h"
#include "OpenSans_ExtraBoldItalic/font.h"
#include "OpenSans_Italic/font.h"
#include "OpenSans_Light/font.h"
#include "OpenSans_LightItalic/font.h"
#include "OpenSans_Medium/font.h"
#include "OpenSans_MediumItalic/font.h"
#include "OpenSans_Regular/font.h"
#include "OpenSans_SemiBold/font.h"
#include "OpenSans_SemiBoldItalic/font.h"

namespace imsharp
{
	const font_entry all_fonts[] = {
		{
			"JetBrains Mono Bold",
			JetBrainsMono_Bold_compressed_data,
			JetBrainsMono_Bold_compressed_size
		},
		{
			"JetBrains Mono Bold Italic",
			JetBrainsMono_BoldItalic_compressed_data,
			JetBrainsMono_BoldItalic_compressed_size
		},
		{
			"JetBrains Mono Extra Bold",
			JetBrainsMono_ExtraBold_compressed_data,
			JetBrainsMono_ExtraBold_compressed_size
		},
		{
			"JetBrains Mono Extra Bold Italic",
			JetBrainsMono_ExtraBoldItalic_compressed_data,
			JetBrainsMono_ExtraBoldItalic_compressed_size
		},
		{
			"JetBrains Mono Extra Light",
			JetBrainsMono_ExtraLight_compressed_data,
			JetBrainsMono_ExtraLight_compressed_size
		},
		{
			"JetBrains Mono Extra Light Italic",
			JetBrainsMono_ExtraLightItalic_compressed_data,
			JetBrainsMono_ExtraLightItalic_compressed_size
		},
		{
			"JetBrains Mono Italic",
			JetBrainsMono_Italic_compressed_data,
			JetBrainsMono_Italic_compressed_size
		},
		{
			"JetBrains Mono Light",
			JetBrainsMono_Light_compressed_data,
			JetBrainsMono_Light_compressed_size
		},
		{
			"JetBrains Mono Light Italic",
			JetBrainsMono_LightItalic_compressed_data,
			JetBrainsMono_LightItalic_compressed_size
		},
		{
			"JetBrains Mono Medium",
			JetBrainsMono_Medium_compressed_data,
			JetBrainsMono_Medium_compressed_size
		},
		{
			"JetBrains Mono Medium Italic",
			JetBrainsMono_MediumItalic_compressed_data,
			JetBrainsMono_MediumItalic_compressed_size
		},
		{
			"JetBrains Mono Regular",
			JetBrainsMono_Regular_compressed_data,
			JetBrainsMono_Regular_compressed_size
		},
		{
			"JetBrains Mono Semi Bold",
			JetBrainsMono_SemiBold_compressed_data,
			JetBrainsMono_SemiBold_compressed_size
		},
		{
			"JetBrains Mono Semi Bold Italic",
			JetBrainsMono_SemiBoldItalic_compressed_data,
			JetBrainsMono_SemiBoldItalic_compressed_size
		},
		{
			"JetBrains Mono Thin",
			JetBrainsMono_Thin_compressed_data,
			JetBrainsMono_Thin_compressed_size
		},
		{
			"JetBrains Mono Thin Italic",
			JetBrainsMono_ThinItalic_compressed_data,
			JetBrainsMono_ThinItalic_compressed_size
		},
		{
			"OpenSans Bold",
			OpenSans_Bold_compressed_data,
			OpenSans_Bold_compressed_size
		},
		{
			"OpenSans Bold Italic",
			OpenSans_BoldItalic_compressed_data,
			OpenSans_BoldItalic_compressed_size,
		},
		{
			"OpenSans Extra Bold",
			OpenSans_ExtraBold_compressed_data,
			OpenSans_ExtraBold_compressed_size,
		},
		{
			"OpenSans Extra Bold Italic",
			OpenSans_ExtraBoldItalic_compressed_data,
			OpenSans_ExtraBoldItalic_compressed_size,
		},
		{
			"OpenSans Italic",
			OpenSans_Italic_compressed_data,
			OpenSans_Italic_compressed_size,
		},
		{
			"OpenSans Light",
			OpenSans_Light_compressed_data,
			OpenSans_Light_compressed_size,
		},
		{
			"OpenSans Light Italic",
			OpenSans_LightItalic_compressed_data,
			OpenSans_LightItalic_compressed_size,
		},
		{
			"OpenSans Medium",
			OpenSans_Medium_compressed_data,
			OpenSans_Medium_compressed_size,
		},
		{
			"OpenSans Medium Italic",
			OpenSans_MediumItalic_compressed_data,
			OpenSans_MediumItalic_compressed_size,
		},
		{
			"OpenSans Regular",
			OpenSans_Regular_compressed_data,
			OpenSans_Regular_compressed_size,
		},
		{
			"OpenSans Semi Bold",
			OpenSans_SemiBold_compressed_data,
			OpenSans_SemiBold_compressed_size,
		},
		{
			"OpenSans Semi Bold Italic",
			OpenSans_SemiBoldItalic_compressed_data,
			OpenSans_SemiBoldItalic_compressed_size,
		},
	};

	const unsigned int all_fonts_count = sizeof(all_fonts) / sizeof(all_fonts[0]);
} // namespace imsharp
