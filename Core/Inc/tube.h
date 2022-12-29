#ifndef __TUBE_H__
#define __TUBE_H__
#include "main.h"
namespace nixie
{
    class TUBE
    {
    private:
        bool status = false;
        const int num_mapping[10] = {0, 2, 8, 9, 3, 7, 6, 4, 5, 1};

    public:
        TUBE();
        ~TUBE();
        void disp(int num);
    };

    class TUBES : public TUBE
    {
    private:
        uint8_t current_lightning_tube;
        GPIO_TypeDef *Tube_GPIO_Port[4] = {Tube_1_GPIO_Port, Tube_2_GPIO_Port, Tube_3_GPIO_Port, Tube_4_GPIO_Port};
        const uint16_t Tube_Pin[4] = {Tube_1_Pin, Tube_2_Pin, Tube_3_Pin, Tube_4_Pin};

    public:
        TUBES();
        void next_tube();
    };
}
#endif