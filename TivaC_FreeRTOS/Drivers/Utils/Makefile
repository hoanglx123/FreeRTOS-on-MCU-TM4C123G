# FREERTOS_DIR: Path to FreeRTOS folder
FREERTOS_DIR := $(ROOT)/FreeRTOS

# OUTDIR: directory to use for output
OUTDIR  := $(ROOT)/build

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
INCLUDES += -I$(ROOT)/$(FREERTOS_CONFIG_PATH)

# Define flags		  
CFLAGS += $(INCLUDES) 			

################################################
########### Don't edit below ###################
################################################

# list of object files, placed in the build directory regardless of source path
OBJECTS = $(addprefix $(OUTDIR)/,$(notdir $(SOURCES:.c=.o)))

# default: build bin
all: $(OBJECTS)

$(OUTDIR)/%.o: $(SRC_DIR)/%.c | $(OUTDIR)
	$(CC) -o $@ $^ $(CFLAGS) 

# Create the output directory
$(OUTDIR):
	$(MKDIR) $(OUTDIR) 

clean:
	-$(RM) $(OUTDIR)/*

.PHONY: all clean flash
