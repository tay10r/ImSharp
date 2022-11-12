using ImSharp.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ImSharp.Vulkan.Impl
{
    internal class Window : IWindow
    {
        IntPtr _windowPointer;

        public Window()
        {
            _windowPointer = WindowSystem.glfwCreateWindow(640, 480, "", IntPtr.Zero, IntPtr.Zero);
            if (_windowPointer == IntPtr.Zero)
            {
                throw new WindowCreationException("Failed to create GLFW window.");
            }
        }

        public void Dispose()
        {
            if (_windowPointer != IntPtr.Zero)
            {
                WindowSystem.glfwDestroyWindow(_windowPointer);
                _windowPointer = IntPtr.Zero;
            }
        }

        public void SwapBuffers()
        {
            WindowSystem.glfwSwapBuffers(_windowPointer);
        }

        public void Show()
        {
            WindowSystem.glfwShowWindow(_windowPointer);
        }

        public void Hide()
        {
            WindowSystem.glfwHideWindow(_windowPointer);
        }

        public bool ShouldClose { get { return WindowSystem.glfwWindowShouldClose(_windowPointer) != 0; } set { WindowSystem.glfwSetWindowShouldClose(_windowPointer, 1); } }
    }
}
