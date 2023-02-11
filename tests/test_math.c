
#include <stdio.h>
#include <nbmath.h>

void
test_hypotl()
{
  long double mka = 1;
  long double nka = 1;
  long double ra = nbhypotl(mka, nka);
  printf("nka:%Le mka:%Le res:%Le\n", mka, nka, ra);  
}

int
main()
{
  test_hypotl();
  return 0;
}
