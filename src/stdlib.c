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

#include <stddef.h>
#include <stdlib.h>
#include <sys/bitops.h>

#include <sys/param.h>
#include <sys/cdefs.h>

void
free_sized(void *ptr, size_t size __unused)
{
  /* size unused since jemalloc does not provide the size */
  free(ptr);
}

void
free_aligned_sized(void *ptr, size_t alignment __unused, size_t size __unused)
{
  /* alignment unused since jemalloc does not provide the alignment */
  /* size unused since jemalloc does not provide the size */
  free(ptr);
}

#if 0
/* not implemented yet */
size_t
memalignment(const void *p)
{
    int fbs;
    uintptr_t ip = p;

    if (p == NULL) {
        return 0;
    }

#ifdef _LP64 /* 64-bit pointers */
#define FLSFUNC fls64
#define FLSTYPE uint64_t
#else  /* 32-bit pointers */
#define FLSFUNC fls32
#define FLSTYPE uint32_t
#endif

    fbs = FLSFUNC((FLSTYPE)p);
    size_t alignment = __BIT(fbs-1);

    while ((ip % alignment) != 0) {
        alignment >>= 1;
    }

    return alignment;
}
#endif

/*
 * not sure if this one works, but my intuition says it might
 * tested and gives the right values for all 32-bit adresses
 */
size_t
memalignment(const void *p)
{
    if (p == NULL)
        return 0;

#ifdef _LP64
    int bit = ffs64((uint64_t)p);
#else
    int bit = ffs32((uint32_t)p);
#endif
    return (size_t)__BIT(bit-1);
}
