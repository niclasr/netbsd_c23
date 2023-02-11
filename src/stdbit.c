
#include <sys/param.h>
#include <sys/cdefs.h>
#include <limits.h>
#include <stdbool.h>
#include <stdbit.h>

#define COUNT_IMPL(COMP)                   \
    typeof(value) mask = 1;                \
    int nbits = sizeof(value) * CHAR_BIT;  \
    int nset = 0;                          \
                                           \
    for (int i = 0; i < nbits; ++i)        \
    {                                      \
        if ((value & mask) COMP 0 )        \
        {                                  \
            ++nset;                        \
        }                                  \
       mask <<= 1;                         \
    }                                      \
                                           \
    return nset;                           \

#define LEADTRIAL_IMPL(START, COMP, SE)   \
    int nbits = sizeof(value) * CHAR_BIT; \
    typeof(value) mask = __BIT(START);    \
    int nset = 0;                         \
                                          \
    for (int i = 0; i < nbits; ++i)       \
    {                                     \
        if ((value & mask) COMP 0) {      \
             return nset;                 \
        }                                 \
        ++nset;                           \
        mask SE 1;                        \
    }                                     \
                                          \
    return nset;                          \



int
stdc_leading_zerosuc(unsigned char value)
{
LEADTRIAL_IMPL(nbits - 1, !=, >>=)
}

int
stdc_leading_zerosus(unsigned short value)
{
LEADTRIAL_IMPL(nbits - 1, !=, >>=)
}

int
stdc_leading_zerosui(unsigned int value)
{
LEADTRIAL_IMPL(nbits - 1, !=, >>=)
}

int
stdc_leading_zerosul(unsigned long value)
{
LEADTRIAL_IMPL(nbits - 1, !=, >>=)
}

int
stdc_leading_zerosull(unsigned long long value)
{
LEADTRIAL_IMPL(nbits - 1, !=, >>=)
}




int
stdc_leading_onesuc(unsigned char value)
{
LEADTRIAL_IMPL(nbits - 1, ==, >>=)
}

int
stdc_leading_onesus(unsigned short value)
{
LEADTRIAL_IMPL(nbits - 1, ==, >>=)
}

int
stdc_leading_onesui(unsigned int value)
{
LEADTRIAL_IMPL(nbits - 1, ==, >>=)
}

int
stdc_leading_onesul(unsigned long value)
{
LEADTRIAL_IMPL(nbits - 1, ==, >>=)
}

int
stdc_leading_onesull(unsigned long long value)
{
LEADTRIAL_IMPL(nbits - 1, ==, >>=)
}



int
stdc_trailing_zerosuc(unsigned char value)
{
LEADTRIAL_IMPL(0, !=, <<=)
}

int
stdc_trailing_zerosus(unsigned short value)
{
LEADTRIAL_IMPL(0, !=, <<=)
}

int
stdc_trailing_zerosui(unsigned int value)
{
LEADTRIAL_IMPL(0, !=, <<=)
}

int
stdc_trailing_zerosul(unsigned long value)
{
LEADTRIAL_IMPL(0, !=, <<=)
}

int
stdc_trailing_zerosull(unsigned long long value)
{
LEADTRIAL_IMPL(0, !=, <<=)
}




int
stdc_trailing_onesuc(unsigned char value)
{
LEADTRIAL_IMPL(0, ==, <<=)
}

int
stdc_trailing_onesus(unsigned short value)
{
LEADTRIAL_IMPL(0, ==, <<=)
}

int
stdc_trailing_onesui(unsigned int value)
{
LEADTRIAL_IMPL(0, ==, <<=)
}

int
stdc_trailing_onesul(unsigned long value)
{
LEADTRIAL_IMPL(0, ==, <<=)
}

int
stdc_trailing_onesull(unsigned long long value)
{
LEADTRIAL_IMPL(0, ==, <<=)
}




int
stdc_first_leading_zerouc(unsigned char value)
{
    int pos =  stdc_leading_onesuc(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_zerous(unsigned short value)
{
    int pos =  stdc_leading_onesus(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_zeroui(unsigned int value)
{
    int pos =  stdc_leading_onesui(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_zeroul(unsigned long value)
{
    int pos =  stdc_leading_onesul(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_zeroull(unsigned long long value)
{
    int pos =  stdc_leading_onesull(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}





int
stdc_first_leading_oneuc(unsigned char value)
{
    int pos =  stdc_leading_zerosuc(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_oneus(unsigned short value)
{
    int pos =  stdc_leading_zerosus(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_oneui(unsigned int value)
{
    int pos =  stdc_leading_zerosui(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_oneul(unsigned long value)
{
    int pos =  stdc_leading_zerosul(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}

int
stdc_first_leading_oneull(unsigned long long value)
{
    int pos =  stdc_leading_zerosull(value);
    return (pos != (sizeof(value) * CHAR_BIT)) * (pos + 1);
}







int
stdc_count_zerosuc(unsigned char value)
{
COUNT_IMPL(==)
}

int
stdc_count_zerosus(unsigned short value)
{
COUNT_IMPL(==)
}
int

stdc_count_zerosui(unsigned int value)
{
COUNT_IMPL(==)
}

int
stdc_count_zerosul(unsigned long value)
{
COUNT_IMPL(==)
}

int
stdc_count_zerosull(unsigned long long value)
{
COUNT_IMPL(==)
}

int
stdc_count_onesuc(unsigned char value)
{
COUNT_IMPL(!=)
}

int
stdc_count_onesus(unsigned short value)
{
COUNT_IMPL(!=)
}

int
stdc_count_onesui(unsigned int value)
{
COUNT_IMPL(!=)
}

int
stdc_count_onesul(unsigned long value)
{
COUNT_IMPL(!=)
}

int
stdc_count_onesull(unsigned long long value)
{
COUNT_IMPL(!=)
}

bool
stdc_has_single_bituc(unsigned char value)
{
    return ((value & (value - 1)) == 0) && (value != 0);
}

bool
stdc_has_single_bitus(unsigned short value)
{
    return ((value & (value - 1)) == 0) && (value != 0);
}

bool
stdc_has_single_bitui(unsigned int value)
{
    return ((value & (value - 1)) == 0) && (value != 0);
}

bool
stdc_has_single_bitul(unsigned long value)
{
    return ((value & (value - 1)) == 0) && (value != 0);
}

bool
stdc_has_single_bitull(unsigned long long value)
{
    return ((value & (value - 1)) == 0) && (value != 0);
}






int
stdc_bit_widthuc(unsigned char value)
{
   return (sizeof(value) * CHAR_BIT) - stdc_leading_zerosuc(value);
}

int
stdc_bit_widthus(unsigned short value)
{
   return (sizeof(value) * CHAR_BIT) - stdc_leading_zerosus(value);
}

int
stdc_bit_widthui(unsigned int value)
{
   return (sizeof(value) * CHAR_BIT) - stdc_leading_zerosui(value);
}

int
stdc_bit_widthul(unsigned long value)
{
   return (sizeof(value) * CHAR_BIT) - stdc_leading_zerosul(value);
}

int
stdc_bit_widthull(unsigned long long value)
{
   return (sizeof(value) * CHAR_BIT) - stdc_leading_zerosull(value);
}







unsigned char
stdc_bit_flooruc(unsigned char value)
{
   return value == 0 ? 0 : (typeof(value))__BIT(stdc_bit_widthuc(value) - 1);
}

unsigned short
stdc_bit_floorus(unsigned short value)
{
   return value == 0 ? 0 : (typeof(value))__BIT(stdc_bit_widthus(value) - 1);
}

unsigned int
stdc_bit_floorui(unsigned int value)
{
   return value == 0 ? 0 : (typeof(value))__BIT(stdc_bit_widthui(value) - 1);
}

unsigned long
stdc_bit_floorul(unsigned long value)
{
   return value == 0 ? 0 : (typeof(value))__BIT(stdc_bit_widthul(value) - 1);
}

unsigned long long
stdc_bit_floorull(unsigned long long value)
{
   return value == 0 ? 0 : (typeof(value))__BIT(stdc_bit_widthull(value) - 1);
}
