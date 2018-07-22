       ################################################################
      # @file   : TaskLed.c                                          #
     # @author : Hoang Nguyen (nguyenthanhhoang7604119@gmail.com)   #
    # @date   : 22 Jul 2018                                        #
   # @brief  : Set up FreeRTOS                                    #
  # @note   :                                                    #  
 #                                                              #
################################################################

# KERNEL_LIB: FreeRTOS KERNEL_LIB
KERNEL_LIB := libFreeRTOS

# FREERTOS_DIR: Path to FreeRTOS folder
FREERTOS_DIR := $(ROOT)/FreeRTOS

# OUTDIR: directory to use for output
OUTDIR  := $(ROOT)/build

# KERNEL_SRC: list of input source KERNEL_SRC 
KERNEL_SRC  = $(wildcard $(FREERTOS_DIR)/Source/*.c)
KERNEL_SRC += $(wildcard $(FREERTOS_DIR)/Source/portable/GCC/ARM_CM4F/*.c)
KERNEL_SRC += $(wildcard $(FREERTOS_DIR)/Source/portable/MemMang/heap_1.c)

# KERNEL_INC: list of KERNEL_INC, by default, use KERNEL_INC directory
KERNEL_INC  = -I$(ROOT)/$(FREERTOS_CONFIG_PATH)
KERNEL_INC += -I$(FREERTOS_DIR)/Source/include
KERNEL_INC += -I$(FREERTOS_DIR)/Source/portable/GCC/ARM_CM4F

#
# Include the configuration file.
#
include $(ROOT)/Config.mk

# Define flags
CFLAGS += $(KERNEL_INC) 

################################################
########### Don't edit below ###################
################################################
# list of object files, placed in the build directory regardless of source path
OBJECTS = $(KERNEL_SRC:.c=.o)

# default: build FreeRTOS KERNEL_LIB as static library 
all: $(OUTDIR)/$(KERNEL_LIB).a
				
$(OUTDIR)/$(KERNEL_LIB).a: $(OBJECTS)
	$(AR) -r $@ $^

%.o : %.c
	$(CC) -o $@ $^ $(CFLAGS) 

# Create the output directory
$(OUTDIR):
	$(MKDIR) $(OUTDIR) 

clean:
	-$(RM) $(shell find -name '*.o') $(shell find -name '*.d')

.PHONY: all clean 
