using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ImSharp.Core
{

    /// <summary>
    /// Used for rendering user interface components.
    /// </summary>
    public interface IComponentRenderer
    {
        /// <summary>
        /// Begins rendering a top-level widget.
        /// </summary>
        /// <param name="name">The name of the widget.</param>
        void BeginWidget(string name);

        /// <summary>
        /// Completes the rendering of a top-level widget.
        /// </summary>
        void EndWidget();
    }
}
