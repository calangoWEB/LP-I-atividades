#ifndef __TIME__H__
#define __TIME__H__

#include <string>

struct Time
{
    unsigned hours;
    unsigned minutes;
    unsigned seconds;

    void set_from_string(const std::string &time);
    std::string toString();
};

#endif //!__TIME__H__