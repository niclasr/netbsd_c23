#ifndef _NBMATH_PRIVATE_H_
#define _NBMATH_PRIVATE_H_

#include <sys/endian.h>
#include <machine/ieee.h>

union ieee_expsign_u {
   struct {
#if _BYTE_ORDER == _BIG_ENDIAN
       uint64_t sign:1;
       uint64_t exp:EXT_EXPBITS;
#else
       uint64_t exp:EXT_EXPBITS;
       uint64_t sign:1;
#endif
   } split;
   uint64_t esu_expsign :1+EXT_EXPBITS;
};

#define esu_sign split.sign
#define esu_exp split.exp

#if 0
union ieee_expsign {
   struct {
#if _BYTE_ORDER == _BIG_ENDIAN
       uint64_t sign:1;
       uint64_t exp:EXT_EXPBITS;
#else
       uint64_t exp:EXT_EXPBITS;
       uint64_t sign:1;
#endif
   } s;
   uint64_t expsign :1+EXT_EXPBITS;
};
#endif

union ieee_80man_u {
    uint64_t manu_man:EXT_FRACBITS;
    struct {
#if _BYTE_ORDER == _BIG_ENDIAN
        uint32_t manh:EXT_FRACHBITS;
        uint32_t manl:EXT_FRACLBITS;
#else
        uint32_t manl:EXT_FRACLBITS;
        uint32_t manh:EXT_FRACHBITS;
#endif
    } man;

};

#define manu_manh man.manh
#define manu_manl man.manl

/* Get expsign as a 16 bit int from a long double.  */

#define GET_LDBL_EXPSIGN(i, d)     \
do {                               \
  union ieee_ext_u ge_u;           \
  union ieee_expsign_u ge_es;      \
  ge_u.extu_ld = (d);              \
  ge_es.esu_sign = ge_u.extu_sign; \
  ge_es.esu_exp = ge_u.extu_exp;   \
  (i) = ge_es.esu_expsign;         \
} while (0)

/* Set expsign of a long double from a 16 bit int.  */

#define SET_LDBL_EXPSIGN(d, v)     \
do {                               \
  union ieee_ext_u se_u;           \
  union ieee_expsign_u se_es;      \
  se_u.extu_ld = (d);              \
  se_es.esu_expsign = (v);         \
  se_u.extu_sign = se_es.esu_sign; \
  se_u.extu_exp = se_es.esu_exp;   \
  (d) = se_u.extu_ld;              \
} while (0)

/*
 * Get expsign and mantissa as 16 bit and 64 bit ints from an 80 bit long
 * double.
 */

#define	EXTRACT_LDBL80_WORDS(ix0,ix1,d)   \
do {                                      \
  union ieee_ext_u ew_u;                  \
  union ieee_expsign_u ew_es;             \
  union ieee_80man_u ew_80man;            \
  ew_u.extu_ld = (d);                     \
  ew_es.esu_sign = ew_u.extu_sign;        \
  ew_es.esu_exp = ew_u.extu_exp;          \
  ew_80man.manu_manh = ew_u.extu_frach;   \
  ew_80man.manu_manh = ew_u.extu_fracl;   \
  (ix0) = ew_es.esu_expsign;              \
  (ix1) = ew_80man.manu_man;              \
} while (0)

/*
 * Get expsign and mantissa as one 16 bit and two 64 bit ints from a 128 bit
 * long double.
 */

#define	EXTRACT_LDBL128_WORDS(ix0,ix1,ix2,d) \
do {                                         \
  union ieee_ext_u ew_u;                     \
  union ieee_expsign_u ew_es;                \
  ew_u.ext_ld = (d);                         \
  ew_es.esu_sign = ew_u.extu_sign;           \
  ew_es.esu_exp = ew_u.extu_exp;             \
  (ix0) = ew_es.esu_expsign;                 \
  (ix1) = ew_u.extu_frach;                   \
  (ix2) = ew_u.extu_fracl;                   \
} while (0)


/*
 * Set an 80 bit long double from a 16 bit int expsign and a 64 bit int
 * mantissa.
 */

#define	INSERT_LDBL80_WORDS(d,ix0,ix1)   \
do {                                     \
  union ieee_ext_u iw_u;                 \
  union ieee_expsign_u iw_es;            \
  union ieee_80man_u iw_man;             \
  iw_es.expsign = ix0;                   \
  iw_u.extu_exp = iw_es.esu_exp;         \
  iw_u.extu_sign = iw_es.esu_sign;       \
  iw_man.manu_man = (ix1);               \
  iw_u.extu_fracl = iw_man.manu_manl;    \
  iw_u.extu_frach = iw_man.manu_manh;    \
  (d) = iw_u.extu_ld;                    \
} while (0)

/*
 * Set a 128 bit long double from a 16 bit int expsign and two 64 bit ints
 * comprising the mantissa.
 */

#define	INSERT_LDBL128_WORDS(d,ix0,ix1,ix2) \
do {                                        \
  union ieee_ext_u iw_u;                    \
  union ieee_expsign_u iw_es;               \
  iw_es.expsign = (ix0);                    \
  iw_u.extu_exp = iw_es.esu_exp;            \
  iw_u.extu_sign = iw_es.esu_sign;          \
  iw_u.extu_frach = (ix1);                  \
  iw_u.extu_fracl = (ix2);                  \
  (d) = iw_u.extu_ld;                       \
} while (0)


/*
 * Mix 0, 1 or 2 NaNs.  First add 0 to each arg.  This normally just turns
 * signaling NaNs into quiet NaNs by setting a quiet bit.  We do this
 * because we want to never return a signaling NaN, and also because we
 * don't want the quiet bit to affect the result.  Then mix the converted
 * args using the specified operation.
 *
 * When one arg is NaN, the result is typically that arg quieted.  When both
 * args are NaNs, the result is typically the quietening of the arg whose
 * mantissa is largest after quietening.  When neither arg is NaN, the
 * result may be NaN because it is indeterminate, or finite for subsequent
 * construction of a NaN as the indeterminate 0.0L/0.0L.
 *
 * Technical complications: the result in bits after rounding to the final
 * precision might depend on the runtime precision and/or on compiler
 * optimizations, especially when different register sets are used for
 * different precisions.  Try to make the result not depend on at least the
 * runtime precision by always doing the main mixing step in long double
 * precision.  Try to reduce dependencies on optimizations by adding the
 * the 0's in different precisions (unless everything is in long double
 * precision).
 */
#define	nan_mix(x, y)		(nan_mix_op((x), (y), +))
#define	nan_mix_op(x, y, op)	(((x) + 0.0L) op ((y) + 0))

#endif
