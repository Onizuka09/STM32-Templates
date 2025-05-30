#ifndef GPIO_H 
#define GPIO_H
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"


#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
void GPIOA_init();
void BTN_init(); 



#endif 
