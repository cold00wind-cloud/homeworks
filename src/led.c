#include "stm32f4xx_hal.h"
#include "led.h"

void led_init(Led *led)
{
    __HAL_RCC_GPIOC_CLK_ENABLE();
    // вимикаю діод
    HAL_GPIO_WritePin(
        led->port, led->pin, led->active == GPIO_PIN_SET ? GPIO_PIN_RESET : GPIO_PIN_SET);

    GPIO_InitTypeDef gpio = {0};
    gpio.Pin = led->pin;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(led->port, &gpio);
}

void led_set(Led *led, LED_STATE state)
{
    switch (state)
    {
    case ON:  HAL_GPIO_WritePin(led->port, led->pin, led->active); break;
    case OFF: HAL_GPIO_WritePin(led->port, led->pin, led->active == GPIO_PIN_SET ? GPIO_PIN_RESET : GPIO_PIN_SET); break;
    default: break;
    }
}