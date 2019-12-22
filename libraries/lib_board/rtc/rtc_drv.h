//***************************************************************************
//! @file $RCSfile: rtc_drv.h,v $
//!
//! Copyright (c) 2005 Atmel.
//!
//! Please read file license.txt for copyright notice.
//!
//! @brief RTC (Real Time Counter) include file.
//!
//! @version $Revision: 2.00 $ $Name: jtellier $ 
//!
//! @todo
//! @bug
//***************************************************************************

#ifndef _RTC_DRV_H_
#define _RTC_DRV_H_

//_____ I N C L U D E S ____________________________________________________

//_____ D E F I N I T I O N S ______________________________________________

#ifndef RTC_TIMER
#  error  You must define RTC_TIMER in "board.h" file
#endif
#ifndef RTC_CLOCK
#  error  You must define RTC_CLOCK in "board.h" file
#endif
#ifndef FOSC
#  error  You must define FOSC in "config.h" file
#endif
	
//_____ M A C R O S ________________________________________________________

//_____ D E C L A R A T I O N S ____________________________________________

extern volatile U32 rtc_tics;
extern volatile U16 rtc_milliseconds;
extern volatile U8  rtc_seconds;
extern volatile U8  rtc_minutes;
extern volatile U8  rtc_hours;
extern volatile U8  rtc_days;
extern Bool rtc_running;

//_____ P R O T O T Y P E S ________________________________________________

extern void wait_for(U16 ms_count);
extern void rtc_int_init(void);

//***************************************************************************

#endif  // _RTC_DRV_H_
