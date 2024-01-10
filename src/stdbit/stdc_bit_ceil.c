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

#include <stdbit.h>

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
