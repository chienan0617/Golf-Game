cmake_minimum_required(VERSION 3.16)
project(MySDL3App LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# 遞迴收集 src/ 下所有 .cpp
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(main ${SOURCES})

target_include_directories(main PRIVATE
    D:/Jimmy/sdl3/x86_64-w64-mingw32/include
)

target_link_directories(main PRIVATE
    D:/Jimmy/sdl3/x86_64-w64-mingw32/lib
)

target_link_libraries(main SDL3)
