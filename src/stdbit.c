/*
Copyright (c) 2023, Niclas Rosenvik

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <sys/param.h>
#include <sys/cdefs.h>
#include <limits.h>
#include <stdbool.h>
#include <stdbit.h>

#define COUNT_IMPL(COMP)                   \
    typeof(value) mask = 1;                \
    int nbits = sizeof(value) * CHAR_BIT;  \
    int nset = 0;                          \
                                           \
    for (int i = 0; i < nbits; ++i)        \
    {                                      \
        if ((value & mask) COMP 0 )        \
        {                                  \
            ++nset;                        \
        }                                  \
       mask <<= 1;                         \
    }                                      \
                                           \
    return nset;                           \

#define LEADTRIAL_IMPL(START, COMP, SE)   \
    int nbits = sizeof(value) * CHAR_BIT; \
    typeof(value) mask = __BIT(START);    \
    int nset = 0;                         \
                                          \
    for (int i = 0; i < nbits; ++i)       \
    {                                     \
        if ((value & mask) COMP 0) {      \
             return nset;                 \
        }                                 \
        ++nset;                           \
        mask SE 1;                        \
    }                                     \
                                          \
    return nset;                          \


/* stdc_leading_zeros */

int
stdc_leading_zeros_uc(unsigned char value)
{
LEADTRIAL_IMPL(nbits - 1, !=, >>=)
}

int
stdc_leading_zeros_us(unsigned short value)
{
LEADTRIAL_IMPL(nbits - 1, !=, >>=)
}

int
stdc_leading_zeros_ui(unsigned int value)
{
LEADTRIAL_IMPL(nbits - 1, !=, >>=)
}

int
stdc_leading_zeros_ul(unsigned long value)
{
LEADTRIAL_IMPL(nbits - 1, !=, >>=)
}

int
stdc_leading_zeros_ull(unsigned long long value)
{
LEADTRIAL_IMPL(nbits - 1, !=, >>=)
}

/* stdc_leading_ones */

int
stdc_leading_ones_uc(unsigned char value)
{
LEADTRIAL_IMPL(nbits - 1, ==, >>=)
}

int
stdc_leading_ones_us(unsigned short value)
{
LEADTRIAL_IMPL(nbits - 1, ==, >>=)
}

int
stdc_leading_ones_ui(unsigned int value)
{
LEADTRIAL_IMPL(nbits - 1, ==, >>=)
}

int
stdc_leading_ones_ul(unsigned long value)
{
LEADTRIAL_IMPL(nbits - 1, ==, >>=)
}

int
stdc_leading_ones_ull(unsigned long long value)
{
LEADTRIAL_IMPL(nbits - 1, ==, >>=)
}

/* stdc_trailing_zeros */

int
stdc_trailing_zeros_uc(unsigned char value)
{
LEADTRIAL_IMPL(0, !=, <<=)
}

int
stdc_trailing_zeros_us(unsigned short value)
{
LEADTRIAL_IMPL(0, !=, <<=)
}

int
stdc_trailing_zeros_ui(unsigned int value)
{
LEADTRIAL_IMPL(0, !=, <<=)
}

int
stdc_trailing_zeros_ul(unsigned long value)
{
LEADTRIAL_IMPL(0, !=, <<=)
}

int
stdc_trailing_zeros_ull(unsigned long long value)
{
LEADTRIAL_IMPL(0, !=, <<=)
}

/* stdc_trailing_ones */

int
stdc_trailing_ones_uc(unsigned char value)
{
LEADTRIAL_IMPL(0, ==, <<=)
}

int
stdc_trailing_ones_us(unsigned short value)
{
LEADTRIAL_IMPL(0, ==, <<=)
}

int
stdc_trailing_ones_ui(unsigned int value)
{
LEADTRIAL_IMPL(0, ==, <<=)
}

int
stdc_trailing_ones_ul(unsigned long value)
{
LEADTRIAL_IMPL(0, ==, <<=)
}

int
stdc_trailing_ones_ull(unsigned long long value)
{
LEADTRIAL_IMPL(0, ==, <<=)
}

/* stdc_first_leading_zero */

int
stdc_first_leading_zero_uc(unsigned char value)
{
    int pos =  stdc_leading_ones_uc(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_zero_us(unsigned short value)
{
    int pos =  stdc_leading_ones_us(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_zero_ui(unsigned int value)
{
    int pos =  stdc_leading_ones_ui(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_zero_ul(unsigned long value)
{
    int pos =  stdc_leading_ones_ul(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_zero_ull(unsigned long long value)
{
    int pos =  stdc_leading_ones_ull(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

/* stdc_first_leading_one */

int
stdc_first_leading_one_uc(unsigned char value)
{
    int pos =  stdc_leading_zeros_uc(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_one_us(unsigned short value)
{
    int pos =  stdc_leading_zeros_us(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_one_ui(unsigned int value)
{
    int pos =  stdc_leading_zeros_ui(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_one_ul(unsigned long value)
{
    int pos =  stdc_leading_zeros_ul(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_one_ull(unsigned long long value)
{
    int pos =  stdc_leading_zeros_ull(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

/* stdc_count_zeros */

int
stdc_count_zeros_uc(unsigned char value)
{
COUNT_IMPL(==)
}

int
stdc_count_zeros_us(unsigned short value)
{
COUNT_IMPL(==)
}
int

stdc_count_zeros_ui(unsigned int value)
{
COUNT_IMPL(==)
}

int
stdc_count_zeros_ul(unsigned long value)
{
COUNT_IMPL(==)
}

int
stdc_count_zeros_ull(unsigned long long value)
{
COUNT_IMPL(==)
}

/* stdc_count_ones */

int
stdc_count_ones_uc(unsigned char value)
{
COUNT_IMPL(!=)
}

int
stdc_count_ones_us(unsigned short value)
{
COUNT_IMPL(!=)
}

int
stdc_count_ones_ui(unsigned int value)
{
COUNT_IMPL(!=)
}

int
stdc_count_ones_ul(unsigned long value)
{
COUNT_IMPL(!=)
}

int
stdc_count_ones_ull(unsigned long long value)
{
COUNT_IMPL(!=)
}

/* stdc_has_single_bit */

bool
stdc_has_single_bit_uc(unsigned char value)
{
    return ((value & (value - 1)) == 0) && (value != 0);
}

bool
stdc_has_single_bit_us(unsigned short value)
{
    return ((value & (value - 1)) == 0) && (value != 0);
}

bool
stdc_has_single_bit_ui(unsigned int value)
{
    return ((value & (value - 1)) == 0) && (value != 0);
}

bool
stdc_has_single_bit_ul(unsigned long value)
{
    return ((value & (value - 1)) == 0) && (value != 0);
}

bool
stdc_has_single_bit_ull(unsigned long long value)
{
    return ((value & (value - 1)) == 0) && (value != 0);
}

/* stdc_bit_width */

int
stdc_bit_width_uc(unsigned char value)
{
   return (sizeof(value) * CHAR_BIT) - stdc_leading_zeros_uc(value);
}

int
stdc_bit_width_us(unsigned short value)
{
   return (sizeof(value) * CHAR_BIT) - stdc_leading_zeros_us(value);
}

int
stdc_bit_width_ui(unsigned int value)
{
   return (sizeof(value) * CHAR_BIT) - stdc_leading_zeros_ui(value);
}

int
stdc_bit_width_ul(unsigned long value)
{
   return (sizeof(value) * CHAR_BIT) - stdc_leading_zeros_ul(value);
}

int
stdc_bit_width_ull(unsigned long long value)
{
   return (sizeof(value) * CHAR_BIT) - stdc_leading_zeros_ull(value);
}

/* stdc_bit_floor */

unsigned char
stdc_bit_floor_uc(unsigned char value)
{
   return value == 0 ? 0 : (typeof(value))__BIT(stdc_bit_width_uc(value) - 1);
}

unsigned short
stdc_bit_floor_us(unsigned short value)
{
   return value == 0 ? 0 : (typeof(value))__BIT(stdc_bit_width_us(value) - 1);
}

unsigned int
stdc_bit_floor_ui(unsigned int value)
{
   return value == 0 ? 0 : (typeof(value))__BIT(stdc_bit_width_ui(value) - 1);
}

unsigned long
stdc_bit_floor_ul(unsigned long value)
{
   return value == 0 ? 0 : (typeof(value))__BIT(stdc_bit_width_ul(value) - 1);
}

unsigned long long
stdc_bit_floor_ull(unsigned long long value)
{
   return value == 0 ? 0 : (typeof(value))__BIT(stdc_bit_width_ull(value) - 1);
}

/* stdc_bit_ceil */

unsigned char
stdc_bit_ceil_uc(unsigned char value)
{
   return (typeof(value))__BIT(stdc_bit_width_uc(value));
}

unsigned short
stdc_bit_ceil_us(unsigned short value)
{
   return (typeof(value))__BIT(stdc_bit_width_us(value));
}

unsigned int
stdc_bit_ceil_ui(unsigned int value)
{
   return (typeof(value))__BIT(stdc_bit_width_ui(value));
}

unsigned long
stdc_bit_ceil_ul(unsigned long value)
{
   return (typeof(value))__BIT(stdc_bit_width_ul(value));
}

unsigned long long
stdc_bit_ceil_ull(unsigned long long value)
{
   return (typeof(value))__BIT(stdc_bit_width_ull(value));
}
