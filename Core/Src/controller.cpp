#include "controller.h"

CONTROLLER::CONTROLLER()
{

    status = normal;
    content = Sec;
    ltime = 0;
    tubes = std::make_shared<nixie::TUBES>();
    pos = 0;
}

void CONTROLLER::changeDisp(Content currentContent)
{
    content = currentContent;
}
void CONTROLLER::changeDisp()
{
    content = (Content)((content + 1) % ContentSize);
}
void CONTROLLER::changeStatus()
{
    status = (Status)!status;
}
void CONTROLLER::disp()
{
    auto current_time = gmtime(&ltime);
    uint8_t sec = current_time->tm_sec;
    uint8_t minute = current_time->tm_min;
    uint8_t hour = current_time->tm_hour;
    uint8_t day = current_time->tm_mday;
    uint8_t month = current_time->tm_mon + 1;     // month is 0-indexed so need to add 1
    uint16_t year = current_time->tm_year + 1900; // need to add 1900
    uint16_t wday = current_time->tm_wday;
    uint16_t blink_pos = 0;
    if (pos != 0)
    {
        blink_pos = (1 << (pos - 1));
    }
    switch (content)
    {
    case Year:
        tubes->disp(year, blink_pos);
        break;
    case Day:
        tubes->disp(month, day, blink_pos);
        break;
    case Hour:
        tubes->disp(hour, minute, blink_pos);
        break;
    case Sec:
        tubes->disp(sec, wday, blink_pos);
        break;
    default:
        break;
    }
}

void CONTROLLER::handler(bool button1, bool button2, bool button3)
{
    if (status == normal)
    {
        pos = 0;
        if (button1)
        {
            if (content == Sec)
                return;
            button1 = false;
            pos = 1;
            changeStatus();
        }
        else if (button2)
        {
            changeDisp((Content)((ContentSize + content - 1) % ContentSize));
        }
        else if (button3)
        {
            changeDisp();
        }
    }

    if (status == abjust)
    {
        if (button1)
        {
            pos = 0;
            status = normal;
            return;
        }
        if (button3)
        {
            pos++;
            pos %= 4;
            if (pos == 0)
                pos = 4;
        }
        auto current_time = gmtime(&ltime);
        switch (content)
        {
        case Year:
            current_time->tm_sec = 0;
            switch (pos)
            {
            case 1:
                if (button2)
                {
                    current_time->tm_year++;
                }
                break;
            case 2:
                if (button2)
                {
                    current_time->tm_year += 10;
                }
                break;
            case 3:
                if (button2)
                {
                    current_time->tm_year += 100;
                }
                break;
            case 4:
                if (button2)
                {
                    current_time->tm_year += 1000;
                }
                break;
            default:
                break;
            }
            break;
        case Day:
            current_time->tm_sec = 0;
            switch (pos)
            {
            case 1:
                if (button2)
                {
                    current_time->tm_mday++;
                }
                break;
            case 2:
                if (button2)
                {
                    current_time->tm_mday += 10;
                }
                break;
            case 3:
                if (button2)
                {
                    current_time->tm_mon++;
                }
                break;
            case 4:
                if (button2)
                {
                    current_time->tm_mon += 10;
                }
                break;
            default:
                break;
            }
            break;
        case Hour:
            current_time->tm_sec = 0;
            switch (pos)
            {
            case 1:
                if (button2)
                {
                    current_time->tm_min++;
                }
                break;
            case 2:
                if (button2)
                {
                    current_time->tm_min += 10;
                }
                break;
            case 3:
                if (button2)
                {
                    current_time->tm_hour++;
                }
                break;
            case 4:
                if (button2)
                {
                    current_time->tm_hour += 10;
                }
                break;
            default:
                break;
            }
            break;
            // case Sec:
            //     switch (pos)
            //     {
            //     case 0:
            //         if (button2)
            //         {
            //             current_time->tm_sec++;
            //         }
            //         break;
            //     case 1:
            //         if (button2)
            //         {
            //             current_time->tm_sec += 10;
            //         }
            //         break;
            //     case 2:
            //         if (button2)
            //         {
            //             current_time->tm_min++;
            //         }
            //         break;
            //     case 3:
            //         if (button2)
            //         {
            //             current_time->tm_min += 10;
            //         }
            //         break;
            //     default:
            //         break;
            //     }
            break;
        default:
            break;
        }
        ltime = std::mktime(current_time);
    }
}

void CONTROLLER::adder()
{
    if (status == normal)
    {
        ltime++;
    }
}