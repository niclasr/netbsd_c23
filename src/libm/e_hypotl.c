/* From: @(#)e_hypot.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 */

#include <sys/cdefs.h>
/* __FBSDID("$FreeBSD$"); not NetBSD */

/* long double version of hypot().  See e_hypot.c for most comments. */

#include <float.h>

/* #include "fpmath.h" not in NetBSD*/
#include "math.h"
/* #include "math_private.h"*/

/* local machine includes */
#include <sys/types.h>
#include <sys/endian.h>
#include <machine/ieee.h>

#define	GET_LDBL_MAN(h, l, v) do {	\
	union ieee_ext_u uv;		\
					\
	uv.extu_ld = v;			\
	h = uv.extu_frach;		\
	l = uv.extu_fracl;		\
} while (0)

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

#define GET_LDBL_EXPSIGN(i, d)	\
do {				\
  union ieee_ext_u ge_u;	\
  union ieee_expsign ge_es;     \
  ge_u.extu_ld = (d);		\
  ge_es.s.sign = ge_u.extu_sign;\
  ge_es.s.exp = ge_u.extu_exp;  \
  (i) = ge_es.expsign;          \
} while (0)

#define SET_LDBL_EXPSIGN(d, v)  \
do {                            \
  union ieee_ext_u se_u;        \
  union ieee_expsign se_es;     \
  se_u.extu_ld = (d);           \
  se_es.expsign = (v);          \
  se_u.extu_sign = se_es.s.sign;\
  se_u.extu_exp = se_es.s.exp;  \
  (d) = se_u.extu_ld;           \
} while (0)


#undef GET_HIGH_WORD
#define	GET_HIGH_WORD(i, v)	GET_LDBL_EXPSIGN(i, v)
#undef SET_HIGH_WORD
#define	SET_HIGH_WORD(v, i)	SET_LDBL_EXPSIGN(v, i)



#define	DESW(exp)	(exp)		/* delta expsign word */
#define	ESW(exp)	(MAX_EXP - 1 + (exp))	/* expsign word */
#define	MANT_DIG	LDBL_MANT_DIG
#define	MAX_EXP		LDBL_MAX_EXP

#if LDBL_MANL_SIZE > 32
typedef	uint64_t man_t;
#else
typedef	uint32_t man_t;
#endif

long double
nbhypotl(long double x, long double y)
{
	long double a=x,b=y,t1,t2,y1,y2,w;
	int32_t j,k,ha,hb;

	GET_HIGH_WORD(ha,x);
	ha &= 0x7fff;
	GET_HIGH_WORD(hb,y);
	hb &= 0x7fff;
	if(hb > ha) {a=y;b=x;j=ha; ha=hb;hb=j;} else {a=x;b=y;}
	a = fabsl(a);
	b = fabsl(b);
	if((ha-hb)>DESW(MANT_DIG+7)) {return a+b;} /* x/y > 2**(MANT_DIG+7) */
	k=0;
	if(ha > ESW(MAX_EXP/2-12)) {	/* a>2**(MAX_EXP/2-12) */
	   if(ha >= ESW(MAX_EXP)) {	/* Inf or NaN */
	       man_t manh, manl;
	       /* Use original arg order iff result is NaN; quieten sNaNs. */
	       w = fabsl(x+0.0L)-fabsl(y+0);
	       GET_LDBL_MAN(manh,manl,a);
	       if (manh == LDBL_NBIT && manl == 0) w = a;
	       GET_LDBL_MAN(manh,manl,b);
	       if (hb >= ESW(MAX_EXP) && manh == LDBL_NBIT && manl == 0) w = b;
	       return w;
	   }
	   /* scale a and b by 2**-(MAX_EXP/2+88) */
	   ha -= DESW(MAX_EXP/2+88); hb -= DESW(MAX_EXP/2+88);
	   k += MAX_EXP/2+88;
	   SET_HIGH_WORD(a,ha);
	   SET_HIGH_WORD(b,hb);
	}
	if(hb < ESW(-(MAX_EXP/2-12))) {	/* b < 2**-(MAX_EXP/2-12) */
	    if(hb <= 0) {		/* subnormal b or 0 */
	        man_t manh, manl;
		GET_LDBL_MAN(manh,manl,b);
		if((manh|manl)==0) return a;
		t1=1;
		SET_HIGH_WORD(t1,ESW(MAX_EXP-2));	/* t1=2^(MAX_EXP-2) */
		b *= t1;
		a *= t1;
		k -= MAX_EXP-2;
	    } else {		/* scale a and b by 2^(MAX_EXP/2+88) */
		ha += DESW(MAX_EXP/2+88);
		hb += DESW(MAX_EXP/2+88);
		k -= MAX_EXP/2+88;
		SET_HIGH_WORD(a,ha);
		SET_HIGH_WORD(b,hb);
	    }
	}
    /* medium size a and b */
	w = a-b;
	if (w>b) {
	    t1 = a;
	    union ieee_ext_u uv;
	    uv.extu_ld = t1; uv.extu_fracl = 0; t1 = uv.extu_ld;
	    t2 = a-t1;
	    w  = sqrtl(t1*t1-(b*(-b)-t2*(a+t1)));
	} else {
	    a  = a+a;
	    y1 = b;
	    union ieee_ext_u uv;
	    uv.extu_ld = y1; uv.extu_fracl = 0; y1 = uv.extu_ld;
	    y2 = b - y1;
	    t1 = a;
	    uv.extu_ld = t1; uv.extu_fracl = 0; t1 = uv.extu_ld;
	    t2 = a - t1;
	    w  = sqrtl(t1*y1-(w*(-w)-(t1*y2+t2*b)));
	}
	if(k!=0) {
	    u_int32_t high;
	    t1 = 1.0;
	    GET_HIGH_WORD(high,t1);
	    SET_HIGH_WORD(t1,high+DESW(k));
	    return t1*w;
	} else return w;
}
