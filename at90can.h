/*****************************************************************************
 Bombardier Transportation (ZWUS) Polska Sp. z o.o.
******************************************************************************

 File    : AT90CAN.H
 Summary : Declarations for the AT90CAN microprocessor.

 Date    : 2008-10-03
 Author  : Wladyslaw Konieczny

 Compiler: AVR Studio 4.12 Service Pack 2

******************************************************************************
 all rights reserved
******************************************************************************/

#ifndef _AT90CAN_H_
#define _AT90CAN_H_

#define _MMIO_BYTE(mem_addr) (*(volatile unsigned char     *)(mem_addr))
#define _MMIO_WORD(mem_addr) (*(volatile unsigned short int*)(mem_addr))
#define _MMIO_DWORD(mem_addr)(*(volatile unsigned long  int*)(mem_addr))
#define _SFR_8(io_addr) _MMIO_BYTE (io_addr)
#define _SFR_16(io_addr) _MMIO_WORD (io_addr)
#define _SFR_32(io_addr) _MMIO_DWORD(io_addr)


/* Stack Pointer */
#define SP        _SFR_16(0x5D)
#define SPL       _SFR_8(0x5D)
#define SPH       _SFR_8(0x5E)

/* Status REGister */
#define SREG      _SFR_8(0x5F)

/* Status Register - SREG */
#define    SREG_I       7
#define    SREG_T       6
#define    SREG_H       5
#define    SREG_S       4
#define    SREG_V       3
#define    SREG_N       2
#define    SREG_Z       1
#define    SREG_C       0

/* Pointer definition */

#define    XL           r26
#define    XH           r27
#define    YL           r28
#define    YH           r29
#define    ZL           r30
#define    ZH           r31



#define _VECTOR(N) __vector_ ## N

/*************************** Interrupt vectors *************************/

/* External Interrupt Request 0 */
#define INT0_vect			_VECTOR(1)
#define SIG_INTERRUPT0			_VECTOR(1)

/* External Interrupt Request 1 */
#define INT1_vect			_VECTOR(2)
#define SIG_INTERRUPT1			_VECTOR(2)

/* External Interrupt Request 2 */
#define INT2_vect			_VECTOR(3)
#define SIG_INTERRUPT2			_VECTOR(3)

/* External Interrupt Request 3 */
#define INT3_vect			_VECTOR(4)
#define SIG_INTERRUPT3			_VECTOR(4)

/* External Interrupt Request 4 */
#define INT4_vect			_VECTOR(5)
#define SIG_INTERRUPT4			_VECTOR(5)

/* External Interrupt Request 5 */
#define INT5_vect			_VECTOR(6)
#define SIG_INTERRUPT5			_VECTOR(6)

/* External Interrupt Request 6 */
#define INT6_vect			_VECTOR(7)
#define SIG_INTERRUPT6			_VECTOR(7)

/* External Interrupt Request 7 */
#define INT7_vect			_VECTOR(8)
#define SIG_INTERRUPT7			_VECTOR(8)

/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		_VECTOR(9)
#define SIG_OUTPUT_COMPARE2		_VECTOR(9)

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			_VECTOR(10)
#define SIG_OVERFLOW2			_VECTOR(10)

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect		_VECTOR(11)
#define SIG_INPUT_CAPTURE1		_VECTOR(11)

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect		_VECTOR(12)
#define SIG_OUTPUT_COMPARE1A		_VECTOR(12)

/* Timer/Counter Compare Match B */
#define TIMER1_COMPB_vect		_VECTOR(13)
#define SIG_OUTPUT_COMPARE1B		_VECTOR(13)

/* Timer/Counter1 Compare Match C */
#define TIMER1_COMPC_vect		_VECTOR(14)
#define SIG_OUTPUT_COMPARE1C		_VECTOR(14)

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			_VECTOR(15)
#define SIG_OVERFLOW1			_VECTOR(15)

/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect		_VECTOR(16)
#define SIG_OUTPUT_COMPARE0		_VECTOR(16)

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			_VECTOR(17)
#define SIG_OVERFLOW0			_VECTOR(17)

/* CAN Transfer Complete or Error */
#define CANIT_vect			_VECTOR(18)
#define SIG_CAN_INTERRUPT1		_VECTOR(18)

/* CAN Timer Overrun */
#define OVRIT_vect			_VECTOR(19)
#define SIG_CAN_OVERFLOW1		_VECTOR(19)

/* SPI Serial Transfer Complete */
#define SPI_STC_vect			_VECTOR(20)
#define SIG_SPI				_VECTOR(20)

/* USART0, Rx Complete */
#define USART0_RX_vect			_VECTOR(21)
#define SIG_UART0_RECV			_VECTOR(21)

/* USART0 Data Register Empty */
#define USART0_UDRE_vect		_VECTOR(22)
#define SIG_UART0_DATA			_VECTOR(22)

/* USART0, Tx Complete */
#define USART0_TX_vect			_VECTOR(23)
#define SIG_UART0_TRANS			_VECTOR(23)

/* Analog Comparator */
#define ANALOG_COMP_vect		_VECTOR(24)
#define SIG_COMPARATOR			_VECTOR(24)

/* ADC Conversion Complete */
#define ADC_vect			_VECTOR(25)
#define SIG_ADC				_VECTOR(25)

/* EEPROM Ready */
#define EE_READY_vect			_VECTOR(26)
#define SIG_EEPROM_READY		_VECTOR(26)

/* Timer/Counter3 Capture Event */
#define TIMER3_CAPT_vect		_VECTOR(27)
#define SIG_INPUT_CAPTURE3		_VECTOR(27)

/* Timer/Counter3 Compare Match A */
#define TIMER3_COMPA_vect		_VECTOR(28)
#define SIG_OUTPUT_COMPARE3A		_VECTOR(28)

/* Timer/Counter3 Compare Match B */
#define TIMER3_COMPB_vect		_VECTOR(29)
#define SIG_OUTPUT_COMPARE3B		_VECTOR(29)

/* Timer/Counter3 Compare Match C */
#define TIMER3_COMPC_vect		_VECTOR(30)
#define SIG_OUTPUT_COMPARE3C		_VECTOR(30)

/* Timer/Counter3 Overflow */
#define TIMER3_OVF_vect			_VECTOR(31)
#define SIG_OVERFLOW3			_VECTOR(31)

/* USART1, Rx Complete */
#define USART1_RX_vect			_VECTOR(32)
#define SIG_UART1_RECV			_VECTOR(32)

/* USART1, Data Register Empty */
#define USART1_UDRE_vect		_VECTOR(33)
#define SIG_UART1_DATA			_VECTOR(33)

/* USART1, Tx Complete */
#define USART1_TX_vect			_VECTOR(34)
#define SIG_UART1_TRANS			_VECTOR(34)

/* 2-wire Serial Interface */
#define TWI_vect			_VECTOR(35)
#define SIG_2WIRE_SERIAL		_VECTOR(35)

/* Store Program Memory Read */
#define SPM_READY_vect			_VECTOR(36)
#define SIG_SPM_READY			_VECTOR(36)


#define ISR(vector)					\
void vector (void) __attribute__ ((signal,__INTR_ATTRS));		\
void vector (void)

#define SIGNAL(signame)					\
void signame (void) __attribute__ ((signal));		\
void signame (void)




/* Timer/Counter 0 interrupt Flag Register */
#define TIFR0  _SFR_8(0x35)
#define    OCF0A        1
#define    TOV0         0

/* Timer/Counter 1 interrupt Flag Register */
#define TIFR1  _SFR_8(0x36)
#define    ICF1       5
#define    OCF1C      3
#define    OCF1B      2
#define    OCF1A      1
#define    TOV1       0

/* Timer/Counter 2 interrupt Flag Register */
#define TIFR2  _SFR_8(0x37)
#define    OCF2A      1
#define    TOV2       0

/* Timer/Counter 3 interrupt Flag Register */
#define TIFR3  _SFR_8(0x38)
#define    ICF3       5
#define    OCF3C      3
#define    OCF3B      2
#define    OCF3A      1
#define    TOV3       0

/* External Interrupt Flag Register */
#define EIFR   _SFR_8(0x3C)
#define    INTF7        7
#define    INTF6        6
#define    INTF5        5
#define    INTF4        4
#define    INTF3        3
#define    INTF2        2
#define    INTF1        1
#define    INTF0        0

/* External Interrupt Mask Register */
#define EIMSK  _SFR_8(0x3D)
#define    INT7         7
#define    INT6         6
#define    INT5         5
#define    INT4         4
#define    INT3         3
#define    INT2         2
#define    INT1         1
#define    INT0         0

/* Interrupt */


/* PORT A definition */
#define PINA    _SFR_8(0x20)
#define    PINA7	    7
#define    PINA6	    6
#define    PINA5	    5
#define    PINA4	    4
#define    PINA3	    3
#define    PINA2	    2
#define    PINA1	    1
#define    PINA0	    0

#define DDRA    _SFR_8(0x21)
#define    DDA7         7
#define    DDA6         6
#define    DDA5         5
#define    DDA4         4
#define    DDA3         3
#define    DDA2         2
#define    DDA1         1
#define    DDA0         0

#define PORTA   _SFR_8(0x22)
#define    PA7	        7
#define    PA6          6
#define    PA5          5
#define    PA4          4
#define    PA3          3
#define    PA2          2
#define    PA1          1
#define    PA0          0

/* Port B */
#define PINB   _SFR_8(0x23)
#define    PINB7        7
#define    PINB6        6
#define    PINB5        5
#define    PINB4        4
#define    PINB3        3
#define    PINB2        2
#define    PINB1        1
#define    PINB0        0

#define DDRB   _SFR_8(0x24)
#define    DDB7         7
#define    DDB6         6
#define    DDB5         5
#define    DDB4         4
#define    DDB3         3
#define    DDB2         2
#define    DDB1         1
#define    DDB0         0

#define PORTB  _SFR_8(0x25)
#define    PB7          7
#define    PB6          6
#define    PB5          5
#define    PB4          4
#define    PB3          3
#define    PB2          2
#define    PB1          1
#define    PB0          0

/* Port C */
#define PINC   _SFR_8(0x26)
#define    PINC7        7
#define    PINC6        6
#define    PINC5        5
#define    PINC4        4
#define    PINC3        3
#define    PINC2        2
#define    PINC1        1
#define    PINC0        0

#define DDRC   _SFR_8(0x27)
#define    DDC7         7
#define    DDC6         6
#define    DDC5         5
#define    DDC4         4
#define    DDC3         3
#define    DDC2         2
#define    DDC1         1
#define    DDC0         0

#define PORTC  _SFR_8(0x28)
#define    PC7          7
#define    PC6          6
#define    PC5          5
#define    PC4          4
#define    PC3          3
#define    PC2          2
#define    PC1          1
#define    PC0          0

/* Port D */
#define PIND   _SFR_8(0x29)
#define    PIND7        7
#define    PIND6        6
#define    PIND5        5
#define    PIND4        4
#define    PIND3        3
#define    PIND2        2
#define    PIND1        1
#define    PIND0        0

#define DDRD   _SFR_8(0x2A)
#define    DDD7         7
#define    DDD6         6
#define    DDD5         5
#define    DDD4         4
#define    DDD3         3
#define    DDD2         2
#define    DDD1         1
#define    DDD0         0

#define PORTD  _SFR_8(0x2B)
#define    PD7          7
#define    PD6          6
#define    PD5          5
#define    PD4          4
#define    PD3          3
#define    PD2          2
#define    PD1          1
#define    PD0          0

/* Port E */
#define PINE   _SFR_8(0x2C)
#define    PINE7        7
#define    PINE6        6
#define    PINE5        5
#define    PINE4        4
#define    PINE3        3
#define    PINE2        2
#define    PINE1        1
#define    PINE0        0

#define DDRE   _SFR_8(0x2D)
#define    DDE7         7
#define    DDE6         6
#define    DDE5         5
#define    DDE4         4
#define    DDE3         3
#define    DDE2         2
#define    DDE1         1
#define    DDE0         0

#define PORTE  _SFR_8(0x2E)
#define    PE7          7
#define    PE6          6
#define    PE5          5
#define    PE4          4
#define    PE3          3
#define    PE2          2
#define    PE1          1
#define    PE0          0

/* Port F */
#define PINF   _SFR_8(0x2F)
#define    PINF7        7
#define    PINF6        6
#define    PINF5        5
#define    PINF4        4
#define    PINF3        3
#define    PINF2        2
#define    PINF1        1
#define    PINF0        0

#define DDRF   _SFR_8(0x30)
#define    DDF7         7
#define    DDF6         6
#define    DDF5         5
#define    DDF4         4
#define    DDF3         3
#define    DDF2         2
#define    DDF1         1
#define    DDF0         0

#define PORTF  _SFR_8(0x31)
#define    PF7          7
#define    PF6          6
#define    PF5          5
#define    PF4          4
#define    PF3          3
#define    PF2          2
#define    PF1          1
#define    PF0          0

/* Port G */
#define PING   _SFR_8(0x32)
#define    PING4        4
#define    PING3        3
#define    PING2        2
#define    PING1        1
#define    PING0        0

#define DDRG   _SFR_8(0x33)
#define    DDG4         4
#define    DDG3         3
#define    DDG2         2
#define    DDG1         1
#define    DDG0         0

#define PORTG  _SFR_8(0x34)
#define    PG4          4
#define    PG3          3
#define    PG2          2
#define    PG1          1
#define    PG0          0




/* CAN General Control Register*/
#define CANGCON _SFR_8(0xD8)

#define    ABRQ       7
#define    OVRQ       6
#define    TTC        5
#define    SYNTTC     4
#define    LISTEN     3
#define    TEST       2
#define    ENASTB     1
#define    SWRES      0


/* CAN General Status Register*/
#define CANGSTA _SFR_8(0xD9)

#define    OVRG       6
#define    TXBSY      4
#define    RXBSY      3
#define    ENFG       2
#define    BOFF       1
#define    ERRP       0


/* CAN General Interrupt Register*/
#define CANGIT _SFR_8(0xDA)

#define    CANIT      7
#define    BOFFIT     6
#define    OVRTIM     5
#define    BXOK       4
#define    SERG       3
#define    CERG       2
#define    FERG       1
#define    AERG       0


/* CAN General Interrupt Enable Register*/
#define CANGIE _SFR_8(0xDB)

#define    ENIT        7
#define    ENBOFF      6
#define    ENRX        5
#define    ENTX        4
#define    ENERR       3
#define    ENBX        2
#define    ENERG       1
#define    ENOVRT      0


/* CAN Enable MOb Register*/
#define CANEN2 _SFR_8(0xDC)

#define    ENMOB7      7
#define    ENMOB6      6
#define    ENMOB5      5
#define    ENMOB4      4
#define    ENMOB3      3
#define    ENMOB2      2
#define    ENMOB1      1
#define    ENMOB0      0


/* CAN Enable MOb Register*/
#define CANEN1 _SFR_8(0xDD)

#define    ENMOB14      6
#define    ENMOB13      5
#define    ENMOB12      4
#define    ENMOB11      3
#define    ENMOB10      2
#define    ENMOB9       1
#define    ENMOB8       0

#define CANEN _SFR_16(0xDC)

/* CAN Enable Interrupt MOb Register*/
#define CANIE2 _SFR_8(0xDE)

#define    IEMOB6      6
#define    IEMOB5      5
#define    IEMOB4      4
#define    IEMOB3      3
#define    IEMOB2      2
#define    IEMOB1      1
#define    IEMOB0      0


/* CAN Enable Interrupt MOb Register*/
#define CANIE1 _SFR_8(0xDF)

#define    IEMOB14      6
#define    IEMOB13      5
#define    IEMOB12      4
#define    IEMOB11      3
#define    IEMOB10      2
#define    IEMOB9       1
#define    IEMOB8       0

/* CAN Status Interrupt MOb Register*/
#define CANSIT  _SFR_16(0xE0)

#define CANSIT2 _SFR_8(0xE0)
#define    SIT7      7
#define    SIT6      6
#define    SIT5      5
#define    SIT4      4
#define    SIT3      3
#define    SIT2      2
#define    SIT1      1
#define    SIT0      0

#define CANSIT1 _SFR_8(0xE1)
#define    SIT14      6
#define    SIT13      5
#define    SIT12      4
#define    SIT11      3
#define    SIT10      2
#define    SIT9       1
#define    SIT8       0


/* CAN Bit Timing Register 1*/
#define CANBT1 _SFR_8(0xE2)

#define    BRP5       6
#define    BRP4       5
#define    BRP3       4
#define    BRP2       3
#define    BRP1       2
#define    BRP0       1


/* CAN Bit Timing Register 2*/
#define CANBT2 _SFR_8(0xE3)

#define    SJW1       6
#define    SJW0       5
#define    PRS2       3
#define    PRS1       2
#define    PRS0       1


/* CAN Bit Timing Register 3*/
#define CANBT3 _SFR_8(0xE4)

#define    PHS22      6
#define    PHS21      5
#define    PHS20      4
#define    PHS12      3
#define    PHS11      2
#define    PHS10      1
#define    SMP        0

/* CAN Timer Control Register*/
#define CANTCON _SFR_8(0xE5)

#define    TPRSC7      7
#define    TPRSC6      6
#define    TPRSC5      5
#define    TPRSC4      4
#define    TPRSC3      3
#define    TPRSC2      2
#define    TPRSC1      1
#define    TPRSC0      0


/* CAN Timer Register*/
#define CANTIM _SFR_16(0xE6)

#define CANTIML _SFR_8(0xE6)
#define    CANTIM7      7
#define    CANTIM6      6
#define    CANTIM5      5
#define    CANTIM4      4
#define    CANTIM3      3
#define    CANTIM2      2
#define    CANTIM1      1
#define    CANTIM0      0

#define CANTIMH _SFR_8(0xE7)
#define    CANTIM15     7
#define    CANTIM14     6
#define    CANTIM13     5
#define    CANTIM12     4
#define    CANTIM11     3
#define    CANTIM10     2
#define    CANTIM9      1
#define    CANTIM8      0


/* RegDef:  CAN TTC Timer Register*/
#define CANTTC _SFR_16(0xE8)

#define CANTTCL _SFR_8(0xE8)
#define    TIMTTC7      7
#define    TIMTTC6      6
#define    TIMTTC5      5
#define    TIMTTC4      4
#define    TIMTTC3      3
#define    TIMTTC2      2
#define    TIMTTC1      1
#define    TIMTTC0      0

#define CANTTCH _SFR_8(0xE9)
#define    TIMTTC15     7
#define    TIMTTC14     6
#define    TIMTTC13     5
#define    TIMTTC12     4
#define    TIMTTC11     3
#define    TIMTTC10     2
#define    TIMTTC9      1
#define    TIMTTC8      0


/* CAN Transmitt Error Counter Register*/
#define CANTEC _SFR_8(0xEA)
#define    TEC7      7
#define    TEC6      6
#define    TEC5      5
#define    TEC4      4
#define    TEC3      3
#define    TEC2      2
#define    TEC1      1
#define    TEC0      0


/* CAN Receive Error Counter Register*/
#define CANREC _SFR_8(0xEB)
#define    REC7      7
#define    REC6      6
#define    REC5      5
#define    REC4      4
#define    REC3      3
#define    REC2      2
#define    REC1      1
#define    REC0      0


/* CAN Highest Priority MOb Register*/
#define CANHPMOB _SFR_8(0xEC)

#define    HPMOB3     7
#define    HPMOB2     6
#define    HPMOB1     5
#define    HPMOB0     4
#define    CGP3       3
#define    CGP2       2
#define    CGP1       1
#define    CGP0       0


/* CAN Page MOb Register*/
#define CANPAGE _SFR_8(0xED)
#define    MOBNB3     7
#define    MOBNB2     6
#define    MOBNB1     5
#define    MOBNB0     4
#define    AINC       3
#define    INDX2      2
#define    INDX1      1
#define    INDX0      0


/* CAN MOb Status Register*/
#define CANSTMOB _SFR_8(0xEE)
#define    DLCW       7
#define    TXOK       6
#define    RXOK       5
#define    BERR       4
#define    SERR       3
#define    CERR       2
#define    FERR       1
#define    AERR       0


/* CAN MOb Control and DLC Register*/
#define CANCDMOB _SFR_8(0xEF)
#define    CONMOB1    7
#define    CONMOB0    6
#define    RPLV       5
#define    IDE        4
#define    DLC3       3
#define    DLC2       2
#define    DLC1       1
#define    DLC0       0


/* CAN Identifier Tag Registers*/
#define CANIDT  _SFR_32(0xF0)

#define CANIDT4 _SFR_8(0xF0)
#define    IDT4       7
#define    IDT3       6
#define    IDT2       5
#define    IDT1       4
#define    IDT0       3
#define    RTRTAG     2
#define    RB1TAG     1
#define    RB0TAG     0

#define CANIDT3 _SFR_8(0xF1)
#define    IDT12      7
#define    IDT11      6
#define    IDT10      5
#define    IDT9       4
#define    IDT8       3
#define    IDT7       2
#define    IDT6       1
#define    IDT5       0

#define CANIDT2 _SFR_8(0xF2)
#define    IDT20      7
#define    IDT19      6
#define    IDT18      5
#define    IDT17      4
#define    IDT16      3
#define    IDT15      2
#define    IDT14      1
#define    IDT13      0

#define CANIDT1 _SFR_8(0xF3)
#define    IDT28      7
#define    IDT27      6
#define    IDT26      5
#define    IDT25      4
#define    IDT24      3
#define    IDT23      2
#define    IDT22      1
#define    IDT21      0



/* CAN Identifier Mask Registers */
#define CANIDM  _SFR_32(0xF4)

#define CANIDM4 _SFR_8(0xF4)
#define    IDMSK4       7
#define    IDMSK3       6
#define    IDMSK2       5
#define    IDMSK1       4
#define    IDMSK0       3
#define    RTRMSK       2
#define    IDEMSK       0

#define CANIDM3 _SFR_8(0xF5)
#define    IDMSK12      7
#define    IDMSK11      6
#define    IDMSK10      5
#define    IDMSK9       4
#define    IDMSK8       3
#define    IDMSK7       2
#define    IDMSK6       1
#define    IDMSK5       0

#define CANIDM2 _SFR_8(0xF6)
#define    IDMSK20      7
#define    IDMSK19      6
#define    IDMSK18      5
#define    IDMSK17      4
#define    IDMSK16      3
#define    IDMSK15      2
#define    IDMSK14      1
#define    IDMSK13      0

#define CANIDM1 _SFR_8(0xF7)
#define    IDMSK28      7
#define    IDMSK27      6
#define    IDMSK26      5
#define    IDMSK25      4
#define    IDMSK24      3
#define    IDMSK23      2
#define    IDMSK22      1
#define    IDMSK21      0

/* RegDef:  CAN TTC Timer Register*/
#define CANSTM _SFR_16(0xF8)

#define CANSTML _SFR_8(0xF8)
#define    TIMSTM7       7
#define    TIMSTM6       6
#define    TIMSTM5       5
#define    TIMSTM4       4
#define    TIMSTM3       3
#define    TIMSTM2       2
#define    TIMSTM1       1
#define    TIMSTM0       0

#define CANSTMH _SFR_8(0xF9)
#define    TIMSTM15       7
#define    TIMSTM14       6
#define    TIMSTM13       5
#define    TIMSTM12       4
#define    TIMSTM11       3
#define    TIMSTM10       2
#define    TIMSTM9        1
#define    TIMSTM8        0


/* CAN Message Register*/
#define CANMSG _SFR_8(0xFA)
#define    MSG7           7
#define    MSG6           6
#define    MSG5           5
#define    MSG4           4
#define    MSG3           3
#define    MSG2           2
#define    MSG1           1
#define    MSG0           0

#define MAX_NO_MOB        15


/* General Timer/Counter Control Register */
#define GTCCR  _SFR_8(0x43)
#define    TSM      7
#define    PSR2     1
#define    PSR310   0


/* Output Compare Register A */
#define OCR0A  _SFR_8(0x47)
#define    OCR0A7     7
#define    OCR0A6     6
#define    OCR0A5     5
#define    OCR0A4     4
#define    OCR0A3     3
#define    OCR0A2     2
#define    OCR0A1     1
#define    OCR0A0     0

/* Timer/Counter 0 Interrupt Mask Register */
#define TIMSK0 _SFR_8(0x6E)
#define    OCIE0A      1
#define    TOIE0       0

/* Timer/Counter 1 Interrupt Mask Register */
#define TIMSK1 _SFR_8(0x6F)
#define    ICIE1       5
#define    OCIE1C      3
#define    OCIE1B      2
#define    OCIE1A      1
#define    TOIE1       0

/* Timer/Counter 2 Interrupt Mask Register */
#define TIMSK2 _SFR_8(0x70)
#define    OCIE2A      1
#define    TOIE2       0

/* Timer/Counter 3 Interrupt Mask Register */
#define TIMSK3 _SFR_8(0x71)
#define    ICIE3       5
#define    OCIE3C      3
#define    OCIE3B      2
#define    OCIE3A      1
#define    TOIE3       0


/* Timer/Counter Control Register A */
#define TCCR0A _SFR_8(0x44)
#define    FOC0A    7
#define    WGM00    6
#define    COM0A1   5
#define    COM0A0   4
#define    WGM01    3
#define    CS02     2
#define    CS01     1
#define    CS00     0

/* Timer/Counter Register */
#define TCNT0  _SFR_8(0x46)


/* Timer/Counter1 Control Register A */
#define TCCR1A _SFR_8(0x80)
#define    COM1A1       7
#define    COM1A0       6
#define    COM1B1       5
#define    COM1B0       4
#define    COM1C1       3
#define    COM1C0       2
#define    WGM11        1
#define    WGM10        0


/* Timer/Counter1 Control Register B */
#define TCCR1B _SFR_8(0x81)
#define    ICNC1        7
#define    ICES1        6
#define    WGM13        4
#define    WGM12        3
#define    CS12         2
#define    CS11         1
#define    CS10         0

/* Timer/Counter1 Control Register C */
#define TCCR1C _SFR_8(0x82)
#define    FOC1A        7
#define    FOC1B        6
#define    FOC1C        5

/* Timer/Counter1 Register */
#define TCNT1  _SFR_16(0x84)
#define TCNT1L _SFR_8(0x84)
#define TCNT1H _SFR_8(0x85)

/* Timer/Counter1 Input Capture Register */
#define ICR1   _SFR_16(0x86)
#define ICR1L  _SFR_8(0x86)
#define ICR1H  _SFR_8(0x87)

/* Timer/Counter1 Output Compare Register A */
#define OCR1A  _SFR_MEM16(0x88)
#define OCR1AL _SFR_MEM8(0x88)
#define OCR1AH _SFR_MEM8(0x89)

/* Timer/Counter1 Output Compare Register B */
#define OCR1B  _SFR_16(0x8A)
#define OCR1BL _SFR_8(0x8A)
#define OCR1BH _SFR_8(0x8B)

/* Timer/Counter1 Output Compare Register C */
#define OCR1C  _SFR_16(0x8C)
#define OCR1CL _SFR_8(0x8C)
#define OCR1CH _SFR_8(0x8D)

/* Timer/Counter3 Control Register A */
#define TCCR3A _SFR_8(0x90)

/* Timer/Counter3 Control Register B */
#define TCCR3B _SFR_8(0x91)

/* Timer/Counter3 Control Register C */
#define TCCR3C _SFR_8(0x92)
#define    FOC3A        7
#define    FOC3B        6
#define    FOC3C        5

/* Timer/Counter3 Register */
#define TCNT3  _SFR_16(0x94)
#define TCNT3L _SFR_8(0x94)
#define TCNT3H _SFR_8(0x95)

/* Timer/Counter3 Input Capture Register */
#define ICR3   _SFR_16(0x96)
#define ICR3L  _SFR_8(0x96)
#define ICR3H  _SFR_8(0x97)

/* Timer/Counter3 Output Compare Register A */
#define OCR3A  _SFR_16(0x98)
#define OCR3AL _SFR_8(0x98)
#define OCR3AH _SFR_8(0x99)

/* Timer/Counter3 Output Compare Register B */
#define OCR3B  _SFR_16(0x9A)
#define OCR3BL _SFR_8(0x9A)
#define OCR3BH _SFR_8(0x9B)

/* Timer/Counter3 Output Compare Register C */
#define OCR3C  _SFR_16(0x9C)
#define OCR3CL _SFR_8(0x9C)
#define OCR3CH _SFR_8(0x9D)

/* Timer/Counter2 Control Register A */
#define TCCR2A _SFR_8(0xB0)

/* Timer/Counter2 Register */
#define TCNT2  _SFR_8(0xB2)

/* Timer/Counter2 Output Compare Register */
#define OCR2A  _SFR_8(0xB3)



/* USART0 Control and Status Register A */
#define UCSR0A _SFR_8(0xC0)
#define    RXC0         7
#define    TXC0         6
#define    UDRE0        5
#define    FE0          4
#define    DOR0         3
#define    UPE0         2
#define    U2X0         1
#define    MPCM0        0

/* USART0 Control and Status Register B */
#define UCSR0B _SFR_8(0xC1)
#define    RXCIE0       7
#define    TXCIE0       6
#define    UDRIE0       5
#define    RXEN0        4
#define    TXEN0        3
#define    UCSZ02       2
#define    RXB80        1
#define    TXB80        0

/* USART0 Control and Status Register C */
#define UCSR0C _SFR_8(0xC2)
#define    UMSEL0       6
#define    UPM01        5
#define    UPM00        4
#define    USBS0        3
#define    UCSZ01       2
#define    UCSZ00       1
#define    UCPOL0       0

/* USART0 Baud Rate Register */
#define UBRR0  _SFR_16(0xC4)
#define UBRR0L _SFR_8(0xC4)
#define UBRR0H _SFR_8(0xC5)

/* USART0 I/O Data Register */
#define UDR0   _SFR_8(0xC6)

/* USART1 Control and Status Register A */
#define UCSR1A _SFR_8(0xC8)
#define    RXC1         7
#define    TXC1         6
#define    UDRE1        5
#define    FE1          4
#define    DOR1         3
#define    UPE1         2
#define    U2X1         1
#define    MPCM1        0

/* USART1 Control and Status Register B */
#define UCSR1B _SFR_8(0xC9)
#define    RXCIE1       7
#define    TXCIE1       6
#define    UDRIE1       5
#define    RXEN1        4
#define    TXEN1        3
#define    UCSZ12       2
#define    RXB81        1
#define    TXB81        0

/* USART1 Control and Status Register C */
#define UCSR1C _SFR_8(0xCA)
#define    UMSEL1       6
#define    UPM11        5
#define    UPM10        4
#define    USBS1        3
#define    UCSZ11       2
#define    UCSZ10       1
#define    UCPOL1       0

/* USART1 Baud Rate Register */
#define UBRR1  _SFR_16(0xCC)
#define UBRR1L _SFR_8(0xCC)
#define UBRR1H _SFR_8(0xCD)

/* USART1 I/O Data Register */
#define UDR1   _SFR_8(0xCE)


/* TWI Bit Rate Register */
#define TWBR   _SFR_8(0xB8)
#define TWBR7			7
#define TWBR6			6
#define TWBR5			5
#define TWBR4			4
#define TWBR3			3
#define TWBR2			2
#define TWBR1			1
#define TWBR0			0

/* TWI Status Register */
#define TWSR   _SFR_8(0xB9)
#define TWS7			7
#define TWS6			6
#define TWS5			5
#define TWS4			4
#define TWS3			3
#define TWPS1			1
#define TWPS0			0

/* TWI (Slave) Address Register */
#define TWAR   _SFR_8(0xBA)
#define TWA6			7
#define TWA5			6
#define TWA4			5
#define TWA3			4
#define TWA2			3
#define TWA1			2
#define TWA0			1
#define TWGCE			0

/* TWI Data Register */
#define TWDR   _SFR_8(0xBB)
#define TWD7			7 
#define TWD6			6 
#define TWD5			5 
#define TWD4			4 
#define TWD3			3 
#define TWD2			2 
#define TWD1			1 
#define TWD0			0 
 

/* TWI Control Register */
#define TWCR   _SFR_8(0xBC)
#define TWINT			7
#define TWEA			6
#define TWSTA			5
#define TWSTO			4
#define TWWC			3
#define TWEN			2
#define TWIE			0


/* External Memory Control Register A */
#define XMCRA _SFR_8(0x74)
#define    SRE         7
#define    SRL2        6
#define    SRL1        5
#define    SRL0        4
#define    SRW11       3
#define    SRW10       2
#define    SRW01       1
#define    SRW00       0

/* External Memory Control Register A */
#define XMCRB _SFR_8(0x75)
#define    XMBK         7
#define    XMM2         2
#define    XMM1         1
#define    XMM0         0


/* SPI Control Register */
#define SPCR   _SFR_8(0x4C)
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0


/* SPI Status Register */
#define SPSR   _SFR_8(0x4D)
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0

/* SPI Data Register */
#define SPDR   _SFR_8(0x4E)

/* Watchdog Timer Control Register */
#define WDTCR  _SFR_8(0x60)
#define    WDCE         4
#define    WDE          3
#define    WDP2         2
#define    WDP1         1
#define    WDP0         0

/* MCU Status Register */
#define MCUSR  _SFR_8(0x54)
#define    JTRF    4
#define    WDRF    3
#define    BORF    2
#define    EXTRF   1
#define    PORF    0

/* Control Rgeister */
#define MCUCR  _SFR_8(0x55)
#define    JTD     7
#define    PUD     4
#define    IVSEL   1
#define    IVCE    0

/* EEPROM Control Register */
#define EECR   _SFR_8(0x3F)
#define    EERIE       3
#define    EEMWE       2
#define    EEWE        1
#define    EERE        0

/* EEPROM Data Register */
#define EEDR   _SFR_8(0x40)
#define    EEDR7     7
#define    EEDR6     6
#define    EEDR5     5
#define    EEDR4     4
#define    EEDR3     3
#define    EEDR2     2
#define    EEDR1     1
#define    EEDR0     0

/* EEPROM Address Register */
#define EEAR   _SFR_16(0x41)
#define EEARL  _SFR_8(0x41)
#define    EEAR7     7
#define    EEAR6     6
#define    EEAR5     5
#define    EEAR4     4
#define    EEAR3     3
#define    EEAR2     2
#define    EEAR1     1
#define    EEAR0     0
#define EEARH  _SFR_8(0x42)
#define    EEAR11    3
#define    EEAR10    2
#define    EEAR9     1
#define    EEAR8     0


#endif
