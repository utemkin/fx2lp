#include "fx2lp.h"

void main()
{
    IOA=1;
}

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
