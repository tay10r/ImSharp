cmake_minimum_required(VERSION 3.14.7)

set(header_list)

macro(pack_font name path)

  set(gendir "${CMAKE_CURRENT_BINARY_DIR}/${name}")

  list(APPEND header_list "${gendir}/font.h")

  file(MAKE_DIRECTORY "${gendir}")

  add_custom_command(OUTPUT "${gendir}/font.h"
    COMMAND $<TARGET_FILE:ImSharpPackFont> "${path}" "${name}" >"${gendir}/font.h"
    DEPENDS "${path}" ImSharpPackFont
    COMMENT "Packing font '${path}'")

endmacro(pack_font name c_path path)

pack_font("OpenSans_Bold"            "${CMAKE_CURRENT_SOURCE_DIR}/OpenSans/OpenSans-Bold.ttf")
pack_font("OpenSans_BoldItalic"      "${CMAKE_CURRENT_SOURCE_DIR}/OpenSans/OpenSans-BoldItalic.ttf")
pack_font("OpenSans_ExtraBold"       "${CMAKE_CURRENT_SOURCE_DIR}/OpenSans/OpenSans-ExtraBold.ttf")
pack_font("OpenSans_ExtraBoldItalic" "${CMAKE_CURRENT_SOURCE_DIR}/OpenSans/OpenSans-ExtraBoldItalic.ttf")
pack_font("OpenSans_Italic"          "${CMAKE_CURRENT_SOURCE_DIR}/OpenSans/OpenSans-Italic.ttf")
pack_font("OpenSans_Light"           "${CMAKE_CURRENT_SOURCE_DIR}/OpenSans/OpenSans-Light.ttf")
pack_font("OpenSans_LightItalic"     "${CMAKE_CURRENT_SOURCE_DIR}/OpenSans/OpenSans-LightItalic.ttf")
pack_font("OpenSans_Medium"          "${CMAKE_CURRENT_SOURCE_DIR}/OpenSans/OpenSans-Medium.ttf")
pack_font("OpenSans_MediumItalic"    "${CMAKE_CURRENT_SOURCE_DIR}/OpenSans/OpenSans-MediumItalic.ttf")
pack_font("OpenSans_Regular"         "${CMAKE_CURRENT_SOURCE_DIR}/OpenSans/OpenSans-Regular.ttf")
pack_font("OpenSans_SemiBold"        "${CMAKE_CURRENT_SOURCE_DIR}/OpenSans/OpenSans-SemiBold.ttf")
pack_font("OpenSans_SemiBoldItalic"  "${CMAKE_CURRENT_SOURCE_DIR}/OpenSans/OpenSans-SemiBoldItalic.ttf")


pack_font("JetBrainsMono_Bold"             "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-Bold.ttf")
pack_font("JetBrainsMono_BoldItalic"       "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-BoldItalic.ttf")
pack_font("JetBrainsMono_ExtraBold"        "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-ExtraBold.ttf")
pack_font("JetBrainsMono_ExtraBoldItalic"  "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-ExtraBoldItalic.ttf")
pack_font("JetBrainsMono_ExtraLight"       "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-ExtraLight.ttf")
pack_font("JetBrainsMono_ExtraLightItalic" "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-ExtraLightItalic.ttf")
pack_font("JetBrainsMono_Italic"           "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-Italic.ttf")
pack_font("JetBrainsMono_Light"            "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-Light.ttf")
pack_font("JetBrainsMono_LightItalic"      "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-LightItalic.ttf")
pack_font("JetBrainsMono_Medium"           "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-Medium.ttf")
pack_font("JetBrainsMono_MediumItalic"     "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-MediumItalic.ttf")
pack_font("JetBrainsMono_Regular"          "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-Regular.ttf")
pack_font("JetBrainsMono_SemiBold"         "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-SemiBold.ttf")
pack_font("JetBrainsMono_SemiBoldItalic"   "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-SemiBoldItalic.ttf")
pack_font("JetBrainsMono_Thin"             "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-Thin.ttf")
pack_font("JetBrainsMono_ThinItalic"       "${CMAKE_CURRENT_SOURCE_DIR}/JetBrainsMono/JetBrainsMonoNL-ThinItalic.ttf")

set(target ImSharpFonts)

add_library(${target} STATIC
  "all_fonts.hpp"
  "all_fonts.cpp"
  ${header_list})

target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
