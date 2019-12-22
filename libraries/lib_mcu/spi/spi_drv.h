//******************************************************************************
//! @file $RCSfile: spi_drv.h,v $
//!
//! Copyright (c) 2006 Atmel.
//!
//! Use of this program is subject to Atmel's End User License Agreement.
//! Please read file license.txt for copyright notice.
//!
//! @brief This file contains the prototypes and the macros of the
//!        low level functions (drivers) of:
//!             - SPI
//!             - for AT90CAN128/64/32.
//!
//! This file can be parsed by Doxygen for automatic documentation generation.
//! This file has been validated with AVRStudio-412462/WinAVR-20060125.
//!
//! @version $Revision: 3.10 $ $Name: jtellier $
//!
//! @todo
//! @bug
//******************************************************************************


#ifndef _SPI_DRV_H_
#define _SPI_DRV_H_

//_____ I N C L U D E S ________________________________________________________

#include "config.h"

//_____ D E F I N I T I O N S __________________________________________________

    // ---------- SPI Controller
    // ---------- Masks
#define MSK_SPI_DATA_MODE         0x0C
#define MSK_SPI_CLOCK_RATE        0x03
#define MSK_SPI_CONFIG            0x3F

    // ---------- Pre-definitions for master slave
#define SPI_MASTER                0x10
#define SPI_SLAVE                 0x00

    // ---------- Pre-definitions for bit configuration
#define SPI_LSB_FIRST             0x20
#define SPI_MSB_FIRST             0x00

    // ---------- Pre-definitions for data (CPOL & CPHA) modes
#define SPI_DATA_MODE_0           0x00
#define SPI_DATA_MODE_1           0x04
#define SPI_DATA_MODE_2           0x08
#define SPI_DATA_MODE_3           0x0C

    // ---------- Pre-definitions for relationship between SCK and CLKIO
#define SPI_CLKIO_BY_2            0x80
#define SPI_CLKIO_BY_4            0x00
#define SPI_CLKIO_BY_8            0x81
#define SPI_CLKIO_BY_16           0x01
#define SPI_CLKIO_BY_32           0x82
#define SPI_CLKIO_BY_64           0x02
#define SPI_CLKIO_BY_128          0x03

//_____ M A C R O S ____________________________________________________________

#define Spi_enable()              (SPCR |=  (1<<SPE))
#define Spi_disable()             (SPCR &= ~(1<<SPE))
#define Spi_enable_it()           (SPCR |=  (1<<SPIE))
#define Spi_disable_it()          (SPCR &= ~(1<<SPIE))
#define Spi_select_master_mode()  (SPCR |=  (1<<MSTR))
#define Spi_select_slave_mode()   (SPCR &= ~(1<<MSTR))

#define Spi_init_config(config)   { Spi_init_bus();                    \
                                    SPCR &= ~MSK_SPI_CONFIG;           \
                                    SPCR |= (config & MSK_SPI_CONFIG); \
                                    SPSR |= (config >> 7);             }

#define Spi_read_data()           (SPDR)
#define Spi_get_byte()            (SPDR)
#define Spi_write_data(ch)        { (SPDR=ch); Spi_wait_spif(); }
#define Spi_send_byte(ch)         { (SPDR=ch); Spi_wait_spif(); }

#define Spi_wait_spif()           { while ((SPSR & (1<<SPIF)) == 0); }      //-- For any SPI rate
#define Spi_wait_eor()            { while ((SPSR & (1<<SPIF)) == 0); }      //-- Wait end of reception
#define Spi_wait_eot()            { while ((SPSR & (1<<SPIF)) == 0); }      //-- Wait end of transmission
#define Spi_eor()                 ((SPSR & (1<<SPIF)) == (1<<SPIF))         //-- Check end of reception
#define Spi_eot()                 ((SPSR & (1<<SPIF)) == (1<<SPIF))         //-- Check end of transmission

#define Spi_get_colision_status() (SPSR & (1<<WCOL))
#define Spi_get_byte()            (SPDR)
#define Spi_tx_ready()            (SPSR & (1<<SPIF))
#define Spi_rx_ready()            (Spi_tx_ready())

#define Spi_init_bus()            ((DDRB |= (1<<DDB2)|(1<<DDB1)))
#define Spi_disable_ss()
#define Spi_enable_ss()

#define Spi_write_dummy()         { (SPDR = 0x00); Spi_wait_spif(); }
#define Spi_read_dummy()          (0x00 = SPDR)

#define Spi_ack_read()            ({                                      \
                                      asm                                 \
                                      (                                   \
                                          "in  r0, %0"      "\n\t"        \
                                          :                               \
                                          : "I" (_SFR_IO_ADDR(SPSR))      \
                                          : "r0"                          \
                                      );                                  \
                                  })
                                  
#define Spi_ack_write()           ({                                      \
                                      asm                                 \
                                      (                                   \
                                          "in  r0, %0"      "\n\t"        \
                                          :                               \
                                          : "I" (_SFR_IO_ADDR(SPSR))      \
                                          : "r0"                          \
                                      );                                  \
                                  })
                                  
#define Spi_ack_cmd()             ({                                      \
                                      asm                                 \
                                      (                                   \
                                          "in  r0, %0"      "\n\t"        \
                                          :                               \
                                          : "I" (_SFR_IO_ADDR(SPSR))      \
                                          : "r0"                          \
                                      );                                  \
                                  })
                    
//______________________________________________________________________________

#endif  /* _SPI_DRV_H_ */

