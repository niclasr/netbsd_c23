
#include <stdbit.h>
#include <stdio.h>

void
test_leading_zeros()
{
  unsigned char a = 1;
  printf("leading zeros in %X: %d size:%zX\n", a, stdc_leading_zerosuc(a), sizeof(a));
  unsigned char b = 7;
  printf("leading zeros in %X: %d size:%zX\n", b, stdc_leading_zerosuc(b), sizeof(b));
  unsigned char c = 0;
  printf("leading zeros in %X: %d size:%zX\n", c, stdc_leading_zerosuc(c), sizeof(c));
}

void
test_leading_ones()
{
  unsigned char a = 1;
  printf("leading ones in %X: %d size:%zX\n", a, stdc_leading_onesuc(a), sizeof(a));
  unsigned char b = 0xE0;
  printf("leading ones in %X: %d size:%zX\n", b, stdc_leading_onesuc(b), sizeof(b));
  unsigned long long c = 0xFFFFFFFFFFFFFFFF;
  printf("leading ones in %llX: %d size:%zX\n", c, stdc_leading_onesull(c), sizeof(c));
  unsigned long long d = 0xFF00000000000000;
  printf("leading ones in %llX: %d size:%zX\n", d, stdc_leading_onesull(d), sizeof(d));
  unsigned long long e = 0xFFFFFFFFFFFFFFFE;
  printf("leading ones in %llX: %d size:%zX\n", e, stdc_leading_onesull(e), sizeof(e));
}

void
test_trailing_zeros()
{
  unsigned char a = 1;
  printf("trailing zeros in %X: %d size:%zX\n", a, stdc_trailing_zerosuc(a), sizeof(a));
  unsigned char b = 7;
  printf("trailing zeros in %X: %d size:%zX\n", b, stdc_trailing_zerosuc(b), sizeof(b));
  unsigned char c = 0;
  printf("trailing zeros in %X: %d size:%zX\n", c, stdc_trailing_zerosuc(c), sizeof(c));
  unsigned long d = 0x30000000000000;
  printf("trailing zeros in %lX: %d size:%zX\n", d, stdc_trailing_zerosul(d), sizeof(d));
}

void
test_trailing_ones()
{
  unsigned char a = 1;
  printf("trailing ones in %X: %d size:%zX\n", a, stdc_trailing_onesuc(a), sizeof(a));
  unsigned char b = 7;
  printf("trailing ones in %X: %d size:%zX\n", b, stdc_trailing_onesuc(b), sizeof(b));
  unsigned char c = 0xFF;
  printf("trailing ones in %X: %d size:%zX\n", c, stdc_trailing_onesuc(c), sizeof(c));
  unsigned long d = ~0x30000000000000;
  printf("trailing ones in %lX: %d size:%zX\n", d, stdc_trailing_onesul(d), sizeof(d));
}

void
test_first_leading_zero()
{
  unsigned char a = 0xE0;
  printf("first leading zero in %X: %d size:%zX\n", a, stdc_first_leading_zerouc(a), sizeof(a));
  unsigned char b = 0xFF;
  printf("first leading zero in %X: %d size:%zX\n", b, stdc_first_leading_zerouc(b), sizeof(b));
}

void
test_first_leading_one()
{
  unsigned char a = 0x1F;
  printf("first leading one in %X: %d size:%zX\n", a, stdc_first_leading_oneuc(a), sizeof(a));
  unsigned char b = 0x00;
  printf("first leading one in %X: %d size:%zX\n", b, stdc_first_leading_oneuc(b), sizeof(b));
}

void
test_count_zeros()
{
  unsigned short a = 1;
  printf("zeros in %X: %d size:%zX\n", a, stdc_count_zerosus(a), sizeof(a));
  unsigned short b = 7;
  printf("zeros in %X: %d size:%zX\n", b, stdc_count_zerosus(b), sizeof(b));
  unsigned int c = 15;
  printf("zeros in %X: %d size:%zX\n", c, stdc_count_zerosui(c), sizeof(c));
}

void
test_count_ones()
{
  unsigned short a = 1;
  printf("ones in %X: %d size:%zX\n", a, stdc_count_onesus(a), sizeof(a));
  unsigned short b = 7;
  printf("ones in %X: %d size:%zX\n", b, stdc_count_onesus(b), sizeof(b));
  unsigned int c = 15;
  printf("ones in %X: %d size:%zX\n", c, stdc_count_onesui(c), sizeof(c));
}

void
test_single_bit()
{
  unsigned short a = 1;
  printf("single bit set in %X: %d\n", a, stdc_has_single_bitus(a));
  unsigned short b = 7;
  printf("single bit set in %X: %d\n", b, stdc_has_single_bitus(b));
  unsigned int c = 15;
  printf("single bit set in %X: %d\n", c, stdc_has_single_bitui(c));
  unsigned int d = 8;
  printf("single bit set in %X: %d\n", d, stdc_has_single_bitui(d));
  unsigned int e = 0;
  printf("single bit set in %X: %d\n", e, stdc_has_single_bitui(e));
}

void
test_bit_width()
{
  unsigned char a = 0x1F;
  printf("bitwidth of %X: %d size:%zX\n", a, stdc_bit_widthuc(a), sizeof(a));
  unsigned char b = 0x00;
  printf("bitwidth of %X: %d size:%zX\n", b, stdc_bit_widthuc(b), sizeof(b));
  unsigned long c = 0x7FFFFFFFFFFFFFFF;
  printf("bitwidth of %lX: %d size:%zX\n", c, stdc_bit_widthul(c), sizeof(c));
}

int
main()
{
  test_leading_zeros();
  test_leading_ones();
  test_trailing_zeros();
  test_trailing_ones();
  test_first_leading_zero();
  test_first_leading_one();
  test_count_zeros();
  test_count_ones();
  test_single_bit();
  test_bit_width();
  return 0;
}
