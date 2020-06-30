#ifndef __MESSAGE__H__
#define __MESSAGE__H__

#include "Date.h"
#include "Time.h"

#include <string>

struct Message
{
    std::string content;
    Date date;
    Time time;
};

#endif //!__MESSAGE__H__