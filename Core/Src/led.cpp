#include "led.h"

void LED::Toggle()
{
    status = !status;
    HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}

void LED::PullUp()
{
    status = true;
}

void LED::PullDown()
{
    status = false;
}