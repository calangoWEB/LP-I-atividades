#ifndef __DATE__H__
#define __DATE__H__

#include <string>

struct Date
{
    unsigned year;
    unsigned month;
    unsigned day;

    void set_from_string(const std::string &date);
};

#endif //!__DATE__H__