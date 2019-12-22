//******************************************************************************
//! @file $RCSfile: uart_drv.c,v $
//!
//! Copyright (c) 2006 Atmel.
//!
//! Use of this program is subject to Atmel's End User License Agreement.
//! Please read file license.txt for copyright notice.
//!
//! @brief This file contains the low level functions (drivers) of:
//!             - Both UARTs
//!             - for AT90CAN128/64/32
//!
//! This file can be parsed by Doxygen for automatic documentation generation.
//! This file has been validated with AVRStudio-412462/WinAVR-20060125.
//!
//! @version $Revision: 3.10 $ $Name: jtellier $
//!
//! @todo
//! @bug
//******************************************************************************


//_____ I N C L U D E S ________________________________________________________
#include "config.h"
#include "uart_drv.h"
#include "timer16_drv.h"

//_____ D E F I N I T I O N S __________________________________________________

//_____ D E C L A R A T I O N S ________________________________________________
#if (USE_UART ==  BOTH_UART)
    U8 uart_selected;
#endif

#if ((UART_BAUDRATE == VARIABLE_UART_BAUDRATE) || (UART_BAUDRATE == UART_AUTOBAUD))
    #ifndef USE_TIMER16
        #error You must define USE_TIMER16 to TIMER16_1 or TIMER16_3 or BOTH_TIMER16 in "config.h" file
    #elif (USE_TIMER16 ==  BOTH_TIMER16)
        U8 timer16_selected;
    #endif
#endif

//_____ F U N C T I O N S ______________________________________________________

#if ((UART_BAUDRATE == VARIABLE_UART_BAUDRATE) || (UART_BAUDRATE == UART_AUTOBAUD))
//------------------------------------------------------------------------------
//  @fn uart_set_baudrate
//!
//! This function programs the UBRRH register of both the UARTs from the
//! value passed as parameter or from an automatic timing detection if
//! there is some communication (activity) on the serial link. This function
//! is called by "Uart_set_baudrate(baudrate)" macro.
//! The function rounds to nearest the division result (i.e. FOSC/BAUDRATE).
//!
//! @warning Lower limit is 300 Bauds per MHz (ex: at 8MHz, lower limit
//!          is 2400 Bauds).
//!          Writting UBBR_L triggers an immediate update of the baud
//!          rate prescaler.
//!
//! @param  !=0: baudrate value
//!         ==0: automatic baudrate detection
//!
//! @return Baudrate Status
//!         ==0: baudrate configuration failed
//!         ==1: baudrate performed
//------------------------------------------------------------------------------
U8 uart_set_baudrate (U32 baudrate)
{
    U16 t_meas_0, t_meas_1, t_meas_2, t_meas_3, t_meas_4;
    U16 t_min, t_max;

    if (baudrate != 0)
    {
        // UBRRN Value (rounded to nearest division) with U2Xn=1
        t_meas_4 = (U16)(( (((((U32)FOSC*1000)<<1)/((U32)baudrate*8))+1)>>1)-1);
    }
    else    // Wait for only one "U" ASCII Char (0x55)
            // Autobaud using "USE_TIMER16" definition
    {
        // Autobaud set-up
        Uart_rx_in_pu_on();     // RxD in input + pull up
        Uart_tx_in_pu_on();     // TxD in input + pull up
        Timer16_clear();        // Flush, Disable and Reset TIMER16

        // Wait for falling edge of SOF.
        while (Uart_rx_get_data()   == 0);  // Wait for RxD=1
        while (Uart_rx_get_data()   != 0);  // Wait for RxD=0

        // SOF Detected
        Timer16_set_clock(TIMER16_CLKIO_BY_1);

        // SOF + bit[0] Measurement. Read 3 times to remove overshoots.
        while (Uart_rx_get_3_data() == 0);  // Wait for RxD=1
        while (Uart_rx_get_data()   != 0);  // Wait for RxD=0
        //t_meas_0 = TCNT3;
        t_meas_0  =  Timer16_get_counter_low();
        t_meas_0 |= (Timer16_get_counter_high() << 8 );

        // SOF + bit[0:2] Measurement. Read 3 times to remove overshoots.
        while (Uart_rx_get_3_data() == 0);  // Wait for RxD=1
        while (Uart_rx_get_data()   != 0);  // Wait for RxD=0
        t_meas_1  =  Timer16_get_counter_low();
        t_meas_1 |= (Timer16_get_counter_high() << 8 );

        // SOF + bit[0:4] Measurement. Read 3 times to remove overshoots.
        while (Uart_rx_get_3_data() == 0);  // Wait for RxD=1
        while (Uart_rx_get_data()   != 0);  // Wait for RxD=0
        t_meas_2  =  Timer16_get_counter_low();
        t_meas_2 |= (Timer16_get_counter_high() << 8 );

        // SOF + bit[0:6] Measurement. Read 3 times to remove overshoots.
        while (Uart_rx_get_3_data() == 0);  // Wait for RxD=1
        while (Uart_rx_get_data()   != 0);  // Wait for RxD=0
        t_meas_3  =  Timer16_get_counter_low();
        t_meas_3 |= (Timer16_get_counter_high() << 8 );

        // SOF + bit[0:7] Measurement. Only 1 read because looking for rising edge.
        while (Uart_rx_get_data()   == 0);  // Wait for RxD=1
        t_meas_4  =  Timer16_get_counter_low();
        t_meas_4 |= (Timer16_get_counter_high() << 8 );

        // End of Frame
        Timer16_off();
        Uart_rx_in_pu_off();     // RxD in input no pull-up
        Uart_tx_in_pu_off();     // TxD in input no pull-up

        // 1-bit (last bit) measurement
        t_meas_4 = t_meas_4 - t_meas_3;     // Bit[7]   length
        // 2-bit measurements
        t_meas_3 = t_meas_3 - t_meas_2;     // Bit[5:6] length
        t_meas_2 = t_meas_2 - t_meas_1;     // Bit[3:4] length
        t_meas_1 = t_meas_1 - t_meas_0;     // Bit[1:2] length
        // t_meas_0 is already 2-bit length

        // Verification if each couple of bits has an length error
        // less than 1/4 (2*1/8) of Bit[7] length
        t_min =  (2* t_meas_4) - (t_meas_4 >> 2);
        t_max =  (2* t_meas_4) + (t_meas_4 >> 2);
        if ((t_meas_0 > t_max) || (t_meas_0 < t_min)) return 0;
        if ((t_meas_1 > t_max) || (t_meas_1 < t_min)) return 0;
        if ((t_meas_2 > t_max) || (t_meas_2 < t_min)) return 0;
        if ((t_meas_3 > t_max) || (t_meas_3 < t_min)) return 0;

        // UBRRN Value (rounded to nearest division) with U2Xn=1
        t_meas_4  = (((((t_meas_0 + t_meas_1 + t_meas_2 + t_meas_3 ) << 1) >> 6) + 1) >> 1) - 1;
    }
    #if (USE_UART ==  UART_0)
        UBRR0H  = (U8)((t_meas_4)>>8);
        UBRR0L  = (U8) (t_meas_4)    ;
        UCSR0A |=  (1<<U2X0);
    #elif (USE_UART ==  UART_1)
        UBRR1H  = (U8)((t_meas_4)>>8);
        UBRR1L  = (U8) (t_meas_4)    ;
        UCSR1A |=  (1<<U2X1);
    #elif (USE_UART ==  BOTH_UART)
        if (uart_selected == UART_0)
        {
            UBRR0H  = (U8)((t_meas_4)>>8);
            UBRR0L  = (U8) (t_meas_4)    ;
            UCSR0A |=  (1<<U2X0);
        }
        else
        {
            UBRR1H  = (U8)((t_meas_4)>>8);
            UBRR1L  = (U8) (t_meas_4)    ;
            UCSR1A |=  (1<<U2X1);
        }
    #   else
    #       error USE_UART definition is not referenced in "uart_drv.h" file
    #endif
    
    return 1;
}

#endif





















