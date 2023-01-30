
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
  printf("memalignment2 of %p: %zd\n", &a, memalignment2(&a));
  printf("memalignment2 of %p: %zd\n", p, memalignment2(p));
  printf("memalignment2 of %p: %zd\n", NULL, memalignment2(NULL));
  free(p);
  return 0;
}
