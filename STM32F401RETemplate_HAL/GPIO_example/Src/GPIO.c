#include "GPIO.h"

#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_rcc.h"

void GPIOA_init(){ 
__HAL_RCC_GPIOA_CLK_ENABLE();
GPIO_InitTypeDef GPIOA_InitSruct = { 0 } ; 
GPIOA_InitSruct.Pin= LD2_Pin ; 
GPIOA_InitSruct.Mode = GPIO_MODE_OUTPUT_PP ; 
GPIOA_InitSruct.Pull = GPIO_NOPULL ; 
GPIOA_InitSruct.Speed = GPIO_SPEED_LOW; 
HAL_GPIO_Init(LD2_GPIO_Port,&GPIOA_InitSruct ) ; 

}

void BTN_init(){ 
__HAL_RCC_GPIOC_CLK_ENABLE(); 
GPIO_InitTypeDef BTN_InitStruct = { 0 } ; 
BTN_InitStruct.Pin = B1_Pin ; 
BTN_InitStruct.Mode = GPIO_MODE_IT_RISING ; 
// BTN_InitStruct.Mode = GPIO_MODE_INPUT ; 
BTN_InitStruct.Pull = GPIO_PULLUP ; 
BTN_InitStruct.Speed = GPIO_SPEED_LOW ; 
HAL_GPIO_Init(B1_GPIO_Port, &BTN_InitStruct); 
// set up interrupt 
// subpriority 
// preemptpriority : if  interrupts has occured and one is running can i preempt it or not ( the one with higher will win)
// subpriority  if both are pending one is going to execute ( the lower is going to win )
HAL_NVIC_SetPriority(EXTI15_10_IRQn,0,0) ; 
HAL_NVIC_EnableIRQ(EXTI15_10_IRQn) ;
}



