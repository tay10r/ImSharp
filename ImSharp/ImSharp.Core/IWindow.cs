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
        /// Begins rendering a new frame.
        /// </summary>
        /// <returns>
        /// Used to render the UI components of the frame.
        /// </returns>
        IComponentRenderer BeginFrame();

        /// <summary>
        /// Completes the frame and performs a buffer swap, which updates the contents of the window.
        /// </summary>
        void EndFrame();

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