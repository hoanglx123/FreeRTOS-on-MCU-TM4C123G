# FreeRTOS-on-MCU-TM4C123G

# 1. Introduce
  The project is based on TI FreeRTOS. It is created with main purpose to study the operation of FreeRTOS on MCU. Please refer the project for studying and improve programming skill. Don't use it for commercial products. 

# 2. Project Structure 

	TivaC_FreeRTOS
	|_Application 
	|	|_AppMain (Contain main function used to start up FreeRTOS)
	|	|	|_Inc
	|	|	|	|_FreeRTOSConfig.h (Configure stack size, priorities, ... used in FreeRTOS)
	|	|	|_Src
	|	|	|	|_startup.c (Define the vector table corresponding to the specified MCU and call main function after initilaztion)  
	|	|	|	|_startup_freertos.c 
	|	|	|_Makefile 
	|	|	|_TM4C123GH6PM.ld (Linker script is used to describe the memory layout of the output file.)
	|	|_AppProg (All programs runned under FreeRTOS should be placed here.)
	|	|	|_Inc
	|	|	|_Src
	|	|	|_Makefile 
	|	|_Makefile 
	|_Drivers 
	| |_BSP (Board Support Package)
	|	|_Libs (Libraries from the third-party)
	|	|_Utils
	|	|_Makefile 
	|_FreeRTOS
	|	|_License 
	|	|_Source
	|	|_Makefile 
	|_Config.mk (Configure Toolchain or declare common definitions for Makefile)
	|_Makefile  

# 3. Toolchains 
