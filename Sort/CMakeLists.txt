cmake_minimum_required(VERSION 3.10)
project(Sorting)

set(CMAKE_C_STANDARD 99)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(sort_library STATIC 
    src/bubble_sort.c 
   src/insertion_sort.c
    src/quick_sort.c
    src/merge_sort.c
)

add_executable(sort_app src/main.c)

target_link_libraries(sort_app PRIVATE sort_library)
