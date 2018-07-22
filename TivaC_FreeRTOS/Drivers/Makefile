       ################################################################
      # @file   : TaskLed.c                                          #
     # @author : Hoang Nguyen (nguyenthanhhoang7604119@gmail.com)   #
    # @date   : 22 Jul 2018                                        #
   # @brief  : Set up FreeRTOS                                    #
  # @note   :                                                    #  
 #                                                              #
################################################################

#
# Include the configuration file.
#
include $(ROOT)/Config.mk

## Subdirectories Path
MODULES = $(wildcard *) 

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

.PHONY: all clean 

	