/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SW_1_Pin GPIO_PIN_13
#define SW_1_GPIO_Port GPIOC
#define SW_2_Pin GPIO_PIN_14
#define SW_2_GPIO_Port GPIOC
#define SW_3_Pin GPIO_PIN_15
#define SW_3_GPIO_Port GPIOC
#define LED_1_Pin GPIO_PIN_0
#define LED_1_GPIO_Port GPIOB
#define LED_2_Pin GPIO_PIN_1
#define LED_2_GPIO_Port GPIOB
#define LED_3_Pin GPIO_PIN_2
#define LED_3_GPIO_Port GPIOB
#define D_Pin GPIO_PIN_10
#define D_GPIO_Port GPIOB
#define Tube_4_Pin GPIO_PIN_3
#define Tube_4_GPIO_Port GPIOB
#define Tube_3_Pin GPIO_PIN_4
#define Tube_3_GPIO_Port GPIOB
#define Tube_2_Pin GPIO_PIN_5
#define Tube_2_GPIO_Port GPIOB
#define Tube_1_Pin GPIO_PIN_6
#define Tube_1_GPIO_Port GPIOB
#define A_Pin GPIO_PIN_7
#define A_GPIO_Port GPIOB
#define B_Pin GPIO_PIN_8
#define B_GPIO_Port GPIOB
#define C_Pin GPIO_PIN_9
#define C_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
