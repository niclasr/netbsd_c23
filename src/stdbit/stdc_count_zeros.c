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

#include <limits.h>
#include <stdbit.h>
#include <strings.h>

unsigned int
stdc_count_zeros_uc(unsigned char value)
{
    return (sizeof(value)*CHAR_BIT) - popcount((unsigned int) value);
}

unsigned int
stdc_count_zeros_us(unsigned short value)
{
    return (sizeof(value)*CHAR_BIT) - popcount((unsigned int) value);
}

unsigned int
stdc_count_zeros_ui(unsigned int value)
{
    return (sizeof(value)*CHAR_BIT) - popcount(value);
}

unsigned int
stdc_count_zeros_ul(unsigned long value)
{
    return (sizeof(value)*CHAR_BIT) - popcountl(value);
}

unsigned int
stdc_count_zeros_ull(unsigned long long value)
{
    return (sizeof(value)*CHAR_BIT) - popcountll(value);
}
