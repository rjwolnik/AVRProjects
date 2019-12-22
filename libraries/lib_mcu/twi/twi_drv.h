/*H**************************************************************************
* $RCSfile: twi_drv.h,v $         
*----------------------------------------------------------------------------
* Copyright (c) 2003 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      $Name: avr-can11-lib-mcu-0_0_3 $      
* REVISION:     $Revision: 1.2 $     
* FILE_CVSID:   $Id: twi_drv.h,v 1.2 2004/02/10 06:48:28 jberthy Exp $       
*----------------------------------------------------------------------------
* PURPOSE: 
* Provide Uart driver
*****************************************************************************/

#ifndef _TWI_DRV_H_
#define _TWI_DRV_H_

#define MSK_TWCR_TWINT   0x80
#define MSK_TWCR_TWEA    0x40 
#define MSK_TWCR_TWSTA   0x20 
#define MSK_TWCR_TWSTO   0x10 
#define MSK_TWCR_TWEN    0x04
#define MSK_TWCR_TWIE    0x01


#define Twi_set_address(address) (TWAR = address)
#define Twi_get_address()        (TWAR)
#define Twi_set_data(data)       (TWDR = data)
#define Twi_set_aa()             (TWCR |= MSK_TWCR_TWEA&(~MSK_TWCR_TWINT))
#define Twi_clear_aa()           (TWCR &= (~MSK_TWCR_TWEA)&(~MSK_TWCR_TWINT))   
#define Twi_get_status()         (TWSR)
#define Twi_clear_start()        (TWCR &= (~MSK_TWCR_TWSTA)&(~MSK_TWCR_TWINT) )
#define Twi_set_start()          (TWCR |= MSK_TWCR_TWSTA)
#define Twi_set_stop()           (TWCR |= MSK_TWCR_TWSTO)
#define Twi_clear_stop()         (TWCR &= ~MSK_TWCR_TWSTO)
#define Twi_get_data()           (TWDR)
#define Twi_clear_si()           (TWCR |= MSK_TWCR_TWINT)
#define Twi_set_baudrate(baudrate)(TWBR = baudrate)
#define Twi_wait_hw_stop()       while((TWCR & MSK_TWCR_TWSTO)==MSK_TWCR_TWSTO)
#define Twi_wait_event()         while(((TWCR & MSK_TWCR_TWINT))!= MSK_TWCR_TWINT)
#define Disable_twi_interrupt()  (TWCR &= ~MSK_TWCR_TWIE)
#define Enable_twi_interrupt()   (TWCR |= MSK_TWCR_TWIE)
#define Twi_init_hw(arg)         (TWCR = arg)






#endif
