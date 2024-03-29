
#include <stdbit.h>

#include <limits.h>

#include <atf-c.h>

ATF_TC(stdc_leading_zeros_uc);
ATF_TC_HEAD(stdc_leading_zeros_uc, tc)
{
  atf_tc_set_md_var(tc, "descr", "Test that stdc_leading_zeros_uc(3) works");
}
ATF_TC_BODY(stdc_leading_zeros_uc, tc)
{
  static const struct {
      unsigned char val;
      unsigned int res;
  } table[] = {
    {0, CHAR_BIT},
    {1, CHAR_BIT - 1},
    {7, CHAR_BIT - 3},
    {UCHAR_MAX, 0},
  };

  for (size_t i = 0; i < __arraycount(table); i++)
    ATF_CHECK(stdc_leading_zeros_uc(table[i].val) == table[i].res);
}


ATF_TP_ADD_TCS(tp)
{
  ATF_TP_ADD_TC(tp, stdc_leading_zeros_uc);

  return atf_no_error();
}
