cmake_minimum_required(VERSION 3.23)

project(nb_c23 LANGUAGES C)

add_library(c23
            src/stddef.c
            src/stdlib.c)
target_include_directories(c23 PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(c23 PUBLIC -Wall -Wextra)
