namespace ImSharp.Core
{
    /// <summary>
    /// The interface for a window.
    /// </summary>
    public interface IWindow : IDisposable
    {

        /// <summary>
        /// Indicates whether or not the window should close.
        /// The window should close if the user hits the window close button.
        /// </summary>
        bool ShouldClose { get; set; }

        /// <summary>
        /// Performs a buffer swap, updating the contents of the window.
        /// </summary>
        void SwapBuffers();

        /// <summary>
        /// Makes the window visible to the user. When a window is created for the first time, it is hidden.
        /// </summary>
        void Show();

        /// <summary>
        /// Makes the window invisible to the user. When a window is created for the first time, it is hidden.
        /// </summary>
        void Hide();
    }
}