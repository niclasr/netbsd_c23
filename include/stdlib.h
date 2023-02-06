
#ifndef _C23_STDLIB_H_OVERLAY_
#define _C23_STDLIB_H_OVERLAY_

#include_next <stdlib.h>

#define __STDC_VERSION_STDLIB_H__ 202311L

void free_sized(void *, size_t);
void free_aligned_sized(void *, size_t, size_t);
size_t memalignment(const void *);

#endif
