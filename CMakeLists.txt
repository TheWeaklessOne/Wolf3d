cmake_minimum_required(VERSION 3.16)
project(Wolf3d C)

set(CMAKE_C_STANDARD 99)

include_directories(Includes)

add_executable(Wolf3d Sources/main.c Includes/wolf.h Includes/list.h Sources/Utils/list.c Sources/Utils/list_2.c Sources/Utils/ft.c Sources/sdl_init.c Sources/sdl.c Sources/keys.c)


target_link_libraries(Wolf3d m SDL2 SDL2_image)