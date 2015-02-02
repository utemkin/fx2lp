#define COMPILE_FX2LP
#include "fx2lp.h"

#if defined(USE_INT2AV)
DECLARE_XSFR(INT2AV_ISR,0x0100);
#endif

#if defined(USE_INT4AV)
DECLARE_XSFR(INT4AV_ISR,0x0100);
#endif
