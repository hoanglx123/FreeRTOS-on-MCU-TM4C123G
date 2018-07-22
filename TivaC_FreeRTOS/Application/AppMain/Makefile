       ################################################################
      # @file   : TaskLed.c                                          #
     # @author : Hoang Nguyen (nguyenthanhhoang7604119@gmail.com)   #
    # @date   : 22 Jul 2018                                        #
   # @brief  : Rules to build main applications in the project    #
  # @note   :                                                    #  
 #                                                              #
################################################################

# TARGET: name of the output file
TARGET := main

# FREERTOS_DIR: Path to FreeRTOS folder
FREERTOS_DIR := $(ROOT)/FreeRTOS

# OUTDIR: directory to use for output
OUTDIR  := $(ROOT)/build

# LIBS_DIR: directory to use for output
LIBS_DIR  := $(ROOT)/Drivers/Libs

# FreeRTOS KERNEL_LIB
KERNEL_LIB  := FreeRTOS

# INC_DIR: Path to include files
INC_DIR := Inc

# SRC_DIR: Path to source files
SRC_DIR := Src

# SOURCES: list of input source sources
SOURCES = $(wildcard $(SRC_DIR)/*.c)

#
# Include the configuration file.
#
include $(ROOT)/Config.mk

# INCLUDES: list of includes, by default, use Includes directory
INCLUDES += -I$(INC_DIR)
INCLUDES += -I$(TIVAWARE_PATH)
INCLUDES += -I$(FREERTOS_DIR)/Source/include
INCLUDES += -I$(FREERTOS_DIR)/Source/portable/GCC/ARM_CM4F

# Define flags		  
CFLAGS += $(INCLUDES) 			

# Libraries
LIBS  = -L $(OUTDIR) -l$(KERNEL_LIB)
LIBS += -L $(LIBS_DIR) -ldriver
LIBS += -L $(LIBS_PATH) -lc

# LD_SCRIPT: linker script
LD_SCRIPT = $(ROOT)/$(SCATTER_FILE)

#
# Configure linker flag
#
LDFLAGS  = -T $(LD_SCRIPT) -Map=$(OUTDIR)/$(TARGET).map --gc-sections $(LIBS) --entry ResetISR 

################################################
########### Don't edit below ###################
################################################
# list of object files, placed in the build directory regardless of source path
OBJECTS = $(addprefix $(OUTDIR)/,$(notdir $(SOURCES:.c=.o)))
OBJECTS += $(OUTDIR)/*.o

# default: build bin
all: $(OUTDIR)/$(TARGET).bin

$(OUTDIR)/%.o: $(SRC_DIR)/%.c | $(OUTDIR)
	$(CC) -o $@ $^ $(CFLAGS) 

$(OUTDIR)/$(TARGET).elf: $(OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS) 

$(OUTDIR)/$(TARGET).bin: $(OUTDIR)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@
	$(OBJCOPY) -O ihex $(OUTDIR)/$(TARGET).elf $(OUTDIR)/$(TARGET).hex
	$(OBJDUMP) -St $(OUTDIR)/$(TARGET).elf > $(OUTDIR)/$(TARGET).lst 
	$(SIZE) $(OUTDIR)/$(TARGET).elf

# Create the output directory
$(OUTDIR):
	$(MKDIR) $(OUTDIR) 

clean:
	-$(RM) $(OUTDIR)/*

.PHONY: all clean flash
