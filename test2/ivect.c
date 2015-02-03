#include "fx2lp.h"

IVT_START

    //0x0003
    #ifdef USE_INT0_ISR
        IVT_ISR(INT0_ISR)
    #else
        IVT_NOISR
    #endif

    //0x000b
    #ifdef USE_TIMER0_ISR
        IVT_ISR(TIMER0_ISR)
    #else
        IVT_NOISR
    #endif

    //0x0013
    #ifdef USE_INT1_ISR
        IVT_ISR(INT1_ISR)
    #else
        IVT_NOISR
    #endif

    //0x001b
    #ifdef USE_TIMER1_ISR
        IVT_ISR(TIMER1_ISR)
    #else
        IVT_NOISR
    #endif

    //0x0023
    #ifdef USE_USART0_ISR
        IVT_ISR(USART0_ISR)
    #else
        IVT_NOISR
    #endif

    //0x002b
    #ifdef USE_TIMER2_ISR
        IVT_ISR(TIMER2_ISR)
    #else
        IVT_NOISR
    #endif

    //0x0033
    #ifdef USE_WAKEUP_ISR
        IVT_ISR(WAKEUP_ISR)
    #else
        IVT_NOISR
    #endif

    //0x003b
    #ifdef USE_USART1_ISR
        IVT_ISR(USART1_ISR)
    #else
        IVT_NOISR
    #endif

    //0x0043
    #ifdef USE_INT2AV
        IVT_AV2
    #else
        IVT_NOISR
    #endif

    //0x004b
    #ifdef USE_I2C_ISR
        IVT_ISR(I2C_ISR)
    #else
        IVT_NOISR
    #endif

    //0x0053
    #ifdef USE_INT4AV
        IVT_AV4
    #elif defined(USE_INT4_ISR)
        IVT_ISR(INT4_ISR)
    #else
        IVT_NOISR
    #endif

    //0x005b
    #ifdef USE_INT5_ISR
        IVT_ISR(INT5_ISR)
    #else
        IVT_NOISR
    #endif

    //0x0063
    #ifdef USE_INT6_ISR
        IVT_ISR(INT6_ISR)
    #else
        IVT_NOISR
    #endif

    #if defined(USE_INT2AV)||defined(USE_INT4AV)

        IVT4_START

            // 0x80
            #ifdef USE_EP2PF_ISR
                IVT4_ISR(EP2PF_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0x84
            #ifdef USE_EP4PF_ISR
                IVT4_ISR(EP4PF_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0x88
            #ifdef USE_EP6PF_ISR
                IVT4_ISR(EP6PF_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0x8c
            #ifdef USE_EP8PF_ISR
                IVT4_ISR(EP8PF_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0x90
            #ifdef USE_EP2EF_ISR
                IVT4_ISR(EP2EF_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0x94
            #ifdef USE_EP4EF_ISR
                IVT4_ISR(EP4EF_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0x98
            #ifdef USE_EP6EF_ISR
                IVT4_ISR(EP6EF_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0x9c
            #ifdef USE_EP8EF_ISR
                IVT4_ISR(EP8EF_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0xa0
            #ifdef USE_EP2FF_ISR
                IVT4_ISR(EP2FF_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0xa4
            #ifdef USE_EP4FF_ISR
                IVT4_ISR(EP4FF_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0xa8
            #ifdef USE_EP6FF_ISR
                IVT4_ISR(EP6FF_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0xac
            #ifdef USE_EP8FF_ISR
                IVT4_ISR(EP8FF_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0xb0
            #ifdef USE_GPIFDONE_ISR
                IVT4_ISR(GPIFDONE_ISR)
            #else
                IVT4_NOISR
            #endif

            // 0xb4
            #ifdef USE_GPIFWF_ISR
                IVT4_ISR(GPIFWF_ISR)
            #else
                IVT4_NOISR
            #endif

        IVT4_END

    #endif

    #ifdef USE_INT2AV

        IVT2_START

            // 0x00
            #ifdef USE_SUDAV_ISR
                IVT2_ISR(SUDAV_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x04
            #ifdef USE_SOF_ISR
                IVT2_ISR(SOF_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x08
            #ifdef USE_SUTOK_ISR
                IVT2_ISR(SUTOK_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x0c
            #ifdef USE_SUSPEND_ISR
                IVT2_ISR(SUSPEND_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x10
            #ifdef USE_USBRESET_ISR
                IVT2_ISR(USBRESET_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x14
            #ifdef USE_HISPEED_ISR
                IVT2_ISR(HISPEED_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x18
            #ifdef USE_EP0ACK_ISR
                IVT2_ISR(EP0ACK_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x1c
            IVT2_NOISR

            // 0x20
            #ifdef USE_EP0IN_ISR
                IVT2_ISR(EP0IN_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x24
            #ifdef USE_EP0OUT_ISR
                IVT2_ISR(EP0OUT_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x28
            #ifdef USE_EP1IN_ISR
                IVT2_ISR(EP1IN_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x2c
            #ifdef USE_EP1OUT_ISR
                IVT2_ISR(EP1OUT_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x30
            #ifdef USE_EP2_ISR
                IVT2_ISR(EP2_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x34
            #ifdef USE_EP4_ISR
                IVT2_ISR(EP4_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x38
            #ifdef USE_EP6_ISR
                IVT2_ISR(EP6_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x3c
            #ifdef USE_EP8_ISR
                IVT2_ISR(EP8_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x40
            #ifdef USE_IBN_ISR
                IVT2_ISR(IBN_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x44
            IVT2_NOISR

            // 0x48
            #ifdef USE_EP0PING_ISR
                IVT2_ISR(EP0PING_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x4c
            #ifdef USE_EP1PING_ISR
                IVT2_ISR(EP1PING_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x50
            #ifdef USE_EP2PING_ISR
                IVT2_ISR(EP2PING_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x54
            #ifdef USE_EP4PING_ISR
                IVT2_ISR(EP4PING_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x58
            #ifdef USE_EP6PING_ISR
                IVT2_ISR(EP6PING_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x5c
            #ifdef USE_EP8PING_ISR
                IVT2_ISR(EP8PING_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x60
            #ifdef USE_ERRLIMIT_ISR
                IVT2_ISR(ERRLIMIT_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x64
            IVT2_NOISR

            // 0x68
            IVT2_NOISR

            // 0x6c
            IVT2_NOISR

            // 0x70
            #ifdef USE_EP2ISOERR_ISR
                IVT2_ISR(EP2ISOERR_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x74
            #ifdef USE_EP2ISOERR_ISR
                IVT2_ISR(EP2ISOERR_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x78
            #ifdef USE_EP2ISOERR_ISR
                IVT2_ISR(EP2ISOERR_ISR)
            #else
                IVT2_NOISR
            #endif

            // 0x7c
            #ifdef USE_EP2ISOERR_ISR
                IVT2_ISR(EP2ISOERR_ISR)
            #else
                IVT2_NOISR
            #endif

        IVT2_END

    #endif

IVT_END
