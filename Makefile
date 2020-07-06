#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for the build system for two platforms, HOST and MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#       <FILE>.o - Builds <FILE>.o object file
#	<FILE>.i - Builds <FILE>.o preprocessed file
#	<FILE>.asm - Builds <FILE>.o assembly file
#	<FILE>.d - Builds <FILE>.d dependency file
#	compile-all - compiles all object files
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Platform Overrides:
#      CPU - ARM Cortex Architecture (cortex-m4)
#      ARCH - ARM Architecture (armv7e-m)
#      SPECS - Specs file to give the linker (nosys.specs)
#
#------------------------------------------------------------------------------
include sources.mk

ifeq ($(PLATFORM),HOST)
		CC = gcc
		LD = ld
		LDFLAGS = -Wl,-Map=$(TARGET).map
		OBJDUMP = objdump
  		
		#Size Utility
		SIZE = size		

else
	        CC = arm-none-eabi-gcc
		LD = arm-none-eabi-ld
		LINKER_FILE = ../msp432p401r.lds
		LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

		# Architectures Specific Flags for ARM
		CPU = cortex-m4
		ARCH = thumb
		FPU = fpv4-sp-d16
		SPECS = nosys.specs
		ARMFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=$(FPU)		
		OBJDUMP = arm-none-eabi-objdump

		#Size Utility
		SIZE = arm-none-eabi-size 	
endif


# Platform Overrides
# Macro variable for choosing platform is -D$(PLATFORM)

TARGET = c1m2

# Compiler Flags and Defines
CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) $(ARMFLAGS)

# Preprocessor Flags and Defines
CPPFLAGS = -E

#Make variables for Preprocessed files, Object files ,Assembly files and Dependency files. 

PRE = $(SOURCES:.c=.i)
OBJ = $(SOURCES:.c=.o)
ASM = $(SOURCES:.c=.asm)
DEP = $(SOURCES:.c=.d)

# To stop after compiling	
%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

# To generate preprocessed files
%.i : %.c
	$(CC) $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) -o $@

# To generate assembly files
%.asm : %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

# To display assembler contents of executable sections
$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

# To generate dependency files 
%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@

# To compile all object files without linking
.PHONY: compile-all
compile-all: $(OBJ)
	$(CC) $(INCLUDES) $(OBJ) -c $(CFLAGS) -o $(TARGET).o

# To generate executable file and assembly files
.PHONY: build
build: $(TARGET).out  $(TARGET).asm

# To generate map file and print memory allocation details of the executable file
$(TARGET).out: $(OBJ) $(DEP) 
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJ)
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out

# To delete all the files except the source files, .mk files and Makefile
.PHONY: clean
clean:
	rm -f $(TARGET).asm $(TARGET).out $(TARGET).map $(PRE) $(ASM) $(DEP) $(OBJ)


