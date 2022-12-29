#include "tube.h"
namespace nixie
{
    TUBE::TUBE()
    {
        HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
    }
    TUBE::~TUBE()
    {
        HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
    }
    void TUBE::disp(int num)
    {
        if (num > 9 || num < 0)
            return;
        uint8_t pin_out = num_mapping[num];
        uint8_t A = pin_out & 1;
        uint8_t B = (pin_out >> 1) & 1;
        uint8_t C = (pin_out >> 2) & 1;
        uint8_t D = (pin_out >> 3) & 1;
        HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, (GPIO_PinState)A);
        HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, (GPIO_PinState)B);
        HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, (GPIO_PinState)C);
        HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, (GPIO_PinState)D);
    }
    TUBES::TUBES()
    {
        HAL_GPIO_WritePin(Tube_1_GPIO_Port, Tube_1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(Tube_2_GPIO_Port, Tube_2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Tube_3_GPIO_Port, Tube_3_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(Tube_4_GPIO_Port, Tube_4_Pin, GPIO_PIN_SET);
    }

    void TUBES::next_tube()
    {
        HAL_GPIO_WritePin(Tube_GPIO_Port[current_lightning_tube], Tube_Pin[current_lightning_tube], GPIO_PIN_RESET);
        HAL_Delay(1);
        HAL_GPIO_WritePin(Tube_GPIO_Port[++current_lightning_tube], Tube_Pin[++current_lightning_tube], GPIO_PIN_SET);
    }
}