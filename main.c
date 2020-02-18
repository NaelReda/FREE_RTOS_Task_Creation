#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "FreeRTOS.h"                   // ARM.FreeRTOS::RTOS:Core
#include "task.h"                       // ARM.FreeRTOS::RTOS:Core
#include "FreeRTOSConfig.h"             // ARM.FreeRTOS::RTOS:Config


#define LED        (1U<<5)
#define LED_BIT       (1U<<10)
#define GPIOA_CLK     (1U<<0)

uint32_t count,count2,counter;

void LED2_Init(void);
void LED2_ON(void);
void LED2_OFF(void);

void LED2_OFF_TASK(void *argument);
void LED2_ON_TASK(void *argument);
void Test_TASK(void *argument);

int main(void)
{
	LED2_Init();
	xTaskCreate(LED2_ON_TASK,"Switching LED2 ON",100,NULL,2,NULL);
	xTaskCreate(LED2_OFF_TASK,"Switching LED2 OFF",100,NULL,2,NULL);
		xTaskCreate(Test_TASK,"TEST_TASK",100,NULL,2,NULL);
  vTaskStartScheduler();	
	while(1)
	{

	}
}

void LED2_Init(void)
{
	RCC->AHB1ENR  |=GPIOA_CLK;
	GPIOA->MODER  |=LED_BIT;	
}
void LED2_ON(void)
{
	GPIOA->ODR |=LED;	
}
void LED2_OFF(void)
{
	GPIOA->ODR &=~LED;
}


void LED2_ON_TASK(void *argument)     
{
	while(1)
	{
		++count;
		LED2_ON();
	}	
}
void LED2_OFF_TASK(void *argument)   
{
	while(1)
	{
		++count2;
		LED2_OFF();		
	}	
}
void Test_TASK(void *argument)   
{
	while(1)
	{
			++counter;
	}	
}
