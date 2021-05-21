/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
	int volatile Number_Of_States=0;
	int volatile Number_Of_States_2=0;
	int volatile Number_Of_Rotations=0;
	int volatile Number_Of_Rotations_2=0;
	int volatile Number_Of_Rotations_3=0;
	int volatile previous_state;
	int volatile previous_state_2;
	float volatile distance_rotation_r=0;
	float volatile distance_rotation_l=0;
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
  MX_USART2_UART_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,0);
	previous_state=HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11);
	int flag=1;
	char temp_directions[]={'F','L','F','R','F'};
	int temp_directions_count=0;
	float volatile distance=0.0;

	previous_state=HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11);
	previous_state_2=HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
   while (1)
  {
       /* USER CODE END WHILE */
		uint8_t direction[] = {0xC1, 0xC9, 0xC1, 0xC9,0xC0};
		uint8_t speed[] = {64, 32, 0};
		
		
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
		
		if(flag==1 && temp_directions[temp_directions_count]=='F')
		{
			HAL_UART_Transmit(&huart1, &direction[0], 1, HAL_MAX_DELAY);
			//HAL_Delay(10);	
			HAL_UART_Transmit(&huart1, &speed[0], 1, HAL_MAX_DELAY);
			HAL_UART_Transmit(&huart1, &direction[1], 1, HAL_MAX_DELAY);
			//HAL_Delay(10);	
			HAL_UART_Transmit(&huart1, &speed[0], 1, HAL_MAX_DELAY);
			distance=Number_Of_Rotations*(12.5/100);
			if(distance >= 0.85){
				temp_directions_count++;
				Number_Of_Rotations=0;
				Number_Of_Rotations_2=0;
				HAL_UART_Transmit(&huart1, &direction[0], 1, HAL_MAX_DELAY);
				HAL_UART_Transmit(&huart1, &speed[2], 1, HAL_MAX_DELAY);
				HAL_UART_Transmit(&huart1, &direction[1], 1, HAL_MAX_DELAY);
				HAL_UART_Transmit(&huart1, &speed[2], 1, HAL_MAX_DELAY);
				HAL_Delay(5000);
			}
		}	
		else if (flag==1 && temp_directions[temp_directions_count]=='L')
		{
		//	while (distance_rotation_l <0.50)
		//	{
			HAL_UART_Transmit(&huart1, &direction[0], 1, HAL_MAX_DELAY);
		//	HAL_Delay(10);	
			HAL_UART_Transmit(&huart1, &speed[0], 1, HAL_MAX_DELAY);
			HAL_UART_Transmit(&huart1, &direction[1], 1, HAL_MAX_DELAY);
			//HAL_Delay(10);	
			HAL_UART_Transmit(&huart1, &speed[2], 1, HAL_MAX_DELAY);
			distance=Number_Of_Rotations_2*(12.5/100);
			if(distance >= 0.75){
				temp_directions_count++;
				Number_Of_Rotations=0;
				Number_Of_Rotations_2=0;
			}
				//distance_rotation_l=Number_Of_Rotations_2*(12.5/100);
			//}
//			Number_Of_Rotations_2=0;
//			temp_directions_count++;
		}
		else if (flag==1 && temp_directions[temp_directions_count]=='R')
		{
//			while (distance_rotation_r <0.50)
//			{
				HAL_UART_Transmit(&huart1, &direction[0], 1, HAL_MAX_DELAY);
			//	HAL_Delay(10);	
				HAL_UART_Transmit(&huart1, &speed[2], 1, HAL_MAX_DELAY);
				HAL_UART_Transmit(&huart1, &direction[1], 1, HAL_MAX_DELAY);
			//	HAL_Delay(10);	
				HAL_UART_Transmit(&huart1, &speed[0], 1, HAL_MAX_DELAY);
				distance=Number_Of_Rotations*(12.5/100);
				if(distance >= .50){
					temp_directions_count++;
					Number_Of_Rotations=0;
					Number_Of_Rotations_2=0;
				}
				//distance_rotation_r=Number_Of_Rotations*(12.5/100);
//			}
//			
//		Number_Of_Rotations=0;	
//		temp_directions_count++;
		}
		
		
//		distance_rotation_l=Number_Of_Rotations_2*(12.5/100);
//		distance_rotation_r=Number_Of_Rotations*(12.5/100);
//		// r=30 --> circle of the car  
//		// 0.47 --> 90 degrees 
//		// 0.235--> 45 defrees 
//		
//		if(distance >= 1.00){
//			temp_directions_count++;
//			Number_Of_Rotations=0;
//		}
//		if(distance_rotation_l >= 0.5){
//			temp_directions_count++;
//			Number_Of_Rotations_2=0;
//		}
//		if(distance_rotation_r >= 0.5){
//			temp_directions_count++;
//			Number_Of_Rotations=0;
//		}
		if(temp_directions_count==5)
		{
			flag=0;
			HAL_UART_Transmit(&huart1, &direction[0], 1, HAL_MAX_DELAY);
			HAL_UART_Transmit(&huart1, &speed[2], 1, HAL_MAX_DELAY);
			HAL_UART_Transmit(&huart1, &direction[1], 1, HAL_MAX_DELAY);
			HAL_UART_Transmit(&huart1, &speed[2], 1, HAL_MAX_DELAY);
		}
		
		
//		if (distance >=1.00)
//		{
//		//	HAL_UART_Transmit(&huart2,"1m",sizeof("1m"),500);
//	//		distance=0;
////			if (temp_directions[temp_directions_count]=='F')
////			{
////				temp_directions_count=temp_directions_count+1;
////			}
//			temp_directions_count=temp_directions_count+1;
//			Number_Of_Rotations=0;
//			if(temp_directions_count==5)
//			{
//				flag=0;
//				HAL_UART_Transmit(&huart1, &direction[0], 1, HAL_MAX_DELAY);
//				HAL_UART_Transmit(&huart1, &speed[2], 1, HAL_MAX_DELAY);
//				HAL_UART_Transmit(&huart1, &direction[1], 1, HAL_MAX_DELAY);
//				HAL_UART_Transmit(&huart1, &speed[2], 1, HAL_MAX_DELAY);
//			}
//		}
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 19200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA11 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
