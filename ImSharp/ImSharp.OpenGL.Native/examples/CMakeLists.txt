cmake_minimum_required(VERSION 3.14.7)

function(add_imsharp_example name)

  set(target ImSharpNativeExample_${name})

  add_executable(${target}
    ${ARGN})

  target_link_libraries(${target} PRIVATE ImSharpNative)

  set_target_properties(${target}
    PROPERTIES
      OUTPUT_NAME ${name}
      RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

endfunction(add_imsharp_example name)

add_imsharp_example(minimal minimal.cpp)

add_imsharp_example(style_editor style_editor.cpp)
