#ifndef _STDBIT_H_
#define _STDBIT_H_

#include <sys/cdefs.h>
#include <sys/endian.h>
#include <sys/stdint.h>

#include <machine/ansi.h>

#include <stdbool.h>

#ifdef  _BSD_SIZE_T_
typedef _BSD_SIZE_T_ size_t;
#undef  _BSD_SIZE_T_
#endif

#define __STDC_VERSION_STDBIT_H__ 202311L

#define __STDC_ENDIAN_LITTLE__	_LITTLE_ENDIAN
#define __STDC_ENDIAN_BIG__	_BIG_ENDIAN
#define __STDC_ENDIAN_NATIVE__	_BYTE_ORDER

__BEGIN_DECLS

unsigned int stdc_leading_zeros_uc(unsigned char) __constfunc;
unsigned int stdc_leading_zeros_us(unsigned short) __constfunc;
unsigned int stdc_leading_zeros_ui(unsigned int) __constfunc;
unsigned int stdc_leading_zeros_ul(unsigned long) __constfunc;
unsigned int stdc_leading_zeros_ull(unsigned long long) __constfunc;

unsigned int stdc_leading_ones_uc(unsigned char) __constfunc;
unsigned int stdc_leading_ones_us(unsigned short) __constfunc;
unsigned int stdc_leading_ones_ui(unsigned int) __constfunc;
unsigned int stdc_leading_ones_ul(unsigned long) __constfunc;
unsigned int stdc_leading_ones_ull(unsigned long long) __constfunc;

unsigned int stdc_trailing_zeros_uc(unsigned char) __constfunc;
unsigned int stdc_trailing_zeros_us(unsigned short) __constfunc;
unsigned int stdc_trailing_zeros_ui(unsigned int) __constfunc;
unsigned int stdc_trailing_zeros_ul(unsigned long) __constfunc;
unsigned int stdc_trailing_zeros_ull(unsigned long long) __constfunc;

unsigned int stdc_trailing_ones_uc(unsigned char) __constfunc;
unsigned int stdc_trailing_ones_us(unsigned short) __constfunc;
unsigned int stdc_trailing_ones_ui(unsigned int) __constfunc;
unsigned int stdc_trailing_ones_ul(unsigned long) __constfunc;
unsigned int stdc_trailing_ones_ull(unsigned long long) __constfunc;

unsigned int stdc_first_leading_zero_uc(unsigned char) __constfunc;
unsigned int stdc_first_leading_zero_us(unsigned short) __constfunc;
unsigned int stdc_first_leading_zero_ui(unsigned int) __constfunc;
unsigned int stdc_first_leading_zero_ul(unsigned long) __constfunc;
unsigned int stdc_first_leading_zero_ull(unsigned long long) __constfunc;

unsigned int stdc_first_leading_one_uc(unsigned char) __constfunc;
unsigned int stdc_first_leading_one_us(unsigned short) __constfunc;
unsigned int stdc_first_leading_one_ui(unsigned int) __constfunc;
unsigned int stdc_first_leading_one_ul(unsigned long) __constfunc;
unsigned int stdc_first_leading_one_ull(unsigned long long) __constfunc;

unsigned int stdc_first_trailing_zero_uc(unsigned char) __constfunc;
unsigned int stdc_first_trailing_zero_us(unsigned short) __constfunc;
unsigned int stdc_first_trailing_zero_ui(unsigned int) __constfunc;
unsigned int stdc_first_trailing_zero_ul(unsigned long) __constfunc;
unsigned int stdc_first_trailing_zero_ull(unsigned long long) __constfunc;

unsigned int stdc_first_trailing_one_uc(unsigned char) __constfunc;
unsigned int stdc_first_trailing_one_us(unsigned short) __constfunc;
unsigned int stdc_first_trailing_one_ui(unsigned int) __constfunc;
unsigned int stdc_first_trailing_one_ul(unsigned long) __constfunc;
unsigned int stdc_first_trailing_one_ull(unsigned long long) __constfunc;

unsigned int stdc_count_zeros_uc(unsigned char) __constfunc;
unsigned int stdc_count_zeros_us(unsigned short) __constfunc;
unsigned int stdc_count_zeros_ui(unsigned int) __constfunc;
unsigned int stdc_count_zeros_ul(unsigned long) __constfunc;
unsigned int stdc_count_zeros_ull(unsigned long long) __constfunc;

unsigned int stdc_count_ones_uc(unsigned char) __constfunc;
unsigned int stdc_count_ones_us(unsigned short) __constfunc;
unsigned int stdc_count_ones_ui(unsigned int) __constfunc;
unsigned int stdc_count_ones_ul(unsigned long) __constfunc;
unsigned int stdc_count_ones_ull(unsigned long long) __constfunc;

bool stdc_has_single_bit_uc(unsigned char) __constfunc;
bool stdc_has_single_bit_us(unsigned short) __constfunc;
bool stdc_has_single_bit_ui(unsigned int) __constfunc;
bool stdc_has_single_bit_ul(unsigned long) __constfunc;
bool stdc_has_single_bit_ull(unsigned long long) __constfunc;

unsigned int stdc_bit_width_uc(unsigned char) __constfunc;
unsigned int stdc_bit_width_us(unsigned short) __constfunc;
unsigned int stdc_bit_width_ui(unsigned int) __constfunc;
unsigned int stdc_bit_width_ul(unsigned long) __constfunc;
unsigned int stdc_bit_width_ull(unsigned long long) __constfunc;

unsigned char      stdc_bit_floor_uc(unsigned char) __constfunc;
unsigned short     stdc_bit_floor_us(unsigned short) __constfunc;
unsigned int       stdc_bit_floor_ui(unsigned int) __constfunc;
unsigned long      stdc_bit_floor_ul(unsigned long) __constfunc;
unsigned long long stdc_bit_floor_ull(unsigned long long) __constfunc;

unsigned char      stdc_bit_ceil_uc(unsigned char) __constfunc;
unsigned short     stdc_bit_ceil_us(unsigned short) __constfunc;
unsigned int       stdc_bit_ceil_ui(unsigned int) __constfunc;
unsigned long      stdc_bit_ceil_ul(unsigned long) __constfunc;
unsigned long long stdc_bit_ceil_ull(unsigned long long) __constfunc;

__END_DECLS

#define __STDBIT_GENERIC__(FSIM, X) _Generic((X),   \
        unsigned char: stdc_ ## FSIM ## _uc,       \
        unsigned short: stdc_ ## FSIM ## _us,      \
        unsigned int: stdc_ ## FSIM ## _ui,        \
        unsigned long: stdc_ ## FSIM ## _ul,       \
        unsigned long long : stdc_ ## FSIM ## _ull \
        )(X)

#define stdc_leading_zeros(X)       __STDBIT_GENERIC__(leading_zeros, X)
#define stdc_leading_ones(X)        __STDBIT_GENERIC__(leading_ones, X)
#define stdc_trailing_zeros(X)      __STDBIT_GENERIC__(trailing_zeros, X)
#define stdc_trailing_ones(X)       __STDBIT_GENERIC__(trailing_ones, X)
#define stdc_first_leading_zero(X)  __STDBIT_GENERIC__(first_leading_zero, X)
#define stdc_first_leading_one(X)   __STDBIT_GENERIC__(first_leading_one, X)
#define stdc_first_trailing_zero(X) __STDBIT_GENERIC__(first_trailing_zero, X)
#define stdc_first_trailing_one(X)  __STDBIT_GENERIC__(first_trailing_one, X)
#define stdc_count_zeros(X)         __STDBIT_GENERIC__(count_zeros, X)
#define stdc_count_ones(X)          __STDBIT_GENERIC__(count_ones, X)
#define stdc_has_single_bit(X)      __STDBIT_GENERIC__(has_single_bit, X)
#define stdc_bit_width(X)           __STDBIT_GENERIC__(bit_width, X)
#define stdc_bit_floor(X)           __STDBIT_GENERIC__(bit_floor, X)
#define stdc_bit_ceil(X)           __STDBIT_GENERIC__(bit_ceil, X)

#endif
