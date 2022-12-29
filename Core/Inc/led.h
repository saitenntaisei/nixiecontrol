#ifndef __LED_H__
#define __LED_H__
#include "main.h"

class LED
{
private:
    bool status = false;
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin;

public:
    LED(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) : GPIOx(GPIOx), GPIO_Pin(GPIO_Pin)
    {
        HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
    };
    ~LED()
    {
        HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
    };
    void toggle();
    void on();
    void off();
    bool get_current_status();
};

#endif
