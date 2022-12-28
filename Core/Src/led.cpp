#include "led.h"

void LED::toggle()
{
    status = !status;
    HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}

void LED::on()
{
    status = true;
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
}

void LED::off()
{
    status = false;
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
}

bool LED::get_current_status()
{
    return status;
}