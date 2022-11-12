# ImSharp

A C# library for creating applications with the following native libraries:

 - [Glfw](https://github.com/glfw/glfw)
 - [ImGui](https://github.com/ocornut/imgui)
 - [ImPlot](https://github.com/epezent/implot)
 - [ImNodes](https://github.com/Nelarius/imnodes)
 - [FreeType](https://freetype.org/)

While there is no shortage of graphical user interfaces in the .NET world, the ImGui-related libraries provide better control over realtime updates of the application content.
Most other frameworks require frame updates to be queued, which makes it difficult to be in sync with the monitors refresh rate.
