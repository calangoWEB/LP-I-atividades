#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

struct DateAndTime
{
    std::string time;
    std::string date;

    std::string format_current_date(const std::string &format);
    std::string get_current_date();
    std::string get_current_time();
};

struct Message
{
    DateAndTime dat;
    std::string content;
    std::string date_today = dat.get_current_date();
    bool check_date(const std::string &date_today);
};

#endif