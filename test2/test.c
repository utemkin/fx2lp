#include "fx2lp.h"
#include <stdio.h>

void putchar(char c)
{
}

void main()
{
    IOA=1;
    printf("This is test\n");
}

/*
void my_isr() __interrupt
{
}
*/

//__code BYTE __at(0x3f00) arr[256]={0x02,(WORD)&my_isr};

/*
void my_func() __naked
{
    __asm__(
        "    .area CABS(ABS,CODE)\n"
        "    .org 0x3f80\n"
        "    ljmp _my_isr\n"
    );
}
*/

/*
extern void my_isr() __interrupt 32;

void my_isr() __interrupt 32
{
}

static void my_vector() __naked
{
    __asm
        .area MY_VECTOR (ABS,OVR)
        .org 0x43
	.db #0x02
	.db #0x01
	.db #0x00
    __endasm;
}
*/

/*
SUDAV_ISR
SOF_ISR
SUTOK_ISR
SUSPEND_ISR
USBRESET_ISR
HISPEED_ISR
EP0ACK_ISR
SPARE_ISR
EP0IN _ISR
EP0OUT_ISR
EP1IN _ISR
EP1OUT_ISR
EP2_ISR
EP4_ISR
EP6_ISR
EP8_ISR
IBN_ISR
SPARE_ISR
EP0PING_ISR
EP1PING_ISR
EP2PING_ISR
EP4PING_ISR
EP6PING_ISR
EP8PING_ISR
ERRLIMIT_ISR
SPARE_ISR
SPARE_ISR
SPARE_ISR
EP2ISOERR_ISR
EP2ISOERR_ISR
EP2ISOERR_ISR
EP2ISOERR_ISR

EP2PF_ISR
EP4PF_ISR
EP6PF_ISR
EP8PF_ISR
EP2EF_ISR
EP4EF_ISR
EP6EF_ISR
EP8EF_ISR
EP2FF_ISR
EP4FF_ISR
EP6FF_ISR
EP8FF_ISR
GPIFDONE_ISR
GPIFWF_ISR
*/

void my_isr() __interrupt 55 //reserve 3+8*55+3=446 bytes while 256+(32+14)*4=440 bytes needed
{
}

//#pragma codeseg CABS
void test()
{
}

void(*const func)()=&test;
