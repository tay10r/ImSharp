using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ImSharp.Core
{
    /// <summary>
    /// Used for managing windows created by the application.
    /// </summary>
    public interface IWindowSystem : IDisposable
    {
        /// <summary>
        /// Creates a new window.
        /// </summary>
        /// <returns>A new window.</returns>
        IWindow CreateWindow();

        /// <summary>
        /// Checks for user input events, such as mouse clicks, keyboard presses, etc.
        /// </summary>
        void PollEvents();
    }
}
