/**
  ******************************************************************************
  * @file    can.c
  * @brief   This file provides code for the configuration
  *          of the CAN instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "can.h"

/* USER CODE BEGIN 0 */
CAN_FilterTypeDef can_filter_template;
CAN_RxHeaderTypeDef can_rx_header;
CAN_TxHeaderTypeDef can_tx_header;
uint8_t can_rx_data[8];
uint8_t TxData[8];
uint8_t count = 0;
uint32_t TxMailbox;
CanDataFrameInit CanFrame;
/* USER CODE END 0 */

CAN_HandleTypeDef hcan;

/* CAN init function */
void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */

  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */

  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 9;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_13TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = DISABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = DISABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */

  /* USER CODE END CAN_Init 2 */

}

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspInit 0 */

  /* USER CODE END CAN1_MspInit 0 */
    /* CAN1 clock enable */
    __HAL_RCC_CAN1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**CAN GPIO Configuration
    PA11     ------> CAN_RX
    PA12     ------> CAN_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* CAN1 interrupt Init */
    HAL_NVIC_SetPriority(CAN1_RX1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(CAN1_RX1_IRQn);
  /* USER CODE BEGIN CAN1_MspInit 1 */




  /* USER CODE END CAN1_MspInit 1 */
  }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{

  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspDeInit 0 */

  /* USER CODE END CAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CAN1_CLK_DISABLE();

    /**CAN GPIO Configuration
    PA11     ------> CAN_RX
    PA12     ------> CAN_TX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_11|GPIO_PIN_12);

    /* CAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(CAN1_RX1_IRQn);
  /* USER CODE BEGIN CAN1_MspDeInit 1 */

  /* USER CODE END CAN1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

void CanInit(CAN_HandleTypeDef *chosen_network) {
	// First we use HAL_CAN_Start to activate can peripherial
  if (HAL_CAN_Start(chosen_network) != HAL_OK) {
		Error_Handler();
	}

  // Then we use HAL_CAN_ActivateNotification to enable receive and transmission
	if (HAL_CAN_ActivateNotification(&chosen_network,
	CAN_IT_RX_FIFO0_MSG_PENDING | CAN_IT_TX_MAILBOX_EMPTY) != HAL_OK) {
		Error_Handler();
	}
}

// Function for saving data after receiving it
void CanSaveReceivedData(CAN_HandleTypeDef chosen_network, CanDataFrameInit *ptr_can_rx_frame_template) {
	if (HAL_CAN_GetRxMessage(&chosen_network, CAN_RX_FIFO0, &ptr_can_rx_frame_template->rx_header,
			ptr_can_rx_frame_template->rx_data) != HAL_OK) {
		/* Reception Error */
		Error_Handler();
	}
}


void CanSendFrame(CAN_HandleTypeDef chosen_network, uint32_t frameId,
		uint8_t number_of_bytes, CanDataFrameInit *ptr_can_frame_template,
		uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3,
		uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7) {
	
  // Putting data into container
  ptr_can_frame_template->tx_header.StdId = frameId;
	ptr_can_frame_template->tx_header.RTR = CAN_RTR_DATA;
	ptr_can_frame_template->tx_header.IDE = CAN_ID_STD;
	ptr_can_frame_template->tx_header.DLC = number_of_bytes;
	ptr_can_frame_template->tx_header.TransmitGlobalTime = DISABLE;
	ptr_can_frame_template->tx_data[0] = byte0;
	ptr_can_frame_template->tx_data[1] = byte1;
	ptr_can_frame_template->tx_data[2] = byte2;
	ptr_can_frame_template->tx_data[3] = byte3;
	ptr_can_frame_template->tx_data[4] = byte4;
	ptr_can_frame_template->tx_data[5] = byte5;
	ptr_can_frame_template->tx_data[6] = byte6;
	ptr_can_frame_template->tx_data[7] = byte7;

	if (HAL_CAN_AddTxMessage(&chosen_network,
			&ptr_can_frame_template->tx_header, ptr_can_frame_template->tx_data,
			&TxMailbox) != HAL_OK) {
		Error_Handler();
	}

	while (HAL_CAN_GetTxMailboxesFreeLevel(&chosen_network) != 3) {
	}

	CanClearTxDataFrame(ptr_can_frame_template);
}

void CanConfigFilter(CAN_HandleTypeDef chosen_network, uint8_t can_filter_bank) {
	can_filter_template.FilterBank = can_filter_bank;
	can_filter_template.FilterMode = CAN_FILTERMODE_IDMASK;
	can_filter_template.FilterScale = CAN_FILTERSCALE_32BIT;
	can_filter_template.FilterIdHigh = 0x0000;
	can_filter_template.FilterIdLow = 0x0000;
	can_filter_template.FilterMaskIdHigh = 0x0000;
	can_filter_template.FilterMaskIdLow = 0x0000;
	can_filter_template.FilterFIFOAssignment = CAN_RX_FIFO0;
	can_filter_template.FilterActivation = ENABLE;
	can_filter_template.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(&chosen_network, &can_filter_template) != HAL_OK) {
		Error_Handler();
	}

}

void CanClearTxDataFrame(CanDataFrameInit *ptr_can_frame_template) {
	ptr_can_frame_template->tx_header.StdId = 0x00;
	ptr_can_frame_template->tx_header.RTR = CAN_RTR_DATA;
	ptr_can_frame_template->tx_header.IDE = CAN_ID_STD;
	ptr_can_frame_template->tx_header.DLC = 0;
	ptr_can_frame_template->tx_header.TransmitGlobalTime = DISABLE;

	ptr_can_frame_template->tx_data[0] = 0x0;
	ptr_can_frame_template->tx_data[1] = 0x0;
	ptr_can_frame_template->tx_data[2] = 0x0;
	ptr_can_frame_template->tx_data[3] = 0x0;
	ptr_can_frame_template->tx_data[4] = 0x0;
	ptr_can_frame_template->tx_data[5] = 0x0;
	ptr_can_frame_template->tx_data[6] = 0x0;
	ptr_can_frame_template->tx_data[7] = 0x0;
}


void CanClearRxDataFrame(CanDataFrameInit *ptr_can_frame_template) {
	ptr_can_frame_template->rx_header.StdId = 0x00;
	ptr_can_frame_template->rx_header.RTR = CAN_RTR_DATA;
	ptr_can_frame_template->rx_header.IDE = CAN_ID_STD;
	ptr_can_frame_template->rx_header.DLC = 0;

	ptr_can_frame_template->rx_data[0] = 0x0;
	ptr_can_frame_template->rx_data[1] = 0x0;
	ptr_can_frame_template->rx_data[2] = 0x0;
	ptr_can_frame_template->rx_data[3] = 0x0;
	ptr_can_frame_template->rx_data[4] = 0x0;
	ptr_can_frame_template->rx_data[5] = 0x0;
	ptr_can_frame_template->rx_data[6] = 0x0;
	ptr_can_frame_template->rx_data[7] = 0x0;
}



/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
