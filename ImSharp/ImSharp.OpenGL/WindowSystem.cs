using ImSharp.Core;
using ImSharp.OpenGL.Impl;
using System.Runtime.InteropServices;

namespace ImSharp.OpenGL
{
    public sealed class WindowSystem : IWindowSystem
    {
        public WindowSystem()
        {
            if (imsharp_global_init() == 0)
            {
                throw new WindowCreationException("Failed to initialize global data.");
            }
        }

        public void Dispose()
        {
            imsharp_global_cleanup();
        }

        public IWindow CreateWindow()
        {
            return new Window();
        }

        public void PollEvents()
        {
            imsharp_poll_events();
        }

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int imsharp_global_init();

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void imsharp_global_cleanup();

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void imsharp_poll_events();

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr imsharp_create_window();

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr imsharp_destroy_window(IntPtr windowPointer);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        internal static extern IntPtr imsharp_begin_frame(IntPtr windowPointer);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void imsharp_end_frame(IntPtr windowPointer, IntPtr framePointer);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int imsharp_window_should_close(IntPtr windowPointer);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void imsharp_set_window_should_close(IntPtr windowPointer, int shouldClose);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void imsharp_show_window(IntPtr windowPointer);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        internal static extern void imsharp_hide_window(IntPtr windowPointer);
    }
}
