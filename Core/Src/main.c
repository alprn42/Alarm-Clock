/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef hrtc;

/* USER CODE BEGIN PV */
uint8_t alarmflag = 0;
RTC_TimeTypeDef sTime = {0};
RTC_AlarmTypeDef sAlarm = {0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_RTC_Init(void);
static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  sAlarm.AlarmTime.Hours = 9;
  sAlarm.AlarmTime.Minutes = 16;
  sAlarm.AlarmTime.Seconds = 20;
  sAlarm.Alarm = RTC_ALARM_A;
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  HAL_Delay(100);
	  RTC_TimeTypeDef tmpTime;
	  RTC_AlarmTypeDef tmpAlarm;
	  HAL_RTC_GetTime(&hrtc, &tmpTime, RTC_FORMAT_BIN);
	  HAL_RTC_GetAlarm(&hrtc, &tmpAlarm, RTC_ALARM_A, RTC_FORMAT_BIN);

	  if(alarmflag == 0) {
		  uint8_t secFirstDigit = tmpTime.Seconds%10;
		  uint8_t secSecondDigit = tmpTime.Seconds/10;

	  	  //uint8_t secFirstDigit = alarmflag?(tmpAlarm.AlarmTime.Seconds%10):(tmpTime.Seconds%10);
	  	  //uint8_t secSecondDigit = alarmflag?(tmpAlarm.AlarmTime.Seconds/10):(tmpTime.Seconds/10);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, secFirstDigit & 0x01);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, secFirstDigit & 0x02);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, secFirstDigit & 0x04);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, secFirstDigit & 0x08);

			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, secSecondDigit & 0x01);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, secSecondDigit & 0x02);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, secSecondDigit & 0x04);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, secSecondDigit & 0x08);

	  	  uint8_t minFirstDigit = tmpTime.Minutes%10;
	  	  uint8_t minSecondDigit = tmpTime.Minutes/10;

	  	  //uint8_t minFirstDigit = alarmflag?(tmpAlarm.AlarmTime.Minutes%10):(tmpTime.Minutes%10);
	  	  //uint8_t minSecondDigit = alarmflag?(tmpAlarm.AlarmTime.Minutes/10):(tmpTime.Minutes/10);

		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, minFirstDigit & 0x01);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, minFirstDigit & 0x02);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, minFirstDigit & 0x04);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, minFirstDigit & 0x08);

		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, minSecondDigit & 0x01);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, minSecondDigit & 0x02);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, minSecondDigit & 0x04);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, minSecondDigit & 0x08);

	  	  uint8_t hourFirstDigit = tmpTime.Hours%10;
	  	  uint8_t hourSecondDigit = tmpTime.Hours/10;

	  	  //uint8_t hourFirstDigit = alarmflag?(tmpAlarm.AlarmTime.Hours%10):(tmpTime.Hours%10);
	  	  //uint8_t hourSecondDigit = alarmflag?(tmpAlarm.AlarmTime.Hours/10):(tmpTime.Hours/10);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, hourFirstDigit & 0x01);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, hourFirstDigit & 0x02);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, hourFirstDigit & 0x04);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, hourFirstDigit & 0x08);

		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, hourSecondDigit & 0x01);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, hourSecondDigit & 0x02);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, hourSecondDigit & 0x04);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, hourSecondDigit & 0x08);
	  }
	  else if (alarmflag == 1) {
		  uint8_t secFirstDigit = tmpAlarm.AlarmTime.Seconds%10;
		  uint8_t secSecondDigit = tmpAlarm.AlarmTime.Seconds/10;

		  //uint8_t secFirstDigit = alarmflag?(tmpAlarm.sAlarm.AlarmTime.Seconds%10):(tmpTime.Seconds%10);
		  //uint8_t secSecondDigit = alarmflag?(tmpAlarm.AlarmTime.Seconds/10):(tmpTime.Seconds/10);

		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, secFirstDigit & 0x01);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, secFirstDigit & 0x02);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, secFirstDigit & 0x04);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, secFirstDigit & 0x08);

		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, secSecondDigit & 0x01);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, secSecondDigit & 0x02);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, secSecondDigit & 0x04);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, secSecondDigit & 0x08);

		  uint8_t minFirstDigit = tmpAlarm.AlarmTime.Minutes%10;
		  uint8_t minSecondDigit = tmpAlarm.AlarmTime.Minutes/10;

		  //uint8_t minFirstDigit = alarmflag?(tmpAlarm.AlarmTime.Minutes%10):(tmpTime.Minutes%10);
		  //uint8_t minSecondDigit = alarmflag?(tmpAlarm.AlarmTime.Minutes/10):(tmpTime.Minutes/10);

		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, minFirstDigit & 0x01);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, minFirstDigit & 0x02);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, minFirstDigit & 0x04);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, minFirstDigit & 0x08);

			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, minSecondDigit & 0x01);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, minSecondDigit & 0x02);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, minSecondDigit & 0x04);
			  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, minSecondDigit & 0x08);
		  uint8_t hourFirstDigit = tmpAlarm.AlarmTime.Hours%10;
		  uint8_t hourSecondDigit = tmpAlarm.AlarmTime.Hours/10;

		  //uint8_t hourFirstDigit = alarmflag?(tmpAlarm.AlarmTime.Hours%10):(tmpTime.Hours%10);
		  //uint8_t hourSecondDigit = alarmflag?(tmpAlarm.AlarmTime.Hours/10):(tmpTime.Hours/10);


		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, hourFirstDigit & 0x01);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, hourFirstDigit & 0x02);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, hourFirstDigit & 0x04);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, hourFirstDigit & 0x08);

		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, hourSecondDigit & 0x01);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, hourSecondDigit & 0x02);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, hourSecondDigit & 0x04);
		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, hourSecondDigit & 0x08);
	  }

	 if (tmpAlarm.AlarmTime.Hours == tmpTime.Hours) {
		  if (tmpAlarm.AlarmTime.Minutes == tmpTime.Minutes) {
			  if(tmpAlarm.AlarmTime.Seconds == tmpTime.Seconds) {
				  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
				  HAL_Delay(200);
				  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_11);
				  HAL_Delay(200);
				  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);
				  HAL_Delay(200);
				  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
				  HAL_Delay(200);


			  }
		  }
	  }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* PVD_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(PVD_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(PVD_IRQn);
  /* RTC_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(RTC_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(RTC_IRQn);
  /* FLASH_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(FLASH_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(FLASH_IRQn);
  /* RCC_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(RCC_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(RCC_IRQn);
  /* EXTI2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);
  /* EXTI3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);
  /* EXTI4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);
  /* EXTI9_5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
  /* RTC_Alarm_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(RTC_Alarm_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(RTC_Alarm_IRQn);
  /* EXTI1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);
}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef DateToUpdate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only 
  */
  hrtc.Instance = RTC;
  hrtc.Init.AsynchPrediv = RTC_AUTO_1_SECOND;
  hrtc.Init.OutPut = RTC_OUTPUTSOURCE_NONE;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date 
  */
  sTime.Hours = 9;
  sTime.Minutes = 15;
  sTime.Seconds = 15;

  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  DateToUpdate.WeekDay = RTC_WEEKDAY_MONDAY;
  DateToUpdate.Month = RTC_MONTH_JANUARY;
  DateToUpdate.Date = 1;
  DateToUpdate.Year = 0;

  if (HAL_RTC_SetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8 
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12 
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10 
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7 
                          |GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : AlarmSet_Pin SecondPlus_Pin SecondMinus_Pin MinutePlus_Pin 
                           MinuteMinus_Pin HourPlus_Pin HourMinus_Pin */
  GPIO_InitStruct.Pin = AlarmSet_Pin|SecondPlus_Pin|SecondMinus_Pin|MinutePlus_Pin 
                          |MinuteMinus_Pin|HourPlus_Pin|HourMinus_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA1 PA2 PA3 PA4 
                           PA5 PA6 PA7 PA8 
                           PA9 PA10 PA11 PA12 
                           PA13 PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8 
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12 
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB3 
                           PB4 PB5 PB6 PB7 
                           PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7 
                          |GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB11 PB12 PB13 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	UNUSED(GPIO_Pin);
	switch(GPIO_Pin) {
		case AlarmSet_Pin: if (alarmflag) alarmflag = 0; else alarmflag = 1; break;
		case SecondPlus_Pin: if (alarmflag) sAlarm.AlarmTime.Seconds++; break;
		case MinutePlus_Pin: if (alarmflag) sAlarm.AlarmTime.Minutes++; break;
		case HourPlus_Pin: if (alarmflag) sAlarm.AlarmTime.Hours++; break;
		case SecondMinus_Pin: if (alarmflag) sAlarm.AlarmTime.Seconds--; break;
		case MinuteMinus_Pin: if (alarmflag) sAlarm.AlarmTime.Minutes--; break;
		case HourMinus_Pin: if (alarmflag) sAlarm.AlarmTime.Hours--; break;
	}
	if(alarmflag) HAL_RTC_SetAlarm(&hrtc, &sAlarm, RTC_FORMAT_BIN);

}
void HAL_RTC_AlarmEventCallBack(RTC_HandleTypeDef *hrtc) {
	UNUSED(hrtc);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
