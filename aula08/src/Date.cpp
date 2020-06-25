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
    std::string teste;
    teste = std::to_string(day) +"/"+ std::to_string(month) +"/"+ std::to_string(year);
    return teste;
}