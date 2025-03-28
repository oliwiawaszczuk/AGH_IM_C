cmake_minimum_required(VERSION 3.10)
project(HelloDynamic C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(library1 SHARED src/function.c)
add_library(library2 SHARED src/integrate.c)

# dodanie katalogu w którym znajdują się pliki nagłówkowe - odpowiednio zmodyfikuj
target_include_directories(library1 PRIVATE src)
target_include_directories(library2 PRIVATE src)

add_executable(hello_app src/main.c)

target_link_libraries(hello_app library1 library2)
target_link_libraries(hello_app m)