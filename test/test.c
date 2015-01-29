#include <fx2macros.h>
#include <fx2ints.h>
//#include <autovector.h>
#include <delay.h>
#include <stdio.h>

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





enum
{
    UART_12_4800=256-208,       //CLKOUT/12
    UART_12_9600=256-208/2,     //CLKOUT/12
    UART_12_19200=256-208/4,    //CLKOUT/12
    UART_12_14400=256-208,      //CLKOUT/4
    UART_12_28800=256-208/2,    //CLKOUT/4
    UART_12_57600=256-208/4,    //CLKOUT/4

    UART_24_9600=256-208,       //CLKOUT/12
    UART_24_19200=256-208/2,    //CLKOUT/12
    UART_24_38400=256-208/4,    //CLKOUT/12
    UART_24_28800=256-208,      //CLKOUT/4
    UART_24_57600=256-208/2,    //CLKOUT/4
    UART_24_115200=256-208/4,   //CLKOUT/4

    UART_48_19200=256-208,      //CLKOUT/12
    UART_48_38400=256-208/2,    //CLKOUT/12
    UART_48_57600=256-208,      //CLKOUT/4
    UART_48_115200=256-208/2,   //CLKOUT/4
    UART_48_230400=256-208/4    //CLKOUT/4
};



volatile static __bit sflag=0;
volatile static char sdata;

void putchar(char c)
{
    while(sflag!=0);
    sdata=c;
    sflag=1;
}

//230400b/s maximum
void timer0_isr() __interrupt TF0_ISR
{
    static __bit next=1;
    static BYTE state=0;
    static BYTE data;
    PA0=next;
    switch(state)
    {
    case 0:
        if(sflag!=1)
        {
            return;
        }
        data=sdata;
        sflag=0;
        next=0;         //start bit
        break;
    case 9:
        next=1;      	//stop bit
        state=0;
        return;
    default:
        next=data&1;    //data bit
        data>>=1;
        break;
    }
    ++state;
}

void main()
{
    SETCPUFREQ(CLK_48M);
    CKCON&=7;            	//zero wait states

    CKCON|=bmBIT3;              //T0M=1 (use CLKOUT/4 as TIMER0 clock)
    TMOD=(TMOD&0xf)|bmBIT1;     //TIMER0 mode 2
    TH0=256-208/4;                //TIMER0 reload register
    TL0=TH0;                    //TIMER0 initial counter
    TR0=1;                      //enable TIMER0 counting
    ENABLE_TIMER0();
    EA=1;                       //enable interrupts

    PA0=1;
    OEA|=bmBIT0;

        printf("This is test\n");
    for(;;)
    {
//        PA0=1;
//        delay(1);	//889us
//        delay(1);
//        PA0=0;
//        delay(1);
//        delay(1);
    }
}
