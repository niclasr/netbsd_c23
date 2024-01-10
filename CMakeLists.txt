cmake_minimum_required(VERSION 3.23)

project(nb_c23 LANGUAGES C)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(Macros)

add_library(c23
            src/stdbit/stdc_bit_ceil.c
            src/stdbit/stdc_bit_floor.c
            src/stdbit/stdc_bit_width.c
            src/stdbit/stdc_count_ones.c
            src/stdbit/stdc_count_zeros.c
            src/stdbit/stdc_first_leading_one.c
            src/stdbit/stdc_first_leading_zero.c
            src/stdbit/stdc_first_trailing_one.c
            src/stdbit/stdc_first_trailing_zero.c
            src/stdbit/stdc_has_single_bit.c
            src/stdbit/stdc_leading_ones.c
            src/stdbit/stdc_leading_zeros.c
            src/stdbit/stdc_trailing_ones.c
            src/stdbit/stdc_trailing_zeros.c

            src/stddef.c
            src/stdlib.c)
target_include_directories(c23 PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(c23 PUBLIC -std=gnu11 -Wall -Wextra)

add_library(m23
            src/libm/e_hypotl.c
            src/libm/e_remainderl.c
            src/libm/s_remquol.c)
target_include_directories(m23 PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(m23 PUBLIC -std=gnu11 -Wall -Wextra)
#tests
c23_test(memalignment)
c23_test(stdbit)
c23_test(math)

c23_atf_test(stdbit AtfTests)
write_atf_file(AtfTests)
