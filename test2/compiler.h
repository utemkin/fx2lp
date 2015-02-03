#ifndef __COMPILER_H
#define __COMPILER_H

#include "config.h"

#if defined(SDCC)||defined(__SDCC)

    #define COMPILER_SDCC

#else

    #error Unsupported compiler

#endif

#define BIT0 (0x01)
#define BIT1 (0x02)
#define BIT2 (0x04)
#define BIT3 (0x08)
#define BIT4 (0x10)
#define BIT5 (0x20)
#define BIT6 (0x40)
#define BIT7 (0x80)

#ifdef COMPILER_SDCC  //checked with SDCC 3.4.0 #8981 (Apr  5 2014)

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
    #define DECLARE_SFR_BIT(name,addr,bit) __sbit __at((addr)+(bit)) name
    #define DECLARE_XSFR(name,addr) __xdata volatile BYTE __at(addr) name
    #define DECLARE_XSFR_ARRAY(name,addr,cnt) __xdata volatile BYTE __at(addr) name[cnt]
    #pragma noiv
    #define DECLARE_ISR(name) extern void name() __interrupt
    #define IMPLEMENT_ISR(name) void name() __interrupt
    #define IVT_START   static void ivect() __naked                    \
                        {                                              \
                            __asm__(".area HOME(CODE)\n"               \
                                    ".globl _ivect_table\n"            \
                                    "_ivect_table:\n"                  \
                                    "ljmp ivect_table_end\n");
    #define IVT_ISR(name)   __asm__("ljmp _" #name "\n"                \
                                    ".ds 5\n");
    #define IVT_AV4          __asm__("ljmp ivect_table4\n"             \
                                    ".ds 5\n");
    #define IVT_AV2          __asm__("ljmp ivect_table2\n"             \
                                    ".ds 5\n");
    #define IVT_NOISR       __asm__("reti\n"                           \
                                    ".ds 7\n");
    #define IVT_END         __asm__("ivect_table_end:\n");             \
                        }
    #define IVT4_START      __asm__(".=_ivect_table+0x80\n"            \
                                    "ivect_table4:\n");
    #define IVT4_ISR(name)  __asm__("ljmp _" #name "\n"                \
                                    ".ds 1\n");
    #define IVT4_NOISR      __asm__("reti\n"                           \
                                    ".ds 3\n");
    #define IVT4_END
    #define IVT2_START      __asm__(".=_ivect_table+0x100\n"           \
                                    "ivect_table2:\n");
    #define IVT2_ISR(name)  __asm__("ljmp _" #name "\n"                \
                                    ".ds 1\n");
    #define IVT2_NOISR      __asm__("reti\n"                           \
                                    ".ds 3\n");
    #define IVT2_END

#endif

#endif
