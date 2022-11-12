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
        /// Sets the X,Y coordinates of the next widget to be rendered.
        /// </summary>
        /// <param name="x">The X coordinate of the next widget, in pixels.</param>
        /// <param name="y">The Y coordinate of the next widget, in pixels.</param>
        void SetNextWidgetPosition(int x, int y);

        /// <summary>
        /// Sets the width and height of the next widget to be rendered.
        /// </summary>
        /// <param name="width">The width of the next widget, in pixels.</param>
        /// <param name="height">The height of the next widget, in pixels.</param>
        void SetNextWidgetSize(int width, int height);

        /// <summary>
        /// Begins rendering a top-level widget.
        /// </summary>
        /// <param name="name">The name of the widget.</param>
        void BeginWidget(string name);

        /// <summary>
        /// Completes the rendering of a top-level widget.
        /// </summary>
        void EndWidget();

        /// <summary>
        /// Causes the next component to be rendered on the same line as the last.
        /// </summary>
        void SameLine();

        /// <summary>
        /// Renders a horizontal line that acts as a separator between two components.
        /// </summary>
        void Separator();

        /// <summary>
        /// Renders a button that the user can click.
        /// </summary>
        /// <param name="label">The text to appear on the button.</param>
        /// <returns>True if the button was clicked, false otherwise.</returns>
        bool Button(string label);

        /// <summary>
        /// Renders a selectable component. Successive calls to this function will render several selectable components 
        /// </summary>
        /// <param name="label"></param>
        /// <returns></returns>
        bool Selectable(string label);

        /// <summary>
        /// Renders a checkbox.
        /// </summary>
        /// <param name="label">The text appearing next to the checkbox.</param>
        /// <param name="isChecked">Whether or not the checkbox is checked.</param>
        /// <returns>True if the state of the checkbox changed, false otherwise.</returns>
        bool Checkbox(string label, ref bool isChecked);

        /// <summary>
        /// Renders the style editor so that a user or designer can develop their own look and feel.
        /// </summary>
        void ShowStyleEditor();
    }
}