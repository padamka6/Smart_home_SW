/*
 * uart.c
 *
 *  Created on: Oct 18, 2019
 *      Author: pasztoradam
 */


#include "uart.h"

UART_HandleTypeDef UARTHandle;
uint8_t rxBuff[1];

void UART_Init()
{
	GPIO_InitTypeDef portInit;

	__GPIOD_CLK_ENABLE();
	// USART RX,TX - GPIOD Pin Configuration
	portInit.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	portInit.Mode = GPIO_MODE_AF_PP;
	portInit.Pull = GPIO_NOPULL;
	portInit.Speed = GPIO_SPEED_FAST;
	portInit.Alternate = GPIO_AF7_USART3;
	HAL_GPIO_Init(GPIOD, &portInit);

	__USART3_CLK_ENABLE();

	HAL_NVIC_SetPriority(USART3_IRQn,7,0);
	HAL_NVIC_EnableIRQ(USART3_IRQn);
	//Enable USART3 periph clk
	/* USART configured as follow:
				- BaudRate = 115200 baud
				- Word Length = 8 Bits
				- One Stop Bit
				- No parity
				- Hardware flow control disabled (RTS and CTS signals)
				- Receive and transmit enabled
	 */
	UARTHandle.Instance = USART3;
	UARTHandle.Init.BaudRate = 115200;
	UARTHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UARTHandle.Init.StopBits = UART_STOPBITS_1;
	UARTHandle.Init.Parity = UART_PARITY_NONE;
	UARTHandle.Init.Mode = UART_MODE_TX_RX;
	UARTHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	HAL_UART_Init(&UARTHandle);

	HAL_UART_Receive_IT(&UARTHandle,rxBuff, sizeof(rxBuff));
}

void USART3_IRQHandler(void)
{
	HAL_UART_IRQHandler(& UARTHandle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if ( huart->Instance == USART3)
	{
		HAL_UART_Receive_IT(&UARTHandle,rxBuff, sizeof(rxBuff));
	}
}

/* Send a string on USART */
void UARTSendString(char* data)
{
	uint16_t len = 0;
	char* ldata = data;
	while (*ldata)
	{
		len++;
		ldata++;
	}

	HAL_UART_Transmit(&UARTHandle, (uint8_t*)data, len, 1000);
}

