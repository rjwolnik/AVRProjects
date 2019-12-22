//***************************************************************************
//! @file $RCSfile: sensor_drv.h,v $
//!
//! Copyright (c) 2005 Atmel.
//!
//! Please read file license.txt for copyright notice.
//!
//! @brief On-board sensor include file.
//!
//! @version $Revision: 2.00 $ $Name: jtellier $ 
//!
//! @todo
//! @bug
//***************************************************************************

#ifndef _SENSOR_DRV_
#define _SENSOR_DRV_

//_____ I N C L U D E S ____________________________________________________

#include "config.h"

//_____ D E F I N I T I O N S ______________________________________________

//_____ M A C R O S ________________________________________________________

//_____ D E C L A R A T I O N S ____________________________________________

#define PU_THERM_VALUE     ((U16)(  100 ))      // Pull-up Res. for THERM = 100 Kohms
#define PU_LDRES_VALUE     ((U16)(   33 ))      // Pull-up Res. for LDRES = 3.3 Kohms
#define VIN_ADC_STEP       ((U16)(25600/0x3FF)) //  VREF / ADC_FULL_RANGE = 2.5 mV
#define VIN_RATIO_VALUE    ((U16)(    5 ))      // Pull-up = 400 Kohms, RVin = 100 Kohms

//_____ P R O T O T Y P E S ________________________________________________

S8  get_temperature (void);
U8  get_luminosity  (void);
U16 get_vin         (void);
    
//***************************************************************************

#endif  // _SENSOR_DRV_

