#ifndef DIARY_H
#define DIARY_H

#include <string>
#include "Message.h"

struct Diary
{
    Message *message;
    void add(std::string const &message);
    void list();
    void show_usage(const std::string &prog_name);
};

#endif