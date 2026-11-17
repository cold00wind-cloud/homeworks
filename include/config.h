#include "stm32f4xx_hal.h"

#define LED_PORT GPIOA

constexpr uint32_t LED_PIN_1 = GPIO_PIN_2;
constexpr uint32_t LED_PIN_2 = GPIO_PIN_3;
constexpr uint32_t LED_PIN_3 = GPIO_PIN_6;
constexpr uint32_t BLINK_DELAY_MS1 = 200;   
constexpr uint32_t BLINK_DELAY_MS2 = 500;   
constexpr uint32_t BLINK_DELAY_MS3 = 1000;   