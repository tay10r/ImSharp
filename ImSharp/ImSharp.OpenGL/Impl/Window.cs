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
        IntPtr _window;

        IntPtr _frame;

        public Window()
        {
            _window = WindowSystem.imsharp_create_window();
            if (_window == IntPtr.Zero)
            {
                throw new WindowCreationException("Failed to create GLFW window.");
            }
        }

        public void Dispose()
        {
            if (_window != IntPtr.Zero)
            {
                WindowSystem.imsharp_destroy_window(_window);
                _window = IntPtr.Zero;
            }
        }

        public IComponentRenderer BeginFrame()
        {
            _frame = WindowSystem.imsharp_begin_frame(_window);

            return new ComponentRenderer(_window, _frame);
        }

        public void EndFrame()
        {
            WindowSystem.imsharp_end_frame(_window, _frame);
        }

        public void Show()
        {
            WindowSystem.imsharp_show_window(_window);
        }

        public void Hide()
        {
            WindowSystem.imsharp_hide_window(_window);
        }

        public bool ShouldClose { get { return WindowSystem.imsharp_window_should_close(_window) != 0; } set { WindowSystem.imsharp_set_window_should_close(_window, 1); } }
    }
}
