###############################################################################
# Makefile for the project BootLoader_CANIO
###############################################################################

## General Flags
PROJECT = BootLoader_CANIO
MCU = at90can128
TARGET = BootLoader_CANIO.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -Os -funsigned-char -funsigned-bitfields
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=BootLoader_CANIO.map
LDFLAGS += -Wl,-section-start=.text=0x1e000
LDFLAGS += -Wl,-section-start=.bootconf=0x1ff00
LDFLAGS += -Wl,-section-start=.flashapi=0x1fffa


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Include Directories
INCLUDES = -I"C:\WinAVR\Projects\BootLoader_CANIO\." -I"C:\WinAVR\Projects\BootLoader_CANIO\libraries\lib_board" -I"C:\WinAVR\Projects\BootLoader_CANIO\libraries\lib_mcu" -I"C:\WinAVR\Projects\BootLoader_CANIO\libraries\lib_mcu\eeprom" -I"C:\WinAVR\Projects\BootLoader_CANIO\libraries\lib_mcu\flash" -I"C:\WinAVR\Projects\BootLoader_CANIO\libraries\lib_module\isp" -I"C:\WinAVR\Projects\BootLoader_CANIO\libraries\lib_mcu\can" 

## Objects that must be built in order to link
OBJECTS = BootLoader_CANIO.o can_drv.o can_isp_protocol.o reduced_can_lib.o flash_api_lib.o flash_boot_drv.o flash_boot_lib.o isp_lib.o eeprom_lib.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) BootLoader_CANIO.hex BootLoader_CANIO.eep BootLoader_CANIO.lss## Compile
BootLoader_CANIO.o: ../BootLoader_CANIO.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

can_drv.o: ../libraries/lib_mcu/can/can_drv.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

can_isp_protocol.o: ../libraries/lib_mcu/can/can_isp_protocol.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

reduced_can_lib.o: ../libraries/lib_mcu/can/reduced_can_lib.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

flash_api_lib.o: ../libraries/lib_mcu/flash/flash_api_lib.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

flash_boot_drv.o: ../libraries/lib_mcu/flash/flash_boot_drv.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

flash_boot_lib.o: ../libraries/lib_mcu/flash/flash_boot_lib.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

isp_lib.o: ../libraries/lib_module/isp/isp_lib.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

eeprom_lib.o: ../libraries/lib_mcu/eeprom/eeprom_lib.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) BootLoader_CANIO.elf dep/* BootLoader_CANIO.hex BootLoader_CANIO.eep BootLoader_CANIO.lss BootLoader_CANIO.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

