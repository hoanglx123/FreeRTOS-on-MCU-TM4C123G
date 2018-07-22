/**
 * @file   : TaskUart.c
 * @author : Hoang Nguyen (nguyenthanhhoang7604119@gmail.com)
 * @date   : 22 Jul 2018
 * @brief  : Configure port for uart and implement uart task 
 * 
 */

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/rom.h"
#include "uartstdio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "TaskUart.h"

/* Prototype */
static void configUART();

void UARTTask(void *pData)
{
    uint32_t UARTVal = GPIO_PIN_3;
    char     cInput  = '\0';

    /* Configure GPIO for UART */
    configUART(); 

    UARTprintf("Input your character:");
    while(1)
    {
        cInput = UARTgetc();
        UARTprintf("%c", cInput);
    }
}

void configUART()
{
    //
    // Enable the GPIO Peripheral used by the UART.
    //
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    //
    // Enable UART0
    //
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    //
    // Configure GPIO Pins for UART mode.
    //
    ROM_GPIOPinConfigure(GPIO_PA0_U0RX);
    ROM_GPIOPinConfigure(GPIO_PA1_U0TX);
    ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    //
    // Use the internal 16MHz oscillator as the UART clock source.
    //
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    //
    // Initialize the UART for console I/O.
    //
    UARTStdioConfig(0, 115200, 16000000);
}