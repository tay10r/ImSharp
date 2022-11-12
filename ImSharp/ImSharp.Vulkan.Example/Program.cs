using ImSharp.Vulkan;
using System.IO;

public sealed class Program
{
    public static void Main(string[] args)
    {
        // Note: This is only required for testing and developing the library.
        //       When the library is consumed as a NuGet, all DLLs reside in the same location.
        var dllPath = Directory.GetCurrentDirectory();
        dllPath = Path.Combine(dllPath, "..");
        dllPath = Path.Combine(dllPath, "..");
        dllPath = Path.Combine(dllPath, "..");
        dllPath = Path.Combine(dllPath, "..");
        dllPath = Path.Combine(dllPath, "ImSharp.Vulkan.Native");
        dllPath = Path.Combine(dllPath, "install");
        dllPath = Path.Combine(dllPath, "bin");
        Environment.SetEnvironmentVariable("PATH", Environment.GetEnvironmentVariable("PATH") + ";" + dllPath);
        // ^^ End of boilerplate for local development.

        using var windowSystem = new WindowSystem();

        using var window = windowSystem.CreateWindow();

        window.Show();

        while (!window.ShouldClose)
        {
            windowSystem.PollEvents();

            window.SwapBuffers();
        }
    }
}