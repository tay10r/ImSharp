using ImSharp.Core;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ImSharp.OpenGL.Impl
{
    internal sealed class ComponentRenderer : IComponentRenderer
    {
        private IntPtr _window;

        private IntPtr _frame;

        public ComponentRenderer(IntPtr window, IntPtr frame)
        {
            _window = window;
            _frame = frame;
        }

        public void SetNextWidgetPosition(int x, int y)
        {
            imsharp_set_next_widget_position(_window, _frame, x, y);
        }

        public void SetNextWidgetSize(int w, int h)
        {
            imsharp_set_next_widget_size(_window, _frame, w, h);
        }

        public void BeginWidget(string title)
        {
            imsharp_begin_widget(_window, _frame, title);
        }

        public void EndWidget()
        {
            imsharp_end_widget(_window, _frame);
        }

        public void SameLine()
        {
            imsharp_same_line(_window, _frame);
        }

        public void Separator()
        {
            imsharp_separator(_window, _frame);
        }

        public bool Button(string label)
        {
            return imsharp_button(_window, _frame, label) != 0;
        }

        public bool Selectable(string label)
        {
            return imsharp_selectable(_window, _frame, label) != 0;
        }

        public bool Checkbox(string label, ref bool isChecked)
        {
            var isCheckedInt = isChecked ? 1 : 0;

            var changed = imsharp_checkbox(_window, _frame, label, ref isCheckedInt);

            isChecked = isCheckedInt != 0;

            return changed != 0;
        }

        public void ShowStyleEditor()
        {
            imsharp_show_style_editor(_window, _frame);
        }

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        private static extern void imsharp_begin_widget(IntPtr context, IntPtr frame, string title);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        private static extern void imsharp_end_widget(IntPtr context, IntPtr frame);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        private static extern int imsharp_set_next_widget_position(IntPtr windowPointer, IntPtr framePointer, int x,
            int y);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        private static extern int imsharp_set_next_widget_size(IntPtr windowPointer, IntPtr framePointer, int w, int h);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        private static extern int imsharp_button(IntPtr windowPointer, IntPtr framePointer, string label);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        private static extern int imsharp_selectable(IntPtr windowPointer, IntPtr framePointer, string label);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        private static extern int imsharp_checkbox(IntPtr windowPointer, IntPtr framePointer, string label,
            ref int isChecked);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        private static extern void imsharp_show_style_editor(IntPtr windowPointer, IntPtr framePointer);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        private static extern void imsharp_same_line(IntPtr windowPointer, IntPtr framePointer);

        [DllImport("ImSharpNative", CallingConvention = CallingConvention.Cdecl)]
        private static extern void imsharp_separator(IntPtr windowPointer, IntPtr framePointer);
    }
}