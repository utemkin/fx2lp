#ifndef __COMPILER_H
#define __COMPILER_H

#include "config.h"

#if defined(SDCC)||defined(__SDCC)

    #define COMPILER_SDCC

#elif defined(__KEIL__)

    #define COMPILER_KEIL

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

#ifdef COMPILER_SDCC  //checked with SDCC mcs51 3.4.0 #8981 (Apr  5 2014)

    #define BIT __bit
    #define BYTE unsigned char
    #define WORD unsigned int
    #define DWORD unsigned long
    #define DATA __data
    #define XDATA __xdata
    #define IDATA __idata
    #define PDATA __pdata
    #define CODE __code
    #define STRINGIFY(s) #s
    #define ATOMIC_INC(direct)      __asm__("inc _" STRINGIFY(direct) "\n") 
    #define ATOMIC_DEC(direct)      __asm__("dec _" STRINGIFY(direct) "\n") 
    #define ATOMIC_AND(direct,data) __asm__("anl _" STRINGIFY(direct) ",#" STRINGIFY(data) "\n") 
    #define ATOMIC_OR(direct,data)  __asm__("orl _" STRINGIFY(direct) ",#" STRINGIFY(data) "\n") 
    #define ATOMIC_XOR(direct,data) __asm__("xrl _" STRINGIFY(direct) ",#" STRINGIFY(data) "\n") 
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
    #define IVT_ISR(name)   __asm__("ljmp _" STRINGIFY(name) "\n"      \
                                    ".ds 5\n");
    #define IVT_AV4         __asm__("ljmp ivect_table4\n"              \
                                    ".ds 5\n");
    #define IVT_AV2         __asm__("ljmp ivect_table2\n"              \
                                    ".ds 5\n");
    #define IVT_NOISR       __asm__("reti\n"                           \
                                    ".ds 7\n");
    #define IVT_END         __asm__("ivect_table_end:\n");             \
                        }
    #define IVT4_START      __asm__(".=_ivect_table+0x80\n"            \
                                    "ivect_table4:\n");
    #define IVT4_ISR(name)  __asm__("ljmp _" STRINGIFY(name) "\n"      \
                                    ".ds 1\n");
    #define IVT4_NOISR      __asm__("reti\n"                           \
                                    ".ds 3\n");
    #define IVT4_END
    #define IVT2_START      __asm__(".=_ivect_table+0x100\n"           \
                                    "ivect_table2:\n");
    #define IVT2_ISR(name)  __asm__("ljmp _" STRINGIFY(name) "\n"      \
                                    ".ds 1\n");
    #define IVT2_NOISR      __asm__("reti\n"                           \
                                    ".ds 3\n");
    #define IVT2_END

#endif

#ifdef COMPILER_KEIL  //checked with KEIL C51 COMPILER V9.53.0.0

    #if !defined(__A51__)&&!defined(__AX51__)

        #define BYTE unsigned char
        #define ATOMIC_AND(direct,data) do{direct=data;}while(0) 
        #define DECLARE_SFR(name,addr) sfr name=addr
        #define DECLARE_SFR_BIT(name,addr,bit) sbit name=((addr)+(bit))
        #define DECLARE_XSFR(name,addr) xdata volatile BYTE name _at_(addr)
        #define DECLARE_XSFR_ARRAY(name,addr,cnt) xdata volatile BYTE name[cnt] _at_(addr)
        #define IMPLEMENT_ISR(name) void name() interrupt 0

    #else

        #define DECLARE_SFR(name,addr)
        #define DECLARE_SFR_BIT(name,addr,bit)
        #define DECLARE_XSFR(name,addr)
        #define DECLARE_XSFR_ARRAY(name,addr,cnt)
        #define DECLARE_ISR(name)

    #endif

#endif

#endif
