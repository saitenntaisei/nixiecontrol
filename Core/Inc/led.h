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
    Button(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) : GPIOx(GPIOx), GPIO_Pin(GPIO_Pin){};
    ~Button();
    void Toggle();
    void PullUp();
    void PullDown();
};

#endif
