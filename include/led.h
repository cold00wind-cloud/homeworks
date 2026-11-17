#include "stm32f4xx_hal.h"
#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum
    {
        OFF = 0,
        ON,
    } LED_STATE;

    typedef struct
    {
        GPIO_TypeDef *port;
        uint16_t pin;
        GPIO_PinState active;
    } Led;

    void led_init(Led *led);
    void led_set(Led *led, LED_STATE state);
#ifdef __cplusplus
}
#endif