cmake_minimum_required(VERSION 3.14)
project(Wolf3d)

set(CMAKE_C_STANDARD 99)

set(sdl_includes
        ../SDL2/include/
        )
set(vulkan_includes
        ../Vulkan/include
        )
link_directories(
        ../SDL2/lib/
        ../Vulkan/lib/
)
add_executable(Wolf3d main.c)