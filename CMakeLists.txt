cmake_minimum_required(VERSION 3.30)

project(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(classes)
add_subdirectory(SDL2-Utilites)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(main main.cpp)
add_executable(Input_Display main.cpp images/icon/icon.rc)

target_link_libraries(main
    lib_classes
    lib_SDL2
)

target_link_libraries(main
    "-l mingw32"
)

target_link_libraries(Input_Display
    lib_classes
    lib_SDL2
)

target_link_libraries(Input_Display
    "-l mingw32"
    "-mwindows"
    "-static-libgcc"
    "-static-libstdc++"
)
