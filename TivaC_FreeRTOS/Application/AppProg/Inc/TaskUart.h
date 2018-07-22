/**
 * @file   : TaskUart.h
 * @author : Hoang Nguyen (nguyenthanhhoang7604119@gmail.com)
 * @date   : 22 Jul 2018
 * @brief  : File containing definitions of Uart task.
 * 
 */

#ifndef _TASK_UART_H_
#define _TASK_UART_H_

#define PRIORITY_UART_TASK   1

/* Prototype */
extern void UARTTask(void *pData); 

#endif /*  _TASK_UART_H_ */