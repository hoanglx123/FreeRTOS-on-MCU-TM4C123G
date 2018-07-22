/**
 * @file   : main.c
 * @author : Hoang Nguyen (nguyenthanhhoang7604119@gmail.com)
 * @date   : 22 Jul 2018
 * @brief  : Main function to demonstrate how to use tasks in FreeRTOS
 * 
 */

#include <stdbool.h>
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "TaskLed.h"
#include "TaskUart.h"

int main(void)
{
    BaseType_t xReturn;
 
    /* Create led task */
    xReturn = xTaskCreate(LEDTask, (const portCHAR *)"LED", 
                        configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + PRIORITY_LED_TASK, NULL);
    /* Loop forever if error occurs */
    if(pdTRUE != pdTRUE)
    {
        while(1);
    }

    /* Create led task */
    xReturn = xTaskCreate(UARTTask, (const portCHAR *)"LED", 
                        configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + PRIORITY_LED_TASK, NULL);
    /* Loop forever if error occurs */
    if(pdTRUE != pdTRUE)
    {
        while(1);
    }

    return 0;
}