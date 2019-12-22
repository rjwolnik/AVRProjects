//***************************************************************************
//! @file $RCSfile: template.c,v $
//!
//! Copyright (c) 2004 Atmel.
//!
//! Please read file license.txt for copyright notice.
//!
//! @brief On-board LEDs routines.
//!
//! These routines need some #define's of "board.h" file.
//!
//! @version $Revision: 1.15 $ $Name:  $ $Id: template.c,v 1.15 2004/06/16 11:21:58 smaincha Exp $
//!
//! @todo
//! @bug
//***************************************************************************

//_____  I N C L U D E S ___________________________________________________

#include "config.h"
#include "led_drv.h"

//_____ M A C R O S ________________________________________________________

//_____ D E F I N I T I O N S ______________________________________________

//_____ D E C L A R A T I O N S ____________________________________________


//***************************************************************************
//  @fn led_init
//!
//! On-board LEDs initialization. Initialize I/O lines for LEDs & clear LEDs. 
//!
//! @warning (none)
//!
//! @param (none)
//!
//! @return (none)
//!
//***************************************************************************
void led_init(void)
{
	// Set direction
	LED_PORT_DIR = 0xFF;
	// Clear LEDs.
	LED_PORT_OUT = 0x00;	
}

//***************************************************************************
//  @fn write_led
//!
//! On-board LEDs writing byte. Write hexa value on LEDs display.
//!
//! @warning (none)
//!
//! @param led_display   Hexa display value
//!
//! @return (none)
//!
//***************************************************************************
void write_led(U8 led_display)
{
	LED_PORT_OUT = led_display;
}

//***************************************************************************
//  @fn swap_nibble_led
//!
//! Swap nibbles of on-board LEDs. Exchange ls-nibble and ms-nibble.
//!
//! @warning (none)
//!
//! @param (none)
//!
//! @return (none)
//!
//***************************************************************************
void swap_nibble_led(void)
{
	LED_PORT_OUT = (LED_PORT_IN << 4) | (LED_PORT_IN >> 4);
}

//***************************************************************************
//  @fn toggle_led_led
//!
//! On-board LEDs toggle. Toggle value of each LED.
//!
//! @warning (none)
//!
//! @param (none)
//!
//! @return (none)
//!
//***************************************************************************
void toggle_led(void)
{
	LED_PORT_IN = 0xFF;
}

//***************************************************************************
//  @fn write_led_number
//!
//! Set or clear one LED of the on-board LEDs. See "Set_led(U8 led_number)"
//! and "Set_led(U8 led_number)" macros.
//!
//! @warning 0 <= "LED number" param <= 7, led_level >=2.
//!
//! @param led_number   Position of the LED.
//! @param led_level    Bool: 1=set, 0=clear.
//!
//! @return range error..
//!          FALSE: led_number >= 8 or led_level >=2,
//!          TRUE:  In range
//!
//***************************************************************************
U8 write_led_number(U8 led_number,Bool led_level)
{
    U8 range_error;
    
    range_error = FALSE;
    if (led_number < 8)
    {
        if (led_level==0)
	    {
	    	range_error = TRUE;
    		LED_PORT_OUT &= ~(1<<led_number);
	    }
	    if (led_level==1)
	    {
	    	range_error = TRUE;
    		LED_PORT_OUT |= (1<<led_number);
	    }
    }
    return range_error;
}
