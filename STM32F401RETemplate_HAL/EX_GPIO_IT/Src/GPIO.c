#include "GPIO.h"

#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_rcc.h"

void GPIOA_init(){ 
__HAL_RCC_GPIOD_CLK_ENABLE();
GPIO_InitTypeDef GPIOD_InitSruct = { 0 } ; 
GPIOD_InitSruct.Pin= GPIO_PIN_13 | GPIO_PIN_12 | GPIO_PIN_14 | GPIO_PIN_15 ; 
GPIOD_InitSruct.Mode = GPIO_MODE_OUTPUT_PP ; 
GPIOD_InitSruct.Pull = GPIO_PULLDOWN ; 
GPIOD_InitSruct.Speed = GPIO_SPEED_LOW; 
HAL_GPIO_Init(LD2_GPIO_Port,&GPIOD_InitSruct ) ; 

}

void BTN_init(){ 
__HAL_RCC_GPIOC_CLK_ENABLE(); 
GPIO_InitTypeDef BTN_InitStruct = { 0 } ; 
BTN_InitStruct.Pin = B1_Pin ; 
BTN_InitStruct.Mode = GPIO_MODE_IT_RISING ; 
// BTN_InitStruct.Mode = GPIO_MODE_INPUT ; 
BTN_InitStruct.Pull = GPIO_PULLUP ; 
HAL_GPIO_Init(B1_GPIO_Port, &BTN_InitStruct); 
// set up interrupt 
// subpriority 
// preemptpriority : if  interrupts has occured and one is running can i preempt it or not ( the one with higher will win)
// subpriority  if both are pending one is going to execute ( the lower is going to win )
HAL_NVIC_SetPriority(EXTI15_10_IRQn,1,0) ; 
HAL_NVIC_EnableIRQ(EXTI15_10_IRQn) ;
}



