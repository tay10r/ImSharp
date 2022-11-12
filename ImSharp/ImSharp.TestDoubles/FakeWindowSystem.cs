using ImSharp.Core;

namespace ImSharp.TestDoubles
{
    public sealed class FakeWindowSystem : IWindowSystem
    {
        public IWindow CreateWindow()
        {
            return new FakeWindow();
        }

        public void Dispose() { }

        public void PollEvents()
        {

        }
    }
}