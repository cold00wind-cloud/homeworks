#include "stm32f4xx_hal.h"
#include "led.h"

#define LED_PORT GPIOC;

constexpr uint32_t LED_PIN = GPIO_PIN_13;
constexpr uint32_t BLINK_DELAY_MS = 500;   
static Led led = {.port = GPIOC, .pin = LED_PIN, .active = GPIO_PIN_RESET};   

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
    HAL_Init();
    led_init(&led);
    uint32_t last_change = 0;
    bool isOn = false;

    while (1)
    {
        if(HAL_GetTick() - last_change >= BLINK_DELAY_MS){
            last_change = HAL_GetTick();
            led_set(&led, isOn ? OFF : ON);
            isOn = !isOn;
        }
    }
    
}
