#include "imsharp.hpp"

#include <glad/glad.h>

#define GLFW_INCLUDE_NONE 1

#include <GLFW/glfw3.h>

#include <imgui.h>

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <array>
#include <vector>

namespace {

ImVec4 color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0xff)
{
    return ImVec4(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
}

std::array<int, 3> g_color_id_table = { {

    { ImGuiCol_WindowBg },
    { ImGuiCol_TitleBg },
    { ImGuiCol_Text }
} };

std::array<const char *, 3> g_color_name_table = { {
    { "Window Background" },
    { "Title Background" },
    { "Text" }
} };

void setup_geometry_style()
{
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 4);
}

void setup_light_style()
{
    ImGui::PushStyleColor(ImGuiCol_WindowBg, color(0xff, 0xff, 0xff));

    ImGui::PushStyleColor(ImGuiCol_TitleBg, color(0xda, 0xda, 0xda));

    ImGui::PushStyleColor(ImGuiCol_Text, color(0, 0, 0));
}

} // namespace

int imsharp_global_init()
{
    return glfwInit() == GLFW_TRUE;
}

void imsharp_global_cleanup()
{
    glfwTerminate();
}

void imsharp_poll_events()
{
    glfwPollEvents();
}

struct imsharp_window final
{
    GLFWwindow* window = nullptr;

    float background_color[4]{ 0, 0, 0, 1 };
};

struct imsharp_frame final
{
    ImVec2 window_size;

    ImVec2 framebuffer_size;

    imsharp_frame(imsharp_window* window) {

        int w = 0;
        int h = 0;

        glfwGetWindowSize(window->window, &w, &h);
        window_size.x = w;
        window_size.y = h;

        glfwGetFramebufferSize(window->window, &w, &h);
        framebuffer_size.x = w;
        framebuffer_size.y = h;
    }
};

imsharp_window* imsharp_create_window()
{
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(640, 480, "", nullptr, nullptr);
    if (!window)
        return nullptr;

    glfwMakeContextCurrent(window);

    gladLoadGLES2Loader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

    glClearColor(0xf0 / 255.0, 0xf0 / 255.0, 0xf0 / 255.0, 1);

    glEnable(GL_DEPTH);

    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    ImGui_ImplGlfw_InitForOpenGL(window, true);

    ImGui_ImplOpenGL3_Init("#version 300 es");

    setup_geometry_style();

    setup_light_style();

    return new imsharp_window{ window };
}

void imsharp_destroy_window(imsharp_window* window)
{
    glfwMakeContextCurrent(window->window);

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window->window);

    delete window;
}

int imsharp_window_should_close(imsharp_window* window)
{
    return glfwWindowShouldClose(window->window);
}

void imsharp_set_window_should_close(imsharp_window* window, int should_close)
{
    glfwSetWindowShouldClose(window->window, should_close);
}

imsharp_frame* imsharp_begin_frame(imsharp_window* window)
{
    glfwMakeContextCurrent(window->window);

    ImGui_ImplOpenGL3_NewFrame();

    ImGui_ImplGlfw_NewFrame();

    ImGui::NewFrame();

    ImGui::ShowStyleEditor();

    auto* frame = new imsharp_frame(window);

    glViewport(0, 0, frame->framebuffer_size.x, frame->framebuffer_size.y);

    glClearColor(window->background_color[0], window->background_color[1], window->background_color[2], window->background_color[3]);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    return frame;
}

void imsharp_end_frame(imsharp_window* window, imsharp_frame* frame)
{
    ImGui::Render();

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    delete frame;
}

void imsharp_begin_widget(imsharp_window* context, imsharp_frame* frame, const char* title)
{
    ImGui::Begin(title);
}

void imsharp_end_widget(imsharp_window* context, imsharp_frame* frame)
{
    ImGui::End();
}

const int* imsharp_get_color_ids()
{
    return g_color_id_table.data();
}

int imsharp_get_color_count()
{
    return g_color_id_table.size();
}

const char* imsharp_get_color_name(int id)
{
    for (auto i = 0; i < g_color_id_table.size(); i++) {
        if (g_color_id_table[i] == id)
            return g_color_name_table[i];
    }

    return "<unknown-color>";
}

void imsharp_push_style_color(imsharp_window* window,
    imsharp_frame* frame,
    int color_id,
    unsigned char r,
    unsigned char g,
    unsigned char b,
    unsigned char a)
{
    ImGui::PushStyleColor(color_id, color(r, g, b, a));
}

void imsharp_pop_style_color(imsharp_window* window, imsharp_frame* frame)
{
    ImGui::PopStyleColor();
}

void imsharp_set_background_color(imsharp_window* window, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    window->background_color[0] = r / 255.0f;
    window->background_color[1] = g / 255.0f;
    window->background_color[2] = b / 255.0f;
    window->background_color[3] = a / 255.0f;
}
