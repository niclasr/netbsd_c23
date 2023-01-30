
#include <stddef.h>
#include <sys/bitops.h>

#include <sys/param.h>
#include <sys/cdefs.h>

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

/*
 * not sure if this one works, but my intuition says it might
 */
size_t
memalignment2(void *p)
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
