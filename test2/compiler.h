#ifndef __COMPILER_H
#define __COMPILER_H

#include "config.h"

#if defined(SDCC)||defined(__SDCC)
#define COMPILER_SDCC
#else
#error Unsupported compiler
#endif

#ifdef COMPILER_SDCC
#define BIT __bit
#define BYTE unsigned char
#define WORD unsigned int
#define DWORD unsigned long
#define DATA __data
#define XDATA __xdata
#define IDATA __idata
#define PDATA __pdata
#define CODE __code
#define DECLARE_SFR(name,addr) __sfr __at(addr) name
#define DECLARE_SFR_BIT(name,addr,bit) __sbit __at(addr+bit) name
#define DECLARE_XSFR(name,addr) __xdata volatile BYTE __at(addr) name
#define DECLARE_XSFR_ARRAY(name,addr,cnt) __xdata volatile BYTE __at(addr) name[cnt]
#endif

#endif
