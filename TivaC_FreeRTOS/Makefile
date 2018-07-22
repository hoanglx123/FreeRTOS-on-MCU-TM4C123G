       ################################################################
      # @file   : TaskLed.c                                          #
     # @author : Hoang Nguyen (nguyenthanhhoang7604119@gmail.com)   #
    # @date   : 22 Jul 2018                                        #
   # @brief  :                                                    #
  # @note   :                                                    #  
 #                                                              #
################################################################

# TARGET: name of the output file
TARGET := main

## ROOT: Path to current project 
ROOT := $(shell pwd)

# OUTDIR: directory to use for output
OUTDIR  := $(ROOT)/build

## Subdirectories Path
MODULES  = FreeRTOS 
MODULES += Drivers 
MODULES += Application 

# Export variables for other Makefile
export ROOT

#
# Include the configuration file.
#
include $(ROOT)/Config.mk

################################################
########### Don't edit below ###################
################################################
all:
	@for i in ${MODULES};               \
	 do                                 \
	     if [ -f $${i}/Makefile ];      \
	     then                           \
	        $(MAKE) -C $${i} || exit $$?; \
	     fi;                            \
	 done

clean:
	@for i in ${MODULES};          \
	 do                            \
	     if [ -f $${i}/Makefile ]; \
	     then                      \
	        $(MAKE) -C $${i} clean;  \
	     fi;                       \
	 done

flash:
	sudo $(FLASH_PROGRAM) $(OUTDIR)/$(TARGET).bin

help:
	@echo You can use the following commands to build the project:
	@echo [1] make           : Build all project 
	@echo [2] make DEBUG=yes : Build all project with debug mode

.PHONY: all clean flash help 

	