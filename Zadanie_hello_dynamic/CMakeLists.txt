cmake_minimum_required(VERSION 3.10)
project(HelloDynamic C)

set(CMAKE_C_STANDARD 99)

# biblioteka dynamiczną (shared)
add_library(hello_library SHARED src/hello.c)

# plik wykonywalny
add_executable(hello_app src/main.c)

# linkowana aplikacja z biblioteką dynamiczną
target_link_libraries(hello_app hello_library)

