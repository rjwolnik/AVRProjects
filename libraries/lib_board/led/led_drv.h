//***************************************************************************
//! @file $RCSfile: template.h,v $
//!
//! Copyright (c) 2004 Atmel.
//!
//! Please read file license.txt for copyright notice.
//!
//! @brief On-board LEDs include file.
//!
//! @version $Revision: 1.13 $ $Name:  $ $Id: template.h,v 1.13 2004/06/16 11:21:58 smaincha Exp $
//!
//! @todo
//! @bug
//***************************************************************************

#ifndef _LED_DRV_
#define _LED_DRV_

//_____ I N C L U D E S ____________________________________________________

#include "config.h"

//_____ D E F I N I T I O N S ______________________________________________

//_____ M A C R O S ________________________________________________________

//***************************************************************************
//! Set LED. Setting LED means ligh "ON" a LED referenced by its number.
//!
//! @param led_number   Position of the LED.
//***************************************************************************
#define Set_led(led_number) write_led_number(led_number,1)

//***************************************************************************
//! Clear LED. Clearing LED means ligh "OFF" a LED referenced by its number.
//!
//! @param led_number   Position of the LED.
//***************************************************************************
#define Clr_led(led_number) write_led_number(led_number,0)

//_____ D E C L A R A T I O N S ____________________________________________

//_____ P R O T O T Y P E S ________________________________________________

extern void led_init(void);
extern void toggle_led(void);
extern void swap_nibble_led(void);
extern void write_led(U8 led_display);
extern U8   write_led_number(U8 led_number, Bool led_level);
	
//***************************************************************************

#endif  // _LED_DRV_

