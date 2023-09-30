/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void clearAllClock();
void setNumberOnClock(int num);
void clearNumberOnClock(int num);

void clearAllClock()
{
	HAL_GPIO_WritePin(GPIOA, L1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, L2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, L3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, L4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, L5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, L6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, L7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, L8_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, L9_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, L10_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, L11_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, L12_Pin, GPIO_PIN_RESET);
}

void setNumberOnClock(int num)
{
	if(num == 1) HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
	if(num == 2) HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
	if(num == 3) HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
	if(num == 4) HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_SET);
	if(num == 5) HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_SET);
	if(num == 6) HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_SET);
	if(num == 7) HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_SET);
	if(num == 8) HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_SET);
	if(num == 9) HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_SET);
	if(num == 10) HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_SET);
	if(num == 11) HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_SET);
	if(num == 0) HAL_GPIO_WritePin(L12_GPIO_Port, L12_Pin, GPIO_PIN_SET);
}

void clearNumberOnClock(int num)
{
	if(num == 1) HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
	if(num == 2) HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
	if(num == 3) HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
	if(num == 4) HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
	if(num == 5) HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_RESET);
	if(num == 6) HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_RESET);
	if(num == 7) HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_RESET);
	if(num == 8) HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_RESET);
	if(num == 9) HAL_GPIO_WritePin(L9_GPIO_Port, L9_Pin, GPIO_PIN_RESET);
	if(num == 10) HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_RESET);
	if(num == 11) HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_RESET);
	if(num == 0) HAL_GPIO_WritePin(L12_GPIO_Port, L12_Pin, GPIO_PIN_RESET);
}
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  // initial hour, minute, second
  int count_second = 0;
  int count_minute = 0;
  int count_hour = 1;

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  //---------- hien thuc kim giay-----------
	  if(count_second == 60)// kim giay chay du 5 vong
	  {
		  // kiem tra dieu kien kim gio, phut, giay trung nhau
		  if((count_second/5 - 1) != (count_minute/5) && (count_second/5 - 1) != count_hour)
		  {
			  //xoa kim giay, tao hieu ung chuyen dong
			  clearNumberOnClock(count_second/5 - 1);
		  }
		  count_minute ++;// cap nhat minute
		  count_second = 0;// reset second ve 0
	  }

	  // kiem tra dieu kien kim gio, phut, giay trung nhau
	  if((count_second/5 - 1) != (count_minute/5) && (count_second/5 - 1) != count_hour)
	  {
		  clearNumberOnClock(count_second/5 - 1);
	  }
	  // hien thi kim giay
	  setNumberOnClock(count_second/5);
	  count_second ++;

	  //--------- hien thuc kim phut----------
	  if(count_minute == 60)//kim phut chay du 1 vong
	  {
		  // kiem tra dieu kien kim gio, phut, giay trung nhau
		  if((count_minute/5 -1) != (count_second/5) && (count_minute/5 -1) != count_hour)
		  {
			  //xoa kim phut, tao hieu ung chuyen dong
			  clearNumberOnClock(count_minute/5 -1);
		  }
		  count_hour ++;// cap nhat kim gio
		  count_minute = 0;// reset kim phut ve 0
	  }

	  // kiem tra dieu kien kim gio, phut, giay trung nhau
	  if((count_minute/5 -1) != (count_second/5) && (count_minute/5 -1) != count_hour)
	  {
		  //xoa kim phut, tao hieu ung chuyen dong
		  clearNumberOnClock(count_minute/5 -1);
	  }
	  // hien thi kim phut
	  setNumberOnClock(count_minute/5);

	  // ------------hien thuc kim gio------------
	  if(count_hour == 12)// kim gio quay duoc 1 vong
	  {
		  // kiem tra dieu kien kim gio, phut, giay trung nhau
		  if((count_hour -1) != (count_minute/5) && (count_hour -1) != (count_second/5))
		  {
			  //xoa kim gio, tao hieu ung chuyen dong
			  clearNumberOnClock(count_hour -1);
		  }
		  count_hour = 0;// reset kim phut ve 0
	  }
	  // kiem tra dieu kien kim gio, phut, giay trung nhau
	  if((count_hour -1) != (count_minute/5) && (count_hour -1) != (count_second/5))
	  {
		  //xoa kim gio, tao hieu ung chuyen dong
		  clearNumberOnClock(count_hour -1);
	  }
	  // hien thi kim gio
	  setNumberOnClock(count_hour);

	  HAL_Delay(50);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
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
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, L1_Pin|L2_Pin|L3_Pin
                          |L4_Pin|L5_Pin|L6_Pin|L7_Pin
                          |L8_Pin|L9_Pin|L10_Pin|L11_Pin|L12_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : L0_Pin L1_Pin L2_Pin L3_Pin
                           L4_Pin L5_Pin L6_Pin L7_Pin
                           L8_Pin L9_Pin L10_Pin L11_Pin */
  GPIO_InitStruct.Pin = L1_Pin|L2_Pin|L3_Pin
                          |L4_Pin|L5_Pin|L6_Pin|L7_Pin
                          |L8_Pin|L9_Pin|L10_Pin|L11_Pin|L12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
void assert_faiL(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
