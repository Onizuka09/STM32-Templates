#include "main.h"
#include "RCC.h"
#include "GPIO.h"
#include "Error_handler.h"
#include "stm32f4xx.h"
#include <stdbool.h>

volatile bool  Flag = false ;  
int main(void)
{
RCC_CLOCK_INIT(); 
GPIOA_init();
BTN_init();
while (1){
  if ( Flag) { 
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15 | GPIO_PIN_15, GPIO_PIN_SET)  ; 
    HAL_Delay(2000);
    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15 | GPIO_PIN_15, GPIO_PIN_RESET)  ; 
    Flag = false ; 
  } else  {
    HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_12 | GPIO_PIN_14 )  ; 
    HAL_Delay(1000); 
// HAL_Delay(2000);
  }
}

}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){ 
 if ( GPIO_Pin == B1_Pin){ 
    Flag= true;   
  //  HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);
// HAL_Delay(2000);

 }
}
void EXTI15_10_IRQHandler(void){ 
  HAL_GPIO_EXTI_IRQHandler(B1_Pin);
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
