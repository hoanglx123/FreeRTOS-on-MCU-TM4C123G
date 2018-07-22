       ######################################################################
      # @file   : TaskLed.c                                                #
     # @author : Hoang Nguyen (nguyenthanhhoang7604119@gmail.com)         #
    # @date   : 22 Jul 2018                                              #
   # @brief  : Common definitions for makefile                          #
  # @note   : Depends on where toolchain is placed, please correct     #
 #          the below paths:                                          #
#           + TOOLCHAIN: gcc-arm-none-eabi                           #
#           + LIBS_PATH: Standard libraries of arm gcc-arm-none-eabi #
#           + TIVAWARE_PATH: Libraries of Tiva Ware                  #
#           + FLASH_PROGRAM: Flash tool                              #
######################################################################

# Toolchain
TOOLCHAIN := /mnt/d/Hoang/FreeRTOS/Toolchain/gcc-arm-none-eabi-7-2018-q2-update/bin

# Path of library 
LIBS_PATH := /mnt/d/Hoang/FreeRTOS/Toolchain/gcc-arm-none-eabi-7-2018-q2-update/arm-none-eabi/lib

# Tool to flash program
FLASH_PROGRAM := /mnt/d/Hoang/FreeRTOS/Toolchain/lm4tools-master/lm4tools-master/lm4flash/lm4flash

# TIVAWARE_PATH: path to tivaware folder
TIVAWARE_PATH := /mnt/d/Hoang/FreeRTOS/Toolchain/SW-TM4C-2.1.4.178

# Path of folder which FreeRTOSConfig.h is placed 
FREERTOS_CONFIG_PATH := Application/AppMain/Inc/

# Scatter file 
SCATTER_FILE := Application/AppMain/TM4C123GH6PM.ld

# Include files
INCLUDES = 

# Set default options
DEBUG ?= no

# Add debug flag
ifeq ($(DEBUG),yes)
    DEBUG_FLAGS := -DDEBUG -g
else
    DEBUG_FLAGS :=
endif

# Set the compiler CPU/FPU options.
#
CPU := -mcpu=cortex-m4
FPU := -mfpu=fpv4-sp-d16 -mfloat-abi=softfp
MCU := TM4C123GH6PM

# Define flags
CFLAGS  = -mthumb 
CFLAGS += ${CPU}
CFLAGS += ${FPU}
CFLAGS += -O2
CFLAGS += -MD
# CFLAGS += -Wall
CFLAGS += -DTARGET_IS_TM4C123_RB1
CFLAGS += -DPART_$(MCU)
CFLAGS += ${DEBUG_FLAGS}
CFLAGS += -c 

#######################################
# Shell
#######################################
RM    := rm -f
MKDIR := mkdir -p

#######################################
# Toolchain
#######################################
CC 		= $(TOOLCHAIN)/arm-none-eabi-gcc
LD 		= $(TOOLCHAIN)/arm-none-eabi-ld
AR 		= $(TOOLCHAIN)/arm-none-eabi-ar
OBJCOPY = $(TOOLCHAIN)/arm-none-eabi-objcopy
OBJDUMP = $(TOOLCHAIN)/arm-none-eabi-objdump
SIZE    = $(TOOLCHAIN)/arm-none-eabi-size