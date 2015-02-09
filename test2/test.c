#include "fx2lp.h"
#include <stdio.h>

BIT my_bit;
BYTE my_byte;
WORD my_word;
DWORD my_dword;

DATA BYTE my_data;
//XDATA BYTE my_xdata;
IDATA BYTE my_idata;
PDATA BYTE my_pdata;
CODE BYTE my_code=1;

void atomic()
{
    ATOMIC_INC(IOA);
    ATOMIC_DEC(IOA);
    ATOMIC_AND(IOA,~0x80);
    ATOMIC_OR(IOA,0x80);
    ATOMIC_XOR(IOA,1);
    NOP;
}

BIT test_and_clear()
{
    return ATOMIC_TEST_AND_CLEAR(PA1);
}

#ifdef USE_INT0_ISR
    IMPLEMENT_INT0_ISR
    {
        SET_PRIO_HIGH_INT0_ISR;
        SET_PRIO_LOW_INT0_ISR;
        ENABLE_INT0_ISR;
        DISABLE_INT0_ISR;
        ACK_INT0_ISR;
    }
#endif

#ifdef USE_TIMER0_ISR
    IMPLEMENT_TIMER0_ISR
    {
        SET_PRIO_HIGH_TIMER0_ISR;
        SET_PRIO_LOW_TIMER0_ISR;
        ENABLE_TIMER0_ISR;
        DISABLE_TIMER0_ISR;
        ACK_TIMER0_ISR;
    }
#endif

#ifdef USE_INT1_ISR
    IMPLEMENT_INT1_ISR
    {
        SET_PRIO_HIGH_INT1_ISR;
        SET_PRIO_LOW_INT1_ISR;
        ENABLE_INT1_ISR;
        DISABLE_INT1_ISR;
        ACK_INT1_ISR;
    }
#endif

#ifdef USE_TIMER1_ISR
    IMPLEMENT_TIMER1_ISR
    {
        SET_PRIO_HIGH_TIMER1_ISR;
        SET_PRIO_LOW_TIMER1_ISR;
        ENABLE_TIMER1_ISR;
        DISABLE_TIMER1_ISR;
        ACK_TIMER1_ISR;
    }
#endif

#ifdef USE_USART0_ISR
    IMPLEMENT_USART0_ISR
    {
        SET_PRIO_HIGH_USART0_ISR;
        SET_PRIO_LOW_USART0_ISR;
        ENABLE_USART0_ISR;
        DISABLE_USART0_ISR;
        ACK_USART0_ISR;
    }
#endif

#ifdef USE_TIMER2_ISR
    IMPLEMENT_TIMER2_ISR
    {
        SET_PRIO_HIGH_TIMER2_ISR;
        SET_PRIO_LOW_TIMER2_ISR;
        ENABLE_TIMER2_ISR;
        DISABLE_TIMER2_ISR;
        ACK_TIMER2_ISR;
    }
#endif

#ifdef USE_WAKEUP_ISR
    IMPLEMENT_WAKEUP_ISR
    {
        ENABLE_WAKEUP_ISR;
        DISABLE_WAKEUP_ISR;
        ACK_WAKEUP_ISR;
    }
#endif

#ifdef USE_USART1_ISR
    IMPLEMENT_USART1_ISR
    {
        SET_PRIO_HIGH_USART1_ISR;
        SET_PRIO_LOW_USART1_ISR;
        ENABLE_USART1_ISR;
        DISABLE_USART1_ISR;
        ACK_USART1_ISR;
    }
#endif

#ifdef USE_I2C_ISR
    IMPLEMENT_I2C_ISR
    {
        SET_PRIO_HIGH_I2C_ISR;
        SET_PRIO_LOW_I2C_ISR;
        ENABLE_I2C_ISR;
        DISABLE_I2C_ISR;
        ACK_I2C_ISR;
    }
#endif

#ifdef USE_INT4_ISR
    IMPLEMENT_INT4_ISR
    {
        SET_PRIO_HIGH_INT4_ISR;
        SET_PRIO_LOW_INT4_ISR;
        ENABLE_INT4_ISR;
        DISABLE_INT4_ISR;
        ACK_INT4_ISR;
    }
#endif

#ifdef USE_INT5_ISR
    IMPLEMENT_INT5_ISR
    {
        SET_PRIO_HIGH_INT5_ISR;
        SET_PRIO_LOW_INT5_ISR;
        ENABLE_INT5_ISR;
        DISABLE_INT5_ISR;
        ACK_INT5_ISR;
    }
#endif

#ifdef USE_INT6_ISR
    IMPLEMENT_INT6_ISR
    {
        SET_PRIO_HIGH_INT6_ISR;
        SET_PRIO_LOW_INT6_ISR;
        ENABLE_INT6_ISR;
        DISABLE_INT6_ISR;
        ACK_INT6_ISR;
    }
#endif

#ifdef USE_SUDAV_ISR
    IMPLEMENT_SUDAV_ISR
    {
        ENABLE_SUDAV_ISR;
        DISABLE_SUDAV_ISR;
        ACK_SUDAV_ISR;
    }
#endif

#ifdef USE_SOF_ISR
    IMPLEMENT_SOF_ISR
    {
        ENABLE_SOF_ISR;
        DISABLE_SOF_ISR;
        ACK_SOF_ISR;
    }
#endif

#ifdef USE_SUTOK_ISR
    IMPLEMENT_SUTOK_ISR
    {
        ENABLE_SUTOK_ISR;
        DISABLE_SUTOK_ISR;
        ACK_SUTOK_ISR;
    }
#endif

#ifdef USE_SUSPEND_ISR
    IMPLEMENT_SUSPEND_ISR
    {
        ENABLE_SUSPEND_ISR;
        DISABLE_SUSPEND_ISR;
        ACK_SUSPEND_ISR;
    }
#endif

#ifdef USE_USBRESET_ISR
    IMPLEMENT_USBRESET_ISR
    {
        ENABLE_USBRESET_ISR;
        DISABLE_USBRESET_ISR;
        ACK_USBRESET_ISR;
    }
#endif

#ifdef USE_HISPEED_ISR
    IMPLEMENT_HISPEED_ISR
    {
        ENABLE_HISPEED_ISR;
        DISABLE_HISPEED_ISR;
        ACK_HISPEED_ISR;
    }
#endif

#ifdef USE_EP0ACK_ISR
    IMPLEMENT_EP0ACK_ISR
    {
        ENABLE_EP0ACK_ISR;
        DISABLE_EP0ACK_ISR;
        ACK_EP0ACK_ISR;
    }
#endif

#ifdef USE_EP0IN_ISR
    IMPLEMENT_EP0IN_ISR
    {
        ENABLE_EP0IN_ISR;
        DISABLE_EP0IN_ISR;
        ACK_EP0IN_ISR;
    }
#endif

#ifdef USE_EP0OUT_ISR
    IMPLEMENT_EP0OUT_ISR
    {
        ENABLE_EP0OUT_ISR;
        DISABLE_EP0OUT_ISR;
        ACK_EP0OUT_ISR;
    }
#endif

#ifdef USE_EP1IN_ISR
    IMPLEMENT_EP1IN_ISR
    {
        ENABLE_EP1IN_ISR;
        DISABLE_EP1IN_ISR;
        ACK_EP1IN_ISR;
    }
#endif

#ifdef USE_EP1OUT_ISR
    IMPLEMENT_EP1OUT_ISR
    {
        ENABLE_EP1OUT_ISR;
        DISABLE_EP1OUT_ISR;
        ACK_EP1OUT_ISR;
    }
#endif

#ifdef USE_EP2_ISR
    IMPLEMENT_EP2_ISR
    {
        ENABLE_EP2_ISR;
        DISABLE_EP2_ISR;
        ACK_EP2_ISR;
    }
#endif

#ifdef USE_EP4_ISR
    IMPLEMENT_EP4_ISR
    {
        ENABLE_EP4_ISR;
        DISABLE_EP4_ISR;
        ACK_EP4_ISR;
    }
#endif

#ifdef USE_EP6_ISR
    IMPLEMENT_EP6_ISR
    {
        ENABLE_EP6_ISR;
        DISABLE_EP6_ISR;
        ACK_EP6_ISR;
    }
#endif

#ifdef USE_EP8_ISR
    IMPLEMENT_EP8_ISR
    {
        ENABLE_EP8_ISR;
        DISABLE_EP8_ISR;
        ACK_EP8_ISR;
    }
#endif

#ifdef USE_IBN_ISR
    IMPLEMENT_IBN_ISR
    {
        ENABLE_IBN_ISR;
        DISABLE_IBN_ISR;
        ACK_IBN_ISR;
    }
#endif

#ifdef USE_EP0PING_ISR
    IMPLEMENT_EP0PING_ISR
    {
        ENABLE_EP0PING_ISR;
        DISABLE_EP0PING_ISR;
        ACK_EP0PING_ISR;
    }
#endif

#ifdef USE_EP1PING_ISR
    IMPLEMENT_EP1PING_ISR
    {
        ENABLE_EP1PING_ISR;
        DISABLE_EP1PING_ISR;
        ACK_EP1PING_ISR;
    }
#endif

#ifdef USE_EP2PING_ISR
    IMPLEMENT_EP2PING_ISR
    {
        ENABLE_EP2PING_ISR;
        DISABLE_EP2PING_ISR;
        ACK_EP2PING_ISR;
    }
#endif

#ifdef USE_EP4PING_ISR
    IMPLEMENT_EP4PING_ISR
    {
        ENABLE_EP4PING_ISR;
        DISABLE_EP4PING_ISR;
        ACK_EP4PING_ISR;
    }
#endif

#ifdef USE_EP6PING_ISR
    IMPLEMENT_EP6PING_ISR
    {
        ENABLE_EP6PING_ISR;
        DISABLE_EP6PING_ISR;
        ACK_EP6PING_ISR;
    }
#endif

#ifdef USE_EP8PING_ISR
    IMPLEMENT_EP8PING_ISR
    {
        ENABLE_EP8PING_ISR;
        DISABLE_EP8PING_ISR;
        ACK_EP8PING_ISR;
    }
#endif

#ifdef USE_ERRLIMIT_ISR
    IMPLEMENT_ERRLIMIT_ISR
    {
        ENABLE_ERRLIMIT_ISR;
        DISABLE_ERRLIMIT_ISR;
        ACK_ERRLIMIT_ISR;
    }
#endif

#ifdef USE_EP2ISOERR_ISR
    IMPLEMENT_EP2ISOERR_ISR
    {
        ENABLE_EP2ISOERR_ISR;
        DISABLE_EP2ISOERR_ISR;
        ACK_EP2ISOERR_ISR;
    }
#endif

#ifdef USE_EP4ISOERR_ISR
    IMPLEMENT_EP4ISOERR_ISR
    {
        ENABLE_EP4ISOERR_ISR;
        DISABLE_EP4ISOERR_ISR;
        ACK_EP4ISOERR_ISR;
    }
#endif

#ifdef USE_EP6ISOERR_ISR
    IMPLEMENT_EP6ISOERR_ISR
    {
        ENABLE_EP6ISOERR_ISR;
        DISABLE_EP6ISOERR_ISR;
        ACK_EP6ISOERR_ISR;
    }
#endif

#ifdef USE_EP8ISOERR_ISR
    IMPLEMENT_EP8ISOERR_ISR
    {
        ENABLE_EP8ISOERR_ISR;
        DISABLE_EP8ISOERR_ISR;
        ACK_EP8ISOERR_ISR;
    }
#endif

#ifdef USE_EP2PF_ISR
    IMPLEMENT_EP2PF_ISR
    {
        ENABLE_EP2PF_ISR;
        DISABLE_EP2PF_ISR;
        ACK_EP2PF_ISR;
    }
#endif

#ifdef USE_EP4PF_ISR
    IMPLEMENT_EP4PF_ISR
    {
        ENABLE_EP4PF_ISR;
        DISABLE_EP4PF_ISR;
        ACK_EP4PF_ISR;
    }
#endif

#ifdef USE_EP6PF_ISR
    IMPLEMENT_EP6PF_ISR
    {
        ENABLE_EP6PF_ISR;
        DISABLE_EP6PF_ISR;
        ACK_EP6PF_ISR;
    }
#endif

#ifdef USE_EP8PF_ISR
    IMPLEMENT_EP8PF_ISR
    {
        ENABLE_EP8PF_ISR;
        DISABLE_EP8PF_ISR;
        ACK_EP8PF_ISR;
    }
#endif

#ifdef USE_EP2EF_ISR
    IMPLEMENT_EP2EF_ISR
    {
        ENABLE_EP2EF_ISR;
        DISABLE_EP2EF_ISR;
        ACK_EP2EF_ISR;
    }
#endif

#ifdef USE_EP4EF_ISR
    IMPLEMENT_EP4EF_ISR
    {
        ENABLE_EP4EF_ISR;
        DISABLE_EP4EF_ISR;
        ACK_EP4EF_ISR;
    }
#endif

#ifdef USE_EP6EF_ISR
    IMPLEMENT_EP6EF_ISR
    {
        ENABLE_EP6EF_ISR;
        DISABLE_EP6EF_ISR;
        ACK_EP6EF_ISR;
    }
#endif

#ifdef USE_EP8EF_ISR
    IMPLEMENT_EP8EF_ISR
    {
        ENABLE_EP8EF_ISR;
        DISABLE_EP8EF_ISR;
        ACK_EP8EF_ISR;
    }
#endif

#ifdef USE_EP2FF_ISR
    IMPLEMENT_EP2FF_ISR
    {
        ENABLE_EP2FF_ISR;
        DISABLE_EP2FF_ISR;
        ACK_EP2FF_ISR;
    }
#endif

#ifdef USE_EP4FF_ISR
    IMPLEMENT_EP4FF_ISR
    {
        ENABLE_EP4FF_ISR;
        DISABLE_EP4FF_ISR;
        ACK_EP4FF_ISR;
    }
#endif

#ifdef USE_EP6FF_ISR
    IMPLEMENT_EP6FF_ISR
    {
        ENABLE_EP6FF_ISR;
        DISABLE_EP6FF_ISR;
        ACK_EP6FF_ISR;
    }
#endif

#ifdef USE_EP8FF_ISR
    IMPLEMENT_EP8FF_ISR
    {
        ENABLE_EP8FF_ISR;
        DISABLE_EP8FF_ISR;
        ACK_EP8FF_ISR;
    }
#endif

#ifdef USE_GPIFDONE_ISR
    IMPLEMENT_GPIFDONE_ISR
    {
        ENABLE_GPIFDONE_ISR;
        DISABLE_GPIFDONE_ISR;
        ACK_GPIFDONE_ISR;
    }
#endif

#ifdef USE_GPIFWF_ISR
    IMPLEMENT_GPIFWF_ISR
    {
        ENABLE_GPIFWF_ISR;
        DISABLE_GPIFWF_ISR;
        ACK_GPIFWF_ISR;
    }
#endif

//void putchar(char c)
//{
//    c=c;
//}

void main()
{
#ifdef USE_INT2AV
    SETUP_INT2AV;
    SET_PRIO_HIGH_INT2AV;
    SET_PRIO_LOW_INT2AV;
#endif
#ifdef USE_INT4AV
    SETUP_INT4AV;
    SET_PRIO_HIGH_INT4AV;
    SET_PRIO_LOW_INT4AV;
#endif

    atomic();
    test_and_clear();
    my_data=my_code;

//    printf("This is test\n");
}
