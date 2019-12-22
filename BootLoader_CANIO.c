//******************************************************************************
//! @file $RCSfile: main_can_bootloader_example.c,v $
//!
//! Copyright (c) 2007 Atmel.
//!
//! Use of this program is subject to Atmel's End User License Agreement.
//! Please read file license.txt for copyright notice.
//!
//! @brief: This application performs a CAN boot loader for AT90CAN128/64/32
//!         with aut-bitrate, IAP (In Application Programming) and API
//!         (Application Programming Interface).
//!
//! This boot loader is an example (application note like), the customer
//! needs to appropriate this code to fit exactly with its application and
//! its environment. Some specific calls (or jump) in customer application
//! are necessary to use correctly the IAP and API features.
//!
//! This file can be parsed by Doxygen for automatic documentation generation.
//! This file has been validated with AVRStudio-413528/WinAVR-20070122.
//!
//! @version $Revision: 3.20 $ $Name: jtellier $
//!
//! @todo
//! @bug
//! Modyfied by WK
//******************************************************************************

//_____  I N C L U D E S _______________________________________________________
#include "config.h"
#include "can_isp_protocol.h"
#include "isp_lib.h"
#include "reduced_can_lib.h"
#include "can_drv.h"
#include "flash_boot_lib.h"
#include "flash_api_lib.h"
#include "ds2431.h"


//_____ M A C R O S ____________________________________________________________

//_____ D E F I N I T I O N S __________________________________________________

//_____ D E C L A R A T I O N S ________________________________________________

//_____ F U N C T I O N S ______________________________________________________

//------------------------------------------------------------------------------
//  @fn main
//!
//! Core of "main_can_boot_loader.c".
//!
//! @brief: This application performs a CAN boot loader for AT90CAN128/64/32
//!         with aut-bitrate, IAP (In Application Programming) and API
//!         (Application Programming Interface).
//!
//! @warning: Don't forget to full locate the boot loader in "Boot Loader
//!           Flash Section".
//!           xxx_HWCB defined in "board.h" file
//!
//! @param none.
//!
//! @return Integer 0
//!
//------------------------------------------------------------------------------

U8 nodeId;
U16 waitForBootMsg; // timer for countingdown 2 sec to get boot telegram
U16	static 	u16_temp;

int main (void)
{
    U8      u8_temp,errorCode,dummy;
    U8      hwcb = FALSE;
	U16    static tmp16;
    Bool    auto_b = 0;

//! --- First of all, disabling the Global Interrupt
    Disable_interrupt();

//! --- If comming from RESET then test of the HardWare Condition Bit

    if (MCUSR != 0)
    {
        //- Clear all reset flags
        MCUSR = 0;
        //- Get HWCB (HardWare Condition Bit)
        HWCB_PORT_DIR &= ~(1<<HWCB_INPUT_PIN);      // HWCB pin in input
        if (HWCB_PULLUP_ON == 1)
        {
            HWCB_PORT_OUT |= (1<<HWCB_INPUT_PIN);   // Pull-up on HWCB
        }

		hwcb = HWCB_PORT_IN&(1<<HWCB_INPUT_PIN);
        //hwcb = HWCB_PORT_IN;
        //if (HWCB_ACTIVE_LEVEL == 0)
        //{
        //    hwcb = ((~hwcb)&(1<<HWCB_INPUT_PIN));
        //}

        //- Start application else start boot loader
        //u8_temp = get_conf_byte(BSB);

        //if ( ((u8_temp!=BSB_DEFAULT)&&(hwcb==0)) || ((u8_temp==BSB_DEFAULT)&&(hwcb!=0)) )
        //{
        //    isp_jump_to ( (((U16)get_conf_byte(SA_H))<<8) | ((U16)get_conf_byte(SA_L)) );   // Start application
        //}
		//if(hwcb) isp_jump_to ( (((U16)get_conf_byte(SA_H))<<8) | ((U16)get_conf_byte(SA_L)) );   // Start application 


        // else go to BOOT LOADER
	//	 PORTA=0xFF; // all LEDs off configur this ONLY after hard reset otherwise this is alredy configured by app
    //     DDRA = (1<<LED_RED)|(1<<LED_YELLOW)|(1<<LED_GREEN);  // set LED as output

		waitForBootMsg=0xFFFF;
    }
	else waitForBootMsg=0;

//! --- Open CAN communication
 
 //errorCode=DS2431ReadMemory(8,&nodeId,1);
/*
 if(errorCode||(!nodeId))
 {
   while(1)
   {
     PORTA&=~(1<<LED_RED);
     for(tmp16=0;tmp16<60000;tmp16++)dummy=tmp16; // for cheating optimalization !!
     PORTA|=(1<<LED_RED);
     for(tmp16=0;tmp16<60000;tmp16++)dummy=tmp16; // for cheating optimalization !!
   }

 }
 if(dummy)dummy=0; // for cheating optimalization !!
*/

    can_communication_opened = 0;   // Not opened

    //- Pull-up on TxCAN & RxCAN one by one to use bit-addressing
    CAN_PORT_DIR &= ~(1<<CAN_INPUT_PIN );
    CAN_PORT_DIR &= ~(1<<CAN_OUTPUT_PIN);
    CAN_PORT_OUT |=  (1<<CAN_INPUT_PIN );
    CAN_PORT_OUT |=  (1<<CAN_OUTPUT_PIN);

    while (1)
    {
        auto_b = ((~auto_b)&0x01);      // Flip of "auto_b"

        //- Wait until activity on RxCAN
        //while ((CAN_PORT_IN & (1<<CAN_INPUT_PIN)) != 0);

        //- Reset CAN peripheral
	    Can_reset();

//        if(get_conf_byte(BTC1)!=8)
//		{
//		  PORTA&=~(1<<LED_RED);
//		  while(1);
//        }
	    //- Set CAN Bit-timming
        //if (get_conf_byte(EB) != 0xFF)
        {
          //  CANBT1 = get_conf_byte(BTC1);       // Correction: 11 MArch 2007 - JT
          //  CANBT2 = get_conf_byte(BTC2);       //  idem
          //  CANBT3 = get_conf_byte(BTC3);       //  idem
        	CANBT1 = 0x02;       // Correction: 11 MArch 2007 - JT
            CANBT2 = 0x04;       //  idem
            CANBT3 = 0x13;
		}
        //else
        //- Loop on auto-bitrate until it is performed
        //{
        //    while ((Can_bit_timing(auto_b))==0);        // c.f. macro in "can_drv.h"
        //}

	    //- Enable CAN peripheral
        can_clear_all_mob();                        // c.f. function in "can_drv.c"
        Can_enable();                               // c.f. macro in "can_drv.h"

//! --- CAN ISP protocol execution
        //- Initialization of CAN ISP PROTOCOL only when CAN communication NOT opened
        if(!can_communication_opened) 
		 can_isp_protocol_init();
		
	
		u16_temp = 0x0;

    	//- Prepare Rx Command
    	can_isp_rx_msg.dlc = 8;        // Max
    	can_isp_rx_msg.id.std = base_isp_id;

    	//- Rx Command
    	while (can_cmd(&can_isp_rx_msg) != CAN_CMD_ACCEPTED);
    	//- Wait for Rx completed
    
			while (1)
		    {
		        if(++u16_temp > 20000) Direct_jump_to_zero();;
				u8_temp = can_get_status(&can_isp_rx_msg);
		        if (u8_temp != CAN_STATUS_NOT_COMPLETED) break; // Out of: while(1...
		    }
		


        //- Exit with "0" only if CAN hardware error occurs
        while(can_isp_protocol_task());
		

    }
    // End of "main"
    return(0);

}

