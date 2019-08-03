cmake_minimum_required(VERSION 3.14)
project(Wolf3d C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} /Users/wstygg/Desktop/Vulkan/include)
link_directories(/Users/wstygg/Desktop/Vulkan/lib)

add_executable(Wolf3d Sources/main.c Includes/Wolf3d.h Includes/constants.h)
target_link_libraries(Wolf3d ${SDL2_LIBRARY} ${PROJECT_SOURCE_DIR} /Users/wstygg/Desktop/Vulkan/lib/libvulkan.1.dylib)