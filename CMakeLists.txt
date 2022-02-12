cmake_minimum_required(VERSION 3.16.3)

project(SortAnimation VERSION 1.0)

add_compile_options(
        -Wall
        -Wextra
        -Werror
        -Wpedantic

        -g
        -Og
        #  -fsanitize=address
)

add_link_options(
        #  -fsanitize=address
)

add_subdirectory(gui/)

set(APP_SOURCE src/app.cpp
               src/main.cpp

               src/sort_animator.cpp
               src/anim_sort_elem.cpp
               src/sorting_system.cpp
               src/render_anim_sort_functor.cpp)

add_executable(SortAnimation ${APP_SOURCE})

target_include_directories(SortAnimation PUBLIC include/ glib/include)
target_link_libraries(SortAnimation PUBLIC gui)
