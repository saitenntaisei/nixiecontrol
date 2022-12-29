#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__
#include "main.h"
#include <ctime>
#include "tube.h"
#include <memory>
const int ContentSize = 4;
enum Content
{
    Year,
    Day,
    Hour,
    Sec
};
enum Status
{
    normal = false,
    abjust = true
};

class CONTROLLER
{
private:
    Content content = Sec;
    Status status = normal;
    std::shared_ptr<nixie::TUBES> tubes;
    uint8_t pos;

public:
    time_t ltime;
    CONTROLLER();
    void changeDisp(Content currentContent);
    void changeDisp();
    void changeStatus();
    void disp();
    void handler(bool button1, bool button2, bool button3);
    void adder();
};

#endif