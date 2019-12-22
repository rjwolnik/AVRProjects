#include "ds2431.h"
#include "at90can.h"


#define COMMAND_WRITE_SCRATCHPAD      0x0F
#define COMMAND_READ_SCRATCHPAD       0xAA
#define COMMAND_COPY_SCRATCHPAD       0x55
#define COMMAND_READ_MEMORY           0xF0

#define COMMAND_READ_ROM              0x33
#define COMMAND_MATCH_ROM             0x55
#define COMMAND_SEARCH_ROM            0xF0
#define COMMAND_SKIP_ROM              0xCC
#define COMMAND_RESUME                0xA5
#define COMMAND_OVERDRIVE_SKIP_ROM    0x3C
#define COMMAND_OVERIDE_MATCH_ROM     0x69




//*************************************************************************************************
//
//    internal data (privet)
//
//*************************************************************************************************

static unsigned char delay;




//*************************************************************************************************
//
//   internal functions (privet)
//
//*************************************************************************************************

unsigned char ResetSequence(void);  //Reset Pulse and Presence Pulse
void  SendToLine(unsigned char data);
unsigned char ReadFromLine(void);




//*************************************************************************************************
//
//   internal code constatnts 
//
//*************************************************************************************************



//*************************************************************************************************
//
//   internal functions (privet) implementation
//
//*************************************************************************************************
unsigned char ResetSequence(void)
{ 
  unsigned char ret;

  ONE_WIRE_DIR|=(1<<ONE_WIRE_LINE);     // set as output
  ONE_WIRE_PORT|=(1<<ONE_WIRE_LINE);    // output 1
  for(delay=0;delay<200;delay++);

  ONE_WIRE_PORT&=~(1<<ONE_WIRE_LINE);   // output 0
  for(delay=0;delay<200;delay++); // 138us@ 16Mhz 276us@8Mhz tRSTL
  for(delay=0;delay<200;delay++); // 276us@8Mhz 
  ONE_WIRE_DIR&=~(1<<ONE_WIRE_LINE);     // set as input
  for(delay=0;delay<50;delay++);  // 69 us@8Mhz tMPS
  if(ONE_WIRE_PIN&(1<<ONE_WIRE_LINE)) ret= 0xAA; // error no Preseance Pulse
  else                                ret= 0x00; // ok 
  for(delay=0;delay<60;delay++);        //83us@8Mhz t
  ONE_WIRE_DIR|=(1<<ONE_WIRE_LINE);     // set as output 
  ONE_WIRE_PORT|=(1<<ONE_WIRE_LINE);    // output 1

  for(delay=0;delay<10;delay++);          // 14us@8Mhz tREC

  return ret;
}

void  SendToLine(unsigned char data)
{
  unsigned char i;

  ONE_WIRE_DIR|=(1<<ONE_WIRE_LINE);          // set as output
  //ONE_WIRE_PORT|=(1<<ONE_WIRE_LINE);    // output 1
  for(i=0;i<8;i++)
  {
    if(data&(1<<i))
	{ //write-one time slot
       ONE_WIRE_PORT&=~(1<<ONE_WIRE_LINE);   // output 0
       for(delay=0;delay<5;delay++);         //8us@8Mhz   tW1L
	   ONE_WIRE_PORT|=(1<<ONE_WIRE_LINE);    // output 1
	   for(delay=0;delay<50;delay++);        // 69 us@8Mhz tSLOT-tW1L
	}
	else
	{//write-zero time slot      
	   ONE_WIRE_PORT&=~(1<<ONE_WIRE_LINE);   // output 0
       for(delay=0;delay<60;delay++);        //83us@8Mhz   tW0L
	   ONE_WIRE_PORT|=(1<<ONE_WIRE_LINE);    // output 1
	   for(delay=0;delay<10;delay++);        // 13us@8Mhz tREC
	}
  }
}


unsigned char ReadFromLine(void)
{
  unsigned char i,out;

  out=0;
  for(i=0;i<8;i++)
  {
    ONE_WIRE_DIR|=(1<<ONE_WIRE_LINE);     // set as output
    ONE_WIRE_PORT&=~(1<<ONE_WIRE_LINE);   // output 0
    for(delay=0;delay<5;delay++);         //8us@8Mhz tRL 
    ONE_WIRE_DIR&=~(1<<ONE_WIRE_LINE);    // set as input
    for(delay=0;delay<2;delay++);         // 3.6us@8Mhz tMPS
	
	if(ONE_WIRE_PIN&(1<<ONE_WIRE_LINE)) out|=0x80;
	if(i<7) out/=2; 
	//ONE_WIRE_PORT|=(1<<ONE_WIRE_LINE);    // output 1
	for(delay=0;delay<20;delay++);        // 28us@8Mhz tREC
  }
  return out;
}

//*************************************************************************************************
//
//   external functions (public) implementation
//
//*************************************************************************************************
unsigned char DS2431WriteMemory(unsigned char address,unsigned char* data)
{
  unsigned char i,T1,T2,ES;

  if(address&0x07) return DS2431_ERROR_WRONG_ADDRESS;
  if(ResetSequence()) return DS2431_ERROR_NO_PRESENCE_PULSE;
  SendToLine(COMMAND_SKIP_ROM);
  SendToLine(COMMAND_WRITE_SCRATCHPAD);
  SendToLine(address);
  SendToLine(0x00);
  for(i=0;i<8;i++) SendToLine(data[i]); 
  // skip CRC16 reading
  if(ResetSequence()) return DS2431_ERROR_NO_PRESENCE_PULSE;
  SendToLine(COMMAND_SKIP_ROM);
  SendToLine(COMMAND_READ_SCRATCHPAD);
  T1=ReadFromLine(); //T1
  if(T1!=address) return DS2431_ERROR_VERIFY_T1;
  T2=ReadFromLine(); //T2
  if(T2) return DS2431_ERROR_VERIFY_T2;
  ES=ReadFromLine(); //ES
  for(i=0;i<8;i++) 
  {
     if(ReadFromLine()!=data[i]) return DS2431_ERROR_VERIFY_DATA;
  }
  // skip CRC16 reading
  if(ResetSequence()) return DS2431_ERROR_NO_PRESENCE_PULSE;
  SendToLine(COMMAND_SKIP_ROM);
  SendToLine(COMMAND_COPY_SCRATCHPAD);
  SendToLine(T1);
  SendToLine(T2);
  SendToLine(ES);
  for(i=0;i<10;i++)                 //           |
  {                                 //           | 
    for(delay=0;delay<200;delay++); // 276us@8Mhz 
    for(delay=0;delay<200;delay++); // 276us@8Mhz  |
    for(delay=0;delay<200;delay++); // 276us@8Mhz  | tPROGmax = 11 ms
    for(delay=0;delay<200;delay++); // 276us@8Mhz 
  }  
  i=ReadFromLine();  
                               //           |
  if(ReadFromLine()==0xAA) return DS2431_OK;
  else                     return DS2431_ERROR_NO_AA;

}

unsigned char DS2431ReadMemory(unsigned char address,unsigned char* data,unsigned char length)
{
  unsigned char i;

  if(ResetSequence()) return DS2431_ERROR_NO_PRESENCE_PULSE;
  SendToLine(COMMAND_SKIP_ROM);
  SendToLine(COMMAND_READ_MEMORY);
  SendToLine(address);
  SendToLine(0x00);
  for(i=0;i<length;i++) 
  {
     data[i]=ReadFromLine();
  }
  return DS2431_OK;
}
