/**
  ******************************************************************************
  * @file    can.h
  * @brief   This file contains all the function prototypes for
  *          the can.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CAN_H__
#define __CAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern CAN_HandleTypeDef hcan;

/* USER CODE BEGIN Private defines */

// Struct to hold onto data 
typedef struct {
	uint8_t tx_data[8];
	CAN_TxHeaderTypeDef tx_header;
	CAN_RxHeaderTypeDef rx_header;
	uint8_t rx_data[8];
} CanDataFrameInit;

// Variables made extern to use in interrupts and main
extern CanDataFrameInit CanFrame;
/* USER CODE END Private defines */

void MX_CAN_Init(void);

/* USER CODE BEGIN Prototypes */

// CAN function for initializing CAN
void CanInit(CAN_HandleTypeDef *hcanx);

// CAN filter configuration function
void CanConfigFilter(CAN_HandleTypeDef hcanx, uint8_t can_filter_bank);

// Function that enables saving data to certain structure
void CanSaveReceivedData(CAN_HandleTypeDef chosen_network, CanDataFrameInit *ptr_can_rx_frame_template);

// Function must clear frame every time after sending to get accurate data
void CanClearTxDataFrame(CanDataFrameInit *can_frame_template);

// Function must clear frame every time after receiving data
void CanClearRxDataFrame(CanDataFrameInit *ptr_can_frame_template);


// Prototype function to sending data via CAN
void CanSendFrame(CAN_HandleTypeDef chosen_network, uint32_t frame_pdo_id,
		uint8_t number_of_bytes, CanDataFrameInit *can_frame_template,
		uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3,
		uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __CAN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
