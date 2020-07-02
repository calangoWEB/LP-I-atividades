#include "../include/Date.h"
#include <iostream>
#include <sstream>
#include <string>

void Date::set_from_string(const std::string &date)
{

    std::stringstream stream(date);
    char discard;

    stream >> day;
    stream >> discard;
    stream >> month;
    stream >> discard;
    stream >> year;
}

std::string Date::toString()
{
    std::stringstream stream;

    if (day < 10)
        stream << 0;
    stream << day;
    stream << '/';
    if (month < 10)
        stream << "0";
    stream << month << "/";
    stream << year;
    return stream.str();
}