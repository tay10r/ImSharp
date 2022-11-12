# About

This contains a `CMakeLists.txt` to build all the native dependencies for this project.

In order to build it, `CMake` must be installed (version >= `3.14.7`).

Once installed, navigate (through a command line) to the directory `ImSharp.Vulkan.Native`.

Run the following commands:

```
mkdir build
mkdir install
cd build
cmake ..
cmake --build . --config Release
cmake --install . --prefix ../install
```

Once complete, the required DLLs will be in `ImSharp.Vulkan.Native/install`.