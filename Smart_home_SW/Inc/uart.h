/*
 * uart.h
 *
 *  Created on: Oct 18, 2019
 *      Author: pasztoradam
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_cortex.h"
#include "stm32f4xx_hal_uart.h"
#include "stm32_hal_legacy.h"

void UART_Init();
void UARTSendString(char* data);
void UARTReceiveString(char* data);


#endif /* INC_UART_H_ */
