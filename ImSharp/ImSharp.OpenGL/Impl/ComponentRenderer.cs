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
        private IntPtr _context;

        private IntPtr _frame;

        public ComponentRenderer(IntPtr context, IntPtr frame)
        {
            _context = context;
            _frame = frame;
        }

        public void BeginWidget(string title)
        {
            imsharp_begin_widget(_context, _frame, title);
        }

        public void EndWidget() {
            imsharp_end_widget(_context, _frame);
        }

        [DllImport("ImSharpNative")]
        private static extern void imsharp_begin_widget(IntPtr context, IntPtr frame, string title);

        [DllImport("ImSharpNative")]
        private static extern void imsharp_end_widget(IntPtr context, IntPtr frame);
    }
}
