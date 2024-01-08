
#include <stdbit.h>
#include <stdio.h>

void
test_leading_zeros()
{
  unsigned char a = 1;
  printf("leading zeros in %X: %u size:%zX\n", a, stdc_leading_zeros_uc(a), sizeof(a));
  unsigned char b = 7;
  printf("leading zeros in %X: %u size:%zX\n", b, stdc_leading_zeros_uc(b), sizeof(b));
  unsigned char c = 0;
  printf("leading zeros in %X: %u size:%zX\n", c, stdc_leading_zeros_uc(c), sizeof(c));
}

void
test_leading_ones()
{
  unsigned char a = 1;
  printf("leading ones in %X: %u size:%zX\n", a, stdc_leading_ones_uc(a), sizeof(a));
  unsigned char b = 0xE0;
  printf("leading ones in %X: %u size:%zX\n", b, stdc_leading_ones_uc(b), sizeof(b));
  unsigned long long c = 0xFFFFFFFFFFFFFFFF;
  printf("leading ones in %llX: %u size:%zX\n", c, stdc_leading_ones_ull(c), sizeof(c));
  unsigned long long d = 0xFF00000000000000;
  printf("leading ones in %llX: %u size:%zX\n", d, stdc_leading_ones_ull(d), sizeof(d));
  unsigned long long e = 0xFFFFFFFFFFFFFFFE;
  printf("leading ones in %llX: %u size:%zX\n", e, stdc_leading_ones_ull(e), sizeof(e));
}

void
test_trailing_zeros()
{
  unsigned char a = 1;
  printf("trailing zeros in %X: %u size:%zX\n", a, stdc_trailing_zeros_uc(a), sizeof(a));
  unsigned char b = 7;
  printf("trailing zeros in %X: %u size:%zX\n", b, stdc_trailing_zeros_uc(b), sizeof(b));
  unsigned char c = 0;
  printf("trailing zeros in %X: %u size:%zX\n", c, stdc_trailing_zeros_uc(c), sizeof(c));
  unsigned long d = 0x30000000000000;
  printf("trailing zeros in %lX: %u size:%zX\n", d, stdc_trailing_zeros_ul(d), sizeof(d));
}

void
test_trailing_ones()
{
  unsigned char a = 1;
  printf("trailing ones in %X: %u size:%zX\n", a, stdc_trailing_ones_uc(a), sizeof(a));
  unsigned char b = 7;
  printf("trailing ones in %X: %u size:%zX\n", b, stdc_trailing_ones_uc(b), sizeof(b));
  unsigned char c = 0xFF;
  printf("trailing ones in %X: %u size:%zX\n", c, stdc_trailing_ones_uc(c), sizeof(c));
  unsigned long d = ~0x30000000000000;
  printf("trailing ones in %lX: %u size:%zX\n", d, stdc_trailing_ones_ul(d), sizeof(d));
}

void
test_first_leading_zero()
{
  unsigned char a = 0xE0;
  printf("first leading zero in %X: %u size:%zX\n", a, stdc_first_leading_zero_uc(a), sizeof(a));
  unsigned char b = 0xFF;
  printf("first leading zero in %X: %u size:%zX\n", b, stdc_first_leading_zero_uc(b), sizeof(b));
}

void
test_first_leading_one()
{
  unsigned char a = 0x1F;
  printf("first leading one in %X: %u size:%zX\n", a, stdc_first_leading_one_uc(a), sizeof(a));
  unsigned char b = 0x00;
  printf("first leading one in %X: %u size:%zX\n", b, stdc_first_leading_one_uc(b), sizeof(b));
}

void
test_count_zeros()
{
  unsigned short a = 1;
  printf("zeros in %X: %u size:%zX\n", a, stdc_count_zeros_us(a), sizeof(a));
  unsigned short b = 7;
  printf("zeros in %X: %u size:%zX\n", b, stdc_count_zeros_us(b), sizeof(b));
  unsigned int c = 15;
  printf("zeros in %X: %u size:%zX\n", c, stdc_count_zeros_ui(c), sizeof(c));
}

void
test_count_ones()
{
  unsigned short a = 1;
  printf("ones in %X: %u size:%zX\n", a, stdc_count_ones_us(a), sizeof(a));
  unsigned short b = 7;
  printf("ones in %X: %u size:%zX\n", b, stdc_count_ones_us(b), sizeof(b));
  unsigned int c = 15;
  printf("ones in %X: %u size:%zX\n", c, stdc_count_ones_ui(c), sizeof(c));
}

void
test_single_bit()
{
  unsigned short a = 1;
  printf("single bit set in %X: %u\n", a, stdc_has_single_bit_us(a));
  unsigned short b = 7;
  printf("single bit set in %X: %u\n", b, stdc_has_single_bit_us(b));
  unsigned int c = 15;
  printf("single bit set in %X: %u\n", c, stdc_has_single_bit_ui(c));
  unsigned int d = 8;
  printf("single bit set in %X: %u\n", d, stdc_has_single_bit_ui(d));
  unsigned int e = 0;
  printf("single bit set in %X: %u\n", e, stdc_has_single_bit_ui(e));
}

void
test_bit_width()
{
  unsigned char a = 0x1F;
  printf("bitwidth of %X: %u size:%zX\n", a, stdc_bit_width_uc(a), sizeof(a));
  unsigned char b = 0x00;
  printf("bitwidth of %X: %u size:%zX\n", b, stdc_bit_width_uc(b), sizeof(b));
  unsigned long c = 0x7FFFFFFFFFFFFFFF;
  printf("bitwidth of %lX: %u size:%zX\n", c, stdc_bit_width_ul(c), sizeof(c));
}

void
test_generics()
{
  printf("Testing generics:\n");
  unsigned char a = 1;
  printf("leading zeros in %X: %u size:%zX\n", a, stdc_leading_zeros(a), sizeof(a));
  unsigned char b = 7;
  printf("leading zeros in %X: %u size:%zX\n", b, stdc_leading_zeros(b), sizeof(b));
  unsigned char c = 0;
  printf("leading zeros in %X: %u size:%zX\n", c, stdc_leading_zeros(c), sizeof(c));
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
  test_generics();
  return 0;
}
