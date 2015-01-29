#ifndef __COMPILER_H
#define __COMPILER_H

#include "config.h"

#if defined(SDCC)||defined(__SDCC)

#define DECLARE_SFR(name,addr) __sfr __at(addr) name
#define DECLARE_SFR_BIT(name,addr,bit) __sbit __at(addr+bit) name
#define DECLARE_XSFR(name,addr) __xdata volatile unsigned char __at(addr) name
#define DECLARE_XSFR_ARRAY(name,addr,cnt) __xdata volatile unsigned char __at(addr) name[cnt]
                                                         
#else

#error Unsupported compiler

#endif

#endif
