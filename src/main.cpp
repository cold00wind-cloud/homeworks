#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include "led.h"
#include "config.h"

#ifdef __cplusplus
extern "C"
{
#endif
    
    void SysTick_Handler(void)
    {
        HAL_IncTick();
    }
#ifdef __cplusplus
}
#endif


int main(void){
    __HAL_RCC_GPIOA_CLK_ENABLE();
    Led led1 = {.port = LED_PORT, .pin = LED_PIN_1, .active = GPIO_PIN_SET};   
    Led led2 = {.port = LED_PORT, .pin = LED_PIN_2, .active = GPIO_PIN_SET};   
    Led led3 = {.port = LED_PORT, .pin = LED_PIN_3, .active = GPIO_PIN_SET};   
    HAL_Init();
    led_init(&led1);
    led_init(&led2);
    led_init(&led3);
    uint32_t last_change1 = 0;
    uint32_t last_change2 = 0;
    uint32_t last_change3 = 0;
    bool isOn1 = false;
    bool isOn2 = false;
    bool isOn3 = false;
    
    while (1)
    {
        if(HAL_GetTick() - last_change1 >= BLINK_DELAY_MS1){
            last_change1 = HAL_GetTick();
            led_set(&led1, isOn1 ? OFF : ON);
            isOn1 = !isOn1;
        }
        if(HAL_GetTick() - last_change2 >= BLINK_DELAY_MS2){
            last_change2 = HAL_GetTick();
            led_set(&led2, isOn2 ? OFF : ON);
            isOn2 = !isOn2;
        }
        if(HAL_GetTick() - last_change3 >= BLINK_DELAY_MS3){
            last_change3 = HAL_GetTick();
            led_set(&led3, isOn3 ? OFF : ON);
            isOn3 = !isOn3;
        }
    }
    
}
