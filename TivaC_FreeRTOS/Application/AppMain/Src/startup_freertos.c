/**
 * @file   : TaskLed.c
 * @author : Hoang Nguyen (nguyenthanhhoang7604119@gmail.com)
 * @date   : 22 Jul 2018
 * @brief  : Set up FreeRTOS
 * @note   : If there is no special reason, please don't change this file. 
 * 
 */

#include <stdbool.h>
#include <stdint.h>
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "FreeRTOS.h"
#include "task.h"

extern int main(void); 

//*****************************************************************************
//
// Initialize FreeRTOS and start the initial set of tasks.
//
//*****************************************************************************
int startup_freertos(void)
{
    //
    // Set the clocking to run at 50 MHz from the PLL.
    //
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

    /* Call main function of program */
    main();

    //
    // Start the scheduler.  This should not return.
    //
    vTaskStartScheduler();

    //
    // In case the scheduler returns for some reason, print an error and loop
    // forever.
    //

    while(1)
    {
    }
}

//*****************************************************************************
//
// This hook is called by FreeRTOS when an stack overflow error is detected.
//
//*****************************************************************************
void vApplicationStackOverflowHook(xTaskHandle *pxTask, char *pcTaskName)
{
    //
    // This function can not return, so loop forever.  Interrupts are disabled
    // on entry to this function, so no processor interrupts will interrupt
    // this loop.
    //
    while(1)
    {
    }
}