using ImSharp.Core;
using ImSharp.Vulkan.Impl;
using System.Runtime.InteropServices;

namespace ImSharp.Vulkan
{
    public sealed class WindowSystem : IWindowSystem
    {
        public WindowSystem()
        {
            if (glfwInit() == 0)
            {
                throw new WindowCreationException("Failed to initialize GLFW.");
            }

            glfwWindowHint(VisibleHint, 0);

            glfwWindowHint(MaximizedHint, 1);

            glfwWindowHint(ClientApiHint, NoApiHintValue);
        }

        public void Dispose()
        {
            glfwTerminate();
        }

        public IWindow CreateWindow()
        {
            return new Window();
        }

        public void PollEvents()
        {
            glfwPollEvents();
        }

        [DllImport("glfw3")]
        internal static extern int glfwInit();

        [DllImport("glfw3")]
        internal static extern void glfwTerminate();

        [DllImport("glfw3")]
        internal static extern void glfwPollEvents();

        [DllImport("glfw3")]
        internal static extern void glfwSwapBuffers(IntPtr windowPointer);

        [DllImport("glfw3")]
        internal static extern IntPtr glfwCreateWindow(int width, int height, string title, IntPtr monitor, IntPtr share);

        [DllImport("glfw3")]
        internal static extern IntPtr glfwDestroyWindow(IntPtr windowPointer);

        [DllImport("glfw3")]
        internal static extern int glfwWindowShouldClose(IntPtr windowPointer);

        [DllImport("glfw3")]
        internal static extern void glfwSetWindowShouldClose(IntPtr windowPointer, int shouldClose);

        [DllImport("glfw3")]
        internal static extern void glfwShowWindow(IntPtr windowPointer);

        [DllImport("glfw3")]
        internal static extern void glfwHideWindow(IntPtr windowPointer);

        [DllImport("glfw3")]
        internal static extern void glfwWindowHint(int hint, int value);

        /// <summary>
        /// Used to indicate that the window should be visible when created.
        /// </summary>
        internal const int VisibleHint = 0x00020004;

        /// <summary>
        /// Used to indicate that the window should be maximized when created.
        /// </summary>
        internal const int MaximizedHint = 0x00020008;

        /// <summary>
        /// Used to indicate what client API should be used when creating the window.
        /// </summary>
        internal const int ClientApiHint = 0x00022001;

        /// <summary>
        /// A value for the client API hint to indicate that no API should be used. This is used when Vulkan is the backend.
        /// </summary>
        internal const int NoApiHintValue = 0;
    }
}