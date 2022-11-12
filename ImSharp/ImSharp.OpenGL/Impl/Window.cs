using ImSharp.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ImSharp.OpenGL.Impl
{
    internal class Window : IWindow
    {
        IntPtr _windowPointer;

        IntPtr _context;

        IntPtr _frame;

        public Window()
        {
            _windowPointer = WindowSystem.glfwCreateWindow(640, 480, "", IntPtr.Zero, IntPtr.Zero);
            if (_windowPointer == IntPtr.Zero)
            {
                throw new WindowCreationException("Failed to create GLFW window.");
            }

            _context = WindowSystem.imsharp_setup(_windowPointer);
            if (_context == IntPtr.Zero)
            {
                throw new WindowCreationException("Failed to create ImSharp context.");
            }
        }

        public void Dispose()
        {
            if (_context!= IntPtr.Zero)
            {
                WindowSystem.imsharp_cleanup(_context);
                _context = IntPtr.Zero;
            }

            if (_windowPointer != IntPtr.Zero)
            {
                WindowSystem.glfwDestroyWindow(_windowPointer);
                _windowPointer = IntPtr.Zero;
            }
        }

        public IComponentRenderer BeginFrame()
        {
            _frame = WindowSystem.imsharp_begin_frame(_context);

            return new ComponentRenderer(_context, _frame);
        }

        public void EndFrame()
        {
            WindowSystem.imsharp_end_frame(_context, _frame);

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
