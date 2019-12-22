#ifndef _DS2431_H_
#define _DS2431_H_

#define ONE_WIRE_PORT   PORTG
#define ONE_WIRE_DIR    DDRG
#define ONE_WIRE_PIN    PING
#define ONE_WIRE_LINE   PG2

#define DS2431_OK                        0
#define DS2431_ERROR_WRONG_ADDRESS       1
#define DS2431_ERROR_NO_PRESENCE_PULSE   2
#define DS2431_ERROR_VERIFY_T1           3
#define DS2431_ERROR_VERIFY_T2           4
#define DS2431_ERROR_VERIFY_DATA         5
#define DS2431_ERROR_NO_AA               6


//*************************************************************************************************
//
//   external functions (public)
//
//*************************************************************************************************

unsigned char DS2431WriteMemory(unsigned char address,unsigned char* data); // data MAX 8 byte
unsigned char DS2431ReadMemory(unsigned char address,unsigned char* data,unsigned char length);
  

#endif
