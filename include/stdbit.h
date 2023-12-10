#ifndef _STDC_VERSION_STDBIT_H_
#define _STDC_VERSION_STDBIT_H_ 202311L

#include <sys/cdefs.h>
#include <sys/endian.h>
#include <sys/stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define __STDC_ENDIAN_LITTLE__	_LITTLE_ENDIAN
#define __STDC_ENDIAN_BIG__	_BIG_ENDIAN
#define __STDC_ENDIAN_NATIVE__	_BYTE_ORDER

__BEGIN_DECLS

int stdc_leading_zerosuc(unsigned char);
int stdc_leading_zerosus(unsigned short);
int stdc_leading_zerosui(unsigned int);
int stdc_leading_zerosul(unsigned long);
int stdc_leading_zerosull(unsigned long long);

int stdc_leading_onesuc(unsigned char);
int stdc_leading_onesus(unsigned short);
int stdc_leading_onesui(unsigned int);
int stdc_leading_onesul(unsigned long);
int stdc_leading_onesull(unsigned long long);

int stdc_trailing_zerosuc(unsigned char);
int stdc_trailing_zerosus(unsigned short);
int stdc_trailing_zerosui(unsigned int);
int stdc_trailing_zerosul(unsigned long);
int stdc_trailing_zerosull(unsigned long long);

int stdc_trailing_onesuc(unsigned char);
int stdc_trailing_onesus(unsigned short);
int stdc_trailing_onesui(unsigned int);
int stdc_trailing_onesul(unsigned long);
int stdc_trailing_onesull(unsigned long long);

int stdc_first_leading_zerouc(unsigned char);
int stdc_first_leading_zerous(unsigned short);
int stdc_first_leading_zeroui(unsigned int);
int stdc_first_leading_zeroul(unsigned long);
int stdc_first_leading_zeroull(unsigned long long);

int stdc_first_leading_oneuc(unsigned char);
int stdc_first_leading_oneus(unsigned short);
int stdc_first_leading_oneui(unsigned int);
int stdc_first_leading_oneul(unsigned long);
int stdc_first_leading_oneull(unsigned long long);

int stdc_count_zerosuc(unsigned char);
int stdc_count_zerosus(unsigned short);
int stdc_count_zerosui(unsigned int);
int stdc_count_zerosul(unsigned long);
int stdc_count_zerosull(unsigned long long);

int stdc_count_onesuc(unsigned char);
int stdc_count_onesus(unsigned short);
int stdc_count_onesui(unsigned int);
int stdc_count_onesul(unsigned long);
int stdc_count_onesull(unsigned long long);

bool stdc_has_single_bituc(unsigned char);
bool stdc_has_single_bitus(unsigned short);
bool stdc_has_single_bitui(unsigned int);
bool stdc_has_single_bitul(unsigned long);
bool stdc_has_single_bitull(unsigned long long);

int stdc_bit_widthuc(unsigned char);
int stdc_bit_widthus(unsigned short);
int stdc_bit_widthui(unsigned int);
int stdc_bit_widthul(unsigned long);
int stdc_bit_widthull(unsigned long long);

unsigned char      stdc_bit_flooruc(unsigned char);
unsigned short     stdc_bit_floorus(unsigned short);
unsigned int       stdc_bit_floorui(unsigned int);
unsigned long      stdc_bit_floorul(unsigned long);
unsigned long long stdc_bit_floorull(unsigned long long);

__END_DECLS

#define __STDBIT_GENERIC__(FSIM, X) _Generic((X),   \
        unsigned char: stdc_ ## FSIM ## uc,       \
        unsigned short: stdc_ ## FSIM ## us,      \
        unsigned int: stdc_ ## FSIM ## ui,        \
        unsigned long: stdc_ ## FSIM ## ul,       \
        unsigned long long : stdc_ ## FSIM ## ull \
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

#endif
