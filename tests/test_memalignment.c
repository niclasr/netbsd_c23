
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int
main()
{
  uint64_t a = 1;
  printf("memalignment of %p: %zd\n", &a, memalignment(&a));
  void * p = aligned_alloc(512, 8);
  printf("memalignment of %p: %zd\n", p, memalignment(p));
  free(p);
  return 0;
}
