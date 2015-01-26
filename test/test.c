#include <fx2macros.h>
#include <fx2ints.h>
#include <autovector.h>
#include <delay.h>

void stall3000cycles()
{
    __asm
        mov a,#249
    1$:
        ljmp 2$	    ;4 cycles
    2$:
        ljmp 3$     ;4 cycles
    3$:
        dec a       ;1 cycle
        jnz 1$      ;3 cycles
                    ;total loop cycles=12
                    ;total cycles including lcall/ret=12*249+4+4+2=2998
    __endasm;
}

void delay1ms()
{
// each cycle takes 4 clocks
// so to obtain 1ms delay need to stall:
//    3000 cycles @ 12MHz
//    6000 cycles @ 24MHz
//   12000 cycles @ 48MHz
    switch(CPUFREQ)
    {
    case CLK_48M:
        stall3000cycles();
        stall3000cycles();
    case CLK_24M:
        stall3000cycles();
    default:
        stall3000cycles();
        break;
    }
}

void delay(WORD millis)
{
    while(millis)
    {
        delay1ms();
        --millis;
    }
}

void main()
{
    SETCPUFREQ(CLK_48M);
    OEA|=bmBIT0;
    for(;;)
    {
        PA0=1;
//        delay(1);	//889us
        delay(1);
        PA0=0;
//        delay(1);
        delay(1);
    }
}
