#include "../include/Time.h"
#include <string>
#include <sstream>

void Time::set_from_string(const std::string &time)
{

    std::stringstream stream(time);
    char discard;

    stream >> hours;
    stream >> discard;
    stream >> minutes;
    stream >> discard;
    stream >> seconds;
}

std::string Time::toString()
{
    std::string teste;
    teste = std::to_string(hours) +":"+ std::to_string(minutes) +":"+ std::to_string(seconds);
    return teste;
}