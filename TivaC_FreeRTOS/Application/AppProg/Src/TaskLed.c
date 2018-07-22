/**
 * @file   : TaskLed.c
 * @author : Hoang Nguyen (nguyenthanhhoang7604119@gmail.com)
 * @date   : 22 Jul 2018
 * @brief  : Configure port for LED and implement Led task 
 * 
 */

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "TaskLed.h"

/* Prototype */
static void configLED();

void LEDTask(void *pData)
{
    uint32_t LedVal = GPIO_PIN_3;

    /* Configure GPIO for LED */
    configLED(); 

    while(1)
    {
        /* Turn on the LED. */
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, LedVal);
        vTaskDelay(1000);

        /* Set LED value */
        LedVal ^= GPIO_PIN_3; 
    }
}

void configLED()
{
    /* Enable the GPIO port that is used for the on-board LED. */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    /* Check if the peripheral access is enabled. */
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }

    /* Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
     * enable the GPIO pin for digital function.
     */
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);
}