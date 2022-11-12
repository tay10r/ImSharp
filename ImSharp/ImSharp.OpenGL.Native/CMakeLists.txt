cmake_minimum_required(VERSION 3.14.7)

project(ImSharpNative)

option(IMSHARP_NATIVE_EXAMPLE "Whether or not to build the example program." OFF)

include(FetchContent)

set(BUILD_SHARED_LIBS   OFF  CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL        OFF CACHE BOOL "" FORCE)
set(GLFW_VULKAN_STATIC  OFF CACHE BOOL "" FORCE)

FetchContent_Declare(glfw URL "https://github.com/glfw/glfw/archive/refs/tags/3.3.8.zip")
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(imgui URL "https://github.com/ocornut/imgui/archive/refs/tags/v1.88.zip")
FetchContent_MakeAvailable(imgui)
FetchContent_GetProperties(imgui)

include(CMakeRC.cmake)

cmrc_add_resource_library(ImSharpFonts
  fonts/JetBrainsMono/JetBrainsMonoNL-Bold.ttf
  fonts/JetBrainsMono/JetBrainsMonoNL-Light.ttf
  fonts/JetBrainsMono/JetBrainsMonoNL-Medium.ttf
  fonts/JetBrainsMono/JetBrainsMonoNL-Regular.ttf
  fonts/JetBrainsMono/JetBrainsMonoNL-Thin.ttf
  fonts/OpenSans/OpenSans-Bold.ttf
  fonts/OpenSans/OpenSans-Italic.ttf
  fonts/OpenSans/OpenSans-Light.ttf
  fonts/OpenSans/OpenSans-Medium.ttf
  fonts/OpenSans/OpenSans-Regular.ttf
)

find_package(OpenGL REQUIRED)

add_library(ImSharpNative SHARED
  imsharp.hpp
  imsharp.cpp
  glad/include/glad/glad.h
  glad/include/KHR/khrplatform.h
  glad/src/glad.c
  ${imgui_SOURCE_DIR}/imconfig.h
  ${imgui_SOURCE_DIR}/imgui.h
  ${imgui_SOURCE_DIR}/imgui.cpp
  ${imgui_SOURCE_DIR}/imgui_demo.cpp
  ${imgui_SOURCE_DIR}/imgui_draw.cpp
  ${imgui_SOURCE_DIR}/imgui_internal.h
  ${imgui_SOURCE_DIR}/imgui_tables.cpp
  ${imgui_SOURCE_DIR}/imgui_widgets.cpp
  ${imgui_SOURCE_DIR}/imstb_rectpack.h
  ${imgui_SOURCE_DIR}/imstb_textedit.h
  ${imgui_SOURCE_DIR}/imstb_truetype.h
  ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.h
  ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.h
  ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
  )

target_compile_definitions(ImSharpNative PRIVATE GLFW_INCLUDE_NONE=1)

target_include_directories(ImSharpNative
  PUBLIC
    ${imgui_SOURCE_DIR}
  PRIVATE
    ${imgui_SOURCE_DIR}/backends
    glad/include)

target_link_libraries(ImSharpNative PUBLIC glfw ImSharpFonts)

install(TARGETS ImSharpNative RUNTIME DESTINATION "bin")

if(IMSHARP_NATIVE_EXAMPLE)

  add_executable(ImSharpNativeExample imsharp_example.cpp)

  target_link_libraries(ImSharpNativeExample PRIVATE ImSharpNative)

endif(IMSHARP_NATIVE_EXAMPLE)
