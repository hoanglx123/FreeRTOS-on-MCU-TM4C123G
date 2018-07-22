/**
 * @file   : TaskLed.h
 * @author : Hoang Nguyen (nguyenthanhhoang7604119@gmail.com)
 * @date   : 22 Jul 2018
 * @brief  : File containing definitions of LED task.
 * 
 */

#ifndef _TASK_LED_H_
#define _TASK_LED_H_

/**
 * @brief Macro definitions.
 *
 */
#define PRIORITY_LED_TASK   1       /* Priority for Led task */

/**
 * @brief Prototypes.
 *
 */
extern void LEDTask(void *pData); 

#endif /*  _TASK_LED_H_ */