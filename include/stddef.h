
#ifndef _C23_STDDEF_H_OVERLAY_
#define _C23_STDDEF_H_OVERLAY_

#include_next <stddef.h>

#define __STDC_VERSION_STDDEF_H__ 202311L

#define unreachable() nbunreachable()

void nbunreachable(void);

#endif
