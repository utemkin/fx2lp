#include "fx2lp.h"
#include <stdio.h>

IMPLEMENT_INT0_ISR
{
    ACK_INT0_ISR;
}

IMPLEMENT_SUDAV_ISR
{
    ACK_SUDAV_ISR;
}

IMPLEMENT_GPIFDONE_ISR
{
    ACK_GPIFDONE_ISR;
}

void putchar(char c)
{
    c=c;
}

void main()
{
    IOA=1;
    printf("This is test\n");
    ENABLE_INT0_ISR;
    ENABLE_SUDAV_ISR;
    ENABLE_GPIFDONE_ISR;
}
